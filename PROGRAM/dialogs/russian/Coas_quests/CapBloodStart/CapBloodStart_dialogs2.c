void ProcessDialogEvent()
{
ref NPChar, sld;
aref Link, NextDiag;
string sLocator, sTemp;
int iTime, n, iChar;
DeleteAttribute(&Dialog,"Links");
makeref(NPChar,CharacterRef);
makearef(Link, Dialog.Links);
makearef(NextDiag, NPChar.Dialog);
switch(Dialog.CurrentNode)
{
case "Exit":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "Exit_Away":
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", Pchar.questTemp.sLocator, "none", "", "", "", sti(Pchar.questTemp.iTime));
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "Exit_RunAway":
LAi_SetActorTypeNoGroup(npchar);
LAi_ActorRunToLocation(npchar, "reload", Pchar.questTemp.sLocator, "none", "", "", "", sti(Pchar.questTemp.iTime));
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "sfight":
DialogExit();
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_group_Attack(NPChar, Pchar);
break;
case "fight":
DialogExit();
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_SetWarriorTypeNoGroup(NPChar);
LAi_group_Attack(NPChar, Pchar);
AddDialogExitQuest("MainHeroFightModeOn");
chrDisableReloadToLocation = false;
LAi_CharacterPlaySound(npchar, "toArm");
break;
case "Qfight":
DialogExit();
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_SetWarriorType(NPChar);
LAi_group_MoveCharacter(NPChar, "TmpEnemy");
LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
LAi_group_FightGroups(GetNationNameByType(ENGLAND) + "_citizens", LAI_GROUP_PLAYER, true);
AddDialogExitQuest("MainHeroFightModeOn");
chrDisableReloadToLocation = true;
break;
case "Finish":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
RestoreBridgetown();
initMainCharacterItem();
ref mc = GetMainCharacter();
mc.Ship.Type = GenerateShip(GOF_SHIP_ARABELLA, true);
mc.Ship.name = "Arabella";
SetBaseShipData(mc);
mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantityFull(mc);
SetCharacterGoods(mc,GOOD_FOOD,2000);
SetCharacterGoods(mc,GOOD_BALLS,2000);
SetCharacterGoods(mc,GOOD_GRAPES,300);
SetCharacterGoods(mc,GOOD_KNIPPELS,400);
SetCharacterGoods(mc,GOOD_BOMBS,2000);
SetCharacterGoods(mc,GOOD_POWDER,2000);
SetCharacterGoods(mc,GOOD_PLANKS,10);
SetCharacterGoods(mc,GOOD_RUM,40);
SetCharacterGoods(mc,GOOD_WEAPON,2000);
DoReloadCharacterToLocation(Pchar.HeroParam.Location, Pchar.HeroParam.Group, Pchar.HeroParam.Locator);
break;
case "plantation_slave":
dialog.text = RandPhraseSimple(RandPhraseSimple("I am so tired, already falling down...", "Can't keep living like that!"), RandPhraseSimple("This work is killing me.", "Guards want us all dead!"));				
link.l1 = RandPhraseSimple("What a pity.", "I am sorry.");
link.l1.go = "exit";				
break;
case "Man_FackYou":
dialog.text = LinkRandPhrase("Robbery, in broad daylight! What the hell's going on?! Hang about there, buddy...", "Heh, what're you digging around there for?! You aren't thinking of robbing me? Well, then you're finished!", "Wait, where you reaching into? Oh, turns out you're a thief! Consider yourself finished, pal...");
link.l1 = LinkRandPhrase("Devil!", "?Caramba!", "Ah, damn!");
link.l1.go = "Qfight";
break;
case "Draguns_0":
dialog.text = LinkRandPhrase("Here he is! Grab him!", "Grab him, boys!", "Hey, stop!");
link.l1 = LinkRandPhrase("Devil!", "Oh no you don't!", "Ah, damn!");
link.l1.go = "Draguns_1";
NextDiag.TempNode = "Draguns_0";
break;
case "Draguns_1":
LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "First time":
dialog.text = "Mistake";
link.l1 = "...";
link.l1.go = "Exit";
if (CheckAttribute(npchar, "CityType") && npchar.CityType == "soldier")
{
if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape2_1")
{
dialog.text = "Go your own way, and don't distract me.";
link.l1 = "I'm afraid it's a serious matter. A Spanish stranger entered the weaponmaker's house, and the door to Griffin's has been locked tight.";
link.l1.go = "SQStep_0";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2_2";
break;
}
if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY || ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -15)
{
dialog.text = RandPhraseSimple("Stop! Turn over your weapons! Follow me!", "Runaway slave! Grab him at once!");
link.l1 = RandPhraseSimple("Shut up, weirdo!", "Oh no you don't!");
link.l1.go = "sfight";
break;
}
switch (rand(5))
{
case 0:
dialog.text = "What's a slave doing without work?";
link.l1 = "I'm taking care of an order from Colonel Bishop.";
link.l1.go = "exit";
break;
case 1:
dialog.text = "Oh, it's you, Doctor Blood. You treated me, when you saved the Pride of Devon.";
link.l1 = "I'm happy that you're better.";
link.l1.go = "exit";
break;
case 2:
dialog.text = "Get out, slave!";
link.l1 = "I'm also happy to see you, whoever you are.";
link.l1.go = "exit";
break;
case 3:
dialog.text = "What weather! And I'm forced to stand here. My only amusement is knocking flies away from my face.";
link.l1 = "I sympathize. But I can't help; that's your job.";
link.l1.go = "exit";
break;
case 4:
dialog.text = "If you want to blab, then find someone else - or better yet, go back to your plantation.";
link.l1 = "Of course.";
link.l1.go = "exit";
break;
case 5:
dialog.text = "Go your own way, and don't distract me.";
link.l1 = "As you say, soldier.";
link.l1.go = "exit";
break;
}
}
if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen")
{
dialog.text = TimeGreeting() + ", doctor.";
link.l1 = "Hello.";
link.l1.go = "Exit";
if(Pchar.questTemp.CapBloodLine.stat == "WakerOffer")
{
link.l2 = RandPhraseSimple("Won't you tell me where I can find Doctor Whacker?", "I need Doctor Whacker. Have you seen him?");
link.l2.go = "Citizen_0";
}
if(CheckAttribute(Pchar, "questTemp.CapBloodLine.ShipForJack") && Pchar.questTemp.CapBloodLine.ShipForJack == true)
{
Link.l2 = RandPhraseSimple("I need to get somewhere. Can you suggest a decent captain?", "I'm looking for a captain who will transport my friend and me for a reasonable price. Do you have anyone in mind?");
Link.l2.go = "Citizen_1";
}
}
if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen" && npchar.location.group == "merchant")
{
if(findsubstr(Pchar.questTemp.CapBloodLine.stat, "PrepareToEscape" , 0) != -1)
{
if (CheckAttribute(npchar, "quest.bGoodMerch") && sti(Pchar.reputation) >= 55)
{
dialog.text = "Oh, Doctor Blood! Hello. I didn't thank you"+NPCharSexPhrase(NPChar, " ", "")+" for saving my little son, which I still often remember and regret. How wonderful that I've met you today!";
link.l1 = "It really is wonderful that people want to return the favor at the most appropriate moment. Won't you tell me, "+NPCharSexPhrase(NPChar, "my friend ", "my dear ")+", where I might find some boarding sabers and two-three pistols, quick as possible, without any unnecessary noise or trouble?";
link.l1.go = "Merchant_0";
break;
}
}
if (CheckAttribute(npchar, "quest.bGoodMerch"))
{
dialog.text = TimeGreeting() + ", doctor.";
link.l1 = "Hello.";
}
else
{
dialog.text = "You're blocking my goods. Move it, slave scum!";
link.l1 = "I'm already gone.";
}
link.l1.go = "Exit";
}
if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen" && findsubstr(npchar.id, "Slave_" , 0) != -1)
{
dialog.text = RandPhraseSimple(RandPhraseSimple("I'm so tired, my feet are breaking under me.", "I have no strength to live like this anymore!"), RandPhraseSimple("This work is too hard for me.", "The overseers haven't left a living spot on my hide!"));
link.l1 = RandPhraseSimple("I empathize, buddy.", "I pity you.");
link.l1.go = "exit";
}
if (npchar.id == "Bridgetown_Poorman")
{
dialog.text = "Hey, man, throw us a coin... Oh, it's you, Doctor Blood.";
link.l1 = "Good luck!";
link.l1.go = "Exit";
}
if (npchar.id == "QuestCitiz_Bridgetown")
{
dialog.text = TimeGreeting() + ", doctor.";
link.l1 = "And to you, too.";
link.l1.go = "Exit";
}
if (npchar.id == "SolderTakeBlades")
{
dialog.text = RandPhraseSimple("Since when do slaves walk freely with weapons?", "You're a slave of Colonel Bishop. Why are you armed?");
link.l1 = RandPhraseSimple("Eh... Heh, heh...", "I don't get it myself...");
link.l1.go = "STBStep_0";
}
if (npchar.id == "Winterwood")
{
if(npchar.location == "Bridgetown_Brothel_room")
{
dialog.text = "What the hell do you need here?! Get out, immediately!";
link.l1 = "Begging your pardon, but that woman's mine.";
link.l1.go = "WWStep_7";
}
else
{
dialog.text = "What the hell do you need here?! Get out immediately!";
link.l1 = "You don't need to me rude! I have business for you.";
link.l1.go = "WWStep_0";
}
}
if (npchar.id == "Quest_Habitue")
{
dialog.text = "*hic* Oh, pal, you look like an old sea wolf! Maybe you'll buy me a cup o' rum?";
link.l1 = "I may be a sea wolf, but that doesn't mean I'll be buying some bum a drink...";
link.l1.go = "exit";
}
if (npchar.id == "Weston")
{
dialog.text = "Get the hell out of my house!";
link.l1 = "I'm already gone.";
link.l1.go = "exit";
}
if (npchar.id == "MoneySpy")
{
if(npchar.quest.meeting == "1")
{
dialog.text = "Get out!";
link.l1 = "I'm already gone.";
link.l1.go = "exit";
}
else
{
npchar.quest.meeting = "1";
dialog.text = "Finally! I thought you weren't going to come! Now, were you able to discover something?";
link.l1 = "You've mistaken me for someone else.";
link.l1.go = "MSStep_0";
link.l2 = "Hmm... So it seems.";
link.l2.go = "MSStep_1";
}
}
if (npchar.id == "Fisherman")
{
dialog.text = "Won't you put a drink on me, eh? *hic*";
link.l1 = "I don't think so.";
link.l1.go = "exit";
}
if (npchar.id == "QStranger")
{
dialog.text = "What do you need?";
link.l1 = "I'm here to work out if you aren't about to leave the city, having forgotten that you owe someone a handsome 30,000?";
link.l1.go = "QSTStep_0";
link.l2 = "Hey, old timer. What, you've completely forgotten me?";
link.l2.go = "QSTStep_1";
link.l3 = "I think your position is serious. Your ruse, uh... whatsisname, Raf, has been outed. If you don't immediately return Carpenter's 30,000, you'll be strung up today!";
link.l3.go = "QSTStep_2";
}
break;
case "Citizen_0":
if (!CheckAttribute(npchar, "quest.btmp"))
{
npchar.quest.btmp = true;
if(rand(3) == 2)
{
dialog.text = LinkRandPhrase("Scurry back to the tavern, and look there. Don't forget to look under the tables.", "I just dropped by the tavern. If I remember properly, he didn't leave.", "Dropped by the bar just now... From the hangover, was it?");
link.l1 = "Thank you.";
link.l1.go = "Exit";
}
else
{
dialog.text = RandPhraseSimple(RandPhraseSimple("I don't know! Leave!", "I can't help you there."), RandPhraseSimple("Move it, slave scum!", "And who is this? I just know Doctor Blood... oh, it's you. Hello."));
link.l1 = "Thank you.";
link.l1.go = "Exit";
}
}
else
{
dialog.text = "Doctor, you've already asked me about that.";
link.l1 = "Sorry.";
link.l1.go = "Exit";
}
break;
case "Citizen_1":
dialog.text = LinkRandPhrase("I can't help you there.", "With all due respect, Doctor, you shouldn't be asking that in your position.", "Alas, I have no one to suggest to you, Doctor Blood.");
link.l1 = "Thank you.";
link.l1.go = "Exit";
break;
case "Merchant_0":
dialog.text = "I'm not going to ask why you need it. If they asked me, I'd have to lie and weasel my way out. All the same, they will ask for a report, no earlier then the day after tomorrow, so...";
link.l1 = "The day after tomorrow you can bravely say that you allowed free use of a few swords and pistols to Peter Blood, who was a doctor in Bridgetown. I don't think Colonel Bishop would mind...";
link.l1.go = "Merchant_1";
break;
case "Merchant_1":
dialog.text = "My son owes you his life, and I as well. Here, Doctor Blood. Take it. And good luck to you!";
link.l1 = "Many thanks.";
link.l1.go = "Exit";
NextDiag.TempNode = "Merchant_2";
if (Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape") Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";//fix чтоб не сбивать уже начатые варианты
GiveItem2Character(Pchar, "Weapon_for_escape");
AddQuestRecord("WeaponsForEscape", "10");
CloseQuestHeader("WeaponsForEscape");
break;
case "Merchant_2":
dialog.text = "And good luck to you, Doctor Blood!";
link.l1 = "Thank you.";
link.l1.go = "Exit";
NextDiag.TempNode = "Merchant_2";
break;
case "STBStep_0":
dialog.text = "Hey, turn those weapons over immediately! I ought to report to Colonel Bishop so he can teach you a good lesson...";
link.l1 = "Here! Take them, and let's forget about all of this.";
link.l1.go = "STBStep_1";
link.l2 = "We'll see who's going to teach who, now!";
link.l2.go = "fight";
break;
case "STBStep_1":
dialog.text = "Ah, all right. Get out.";
link.l1.go = "Exit_Away";
Pchar.questTemp.sLocator = "reload1_back";
Pchar.questTemp.iTime = 40;
RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
while (FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE) != "" && FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE) != "blade_05")
{
TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
}
while (FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE) != "" && FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE) != "pistol1")
{
TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
}
SetNewModelToChar(Pchar);
pchar.quest.CapBloodDetectBlades1.over = "yes";
pchar.quest.CapBloodDetectBlades2.over = "yes";
chrDisableReloadToLocation = false;
break;
case "STBStep_2":
dialog.text = "Colonel Bishop's been looking all over for you. Be off to the plantation, at once!";
link.l1 = "As you say.";
link.l1.go = "Exit_Away";
//link.l1.go = "finish";
Pchar.questTemp.sLocator = "gate1_back";
Pchar.questTemp.iTime = -1;
chrDisableReloadToLocation = false;
pchar.quest.CapBloodEscape2.win_condition.l1 = "location";
pchar.quest.CapBloodEscape2.win_condition.l1.location = "Bridgetown_Plantation";
pchar.quest.CapBloodEscape2.function  = "ReturnToPlantation2";
sld = characterFromID("Hugtorp");
sld.Dialog.CurrentNode = "HTStep_14";
ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "goto", "goto18");
break;
case "SoldierNotBlade":
if (Pchar.questTemp.CapBUnarmed == false)
{
dialog.text = LinkRandPhrase("Why the hell are you running around the city with a drawn dagger? Hide the weapon immediately!", "I order you to sheath your weapon at once!", "Hey, pal, stop scaring the people! Sheath your weapon.");
link.l1 = LinkRandPhrase("Fine.", "Okay.", "As you say...");
link.l1.go = "exit";
link.l2 = LinkRandPhrase("To hell with it!", "Dream about it...", "After the rain, on Thursday.");
link.l2.go = "fight";
}
else
{
dialog.text = RandPhraseSimple("Since when do slaves walk where they please with weapons?", "You're a slave of Colonel Bishop. Why are you armed?")+"Hey, turn those weapons over immediately! I ought to report to Colonel Bishop so he can teach you a good lesson...";
link.l1 = "Here! Take them, and let's forget about all of this.";
link.l1.go = "SoldierNotBladeEx";
link.l2 = "We'll see who's going to teach who, now!";
link.l2.go = "fight";
}
npchar.greeting = "soldier_common";
NextDiag.TempNode = "First Time";
break;
case "SoldierNotBladeEx":
RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
while (FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE) != "")
{
TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
}
while (FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE) != "")
{
TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
}
//свободен
pchar.quest.CapBloodDetectBlades1.over = "yes";
pchar.quest.CapBloodDetectBlades2.over = "yes";
iChar = GetCharacterIndex("SolderTakeBlades");
if (iChar != -1)
{
sld = &characters[iChar];
LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
chrDisableReloadToLocation = false;
}
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "SQStep_0":
dialog.text = "Spaniard? You're joking! A Spaniard couldn't have... Er. Or... could he?";
link.l1 = "I tell you, it was a Spaniard.";
link.l1.go = "SQStep_1";
break;
case "SQStep_1":
dialog.text = "I'm going there at once. Where is the house located?";
link.l1 = "It's the house of Mr. Griffin, not far from the Governor's mansion.";
link.l1.go = "Exit_RunAway";
Pchar.questTemp.sLocator = "houseSp2";
Pchar.questTemp.iTime = 20;
string smodel = NPChar.model;
if (findsubstr(smodel, "eng_mush" , 0) != -1) smodel = "sold_eng_"+(rand(7)+1);
sld = GetCharacter(NPC_GenerateCharacter("CPBQuest_Solder", smodel, "man", "man", 10, ENGLAND, 1, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
SetFantomParamHunter(sld);
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
LAi_SetActorTypeNoGroup(sld);
LAi_ActorSetLayMode(sld);
LAi_SetImmortal(sld, true);
ChangeCharacterAddressGroup(sld, "CommonFlamHouse", "reload","reload3");
sld = characterFromID("Griffin");
ChangeCharacterAddressGroup(sld, "CommonRoom_MH4", "barmen","bar1");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorTurnToLocator(sld, "goto","goto2");
LAi_SetStayTypeNoGroup(sld);
sld = characterFromID("Spain_spy");
ChangeCharacterAddressGroup(sld, "CommonRoom_MH4", "goto","goto2");
sld.dialog.currentnode = "SSStep_3";
LAi_SetActorType(sld);
LAi_ActorDialog(sld, pchar, "", 0, 0);
pchar.quest.PrepareToEscape2_3.win_condition.l1 = "location";
pchar.quest.PrepareToEscape2_3.win_condition.l1.location = "CommonFlamHouse";
pchar.quest.PrepareToEscape2_3.function  = "_DeadSolder";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2_3";
DoQuestFunctionDelay("SpainSpyAttack", 20.0);
break;
case "SLQStep_0":
dialog.text = "Hello, Mr. Blood. It seems like you're the doctor here? Won't you give me something for my headache? Because my head hurts so much that at times I can't take it.";
if (GetCharacterItem(pchar,"migraine_potion") > 0)
{
link.l0 = "Here, take this mixture. It'll take care of your migraine. At least, for the moment.";
link.l0.go = "SLQStep_3";
}
link.l1 = "Unfortunately, I don't have anything for headaches. And Colonel Bishop probably won't give money for the necessary medicines, since he considers the illness of his slaves to stem from lack of work. Alas, all I can suggest is to rest more when it's possible.";
link.l1.go = "SLQStep_1";
break;
case "SLQStep_1":
dialog.text = "Doctor, in my position, following your suggestion would be difficult. I have no money, but I have something that you might find handy. So if you are able to find something for me, then I won't stay in your debt.";
link.l1 = "Fine, I'll try to find some medicine for you.";
link.l1.go = "Exit";
NextDiag.TempNode = "SLQStep_2";
break;
case "SLQStep_2":
dialog.text = "Will you give me the medicine, Doctor?";
if (GetCharacterItem(pchar,"migraine_potion") > 0)
{
link.l1 = "Yes, I brought migraine medicine.";
link.l1.go = "SLQStep_3";
link.l2 = "I'd rather not.";
link.l2.go = "Exit";
}
else
{
link.l1 = "No, I have been unable to find the right mixture yet.";
link.l1.go = "Exit";
}
NextDiag.TempNode = "SLQStep_2";
break;
case "SLQStep_3":
dialog.text = "Thank you, Doctor. As a token of my gratitude, please accept this small gun. I've long hid it from the overseers, but I think it'll be of more use to you.";
link.l1 = "Yes, but slaves aren't allowed to keep weapons!";
link.l1.go = "SLQStep_4";
TakeItemFromCharacter(Pchar, "migraine_potion");
GiveItem2Character(Pchar, "pistol1");
TakeNItems(pchar, "bullet", 5);
AddItems(Pchar, "gunpowder", 5);
break;
case "SLQStep_4":
dialog.text = "Don't worry, Doctor. It's easy to hide under your clothes, in a way that no else will notice. Just don't you wave it around in front of soldiers, hear?";
link.l1 = "Thank you, my friend. And get well soon.";
link.l1.go = "Exit";
NPChar.talker = 0;
NextDiag.TempNode = "First time";
break;
case "WWStep_0":
dialog.text = "What are babbling about, slave scum?! What kind of business could you have with me?!";
link.l1 = "I need that ring...";
link.l1.go = "WWStep_1";
break;
case "WWStep_1":
dialog.text = "Ring?! I won't sell it you for any amount of money! Go and buy from another seller, who'd agree to deal with a slave!";
link.l1 = "I need not just the ring, but the finger on which it is worn.";
link.l1.go = "WWStep_2";
break;
case "WWStep_2":
dialog.text = "You'll pay dearly for those words.";
link.l1 = "I knew it. Such things are better done without witnesses Come to the city gates in an hour.";
link.l1.go = "WWStep_3";
break;
case "WWStep_3":
Dialog.Text = "All right, let's meet by the gates in an hour.";
link.l1 = "See you soon.";
link.l1.go = "WWStep_4";
if (GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE) != "")
{
link.l2 = "I don't have much time. I want to finish with you right now!";
link.l2.go = "WWStep_5_1";
}
break;
case "WWStep_4":
PChar.quest.CapBloodLineTimer_3.win_condition.l1 = "Timer";
PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.hour = sti(GetTime() + 1);
PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.day = GetAddingDataDay(0, 0, 0);
PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
PChar.quest.CapBloodLineTimer_3.function = "WinterwoodDuel";
NextDiag.CurrentNode = "WWStep_5";
DialogExit();
break;
case "WWStep_5":
Dialog.Text = "Well, what else do you want?";
link.l1 = "I don't have much time. I want to finish with you right now!";
link.l1.go = "WWStep_5_1";
link.l2 = "I simply wanted to remind you of our meeting.";
link.l2.go = "Exit";
NextDiag.TempNode = "WWStep_5";
break;
case "WWStep_5_1":
Dialog.Text = "Hmm... You chose your own fate!";
link.l1 = "Let's begin.";
link.l1.go = "WWStep_6";
break;
case "talk_off_town":
Dialog.Text = "Well then, ready to meet your maker?";
link.l1 = "Sure. How about you introduce us? I'll catch up later!";
link.l1.go = "WWStep_6";
chrDisableReloadToLocation = false;
break;
case "WWStep_6":
AddDialogExitQuestFunction("Winterwood_Prepare_Fight");
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "WWStep_7":
dialog.text = "What are you bringing, slave scum?";
link.l1 = "I'm bringing you news that playtime is over.";
link.l1.go = "WWStep_8";
break;
case "WWStep_8":
dialog.text = "You have three seconds to get back into the hole you crawled out of, and pray we never cross paths again.";
link.l1 = "I have a better idea. Why don't you get really furious and challenge me to a duel, while I sit here, biding my time.";
link.l1.go = "WWStep_3";
n = FindLocation("Bridgetown_Brothel");
locations[n].reload.l2.disable = true;
break;
case "QHStep_0":
dialog.text = "*Hic* Oi, chum, friend! You look like a weathered old sea dog! How about a glass of preservative? My treat.";
link.l1 = "I may be a sea dog, but that doesn't mean I sit around drinking with random bums...";
link.l1.go = "exit";
link.l2 = "I'd be happy to join you, for the companionship.";
link.l2.go = "QHStep_1";
NextDiag.TempNode = "QHStep_0";
break;
case "QHStep_1":
NextDiag.TempNode = "begin_sit";
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
pchar.questTemp.friend_in_tavern = npchar.id;
AddDialogExitQuest("alc");
break;
case "begin_sit":
NextDiag.TempNode = "first time";
dialog.snd = "Voice\HADI\HADI028";
dialog.text = "*Hic* I'll drink to that! Here, this is how our people do it! Today it's my treat!";
link.l1 = "Innkeep! Rum!";
link.l1.go = "QHStep_2";
break;
case "QHStep_2":
WaitDate("",0,0,0, 0, 30);
dialog.text = LinkRandPhrase("Wow, you're a real friend! Let's us drink to such an opportune meetin'! ",
"*Hic* This, my man, is the rum of the gods! So, we all ready?",
"To your health, and may you be free as soon as possible! ");
link.l1 = "My brother, why don't you tell me some of the stories you've heard in your tour of the local taverns?";
link.l1.go = "QHStep_3";
break;
case "QHStep_3":
dialog.text = "Nothing new, really... There's some merchant, turned up on a ship from Jamaica. They say he's got a cargo worth a king's ransom. Now I may be wrong, but I've a notion he's an old acquaintance of Colonel Bishop. Guess he plans to stay a few days. He's found himself accommodations in a house 'round here.";
link.l1 = "Yes, well, that was a nice chat. But now it's time to go.";
link.l1.go = "exit_sit";
NextDiag.TempNode = "First time";
if (CheckNationLicence(ENGLAND)) TakeNationLicence(ENGLAND);
sTemp = NationShortName(ENGLAND)+"TradeLicence";
ref rItem = ItemsFromID(sTemp);
SaveCurrentNpcQuestDateParam(rItem, "Action_date");
rItem.Action_date = GetCurrentDate();
rItem.Validity = FindRussianDaysString(60);
rItem.Validity.QtyDays = 60;
n = FindLocation("CommonStoneHouse");
locations[n].private1.items.jewelry4 = 20;
locations[n].private1.items.EngTradeLicence = 1;
locations[n].private1.money = 6000;
sld = GetCharacter(NPC_GenerateCharacter("Weston", "trader_3", "man", "man", 10, ENGLAND, 1, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart_dialogs2.c";
sld.name = "Charles";
sld.lastname = "Weston";
sld.greeting = "Gr_bankeer";
SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
LAi_SetImmortal(sld, true);
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
LAi_SetOwnerTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "CommonStoneHouse", "barmen","stay");
pchar.quest.MoneyForDieke.win_condition.l1 = "Money_in_box";
pchar.quest.MoneyForDieke.win_condition.l1.Location = "CommonStoneHouse";
pchar.quest.MoneyForDieke.win_condition.l1.Box = "private1";
pchar.quest.MoneyForDieke.win_condition.l1.Money = "0";
pchar.quest.MoneyForDieke.function = "MoneyForDieke";
AddQuestRecord("DiekeQuest", "3");
break;
case "exit_sit":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
AddDialogExitQuest("exit_sit");
break;
case "MSStep_0":
dialog.text = "Then get lost!";
link.l1 = "";
link.l1.go = "Exit";
break;
case "MSStep_1":
dialog.text = "So how many are there?";
link.l1 = "They're all there.";
link.l1.go = "MSStep_2";
link.l2 = "There are five of them.";
link.l2.go = "MSStep_3";
link.l3 = "There are more than I could count.";
link.l3.go = "MSStep_4";
break;
case "MSStep_2":
dialog.text = "What are you talking about? Get away, you cursed scoundrel!";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_3":
dialog.text = "Five? Hmm... All right, then. Are they armed?";
link.l1 = "They have light weaponry, but they aren't showing it off.";
link.l1.go = "MSStep_5";
link.l2 = "No, they behave quite peaceably.";
link.l2.go = "MSStep_6";
break;
case "MSStep_4":
dialog.text = "They... what? Get out of my house, you liar!";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_5":
dialog.text = "I knew it! Griffin sold them weapons! Are they asking about me or my cargo?";
link.l1 = "They asked the guards about you.";
link.l1.go = "MSStep_7";
link.l2 = "They tried to worm some information about you out of the innkeep.";
link.l2.go = "MSStep_8";
break;
case "MSStep_6":
dialog.text = "Peaceably? Are you crazy?";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_7":
dialog.text = "Guards? Bwa-ha! What a wit! Now go to hell!";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_8":
dialog.text = "That old dog wouldn't turn me in. How did they get to town?";
link.l1 = "The 'Cinco Liagas' docked; they were on board.";
link.l1.go = "MSStep_9";
link.l2 = "They slipped into town at night through the jungle.";
link.l2.go = "MSStep_10";
link.l3 = "They've actually been here for a while, lurking out of sight...";
link.l3.go = "MSStep_11";
break;
case "MSStep_9":
dialog.text = "On... the ship? But... no. No, you're lying! Go to hell!";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_10":
dialog.text = "The jungle... Five of them? You're crazy! Leave me.";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_11":
dialog.text = "Yes, I'm sure I've seen them before. Good work, friend. But still... who are they?";
link.l1 = "Spaniards.";
link.l1.go = "MSStep_12";
link.l2 = "Pirates.";
link.l2.go = "MSStep_13";
link.l3 = "Bounty hunters.";
link.l3.go = "MSStep_14";
break;
case "MSStep_12":
dialog.text = "Not a bad attempt... You're more or less worth what they paid you. But you can leave now.";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_13":
dialog.text = "Pirates? Ho ho ho! Oh, what a jester. What a clown. To the sea devil with you!";
link.l1 = "...";
link.l1.go = "exit";
break;
case "MSStep_14":
dialog.text = "Take your money. Tell him I am satisfied with your work.";
link.l1 = "...";
link.l1.go = "exit";
AddMoneyToCharacter(pchar, 1000);
AddCharacterExpToSkill(pchar, "Sneak", 80);
AddCharacterExpToSkill(pchar, "Fortune", 30);
break;
case "FStep_1":
dialog.text = "Hmm... I suppose today it's my treat. As it was yesterday... and the day before, and every other day since... well, it doesn't matter.";
if(makeint(Pchar.money) >= 4)
{
link.l1 = "No, no! Allow me to treat the greatest fisherman in Barbados!";
link.l1.go = "FStep_1_2";
}
link.l2 = "As you wish, my lord... of fish.";
link.l2.go = "FStep_1_3";
break;
case "FStep_1_2":
NextDiag.TempNode = "FStep_2";
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
pchar.questTemp.friend_in_tavern = npchar.id;
AddDialogExitQuest("alc");
break;
case "FStep_1_3":
NextDiag.TempNode = "FStep_3";
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
pchar.questTemp.friend_in_tavern = npchar.id;
AddDialogExitQuest("alc");
break;
case "FStep_2":
AddMoneyToCharacter(pchar, -2);
dialog.snd = "Voice\HADI\HADI028";
dialog.text = "You're God-damned right as hell, god Dammit! Let's drink to that!";
link.l1 = "To the king of fish! *Glurk* So, Arnie, my friend, how long have you been doing this?";
link.l1.go = "FStep_4";
break;
case "FStep_3":
dialog.snd = "Voice\HADI\HADI028";
dialog.text = "What don't you like? By God, I am the greatest fisherman in all the archipelago!";
link.l1 = "Of course it's easy to be the best, in a place with no fish... I also... fished, once.";
link.l1.go = "FStep_5";
break;
case "FStep_4":
AddMoneyToCharacter(pchar, -2);
dialog.text = "Not my first decade at it, my friend. Not my first decade... but anchor me in, I've never seen anything like this...";
link.l1 = "Seen anything like what? Whatever, I'll drink to it!";
link.l1.go = "FStep_6";
break;
case "FStep_5":
dialog.text = "No fish... No fish?! You just must know the area, stupid! There's this one place I found - positively unique! Overnight, poof! The net is full, like magic. God as my witness!";
link.l1 = "Yeah, spots... hotbeds, I looked for spots, looked everywhere... Tell you, ain't no fish here, and no hotspots. To hell with fishing, there's no profit in it!";
link.l1.go = "FStep_7";
break;
case "FStep_6":
dialog.text = "Down the hatch... Ah... now that hits the spot... that... spot... it... Mmm...";
link.l1 = "...";
link.l1.go = "FStep_8";
link.l2 = "Oh yeah? Then where is it?";
link.l2.go = "FStep_Fail";
break;
case "FStep_7":
dialog.text = "You just don't know how to look! You know, I could show you the... you know...";
link.l1 = "...";
link.l1.go = "FStep_8";
link.l2 = "Oh yeah? Then where is it?";
link.l2.go = "FStep_Fail";
break;
case "FStep_8":
Pchar.questTemp.CapBloodLine.fishplace = "Cape Rugged Point.";
dialog.text = "It's... very close. "+Pchar.questTemp.CapBloodLine.fishplace;
link.l1 = "Incredible! Oh, is that the time? I'd best be going...";
link.l1.go = "exit_sit";
NextDiag.TempNode = "First time";
AddQuestRecord("FishermanQuest", "2");
break;
case "FStep_Fail":
dialog.text = "You... Get lost, you slave scout!";
link.l1 = "Go to the sea devil's hell!";
link.l1.go = "exit_sit";
NextDiag.TempNode = "First time";
break;
case "QSTStep_0":
dialog.text = "Who are you, anyway? My name is Alex Winner, and I'm a merchant! Get off, before I buy you from your master, strap a cannon ball to your chest, and dump you off the poop deck!";
link.l1 = "Ahem...";
link.l1.go = "Exit_Away";
Pchar.questTemp.sLocator = "reload1_back";
if(npchar.location == "CommonRoom_MH7") Pchar.questTemp.sLocator = "reload1"
Pchar.questTemp.iTime = -1;
CloseQuestHeader("UsurerQuest");
break;
case "QSTStep_1":
dialog.text = "Hmm... We know each other? My memory's not ideal. What is your...";
link.l1 = "Of course, Raf! But... If you've forgotten my debt to you, then...";
link.l1.go = "QSTStep_3";
break;
case "QSTStep_2":
dialog.text = "What are you talking about? I don't know any moneylenders! I... curses!";
link.l1 = "Give me the money, and I will assure Governor Steed that you returned it voluntarily. You will be a free man.";
link.l1.go = "QSTStep_6";
break;
case "QSTStep_3":
dialog.text = "Oh, wait... Yes, I... think I remember... Yes, right. So, when are you going to repay me?";
link.l1 = "It's a debt of life, my friend... Where would you prefer to die? Is here good?";
link.l1.go = "QSTStep_4";
break;
case "QSTStep_4":
dialog.text = "What?!";
link.l1 = "You betrayed me, Guinness! Because of you, I lost everything! You will die!";
link.l1.go = "QSTStep_5";
break;
case "QSTStep_5":
PChar.quest.QUsurer.win_condition.l1 = "Timer";
PChar.quest.QUsurer.win_condition.l1.date.hour = 0;
PChar.quest.QUsurer.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
PChar.quest.QUsurer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
PChar.quest.QUsurer.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
PChar.quest.QUsurer.function = "QUsurerLate";
AddMoneyToCharacter(pchar, 55000);
ChangeCharacterReputation(PChar, -10);
AddCharacterExpToSkill(pchar, "Leadership", 30);
dialog.text = "No, hold on... see... I have fifty-five thousand! Take it all! I don't need it!";
link.l1 = "Thank you very much, my dear friend.";
link.l1.go = "Exit_Away";
Pchar.questTemp.sLocator = "reload1_back";
if(npchar.location == "CommonRoom_MH7") Pchar.questTemp.sLocator = "reload1";
Pchar.questTemp.iTime = -1;
AddQuestRecord("UsurerQuest", "3");
break;
case "QSTStep_6":
PChar.quest.QUsurer.win_condition.l1 = "Timer";
PChar.quest.QUsurer.win_condition.l1.date.hour = 0;
PChar.quest.QUsurer.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
PChar.quest.QUsurer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
PChar.quest.QUsurer.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
PChar.quest.QUsurer.function = "QUsurerLate";
AddMoneyToCharacter(pchar, 30000);
dialog.text = "You... all right. Here, take it. Take it, Dammit!";
link.l1 = "Thank you very much, my dear friend.";
link.l1.go = "Exit_Away";
Pchar.questTemp.sLocator = "reload1_back";
if(npchar.location == "CommonRoom_MH7") Pchar.questTemp.sLocator = "reload1"
Pchar.questTemp.iTime = -1;
AddQuestRecord("UsurerQuest", "4");
break;
//Жак Соловей
case "JSTStep_0":
dialog.text = "And who would you be? What do you need here?";
link.l1 = "I just wanted to buy some things, but you don't look like a seller.";
link.l1.go = "JSTStep_1";
break;
case "JSTStep_1":
dialog.text = "Maybe it's because I'm not? Or... wait, am I? Hmm.";
link.l1 = "You're not a pirate, are you?";
link.l1.go = "JSTStep_2";
break;
case "JSTStep_2":
dialog.text = "I think so. I could be one, if it pleases you. But is it worth the trouble? No, probably not...";
link.l1 = "Jacques Swallow, isn't it?";
link.l1.go = "JSTStep_3";
break;
case "JSTStep_3":
dialog.text = "Captain Jacques Swallow, if you please.";
link.l1 = "And where is your ship... Captain?";
link.l1.go = "JSTStep_4";
link.l2 = "Do you... see it here?";
link.l2.go = "JSTStep_5";
break;
case "JSTStep_4":
dialog.text = "Ah, well, it's docked... somewhere...";
link.l1 = "Can I help you with something?";
link.l1.go = "JSTStep_6";
break;
case "JSTStep_5":
dialog.text = "Pardon me, what?";
link.l1 = "Can I help you with something?";
link.l1.go = "JSTStep_6";
break;
case "JSTStep_6":
dialog.text = "Why all this trouble? That ship has sailed! Unless under your corsage you hide... well, a sail...";
link.l1 = "Yes, well. About your help?";
link.l1.go = "JSTStep_7";
break;
case "JSTStep_7":
dialog.text = "Well, I already borrowed a few piasters from the owner of this fine establishment...";
link.l1 = "That's exactly what I need.";
link.l1.go = "JSTStep_8";
break;
case "JSTStep_8":
dialog.text = "Do you think it wise... to pick a fight with a pirate?";
link.l1 = "You threatened Miss... Hang about, I'm on the wrong trail here. Where was I? What were we talking about?";
link.l1.go = "JSTStep_9";
break;
case "JSTStep_9":
dialog.text = "Find me someone who can get me to Tortuga for three thousand, and fifteen hundred is yours for the keeping. What do you say?";
link.l1 = "I guess I could try.";
link.l1.go = "JSTStep_10";
link.l2 = "Not interested.";
link.l2.go = "Exit_Away";
Pchar.questTemp.sLocator = "reload1_back";
Pchar.questTemp.iTime = -1;
break;
case "JSTStep_10":
dialog.text = "Just don't tell them who their passenger is. Just say... that I have amnesia. No, say that I hit my head and...";
link.l1 = "I'll think of something.";
link.l1.go = "Exit_Away";
Pchar.questTemp.sLocator = "reload1_back";
Pchar.questTemp.iTime = -1;
AddQuestRecord("PirateQuest", "1");
Pchar.questTemp.CapBloodLine.ShipForJack = true;
sld = characterFromID("Bridgetown_trader");
LAi_RemoveLoginTime(sld);
break;
case "JSTStep_11":
dialog.text = "I'm all ears, my friend. Did you manage to find a... find a... Er, Captain?";
link.l1 = "The corvette 'Sailing Briton', directed by a certain Captain John Mayner is waiting at your service.";
link.l1.go = "JSTStep_12";
break;
case "JSTStep_12":
dialog.text = "Well, what can I say - my hat to you, and many thanks...";
link.l1 = "And fifteen hundred, Jacques.";
link.l1.go = "JSTStep_13";
break;
case "JSTStep_13":
dialog.text = "Ah yes, of course. I just wanted to express my deepest gratitude, and offer you some of my strongest rum...";
link.l1 = "Fifteen hundred, Jacques.";
link.l1.go = "JSTStep_14";
break;
case "JSTStep_14":
dialog.text = "All right, I'm getting there. Here, here, take it. There. See, there it is.";
link.l1 = "Many thanks.";
link.l1.go = "Exit";
AddMoneyToCharacter(pchar, 1500);
AddQuestRecord("PirateQuest", "5");
CloseQuestHeader("PirateQuest");
NextDiag.TempNode = "JSTStep_15";
NPChar.lifeDay = 0;
break;
case "JSTStep_15":
dialog.text = "That's it, then. You may go.";
link.l1 = "Uh-huh.";
link.l1.go = "Exit";
NextDiag.TempNode = "JSTStep_15";
break;
//Джон Майнер
case "MNStep_0":
dialog.text = "John Mayner, captain of the corvette 'Sailing Briton', at your service. What can I do for you?";
link.l1 = "Good day to you, Captain. My name is Peter Blood. May I ask a favor of you? A friend of mine is in a desperate need to set foot on Tortuga, and he is ready to part with three thousand piasters to make it happen.";
link.l1.go = "MNStep_1";
break;
case "MNStep_1":
dialog.text = "May I ask the name of your friend, Mr. Blood?";
link.l1 = "Why, yes. It's... er, Jean-Paul. Ahem.";
link.l1.go = "MNStep_2";
link.l2 = "Sure. Does the name Jacques Swallow mean anything to you?";
link.l2.go = "MNStep_3";
link.l3 = "No.";
link.l3.go = "MNStep_4";
break;
case "MNStep_2":
dialog.text = "Jean-Paul? So he's a Frenchman?";
link.l1 = "And why not? Tortuga is a French port. He is... what you might call a collector. Buys all manner of odd junk.";
link.l1.go = "MNStep_5";
break;
case "MNStep_3":
dialog.text = "Yes... yes indeed it does. Very well, I'll wait for him to board.";
link.l1 = "All the best to you.";
link.l1.go = "MNStep_Exit";
break;
case "MNStep_4":
dialog.text = "No? How can I agree to take on a passenger if I don't know who I'm carrying?";
link.l1 = "Let's say he is Mr. Smith, whose silent delivery will put three thousand in your personal coffer.";
link.l1.go = "MNStep_6";
break;
case "MNStep_5":
dialog.text = "All right, I can take him. But best be quick about it. Let your Jean-Paul know that the 'Sailing Briton' is ready to set sail.";
link.l1 = "Many thanks.";
link.l1.go = "MNStep_Exit";
AddCharacterExpToSkill(pchar, "Sneak", 50);
break;
case "MNStep_6":
dialog.text = "I will wait for Mr. Smith to board my ship.";
link.l1 = "Mr. Smith will be honored to do so.";
link.l1.go = "MNStep_Exit";
break;
case "MNStep_Exit":
AddQuestRecord("PirateQuest", "4");
sld = characterFromID("Jack");
sld.Dialog.CurrentNode = "JSTStep_11";
LAi_SetSitTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit4");
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "ASStep_0":
dialog.text = "You saved me? Who are you?";
link.l1 = "I'm Peter Blood, a... er, local doctor. Why, do you want to see my papers? What's happening here?";
link.l1.go = "ASStep_1";
ChangeCharacterReputation(pchar, 5);
break;
case "ASStep_1":
dialog.text = "Spaniards... they... That large ship... it entered the harbor today. We didn't think twice, but... a Spanish brigand. Their flag trick... it had us all fooled. They gave the fort a full twenty-cannon salute... All of us, fooled...";
link.l1 = "And now, I suppose, the crew of this privateer is pillaging the city?";
link.l1.go = "ASStep_2";
break;
case "ASStep_2":
dialog.text = "Yes... exactly. By sunset, our garrison had surrendered... Two hundred and fifty Spaniards were the new masters of Bridgetown.";
link.l1 = "Well, that's a stroke of luck. Still, devil knows what will come of all this! Look, you run to the woods and hide until the Spaniards have cleared off. Go on.";
Pchar.questTemp.CapBloodLine.SpainInBridgetown = true;
Pchar.questTemp.sLocator = "gate1_back";
Pchar.questTemp.iTime = -1;
link.l1.go = "Exit_RunAway";
AddQuestRecord("EscapeFormBarbados", "3");
break;
}
}