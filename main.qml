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
        id: column
        width: parent.width
        height: parent.height

        Row {
            id: menu
            height: parent.height/5
            layer.enabled: false
            width: parent.width

            Text {
                id: title
                color: cTEXT_COLOR
                text: vDamierQML.score
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
        }// Row

        Grid {
            id: main_grid
            height: parent.height*4/5
            width: parent.width
            objectName: "main_grid"
            columns: 4
            horizontalItemAlignment: Grid.AlignHCenter
            verticalItemAlignment: Grid.AlignVCenter
            focus: true

            MyTile {objectName: "tile0"; size: parent.height/4 }
            MyTile {objectName: "tile1"; size: parent.height/4 }
            MyTile {objectName: "tile2"; size: parent.height/4 }
            MyTile {objectName: "tile3"; size: parent.height/4 }
            MyTile {objectName: "tile4"; size: parent.height/4 }
            MyTile {objectName: "tile5"; size: parent.height/4 }
            MyTile {objectName: "tile6"; size: parent.height/4 }
            MyTile {objectName: "tile7"; size: parent.height/4 }
            MyTile {objectName: "tile8"; size: parent.height/4 }
            MyTile {objectName: "tile9"; size: parent.height/4 }
            MyTile {objectName: "tile10"; size: parent.height/4 }
            MyTile {objectName: "tile11"; size: parent.height/4 }
            MyTile {objectName: "tile12"; size: parent.height/4 }
            MyTile {objectName: "tile13"; size: parent.height/4 }
            MyTile {objectName: "tile14"; size: parent.height/4 }
            MyTile {objectName: "tile15"; size: parent.height/4 }

            Keys.onPressed: {
                switch (event.key) {
                case Qt.Key_Up:
                    vDamierQML.updateTilesContent(0);
                    break;
                case Qt.Key_Right:
                    vDamierQML.updateTilesContent(1);
                    break;
                case Qt.Key_Down:
                    vDamierQML.updateTilesContent(2);
                    break;
                case Qt.Key_Left:
                    vDamierQML.updateTilesContent(3);
                    break;
                }
            }
        }// Grid
    }// Column
} // Window

/*##^##
Designer {
    D{i:4;anchors_height:200;anchors_width:200}D{i:7;anchors_height:200;anchors_width:200}
D{i:2;anchors_width:200;anchors_x:0}D{i:9;anchors_height:400;anchors_width:400}D{i:1;anchors_height:490;anchors_width:442;anchors_x:0;anchors_y:0}
}
##^##*/
