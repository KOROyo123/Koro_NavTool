pragma Singleton

import QtQuick 2.15
import FluentUI 1.0

QtObject{

    property int displayMode: FluNavigationViewType.Auto
    property string displayName: "Koro_NavTool"
    property string displayLogo: "qrc:/logo.ico"

    property var switchPageUrl


    function switchPage(url){
        switchPageUrl=url
    }


}
