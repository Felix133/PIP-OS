import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
    id: root
    color: "grey"

    ListView {
        anchors.fill: parent
        model: inventory

        delegate: Text {
            color: "white"
            text: model.displayRole
            font.family: "Roboto Condensed"
            font.pixelSize: 20
        }
    }
}
