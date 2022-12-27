import QtQuick 2.15
import QtQuick.Controls

Button {
    id: control

    contentItem: Text {
        text: control.text
        font: control.font
        color: Theme.fontColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 90
        implicitHeight: 30
        color: control.down ? "#85929E" : "white"
        border.color: Theme.borderColor
        border.width: Theme.borderWidth
        radius: Theme.borderRadius
    }

}
