# JSONListModel

Original component is an adaptation of https://github.com/kromain/qml-utils there were some issues with it and the JSONPath implementation was switched out to use https://www.npmjs.com/package/json-query.

The `json-query` library was converted to be QML compliant using https://gitlab.com/bhdouglass/qml-browserify

## Usage

```
JSONListModel{
    id: list
    source: "file:///path/to/file.json"
    sortKey: "text"
    query: "Inventory"
}
```

### Querying

You can use the online tester tool here https://maxleiko.github.io/json-query-tester/

### Sorting

The `sortKey` will filter an array of result objects based on this object key, alphabetically.
