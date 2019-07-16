import QtQuick 2.12
import QtQuick.Controls 2.5
import tr.com.pcis 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: 55
            delegate: ItemDelegate {
                text: "Item " + (index + 1)
                width: parent.width
                onClicked: function(){
                    this.text = tester.getNames();
                }
            }
        }
    }



    NetworkTester {
        id:tester
    }
}
