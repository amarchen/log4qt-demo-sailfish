import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Silica 1.0

import harbour.log4qtdemo 0.1


// Just a simple example to demo both property binding and doing something via pulley menu action
// to provide a sample of Sailfish-specific UI testing
Page {
    id: page

    Person {
        id: bill
        name: "Bill Gates"
    }

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent
        PageHeader {
            title: "Business world"
        }

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            id: pullDownMenu
            MenuItem {
                id: subtractMenuAction
                text: "Subtract!"
                onClicked: {
                    console.log("subtractMenuAction clicked")
                    subtrLabel.text = "A-B = " + (parseInt(a.text) - parseInt(b.text))
                }
            }
        }
        
        // Tell SilicaFlickable the height of its content.
        contentHeight: childrenRect.height
        
        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            anchors.fill: parent
            anchors.margins: Theme.paddingLarge
            spacing: Theme.paddingLarge
            Item {
                height: 20
                width: parent.width
                Text {
                    text: "Bill's name is " + bill.name
                }
            }
        }
    }

}


