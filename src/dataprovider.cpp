#include <QJsonDocument>
#include <QQmlContext>
#include <jsoncons/json.hpp>
#include <jsoncons_ext/jsonpath/jsonpath.hpp>
#include <jsoncons_ext/jsonpath/jsonpath_error.hpp>

#include "app.h"
#include "dataprovider.h"

QVariant jsonToVariant( const jsoncons::json& value )
{
    if( value.is_object() )
    {
        QVariantMap map;
        for( const auto& [ key, val ] : value.object_range() )
        {
            map[ QString::fromStdString( key ) ] = jsonToVariant( val );
        }
        return map;
    }
    else if( value.is_array() )
    {
        QVariantList list;
        for( const auto& item : value.array_range() )
        {
            list.append( jsonToVariant( item ) );
        }
        return list;
    }
    else if( value.is_string() )
    {
        return QString::fromStdString( value.as<std::string>() );
    }
    else if( value.is_bool() )
    {
        return value.as_bool();
    }
    else if( value.is_double() )
    {
        return value.as_double();
    }
    else if( value.is_int64() )
    {
        return static_cast<qint64>( value.as_integer<qint64>() );
    }
    else if( value.is_uint64() )
    {
        return static_cast<quint64>( value.as_double() );
    }
    else if( value.is_null() )
    {
        return QVariant();
    }
    return QVariant();
}

namespace PipOS {

DataProvider::DataProvider(QObject *parent)
    : QObject(parent)
    , m_query("$")
{
    connect(this, &DataProvider::queryChanged, &DataProvider::doQuery);
}

void DataProvider::doQuery()
{
    if (m_query == "") { return; }

    qDebug() << "DataProvider doing query:" << m_query.toStdString();
    
    m_queryInProgress = true;
    emit queryInProgressChanged();

    try {
        // Get data from the root context
        QVariant appV = qmlEngine(this)->rootContext()->contextProperty("app");
        App *app = qobject_cast<App *>(qvariant_cast<QObject *>(appV));

        // Query the internal data structure
        jsoncons::json result = jsoncons::jsonpath::json_query(app->externalData(),
                                                               m_query.toStdString());

        m_data = jsonToVariant( result );

        emit dataChanged();
    } catch (const jsoncons::jsonpath::jsonpath_error &e) {
        qWarning() << "DataProvider query error:" << m_query << e.what();
    }

    m_queryInProgress = false;
    emit queryInProgressChanged();
}

void DataProvider::setQuery(const QString &newQuery)
{
    if (m_query == newQuery)
        return;
    m_query = newQuery;
    emit queryChanged();
}

} // namespace PipOS
