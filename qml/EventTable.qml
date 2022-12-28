import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Item {
    Rectangle {
        id: eventTable
        width: parent.width
        height: parent.height
        border.width: Theme.borderWidth
        border.color: Theme.borderColor
        radius: Theme.borderRadius

        RowLayout {
            id: headerRow
            Layout.alignment: Qt.AlignCenter
            Rectangle {
                implicitHeight: Theme.tableRowHeight
                implicitWidth: Theme.tableRowWidth
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: statusLabel
                    text: "Status"
                    color: "white"
                }
            }
            Rectangle {
                implicitHeight: Theme.tableRowHeight
                implicitWidth: Theme.tableRowWidth
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: pathLabel
                    text: "Path"
                    color: "white"
                }
            }
            Rectangle {
                implicitHeight: Theme.tableRowHeight
                implicitWidth: Theme.tableRowWidth
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: isDirLabel
                    text: "isDir"
                    color: "white"
                }
            }
            Rectangle {
                implicitHeight: Theme.tableRowHeight
                implicitWidth: Theme.tableRowWidth
                color: "#5b5f63"
                radius: Theme.borderRadius
                Label {
                    id: timestampLabel
                    text: "Timestamp"
                    color: "white"
                }
            }
        }

        TableView {
            id: eventView
            width: parent.width - 2 * eventTable.border.width
            height: parent.height - 2 * eventTable.border.width - headerRow.height
            clip: true
            y: 27
            x: 2

            model: eventModel
            delegate: Rectangle {
                id: delegateRect
                implicitHeight: Theme.tableRowHeight
                implicitWidth: Theme.tableRowWidth
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
