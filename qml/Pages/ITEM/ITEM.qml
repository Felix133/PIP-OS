import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as C
import PipOS

import "../../Layout"

C.Page {
    id: root

    property alias subMenuIndex: subMenu.currentIndex
    property int subMenuCenter
    property variant pages: ["WEAPONS", "APPAREL", "AID", "MISC", "HOLO", "NOTES", "JUNK", "AMMO"]

    background: Rectangle {
        color: "black"
    }

    header: SubMenu {
        id: subMenu
        model: root.pages
        centerPoint: root.subMenuCenter
    }

    Inventory {
        id: inventory
        enabled: root.enabled
        state: root.pages[subMenu.currentIndex]
        anchors.fill: parent
    }

    footer: Rectangle {
        height: 40
        color: "#00000000"

        RowLayout {
            spacing: 4
            height: parent.height
            anchors.left: parent.left
            anchors.right: parent.right

            Rectangle {
                Layout.preferredWidth: 180
                Layout.preferredHeight: parent.height
                color: "#333333"

                Row {
                    anchors.fill: parent
                    spacing: 8

                    Image {
                        id: icon
                        source: "/images/status/weight.svg"
                        fillMode: Image.PreserveAspectFit
                        width: parent.height * 0.8
                        height: parent.height * 0.8
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Text {
                        anchors.left: icon.right
                        anchors.right: parent.right
                        anchors.margins: 10
                        anchors.verticalCenter: parent.verticalCenter
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                        font.pixelSize: 28
                        font.family: "Roboto Condensed Bold"
                        text: Dweller.weight + "/" + Dweller.maxWeight
                        color: "white"
                    }
                }
            }

            Rectangle {
                Layout.preferredWidth: 180
                Layout.preferredHeight: parent.height
                color: "#333333"

                Text {
                    anchors.fill: parent
                    anchors.margins: 10
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 28
                    font.family: "Roboto Condensed Bold"
                    text: "± %1".arg(Dweller.collections.find(
                                         a => a.name === "Caps")?.quantity ?? 0)
                    color: "white"
                }
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: parent.height
                color: "#333333"

                Text {
                    anchors.fill: parent
                    anchors.margins: 10
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 28
                    font.family: "Roboto Condensed Bold"
                    text: "-"
                    color: "white"
                }
            }
        }
    }
}
