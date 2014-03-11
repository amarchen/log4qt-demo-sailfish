import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"

ApplicationWindow
{
    initialPage: sailCalcComponent
    Component {
        id: sailCalcComponent
        MainPage { }
    }

    Component.onCompleted: {
        console.log("nameless AppWindow completed. objectName is " + objectName)
    }
}


