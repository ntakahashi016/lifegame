import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("LifeGame")
    GridLayout {
        columns: 100
        columnSpacing: -1
        rowSpacing: -1
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        Repeater {
            model: 5000
            MouseArea {
                id: _ma
                width: 10
                height: 10
                hoverEnabled: true
                onEntered: {
                }
                onExited: {
                }
                Rectangle {
                    id: _bg
                    anchors.fill: parent
                    color: "#FFFFFF"
                    border.color: "#000000"
                    border.width: 1
                }
                states: [
                    State {
                        name: "pressed"
                        when: _ma.pressed
                        PropertyChanges {
                            target: _bg
                            color: "#ff0000"
                        }
                    }

                ]
            }
        }
    }
}
