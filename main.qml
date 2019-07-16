import QtQuick 2.12
import QtQuick.Controls 2.5
import tr.com.pcis 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "black"
        Text {
            id: time
            color: "white"
            text: "00:00:00"
            font.pointSize: 35
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    TimeWatcher {
        id: timeWatcher
        onTick: function(curTime){
            time.text = curTime;
        }
    }
}
