import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id:ui_mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Stack Visualization")
    MenuBarControls {
        id:ui_menuBar
        width:ui_mainWindow.width
        height: ui_mainWindow.height / 12
    }
    StackControls {
        id:ui_stackControls
        height: ui_mainWindow.height
        width: ui_menuBar.height * 5/2
        anchors.top: ui_menuBar.bottom
        anchors.topMargin: ui_menuBar.height
        anchors.left:ui_menuBar.left
        anchors.leftMargin: 20
    }
    ListView {
        id:ui_stackView

        model:ListModel {
            id:stackView_Model
        }
        height: ui_mainWindow.height
        width: 200
        anchors.top: ui_menuBar.bottom
        anchors.topMargin: ui_menuBar.height
        anchors.left:ui_stackControls.right
        anchors.leftMargin: 175
        delegate: TextField{
                id:stackView_textField
                height: 24
                width: parent.width
                leftPadding: width / 2
                text:key
            }
        add: Transition {
            NumberAnimation { properties: "x"; from: -100; duration: 500 }
            NumberAnimation { properties: "opacity"; from:0;to: 1; duration:500 }
        }
        remove: Transition {
            NumberAnimation { properties: "x"; to: -100; duration: 500 }
            NumberAnimation { properties: "opacity"; from:1;to: 0; duration:500 }
        }
        }
}

