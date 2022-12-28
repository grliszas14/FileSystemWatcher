import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Item {
    Rectangle {
        id: watchedPathsList
        width: parent.width
        height: parent.height
        border.width: Theme.borderWidth
        border.color: Theme.borderColor
        radius: Theme.borderRadius

        RowLayout {
            id: headerRow
            Rectangle {
                implicitHeight: 25
                implicitWidth: 250
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: statusLabel
                    text: "Status"
                    Layout.leftMargin: 10
                    Layout.alignment: Qt.AlignCenter
                    color: "white"
                }
            }
            Rectangle {
                implicitHeight: 25
                implicitWidth: 250
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: pathLabel
                    text: "Path"
                    Layout.leftMargin: 10
                    Layout.alignment: Qt.AlignCenter
                    color: "white"
                }
            }
            Rectangle {
                implicitHeight: 25
                implicitWidth: 250
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: isDirLabel
                    text: "isDir"
                    Layout.leftMargin: 10
                    Layout.alignment: Qt.AlignCenter
                    color: "white"
                }
            }
            Rectangle {
                implicitHeight: 25
                implicitWidth: 250
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: timestampLabel
                    text: "Timestamp"
                    Layout.leftMargin: 10
                    Layout.alignment: Qt.AlignCenter
                    color: "white"
                }
            }


        }

        TableView {
            id: eventView
            width: parent.width - 2 * watchedPathsList.border.width
            height: parent.height - 2 * watchedPathsList.border.width - headerRow.height
            clip: true
            y: 27
            x: 2

            model: eventModel
            delegate: Rectangle {
                id: delegateRect
                implicitHeight: 25
                implicitWidth: 250

                color: index.row % 2 == 0 ? "#D5D8DC" : "white"
                x: 2
                radius: Theme.borderRadius

                RowLayout {
                    width: parent.width
                    Label {
                        id: eventState
                        text: tabledata
                        Layout.leftMargin: 10
                        Layout.alignment: Qt.AlignLeft
                        color: Theme.fontColor
                    }
                }
            }
        }
    }
}
