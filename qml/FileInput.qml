import QtQuick 2.15
import QtQuick.Dialogs

Item {
    id: fileInput

    Rectangle {
        id: fileInputRect
        width: parent.width
        height: parent.height
        radius: 10
        border.width: 2
        border.color: "black"

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
                    console.log("clicked on TextInput")
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
