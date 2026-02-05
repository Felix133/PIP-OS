import QtQuick
import PipOS 1.0

import "../"

Item {
    id: root

    HealthBar {
        progress: Dweller.healthHead
        width: 40
        height: 10
        anchors {
            horizontalCenter: root.horizontalCenter
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -210
        }
    }

    HealthBar {
        progress: Dweller.healthBody
        width: 40
        height: 10
        anchors {
            horizontalCenter: root.horizontalCenter
            verticalCenter: root.verticalCenter
            verticalCenterOffset: 76
        }
    }

    HealthBar {
        progress: Dweller.healthLeftArm
        width: 40
        height: 10
        anchors {
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: -130
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -105
        }
    }

    HealthBar {
        progress: Dweller.healthRightArm
        width: 40
        height: 10
        anchors {
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: 120
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -105
        }
    }

    HealthBar {
        progress: Dweller.healthLeftLeg
        width: 40
        height: 10
        anchors {
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: -130
            verticalCenter: root.verticalCenter
            verticalCenterOffset: 30
        }
    }

    HealthBar {
        progress: Dweller.healthRightLeg
        width: 40
        height: 10
        anchors {
            horizontalCenter: root.horizontalCenter
            horizontalCenterOffset: 120
            verticalCenter: root.verticalCenter
            verticalCenterOffset: 30
        }
    }

    AnimatedImage {
        id: vaultboy
        anchors {
            horizontalCenter: root.horizontalCenter
            verticalCenter: root.verticalCenter
            verticalCenterOffset: -55
        }
        source: "/images/status_ok.gif"
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
            itemIcon: "/images/status/weapon.svg"
            itemStats: ListModel {
                id: weaponModel
            }
        }

        Connections {
            target: Dweller
            onWeaponDamageChanged: weapon_stats.itemStats.setProperty(0, "value", Dweller.weaponDamage)
        }

        // Armor stats
        ItemStat {
            id: armor_stats
            itemIcon: "/images/status/armor.svg"
            itemStats: ListModel {
                id: armorModel
            }
        }


    Component.onCompleted: {
        weaponModel.clear()
        weaponModel.append({"icon": "/images/status/damage.svg", "value": Dweller.weaponDamage})

        armorModel.clear()
        armorModel.append({"icon": "/images/status/defence.svg", "value": Dweller.defence})
        armorModel.append({"icon": "/images/status/poison.svg", "value": Dweller.poisonResistance})
        armorModel.append({"icon": "/images/status/energy.svg", "value": Dweller.energyResistance})
        armorModel.append({"icon": "/images/status/radiation.svg", "value": Dweller.radiationResistance})
    }
        Connections {
            target: Dweller
            onDefenceChanged: armor_stats.itemStats.setProperty(0, "value", Dweller.defence)
            onPoisonResistanceChanged: armor_stats.itemStats.setProperty(1, "value", Dweller.poisonResistance)
            onEnergyResistanceChanged: armor_stats.itemStats.setProperty(2, "value", Dweller.energyResistance)
            onRadiationResistanceChanged: armor_stats.itemStats.setProperty(3, "value", Dweller.radiationResistance)
        }
    }

    Text {
        id: dwellerName
        text: Dweller.name
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
