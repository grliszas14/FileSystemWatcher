import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import WatchedPathsModel 1.0


Item {
    Rectangle {
        id: watchedPathsList
        width: parent.width
        height: parent.height
        border.width: Theme.borderWidth
        border.color: Theme.borderColor
        radius: Theme.borderRadius
        clip: true

        // todo: change it -> display rows and line and print delegates on it

        ListView {
            id: watchedPathsListView
            width: parent.width - 2 * watchedPathsList.border.width
            height: parent.height - 2 * watchedPathsList.border.width
            clip: true
            y: 2
            x: 2

            model: watchedPathsModel
            delegate: Rectangle {
                id: delegateRect
                implicitHeight: 25
                implicitWidth: parent.width - 2 * watchedPathsList.border.width
                color: index % 2 == 0 ? "#D5D8DC" : "white"
                x: 2
                radius: Theme.borderRadius

                RowLayout {
                    width: parent.width
                    Label {
                        id: singlePath
                        text: model.path
                        Layout.leftMargin: 10
                        Layout.alignment: Qt.AlignLeft
                        color: Theme.fontColor
                    }

                    Rectangle {
                        id: line
                        color: "black"
                        Layout.preferredWidth: 2
                        Layout.preferredHeight: delegateRect.height
                    }

                    Label {
                        text: model.status
                        Layout.alignment: Qt.AlignRight
                        color: Theme.fontColor
                    }
                }

            }
        }
    }
}
