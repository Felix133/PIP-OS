import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
    id: root

    property int activeTabIndex: 0
    property list<string> allTabs: ["STAT", "ITEM", "DATA", "MAP", "RADIO"]
    property MainNavigationTab activeTab

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
        activeTab = repeater.itemAt(root.activeTabIndex)
    }

    color: "#000000000"
    height: 32

    Rectangle {
        anchors {
            left: root.left
            right: root.right
            bottom: root.bottom
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
            state: root.allTabs[root.activeTabIndex]
            model: root.allTabs

            MainNavigationTab {
                Layout.fillWidth: true
                active: repeater.state === modelData
                text: modelData
            }

            Component.onCompleted: {
                activeTab = repeater.itemAt(root.activeTabIndex)
            }
        }
    }
}
