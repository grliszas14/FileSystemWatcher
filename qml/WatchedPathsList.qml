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
        clip: true

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

                    Button {
                        text: "Remove"

                        onClicked: {
                            watchedPathsModel.removePath(index)
                        }
                    }
                }
            }
        }
    }
}
