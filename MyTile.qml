import QtQuick 2.0

Item {
    //property string cBACKGROUND: "#3f334d"
    id: tile

    property alias size: rectangle.height

    Rectangle {
        id: rectangle
        width: height // create a square
        color: 'white'
    }
}

