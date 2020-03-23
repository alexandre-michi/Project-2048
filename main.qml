import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 320
    height: 240
    color: "#4c5cdc"
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        width: 100
        height: 50
        color: "#6be1ef"
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter; margins: 20 }

        Text {
            id: element
            x: 100
            y: 50
            color: "#200cc6"
            text: vueObjetCpt.cptQML
            Keys.onPressed: {
                switch (event.key) {
                case Qt.Key_Up:
                    vueObjetCpt.increment();
                    break;
                case Qt.Key_Down:
                    vueObjetCpt.decrement();
                    break;
                }
            }
            font.bold: true
            font.pixelSize: 34
            anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
            focus: true
        }
        transformOrigin: Item.Center
    }
}
