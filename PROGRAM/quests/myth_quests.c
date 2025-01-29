void MythQuestComplete(string sQuestName, string qname)
{
ref sld, npchar, sld1, chr;
aref arOldMapPos, arAll, arPass;
int iTemp, i, ShipType, Rank, iChar, SiegeShips, hcrew, iSpace1, iSpace2, n;
float locx, locy, locz, fTemp;
string attrName, Model, Blade, Gun, sTemp, Ship, sQuest, sGunPowder;
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
LAi_ActorDialog(sld, pchar, "", -1.0, 0);
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
sld = characterFromID("Beyns");
ChangeCharacterAddressGroup(sld, "EstateOffice", "goto", "goto6");
DoQuestReloadToLocation("EstateOffice", "goto", "goto3", "Blood10");
break;
case "Blood10":
sld = characterFromID("Beyns");
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
pchar.quest.Blood12Check.win_condition.l1.Type = "Full";
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
LAi_SetStayType(Pchar);
DeleteAttribute(Pchar, "equip");
DeleteAttribute(Pchar, "items");
DeleteAttribute(Pchar, "ship");
DeleteAttribute(Pchar, "ShipSails.gerald_name");
RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
Pchar.ship.type = SHIP_NOTUSED;
Pchar.money = 0;
sld = characterFromID("Bridgetown_Mayor");
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
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
LAi_SetImmortal(pchar, false);
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
case "Blood_add0":
sld = characterFromID("Waker");
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorDialog(pchar, sld, "", -1.0, 0);
break;
case "Blood_add1":
pchar.quest.Blood_add1Check.win_condition.l1 = "location";
pchar.quest.Blood_add1Check.win_condition.l1.location = "BridgeTown_town";
pchar.quest.Blood_add1Check.win_condition = "Blood_add2";
break;
case "Blood_add2":
sld = characterFromID("Den");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorTurnToCharacter(sld, pchar);
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorWaitDialog(sld, pchar);
LAi_ActorDialog(pchar, sld, "", -1.0, 0);
sld = characterFromID("MisStid");
sld.talker = 10;
break;
case "Blood_add3":
pchar.quest.Blood_add3Check.win_condition.l1 = "Ready_Fight";
pchar.quest.Blood_add3Check.win_condition.l1.Type = "Blade";
pchar.quest.Blood_add3Check.win_condition = "Blood_add4";
break;
case "Blood_add4":
chrDisableReloadToLocation = false;
break;
case "Blood_add5":
LAi_group_SetAlarm("TmpEnemy", LAI_GROUP_PLAYER, 0);
sld = characterFromID("Griffin");
LAi_SetStayType(sld);
sld.dialog.currentnode = "GRStep_14";
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorDialog(pchar, sld, "pchar_back_to_player", -1.0, 0);
break;
case "Blood_add6":
LAi_group_SetAlarm("TmpEnemy", LAI_GROUP_PLAYER, 0);
pchar.quest.Blood_add6Check.win_condition.l1 = "item";
pchar.quest.Blood_add6Check.win_condition.l1.item = "Griffins_Weapon";
pchar.quest.Blood_add6Check.win_condition = "Blood_add4";
sld = characterFromID("Griffin");
sld.talker = 10;
break;
case "RomanticQuest_Bermudes":
if(pchar.sex == "man")
{
pchar.RomanticQuest = "canTakeQuest";
n = rand (20) + 10;
sld = GetCharacter(NPC_GenerateCharacter("Atilla", "Usurer_3", "man", "man", 22, PIRATE, -1, false, "quest"));
sld.name = "Atilla";
GiveItem2Character(sld, GUN_COMMON);
sld.equip.gun = GUN_COMMON;
GiveItem2Character(sld, BLADE_LONG);
sld.equip.blade = BLADE_LONG;
sld.location = "Pirates_town";
sld.location.group = "goto";
sld.location.locator = "goto1";
sld.Dialog.Filename = "Coas_quests\Isabella\Atilla.c";
sld.greeting = "Gr_Smuggler Agent";
sld.rank = 25;
sld.reputation = "30";
sld.talker = 10;
SetRandSPECIAL(sld);
SetSelfSkill(sld, 80, 70, 90, 60, 50);
SetShipSkill(sld, 50, 10, 60, 60, 40, 70, 70, 40, 50);
sld.money = "200";
LAi_SetCitizenType(sld);
LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
LAi_SetLoginTime(sld, 0.0, 24.0);
LAi_SetHP(sld, 200.0, 200.0);
LAi_NoRebirthEnable(sld);
sld.DontClearDead = true;
sld.greeting = "Gr_Atilla";
LAi_SetImmortal(sld, true);
sGunpowder = LAi_GetCharacterGunpowderType(sld);
TakeNItems(sld, LAi_GetCharacterBulletType(sld), n);
if(sGunPowder != "")
{
AddItems(sld, sGunpowder, n);
}
n = rand (20) + 10;
sld = GetCharacter(NPC_GenerateCharacter("Husband", "Usurer_7", "man", "man", 22, PIRATE, -1, false, "quest"));
sld.name = "Salvatore";
sld.lastname = "Olivares";
sld.location = "SanJuan_houseSp6";
sld.location.group = "goto";
sld.location.locator = "goto2";
sld.Dialog.Filename = "Coas_quests\Isabella\Husband.c";
GiveItem2Character(sld, "pistol5");
sld.equip.gun = "pistol5";
TakeNItems(sld, LAi_GetCharacterBulletType(sld), n);
if(sGunPowder != "")
{
AddItems(sld, sGunpowder, n);
}
GiveItem2Character(sld, "GOF_blade34");
sld.equip.blade = "GOF_blade34";
sld.rank = 40;
sld.reputation = "35";
SetRandSPECIAL(sld);
SetSelfSkill(sld, 90, 90, 90, 70, 90);
SetShipSkill(sld, 20, 90, 10, 10, 10, 20, 10, 10, 50);
sld.money = "1000";
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
LAi_SetLoginTime(sld, 0.0, 24.0);
LAi_SetHP(sld, 220.0, 220.0);
LAi_SetHuberStayType(sld);
LAi_SetStayHuberPointWindow(sld, "goto", "goto1");
LAi_SetStayHuberPointMap(sld, "goto", "goto2");
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
LAi_SetImmortal(sld, true);
LAi_LoginInCaptureTown(sld, true);
sld.greeting = "Gr_OliverTrast";
sld.talker = 10;
sld = GetCharacter(NPC_GenerateCharacter("Isabella", "lady_2", "woman", "towngirl", 8, SPAIN, -1, false, "quest"));
sld.name = "Isabella";
sld.lastname = "Olevares";
sld.location = "SanJuan_houseS1Bedroom";
sld.location.group = "goto";
sld.location.locator = "goto4";
sld.Dialog.Filename = "Coas_quests\Isabella\Isabella.c";
sld.nation = SPAIN;
sld.rank = 8;
sld.DontClearDead = true;
sld.money = "10000";
LAi_NoRebirthEnable(sld);
LAi_SetStayType(sld);
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
LAi_SetLoginTime(sld, 0.0, 24.0);
LAi_SetHP(sld, 75.0, 75.0);
sld.greeting = "Isabella";
sld.talker = 10;
LAi_SetImmortal(sld, true);
}
else
{
pchar.RomanticQuest = "NoMan";
}
break;
case "Romantic_Pirat_toTavern":
chrDisableReloadToLocation = true;
bDisableFastReload = true;
FreeSitLocator("Pirates_tavern", "sit2");
DoQuestReloadToLocation("Pirates_tavern", "sit", "sit2", "");
sld = characterFromID("Atilla");
LAi_SetActorType(sld);
LAi_ActorSetSitMode(sld);
LAi_ActorDialogDelay(sld, pchar, "", 1.5);
break;
case "Romantic_Pirat_toTavern_end":
chrDisableReloadToLocation = false;
bDisableFastReload = false;
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
pchar.RomanticQuest = "toSalvator";
AddQuestRecord("Romantic_Line", "3");
LAI_SetPlayerType(pchar);
DoQuestReloadToLocation("Pirates_tavern", "tables", "stay3", "");
sld = CharacterFromID("Atilla");
LAI_SetSitType(sld);
Pchar.quest.Romantic_TalkInShop.win_condition.l1 = "location";
Pchar.quest.Romantic_TalkInShop.win_condition.l1.location = "SanJuan_Store";
Pchar.quest.Romantic_TalkInShop.win_condition = "Romantic_TalkInShop";
PChar.quest.Romantic_TalkInShop.again = true;
PChar.quest.Romantic_TalkInShop.DontCheck = true;
break;
case "RP_afterVisitBedroom":
chrDisableReloadToLocation = true;
bDisableFastReload = true;
sld = characterFromID("Husband");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, Pchar, "", -1, 0);
break;
case "RP_talkWithHusbandIsOver":
LAi_SetStayType(characterFromID("Husband"));
break;
case "Romantic_TalkInShop":
if(CheckAttribute(Pchar, "RomanticQuest.TalkInShop"))
{
PChar.quest.Romantic_TalkInShop.over = "yes";
characters[GetCharacterIndex("SanJuan_trader")].dialog.currentnode = "Romantic_1";
sld = CharacterFromID("Isabella");
LAi_SetStayType(sld);
ChangeCharacterAddressGroup(sld, PChar.location, "goto", "goto3");
sld.dialog.currentnode = "TalkInShop";
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "Romantic_TalkInShop_3", -1, 0);
}
break;
case "Romantic_TalkInShop_2":
sld = characterFromID("Isabella");
LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
break;
case "Romantic_TalkInShop_3":
sld = CharacterFromID("SanJuan_trader");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, Pchar, "", 0.0, 0);
break;
case "Romantic_TalkInShop_end":
chrDisableReloadToLocation = false;
LAi_SetStayType(characterFromID("SanJuan_trader"));
LAI_SetPlayerType(Pchar);
AddQuestRecord("Romantic_Line", "4");
sld = CharacterFromID("Isabella");
LAi_SetCitizenType(sld);
sld.dialog.currentnode = "TalkInChurch";
DoQuestCheckDelay("SetIsabellaTalker", 4.0);
break;
case "SetIsabellaTalker":
sld = characterFromID("Isabella");
sld.talker = 10;
Pchar.RomanticQuest.PriestAsk = true;
break;
case "Romantic_Battle_in_Bedroom_1":
sld = CharacterFromID("Husband");
ChangeCharacterAddressGroup(sld, "SanJuan_houseS1Bedroom", "reload", "reload1");
LAi_SetActorType(Pchar);
LAi_SetActorType(sld);
LAi_ActorFollow(sld, Pchar, "Romantic_Battle_in_Bedroom_2", 3.0);
break;
case "Romantic_Battle_in_Bedroom_2":
sld = CharacterFromID("Husband");
sld.Dialog.CurrentNode = "Romantic_Battle_in_Bedroom";
LAi_ActorWaitDialog(Pchar, sld);
LAi_ActorDialog(sld, Pchar, "", 2.0, 0);
break;
case "Romantic_Battle_in_Bedroom_3":
pchar.quest.RP_afterVisitBedroom.over = "yes";
chrDisableReloadToLocation = true;
bDisableFastReload = true;
LAi_SetPlayerType(pchar);
ChangeCharacterReputation(pchar, -15);
sld = CharacterFromID("Husband");
Lai_SetImmortal(sld, false);
LAi_SetWarriorType(sld);
LAi_group_MoveCharacter(sld, "TmpEnemy");
LAi_group_SetHearRadius("TmpEnemy", 100.0);
LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
LAi_group_SetCheck("TmpEnemy", "Romantic_Battle_in_Bedroom_End");
break;
case "Romantic_Battle_in_Bedroom_End":
chrDisableReloadToLocation = false;
bDisableFastReload = false;
sld = CharacterFromID("Isabella");
sld.Dialog.CurrentNode = "Murder";
AddQuestRecord("Romantic_Line", "1");
LAi_group_SetAlarm("TmpEnemy", LAI_GROUP_PLAYER, 0);
CloseQuestHeader("Romantic_Line");
break;
case "Romantic_Battle_in_Bedroom_4":
LAi_SetPlayerType(pchar);
sld = CharacterFromID("Husband");
LAi_ActorRunToLocation(sld, "reload", "reload1", "SanJuan_houseSp6", "goto", "goto5", "Romantic_Battle_in_Bedroom_5", 2.0);
AddQuestRecord("Romantic_Line", "2");
break;
case "Romantic_Battle_in_Bedroom_5":
sld = CharacterFromID("Husband");
LAi_SetHuberStayType(sld);
LAi_SetStayHuberPointWindow(sld, "goto", "goto1");
LAi_SetStayHuberPointMap(sld, "goto", "goto2");
break;
case "Romantic_TalkInChurch_end":
sld = CharacterFromID("Isabella");
LAi_SetStayType(sld);
chrDisableReloadToLocation = false;
bDisableFastReload = false;
break;
case "Romantic_Brother":
chrDisableReloadToLocation = true;
bDisableFastReload = true;
Pchar.GenQuest.Hunter2Pause = true;
sld = GetCharacter(NPC_GenerateCharacter("MigelDeValdes", "citiz_9", "man", "man", 5, SPAIN, -1, true, "quest"));
sld.name = "Miguel";
sld.lastname = "de Valdez";
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
sld.dialog.currentnode = "Romantic_Brother_1";
sld.greeting = "Gr_YoungMan";
LAi_SetImmortal(sld, true);
PlaceCharacter(sld, "goto", "random_must_be_near");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", 1.5, 0);
break;
case "Romantic_Brother_port":
chrDisableReloadToLocation = true;
Pchar.GenQuest.Hunter2Pause = true;
sld = CharacterFromID("MigelDeValdes");
sld.dialog.currentnode = "Romantic_Brother_port_1";
GetCharacterPos(pchar, &locx, &locy, &locz);
ChangeCharacterAddressGroup(sld, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", 0.5, 0);
break;
case "Romantic_Brother_House":
pchar.RomanticQuest = "exitFromDetector";
sld = CharacterFromID("Isabella");
sld.dialog.currentnode = "Brother_1";
ChangeCharacterAddressGroup(sld, "SanJuan_houseSp6", "goto", "goto3");
LAi_SetActorType(sld);
sld = CharacterFromID("MigelDeValdes");
sld.dialog.currentnode = "Romantic_Brother_port_1";
ChangeCharacterAddressGroup(sld, "SanJuan_houseSp6", "goto", "goto4");
LAi_SetActorType(sld);
break;
case "Romantic_Brother_House_3":
SetMainCharacterIndex(1);
PChar = GetMainCharacter();
LAi_SetPlayerType(PChar);
locCameraTarget(PChar)
locCameraFollow();
EndQuestMovie();
sld = characterFromID("Isabella");
sld.talker = 10;
LAi_SetCitizenType(sld);
sld = characterFromID("MigelDeValdes");
LAi_SetCitizenType(sld);
sld.dialog.currentnode = "Romantic_Brother_Thanks";
sld = characterFromID("Husband");
sld.dialog.currentnode = "WeWaitYouTonight";
pchar.RomanticQuest = "DelivMigel";
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", true);
break;
case "Romantic_DeadBrother_1":
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
chrDisableReloadToLocation = true;
SetMainCharacterIndex(1);
PChar = GetMainCharacter();
LAi_SetPlayerType(PChar);
locCameraTarget(PChar)
locCameraFollow();
npchar = characterFromID("MigelDeValdes");
LAi_group_MoveCharacter(npchar, "BrotherGroup");
sld = characterFromID("Husband");
LAi_SetWarriorType(sld);
LAi_group_MoveCharacter(sld, "HusbandGroup");
LAi_group_SetRelation("HusbandGroup", "BrotherGroup", LAI_GROUP_ENEMY);
LAi_group_FightGroups("HusbandGroup", "BrotherGroup", true);
LAi_group_SetCheck("BrotherGroup", "Romantic_DeadBrother_2");
LAi_LockFightMode(pchar, true);
EndQuestMovie();
break;
case "Romantic_DeadBrother_2":
LAi_group_Delete("BrotherGroup");
sld = characterFromID("Husband");
sld.dialog.currentnode = "SeenMainHero";
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 1.0, 0);
break;
case "OpenTheDoors_R":
LAi_SetFightMode(pchar, false);
LAi_group_SetAlarm("EnemyFight", LAI_GROUP_PLAYER, 0);
chrDisableReloadToLocation = false;
bDisableFastReload = false; 
sld = characterFromID("Husband");
sld.talker = 10;
LAi_SetFightMode(pchar, false);
break;
case "Romantic_DeadBrother_3":
ChangeCharacterAddress(CharacterFromID("Isabella"), "none", "");
sld = characterFromID("Husband");
LAi_SetCitizenType(sld);
LocatorReloadEnterDisable("SanJuan_houseSp6", "reload2", true);
LAi_LocationFightDisable(&Locations[FindLocation("SanJuan_houseSp6")], true);
break;
case "Romantic_DeadBrother_Cancel":
pchar.RomanticQuest = "QuestOver";
ChangeCharacterAddress(CharacterFromID("Husband"), "none", "");
ChangeCharacterAddress(CharacterFromID("MigelDeValdes"), "none", "");
CloseQuestHeader("Romantic_Line");
break;
case "Romantic_ArrestInHouse":
sld = characterFromID("Atilla");
LAi_SetSitType(sld);
ChangeCharacterAddressGroup(sld, "Pirates_houseF1", "sit", "sit2");
sld.dialog.currentnode = "TalkingNews";
npchar = characterFromID("Husband");
LAi_SetActorType(npchar);
LAi_ActorRunToLocation(npchar, "reload", "reload1", "SanJuan_houseS1Bedroom", "goto", "goto3", "", 5.0);
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", true);
iTemp = FindColony("SanJuan");
sTemp = NationShortName(sti(colonies[iTemp].nation));
for (i=1; i<=3; i++)
{
if (i==1)
{
if (sti(colonies[iTemp].HeroOwn))
{
Model = "officer_18";
}
else
{
Model = "off_" + sTemp + "_1";
}
Rank = sti(pchar.rank)+ MOD_SKILL_ENEMY_RATE + 6;
Blade = "GOF_blade25";
}
else
{
if (sti(colonies[iTemp].HeroOwn))
{
Model = "pirate_" + i;
}
else
{
Model = "sold_" + sTemp + "_" +(rand(7)+1);
}
Rank = sti(pchar.rank)+ MOD_SKILL_ENEMY_RATE + 2;
Blade = "GOF_blade24";
}
sld = GetCharacter(NPC_GenerateCharacter("Soldier_"+i, Model, "man", "man", Rank, sti(colonies[iTemp].nation), 0, true, "quest"));
FantomMakeCoolFighter(sld, Rank, 100, 90, Blade, "pistol5", "bullet",200);
sld.City = colonies[iTemp].id;
sld.CityType = "soldier";
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
sld.dialog.currentnode = "ArrestInHome_2";
LAi_SetWarriorType(sld);
if (i != 1) LAi_warrior_DialogEnable(sld, false);
LAi_group_MoveCharacter(sld, GetNationNameByType(sti(colonies[iTemp].nation)) + "_citizens");
ChangeCharacterAddressGroup(sld, "SanJuan_houseSp6", "reload", "reload1");
}
sld = characterFromID("Soldier_1");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 1.5, 0);
LocatorReloadEnterDisable("Pirates_town", "houseF1", false);
break;
case "Romantic_AtillaToHouse":
sld = characterFromID("Atilla");
LAi_SetSitType(sld);
ChangeCharacterAddressGroup(sld, "Pirates_houseF1", "sit", "sit2");
sld.dialog.currentnode = "AtillaInHouse";
LocatorReloadEnterDisable("Pirates_town", "houseF1", false);
break;
case "Romantic_AmbushInHouse":
chrDisableReloadToLocation = true;
LAi_LocationFightDisable(&locations[FindLocation("SanJuan_houseSp6")], true);
LAi_group_Delete("EnemyFight");
for (i=1; i<=3; i++)
{
sld = GetCharacter(NPC_GenerateCharacter("Bandit"+i, "officer_"+(i+10), "man", "man", 25, PIRATE, 0, true, "quest"));
FantomMakeCoolFighter(sld, 25, 70, 60, BLADE_LONG, "pistol2", "bullet", 20);
LAi_SetStayType(sld);
LAi_CharacterDisableDialog(sld);
LAi_group_MoveCharacter(sld, "EnemyFight");
ChangeCharacterAddressGroup(sld, "SanJuan_houseSp6", "goto", "goto"+i);
}
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
sld.dialog.currentnode = "AmbushBandit";
LAi_CharacterEnableDialog(sld);
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0);
break;
case "Romantic_BrigTimeOver":
pchar.quest.Romantic_AttackBrig.over = "yes";
AddQuestRecord("Romantic_Line", "14");
QuestSetCurrentNode("Atilla", "Brig_Late");
break;
case "Romantic_AttackBrig":
pchar.quest.Romantic_BrigTimeOver.over = "yes";
Island_SetReloadEnableGlobal("PortoBello", false);
Group_FindOrCreateGroup("Pirate_Attack");
Group_SetType("Pirate_Attack", "trade");
sld = GetCharacter(NPC_GenerateCharacter("IsaAttackCap", "officer_14", "man", "man", 20, SPAIN, 0, true, "quest"));
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
sld.dialog.currentnode = "BrigAbordage";
FantomMakeCoolSailor(sld, SHIP_BRIG, "Rapturous", CANNON_TYPE_CANNON_LBS24, 70, 70, 70);
FantomMakeCoolFighter(sld, 20, 70, 50, "GOF_blade24", "pistol3", "bullet", 20);
sld.DontRansackCaptain = true;
sld.Coastal_Captain = true;
sld.AlwaysEnemy = true;
Group_AddCharacter("Pirate_Attack", "IsaAttackCap");
Group_SetGroupCommander("Pirate_Attack", "IsaAttackCap");
Group_SetTaskAttack("Pirate_Attack", PLAYER_GROUP);
Group_SetPursuitGroup("Pirate_Attack", PLAYER_GROUP);
Group_SetAddress("Pirate_Attack", "PortoBello", "", "");
Group_LockTask("Pirate_Attack");
pchar.quest.Romantic_AfterBrigSunk.win_condition.l1 = "Character_sink";
pchar.quest.Romantic_AfterBrigSunk.win_condition.l1.character = "IsaAttackCap";
pchar.quest.Romantic_AfterBrigSunk.win_condition = "Romantic_AfterBrigSunk";
pchar.quest.Romantic_BrigDieHard.win_condition.l1 = "MapEnter";
pchar.quest.Romantic_BrigDieHard.win_condition = "Romantic_BrigDieHard";
break;
case "Romantic_BrigDieHard":
pchar.quest.Romantic_AfterBrigSunk.over = "yes";
group_DeleteGroup("Pirate_Attack");
Island_SetReloadEnableGlobal("PortoBello", true);
AddQuestRecord("Romantic_Line", "16");
QuestSetCurrentNode("Atilla", "Brig_DieHard");
break;
case "Romantic_AfterBrigSunk":
pchar.quest.Romantic_BrigDieHard.over = "yes";
Island_SetReloadEnableGlobal("PortoBello", true);
group_DeleteGroup("Pirate_Attack");
AddQuestRecord("Romantic_Line", "15");
QuestSetCurrentNode("Atilla", "Brig_Sunk");
break;
case "Romantic_TaklInCabinBrig":
LAi_group_SetAlarm(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, 0);
LAi_SetFightMode(pchar, false);
sld = characterFromID("Isabella");
sld.dialog.currentnode = "BrigAbordage";
GetCharacterPos(pchar, &locx, &locy, &locz);
ChangeCharacterAddressGroup(sld, pchar.location, "reload", LAi_FindFarLocator("reload", locx, locy, locz));
LAi_SetActorType(pchar);
LAi_SetActorType(sld);
SetActorDialogAny2Pchar(sld.id, "", 0.0, 0.0);
LAi_ActorFollow(pchar, sld, "ActorDialog_Any2Pchar", -1);
break;
case "Romantic_AmbushInPortoBello":
chrDisableReloadToLocation = true;
LAi_LocationFightDisable(&locations[FindLocation("PortoBello_houseF2")], true);
LAi_group_Delete("EnemyFight");
for (i=1; i<=2; i++)
{
sld = GetCharacter(NPC_GenerateCharacter("Bandit_P"+i, "officer_"+i, "man", "man", 30, PIRATE, 0, true, "quest"));
FantomMakeCoolFighter(sld, 30, 80, 70, "blade_15", "pistol3", "bullet",40);
LAi_SetStayType(sld);
LAi_CharacterDisableDialog(sld);
LAi_group_MoveCharacter(sld, "EnemyFight");
ChangeCharacterAddressGroup(sld, "PortoBello_houseF2", "goto", "goto"+i);
}
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
sld.dialog.currentnode = "AmbushPotroBello";
LAi_CharacterEnableDialog(sld);
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0);
break;
case "Romantic_TalkPortoBello":
LAi_SetFightMode(pchar, false);
LAi_group_SetAlarm("EnemyFight", LAI_GROUP_PLAYER, 0);
chrDisableReloadToLocation = false;
sld = CharacterFromID("Isabella");
sld.dialog.currentnode = "AmbushPortoBello";
ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 1.5);
break;
case "SeekIsabella_exitTown":
sld = CharacterFromID("ServantGirl");
LAi_SetActorType(sld);
LAi_ActorSetLayMode(sld);
LAi_KillCharacter(sld);
chrDisableReloadToLocation = true;
pchar.quest.SeekIsabella_exitTownCheck.win_condition.l1 = "locator";
pchar.quest.SeekIsabella_exitTownCheck.win_condition.l1.location = "Beliz_ExitTown";
pchar.quest.SeekIsabella_exitTownCheck.win_condition.l1.locator_group = "quest";
pchar.quest.SeekIsabella_exitTownCheck.win_condition.l1.locator = "detector1";
pchar.quest.SeekIsabella_exitTownCheck.win_condition = "SeekIsabella_exitTown1";
break;
case "SeekIsabella_exitTown1":
chrDisableReloadToLocation = false;
DeleteAttribute(&locations[FindLocation("Beliz_ExitTown")], "DisableEncounters");
DoQuestCheckDelay("TalkSelf_Quest", 0.1);
break;
case "Romantic_BelizCityTalk":
chrDisableReloadToLocation = true;
Pchar.GenQuest.Hunter2Pause = true;
sld = CharacterFromID("Isabella");
sld.dialog.currentnode = "BelizTalk";
ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto17");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0.0);
break;
case "Romantic_BanditIsDead":
LAi_SetFightMode(pchar, false);
LAi_group_SetAlarm(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, 0);
sld = CharacterFromID("Isabella");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0.0);
break;
case "Romantic_SalvatorInCave":
LAi_LockFightMode(pchar, true);
sld = CharacterFromID("Husband");
sld.dialog.currentnode = "TalkInCave";
sld.items.jewelry5 = 100;
sld.items.jewelry13 = 7;
sld.items.jewelry14 = 6;
sld.items.jewelry15 = 5;
sld.items.jewelry17 = 30;
sld.items.jewelry18 = 12;
sld.items.indian1 = 1;
sld.items.indian5 = 1;
sld.items.indian6 = 1;
sld.items.indian10 = 2;
sld.items.indian12 = 1;
sld.items.indian14 = 1;
sld.items.jewelry12 = 12;
sld.items.jewelry11 = 6;
sld.items.jewelry10 = 20;
sld.items.jewelry7 = 21;
sld.items.jewelry6 = 11;
sld.items.jewelry4 = 7;
sld.items.jewelry3 = 15;
sld.items.jewelry2 = 18;
sld.items.jewelry1 = 31;
sld.money = 350535;
Lai_SetImmortal(sld, false);
ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto7");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0);
break;
case "Romantic_SalvatorIsDead":
LAi_SetFightMode(pchar, false);
LAi_group_SetAlarm("EnemyFight", LAI_GROUP_PLAYER, 0);
LAi_LocationDisableOfficersGen("Beliz_Cave_2", false);
LAi_LocationDisableMonstersGen("Beliz_Cave_2", false);
QuestSetCurrentNode("Isabella", "SalvatorIsDead");
sld = CharacterFromID("Isabella");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0.0);
break;
case "Romantic_DelivToRosita":
if (GetCharacterIndex("Isabella") == -1)
{
QuestSetCurrentNode("Rosita", "IsabellaIsDead_Beliz");
}
else
{
pchar.RomanticQuest = "Beliz_exitFromDetector";
QuestSetCurrentNode("Rosita", "SavedIsabella");
}
break;
case "Romantic_DelivToRosita_2":
SetMainCharacterIndex(1);
PChar = GetMainCharacter();
LAi_SetPlayerType(PChar);
locCameraTarget(PChar)
locCameraFollow();
EndQuestMovie();
LAi_SetCitizenType(characterFromID("Rosita"));
sld = characterFromID("Isabella");
LAi_SetCitizenType(sld);
sld.talker = 10;
sld.dialog.currentnode = "RositaHouse";
SetTimerCondition("Romantic_IsabellaToSanJuan", 0, 1, 0, false);
break;
case "Romantic_IsabellaToSanJuan":
sld = CharacterFromID("Isabella");
ChangeCharacterAddressGroup(sld , "SanJuan_houseSp6", "goto", "goto1");
sld.dialog.currentnode = "InSanJuanAgain";
sld.talker = 10;
break;
case "Romantic_OutFromHouse":
DoReloadCharacterToLocation("SanJuan_town", "reload", "houseSp6");
break;
case "Romantic_Widding_Cancel":
pchar.quest.Isabella_widding.over = "yes";
pchar.RomanticQuest = "QuestOver";
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
sld = characterFromID("Isabella");
LAi_SetStayType(sld);
sld.dialog.currentnode = "Cancel_Widding";
ChangeCharacterAddressGroup(sld , "SanJuan_houseSp6", "goto", "goto1");
sld = CharacterFromID("SanJuan_Priest");
LAi_SetPriestType(sld);
break;
case "Isabella_widding":
pchar.quest.Romantic_Widding_Cancel.over = "yes";
pchar.RomanticQuest = "Widding";
sld = characterFromID("Isabella");
LAi_SetActorType(pchar);
SetActorDialogAny2Pchar(sld.id, "", 0.0, 0.0);
LAi_ActorFollow(pchar, sld, "ActorDialog_Any2Pchar", 0.0);	
break;
case "Romantic_Padre":
LAi_SetActorType(pchar);
LAi_ActorTurnToLocator(pchar, "barmen", "stay");
DoQuestCheckDelay("Romantic_Padre_1", 1.0);
break;
case "Romantic_Padre_1":
SetLaunchFrameFormParam("Forty minutes passed," + NewStr()+" over the course of the service.", "Romantic_Padre_2", 0, 3);
LaunchFrameForm();
WaitDate("", 0, 0, 0, 0, 40);
RecalculateJumpTable();
break;
case "Romantic_Padre_2":
StartQuestMovie(true, true, true);
locCameraToPos(-1.52, 3.25, -3.36, false);
sld = CharacterFromID("SanJuan_Priest");
sld.dialog.currentnode = "Romantic_2";
LAi_SetActorType(sld);
SetActorDialogAny2Pchar("SanJuan_Priest", "", 0.0, 0.0);
LAi_ActorFollow(PChar, sld, "ActorDialog_Any2Pchar", 0.0);
break;
case "Romantic_Padre_3":
LAi_SetPlayerType(PChar);
locCameraTarget(PChar)
locCameraFollow();
EndQuestMovie();
sld = CharacterFromID("Isabella");
LAi_SetActorType(sld);
LAi_ActorTurnToCharacter(sld, pchar);
DoQuestCheckDelay("Romantic_fightInChurch", 2.0);
break;
case "Romantic_fightInChurch":
chrDisableReloadToLocation = true;
LAi_group_Delete("EnemyFight");
iTemp = sti(2+(MOD_SKILL_ENEMY_RATE/1.5));
Rank = 10+MOD_SKILL_ENEMY_RATE*2;
for (i=1; i<=iTemp; i++)
{
sld = GetCharacter(NPC_GenerateCharacter("Bandit"+i, "officer_"+(i+3), "man", "man", Rank, PIRATE, 0, true, "quest"));
FantomMakeCoolFighter(sld, Rank, 80, 70, "blade_15", "pistol1", "bullet", 40);
LAi_SetWarriorType(sld);
LAi_warrior_SetStay(sld, true);
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
LAi_group_MoveCharacter(sld, "EnemyFight");
ChangeCharacterAddressGroup(sld, "SanJuan_church", "reload", "reload1");
}
sld.dialog.currentnode = "AmbushInChurch";
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 1.0, 0);
break;
case "Romantic_fightInChurch_1":
sld = characterFromID("Isabella");
sld.dialog.currentnode = "AmbushInChurch";
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 0, 0);
break;
case "Romantic_fightInChurch_2":
LAi_LocationFightDisable(loadedLocation, false);
sld = characterFromID("SanJuan_Priest");
LAi_SetActorType(sld);
LAi_ActorRunToLocator(sld, "barmen", "bar2", "", -1);
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_SetRelation("EnemyFight", "SPAIN_CITIZENS", LAI_GROUP_ENEMY);
LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
LAi_group_SetCheck("EnemyFight", "Romantic_afterFightInChurch");
sld = characterFromID("Isabella");
LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
GiveItem2Character(sld, "unarmed");
EquipCharacterbyItem(sld, "unarmed");
LAi_SetFightMode(sld, false);
LAi_SetActorTypeNoGroup(sld);
LAi_ActorRunToLocator(sld, "barmen", "bar1", "", -1);
break;
case "Romantic_afterFightInChurch":
chrDisableReloadToLocation = false;
LAi_LocationFightDisable(loadedLocation, true);
sld = CharacterFromID("SanJuan_Priest");
LAi_SetPriestType(sld);
LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
sld = CharacterFromID("Isabella");
LAi_group_SetAlarm("EnemyFight", LAI_GROUP_PLAYER, 0);
if (LAi_IsDead(sld))
{
AddQuestRecord("Romantic_Line", "25");
pchar.RomanticQuest = "IsabellaIsDead";
QuestSetCurrentNode("Atilla", "IsabellaIsDead");
QuestSetCurrentNode("Rosita", "IsabellaIsDead");
}
else
{
LAi_SetFightMode(pchar, false);
AddQuestRecord("Romantic_Line", "26");
pchar.RomanticQuest = "IsabellaIsMyWife";
QuestSetCurrentNode("Atilla", "IsabellaIsMyWife");
QuestSetCurrentNode("Rosita", "IsabellaIsMyWife");
QuestSetCurrentNode("Isabella", "IsabellaIsMyWife");
sld = characterFromID("Isabella");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 1.0, 0);
}
break;
case "Romantic_afterFirstTime":
SaveCurrentQuestDateParam("RomanticQuest");
IsabellaSetCurrentState("all");
IsabellaCheckBreachState();
pchar.RomanticQuest.HorseCheck = pchar.questTemp.HorseQty;
IsabellaNullBudget();
sld = CharacterFromID("Isabella");
sld.greeting = "Gr_Isabella_1";
SaveCurrentNpcQuestDateParam(sld, "sex");
sld.sex.control_year = sti(sld.sex.control_year) - 1;
QuestSetCurrentNode("Rosita", "IsabellaIsWife");
pchar.RomanticQuest = "NewLifeForHero";
AddQuestRecord("Romantic_Line", "28");
AddQuestUserData("Romantic_Line", "IsabellaBuget", FindRussianMoneyString(MOD_SKILL_ENEMY_RATE*10000));
Pchar.quest.Romantic_OutHome.win_condition.l1 = "location";
Pchar.quest.Romantic_OutHome.win_condition.l1.location = "PuertoRico";
Pchar.quest.Romantic_OutHome.win_condition = "Romantic_OutHome";
break;
case "Romantic_EnterHome":
if (CheckAttribute(pchar, "RomanticQuest.State"))
{
IsabellaCheckBreachState();
pchar.RomanticQuest.Cheking = "";
QuestSetCurrentNode("Isabella", "NewLife_hello");
Pchar.quest.Romantic_OutHome.win_condition.l1 = "location";
Pchar.quest.Romantic_OutHome.win_condition.l1.location = "PuertoRico";
Pchar.quest.Romantic_OutHome.win_condition = "Romantic_OutHome";
}
break;
case "Romantic_OutHome":
if (CheckAttribute(pchar, "RomanticQuest.State"))
{
pchar.RomanticQuest = "NewLifeForHero";
SaveCurrentQuestDateParam("RomanticQuest");
Pchar.quest.Romantic_EnterHome.win_condition.l1 = "location";
Pchar.quest.Romantic_EnterHome.win_condition.l1.location = "SanJuan_houseSp6";
Pchar.quest.Romantic_EnterHome.win_condition = "Romantic_EnterHome";
}
break;
case "Romantic_IsabellaBackToHall":
Pchar.quest.Romantic_Sex.over = "yes";
sld = CharacterFromID("Isabella");
LAi_SetStayType(sld);
ChangeCharacterAddressGroup(sld, "SanJuan_houseSp6", "goto", "goto1");
QuestSetCurrentNode("Isabella", "NewLife");
break;
case "sleep_in_home":
DoQuestReloadToLocation("SanJuan_houseS1Bedroom", "goto", "goto4", "restore_hp");
break;
}
}