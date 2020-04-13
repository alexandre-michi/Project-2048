import QtQuick 2.0

Rectangle {
    id: tile
    property alias size: tile.height
    property alias tileLbl: lbl.text
    property alias txtColor: lbl.color
    width: height // create a square
    color: cBACKGROUND

    Text {
        id: lbl
        text: qsTr("")
        color: cBACKGROUND
        width: parent.width
        height: parent.height
        fontSizeMode: Text.Fit
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 24
        font.bold: true
    }
}

