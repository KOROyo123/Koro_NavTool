import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import FluentUI 1.0
import "../window"
import "../global"

FluScrollablePage{

    FluButton{
        onClicked: {
            GlobalSetting.displayMode=2
            GlobalSetting.displayName="xxxxxx"

            console.log(GlobalSetting.displayName)
        }
    }

}

