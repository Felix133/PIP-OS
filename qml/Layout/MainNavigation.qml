import QtQuick 2.15
import QtQuick.Layouts

Rectangle {
    id: root

    property int activeTabIndex: 0
    property list<string> allTabs: ["STAT", "ITEM", "DATA", "MAP", "RADIO"]
    property MainNavigationTab activeTab

    color: "#000000000"
    height: 32

    function findItemPosition(itemToFind) {
        for (var i = 0; i < allTabs.length; ++i) {
            if (allTabs[i] === itemToFind) { return i; }
        }
        return -1; // Item not found
    }

    function setActiveTab(tab) {
        activeTabIndex = findItemPosition(tab)
        activeTab = repeater.itemAt(root.activeTabIndex)
    }

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
                required property string modelData
                Layout.fillWidth: true
                active: repeater.state === modelData
                text: modelData
            }

            Component.onCompleted: {
                root.activeTab = repeater.itemAt(root.activeTabIndex)
            }
        }
    }
}
