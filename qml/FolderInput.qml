import QtQuick 2.15
import QtQuick.Dialogs
import Qt.labs.platform

Item {
    id: folderInput
    property alias text: folderPath.text

    Rectangle {
        id: fileInputRect
        width: parent.width
        height: parent.height
        radius: Theme.borderRadius
        border.width: Theme.borderWidth
        border.color: Theme.borderColor

        TextInput {
            id: folderPath
            width: parent.width
            height: parent.height
            font.pixelSize: parent.height - 2 * padding
            padding: 5
            readOnly: true

            MouseArea {
                anchors.fill: parent
                propagateComposedEvents: true

                onClicked: {
                    folderDialog.open()
                }
            }
        }
    }

    FolderDialog {
        id: folderDialog
        currentFolder: StandardPaths.writableLocation(StandardPaths.HomeLocation)

        onAccepted: {
            folderPath.text = folder
        }
    }
}
