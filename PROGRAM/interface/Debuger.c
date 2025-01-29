//  boal 14.02.06 меню дебугера
string totalInfo;
int idLngFile = -1;
int remInt = 0;
int BOAL_debug_num = 1;
void InitInterface(string iniName)
{
StartAboveForm(true);
GameInterface.title = "titleBoal_Debug";
SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
CalculateInfoData();
CalculateCheatsInfo();
SetFormatedText("INFO_TEXT",totalInfo);
SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);
SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
SetEventHandler("exitCancel","ProcessCancelExit",0);
SetEventHandler("evntDoPostExit","DoPostExit",0);
SetEventHandler("ievnt_command","ProcCommand",0);
SetEventHandler("SetScrollerPos","SetScrollerPos",0);
SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
SetEventHandler("ScrollTopChange","ProcScrollChange",0);
GameInterface.reload_edit.str = "Pirates_Shipyard, reload, reload1";
}
void ProcessBreakExit()
{
IDoExit( RC_INTERFACE_QUICK_SAVE );
}
void ProcessCancelExit()
{
IDoExit( RC_INTERFACE_QUICK_SAVE );
}
void IDoExit(int exitCode)
{
EndAboveForm(true);
DelEventHandler("InterfaceBreak","ProcessBreakExit");
DelEventHandler("exitCancel","ProcessCancelExit");
DelEventHandler("evntDoPostExit","DoPostExit");
DelEventHandler("ievnt_command","ProcCommand");
DelEventHandler("SetScrollerPos","SetScrollerPos");
DelEventHandler("ScrollPosChange","ProcScrollPosChange");
DelEventHandler("ScrollTopChange","ProcScrollChange");
if(bSeaActive)
{
RefreshBattleInterface();
}
interfaceResultCommand = exitCode;
EndCancelInterface(true);
}
void DoPostExit()
{
int exitCode = GetEventData();
IDoExit(exitCode);
}
void CalculateInfoData()
{
// тут высчитываем нужную информацию и выводим в totalInfo - Инициализация -->
totalInfo = "This is cheat menu. Buttons: "+NewStr();
totalInfo = totalInfo + "F1 - " + descF1 + NewStr() +
"F2 - " + descF2 + NewStr() +
"F3 - " + descF3 + NewStr() +
"F4 - " + descF4 + NewStr() +
"F5 - " + descF5 + NewStr() +
"F6 - " + descF6 + NewStr() +
"F7 - " + descF7 + NewStr() +
"F8 - " + descF8 + NewStr() +
"F9 - " + descF9 + NewStr() +
"F10 - " + descF10 + NewStr() +
"F11 - " + descF11 + NewStr() +
"F12 - " + descF12 + NewStr() +
"F13 - " + descF13 + NewStr() +
"F14 - " + descF14 + NewStr() +
"F15 - " + descF15 + NewStr() +
"F16 - " + descF16 + NewStr() +
"F17 - " + descF17 + NewStr() +
"F18 - " + descF18 + NewStr() +
"F19 - " + descF19 + NewStr() +
"F20 - " + descF20 + NewStr() +
"F21 - " + descF21 + NewStr() +
"F22 - " + descF22 + NewStr() +
"F23 - " + descF23 + NewStr() +
"F24 - " + descF24 + NewStr() +
"F25 - " + descF25 + NewStr() +
"F26 - " + descF26 + NewStr() +
"F27 - " + descF27 + NewStr() +
"F28 - " + descF28 + NewStr() +
"F29 - " + descF29 + NewStr() +
"F30 - " + descF30 + NewStr();
// перевод строки (по другому у меня не вышло) +LanguageConvertString(idLngFile,"new_string");
// тут высчитываем нужную информацию и выводим в totalInfo <--
}
void ProcCommand()
{
string comName = GetEventData();
string nodName = GetEventData();
switch(nodName)
{
case "B_F1":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF1();
}
break;
case "B_F2":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF2();
}
break;
case "B_F3":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF3();
}
break;
case "B_F4":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF4();
}
break;
case "B_F5":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF5();
}
break;
case "B_F6":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF6();
}
break;
case "B_F7":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF7();
}
break;
case "B_F8":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF8();
}
break;
case "B_F9":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF9();
}
break;
case "B_F10":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF10();
}
break;
case "B_F11":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF11();
}
break;
case "B_F12":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF12();
}
break;
case "B_F13":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF13();
}
break;
case "B_F14":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF14();
}
break;
case "B_F15":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF15();
}
break;
case "B_F16":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF16();
}
break;
case "B_F17":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF17();
}
break;
case "B_F18":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF18();
}
break;
case "B_F19":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF19();
}
break;
case "B_F20":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF20();
}
break;
case "B_F21":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF21();
}
break;
case "B_F22":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF22();
}
break;
case "B_F23":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF23();
}
break;
case "B_F24":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF24();
}
break;
case "B_F25":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF25();
}
break;
case "B_F26":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF26();
}
break;
case "B_F27":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF27();
}
break;
case "B_F28":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF28();
}
break;
case "B_F29":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF29();
}
break;
case "B_F30":
if(comName=="activate" || comName=="click")
{
CalculateInfoDataF30();
}
break;
case "B_RELOAD":
if(comName=="activate" || comName=="click")
{
ReloadByStr();
}
break;
}
CalculateCheatsInfo();
}
string descF1 = "Delete Sea!";
void CalculateInfoDataF1()
{
totalInfo = descF1;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
DeleteSea();
Statistic_AddValue(PChar, "Cheats.F1", 1);
}
string descF2 = "Create Sea!";
void CalculateInfoDataF2()
{
totalInfo = descF2;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
CreateSea(EXECUTE, REALIZE);
Statistic_AddValue(PChar, "Cheats.F2", 1);
}
string descF3 = "Weather Create Sea Environment!";
void CalculateInfoDataF3()
{
totalInfo = descF3;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
WhrCreateSeaEnvironment();
Statistic_AddValue(PChar, "Cheats.F3", 1);
}
string descF4 = "Reload Sea!";
void CalculateInfoDataF4()
{
totalInfo = descF4;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Sea_ReloadStart();
Statistic_AddValue(PChar, "Cheats.F4", 1);
}
string descF5 = "Delete Weather";
void CalculateInfoDataF5()
{
totalInfo = descF5;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
DeleteWeatherEnvironment();
DeleteWeather();
Statistic_AddValue(PChar, "Cheats.F5", 1);
}
string descF6 = "Update Weather";
void CalculateInfoDataF6()
{
totalInfo = descF6;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Whr_UpdateWeather();
Statistic_AddValue(PChar, "Cheats.F6", 1);
}
string descF7 = "Recreate Weather Environment";
void CalculateInfoDataF7()
{
totalInfo = descF7;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
CreateWeatherEnvironment();
Statistic_AddValue(PChar, "Cheats.F7", 1);
}
string descF8 = "Output Weather";
void CalculateInfoDataF8()
{
if(GetAttributesNum(&Weather) > 0){
Log_SetStringToLog("Weather has attributes");
}
else{
Log_SetStringToLog("Weather has no attributes");
}
}
string descF9 = "Fix Weather";
void CalculateInfoDataF9()
{
totalInfo = descF9;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
DeleteWeatherEnvironment();
CreateSea(EXECUTE, REALIZE);
Whr_UpdateWeather();
SetEventHandler("frame", "LoadNextWeather_frame", 1);
Statistic_AddValue(PChar, "Cheats.F9", 1);
}
string descF10 = "Load 'next' weather 0";
void CalculateInfoDataF10()
{
totalInfo = descF10;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Whr_LoadNextWeather(0);
Statistic_AddValue(PChar, "Cheats.F10", 1);
}
string descF11 = "Dump Weather and Sky";
void CalculateInfoDataF11()
{
totalInfo = descF11;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
trace("====DUMPING WEATHER====")
DumpAttributes(&Weather);
trace("====DUMPING SKY====")
DumpAttributes(&Sky);
Statistic_AddValue(PChar, "Cheats.F11", 1);
}
string descF12 = "Enable or disable the main character's immortality.";
void CalculateInfoDataF12()
{
totalInfo = descF12;
PlaySound("interface\knock.wav");
if(LAi_IsImmortal(pchar))
{
LAi_SetImmortal(pchar, false);
}else{
LAi_SetImmortal(pchar, true);
}
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F12", 1);
}
string descF13 = "Enable or disable logging for quests.";
void CalculateInfoDataF13()
{
totalInfo = descF13;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bQuestLogShow = !bQuestLogShow;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F13", 1);
}
string descF14 = "Enable or disable the permanent surrender of captains.";
void CalculateInfoDataF14()
{
totalInfo = descF14;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
TestRansackCaptain = !TestRansackCaptain;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F14", 1);
}
string descF15 = "Enable or disable display of locators.";
void CalculateInfoDataF15()
{
totalInfo = descF15;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bLocatorShow = !bLocatorShow;
if(bLocatorShow)
{
ShowAllLocators();
worldMap.debug = true;
worldMap.evwin = true;
}
else
{
HideAllLocators();
worldMap.debug = false;
worldMap.evwin = false;
}
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F15", 1);
}
string descF16 = "Enable or disable experience logs.";
void CalculateInfoDataF16()
{
totalInfo = descF16;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bExpLogShow = !bExpLogShow;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F16", 1);
}
string descF17 = "Enable or disable provision spending.";
void CalculateInfoDataF17()
{
totalInfo = descF17;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bNoEatNoRats = !bNoEatNoRats;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F17", 1);
}
string descF18 = "Enable or disable the progress logs of other captains.";
void CalculateInfoDataF18()
{
totalInfo = descF18;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bPGGLogShow = !bPGGLogShow;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F18", 1);
}
string descF19 = "Enable or disable free camera mode.";
void CalculateInfoDataF19()
{
totalInfo = descF19;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
locCameraEnableFree = !locCameraEnableFree;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F19", 1);
}
string descF20 = "Enable or disable ships on the global map.";
void CalculateInfoDataF20()
{
totalInfo = descF20;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
if(CheckAttribute(pchar,"worldmapencountersoff")== 0)
{
pchar.worldmapencountersoff = "1";
}
else
{
if(pchar.worldmapencountersoff == "1")
{
pchar.worldmapencountersoff = "0";
}
else
{
pchar.worldmapencountersoff = "1";
}
}
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F20", 1);
}
string descF21 = "Enable or disable the beta test mode.";
void CalculateInfoDataF21()
{
totalInfo = descF21;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bBettaTestMode = !bBettaTestMode;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F21", 1);
}
string descF22 = "Enable or disable experience logs.";
void CalculateInfoDataF22()
{
totalInfo = descF22;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
bExpLogShow = !bExpLogShow;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F22", 1);
}
string descF23 = "Repair all the ships and replenish the crew.";
void CalculateInfoDataF23()
{
totalInfo = descF23;
PlaySound("interface\knock.wav");
int idxLoadLoc = FindLoadedLocation();
if(idxLoadLoc != -1 && !bSeaActive)
{
RepairAllShips();
SetCrewQuantityFull(pchar);
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
}
else
{
totalInfo = totalInfo + NewStr() + NewStr() + "You must be in a location (not sea or global map).";
}
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F23", 1);
}
string descF24 = "+ 10 units to the experience of the crew on the main character's ship.";
void CalculateInfoDataF24()
{
totalInfo = descF24;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
ChangeCrewExp(pchar, "Sailors", 10);
ChangeCrewExp(pchar, "Cannoners", 10);
ChangeCrewExp(pchar, "Soldiers", 10);
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F24", 1);
}
string descF25 = "Add money: 50000000.";
void CalculateInfoDataF25()
{
totalInfo = descF25;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
Pchar.money = sti(Pchar.money) + 50000000;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F25", 1);
}
string descF26 = "+2200 points for skills.";
void CalculateInfoDataF26()
{
totalInfo = descF26;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
pchar.Skill.FreeSkill = sti(pchar.Skill.FreeSkill) + 2200;
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.26", 1);
}
string descF27 = "Tavern Teleport.";
void CalculateInfoDataF27()
{
totalInfo = descF27;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
TeleportToLocWithNPC("tavernman");
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F27", 1);
}
string descF28 = "+ 5 days.";
void CalculateInfoDataF28()
{
totalInfo = descF28;
PlaySound("interface\knock.wav");
LAi_Fade("", "");
AddDataToCurrent(0, 0, 5);
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F28", 1);
}
string descF29 = "+ 20 days.";
void CalculateInfoDataF29()
{
totalInfo = descF29;
PlaySound("interface\knock.wav");
LAi_Fade("", "");
AddDataToCurrent(0, 0, 20);
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F29", 1);
}
string descF30 = "Cheat 30";
void CalculateInfoDataF30()
{
totalInfo = descF30;
PlaySound("interface\knock.wav");
totalInfo = totalInfo + NewStr() + NewStr() + "Success";
SetFormatedText("INFO_TEXT",totalInfo);
Statistic_AddValue(PChar, "Cheats.F30", 1);
}
void ReloadByStr()
{
string  loc = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 0));
string  grp = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 1));
string  ltr = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 2));
int i = FindLocation(loc);
if (i != -1)
{
if(CheckAttribute(&locations[i],"fastreload"))
{
if (GetCityFrom_Sea(locations[i].fastreload) != "")
{
setCharacterShipLocation(pchar, GetCityFrom_Sea(locations[i].fastreload));
setWDMPointXZ(GetCityFrom_Sea(locations[i].fastreload));
}
}
else
{
if (locations[i].type == "seashore" || locations[i].type == "mayak")
{
setCharacterShipLocation(pchar, loc);
setWDMPointXZ(loc);
}
}
DoQuestReloadToLocation(loc, grp, ltr, "");
Log_Info(loc);
Statistic_AddValue(PChar, "Cheats.ReloadByStr", 1);
else
{
Log_Info("Location not found.");
}
}
}
void XI_SetScroller(float pos)
{
SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"QUESTSCROLL",pos);
}
void SetScrollerPos()
{
string nodName = GetEventData();
float pos = GetEventData();
XI_SetScroller(pos);
}
void ProcScrollPosChange()
{
float newPos = GetEventData();
SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",2, newPos);
}
void ProcScrollChange()
{
int changeNum = GetEventData();
if(changeNum==0) return;
string controlNode = "";
if( GetSelectable("INFO_TEXT") ) controlNode = "INFO_TEXT";
if(controlNode!="")
{
if(changeNum>0) {
SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
} else {
SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
}
}
}
void TeleportToLocWithNPC(string sText)
{
ref ch;
int n, idx;
idx = GetCharIDXByParam(sText, "location", pchar.location);
bool ok = true;
while(ok)
{
for(n=0; n<MAX_CHARACTERS; n++)
{
makeref(ch,Characters[n]);
if(CheckAttribute(ch, sText))
{
if(ch.location == "none")continue;
if(n > idx)
{
ok = false;
if(GetCityFrom_Sea(ch.City)!= "")
{
setCharacterShipLocation(pchar, GetCityFrom_Sea(ch.City));
setWDMPointXZ(GetCityFrom_Sea(ch.City));
}
DoQuestReloadToLocation(ch.location,"goto","goto1", "");
break;
}
}
}
idx = -1;
}
}