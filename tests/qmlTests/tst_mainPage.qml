/**
 * Tests that operate on the UI level. They expect window to be shown.
 * This is not exactly the good practice, this example is for demostrating logging, not
 * for showing good test practices.
 * @see for example http://www.slideshare.net/AgileArtem/test-drivingqml-12941898 for quick start on unit testing in QML
 */
import QtQuick 2.0
import QtTest 1.0
import Sailfish.Silica 1.0

//import "../src/qml/pages"
import "../harbour-log4qtdemo/qml/pages"


// Putting TestCase into the full app structure to test UI interactions and probably page transitions too
ApplicationWindow {
    id: wholeApp
    initialPage: MainPage {
        id: mainPage
    }

    TestCase {
        name: "MainPage test"

        // You won't see anything yet at this moment, but UI is actually constructed already and e.g. mouseClick will work
        // Painting happens later, you can set up timer to wait for it (painting happens some 50-100ms after ApplicationWindow's
        // applicationActive becomes true), then you might be able to
        // see graphics update when test is clicking through buttons, though you might need to yield control from time to time then
        when: windowShown

        function test_ceoChangesOnButtonPress() {
            compare(mainPage._i.c2.ceo.name, "Bill Gates")

            // Calling slot directly, it is not identical to touch interaction.
            // And this is good as we do not want to check if pulling Pulley menu actually
            // works - that is for Jolla people to care after :)
            mainPage._i.changingButton.clicked(null)
            compare(mainPage._i.c2.ceo.name, "Steven Elop")
        }
    }

}

