pragma Singleton
import QtQuick 2.15

QtObject {
    // font
    property int fontSize: 20
    property color fontColor: "black"

    // borders
    property int borderWidth: 2
    property color borderColor: "black"
    property int borderRadius: 10

    // table
    property int tableRowWidth: 250
    property int tableRowHeight: 25
}
