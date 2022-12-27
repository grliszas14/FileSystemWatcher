import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "."

Window {
    width: 1000
    height: 600
    visible: true
    title: qsTr("File System Watcher")
    color: "#E5E8E8"

    ColumnLayout {
        Layout.alignment: Qt.AlignCenter
        RowLayout {
            spacing: 20
            Layout.alignment: Qt.AlignCenter

            FileInput {
                id: fileInput
                Layout.preferredWidth: 800
                Layout.preferredHeight: 30
            }

            Button {
                id: addButton
                width: 50
                height: 30
                text: "Add"
            }
        }

        Label {
            id: watchedPathsLabel
            text: "Watched paths"
            font.pixelSize: Theme.fontSize
            color: Theme.fontColor
        }
    }
}
