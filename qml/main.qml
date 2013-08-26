import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0

ApplicationWindow {
    id: applicationwindow1
    title: qsTr("Test")
    width: 640
    height: 480

    signal qmlRequest()
    signal qmlParse()

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button {
        id: button1
        text: qsTr("Request")
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        onClicked: applicationwindow1.qmlRequest()
    }

    TextArea {
        id: text_area1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: button1.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Button {
        id: button2
        text: "Parse"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: button1.right
        anchors.leftMargin: 10
        onClicked: applicationwindow1.qmlParse()
    }

    function write(text) {
        text_area1.append(text)
    }
}
