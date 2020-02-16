import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id:menuBarPanel
    MenuBar {
        width:menuBarPanel.width
        height: menuBarPanel.height
        Menu {
            title: qsTr("&File")
            width: 125
            Action {
                text: qsTr("&New...     Ctrl+N")
                shortcut: "Ctrl+N"
                icon.source: "newfile-button.png"
                onTriggered: {

                }
            }
            Action {
                text: qsTr("&Open...    Ctrl+O")
                shortcut: "Ctrl+O"
                icon.source: "open-button.png"
                onTriggered: {

                }
            }
            Action {
                text: qsTr("&Save        Ctrl+S")
                shortcut: "Ctrl+S"
                icon.source: "save-button.png"
            }
            Action {
                text: qsTr("Save &As...")
                icon.source: "saveas-button.png"
                onTriggered: {

                }
            }
            MenuSeparator { }
            Action {
                text: qsTr("&Quit       Ctrl+Q")
                shortcut: "Ctrl+Q"
                icon.source: "exit-button.png"
                onTriggered: {
                    Qt.quit();
                }
            }
        }
        Menu {
            title: qsTr("&Help")
            Action {
                text: qsTr("&About")
                icon.source: "about-button.png"
                onTriggered: {

                }
            }
        }
    }
}
