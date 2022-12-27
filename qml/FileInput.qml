import QtQuick 2.15
import QtQuick.Dialogs

Item {
    id: fileInput
    property alias text: filePath.text

    Rectangle {
        id: fileInputRect
        width: parent.width
        height: parent.height
        radius: Theme.borderRadius
        border.width: Theme.borderWidth
        border.color: Theme.borderColor

        TextInput {
            id: filePath
            width: parent.width
            height: parent.height
            font.pixelSize: parent.height - 2 * padding
            padding: 5
            readOnly: true

            MouseArea {
                anchors.fill: parent
                propagateComposedEvents: true

                onClicked: {
                    fileDialog.open()
                }
            }
        }
    }

    FileDialog {
        id: fileDialog

        // add default home path
        onAccepted: {
            filePath.text = selectedFile
        }
    }
}
