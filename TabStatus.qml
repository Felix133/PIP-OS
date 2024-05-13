import QtQuick 6.5
import QtQuick.Layouts
import QtMultimedia

Item {
    id: root

    ProgressBar {
        width: 40
        height: 12
        y: 114
        anchors.horizontalCenter: root.horizontalCenter
        progress: Dweller.healthHead
    }

    ProgressBar {
        width: 40
        height: 12
        y: 398
        anchors.horizontalCenter: root.horizontalCenter
        progress: Dweller.healthBody
    }

    ProgressBar {
        width: 40
        height: 12
        anchors.horizontalCenterOffset: -130
        y: 216
        anchors.horizontalCenter: root.horizontalCenter
        progress: Dweller.healthLeftArm
    }

    ProgressBar {
        width: 40
        height: 12
        anchors.horizontalCenterOffset: 123
        y: 216
        anchors.horizontalCenter: root.horizontalCenter
        progress: Dweller.healthRightArm
    }

    ProgressBar {
        width: 40
        height: 12
        anchors.horizontalCenterOffset: -130
        y: 348
        anchors.horizontalCenter: root.horizontalCenter
        progress: Dweller.healthLeftLeg
    }

    ProgressBar {
        width: 40
        height: 12
        anchors.horizontalCenterOffset: 123
        y: 348
        anchors.horizontalCenter: root.horizontalCenter
        progress: Dweller.healthRightLeg
    }

    Text {
        y: 514
        width: 300
        height: 22
        color: "#ffffff"
        text: Dweller.name
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Roboto Condensed"
        font.pixelSize: 26
        anchors.horizontalCenter: root.horizontalCenter
    }

    AnimatedSprite {
        id: vaultboy
        anchors.horizontalCenter: root.horizontalCenter
        y: 214
        source: "/images/body_0.png"
        frameRate: 7.5
        interpolate: false
        frameWidth: 120
        frameHeight: 180
        frameCount: 8
    }

    AnimatedSprite {
        anchors.bottom: vaultboy.top
        anchors.bottomMargin: -19
        anchors.horizontalCenter: vaultboy.horizontalCenter
        source: "/images/head_0.png"
        frameRate: 7.5
        interpolate: false
        frameWidth: 120
        frameHeight: 90
        frameCount: 8
    }

    Row {
        y: 430
        height: 64
        width: weapon_stats.width + armor_stats.width + 20
        anchors.horizontalCenter: root.horizontalCenter
        spacing: 20

        // Weapon stats
        ItemStat {
            id: weapon_stats
            itemIcon: "/images/weapon.svg"
            itemStats: ListModel {
                ListElement {
                    icon: "/images/defence.svg"
                    value: 66
                }
                ListElement {
                    icon: "/images/defence.svg"
                    value: 12
                }
            }
        }

        // Armor stats
        ItemStat {
            id: armor_stats
            itemIcon: "/images/armor.svg"
            itemStats: ListModel {
                ListElement {
                    icon: "/images/defence.svg"
                    value: 123
                }
                ListElement {
                    icon: "/images/defence.svg"
                    value: 666
                }
                ListElement {
                    icon: "/images/defence.svg"
                    value: 31
                }
            }
        }
    }

    // Development use for positioning reference
    // Image {
    //     // visible: false
    //     anchors.fill: root
    //     verticalAlignment: Image.AlignBottom
    //     source: "/images/ripped_ref_stat.png"
    //     z: 1
    //     opacity: 0.5
    //     fillMode: Image.PreserveAspectFit
    // }
}
