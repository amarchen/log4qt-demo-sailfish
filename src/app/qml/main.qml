import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"

ApplicationWindow
{
    initialPage: mainPageComponent
    Component {
        id: mainPageComponent
        MainPage { }
    }

    Component.onCompleted: {
        console.log("Nameless AppWindow completed. objectName is " + objectName)
    }
}


