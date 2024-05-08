pragma Singleton

import QtQuick 2.15
import FluentUI 1.0

FluObject{

    property var navigationView
    property var paneItemMenu

    id:footer_items

    FluPaneItemSeparator{}

    FluPaneItem{
        title:qsTr("Settings")
        menuDelegate: paneItemMenu
        icon:FluentIcons.Settings
        url:"qrc:/qml/page/T_Settings.qml"
        onTap:{
            navigationView.push(url)
        }
    }

}
