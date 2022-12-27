import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "." // needed for using Theme

Window {
    width: 700
    height: 600
    visible: true
    title: qsTr("File System Watcher")
    color: "#E5E8E8"

    ColumnLayout {
        Layout.alignment: Qt.AlignCenter
        Layout.fillWidth: true
        Layout.fillHeight: true
        width: parent.width
        height: parent.height

        RowLayout {
            spacing: 20
            Layout.alignment: Qt.AlignCenter
            Layout.margins: 20

            FileInput {
                id: fileInput
                Layout.preferredHeight: 30
                Layout.preferredWidth: 800
                Layout.fillWidth: true
            }

            StyledButton {
                id: addButton
                Layout.preferredHeight: 30
                Layout.preferredWidth: 90
                text: "Add"

                onClicked: {
                    if (fileInput.text !== "") {
                        watchedPathsModel.appendPath(fileInput.text)
                    }
                }
            }
        }

        ColumnLayout {
            Label {
                id: watchedPathsLabel
                text: "Watched paths"
                font.pixelSize: Theme.fontSize
                color: Theme.fontColor
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 20
                Layout.rightMargin: 20
            }

            WatchedPathsList {
                id: watchedPathsList
                Layout.preferredHeight: 200
                Layout.preferredWidth: 900
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Layout.leftMargin: 20
                Layout.rightMargin: 20
                Layout.bottomMargin: 20
                Layout.fillHeight: true
            }
        }

        ColumnLayout {
            EventTable {
                id: eventTable
                Layout.preferredHeight: 200
                Layout.preferredWidth: 900
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Layout.leftMargin: 20
                Layout.rightMargin: 20
                Layout.fillHeight: true
            }

            RowLayout {
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 20
                Layout.rightMargin: 20
                Layout.bottomMargin: 20
                spacing: 20

                StyledButton {
                    id: clearButton
                    Layout.preferredHeight: 30
                    Layout.preferredWidth: 90
                    text: "Clear"

                    onClicked: {
                        // clear events, not watched paths
                        watchedPathsModel.clear()
                    }
                }
                StyledButton {
                    id: startButton
                    Layout.preferredHeight: 30
                    Layout.preferredWidth: 90
                    text: "Start"
                }
                StyledButton {
                    id: stopButton
                    Layout.preferredHeight: 30
                    Layout.preferredWidth: 90
                    text: "Stop"
                }
            }
        }
    }
}
