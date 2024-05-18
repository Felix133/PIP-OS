import QtQuick 2.15
import BootScreen

Rectangle {
    id: root
    color: "black"

    BootScreen {
        id: constants
    }

    Text {
        id: bootText
        text: constants.bootingText
        font.pixelSize: 16
        anchors {
            top: root.bottom
            topMargin: 0
            left: root.left
            leftMargin: 64
        }
        color: "white"
        font.family: "Share-TechMono Regular"
        states: State {
            name: "animating"
            AnchorChanges { target: bootText; anchors.bottom: root.top; anchors.top: undefined }
        }

        transitions: Transition {
            AnchorAnimation { duration: 3500; easing.type: Easing.InQuad }
        }

        Component.onCompleted: bootText.state = "animating"
    }

    property string currentSystemText: ""
    property int currentIndex: 0

    Text {
        id: systemText
        text: root.currentSystemText
        font.pixelSize: 22
        anchors {
            top: root.top
            topMargin: 30
            left: root.left
            leftMargin: 75
        }
        color: "white"
        font.family: "Share-TechMono Regular"

        states: State {
            name: "animating"
            AnchorChanges { target: systemText; anchors.bottom: root.top; anchors.top: undefined }
        }

        transitions: Transition {
            AnchorAnimation { duration: 600; easing.type: Easing.Linear }
        }
    }

    Timer {
        id: systemTextTimer
        interval: 20
        running: false
        repeat: true
        onTriggered: {
            if (root.currentIndex < constants.systemText.length) {
                root.currentSystemText += constants.systemText.charAt(root.currentIndex);
                root.currentIndex++;
            } else {
                systemTextTimer.running = false
                systemText.state = "animating"
            }
        }
    }

    AnimatedSprite {
        visible: false
        id: bootVaultBoy
        anchors {
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: -30
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -20
        }
        source: "/images/boot_vaultboy.png"
        frameDuration: 133 // TODO: This is wrong, need to work out how to control when each frame animates
        interpolate: false
        frameWidth: 160
        frameHeight: 230
        frameCount: 8
        loops: 1
        paused: true

        onFinished: {
            console.log("all done")
        }

        Timer {
            id: bootVaultBoyTimer
            interval: 2500
            onTriggered: bootVaultBoy.paused = false
        }

        Timer {
            id: bootVaultBoyTimerTwo
            interval: bootVaultBoy.frameCount * bootVaultBoy.frame - 1
            running: bootVaultBoy.running
            repeat: false
            onTriggered: bootVaultBoy.running = false
        }
    }

    Image {
        visible: false
        id: initiatingText
        source: "/images/initiating.svg"
        anchors.horizontalCenter: root.horizontalCenter
        anchors.top: bootVaultBoy.bottom
        anchors.topMargin: 50

        OpacityAnimator on opacity {
            from: 1
            to: 0.5
            duration: 1000
            loops: Animation.Infinite
            easing.type: Easing.InOutSine
        }
    }

    // When boot text stops scrolling, start the system text animation
    Connections {
        target: bootText.transitions[0]
        function onRunningChanged () {
            if (!bootText.transitions[0].running) {
                systemTextTimer.running = true
            }
        }
    }

    // When the system text stops animating, show the vault boy initiating...
    Connections {
        target: systemText.transitions[0]
        function onRunningChanged () {
            if (!systemText.transitions[0].running) {
                bootVaultBoy.visible = true
                bootVaultBoyTimer.start()
                initiatingText.visible = true
            }
        }
    }
}
