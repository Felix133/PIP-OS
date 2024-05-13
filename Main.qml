import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Effects

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("PIP-OS V7.1.0.8")

    Rectangle {
        id: main
        anchors.fill: parent
        color: "black"

        layer.enabled: true
        layer.effect: screenOverlay

        TabBar {
            id: tabs
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                topMargin: -5
                leftMargin: 95
                rightMargin: 95
            }
            height: 34

            currentIndex: 0

            NavButton { text: "STAT" }
            NavButton { text: "INV" }
            NavButton { text: "DATA" }
            // NavButton { text: "MAP" }
            NavButton { text: "RADIO" }

            focus: true

            Keys.onPressed: event => {
                switch (event.key) {
                    case Qt.Key_1:
                    if (tabs.currentIndex !== 0) {
                        tabs.setCurrentIndex(0)
                        pageStat.subMenuIndex = 0
                    }
                    else pageStat.subMenuNext()
                    break

                    case Qt.Key_2:
                    if (tabs.currentIndex !== 1) {
                        tabs.setCurrentIndex(1)
                        pageStat.pageInv = 0
                    }
                    else pageStat.pageInv()
                    break

                    case Qt.Key_3:
                    if (tabs.currentIndex !== 2) {
                        tabs.setCurrentIndex(2)
                        pageStat.pageData = 0
                    }
                    else pageStat.pageData()
                    break

                    case Qt.Key_4:
                    if (tabs.currentIndex !== 3) {
                        tabs.setCurrentIndex(3)
                    }
                    break
                }
            }
        }

        StackLayout {
            id: stack
            anchors {
                top: tabs.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
            }

            currentIndex: tabs.currentIndex

            PageStat { id: pageStat }
            PageInv { id: pageInv }
            PageData { id: pageData }
            // PageMap { id: pageMap }
            PageRadio { id: pageRadio }
        }

        Rectangle {
            id: scanlines
            anchors.fill: main
            opacity: 0.1
            color: "black"
            Column {
                spacing: 2
                Repeater {
                    model: 200
                    Rectangle {
                        width: scanlines.width
                        height: 2
                        color: "black"
                    }
                }
            }
        }

        // Overlay the screen with the color scheme of choice
        Component {
            id: screenOverlay
            MultiEffect {
                source: main
                anchors.fill: main
                colorization: 1
                colorizationColor: Style.overlayColor
                blurEnabled: true
                blur: 0.05
            }
        }

        Image {
            id: ref
            visible: false
            anchors.fill: main
            verticalAlignment: Image.AlignBottom
            source: "ripped_ref.png"
            anchors.horizontalCenterOffset: -8
            z: 1
            opacity: 0.2
            fillMode: Image.PreserveAspectFit
        }
    }
}
