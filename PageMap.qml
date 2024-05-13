import QtQuick 2.15
import QtQuick.Controls

Page {
    background: Rectangle { color: "black" }

    header: SubMenu {
        items: ["STATUS", "EFFECTS", "SPECIAL", "COLLECTIONS"]
        horizontalOffset: -230
    }

    footer: Rectangle {
        color: "grey"
        height: 40
    }
}
