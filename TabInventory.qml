import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
    id: root
    width: 100; height: 100

    color: "grey"
    // Rectangle {
    //     color: "grey"

    //     width: 100; height:100
    //     // Layout.alignment: Qt.AlignCenter
    // }
    Text {
        Layout.alignment: Qt.AlignCenter
        text: "ALBERT"
        color: "white"
        font {
            family: "Roboto Condensed"
            pixelSize: 30
        }
        horizontalAlignment: Text.AlignHCenter
    }
}
