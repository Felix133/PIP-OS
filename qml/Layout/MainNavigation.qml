import QtQuick 2.15
import QtQuick.Layouts
import QtMultimedia

Rectangle {
    id: tabs

    property int activeTabIndex: 0
    property list<string> allTabs: ["STAT", "ITEM", "DATA", "MAP", "RADIO"]
    property Rectangle activeTab: repeater.itemAt(activeTabIndex)

    function findItemPosition(itemToFind) {
        for (var i = 0; i < allTabs.length; ++i) {
            if (allTabs[i] === itemToFind) {
                return i; // Found the item; return its index
            }
        }
        return -1; // Item not found
    }

    function setActiveTab(tab) {
        activeTabIndex = findItemPosition(tab)
        sfxRotary.play()
    }

    SoundEffect {
        id: sfxRotary
        source: "/assets/sounds/horizontal_tab.wav"
    }

    color: "#000000000"
    height: 32

    Rectangle {
        anchors {
            left: tabs.left
            right: tabs.right
            bottom: tabs.bottom
        }

        height: 3
        color: "white"
    }

    RowLayout {
        anchors {
            top: parent.top
            topMargin: -10
            left: parent.left
            leftMargin: 65
            right: parent.right
            rightMargin: 75
        }

        Repeater {
            id: repeater
            state: tabs.allTabs[tabs.activeTabIndex]
            model: tabs.allTabs

            delegate: Rectangle {
                Layout.fillWidth: true
                color: "#000000000"
                Rectangle {
                    visible: repeater.state === modelData
                    anchors {
                        horizontalCenter: tabText.horizontalCenter
                        top:  tabText.top
                        topMargin: 20
                    }

                    width: tabText.implicitWidth + 16
                    height: 50
                    border.color: "white"
                    border.width: 1
                    color: "#000000000"

                    // Blank out a portion of the outline
                    Rectangle {
                        anchors {
                            top: parent.top
                            horizontalCenter: parent.horizontalCenter
                        }
                        width: tabText.implicitWidth + 2
                        height: 2
                        color: "black"
                    }
                }

                Text {
                    id: tabText
                    anchors.fill: parent
                    text: modelData
                    color: "white"
                    font {
                        family: "Roboto Condensed Bold"
                        pixelSize: 32
                    }
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
    }
}
