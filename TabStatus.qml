import QtQuick 6.5
import QtQuick.Layouts
import QtMultimedia

Item {
    id: root

    ProgressBar {
        progress: Dweller.healthHead
        width: 40
        height: 10
        anchors{
            horizontalCenter: root.horizontalCenter
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -210
        }
    }

    ProgressBar {
        progress: Dweller.healthBody
        width: 40
        height: 10
        anchors{
            horizontalCenter: root.horizontalCenter
            verticalCenter: root.verticalCenter
            verticalCenterOffset: 76
        }
    }

    ProgressBar {
        progress: Dweller.healthLeftArm
        width: 40
        height: 10
        anchors{
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: -130
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -105
        }
    }

    ProgressBar {
        progress: Dweller.healthRightArm
        width: 40
        height: 10
        anchors{
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: 120
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -105
        }
    }

    ProgressBar {
        progress: Dweller.healthLeftLeg
        width: 40
        height: 10
        anchors{
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: -130
            verticalCenter: root.verticalCenter
            verticalCenterOffset: 30
        }
    }

    ProgressBar {
        progress: Dweller.healthRightLeg
        width: 40
        height: 10
        anchors{
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: 120
            verticalCenter: root.verticalCenter
            verticalCenterOffset: 30
        }
    }

    AnimatedSprite {
        id: vaultboy
        anchors {
            horizontalCenter: root.horizontalCenter
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -20
        }
        source: "/images/body_0.png"
        frameRate: 7.5
        interpolate: false
        frameWidth: 120
        frameHeight: 180
        frameCount: 8
    }

    AnimatedSprite {
        anchors {
            bottom: vaultboy.top
            bottomMargin: -19
            horizontalCenter: vaultboy.horizontalCenter
        }
        source: "/images/head_0.png"
        frameRate: 7.5
        interpolate: false
        frameWidth: 120
        frameHeight: 90
        frameCount: 8
    }

    Row {
        anchors {
            horizontalCenter: root.horizontalCenter
            bottom: dwellerName.top
            bottomMargin: 20
        }
        height: 64
        width: weapon_stats.width + armor_stats.width + 20
        spacing: 20

        // Weapon stats
        ItemStat {
            id: weapon_stats
            itemIcon: "/images/weapon.svg"
            itemStats: ListModel {
                ListElement {
                    icon: "/images/defence.svg"
                    value: 18
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
                    value: 10
                }
            }
        }
    }

    Text {
        id: dwellerName
        text: DwellerSettings.name
        anchors {
            horizontalCenter: root.horizontalCenter
            bottom: root.bottom
            bottomMargin: 26
        }
        font {
            family: "Roboto Condensed"
            pixelSize: 26
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        width: 300
        height: 22
        color: "white"
    }
}
