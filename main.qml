import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: appPath

    Rectangle {
        anchors.fill: parent
        color: '#000'


        Text {
        anchors.centerIn: parent
            text: "Movies location is\n" + moviesPath
            color: 'red'
        }
    }
}
