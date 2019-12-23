import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("LifeGame")
    signal runButtonSignal(variant array)
    signal stopButtonSignal(string msg)
    function getCellArray() {
        var cellarray = new Array
        for (var i=0; i<_CellAreas.count; i++) {
            cellarray.push(_CellAreas.itemAt(i).alive);
        }
        return cellarray;
    }
    function setCellArraySlot(array)
    {
        for (var i=0; i<array.length; i++) {
            _CellAreas.itemAt(i).alive = array[i];
        }
    }

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
                id: _CellAreas
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
                    states: [
                        State {
                            name: "Alive"
                            when: alive
                            PropertyChanges {
                                target: _bg
                                color: aliveCell
                            }
                        },
                        State {
                            name: "Dead"
                            when: !alive
                            PropertyChanges {
                                target: _bg
                                color: deadCell
                            }
                        }

                    ]
                    MouseArea {
                        id: _ma
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: { _bg.alive = !_bg.alive }
                    }
                }
            }
        }
        ColumnLayout {
            Button {
                id: _RunButton
                text: "うごかす"
                onClicked: {
                    runButtonSignal(getCellArray())
                }
            }
            Button {
                id: _StopButton
                text: "とめる"
                onClicked: {
                    stopButtonSignal("stop button clicked")
                }
            }
        }
    }
}
