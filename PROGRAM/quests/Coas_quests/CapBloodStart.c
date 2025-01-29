void Blood_StartGame(string qName)
{
ref sld;
Pchar.BaseNation = ENGLAND;
Pchar.questTemp.CapBloodLine.stat = "Begining";
Pchar.questTemp.CapBloodLine = true;
DeleteAttribute(Pchar, "perks.list.FlagFra");
DeleteAttribute(Pchar, "perks.list.FlagSpa");
DeleteAttribute(Pchar, "perks.list.FlagHol");
SetCharacterPerk(Pchar, "FlagEng");
Flag_ENGLAND();
int n = FindLocation("Bridgetown_town");
DeleteAttribute(&locations[n], "questSeekCap");
DeleteAttribute(&locations[n], "houseEnc");
locations[n].notCloseCommonHouse = true;
n = FindLocation("Bridgetown_tavern");
DeleteAttribute(&locations[n], "habitues");
RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
RemoveCharacterEquip(pchar, SPYGLASS_ITEM_TYPE);
RemoveCharacterEquip(pchar, PATENT_ITEM_TYPE);
RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
RemoveCharacterEquip(pchar, MAPS_ITEM_TYPE);
DeleteAttribute(Pchar, "money");
DeleteAttribute(Pchar, "items");
DeleteAttribute(Pchar, "ship");
DeleteAttribute(Pchar, "ShipSails.gerald_name");
Pchar.ship.type = SHIP_NOTUSED;
TakeNItems(Pchar, "potion3", 1);
TakeNItems(Pchar, "potion2", 3);
TakeNItems(Pchar, "potion1", 4);
SetCharacterPerk(Pchar, "Doctor1");
sld = GetCharacter(NPC_GenerateCharacter("DeadLord", "trader_9", "man", "man", 7, ENGLAND, 1, false, "quest"));
ChangeCharacterAddressGroup(sld, "EstateBadroom1", "sit", "sit1");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorSetLayMode(sld);
sld = GetCharacter(NPC_GenerateCharacter("Beyns", "trader_8", "man", "man", 7, ENGLAND, 1, false, "quest"));
sld.name = "Andrew";
sld.lastname = "Baynes";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.dialog.currentnode = "First time";
sld.greeting = "cit_common";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
LAi_SetStayTypeNoGroup(sld);
LAi_SetImmortal(sld, true);
sld.talker = 10;
ChangeCharacterAddressGroup(sld, "Estate", "goto", "goto12");
sld = GetCharacter(NPC_GenerateCharacter("Pitt", "Pitt", "man", "man", 1, ENGLAND, -1, false, "quest"));
sld.name = "Jeremy";
sld.lastname = "Pitt";
sld.Dialog.CurrentNode = "First time";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_YoungMan";
SetSPECIAL(sld, 5,9,7,5,10,7,4);
sld.rank = 12;
sld.OfficerWantToGo.DontGo = true;
sld.loyality = MAX_LOYALITY;
InitStartParam(sld);
SetSelfSkill(sld, 40, 35, 20, 40, 25);
SetShipSkill(sld, 45, 30, 25, 25, 50, 25, 25, 25, 30);
SetCharacterPerk(sld, "ShipSpeedUp");
SetCharacterPerk(sld, "ShipTurnRateUp");
SetCharacterPerk(sld, "StormProfessional");
SetCharacterPerk(sld, "WindCatcher");
SetCharacterPerk(sld, "SailsMan");
SetCharacterPerk(sld, "SandbankManeuver");
SetFantomHP(sld);
SetEnergyToCharacter(sld);
LAi_SetImmortal(sld, true);
LAi_SetActorType(sld);
LAi_SetStayType(pchar);
LAi_ActorDialog(sld, pchar, "", 2.0, 0);
ChangeCharacterAddressGroup(sld, "Estate", "goto", "goto1");
pchar.quest.CureLordMovie.win_condition.l1 = "location";
pchar.quest.CureLordMovie.win_condition.l1.location = "EstateBadroom1";
pchar.quest.CureLordMovie.win_condition = "Blood0";
}
void CureLordMovie()
{
InterfaceStates.Buttons.Save.enable = false;
StartQuestMovie(true, true, true);
ChangeShowIntarface();
LAi_SetActorTypeNoGroup(Pchar);
LAi_ActorGoToLocator(Pchar, "goto", "goto6", "CureLordMovie_Con1", 10.0);
}
void DragunInvansion()
{
ref sld;
sld = characterFromID("Pitt");
sld.dialog.currentnode = "PStep_5";
ChangeCharacterAddressGroup(sld, "EstateOffice", "reload", "reload1");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", -1, 0);
}
void DragunInvansion3()
{
LAi_SetActorTypeNoGroup(pchar);
LAi_SetCheckMinHP(Pchar, 1, true, "Blood16");
LAi_SetImmortal(pchar, false);
ref ch, sld;
LAi_LocationFightDisable(loadedLocation, true);
LAi_SetFightMode(Pchar, false);
LAi_LockFightMode(pchar, true);
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
LAi_group_SetHearRadius("TmpEnemy", 3000.0);
ch = GetCharacter(NPC_GenerateCharacter("CapGobart", "Hobart", "man", "man", 10, ENGLAND, 0, false, "quest"));
ch.name = "George";
ch.lastname = "Hobart";
ch.Dialog.CurrentNode = "First time";
ch.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
ch.greeting = "soldier_arest";
ch.location = "none";
SetFantomParamFromRank(sld, 20, true);
LAi_SetImmortal(ch, true);
ch.BreakTmplAndFightGroup = true;
LAi_group_MoveCharacter(ch, "TmpEnemy");
ChangeCharacterAddressGroup(ch, "Estate", "goto", "goto1");
LAi_SetActorTypeNoGroup(ch);
LAi_ActorDialog(ch, pchar, "", 7, 0);
for (int i = 0; i<= 4; i++)
{
sTemp = "SoldierEnglish_1";
if (i == 1) sTemp = "Dragoon_1";
sld = GetCharacter(NPC_GenerateCharacter(("Dragun_"+i), sTemp, "man", "man", 2, ENGLAND, 0, false, "quest"));
sld.location = "none";
sld.BreakTmplAndFightGroup = true;
SetSPECIAL(sld, 8,10,9,3,6,10,4);
InitStartParam(sld);
SetEnergyToCharacter(sld);
LAi_SetImmortal(sld, true);
GiveItem2Character(sld, "blade_04");
EquipCharacterByItem(sld, "blade_04");
sld.Dialog.CurrentNode = "Draguns_0";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
LAi_group_MoveCharacter(sld, "TmpEnemy");
ChangeCharacterAddressGroup(sld, "Estate", "reload", "reload1");
LAi_SetActorTypeNoGroup(sld);
if(i == 1 || i == 2)
{
GiveItem2Character(sld, "pistol2");
EquipCharacterByItem(sld, "pistol2");
TakeNItems(sld, LAi_GetCharacterBulletType(sld), 30);
string sGunpowder = LAi_GetCharacterGunpowderType(sld);
if(sGunPowder != "")
{
AddItems(sld, sGunpowder, 30);
}
LAi_ActorFollow(sld, ch, "", -1);
}
if(i == 3)LAi_ActorRunToLocation(sld, "reload", "reload3", "none", "", "", "", 20);
if(i == 4)LAi_ActorRunToLocation(sld, "reload", "reload5", "none", "", "", "", 20);
}
LAi_ActorTurnToCharacter(pchar, characterFromID("CapGobart"));
LAi_ActorWaitDialog(pchar, characterFromID("CapGobart"));
}
void DragunInvansion4()
{
ref ch, sld;
LAi_LockFightMode(pchar, false);
LAi_LocationFightDisable(loadedLocation, false);
ch = characterFromID("Pitt");
ChangeCharacterAddressGroup(ch, "Estate", "reload", "reload5");
LAi_SetActorType(ch);
LAi_ActorGoToLocator(ch, "goto", "goto5", "", -1);
sld = characterFromID("Beyns");
ChangeCharacterAddressGroup(sld, "Estate", "reload", "reload5");
LAi_SetActorType(sld);
LAi_ActorFollow(sld, ch, "", -1);
for (i = 1; i<5; i++)
{
sld = characterFromID("Dragun_"+i);
if(i == 3 || i == 4)
{
ChangeCharacterAddressGroup(sld, "Estate", "reload", "reload5");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorFollow(sld, ch, "", -1);
}
}
}
void CapGobartAttack(string qName)
{
ref sld;
int numdead = 0;
for (i = 1; i<= 2; i++)
{
sld = characterFromID("Dragun_"+i);
if (CharacterIsDead(sld))
{
numdead++;
}
}
if(numdead == 2)
{
sld = characterFromID("CapGobart");
LAi_SetWarriorTypeNoGroup(sld);
LAi_group_Attack(sld, Pchar);
}
}
void Blood_StartGame_End(string qName)
{
ref sld;
chrDisableReloadToLocation = true;
InterfaceStates.Launched = false;
InterfaceStates.Buttons.Save.enable = true;
sld = characterFromID("Dragun_0");
LAi_RemoveCheckMinHP(sld);
pchar.quest.CapGobartAttack_1.over = "yes";
pchar.quest.CapGobartAttack_2.over = "yes";
CreateEntity(&LAi_QuestFader, "fader");
SendMessage(&LAi_QuestFader, "lfl", FADER_OUT, 0.5, false);
LAi_QuestFader.oldSaveState = InterfaceStates.Buttons.Save.enable;
InterfaceStates.Buttons.Save.enable = 0;
Pchar.model = "blood_bomj";
TakeNItems(pchar, "potion1", 5);
DoQuestCheckDelay("Blood15", 0.1);
}
void CapBloodLine_firstEnterHome(string qName)
{
sld = characterFromID("Pitt");
sld.Dialog.CurrentNode = "PStep_7";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "Plantation_S1", "reload", "reload1");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", 3, 0);
Pchar.questTemp.CapBloodLine.statcrew = "";
}
void CapBloodLine_q1(string qName)
{
ref sld;
LAi_LocationFightDisable(loadedLocation, true);
LAi_SetFightMode(Pchar, false);
LAi_LockFightMode(pchar, true);
chrDisableReloadToLocation = true;
bDisableFastReload = true;
Pchar.questTemp.CapBUnarmed = true;
sld = GetCharacter(NPC_GenerateCharacter("Bishop", "trader_2", "man", "man", 1, ENGLAND, 3, false, "quest"));
sld.name = "William";
sld.lastname = "Bishop";
sld.Dialog.CurrentNode = "First Bishop";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_Bishop";
SetSPECIAL(sld, 9,8,10,3,6,10,4);
InitStartParam(sld);
SetEnergyToCharacter(sld);
GiveItem2Character(sld, "blade_22");
EquipCharacterByItem(sld, "blade_22");
GiveItem2Character(sld, "pistol2");
EquipCharacterByItem(sld, "pistol2");
LAi_SetImmortal(sld, true);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "reload", "houseSp1");
LAi_SetActorType(sld);
LAi_SetStayTypeNoGroup(pchar);
LAi_ActorDialog(sld, pchar, "", -1, 0);
sld = characterFromID("Pitt");
sld.Dialog.CurrentNode = "First time";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
LAi_SetCitizenType(sld);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "officers", "houseS1_3");
sld = GetCharacter(NPC_GenerateCharacter("Griffin", "shipowner_11", "man", "man", 10, ENGLAND, 3, false, "quest"));
sld.name = "Ed";
sld.lastname = "Griffin";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_Master";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_SetOwnerType(sld);
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "CommonFlamHouse", "goto","goto1");
LAi_SetImmortal(sld, true);
sld = GetCharacter(NPC_GenerateCharacter("Hells", "shipowner_9", "man", "man", 10, PIRATE, 3, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.name = "Tobias";
sld.lastname = "Hells";
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
sld.greeting = "Gr_Fisher";
AddMoneyToCharacter(sld, 2000);
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_SetOwnerTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "CommonRoom_MH2", "goto","goto4");
sld = GetCharacter(NPC_GenerateCharacter("Quest_Smuggler", "Pirate_4", "man", "man", 10, ENGLAND, 3, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_Smuggler Agent";
LAi_SetSitTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit2");
int i = rand(2);
sld = GetCharacter(NPC_GenerateCharacter("Quest_Habitue", "citiz_"+(rand(11)+1), "man", "man", 10, ENGLAND, 3, false, "quest"));
sld.greeting = "Gr_Tavern_Mate";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.Default = "Bridgetown_tavern";
sld.Default.group = "sit";
sld.Default.ToLocator = "sit_front" + (i+1);
LAi_SetCitizenType(sld);
LAi_SetSitTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit_base"+(1+i));
sld = GetCharacter(NPC_GenerateCharacter("Hugtorp", "officer_16", "man", "man", 10, ENGLAND, -1, false, "quest"));
sld.name = "Nathaniel";
sld.lastname = "Hagthorpe";
sld.Dialog.CurrentNode = "First time";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_Officer";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
LAi_SetCitizenType(sld);
SetRandSPECIAL(sld);
InitStartParam(sld);
sld.rank = 10;
SetSelfSkill(sld, 20, 40, 35, 30, 30);
SetShipSkill(sld, 45, 30, 25, 25, 20, 25, 35, 30, 20);
SetCharacterPerk(sld, "LongRangeGrappling");
SetCharacterPerk(sld, "Brander");
SetCharacterPerk(sld, "Troopers");
SetCharacterPerk(sld, "AdvancedDefense");
SetCharacterPerk(sld, "HardHitter");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "Gunman");
SetEnergyToCharacter(sld);
SetFantomHP(sld);
LAi_SetImmortal(sld, true);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "officers", "houseS2_1");
sld = GetCharacter(NPC_GenerateCharacter("Dieke", "officer_19", "man", "man", 10, ENGLAND, -1, false, "quest"));
sld.name = "Nicolas";
sld.lastname = "Dyke";
sld.Dialog.CurrentNode = "First time";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_Officer";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
LAi_SetCitizenType(sld);
SetRandSPECIAL(sld);
InitStartParam(sld);
sld.rank = 10;
SetSelfSkill(sld, 40, 35, 20, 30, 30);
SetShipSkill(sld, 30, 35, 20, 20, 20, 45, 25, 35, 20);
SetCharacterPerk(sld, "BasicCommerce");
SetCharacterPerk(sld, "LightRepair");
SetCharacterPerk(sld, "Carpenter");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "Sliding");
SetCharacterPerk(sld, "Tireless");
SetCharacterPerk(sld, "EnergyPlus");
SetEnergyToCharacter(sld);
SetFantomHP(sld);
LAi_SetImmortal(sld, true);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "officers", "houseF1_1");
sld = GetCharacter(NPC_GenerateCharacter("Ogl", "Chard3a", "man", "man", 10, ENGLAND, -1, false, "quest"));
sld.name = "Ned";
sld.lastname = "Ogle";
sld.Dialog.CurrentNode = "First time";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.greeting = "Gr_Ogl";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
LAi_SetCitizenType(sld);
LAi_SetStayTypeNoGroup(sld);
SetRandSPECIAL(sld);
InitStartParam(sld);
sld.rank = 10;
sld.OfficerWantToGo.DontGo = true;
sld.loyality = MAX_LOYALITY;
SetSPECIAL(sld, 8, 9, 5, 5, 9, 5, 7);
SetSelfSkill(sld, 20, 30, 20, 35, 30);
SetShipSkill(sld, 20, 10, 50, 40, 15, 20, 20, 20, 20);
SetCharacterPerk(sld, "FastReload");
SetCharacterPerk(sld, "HullDamageUp");
SetCharacterPerk(sld, "CrewDamageUp");
SetCharacterPerk(sld, "SailsDamageUp");
SetCharacterPerk(sld, "LongRangeShoot");
SetCharacterPerk(sld, "BasicDefense");
SetCharacterPerk(sld, "GunProfessional");
SetCharacterPerk(sld, "SharedExperience");
SetEnergyToCharacter(sld);
SetFantomHP(sld);
LAi_SetImmortal(sld, true);
ChangeCharacterAddressGroup(sld, "Plantation_S2", "barmen", "stay");
sld = GetCharacter(NPC_GenerateCharacter("Slave_Quest", "shipowner_6", "man", "man", 7, ENGLAND, 2, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.Dialog.CurrentNode = "SLQStep_0";
sld.greeting = "Gr_slave";
sld.talker = 10;
sld.CityType = "citizen";
sld.city = "BridgeTown";
LAi_SetLoginTime(sld, 6.0, 22.99);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "goto", "goto12");
LAi_SetCitizenType(sld);
LAi_group_MoveCharacter(sld, sTemp);
pchar.quest.CapBloodLine_q1_1.win_condition.l1 = "location";
pchar.quest.CapBloodLine_q1_1.win_condition.l1.location = "Bridgetown_town";
pchar.quest.CapBloodLine_q1_1.function = "_PrepareBridgeTown";
}
void _PrepareBridgeTown(string qName)
{
DoQuestFunctionDelay("PrepareBridgeTown", 1.0);
}
void PrepareBridgeTown(string qName)
{
ChangeBridgeTownDialogs(false);
sld = &characters[GetCharacterbyLocation("Bridgetown_town", "soldiers", "soldier2")];
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.Dialog.CurrentNode = "First Guard";
sld.protector = true;
sld.protector.CheckAlways = 1;
LAi_RemoveLoginTime(sld);
LoginCharacter(sld, "BridgeTown_town");
LoginNettl("");
LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", true);
LocatorReloadEnterDisable("BridgeTown_fort", "reload2", true);
sld = characterFromID("Bridgetown_Smuggler");
LoginCharacter(sld, "Bridgetown_tavern");
}
void DetectBlades()
{
if (Pchar.questTemp.CapBloodLine == true && Pchar.questTemp.CapBUnarmed == true)
{
string sweapon = FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE);
string sgun = FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE);
bool bblades = (sweapon != "unarmed") && (sweapon != "blade_05" ) && (sweapon!= "");
bool bguns = (sgun != "") && (sgun != "pistol1");
if(bblades || bguns)
{
pchar.quest.CapBloodDetectBlades1.win_condition.l1 = "location";
pchar.quest.CapBloodDetectBlades1.win_condition.l1.location = "Bridgetown_town";
pchar.quest.CapBloodDetectBlades1.function = "TakeBlades";
pchar.quest.CapBloodDetectBlades2.win_condition.l1 = "location";
pchar.quest.CapBloodDetectBlades2.win_condition.l1.location = "BridgeTown_Plantation";
pchar.quest.CapBloodDetectBlades2.function = "TakeBlades";
}
}
}
void TakeBlades(string qName)
{
sld = GetCharacter(NPC_GenerateCharacter("SolderTakeBlades", "sold_eng_"+(rand(7)+1), "man", "man", 10, ENGLAND, 0, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.dialog.currentnode = "First time";
sld.city = "Bridgetown_town";
sld.greeting = "soldier_arest";
sld.location = "none";
sld.BreakTmplAndFight = true;
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_SetCitizenType(sld);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
PlaceCharacter(sld, "goto", "random_must_be_near");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", -1.0, 0);
chrDisableReloadToLocation = true;
pchar.quest.SolderTakeBladesDie.win_condition.l1 = "NPC_death";
pchar.quest.SolderTakeBladesDie.win_condition.l1.character = "SolderTakeBlades";
pchar.quest.SolderTakeBladesDie.function = "SolderTakeBladesDie";
}
void SolderTakeBladesDie(string qName)
{
chrDisableReloadToLocation = false;
}
void ChangeBridgeTownDialogs(bool restore)
{
ref sld;
int num, cur;
num = 0;
cur = rand(3)+1;
for(int i = 0;i<MAX_CHARACTERS;i++)
{
sld = &characters[i];
if (CheckAttribute(sld, "city") && sld.city == "Bridgetown")
{
if(CheckAttribute(sld, "CityType") && sld.CityType == "soldier")
{
if (!restore)
{
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
}
else
{
sld.dialog.filename = "Common_Soldier.c";
}
sld.lifeDay = 3;
}
if(CheckAttribute(sld, "CityType") && sld.CityType == "citizen")
{
if (!restore)
{
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
if(sld.location.group == "merchant")
{
num++;
if(num == cur)
{
sld.quest.bGoodMerch = true;
}
}
}
else
{
if(sld.location.group == "merchant")
{
sld.dialog.filename = "Common_ItemTrader.c";
}
else
{
sld.dialog.filename = "Common_citizen.c";
}
}
sld.lifeDay = 3;
}
if(sld.id == "Bridgetown_Poorman")
{
if (!restore)
{
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
}
else
{
sld.dialog.filename = "Common_poorman.c";
}
}
if(sld.id == "QuestCitiz_Bridgetown")
{
if (!restore)
{
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.Dialog.CurrentNode = "First time";
}
else
{
sld.dialog.filename = "Quest\ForAll_dialog.c";
}
}
}
}
}
void LoginNettl(string qName)
{
Pchar.questTemp.CapBloodLine.TalkWithNettl = false;
sld = GetCharacter(NPC_GenerateCharacter("Nettl", "shipowner_2", "man", "man", 7, ENGLAND, 3, false, "quest"));
sld.name = "James";
sld.lastname = "Nettall";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.dialog.currentnode = "First time";
sld.city = "Bridgetown_town";
sld.greeting = "Gr_Tavern_Mate";
LAi_SetCitizenType(sld);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
sld.talker = 10;
PlaceCharacter(sld, "goto", "random");
}
void CapBloodLine_q1_Late(string qName)
{
InterfaceStates.Buttons.Save.enable = false;
GameOver("blood");
}
void CapBloodLine_q1_End(string qName)
{
AddQuestRecord("CapBloodLine_q1", "6");
Pchar.questTemp.CapBloodLine.stat = "CureMisStid_Complite";
}
void CapBloodLine_q1_Complited(string qName)
{
ref sld;
pchar.quest.CapBloodLineTimer_1.over = "yes";
sld = characterFromID("MisStid");
sld.location = "none";
sld = characterFromID("Bridgetown_Mayor");
sld.Dialog.CurrentNode = "First time";
int n = FindLocation("Bridgetown_town");
locations[n].reload.l3.close_for_night = true;
AddQuestRecord("CapBloodLine_q1", "7");
CloseQuestHeader("CapBloodLine_q1");
bQuestCheckProcessFreeze = true;
WaitDate("",0,0,0, 12, 0);
SetCurrentTime(7, 0);
bQuestCheckProcessFreeze = false;
SetLaunchFrameFormParam("Later...", "Reload_To_Location", 0.1, 2.0);
SetLaunchFrameReloadLocationParam("Bridgetown_tavern", "reload","reload2", "");
LaunchFrameForm();
CapBloodLine_q2();
}
void CapBloodLine_q2()
{
ref sld;
sld = characterFromID("Waker");
sld.dialog.currentnode = "First time";
Pchar.questTemp.CapBloodLine.stat = "WakerOffer";
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern_upstairs", "goto","goto1");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 2.0, 0);
AddQuestRecord("CapBloodLine_q2", "2");
AddQuestRecord("CapBloodLine_q2", "3");
PChar.quest.CapBloodLineTimer_2.win_condition.l1 = "Timer";
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.hour = 17;
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 0);
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
PChar.quest.CapBloodLineTimer_2.function = "CapBloodLine_q2_Late";
}
void Spain_spyDie(string qName)
{
ref sld;
sld = characterFromID("Spain_spy");
LAi_KillCharacter(sld);
}
void LoginSpain_spy(string qName)
{
LAi_SetStayType(pchar);
ref sld;
sld = GetCharacter(NPC_GenerateCharacter("Spain_spy", "shipowner_13", "man", "man", 7, SPAIN, 2, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
sld.name = "Sergio";
sld.lastname = "Crespo";
sld.dialog.currentnode = "First time";
sld.city = "Bridgetown_town";
sld.greeting = "Gr_HUNTER";
sld.location = "none";
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_SetCitizenType(sld);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "goto","goto3");
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorDialog(pchar, sld, "pchar_back_to_player", -1.0, 0);
}
void SpainSpyAttack(string qName)
{
LAi_Fade("", "");
bQuestCheckProcessFreeze = true;
WaitDate("",0,0,0, 0, 10);
bQuestCheckProcessFreeze = false;
AddQuestRecord("WeaponsForEscape", "8");
LocatorReloadEnterDisable("BridgeTown_town", "houseSp2", false);
}
void _DeadSolder(string qName)
{
PlaySound("People Fight\Death_NPC_04.WAV");
DoQuestFunctionDelay("DeadSolder", 1.0);
}
void DeadSolder(string qName)
{
LocatorReloadEnterDisable(pchar.location, "reload1", true);
ref sld;
sld = characterFromID("CPBQuest_Solder");
DeleteAttribute(sld, "money");
DeleteAttribute(sld, "equip");
DeleteAttribute(sld, "items");
TakeNItems(sld, "potion1", 5);
GiveItem2Character(sld, "blade_07");
if (rand (3) == 2)
{
GiveItem2Character(sld, "pistol1");
TakeNItems(sld, "bullet", 5);
string sGunpowder = LAi_GetCharacterGunpowderType(sld);
if(sGunPowder != "")
{
AddItems(sld, sGunpowder, 5);
}
if(GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE) == "")
{
chrDisableReloadToLocation = true;
DoQuestCheckDelay("Blood_add3", 1.0)	
}
LAi_KillCharacter(sld);
}
}
void FindMsStid_ring(string qName)
{
AddQuestRecord("WeaponsForEscape", "14");
}
void LoginWinterwood()
{
ref sld, ch, itm;
sld = GetCharacter(NPC_GenerateCharacter("Winterwood", "officer_20", "man", "man", 10, PIRATE, 3, false, "quest"));
sld.name = "Stuart";
sld.lastname = "Winterwood";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.greeting = "pirat_common";
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
GiveItem2Character(sld, "HugtorpRing");
AddMoneyToCharacter(sld, 1000);
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
LAi_SetCitizenType(sld);
string sQuest = "WinterwoodDuel";
pchar.quest.(sQuest).win_condition.l1 = "NPC_Death";
pchar.quest.(sQuest).win_condition.l1.character = sld.id;
pchar.quest.(sQuest).function = "WinterwoodDie";
if(!rand(1))
{
LAi_SetSitTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit4");
}
else
{
LAi_SetStayTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "Bridgetown_Brothel_room", "goto","goto3");
ch = GetCharacter(NPC_GenerateCharacter("Qhorse", "horse07", "woman", "towngirl", 10, ENGLAND, 1, false, "quest"));
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(ch, sTemp);
LAi_SetActorTypeNoGroup(ch);
LAi_ActorAfraid(ch, Pchar, false);
ChangeCharacterAddressGroup(ch, "Bridgetown_Brothel_room", "goto","goto1");
int n = FindLocation("Bridgetown_Brothel");
locations[n].reload.l2.disable = false;
}
}
void WinterwoodDuel(string qName)
{
pchar.quest.Winterwood2Place.win_condition.l1 = "Location";
pchar.quest.Winterwood2Place.win_condition.l1.location = "Bridgetown_ExitTown";
pchar.quest.Winterwood2Place.function = "Winterwood2Place";
}
void Winterwood2Place(string qName)
{
ref sld;
sld = characterFromID("Winterwood");
sld.Dialog.CurrentNode = "talk_off_town";
if (CheckAttribute(sld, "CityType"))
{
DeleteAttribute(sld, "City");
DeleteAttribute(sld, "CityType");
}
ChangeCharacterAddressGroup(sld, "Bridgetown_ExitTown", "goto","goto1");
LAi_SetStayTypeNoGroup(sld);
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", -1.0, 0);
chrDisableReloadToLocation = true;
}
void Winterwood_Prepare_Fight()
{
int i, idx;
ref npchar, rLoc;
npchar = characterFromID("Winterwood");
makeref(rLoc, Locations[FindLoadedLocation()]);
if (CheckAttribute(rLoc, "type") && rLoc.type == "tavern")
{
if (PChar.chr_ai.type == LAI_TYPE_SIT)
{
LAi_SetPlayerType(pchar);
PlaceCharacter(pchar, "tables", pchar.location);
}
PChar.Quest.Duel_Fight_Right_Now.win_condition.l1 = "Location";
PChar.Quest.Duel_Fight_Right_Now.win_condition.l1.Location = "Clone_location";
PChar.Quest.Duel_Fight_Right_Now.function = "Winterwood_Fight_Right_Now";
LocationMakeClone(pchar.location);
Locations[FindLocation("Clone_location")].image = "loading\tavern_fight.tga";
DoReloadCharacterToLocation("Clone_location", pchar.location.group, pchar.location.locator);
PlaceCharacter(npchar, "goto", "Clone_location")
}
else
{
DoQuestFunctionDelay("Winterwood_Fight_Right_Now", 0.5);
}
LAi_SetWarriorType(npchar);
LAi_group_MoveCharacter(npchar, "DUEL_FIGHTER");
}
void Winterwood_Fight_Right_Now(string qName)
{
bool bOk = false;
ref sld = &Locations[FindLocation(pchar.location)];
if (CheckAttribute(sld, "noFight"))
{
bOk = sti(sld.noFight);
}
if (bOk)
{
LAi_LocationFightDisable(sld, !bOk);
pchar.questTemp.LocFightEnable = bOk;
}
LAi_SetFightMode(pchar, true);
LAi_group_SetRelation("DUEL_FIGHTER", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_FightGroups("DUEL_FIGHTER", LAI_GROUP_PLAYER, true);
chrDisableReloadToLocation = true;
}
void WinterwoodDie(string qName)
{
if (CheckAttribute(PChar, "quest.Winterwood2Place")) Pchar.quest.Winterwood2Place.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodLineTimer_3")) Pchar.quest.CapBloodLineTimer_3.over = "yes";
if (CheckAttribute(pchar, "questTemp.LocFightEnable") && sti(pchar.questTemp.LocFightEnable))
{
sld = &Locations[FindLocation(pchar.location)];
LAi_LocationFightDisable(sld, true);
DeleteAttribute(pchar, "questTemp.LocFightEnable");
}
if (CheckAttribute(pchar, "questTemp.LocationClone") && sti(pchar.questTemp.LocationClone))
{
DoQuestCheckDelay("TalkSelf_Start", 0.2);
}
DoQuestCheckDelay("hide_weapon", 2.0);
AddQuestRecord("HugtorpTrouble", "3");
pchar.quest.WinterwoodDieR.win_condition.l1 = "item";
pchar.quest.WinterwoodDieR.win_condition.l1.item = "HugtorpRing";
pchar.quest.WinterwoodDieR.win_condition = "Blood_add4";
LAi_group_SetAlarm("DUEL_FIGHTER", LAI_GROUP_PLAYER, 0);
}
void MoneyForDieke(string qName)
{
sld = characterFromID("Dieke");
sld.Dialog.CurrentNode = "DKStep_3";
AddQuestRecord("DiekeQuest", "4")
}
void CapBloodLine_q2_Late(string qName)
{
InterfaceStates.Buttons.Save.enable = false;
GameOver("blood");
}
void CapBloodLine_q2_Complited()
{
ref sld;
Pchar.quest.CapBloodLineTimer_2.over = "yes";
AddQuestRecord("CapBloodLine_q2", "6");
int n = FindLocation("Bridgetown_tavern");
locations[n].reload.l2.disable = false;
sld = characterFromID("Waker");
sld.Dialog.CurrentNode = "WStep_11";
LAi_SetStayTypeNoGroup(sld);
bQuestCheckProcessFreeze = true;
WaitDate("",0,0,0, 12, 0);
Environment.date.day = 3;
SetCurrentTime(7, 0);
bQuestCheckProcessFreeze = false;
sld = GetCharacter(NPC_GenerateCharacter("MoneySpy", "shipowner_5", "man", "man", 10, ENGLAND, 1, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
sld.quest.meeting = 0;
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_SetOwnerType(sld);
LAi_group_MoveCharacter(sld, sTemp);
sld.talker = 10;
ChangeCharacterAddressGroup(sld, "CommonDoubleFlourHouse_1", "barmen", "stay");
sld = GetCharacter(NPC_GenerateCharacter("Fisherman", "shipowner_8", "man", "man", 10, ENGLAND, 1, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.name = "Arnold";
sld.lastname = "Summerlite";
sld.greeting = "Gr_Fisher";
sld.Default = "Bridgetown_tavern";
sld.Default.group = "sit";
sld.Default.ToLocator = "sit_front4";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_SetSitType(sld);
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit_base4");
sld = GetCharacter(NPC_GenerateCharacter("Jack", "pirate_5", "man", "man", 10, ENGLAND, 1, false, "quest"));
sld.name = "Jacques";
sld.lastname = "Swallow";
sld.greeting = "Gr_Solovey";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
sld.dialog.currentnode = "JSTStep_0";
sld.talker = 10;
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_SetStayType(sld);
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "Bridgetown_Store", "goto", "goto1");
sld = characterFromID("Bridgetown_trader");
LAi_SetLoginTime(sld, 0.0, 1.0);
PChar.quest.CapBloodLineTimer_2.win_condition.l1 = "Timer";
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.hour = 15;
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 0);
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
PChar.quest.CapBloodLineTimer_2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
PChar.quest.CapBloodLineTimer_2.function = "CapBloodLine_q2_Late";
SetLaunchFrameFormParam("The next morning...", "Reload_To_Location", 0.1, 2.0);
SetLaunchFrameReloadLocationParam("Plantation_S1", "goto", "goto1", "");
LaunchFrameForm();
}
void QUsurerLate(string qName)
{
ChangeCharacterHunterScore(PChar, "enghunter", 30);
}
void LoginMainer()
{
ref sld;
Pchar.questTemp.CapBloodLine.ShipForJack = false;
sld = GetCharacter(NPC_GenerateCharacter("Mainer", "officer_1", "man", "man", 7, ENGLAND, 3, false, "quest"));
sld.name = "John";
sld.lastname = "Mayner";
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.dialog.currentnode = "MNStep_0";
sld.city = "Bridgetown_town";
LAi_SetCitizenType(sld);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "reload", "reload1");
}
void CapBloodLine_q3_Complited()
{
Pchar.quest.CapBloodLineTimer_2.over = "yes";
pchar.quest.CapBloodEscape1.win_condition.l1 = "location";
pchar.quest.CapBloodEscape1.win_condition.l1.location = "Bridgetown_town";
pchar.quest.CapBloodEscape1.function = "ReturnToPlantation1";
}
void ReturnToPlantation1(string qName)
{
ref sld;
sld = GetCharacter(NPC_GenerateCharacter("SolderTakeBlades", "sold_eng_"+(rand(7)+1), "man", "man", 10, ENGLAND, 0, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.dialog.currentnode = "STBStep_2";
sld.city = "Bridgetown_town";
sld.greeting = "Gr_HUNTER";
sld.location = "none";
sld.BreakTmplAndFightGroup = true;
SetFantomParamHunter(sld);
LAi_SetCitizenType(sld);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_SetActorType(sld);
LAi_group_MoveCharacter(sld, sTemp);
PlaceCharacter(sld, "goto", "random_must_be_near");
LAi_ActorDialog(sld, pchar, "", -1.0, 0);
chrDisableReloadToLocation = true;
}
void ReturnToPlantation2(string qName)
{
ref sld;
sld = characterFromID("Hugtorp");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1.0, 0);
sld = characterFromID("Pitt");
ChangeCharacterAddressGroup(sld, "None", "", "");
chrDisableReloadToLocation = true;
}
void ReturnToPlantation3()
{
ref sld;
SetLocationCapturedState("BridgeTown_Plantation", true);
string sTemp = "TmpEnemy";
LAi_group_SetAlarm("TmpEnemy", LAI_GROUP_PLAYER, 1);
LAi_group_SetHearRadius(sTemp, LAI_GROUP_GRD_HEAR - 3);
LAi_group_SetSayRadius(sTemp, LAI_GROUP_GRD_SAY - 1);
LAi_group_SetLookRadius(sTemp, LAI_GROUP_GRD_LOOK - 1);
LAi_group_SetRelation(sTemp, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
SetShipInBridgetown();
Pchar.questTemp.CapBUnarmed = false;
sld = characterFromID("Hugtorp");
LAi_LoginInCaptureTown(sld, true);
LAi_SetStayTypeNoGroup(sld);
sld.talker = 10;
sld.Dialog.CurrentNode = "HTStep_18";
GiveItem2Character(sld, "blade_07");
EquipCharacterByItem(sld, "blade_07");
TakeNItems(sld, "potion1", 5);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "quest", "quest3");
sld = characterFromID("Ogl");
LAi_LoginInCaptureTown(sld, true);
sld.Dialog.CurrentNode = "HTStep_18";
LAi_SetStayTypeNoGroup(sld);
GiveItem2Character(sld, "blade_07");
EquipCharacterByItem(sld, "blade_07");
TakeNItems(sld, "potion1", 5);
LAi_SetImmortal(sld, false);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "quest", "quest4");
sld = characterFromID("Dieke");
LAi_LoginInCaptureTown(sld, true);
LAi_SetStayTypeNoGroup(sld);
sld.Dialog.CurrentNode = "HTStep_18";
GiveItem2Character(sld, "blade_07");
EquipCharacterByItem(sld, "blade_07");
TakeNItems(sld, "potion1", 5);
LAi_SetImmortal(sld, false);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "quest", "quest5");
sld = characterFromID("Pitt");
LAi_LoginInCaptureTown(sld, true);
LAi_SetActorType(sld);
LAi_ActorSetLayMode(sld);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "quest", "sit2");
worldMap.date.day = 4;
Environment.date.day = 4;
SetCurrentTime(0, 0);
int n = FindLocation("BridgeTown_Plantation");
DeleteAttribute(&locations[n], "citizens");
DeleteAttribute(&locations[n], "carrier");
DoReloadCharacterToLocation("BridgeTown_Plantation", "reload", "reload1_back");
SetNationRelation2MainCharacter(ENGLAND, RELATION_ENEMY);
for (int i = 0; i < 7; i++)
{
if(i < 2)
{
sld = GetCharacter(NPC_GenerateCharacter("PittGuard_"+i, "sold_eng_"+(rand(7)+1), "man", "man", 10, ENGLAND, 0, false, "quest"));
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_LoginInCaptureTown(sld, true);
LAi_SetStayType(sld);
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "quest", "sit"+(2*i+1));
}
else
{
int iChar = NPC_GeneratePhantomCharacter("soldier", ENGLAND, MAN, 2);
sld = &characters[iChar];
SetNPCModelUniq(sld, "soldier", MAN);
sld.City = "Bridgetown";
sld.CityType = "soldier";
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_LoginInCaptureTown(sld, true);
LAi_SetWarriorType(sld);
LAi_SetPatrolType(sld);
LAi_group_MoveCharacter(sld, sTemp);
PlaceCharacter(sld, "patrol", "random_free");
}
LAi_SetLoginTime(sld, 0.0, 24.0);
sld.greeting = "soldier_common";
sld.dialog.filename = "Common_Soldier.c";
sld.dialog.currentnode = "first time";
}
pchar.GenQuestBox.BridgeTown_Plantation.box1.items.blade_07 = 1;
pchar.GenQuestBox.BridgeTown_Plantation.box1.items.potion1 = 3;
pchar.quest.CapBloodEscape3.win_condition.l1 = "locator";
pchar.quest.CapBloodEscape3.win_condition.l1.location = "BridgeTown_Plantation";
pchar.quest.CapBloodEscape3.win_condition.l1.locator_group = "quest";
pchar.quest.CapBloodEscape3.win_condition.l1.locator = "detector1";
pchar.quest.CapBloodEscape3.function = "ReturnToPlantation4";
chrDisableReloadToLocation = true;
}
void ReturnToPlantation4(string qName)
{
ref sld;
string sTemp = "TmpEnemy";
LAi_group_SetAlarm("TmpEnemy", LAI_GROUP_PLAYER, 1);
LAi_group_SetHearRadius(sTemp, 3);
LAi_group_SetSayRadius(sTemp, 4);
LAi_group_SetLookRadius(sTemp, 5);
for (i = 0; i < 2; i++)
{
sld = characterFromID("PittGuard_"+i);
LAi_SetWarriorTypeNoGroup(sld);
LAi_group_Attack(sld, Pchar);
}
sld = characterFromID("Pitt");
sld.Dialog.CurrentNode = "PStep_11";
LAi_SetGroundSitTypeNoGroup(sld);
LAi_group_MoveCharacter(sld, "Pitt");
SetLocationCapturedState("Bridgetown_town", true);
pchar.quest.CapBloodEscape4.win_condition.l1 = "location";
pchar.quest.CapBloodEscape4.win_condition.l1.location = "Bridgetown_town";
pchar.quest.CapBloodEscape4.function = "StillShip";
}
void StillShip(string qName)
{
ref chr,sld;
aref st;
int iNation = SPAIN;
string slai_group, locatorName, sType;
slai_group = "TmpEnemy";
LAi_group_SetHearRadius(slai_group, LAI_GROUP_GRD_HEAR - 3);
LAi_group_SetSayRadius(slai_group, LAI_GROUP_GRD_SAY - 1);
LAi_group_SetLookRadius(slai_group, LAI_GROUP_GRD_LOOK - 1);
LAi_group_SetAlarm(sTemp, LAI_GROUP_PLAYER, 0);
for (i = 1; i < 12; i++)
{
chr = GetCharacter(NPC_GenerateCharacter("SpaSolder_"+i, "sold_spa_"+(rand(7)+1), "man", "man", sti(pchar.rank)+rand(2)+1, SPAIN, 1, false, "quest"));
chr.City = "Bridgetown";
chr.CityType = "soldier";
SetFantomParamFromRank(chr, sti(pchar.rank)+rand(2)+1, true);
LAi_LoginInCaptureTown(chr, true);
LAi_SetLoginTime(chr, 0.0, 24.0);
LAi_SetWarriorType(chr);
LAi_SetPatrolType(chr);
LAi_group_MoveCharacter(chr, slai_group);
chr.greeting = "soldier_common";
ChangeCharacterAddressGroup(chr, "Bridgetown_town", "goto", "goto"+i);
chr.dialog.filename = "Common_Soldier.c";
chr.dialog.currentnode = "first time";
}
sld = GetCharacter(NPC_GenerateCharacter("SpaRaider", "off_spa_2", "man", "man", 10, SPAIN, 1, false, "quest"));
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
sld.BreakTmplAndFight = true;
LAi_LoginInCaptureTown(sld, true);
LAi_SetLoginTime(chr, 0.0, 24.0);
LAi_SetActorType(sld);
LAi_group_MoveCharacter(sld, slai_group);
sld.greeting = "soldier_common";
sld.dialog.filename = "Common_Soldier.c";
sld.dialog.currentnode = "first time";
sld.City = "Bridgetown";
sld.CityType = "soldier";
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "reload", "houseF2");
string sQuest = "SaveArabelaService";
pchar.quest.(sQuest).win_condition.l1 = "NPC_Death";
pchar.quest.(sQuest).win_condition.l1.character = sld.id;
pchar.quest.(sQuest).function = "SaveArabelaService";
chr = GetCharacter(NPC_GenerateCharacter("ArabelaService", "Girl_8", "woman", "towngirl", 10, ENGLAND, 1, false, "quest"));
chr.greeting = "Enc_RapersGirl_1";
chr.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
chr.dialog.currentnode = "ASStep_0";
LAi_SetActorType(chr);
LAi_LoginInCaptureTown(chr, true);
LAi_SetLoginTime(chr, 0.0, 24.0);
ChangeCharacterAddressGroup(chr, "Bridgetown_town", "officers", "houseH1_2");
LAi_ActorRunToLocator(chr, "officers", "gate1_3", "Blood20", 5);
LAi_ActorFollow(sld, chr, "", -1);
pchar.quest.CapBloodEscape5.win_condition.l1 = "locator";
pchar.quest.CapBloodEscape5.win_condition.l1.location = "Bridgetown_town";
pchar.quest.CapBloodEscape5.win_condition.l1.locator_group = "quest";
pchar.quest.CapBloodEscape5.win_condition.l1.locator = "quest11";
pchar.quest.CapBloodEscape5.function = "ShipGuardsAlarm";
ShipGuards();
Pchar.questTemp.CapBloodLine.SpainInBridgetown = false;
Pchar.questTemp.CapBloodLine.withCrew = false;
LocatorReloadEnterDisable("BridgeTown_town", "reload5_back", true);
LocatorReloadEnterDisable("BridgeTown_town", "reloadShip", true);
Colonies[FindColony("Bridgetown")].DontSetShipInPort = true;
sld = characterFromID("Bridgetown Fort Commander");
sld.Fort.Mode = FORT_DEAD;
sld.Fort.DieTime.Year = GetDataYear();
sld.Fort.DieTime.Month = GetDataMonth();
sld.Fort.DieTime.Day = GetDataDay();
sld.Fort.DieTime.Time = GetTime();
Event(FORT_DESTROYED, "l", sti(sld.index));
}
void ShipGuards()
{
ref chr,sld;
string slai_group = "EnemyFight";
int iChar;
string model[6];
model[0] = "shipowner_1";
model[1] = "shipowner_6";
model[2] = "shipowner_9";
model[3] = "shipowner_10";
model[4] = "pirate_1";
model[5] = "pirate_8";
LAi_group_Delete(slai_group);
for (int i = 0; i <= 9; i++)
{
if(i <= 6)
{
chr = GetCharacter(NPC_GenerateCharacter("ShipGuard_"+i, "sold_spa_"+(rand(7)+1), "man", "man", 10, SPAIN, 1, false, "quest"));
SetFantomParamFromRank(chr, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_SetImmortal(chr, true);
LAi_LoginInCaptureTown(chr, true);
LAi_SetLoginTime(chr, 0.0, 24.0);
LAi_SetActorTypeNoGroup(chr);
LAi_ActorStay(chr);
LAi_group_MoveCharacter(chr, slai_group);
ChangeCharacterAddressGroup(chr, "Bridgetown_town", "rld", "aloc"+i);
}
else
{
sld = GetCharacter(NPC_GenerateCharacter("FreeSlave_"+(i-6), model[rand(5)], "man", "man", 10, SPAIN, 1, false, "quest"));
SetFantomParamFromRank(sld, sti(pchar.rank)+makeint(2*MOD_SKILL_ENEMY_RATE/3), true);
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs.c";
LAi_LoginInCaptureTown(sld, true);
LAi_SetActorType(sld);
LAi_ActorStay(sld);
LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "quest", "quest"+i);
}
}
sld = GetCharacter(NPC_GenerateCharacter("SpaFirstMate", "off_spa_1", "man", "man", 12, SPAIN, 1, false, "quest"));
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_LoginInCaptureTown(sld, true);
LAi_SetWarriorType(sld);
ChangeCharacterAddressGroup(sld, "Cabin", "rld", "aloc0");
pchar.quest.SpaFirstMateDie.win_condition.l1 = "NPC_death";
pchar.quest.SpaFirstMateDie.win_condition.l1.character = "SpaFirstMate";
pchar.quest.SpaFirstMateDie.function = "SpaFirstMateDie";
}
void SaveArabelaService(string qName)
{
ref sld;
LAi_SetFightMode(pchar, false);
sld = characterFromID("ArabelaService");
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", -1.0, 0);
sld = characterFromID("Hugtorp");
sld.talker = 10;
}
void CapBloodOfficers()
{
string offName;
ref sld;
Pchar.questTemp.CapBloodLine.withCrew = true;
for (int i = 1; i <= 6; i++)
{
if(i > 3) offName = "FreeSlave_"+(i-3);
switch(i)
{
case 1:
offName = "Hugtorp";
break;
case 2:
offName = "Dieke";
break;
case 3:
offName = "Ogl";
break;
}
sld = characterFromID(offName);
LAi_SetImmortal(sld, false);
sld.DontClearDead = true;
sld.BreakTmplAndFight = true;
LAi_SetActorType(sld);
LAi_ActorFollow(sld, pchar, "", -1);
LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
sld.Dialog.CurrentNode = "HTStep_22b";
}
}
void ShipGuardsAlarm(string qName)
{
chrDisableReloadToLocation = true;
LAi_group_SetCheck("EnemyFight", "Blood21");
DoQuestFunctionDelay("AttakShip", 2.0);
}
void AttakShip(string qName)
{
string offName;
ref sld;
int iChar;
for (int i = 0; i <= 9; i++)
{
offName = "ShipGuard_"+i;
switch(i)
{
case 7:
offName = "Hugtorp";
break;
case 8:
offName = "Dieke";
break;
case 9:
offName = "Ogl";
break;
}
iChar = GetCharacterIndex(offName);
if (iChar != -1)
{
sld = &characters[iChar]
LAi_SetWarriorTypeNoGroup(sld);
if(Pchar.questTemp.CapBloodLine.withCrew) LAi_SetImmortal(sld, false);
}
}
LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
LAi_group_SetRelation("TmpEnemy", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
}
void SpaFirstMateDie(string qName)
{
string offName;
ref sld;
int iChar;
for (int i = 0; i < 13; i++)
{
offName = "SpaSolder_"+i;
switch(i)
{
case 11:
offName = "SpaRaider";
break;
case 12:
offName = "ArabelaService";
break;
}
iChar = GetCharacterIndex(offName);
if (iChar != -1)
{
sld = &characters[iChar];
sld.lifeDay = 0;
}
}
pchar.quest.CapBloodEscape6.win_condition.l1 = "location";
pchar.quest.CapBloodEscape6.win_condition.l1.location = "Bridgetown_town";
pchar.quest.CapBloodEscape6.function = "QOfficersRecruit";
AddQuestRecord("EscapeFormBarbados", "5");
CloseQuestHeader("EscapeFormBarbados");
DoQuestCheckDelay("Blood21", 0.3);
}
void QOfficersRecruit(string qName)
{
string offName, sNode;
ref sld;
int iChar;
for (int i = 0; i <= 3; i++)
{
offName = "ShipGuard_"+i;
switch(i)
{
case 0:
offName = "Pitt";
sNode = "PStep_16";
break;
case 1:
offName = "Hugtorp";
sNode = "HTStep_24";
break;
case 2:
offName = "Dieke";
sNode = "DKStep_5";
break;
case 3:
offName = "Ogl";
sNode = "OGLStep_11";
break;
}
iChar = GetCharacterIndex(offName);
if (iChar != -1)
{
sld = &characters[iChar];
sld.loyality = MAX_LOYALITY;
LAi_SetImmortal(sld, false);
ChangeCharacterAddressGroup(sld, "Bridgetown_town", "rld", "aloc"+(i+1));
LAi_SetActorTypeNoGroup(sld);
LAi_ActorTurnToLocator(sld, "quest", "quest11");
sld.dialog.currentnode = sNode;
if (offName == "Pitt") LAi_ActorDialog(sld, pchar, "", -1.0, 0);
else LAi_SetStayTypeNoGroup(sld);
}
}
}
void CapBloodLaspEpisode(string qName)
{
RestoreBridgetown();
}
void SpaCrewAtack()
{
int hcrew,iChar,i;
ref chref;
chref = characterFromID("Pitt");
chref.Dialog.CurrentNode = "hired";
chref.Dialog.FileName = "Enc_Officer_dialog.c";
chref.greeting = "Gr_questOfficer";
string sGroup = "SpaCrew";
Group_FindOrCreateGroup(sGroup);
Group_SetType(sGroup,"war");
Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
Group_LockTask(sGroup);
for (i = 0; i<2; i++)
{
iChar = NPC_GenerateCharacter("SpaBoat_"+i, "off_spa_2", "man", "man", 7, SPAIN, 1, true, "quest");
makeref(chref, Characters[iChar]);
chref.Ship.Mode = "war";
chref.Ship.Type = GenerateShip(SHIP_LUGGER, 1);
SetRandomNameToCharacter(chref);
SetRandomNameToShip(chref);
SetBaseShipData(chref);
hcrew = GetMaxCrewQuantity(chref);
SetCrewQuantityOverMax(chref, 150);
DeleteAttribute(chref,"ship.sails");
DeleteAttribute(chref,"ship.masts");
DeleteAttribute(chref,"ship.blots");
Fantom_SetCannons(chref, "war");
Fantom_SetBalls(chref, "war");
SetFantomParamHunter(chref);
SetCaptanModelByEncType(sld, "war");
Group_AddCharacter(sGroup, chref.id);
if (i == 0)
{
Group_SetGroupCommander(sGroup, chref.id);
}
}
Group_SetAddress(sGroup, "Barbados", "IslandShips1", "ship_3");
}
void OglAdd()
{
ref chref;
chref = characterFromID("Ogl");
chref.Dialog.CurrentNode = "hired";
chref.Dialog.FileName = "Enc_Officer_dialog.c";
chref.greeting = "Gr_questOfficer";
}
void RestoreBridgetown()
{
ref rColony;
Pchar.questTemp.CapBloodLine = false;
Pchar.model = "Blood5";
ref sld;
sld = characterFromID("Bridgetown_Mayor");
sld.Dialog.Filename = "Common_Mayor.c";
sld.Dialog.CurrentNode = "First time";
int n = FindLocation("Bridgetown_town");
locations[n].reload.l3.close_for_night = true;
locations[n].questSeekCap = 6;
locations[n].houseEnc = true;
n = FindLocation("Bridgetown_tavern");
locations[n].habitues = 1;
DeleteAttribute(&locations[n], "notCloseCommonHouse");
ChangeBridgeTownDialogs(true);
bDisableLandEncounters = false;
chrDisableReloadToLocation = false;
bDisableFastReload = false;
Pchar.questTemp.CapBUnarmed = false;
n = FindLocation("CommonStoneHouse");
locations[n].models.day.locators = "StoneHouse_locators";
locations[n].models.night.locators = "StoneHouse_Nlocators";
n = FindLocation("BridgeTown_Plantation");
locations[n].citizens = true;
locations[n].carrier = true;
SetLocationCapturedState("Bridgetown_town", false);
SetLocationCapturedState("BridgeTown_Plantation", false);
LocatorReloadEnterDisable("BridgeTown_town", "reload5_back", false);
LocatorReloadEnterDisable("BridgeTown_town", "reload1_back", false);
LocatorReloadEnterDisable("BridgeTown_fort", "reload2", false); //fix
LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
LocatorReloadEnterDisable("Bridgetown_Townhall", "reload3", false);
LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
sld = characterFromID("Bridgetown_trader");
LAi_RemoveLoginTime(sld);
makeref(rColony, Colonies[FindColony("Bridgetown")]);
DeleteAttribute(rColony, "DontSetShipInPort");
RemoveShipFromBridgetown();
LAi_group_Delete("EnemyFight");
LAi_group_Delete("TmpEnemy");
if (CheckAttribute(PChar, "quest.CureLordMovie")) Pchar.quest.CureLordMovie.over = "yes";
if (CheckAttribute(PChar, "quest.DragunInvansion")) Pchar.quest.DragunInvansion.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodLine_q1_1")) Pchar.quest.CapBloodLine_q1_1.over = "yes";
if (CheckAttribute(PChar, "quest.onPlantation")) Pchar.quest.onPlantation.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodDetectBlades1")) Pchar.quest.CapBloodDetectBlades1.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodDetectBlades2")) Pchar.quest.CapBloodDetectBlades2.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodLineTimer_1")) Pchar.quest.CapBloodLineTimer_1.over = "yes";
if (CheckAttribute(PChar, "quest.CureMisStid")) Pchar.quest.CureMisStid.over = "yes";
if (CheckAttribute(PChar, "quest.PrepareToEscape2")) Pchar.quest.PrepareToEscape2.over = "yes";
if (CheckAttribute(PChar, "quest.PrepareToEscape3")) Pchar.quest.PrepareToEscape3.over = "yes";
if (CheckAttribute(PChar, "quest.WinterwoodDuel")) Pchar.quest.WinterwoodDuel.over = "yes";
if (CheckAttribute(PChar, "quest.MoneyForDieke")) Pchar.quest.MoneyForDieke.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodLineTimer_2")) Pchar.quest.CapBloodLineTimer_2.over = "yes";
if (CheckAttribute(PChar, "quest.QUsurer")) Pchar.quest.QUsurer.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodEscape1")) Pchar.quest.CapBloodEscape1.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodEscape2")) Pchar.quest.CapBloodEscape2.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodEscape3")) Pchar.quest.CapBloodEscape3.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodEscape4")) Pchar.quest.CapBloodEscape4.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodEscape5")) Pchar.quest.CapBloodEscape5.over = "yes";
if (CheckAttribute(PChar, "quest.CapBloodEscape6")) Pchar.quest.CapBloodEscape6.over = "yes";
if (CheckAttribute(PChar, "quest.SolderTakeBladesDie")) Pchar.quest.SolderTakeBladesDie.over = "yes";
LAi_group_RemoveCheck("EnemyFight");
CloseQuestHeader("FishermanQuest");
CloseQuestHeader("UsurerQuest");
CloseQuestHeader("PirateQuest");
TakeNItems(pchar, "migraine_potion", -1);
TakeNItems(pchar, "Weapon_for_escape", -1);
}
void SetShipInBridgetown()
{
int n = FindLocation("Bridgetown_town");
locations[n].models.always.ship = "Bridgetown_ship";
locations[n].models.always.shipreflect = "Bridgetown_shipreflect";
Locations[n].models.always.shipreflect.sea_reflection = 1;
locations[n].models.always.locators = "Bridgetown_locatorsShip";
locations[n].models.day.fonarShip = "Bridgetown_fdShip";
locations[n].models.night.fonarShip = "Bridgetown_fnShip";
locations[n].models.day.charactersPatch = "Bridgetown_patchship_day";
locations[n].models.night.charactersPatch = "Bridgetown_patchship_night";
locations[n].reload.ship1.name = "reloadShip";
locations[n].reload.ship1.go = "Cabin";
locations[n].reload.ship1.emerge = "reload1";
locations[n].reload.ship1.autoreload = "0";
locations[n].reload.ship1.label = "cabine";
n = FindLocation("Cabin");
DeleteAttribute(&locations[n], "boarding");
DeleteAttribute(&locations[n], "camshuttle");
DeleteAttribute(&locations[n], "CabinType");
locations[n].reload.l1.name = "reload1";
locations[n].reload.l1.go = "Bridgetown_town";
locations[n].reload.l1.emerge = "reloadShip";
locations[n].reload.l1.autoreload = "0";
locations[n].reload.l1.label = "Ship";
}
void RemoveShipFromBridgetown()
{
int n = FindLocation("Bridgetown_town");
DeleteAttribute(&locations[n], "models.always.ship");
DeleteAttribute(&locations[n], "models.always.shipreflect");
DeleteAttribute(&locations[n], "models.always.shipreflect.sea_reflection");
locations[n].models.always.locators = "Bridgetown_locators";
DeleteAttribute(&locations[n], "models.day.fonarShip");
DeleteAttribute(&locations[n], "models.night.fonarShip");
locations[n].models.day.charactersPatch = "Bridgetown_patch_day";
locations[n].models.night.charactersPatch = "Bridgetown_patch_night";
DeleteAttribute(&locations[n], "reload.ship1");
n = FindLocation("Cabin");
DeleteAttribute(&locations[n], "reload");
Locations[n].boarding = "true";
Locations[n].boarding.nextdeck = "";
Locations[n].camshuttle = 1;
Locations[n].boarding.locatorNum = 1;
Locations[n].CabinType = true;
locations[n].environment.weather.rain = false;
Locations[n].boarding.Loc.Hero = "loc0";
Locations[n].boarding.Loc.Capt = "aloc2";
}