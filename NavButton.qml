import QtQuick 2.15
import QtQuick.Templates as T

T.TabButton {
    id: control

    background: Rectangle {
        color: control.checked ? "black": "white"
        // color: "grey"
        border.color: "white"
        border.width: 2
    }

    contentItem: Text {
        text: control.text
        color:  control.checked ? "white": "grey"
        horizontalAlignment: Text.AlignHCenter
        font {
            pixelSize: 32
            family: "Roboto Condensed Bold"
        }
    }
}
