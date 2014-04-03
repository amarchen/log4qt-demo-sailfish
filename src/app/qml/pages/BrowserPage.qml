import QtQuick 2.0
import Sailfish.Silica 1.0

// TODO: Add pulley menu with "Open in a browser". Note that logging demo sometimes opens .log
//       file in BrowserPage.qml, it won't work via just Qt.openUrlExternally. Maybe disable pulley menu
//       in this case
Page {
    property alias url: webView.url

    SilicaWebView {
        header: PageHeader {
            title: "Web"
        }

        id: webView
        anchors.fill: parent
    }
    ProgressCircle {
        id: loadingProgressIndicator
        anchors.centerIn: parent
        visible: webView.loading
        value: webView.loadProgress / 100
    }

}
