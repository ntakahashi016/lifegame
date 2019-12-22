import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("LifeGame")
    RowLayout {
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        GridLayout {
            columns: 50
            columnSpacing: -1
            rowSpacing: -1
            Repeater {
                model: 2500
                Rectangle {
                    id: _bg
                    width: 10
                    height: 10
                    property color deadCell: "#FFFFFF"
                    property color aliveCell: "#000000"
                    property color selectedCell: "#8888FF"
                    property color pressedCell: "#FF0000"
                    property color cellBorder: "#BBBBBB"
                    property bool alive: false
                    color: deadCell
                    border.color: cellBorder
                    border.width: 1
                    MouseArea {
                        id: _ma
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            _bg.color = selectedCell
                        }
                        onExited: {
                            if (_bg.alive === true) {
                                _bg.color = aliveCell
                            } else {
                                _bg.color = deadCell
                            }
                        }
                        onClicked: {
                            if (_bg.alive === true) {
                                _bg.alive = false
                                _bg.color = deadCell
                            } else {
                                _bg.alive = true
                                _bg.color = aliveCell1
                            }
                        }
                        states: [
                            State {
                                name: "pressed"
                                when: _ma.pressed
                                PropertyChanges {
                                    target: _bg
                                    color: pressedCell
                                }
                            }

                        ]
                    }
                }
            }
        }
        ColumnLayout {
            Button {
                id: _RunButton
                text: "うごかす"
                onClicked: {
                    console.log(_RunButton.text + "clicked")
                }
            }
            Button {
                id: _StopButton
                text: "とめる"
                onClicked: {
                    console.log(_StopButton.text + "clicked")
                }
            }
        }
    }
}
