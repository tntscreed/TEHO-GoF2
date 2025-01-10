void MythQuestComplete(string sQuestName, string qname)
{
ref sld, npchar, sld1, chr;
aref arOldMapPos, arAll, arPass;
int iTemp, i, ShipType, Rank, iChar, SiegeShips, hcrew, iSpace1, iSpace2, n;
float locx, locy, locz, fTemp;
string attrName, Model, Blade, Gun, sTemp, Ship, sQuest;
bool bOk;
int idxLoadLoc;
int iOfficer;
switch(sQuestName)
{
case "Blood0":
StartQuestMovie(true, true, true);
ChangeShowIntarface();
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "quest", "quest1", "Blood1", -1);
break;
case "Blood1":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
sld = characterFromID("Beyns");
ChangeCharacterAddressGroup(sld, "EstateBadRoom1", "reload", "reload1");
sld.dialog.currentnode = "EBStep_1";
LAi_SetActorTypeNoGroup(sld);
LAi_SetStayTypeNoGroup(pchar);
LAi_ActorDialog(sld, pchar, "",  -1.0, 0);
break;
case "Blood2":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorTurnToLocator(Pchar, "sit", "sit2");
sld = characterFromID("Beyns");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorGoToLocator(sld, "quest", "quest2", "Blood3", -1);
break;
case "Blood3":
sld = characterFromID("Beyns");
LAi_ActorAnimation(sld, "Barman_idle", "Blood4", 5);
break;
case "Blood4":
sld = characterFromID("Beyns");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorGoToLocator(sld, "reload", "reload1", "Blood5", -1);
break;
case "Blood5":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "quest", "quest2", "Blood6", -1);
sld = characterFromID("Beyns");
LAi_ActorTurnToLocator(sld, "sit", "sit2");
break;
case "Blood6":
LAi_ActorAnimation(pchar, "Barman_idle", "Blood7", 5);
break;
case "Blood7":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "quest", "quest3", "Blood8", -1);
break;
case "Blood8":
LAi_ActorTurnToLocator(Pchar, "sit", "sit2");
LAi_ActorAnimation(Pchar, "Barman_idle", "Blood9", 5);
break;
case "Blood9":
EndQuestMovie();
ChangeShowIntarface();
LAi_SetPlayerType(Pchar);
sld = &characters[GetCharacterIndex("Beyns")];
ChangeCharacterAddressGroup(sld, "EstateOffice", "goto", "goto6");
DoQuestReloadToLocation("EstateOffice", "goto", "goto3", "Blood10");
break;
case "Blood10":
sld = &characters[GetCharacterIndex("Beyns")];
sld.dialog.currentnode = "EBStep_2";
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialogNow(sld, pchar, "", -1);
InterfaceStates.Buttons.Save.enable = true;
break;
case "Blood11":
chrDisableReloadToLocation = true;
DoQuestReloadToLocation("Estate", "reload", "reload5", "Blood12");
break;
case "Blood12":
pchar.quest.Blood12Check.win_condition.l1 = "Ready_Fight";
pchar.quest.Blood12Check.win_condition = "Blood13";
break;
case "Blood13":
LAi_SetActorType(pchar);
LAi_ActorRunToLocator(pchar, "goto", "goto8", "Blood14", -1);
break;
case "Blood14":
StartQuestMovie(true, true, true);
DragunInvansion3();
break;
case "Blood15":
LAi_SetCurHPMax(Pchar);
LAi_SetPlayerType(Pchar);
LAi_SetImmortal(Pchar, false);
DeleteAttribute(Pchar, "items");
DeleteAttribute(Pchar, "equip");
DeleteAttribute(Pchar, "ship");
DeleteAttribute(Pchar, "ShipSails.gerald_name");
Pchar.ship.type = SHIP_NOTUSED;
Pchar.money = 0;
sld = &characters[GetCharacterIndex("Bridgetown_Mayor")];
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart.c";
sld.name = "Artur";
sld.lastname = "Steed";
Environment.date.month = 4;
SetCurrentTime(23, 1);
pchar.quest.onPlantation.win_condition.l1 = "location";
pchar.quest.onPlantation.win_condition.l1.location = "BridgeTown_Plantation";
pchar.quest.onPlantation.function = "CapBloodLine_q1";
n = FindLocation("Bridgetown_town");
locations[n].reload.l3.close_for_night = false;
bDisableLandEncounters = true;
PostVideoAndQuest("slave", 100, "Blood22");
break;
case "Blood16":
LAi_group_SetRelation("TmpEnemy", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
InterfaceStates.Buttons.Save.enable = false;
InterfaceStates.Launched = true;
LAi_SetFightMode(pchar, false);
DoQuestFunctionDelay("Blood_StartGame_End", 1.5);
break;
case "Blood17":
for (i=0; i<=2; i++)
{
sld = characterFromID("Dragun_"+i);
if (i == 0)
{
LAi_RemoveCheckMinHP(sld);
LAi_KillCharacter(sld);
}
else
{
sQuest = "CapGobartAttack_"+i;
pchar.quest.(sQuest).win_condition.l1 = "NPC_Death";
pchar.quest.(sQuest).win_condition.l1.character = sld.id;
pchar.quest.(sQuest).function = "CapGobartAttack";
LAi_SetImmortal(sld, false);
LAi_SetWarriorTypeNoGroup(sld);
LAi_warrior_DialogEnable(sld, false);
LAi_group_MoveCharacter(sld, "TmpEnemy");
}
}
break;
case "Blood18":
sld = characterFromID("Bishop");
sld.talker = 10;
LAi_SetOwnerTypeNoGroup(sld);
break;
case "Blood19":
sld = characterFromID("Nettl");
LAi_SetSitTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit8");
break;
case "Blood20":
chr = characterFromID("ArabelaService");
sld = characterFromID("SpaRaider");
LAi_ActorAfraid(chr, sld, true);
LAi_SetPatrolTypeNoGroup(sld);
break;
case "Blood21":
chrDisableReloadToLocation = false;
LocatorReloadEnterDisable("BridgeTown_town", "reloadShip", false);
sld = characterFromID("SpaFirstMate");
LAi_group_MoveCharacter(sld, "EnemyFight");
break;
case "Blood22":
pchar.quest.Blood22.win_condition.l1 = "location";
pchar.quest.Blood22.win_condition.l1.location = "Plantation_S1";
pchar.quest.Blood22.function = "CapBloodLine_firstEnterHome";
StartPictureAsVideo("Loading\finalbad2.tga.tx", 1);
DoReloadCharacterToLocation("Plantation_S1", "goto", "goto1");
DoQuestFunctionDelay("FadeDelay", 0.1);
break;
}
}