import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Silica 1.0

import harbour.log4qtdemo 0.1


// Just a simple example to demo both property binding and doing something via pulley menu action
// to provide a sample of Sailfish-specific UI testing
Page {
    id: page

    property Logger log: Logger {name: "page"}

    Person {
        id: bill
        name: "Bill Gates"
        property Logger log: Logger {name: "bill"}

        onNameChanged: {
            log.debug("Name changed to " + name)
        }

        Component.onCompleted:  {
            log.debug("Bill completed.")
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

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
//        PullDownMenu {
//            id: pullDownMenu
//        }
        
        // Tell SilicaFlickable the height of its content.
        contentHeight: childrenRect.height
        
        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            id: column
            anchors.fill: parent
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
                    text: "Make C1 CEO head C2 as well!"
                    onClicked: {
                        c2.ceo = c1.ceo
                    }
                }
            }

        }

        Component.onCompleted: {
            log.debug("nameless flickable completed.")
        }
    }

    Component.onCompleted: {
        log.debug("Main page completed, objectName ")
    }

}


