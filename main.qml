import QtQuick 2.12
import QtQuick.Controls 2.5
import tr.com.pcis 1.0

ApplicationWindow {
    visible: true
    width: 1024
    height: 768
    title: qsTr("Scroll")

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "black"
        Text {
            id: txtTime
            color: "white"
            text: "--:--:--"
            font.pointSize: 64
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            NumberAnimation on font.pointSize {
                id: numAnim
                from: 84
                to: 64
                duration: 800
            }
        }

         Button {
             id: button
             x: 462
             y: 539
             text: qsTr("Click Me")
             autoExclusive: false
             flat: false
             highlighted: false
             anchors.horizontalCenter: parent.horizontalCenter
             onClicked: function(){
                 timeWatcher.throwError();
             }
         }

         Text {
             id: element
             x: 251
             y: 140
             width: 658
             height: 95
             color: "#ffffff"
             text: qsTr("PCIS APP DEMO")
             font.letterSpacing: 1.5
             font.bold: true
             anchors.horizontalCenterOffset: 0
             anchors.horizontalCenter: parent.horizontalCenter
             font.pixelSize: 83
         }
    }
    TimeWatcher {
        id: timeWatcher
        onTickSeconds: function(time){
            txtTime.text = time;
            numAnim.start();
        }
    }
}
