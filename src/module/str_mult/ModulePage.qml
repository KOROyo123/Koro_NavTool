import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0

import "qrc:/qml/window"
import "qrc:/qml/global"


Loader{
    id:loader
    anchors.fill: parent

    Component.onCompleted: {
        loader.source="qrc:/module/str_mult/MainPage.qml"
    }
}






