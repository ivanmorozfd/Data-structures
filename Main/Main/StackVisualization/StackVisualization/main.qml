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

        model:[]
        height: ui_mainWindow.height
        width: 200
        anchors.top: ui_menuBar.bottom
        anchors.topMargin: ui_menuBar.height
        anchors.left:ui_stackControls.right
        anchors.leftMargin: 175
        delegate: TextField{
            Component.onCompleted: showAnim.start();
                id:stackView_textField
                transform: Rotation { id:rt; origin.x: width; origin.y: height; axis { x: 0.3; y: 1; z: 0 } angle: 0}
                height: 24
                width: parent.width
                leftPadding: width/2

                text:modelData
                SequentialAnimation {
                    id: showAnim
                    running: false
                    RotationAnimation { target: rt; from: 180; to: 0; duration: 800; easing.type: Easing.OutBack; property: "angle" }
                }
            }
        }
}

