import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.12
Item {
    id:buttons_group
    ColumnLayout {
        id: group_clayout
        spacing: 20
        RowLayout {
            id:clayout_pushRow
            Button {
                id:clayout_pushButton
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                text:"Push"
                onClicked: {
                    stackView_Model.append({"key":"a"});
                }
            }
            TextField {
                id:clayout_pushButtonField
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
            }
        }
        RowLayout {
            id:clayout_popRow
            Button {
                id:clayout_popButton
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                text:"Pop"
                onClicked: {
                    stackView_Model.remove(stackView_Model.count - 1);
                }
            }
            TextField {
                id:clayout_popButtonField
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                readOnly: true
            }
        }
        RowLayout {
            id:clayout_peekRow
            Button {
                id:clayout_peekButton
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                text:"Peek"
            }
            TextField {
                id:clayout_peekButtonField
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                readOnly: true
            }
        }
        RowLayout {
            id:clayout_clearRow
            Button {
                id:clayout_clearButton
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                text:"Clear"
            }
            TextField {
                id:clayout_clearButtonField
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                readOnly: true
            }
        }
        RowLayout {
            id:clayout_findRow
            Button {
                id:clayout_findButton
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                text:"Find"
            }
            TextField {
                id:clayout_findButtonField
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                readOnly: true
            }
        }
        RowLayout {
            id:clayout_sortField
            Button {
                id:clayout_sortButton
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                text:"Sort"
            }
            TextField {
                id:clayout_sortButtonField
                Layout.preferredHeight: 24
                Layout.preferredWidth: 100
                readOnly: true
            }
        }
    }
}
