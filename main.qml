import QtQuick 2.12
import QtQuick.Window 2.12
import DamierQML 1.0

Window {
    id: window
    visible: true
    width: 500
    height: 500
    color: cBACKGROUND
    title: qsTr("2048")


    // COLORS
    property string cPRIMARY: "#eaf0ce"
    property string cSECONDARY: "#7d8491"
    property string cTERTIARY: "574b60"
    property string cBACKGROUND: "#3f334d"
    property string cTEXT_COLOR: "#c0c5c1"

    Row {
        id: row
        width: parent.width
        height: parent.height

        Rectangle {
            id: menu
            height: parent.height/5
            width: parent.width
            color: "#00000000"
//            anchors.top: parent.top
//            anchors.topMargin: 0

            Grid {
                id: grid1
                anchors.fill: parent

                Text {
                    id: title
                    color: cTEXT_COLOR
                    text: qsTr("2048")
                    height: parent.height
                    width: parent.width/2
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    fontSizeMode: Text.Fit
                    font.pixelSize: 50
                }

                Rectangle {
                    id: new_game
                    width: parent.width/4
                    height: parent.height
                    color: cPRIMARY
//                    anchors.rightMargin: 0
//                    anchors.right: undo.left

                    Text {
                        id: new_game_text
                        color: cTEXT_COLOR
                        text: qsTr("New\nGame")
                        font.bold: true
                        width: parent.width
                        height: parent.height
                        font.family: "Tahoma"
                        fontSizeMode: Text.Fit
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: 20
                    }
                }

                Rectangle {
                    id: undo
                    width: parent.width/4
                    height: parent.height
                    color: cSECONDARY
//                    anchors.right: parent.right

                    Text {
                        id: undo_text
                        color: cTEXT_COLOR
                        text: qsTr("Undo")
                        width: parent.width
                        height: parent.height
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.family: "Tahoma"
                        font.bold: true
                        fontSizeMode: Text.Fit
                        font.pixelSize: 20
                    }
                }
            }
        }

        Grid {
            id: grid_damier
            height: parent.height*4/5
            width: parent.width
//            anchors.top: menu.bottom
//            anchors.left: parent.left
        }
    }
}

/*##^##
Designer {
    D{i:4;anchors_height:200;anchors_width:200}D{i:7;anchors_height:200;anchors_width:200}
D{i:2;anchors_width:200;anchors_x:0}D{i:9;anchors_height:400;anchors_width:400}D{i:1;anchors_height:490;anchors_width:442;anchors_x:0;anchors_y:0}
}
##^##*/
