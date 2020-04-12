import QtQuick 2.12
import QtQuick.Window 2.12
import DamierQML 1.0

Rectangle {
    id: window
    visible: true
    width: 500
    height: 500
    color: cBACKGROUND
//    title: qsTr("2048")


    // COLORS
    property string cPRIMARY: "#eaf0ce"
    property string cSECONDARY: "#7d8491"
    property string cTERTIARY: "574b60"
    property string cBACKGROUND: "#3f334d"
    property string cTEXT_COLOR: "#c0c5c1"

    Column {
        width: parent.width
        height: parent.height

        Row {
            id: menu
            height: parent.height/5
            width: parent.width

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

            MyButton {
                id: new_game
                txt: qsTr("New\nGame")
                txt_color: cTEXT_COLOR
                bg_color: cPRIMARY
            }

            MyButton {
                id: undo
                txt: qsTr("Undo")
                txt_color: cTEXT_COLOR
                bg_color: cSECONDARY
            }
        } // Row

        GridView {
            objectName: "main_grid"
//            DamierQML {
//               id: damier_qml
//            }
        } // Grid
    } // Column
} // Window

/*##^##
Designer {
    D{i:4;anchors_height:200;anchors_width:200}D{i:7;anchors_height:200;anchors_width:200}
D{i:2;anchors_width:200;anchors_x:0}D{i:9;anchors_height:400;anchors_width:400}D{i:1;anchors_height:490;anchors_width:442;anchors_x:0;anchors_y:0}
}
##^##*/
