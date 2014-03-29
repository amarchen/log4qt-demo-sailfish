import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Silica 1.0

import harbour.log4qtdemo 0.1


// Just a simple example to demo both property binding and doing something via pulley menu action
// to provide a sample of Sailfish-specific UI testing
Page {
    id: page

    property Logger log: Logger {name: "page"}

    // testing interface
    property QtObject _i: QtObject {
        property alias c1: c1
        property alias c2: c2
        property alias changingButton: changingButton
    }

    Person {
        id: bill
        name: "Bill Gates"
        property Logger log: Logger {name: "bill"}

        onNameChanged: {
            log.debug("Name changed to " + name)
        }

        Component.onCompleted:  {
            log.debug("Bill completed.")

            // will print object type and pointer only, no QDebug stream info
            log.debug("bill's object: " + bill)
        }
    }

    Person {
        id: steven
        name: "Steven Elop"
    }

    Company {
        id: c1
        name: "Nokia"
        ceo: steven
    }

    Company {
        id: c2

        // It could be not so good idea to give long names to loggers though
        property Logger log: Logger {name: "QML Microsoft"}
        name: "Microsoft"
        ceo: bill
        onCeoChanged: {
            log.info("CEO changed to " + ceo.name)
        }
    }

    PageHeader {
        id: header
        title: "Business world"
    }


    Column {
        id: column
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: Theme.paddingLarge
        spacing: Theme.paddingLarge
        Item {
            height: childrenRect.height
            width: parent.width
            Label {
                text: "Company1 is " + c1.name
            }
        }
        Item {
            height: childrenRect.height
            width: parent.width
            Label {
                text: "Company1 CEO is " + c1.ceo.name
            }
        }

        Item {
            height: childrenRect.height
            width: parent.width
            Label {
                text: "Company2 is " + c2.name
            }
        }

        Item {
            height: childrenRect.height
            width: parent.width
            Label {
                text: "Company2 CEO is " + c2.ceo.name
            }
        }
        Item {
            height: childrenRect.height
            width: parent.width
            Button {
                id: changingButton
                text: "Make C1 CEO head C2 as well!"
                onClicked: {
                    c2.ceo = c1.ceo
                }
            }
        }

    }  // Column

    Item {
        anchors.top: column.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        Label {
            anchors.fill: parent
            anchors.topMargin: 3*Theme.paddingLarge
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.StyledText
            text: "This is not a real appllication, just the development example.<br/>\
                  see Logs in <a href='file:///home/nemo/.cache/harbour-log4qtdemo/harbour-log4qtdemo.log'>/home/nemo/.cache/harbour-log4qtdemo/harbour-log4qtdemo.log</a>.<br/>\
                  Check <a href='https://github.com/amarchen/log4qt-demo-sailfish'>github project page</a> to see what it is all about."

            linkColor: Theme.highlightColor
            onLinkActivated: {
                pageStack.push("BrowserPage.qml", {"url": link})
            }
        }
    }

    Component.onCompleted: {
        log.debug("Main page completed")
    }

}


