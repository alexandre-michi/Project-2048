import QtQuick 2.0

/*
 * Components pour les boutons nouveau jeu et quitter
 */
Item {
    id: my_button
    width: parent.width/4
    height: parent.height

    property alias txt: button_txt.text
    property alias txt_color: button_txt.color
    property alias bg_color: rect.color
    
    Rectangle {
        id: rect
        anchors.fill: parent
    }
    Text {
        id: button_txt
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
