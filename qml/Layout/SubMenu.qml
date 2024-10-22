import QtQuick 2.15
import QtMultimedia

ListView {
    id: list

    property int centerPoint: 0

    signal goNext()

    Component.onCompleted: {
        list.goNext.connect(goToNext)
    }

    function goToNext() {
        if (currentIndex + 1 === model.length) currentIndex = 0
        else currentIndex = currentIndex + 1
        sfxRotary.play()
    }

    function goToStart() {
        currentIndex = 0
        sfxRotary.play()
    }

    orientation: ListView.Horizontal
    spacing: 20
    height: 42

    highlightRangeMode: ListView.StrictlyEnforceRange
    preferredHighlightBegin: centerPoint - (currentItem.width / 2)
    preferredHighlightEnd: centerPoint + (currentItem.width / 2)
    highlightResizeDuration: 0

    delegate: Text {
        text: modelData
        color: "white"
        font.family: "Roboto Condensed"
        height: list.height
        verticalAlignment: Text.AlignBottom
        width: implicitWidth
        font.pixelSize: 32
        opacity: 1.0 - ((index - list.currentIndex) > 0 ? (index - list.currentIndex) : (list.currentIndex - index)) * 0.34
    }

    SoundEffect {
        id: sfxRotary
        source: "/assets/sounds/horizontal_tab.wav"
    } 

    // Debug selected item
    // highlight: Rectangle {
    //     border.color: "grey"
    //     border.width: 2
    //     color: "black"
    // }
}
