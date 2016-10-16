import QtQuick 2.5
import QtQuick.Window 2.2

import Files 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: appPath
    property string error
    property string output

    Rectangle {
        anchors.fill: parent
        color: '#000'


        Text {
            id: text
            anchors.centerIn: parent
            text: "Loading ... click me"
            color: 'red'
        }
        MouseArea {
            anchors.fill: parent
            onClicked: reader.readFile()
        }
    }

    ReadFile {
        id: reader
        onError: console.log("There has been an error:" + errorString)
        onTextChanged: {
            text.text = output
        }

        fileName: '/Users/user/Workspace/tutorials/qt-cpp-demo/LICENSE'
    }
}
