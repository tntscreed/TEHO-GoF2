void ProcessDialogEvent()
{
ref NPChar, sld;
aref Link, NextDiag;
string sLocator;
int iTime, n;
string sTemp;
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
LAi_SetActorTypeNoGroup(npchar);
LAi_ActorGoToLocation(npchar, "reload", Pchar.questTemp.CapBloodLine.sLocator, "none", "", "", "", sti(Pchar.questTemp.CapBloodLine.iTime));
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "Exit_AwayP":
LAi_SetPlayerType(pchar);
LAi_SetActorTypeNoGroup(npchar);
LAi_ActorGoToLocation(npchar, "reload", Pchar.questTemp.CapBloodLine.sLocator, "none", "", "", "", sti(Pchar.questTemp.CapBloodLine.iTime));
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "Exit_RunAway":
LAi_SetActorTypeNoGroup(npchar);
LAi_ActorRunToLocation(npchar, "reload", Pchar.questTemp.CapBloodLine.sLocator, "none", "", "", "", sti(Pchar.questTemp.CapBloodLine.iTime));
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "GFight":
DialogExit();
LAi_SetPlayerType(Pchar);
NextDiag.CurrentNode = NextDiag.TempNode;
sld = &characters[GetCharacterIndex("Dragun_0")];
LAi_SetCheckMinHP(sld, 1, true, "Blood17");
LAi_SetImmortal(sld, false);
LAi_SetWarriorTypeNoGroup(sld);
LAi_warrior_DialogEnable(sld, false);
LAi_group_MoveCharacter(sld, "TmpEnemy");
LAi_group_Attack(sld, Pchar);
LAi_group_SetRelation("TmpEnemy", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_SetHearRadius("TmpEnemy", 3000.0);
AddDialogExitQuest("MainHeroFightModeOn");
LAi_ActorGoToLocator(NPChar, "goto", "goto6", "", -1);
break;
case "fight1":
DialogExit();
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_SetWarriorType(NPChar);
LAi_group_MoveCharacter(NPChar, "TmpEnemy");
LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true)
AddDialogExitQuest("MainHeroFightModeOn");
Spain_spyDie("");
AddQuestRecord("WeaponsForEscape", "5");
break;
case "fight":
DialogExit();
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_SetWarriorType(NPChar);
LAi_group_MoveCharacter(NPChar, "TmpEnemy");
LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
AddDialogExitQuest("MainHeroFightModeOn");
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
case "Man_FackYou":
dialog.text = LinkRandPhrase("Robbery, in broad daylight! What the hell's going on?! Hang about there, buddy...", "Heh, what're you digging around there for?! You aren't thinking of robbing me? Well, then you're finished!", "Wait, where you reaching into? Oh, turns out you're a thief! Consider yourself finished, pal...");
link.l1 = LinkRandPhrase("Devil!", "?Caramba!", "Ah, damn!");
link.l1.go = "fight_owner";
break;
case "fight_owner":
LAi_SetOwnerTypeNoGroup(NPChar);
LAi_group_Attack(NPChar, Pchar);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "NextQuest":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
Pchar.questTemp.CapBloodLine.stat = "";
AddDialogExitQuest("");
break;
case "First time":
dialog.text = "Mistake";
link.l1 = "...";
link.l1.go = "Exit";
npchar.quest.meeting = "1";
if (npchar.id == "Pitt")
{
if (bBettaTestMode)
{
link.l0 = "Beta Test - Keep on going, to start the game.";
link.l0.go = "Finish";
}
if (Pchar.questTemp.CapBloodLine.stat == "Begining")
{
dialog.text = "Lord Gildoy is heavily injured! He's here, in the house; I carried him here! He sent me for you! To him, quickly!";
link.l1 = "Thanks, Pitt... I'll go to him. You stay here, and if you see the king's dragoons galloping towards here, immediately warn us.";
link.l1.go = "Exit_AwayP";
Pchar.questTemp.CapBloodLine.sLocator = "reload1";
Pchar.questTemp.CapBloodLine.iTime = -1;
if (bBettaTestMode)
{
link.l3 = "Beta Test - To the second quest.";
link.l3.go = "NextQuest";
}
break;
}
if (Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
{
dialog.text = "Peter, Colonel Bishop has been searching for you all evening. The Governor's wife is having another attack. You must go to Governor Steed's residency, immediately.";
link.l1 = "Thank you, Pitt. He's told me.";
link.l1.go = "Exit";
break;
}
if (Pchar.questTemp.CapBloodLine.stat == "WakerOfferComplited")
{
dialog.text = "How are things, my friend?";
link.l1 = "Talk lower, colleague, for now our fates are on the line.";
link.l1.go = "PStep_0";
break;
}
dialog.text = "I'm sorry, Peter, but I must go and work now.";
link.l1 = "Fine. Go.";
link.l1.go = "Exit";
}
if (npchar.id == "Beyns")
{
dialog.text = "Oh. Hello, Doctor Blood. How good that you've come. Lord Gildoy is heavily injured. He's lying now in the bedroom on the second floor of the west wing...";
link.l1 = "I came as soon as I could. I'll go to him immediately. In the meanwhile, you get some hot water and clean cloth ready.";
link.l1.go = "EBStep_0";
}
if (npchar.id == "CapGobart")
{
dialog.text = "I'm Captain Hobart, from the dragoon of Colonel Kirk. Are you hiding the rebels? We have heard about an injured man lying on the second floor, who is he?";
link.l1 = "We're not hiding any rebels, sir. The gentlemen is hurt...";
link.l1.go = "CGStep_1";
DragunInvansion4();
}
if (npchar.id == "Bridgetown_Mayor")
{
if(Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
{
dialog.text = "I wanted to send for Whacker, already. What's the holdup?";
link.l1 = "I was delayed. Please forgive me, Governor.";
link.l1.go = "SStep_0";
link.l2 = "Your people delayed me, Governor Steed. It turns out that your orders are apt to be questioned. Also, some individuals are actively blocking me from healing Spanish soldiers.";
link.l2.go = "SStep_1";
break;
}
if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape3")
{
dialog.text = "Greetings, Doctor Blood. To what do I owe this visit?";
link.l1 = "Good day, Governor. I've brought some prophylactic extract for your spouse, and wanted to have a chance to examine her.";
link.l1.go = "SStep_9";
break;
}
dialog.text = "What do you want, Doctor Blood?";
link.l1 = "Oh, nothing. Sorry for the disturbance.";
link.l1.go = "Exit";
NextDiag.TempNode = "First time";
}
if (npchar.id == "MisStid" && Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
{
dialog.text = "Oh, Doctor Blood! At last! Please, help me!";
link.l1 = "Good evening, Mrs. Steed. Don't worry. Please, you must stop fussing. Steady on; look at me. I need to see your eyes.";
link.l1.go = "MSStep_0";
}
if (npchar.id == "Nettl")
{
dialog.text = "Hey, pal... I'm in sound mind, and... and, uh... health. What, heal... health? Ah, as in sober... Yes, sober. Do you know how I can dis... disappear somewhere, and... er... come back later, somewhere... not there, where... not there, where I, uh... disappeared?";
if(Pchar.questTemp.CapBloodLine.stat == "needMoney")
{
link.l1 = "I must admit that I know just one trick.";
link.l1.go = "NStep_6";
}
else
{
link.l1 = "I'd like to know myself, old timer.";
link.l1.go = "NStep_0";
}
}
if (npchar.id == "Waker")
{
if(Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
{
dialog.text = "Doctor Blood! I'm so happy to see you! I've been looking everywhere for you today, but I couldn't find you. It was as if you were moving across the city like a ghost.";
link.l1 = "Life taught me. Where can I find Mr. Dan?" ;
link.l1.go = "WStep_0";
link.l2 = "Good evening. Where can I find Mr. Dan?";
link.l2.go = "WStep_1";
}
if(Pchar.questTemp.CapBloodLine.stat == "WakerOffer")
{
dialog.text = "I hear that Mrs. Steed is taking up a lot of your time. Well, what can I say? Youth and an attractive demeanor, Doctor Blood! Youth and beauty! That gives a doctor a big advantage, especially when he's curing ladies!";
link.l1 = "I think I see what you're getting at. Why don't you tell it to Governor Steed instead of me. Maybe he'll find it amusing. At your discretion, of course..." ;
link.l1.go = "WStep_3";
}
}
if (npchar.id == "Den")
{
dialog.text = "Good evening, Doctor Blood. May I inquire as to what you were doing in my house?";
link.l1 = "Mrs. Steed is having another migraine attack. I was called immediately. I examined her, and was forced to come to you at such a late hour for the required medicine. Since I didn't find you at home, I decided to wait. I was just about to leave, actually." ;
link.l1.go = "DStep_0";
if (GetCharacterItem(pchar,"migraine_potion") > 0)
{
link.l2 = "Mrs. Steed is having another migraine attack. I was called immediately. I examined her, and was forced to come to you at such a late hour for the required medicine. Having not found you here, I helped myself to the medicine without permission. I ask your pardon, but the situation is quite serious.";
link.l2.go = "DStep_1";
}
link.l3 = "I just came to relay that Doctor Whacker was looking for you, Mr. Dan.";
link.l3.go = "DStep_2";
}
if (npchar.id == "Griffin")
{
if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape1")
{
dialog.text = "Why the devil are you bouncing in here without a knock, you cursed... Oh, it's you, Doctor Blood!";
link.l1 = "Good day, Mr. Griffin. I'll ask you to pardon such an uncouth entry, but I have business for you that can't wait.";
link.l1.go = "GRStep_0";
break;
}
if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape")
{
dialog.text = "Who are you, the Devil take you?!";
link.l1 = "I'm Doctor Blood, a physician from Bridgetown." ;
link.l1.go = "GRStep_10";
break;
}
dialog.text = "What did you forget here, the devil take you?!";
link.l1 = "I'm Doctor Blood, and I'm already gone." ;
link.l1.go = "Exit";
}
if (npchar.id == "Hells")
{
if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape1_1")
{
dialog.text = "What the hell do all of you need?! Protect yourself!";
link.l1 = "Calm down, sir. I'm Peter Blood, a physician from Bridgetown. I mean no harm.";
link.l1.go = "HStep_0";
link.l2 = "Well, if you're asking for it...";
link.l2.go = "fight1";
break;
}
if(Pchar.questTemp.CapBloodLine.stat == "needMoney" && !CheckAttribute(Pchar, "questTemp.CapBloodLine.fishplace"))
{
dialog.text = "Oh, how good that you're here...";
link.l1 = "How may I help?";
link.l1.go = "HStep_5";
break;
}
dialog.text = "What did you forget here, the devil take you?!";
link.l1 = "I'm Doctor Blood, and I'm already gone." ;
link.l1.go = "Exit";
}
if (npchar.id == "Quest_Smuggler")
{
if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape" && sti(Pchar.reputation) >= 50)
{
dialog.text = "I heard about you, Doctor Blood. You've become a real star among the slaves rotting on the plantations. How may I be of service?";
link.l1 = "With you permission, we'll talk lower. The matter is that I need weapons...";
link.l1.go = "QSStep_0";
break;
}
dialog.text = "Hello, Doctor Blood. If they find out that you were talking with me, then you'll be flogged to death. So it's better for you to go your own way.";
link.l1 = "I could be flogged to death even without that... Though you're right, it's time to go." ;
link.l1.go = "Exit";
}
if (npchar.id == "Spain_spy")
{
dialog.text = "Hey, you! Wait...";
link.l1 = "How can I help?";
link.l1.go = "SSStep_0";
}
if(npchar.id == "Hugtorp")
{
if(Pchar.questTemp.CapBloodLine.statcrew == "find")
{
dialog.text = "I'm informed, Peter. Jeremy briefly told me what the matter was, but alas I have to decline.";
link.l1 = "Why? Do you doubt something?";
link.l1.go = "HTStep_1";
break;
}
dialog.text = "Greetings, Peter. The hand that you've treated has fully healed. Thank you.";
link.l1 = "I'm happy that you're better.";
link.l1.go = "Exit";
}
if(npchar.id == "Dieke")
{
if(Pchar.questTemp.CapBloodLine.statcrew == "find")
{
dialog.text = "How can I be of service to you, doctor?";
link.l1 = "You can be of much service, Nicolas. Pitt has already told you what we're planning?";
link.l1.go = "DKStep_0";
break;
}
dialog.text = "How can I be of service to you, doctor?";
link.l1 = "No, nothing. Just passing by.";
link.l1.go = "Exit";
}
if(npchar.id == "Ogl")
{
if(Pchar.questTemp.CapBloodLine.statcrew == "find")
{
dialog.text = TimeGreeting() + ", Doctor Blood.";
link.l1 = "What about the mission, Ogle? Is there still powder in the powder kegs?";
link.l1.go = "OGLStep_0";
break;
}
dialog.text = TimeGreeting() + ", Doctor Blood.";
link.l1 = "Kind.";
link.l1.go = "Exit";
}
break;
case "First Bishop":
if(NPChar.quest.meeting == "0")
{
dialog.text = "The Governor's wife is having another attack. Immediately go to Steed's residence, and do what you have to. When you're finished, come back here - and God help you if you end up next to any Spanish patients.\nTomorrow, I'll find something more important to occupy you with. There's...";
link.l1 = "... Whacker and Bronson, who you could always recommend to the Governor, citing my extraordinary business at the plantation. They're not the brightest physicians, but still hard-working and educated people. In another case, if Governor Steed demands a report about the state of the wounded, I'll be forced to answer him, then go to the poor guys and look them over.";
link.l1.go = "BStep_0";
npchar.quest.meeting = "1";
}
else
{
dialog.text = "Get out of there, you useless lazybones, or I'll order you put in shackles!";
link.l1 = "As you say.";
link.l1.go = "Exit";
}
break;
case "BStep_0":
dialog.text = "Don't give instructions to me, dog! Heal the renowned Mrs. Steed. The lenient treatment we give you as a sick man will change to the cold indifference\nThen we'll see how you like hoeing the ground on the plantations, instead of freely walking the city! Remember your place, slave.";
link.l1 = "I think you're risking a lot, holding me here when Mrs. Steed needs immediate help.";
link.l1.go = "Bishop_Away";
LAi_LockFightMode(pchar, false);
chrDisableReloadToLocation = false;
LAi_LocationFightDisable(loadedLocation, false);
Pchar.questTemp.CapBloodLine.stat = "CureMisStid";
NextDiag.TempNode = "First Bishop";
PChar.quest.CapBloodLineTimer_1.win_condition.l1 = "Timer";
PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.hour = 4;
PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
PChar.quest.CapBloodLineTimer_1.function = "CapBloodLine_q1_Late";
AddQuestRecord("CapBloodLine_q1", "1");
break;
case "BStep_1":
dialog.text = "If you're going to stick your nose into my business, I'll have to do something, handsome to make you stop loitering and misusing the freedom given you. Don't forget that you're a convicted rebel!";
link.l1 = "I get reminded of that all the time.";
link.l1.go = "Exit";
NextDiag.TempNode = "BStep_1";
break;
case "BStep_2":
dialog.text = "You wander about without work for days on end! As far as I'm aware, the Governor and his spouse have everything in order. Might I not close your passage into the city for the time being?";
link.l1 = "You intend to sell Nicolas Dyke?";
link.l1.go = "BStep_3";
break;
case "BStep_3":
dialog.text = "... And there are rumors going about you... What? What business do you have with that poor fellow, dog?";
link.l1 = "Well, the thing is... He's showing the first signs of leprosy...";
link.l1.go = "BStep_4";
break;
case "BStep_4":
dialog.text = "What are you babbling about? Don't you dare pry into my business, or I'll send you to the hoe, having flogged you half to death first!";
link.l1 = "The responsibility of the sale will fall to...";
link.l1.go = "BStep_5";
break;
case "BStep_5":
dialog.text = "Shut up! I'm in debt to Mr. Weston, and this deal will continue! Get out of my sight!";
link.l1 = "Okay.";
link.l1.go = "Exit";
NextDiag.TempNode = "BStep_1";
sld = characterFromID("Quest_Habitue");
sld.Dialog.CurrentNode = "QHStep_0";
AddQuestRecord("DiekeQuest", "2");
break;
case "Bishop_Away":
LAi_SetActorTypeNoGroup(npchar);
LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "Plantation_Sp1", "goto", "goto1", "Blood18", -1);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit()
break;
case "EBStep_0":
dialog.text = "I'll bring everything that you ask. I beg you, hurry! Milord is too bad!";
link.l1 = "I'll do everything that's in my power.";
link.l1.go = "Exit_RunAway";
DeleteAttribute(npchar, "talker");
Pchar.questTemp.CapBloodLine.sLocator = "Reload5";
Pchar.questTemp.CapBloodLine.iTime = -1;
break;
case "EBStep_1":
dialog.text = "Doctor, I've prepared everything that you've asked.";
link.l1 = "Thank you. Put it there.";
link.l1.go = "Exit";
NextDiag.TempNode = "EBStep_2";
AddDialogExitQuest("Blood2");
break;
case "EBStep_2":
dialog.text = "What's happened to Lord Gildoy? Will he live?";
link.l1 = "The worst has passed. I've treated the wounds, and administered medicine. Now he'll get better, but he needs complete rest...";
link.l1.go = "Exit";
NextDiag.TempNode = "EBStep_3";
AddDialogExitQuestFunction("DragunInvansion");
break;
case "EBStep_3":
dialog.text = "I think you ought to heed Jeremy Pitt's warning, and get yourself a weapon.";
link.l1 = "Fine, I'll do just that.";
link.l1.go = "Exit";
NextDiag.TempNode = "EBStep_3";
break;
case "CGStep_1":
dialog.text = "That's clear without words! There's no need to ask how this cursed rebel was wounded... Take him, boys!";
link.l1 = "In the name of all that's humane, sir! We live in England, not in Tangiers! This man is heavily wounded! He can't be moved without endangering his life.";
link.l1.go = "CGStep_2";
break;
case "CGStep_2":
dialog.text = "Oh, and now I have to worry about the health of the rebels! Damn it! You think we're going to cure him? Along the road from Weston to Bridgewater, they've put up gallows - and he'll go to any of them. Colonel Kirk will teach these fool Protestants something that their children, grandchildren and great-grandchildren will remember!";
link.l1 = "If you do that, then I'm afraid you'll be hanged the next day. He doesn't belong to the category of people that you can hang without first asking questions. He has the right to demand a fair trial, a trial by his peers.";
link.l1.go = "CGStep_3";
break;
case "CGStep_3":
dialog.text = "Trial by his peers?";
link.l1 = "Of course. Any person, if he isn't a barbarian or a fool, would first ask a person's family name before sending him to the gallows. This person is Lord Gildoy.";
link.l1.go = "CGStep_4";
break;
case "CGStep_4":
dialog.text = "This person is a rebel, and he'll be sent to Bridgewater, to jail.";
link.l1 = "He won't survive the journey. He can't be moved now.";
link.l1.go = "CGStep_5";
break;
case "CGStep_5":
dialog.text = "The worse for him. My business is arresting rebels!\nAnd who's that man who's been hiding in the fireplace? Another grandee? I'll string him up with my bare hands. That's for sure.";
link.l1 = "That's Viscount Pitt, the cousin of Sir Thomas Vernon, married to the beauty Molly Kirk - the sister of your Colonel.";
link.l1.go = "CGStep_6";
break;
case "CGStep_6":
dialog.text = "You're lying, right? I swear to God, you too shall hang if you are mocking me!";
link.l1 = "If you're so sure of that, then go ahead! Hang him and me! See what happens to you.";
link.l1.go = "CGStep_7";
break;
case "CGStep_7":
dialog.text = "Damn. Who are you, and where did you crawl out from? And how did you end up here?";
link.l1 = "My name is Peter Blood. I'm a physician, and I've been brought here to assist the wounded.";
link.l1.go = "CGStep_8";
break;
case "CGStep_8":
dialog.text = "And who invited you? The Rebels?\nTake him! Tie them up too. We'll show you how to hide rebels!";
link.l1 = "I can't allow you to do that!";
link.l1.go = "GFight";
NextDiag.TempNode = "CGStep_9";
EndQuestMovie();
break;
case "CGStep_9":
dialog.text = LinkRandPhrase("There he is! Grab him!", "Grab him, boys!", "Now, stop!");
link.l1 = LinkRandPhrase("Devil!", "No you don't!", "Ah, damn!");
link.l1.go = "Exit";
AddDialogExitQuestFunction("CapGobartAttack");
NextDiag.TempNode = "CGStep_9";
break;
case "First Guard":
dialog.text = "Where are you off to?";
link.l1 = "My name is Peter Blood. I'm here under orders from Colonel Bishop. I've been ordered to come and see to the treatment of the Governor's spouse.";
link.l1.go = "GStep_0";
break;
case "GStep_0":
dialog.text = "Yes, I remember you. You treated my brother, and others from the Pride of Devon - and also all that Spanish scum, who miraculously survived.\nBronson is my friend... And you're bankrupting him, just like Whacker, making it everywhere all the time. Such clever fellows are rare among slaves, and they don't live long.";
link.l1 = "I ask your pardon, but at the moment the Governor's spouse is in ill health, and by holding me you risk ending up in the same cage as that Spanish scum.";
link.l1.go = "Exit";
LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
LAi_SetLoginTime(npchar, 6.0, 23.0);
npchar.protector = false;
npchar.protector.CheckAlways = 0;
npchar.dialog.filename = "Quest\CapBloodLine\questNPC.c";
break;
case "GStep_1":
dialog.text = "Oh, Doctor Blood! This time I don't remember hearing that Governor Steed has sent for you. What do you need?";
if (GetCharacterItem(pchar,"migraine_potion") > 0)
{
link.l1 = "I've got a migraine prophylactic medicine on me. My goal is to get it to Mrs. Steed, and examine her. Do you think that holding me up at such a time is wise?";
link.l1.go = "Exit";
LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
npchar.protector = false;
npchar.protector.CheckAlways = 0;
npchar.dialog.filename = "Quest\CapBloodLine\questNPC.c";
}
else
{
link.l1 = "Well, if I'm here, it's logical to conclude that I need to get to the Governor.";
link.l1.go = "GStep_2";
}
break;
case "GStep_2":
dialog.text = "Is that so. Well, if I'm stopping you then it's logical to conclude that you won't be getting through that door until I hear a proper order from Governor Steed.";
link.l1 = "In that case, I won't dare distract you further.";
link.l1.go = "Exit";
NextDiag.TempNode = "GStep_3";
AddQuestRecord("WeaponsForEscape", "12");
break;
case "GStep_3":
dialog.text = "And what else?";
if (GetCharacterItem(pchar,"migraine_potion") > 0)
{
link.l1 = "I've got a migraine prophylactic medicine on me. My goal is to get it to Mrs. Steed, and examine her. Do you think that holding me up at such a time is wise?";
link.l1.go = "Exit";
LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
npchar.protector = false;
npchar.protector.CheckAlways = 0;
npchar.dialog.filename = "Quest\CapBloodLine\questNPC.c";
NextDiag.TempNode = "First time";
}
else
{
link.l1 = "I was checking if you were alive or not.";
link.l1.go = "Exit";
NextDiag.TempNode = "GStep_3";
}
break;
case "SStep_0":
ChangeCharacterReputation(PChar, 5);
dialog.text = "Be that as it may, the most important thing now is my wife. She's had another migraine attack. She's overexcited, and rejects any attempts to put her to bed!";
link.l1 = "May I see her?";
link.l1.go = "SStep_2";
break;
case "SStep_1":
dialog.text = "Be that as it may, the most important thing now is my wife. She's had another migraine attack. She's overexcited, and rejects any attempts to put her to bed!";
link.l1 = "May I see her?";
link.l1.go = "SStep_2";
break;
case "SStep_2":
dialog.text = "Yes, yes, of course. She's in the bedroom on the upper floor. Go through the door on my left, up the stairs. Go ahead.";
link.l1.go = "Exit";
NextDiag.TempNode = "SStep_3";
sld = GetCharacter(NPC_GenerateCharacter("MisStid", "AnnaDeLeiva", "woman", "towngirl2", 10, ENGLAND, 3, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart.c";
sld.name = "Alice";
sld.lastname = "Steed";
sld.greeting = "Gr_Dama";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
LAi_SetStayTypeNoGroup(sld);
ChangeCharacterAddressGroup(sld, "CommonBedroom", "goto","goto5");
AddQuestRecord("CapBloodLine_q1", "2");
break;
case "SStep_3":
sld = &characters[GetCharacterIndex("MisStid")];
if (sld.quest.meeting != "1")
{
dialog.text = "Doctor Blood! Hurry and examine my wife.";
link.l1 = "I'm going, already.";
link.l1.go = "Exit";
}
else
{
dialog.text = "How is she, Doctor? You...";
link.l1 = "Everything will be okay, Governor Steed, but I've got to go to the pharmacist for the necessary medicine. I wanted to let you know.";
link.l1.go = "SStep_4";
link.l2 = "Everything will be okay, Governor Steed, if I can catch Mr. Dan at home and wake him. I need medicine immediately, and I'll ask you to issue me funds for the purchase.";
link.l2.go = "SStep_5";
}
break;
case "SStep_4":
dialog.text = "I ask you, hurry!";
link.l1 = "I'm going, already.";
link.l1.go = "Exit";
NextDiag.TempNode = "SStep_4";
break;
case "SStep_5":
dialog.text = "Oh, of course... How much do you need?";
link.l1 = "500 piasters";
link.l1.go = "SStep_6";
link.l2 = "1000 piasters";
link.l2.go = "SStep_7";
link.l3 = "2500 piasters, sir. It's a very expensive healing extract.";
link.l3.go = "SStep_8";
break;
case "SStep_6":
AddMoneyToCharacter(pchar, 500);
dialog.text = "Here. Take 500 piasters.";
link.l1 = "I must hurry.";
link.l1.go = "Exit";
NextDiag.TempNode = "SStep_4";
AddQuestRecord("CapBloodLine_q1", "4");
AddQuestUserData("CapBloodLine_q1", "iMoney", 500);
break;
case "SStep_7":
AddMoneyToCharacter(pchar, 1000);
dialog.text = "Here. Take 1000 piasters, and I hope they're for Mr. Dan.";
link.l1 = "I must hurry.";
link.l1.go = "Exit";
NextDiag.TempNode = "SStep_4";
AddQuestRecord("CapBloodLine_q1", "4");
AddQuestUserData("CapBloodLine_q1", "iMoney", 1000);
break;
case "SStep_8":
AddMoneyToCharacter(pchar, 2500);
dialog.text = "That's a large sum, Doctor. I'll give it to you, but I'll ask you to account upon returning. I'll check everything.";
link.l1 = "Of course. Now, I must hurry.";
link.l1.go = "Exit";
NextDiag.TempNode = "SStep_4";
AddQuestRecord("CapBloodLine_q1", "5");
break;
case "SStep_9":
dialog.text = "You're right, of course, I'll give you such an opportunity. But surely you don't think it's worth worrying about another attack?";
link.l1 = "I came here to prevent it, sir. With your permission...";
link.l1.go = "Exit";
NextDiag.TempNode = "First time";
LocatorReloadEnterDisable("Bridgetown_Townhall", "reload3", false);
LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape3_1";
break;
case "MSStep_0":
dialog.text = "You can do something, Doctor?";
link.l1 = "It looks like it won't work without medicine, but the pharmacy has long since closed. I will have to go to Mr. Dan's house, to get what's required. Drink warm water, and wait for me. I'll return as quickly as I can!";
link.l1.go = "Exit";
NextDiag.TempNode = "MSStep_1";
sld = GetCharacter(NPC_GenerateCharacter("Waker", "usurer_5", "man", "man", 7, ENGLAND, 3, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart.c";
sld.name = "Markus";
sld.lastname = "Whacker";
sld.greeting = "Gr_medic";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "CommonPirateHouse", "goto","goto6");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 2.0, 0);
pchar.quest.CureMisStid.win_condition.l1 = "item";
pchar.quest.CureMisStid.win_condition.l1.item = "migraine_potion";
pchar.quest.CureMisStid.function = "CapBloodLine_q1_End";
sld = ItemsFromID("migraine_potion");
sld.shown = true;
sld.startLocation = "CommonPirateHouse";
sld.startLocator = "item1";
AddQuestRecord("CapBloodLine_q1", "3");
break;
case "MSStep_1":
dialog.text = "Have you brought the medicine, Doctor?";
if(Pchar.questTemp.CapBloodLine.stat == "CureMisStid_Complite")
{
link.l1 = "Yes, it'll put you on your feet quickly.";
link.l1.go = "MSStep_2";
TakeItemFromCharacter(Pchar, "migraine_potion");
}
else
{
link.l1 = "Not yet. I was just going for it.";
link.l1.go = "Exit";
}
break;
case "MSStep_2":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
CapBloodLine_q1_Complited("");
break;
case "MSStep_3":
dialog.text = "Hello, Doctor Blood. I'm much better. It looks like I've really begun to recover - and all thanks to you.";
link.l1 = "Thank you, Mrs. Steed. I'm here to...";
link.l1.go = "MSStep_4";
DeleteAttribute(npchar, "talker");
break;
case "MSStep_4":
dialog.text = "I see that you aren't taking your eyes off this ring... Perhaps it's yours?";
link.l1 = "Muh... mine?";
link.l1.go = "MSStep_5";
link.l1 = "No, alas. It doesn't belong to me.";
link.l1.go = "MSStep_5";
break;
case "MSStep_5":
dialog.text = "The problem is that it's not mine. I didn't have such a ring yesterday, yet this morning I noticed it where you see it now. Um. if my husband weren't so sure that at the time of the ring's appearance he was elsewhere, and that nobody could have come, then surely he...";
link.l1 = "Very interesting.";
link.l1.go = "MSStep_6";
break;
case "MSStep_6":
dialog.text = "It's a simple, unadorned ring. Not my style, and I... well. Here, Doctor Blood. Take it. No matter whose it may be, I don't need it.";
link.l1 = "Oh no, Mrs. Steed! I can't take it... Perhaps instead, I can try to find out whose it is, and how it got here.";
link.l1.go = "MSStep_7";
break;
case "MSStep_7":
dialog.text = "Then let it be so. And now, I must ask you to leave me.";
link.l1 = "Here, I've brought some more miracle extract - which was the point of my visit. All the best.";
TakeItemFromCharacter(Pchar, "migraine_potion");
AddQuestRecord("WeaponsForEscape", "15");
link.l1.go = "Exit";
NextDiag.TempNode = "MSStep_8";
break;
case "MSStep_8":
dialog.text = "Goodbye, Doctor Blood.";
link.l1 = "Yes. Again, all the best.";
link.l1.go = "Exit";
NextDiag.TempNode = "MSStep_8";
break;
case "NStep_0":
dialog.text = "If you... find out... if you find a method, then don't... don't leave me. I'll help. It's... it's the truth.";
link.l1 = "Go home, you old sea wolf. You need some sleep.";
link.l1.go = "Nettl_Away";
NextDiag.TempNode = "NStep_1";
Pchar.questTemp.CapBloodLine.TalkWithNettl = true;
break;
case "NStep_1":
dialog.text = "To your health, Doctor! Eee-heeheehee!";
if(Pchar.questTemp.CapBloodLine.stat == "needMoney")
{
link.l1 = "I've got a conversation for you.";
link.l1.go = "NStep_2";
}
else
{
link.l1 = "My advice to you is to go home and get some sleep.";
link.l1.go = "Exit";
NextDiag.TempNode = "NStep_1";
}
break;
case "NStep_2":
dialog.text = "I heard that Jeremy Pitt already blabbed...";
if(makeint(pchar.money) >= 25000)
{
link.l1 = "Here's 25,000. Take care of the purchase and all the things attached, friend. Don't let me down.";
link.l1.go = "NStep_3";
}
else
{
link.l1 = "Be ready. I will try to sell some items in the Store and as soon as I get the necessary money, we'll work on buying a sloop.";
link.l1.go = "Exit";
NextDiag.TempNode = "NStep_5";
}
break;
case "NStep_3":
AddMoneyToCharacter(pchar, -25000);
dialog.text = "Well, I don't have much of a selection... it seems.";
link.l1 = "Hurry.";
link.l1.go = "Exit";
NextDiag.TempNode = "NStep_4";
NPChar.lifeDay = 0;
CloseQuestHeader("CapBloodLine_q2");
CapBloodLine_q3_Complited();
break;
case "NStep_4":
dialog.text = "Let me finish pouring my rum, and I'll go to the shipyard.";
link.l1 = "Hurry.";
link.l1.go = "Exit";
NextDiag.TempNode = "NStep_4";
break;
case "NStep_5":
dialog.text = "Have you brought the money?";
if(makeint(pchar.money) >= 25000)
{
link.l1 = "Here's 25,000. Take care of the purchase and all the things attached, friend. Don't let me down.";
link.l1.go = "NStep_3";
}
else
{
link.l1 = "Not yet.";
link.l1.go = "Exit";
NextDiag.TempNode = "NStep_5";
}
break;
case "Nettl_Away":
LAi_SetActorTypeNoGroup(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "Blood19", -1);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "NStep_6":
dialog.text = "*hic* Heavenly forces! And how can that be done?";
link.l1 = "Well. In general, I'll take matters into my own hands. All you need to do is go to the shipyard and buy a sloop. I'll bring you the money. Be off to the tavern. We're seen by too many people here.";
link.l1.go = "Nettl_Away";
NextDiag.TempNode = "NStep_5";
Pchar.questTemp.CapBloodLine.TalkWithNettl = true;
break;
case "WStep_0":
AddCharacterExpToSkill(pchar, "Sneak", 50);
dialog.text = "I would like to know myself where he is. I've been waiting for him for hours. It is possible that the guy ran off from too much drinking?\nAnyway, I have things to discuss with you...";
link.l1 = "I'm in a real hurry, Doctor Whacker. I need to find Mr. Dan as soon as possible. We'll have to put aside this talk for now.";
link.l1.go = "WStep_2";
break;
case "WStep_1":
dialog.text = "I would like to know myself where he is. I've been waiting for him for hours. Is is possible that the guy ran off from too much drinking?\nAnyway, I have things to discuss with you...";
link.l1 = "I'm in a real hurry, Doctor Whacker. I need to find Mr. Dan as soon as possible. We'll have to put aside this talk for now.";
link.l1.go = "WStep_2";
break;
case "WStep_2":
dialog.text = "Well, then. I'm not in much of a mood to discuss that which doesn't need to discussed here and now. So I'll go, and if you like you can wait for Dan. We'll talk tomorrow. As soon as you have a free moment, drop by the tavern. I'm really counting on you.";
link.l1 = "Goodbye.";
link.l1.go = "Exit_Away";
Pchar.questTemp.CapBloodLine.sLocator = "reload1";
Pchar.questTemp.CapBloodLine.iTime = 5;
sld = GetCharacter(NPC_GenerateCharacter("Den", "usurer_1", "man", "man", 7, ENGLAND, 3, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart.c";
sld.name = "Henry";
sld.lastname = "Dan";
sld.greeting = "Gr_medic";
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(sld, sTemp);
ChangeCharacterAddressGroup(sld, "BridgeTown_town", "goto","goto3");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 2.0, 0);
AddQuestRecord("CapBloodLine_q2", "1");
break;
case "WStep_3":
dialog.text = "Don't be so hot-headed, my friend. You've misunderstood. The thought never crossed my mind. I want to help you. Since slavery must be so unbearable to a person as talented as you.";
link.l1 = "What insight!";
link.l1.go = "WStep_4";
break;
case "WStep_4":
dialog.text = "I'm no fool, dear colleague. I can see through a person, and can even tell you what he's thinking.";
link.l1 = "You'll convince me if you tell me what I'm thinking about.";
link.l1.go = "WStep_5";
break;
case "WStep_5":
dialog.text = "I haven't once noticed you looking out at sea. And you presume that I don't know your thoughts?\nIf you'd have been able to save yourself from this hell, you could have, as a free person, with relish and profit. You'd fully devote yourself to your profession, in which you are brilliant.\nThe world is great, and there are many countries besides England where a person like you would be warmly met. Aside from the English colonies, there are others.\nThe Dutch colony of Curacao is close by. At this time of the year, it'd be simple to get there even on a small boat. Curacao may become a bridge to a larger world. It'll open up to you as soon as you lose your chains.\nWhat do you say to that?";
link.l1 = "I don't have any money, and a journey like this would take a lot.";
link.l1.go = "WStep_6";
break
case "WStep_6":
dialog.text = "Didn't I say that I wanted to be your friend?";
link.l1 = "Why?";
link.l1.go = "WStep_7";
link.l2 = "That's very honorable from your side, colleague. I would act the same if I the same situation came along.";
link.l2.go = "WStep_8";
break;
case "WStep_7":
dialog.text = "You can't imagine how my heart fills with blood to see a fellow colleague, suffering in slavery, stripped of the opportunity to apply his wonderful capabilities! Why should you live in fetters, even those invisible to the eye, when you can go beyond the horizon and make the world a drop better?\nLeave our work for us in Bridgetown, am I right?";
link.l1 = "To run away... Aside from courage, a man would need money. A sloop will set one back, probably, 20,000.";
link.l1.go = "WStep_9";
break;
case "WStep_8":
dialog.text = "So you agree?";
link.l1 = "To run away... Aside from courage, you need money. A sloop will set one back, probably, 20,000.";
link.l1.go = "WStep_9";
break;
case "WStep_9":
dialog.text = "You'll get your money! It will be a loan, which you'll return to us... that is, to me, when you can.";
link.l1 = "I need to prepare. To think everything over, and coordinate everything with the right people. We'll continue our talk tomorrow. You've opened the door of hope for me, my friend and colleague!";
link.l1.go = "Exit";
n = FindLocation("Bridgetown_tavern");
locations[n].reload.l2.disable = true;
Pchar.questTemp.CapBloodLine.stat = "WakerOfferComplited";
AddQuestRecord("CapBloodLine_q2", "4");
NextDiag.TempNode = "WStep_10";
break;
case "WStep_10":
dialog.text = "Til tomorrow, colleague.";
link.l1 = "Goodbye.";
link.l1.go = "Exit";
NextDiag.TempNode = "WStep_10";
break;
case "WStep_11":
dialog.text = "Good morning, Doctor Blood. I've been waiting for you.";
link.l1 = "It's good, Doctor Whacker. Well, I've collected the people and everything required. I'm just waiting for the money you promised.";
link.l1.go = "WStep_12";
break;
case "WStep_12":
dialog.text = "The thing is, I only have 18,000 piasters on hand - and I estimate you'll need about 25,000. Nevertheless, with such a head start I'm sure that you'll be able to find the rest of the balance.";
link.l1 = "That will be difficult, but I have no choice. What about the sloop? No slave can just come to the shipyard and buy a sloop for himself, as if nothing were the matter.";
link.l1.go = "WStep_13";
AddMoneyToCharacter(pchar, 18000);
break;
case "WStep_13":
dialog.text = "You're right as always, Doctor. I didn't think about that...";
if(Pchar.questTemp.CapBloodLine.TalkWithNettl == false)
{
link.l1 = "Do you know anyone who can help?";
link.l1.go = "WStep_14";
}
else
{
link.l1 = "There's Nattall, the carpenter. I saw him in the tavern earlier.";
link.l1.go = "WStep_15";
}
break;
case "WStep_14":
dialog.text = "The island has not just exiles, but people suffering exile for debts. They'd be happy to spread their wings. I think that any one of them would happily take the opportunity to leave.";
link.l1 = "Thank you, colleague!";
link.l1.go = "Exit";
NextDiag.TempNode = "WStep_16";
n = FindLocation("Bridgetown_tavern");
locations[n].reload.l2.disable = true;
Pchar.questTemp.CapBloodLine.stat = "needMoney";
AddQuestRecord("CapBloodLine_q2", "7");
break;
case "WStep_15":
dialog.text = "Nattall... Yes, a ship's carpenter could be of service. I don't think he'd have any reason to deny you. Well... Courage, Doctor Blood. And good luck!";
link.l1 = "Thank you, my colleague!";
link.l1.go = "Exit";
NextDiag.TempNode = "WStep_16";
n = FindLocation("Bridgetown_tavern");
locations[n].reload.l2.disable = true;
Pchar.questTemp.CapBloodLine.stat = "needMoney";
AddQuestRecord("CapBloodLine_q2", "7");
break;
case "WStep_16":
dialog.text = "Good luck!";
link.l1 = "Thank you.";
link.l1.go = "Exit";
NextDiag.TempNode = "WStep_16";
break;
case "DStep_0":
dialog.text = "What a nightmare! I've got a vial with me, take it. This would not be the first day I suffered without. It's okay, I've got more stored away. Take it, Doctor - it's my civilian duty!";
link.l1 = "All the best.";
link.l1.go = "Exit_Away";
GiveItem2Character(Pchar, "migraine_potion");
Pchar.questTemp.CapBloodLine.sLocator = "houseSp1";
Pchar.questTemp.CapBloodLine.iTime = -1;
break;
case "DStep_1":
dialog.text = "What! Mrs. Steed's health is at stake?! You acted correctly! Hurry then!";
link.l1 = "All the best.";
link.l1.go = "Exit_Away";
ChangeCharacterReputation(PChar, 5);
Pchar.questTemp.CapBloodLine.sLocator = "houseSp1";
Pchar.questTemp.CapBloodLine.iTime = -1;
break;
case "DStep_2":
dialog.text = "Hm... It's clear.";
link.l1 = "All the best.";
link.l1.go = "Exit_Away";
Pchar.questTemp.CapBloodLine.sLocator = "houseSp1";
Pchar.questTemp.CapBloodLine.iTime = -1;
break;
case "DStep_3":
dialog.text = "Hello, Doctor Blood. How may I help you?";
link.l1 = "Good day, Mr. Dan. I'm here under orders from his excellency Governor Steed. I need your miracle extract for the prevention of migraines, immediately.";
link.l1.go = "DStep_4";
break;
case "DStep_4":
dialog.text = "Oh, course, take it. I've got a little left. Give a bow to the governor for me.";
link.l1 = "Thank you. Allow me to be off.";
link.l1.go = "Exit";
GiveItem2Character(Pchar, "migraine_potion");
NextDiag.TempNode = "DStep_5";
AddQuestRecord("WeaponsForEscape", "13");
break;
case "DStep_5":
dialog.text = "Do you require something?";
link.l1 = "No, thank you.";
link.l1.go = "Exit";
NextDiag.TempNode = "DStep_5";
break;
case "PStep_0":
dialog.text = "What? What are you talking about?";
link.l1 = "I'm talking about the opportunity to buy a sloop at the shipyard. Get the slaves in the plantation - obviously, only those who can be completely trusted - ready to depart for the southwest horizon, to the Dutch colony of Curacao.";
link.l1.go = "PStep_1";
break;
case "PStep_1":
dialog.text = "Are you mad, Doctor? No money, no influence among the slaves, no connections in the city... You don't have any of that, and won't!";
link.l1 = "Listen to me, Jeremy Pitt. You're the only navigator we have. Without you, we can't get to the right place. And if I can't get there, it doesn't matter if I get all the people, and sail off after midnight the next day. I need you now, just as much as I needed you at Oglethorpe's mansion...";
link.l1.go = "PStep_2";
link.l2 = "Do you want to get out of here, or not?";
link.l2.go = "PStep_3";
break;
case "PStep_2":
dialog.text = "All right, I understand. I get you entirely. I'll do everything in my power to help...";
link.l1 = "Remember, if you're discovered, all is lost. You are the only navigator amongst us, so without you escape is impossible.";
link.l1.go = "Exit";
AddCharacterExpToSkill(pchar, "LeaderShip", 50);
NextDiag.TempNode = "PStep_4";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape";
Pchar.questTemp.CapBloodLine.statcrew = "find";
Pchar.questTemp.CapBloodLine.Officer = 0;
AddQuestRecord("CapBloodLine_q2", "5");
AddQuestRecord("WeaponsForEscape", "1");
break;
case "PStep_3":
dialog.text = "All right, I understand. I get you entirely. I'll do everything in my power to help...";
link.l1 = "Remember, if you're discovered, all is lost. You are the only navigator amongst us, so without you escape is impossible.";
link.l1.go = "Exit";
NextDiag.TempNode = "PStep_4";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape";
Pchar.questTemp.CapBloodLine.statcrew = "find";
AddQuestRecord("CapBloodLine_q2", "5");
AddQuestRecord("WeaponsForEscape", "1");
break;
case "PStep_4":
if(CheckAttribute(Pchar, "questTemp.CapBloodLine.Officer") && Pchar.questTemp.CapBloodLine.Officer == 3 && Pchar.questTemp.CapBloodLine.stat == "ReadyToEscape")
{
dialog.text = "When do we leave, Peter?";
link.l1 = "I've procured weapons and talked to the men. The only thing left is to buy a sloop. By tomorrow night we'll be far away from here!";
link.l1.go = "PStep_9";
while (GetCharacterItem(pchar,"Weapon_for_escape") > 0)
{
TakeItemFromCharacter(Pchar, "Weapon_for_escape");
}
NextDiag.TempNode = "PStep_10";
break;
}
dialog.text = "Find your men and make all the preparations. I'll wait for you here.";
link.l1 = "See you.";
link.l1.go = "Exit";
NextDiag.TempNode = "PStep_4";
break;
case "PStep_5":
dialog.text = "Peter, dragoons of the Tangier regiment are coming here looking for the rebels....";
link.l1 = "I think we have nothing to fear. We live in a Christian country, and Christians don't fight the wounded or those who give them shelter. Still... Jeremy had better lay low somewhere.";
link.l1.go = "PStep_6";
break;
case "PStep_6":
dialog.text = "All right, I'll hide in the chimney pipe - but you don't know Colonel Kirk. He's the devil incarnate. And you don't even have a sword to defend yourself. \nActually... Take mine; I hid it in the chest on the balcony, but you need to find the key. And hurry up. The dragoons will swoop in here any moment now.";
link.l1 = "Thanks. I'll go get it, though if fate is with me, I won't need it.";
link.l1.go = "Exit_RunAway";
sld = ItemsFromID("key3");
sld.shown = true;
sld.startLocation = "Estate";
sld.startLocator = "item1";
Pchar.questTemp.CapBloodLine.sLocator = "reload2";
Pchar.questTemp.CapBloodLine.iTime = 5;
AddDialogExitQuest("Blood11");
break;
case "PStep_7":
dialog.text = "Hello, Peter. Today marks exactly one month since we started work on Colonel Bishop's sugar plantations. We have it so rough here that sometimes I feel we'd be better off hanged. Some days, it's hard to keep upright... \nJust yesterday, the blacksmith from Bridgewaters was lashed to death for rabble rousing. All he did was express his annoyance with the severity of supervisor Kent. Peter, we must do something, if we want to be alive come winter.";
link.l1 = "Nothing would make me happier, but we can't do a thing without outside help. Look at the fellow who got caught a couple of weeks back. First they flogged him, then they branded the letters 'EC' on his forehead so for the rest of his life everybody would know he was an escaped convict.";
link.l1.go = "PStep_8";
break;
case "PStep_8":
dialog.text = "The blacksmith, he was lucky he only had to face the beatings. \nStill, I'm not here to grouse about hard times. Bishop is looking for you. Why, I dunno. Try not to irritate him, because we do need a doctor around here...";
link.l1 = "Thanks, Jeremy. I'll be meek as a lamb.";
link.l1.go = "Exit_AwayP";
Pchar.questTemp.CapBloodLine.sLocator = "reload1";
Pchar.questTemp.CapBloodLine.iTime = -1;
NextDiag.TempNode = "First time";
Pchar.questTemp.CapBloodLine.stat = "";
chrDisableReloadToLocation = false;
AddDialogExitQuestFunction("ChangePIRATES");
break;
case "PStep_9":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
CapBloodLine_q2_Complited();
break;
case "PStep_10":
dialog.text = "Listen, Peter, did you manage to buy a sloop?";
link.l1 = "Not yet.";
link.l1.go = "Exit";
NextDiag.TempNode = "PStep_10";
break;
case "PStep_11":
dialog.text = "Forgive me, Peter. They... they followed me...";
link.l1 = "Calm down, Jeremy. Hagthorpe told me everything. I take it you meant to leave us without a navigator, by giving that swine Bishop a reason to slice you open?";
link.l1.go = "PStep_12";
break;
case "PStep_12":
dialog.text = "Peter, I don' t think we'll even need a navigator.";
link.l1 = "Oh? And why is that, then?";
link.l1.go = "PStep_13";
break;
case "PStep_13":
dialog.text = "Nettall ran away.";
link.l1 = "Nettall is an imbecile. We'll think of something. Anyway, we'll steal the sloop, regardless. Hagthorpe and the others are all waiting for us in the city. We must warn them before they get caught!";
link.l1.go = "PStep_14";
break;
case "PStep_14":
dialog.text = "Then run to the city and warn them! You can come back later.";
link.l1 = "Okay, Jeremy. Wait for us here.";
link.l1.go = "Exit";
NextDiag.TempNode = "PStep_15";
chrDisableReloadToLocation = false;
LAi_group_SetHearRadius("TmpEnemy", LAI_GROUP_GRD_HEAR - 3);
LAi_group_SetSayRadius("TmpEnemy", LAI_GROUP_GRD_SAY - 1);
LAi_group_SetLookRadius("TmpEnemy", LAI_GROUP_GRD_LOOK - 1);
AddQuestRecord("EscapeFormBarbados", "2");
break;
case "PStep_15":
dialog.text = "Go on, off to the city!";
link.l1 = "We'll come get you.";
link.l1.go = "Exit";
NextDiag.TempNode = "PStep_15";
break;
case "PStep_16":
dialog.text = "Good job, Peter! The guys told me of your skirmish with the Spanish. A pity I missed the fun! Still, we did what we set out to. And good riddance to cursed isle...";
link.l1 = "Good to see you on your feet, my friend! Unfortunately, we're not in safe waters yet. We still must make the open sea, and decide where we're going.";
link.l1.go = "PStep_17";
break;
case "PStep_17":
dialog.text = "True... There's no heading back to England - the moment we show our necks, they'll put a noose around them. Spain's no better, nor Holland... And that goes for the colonies. Our best bet is the French colonies, or the pirates.";
link.l1 = "Well, we should have time to think it over. Not much, mind. Our friends we left behind are neither dead nor are they blind. And soon they'll spy our weakness. We must pick a captain, and prepare to defend ourselves...";
link.l1.go = "PStep_18";
break;
case "PStep_18":
dialog.text = "What choice is there, Peter? We all agree that you should be our captain.";
link.l1 = "Really? All right, then. If there are no objections, let's prepare the ship for combat. Jeremy, you'll be navigator, since you're the only one who's done this before.";
link.l1.go = "PStep_19";
break;
case "PStep_19":
dialog.text = "Aye, aye, Captain!";
link.l1 = "";
link.l1.go = "Exit_RunAway";
Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
Pchar.questTemp.CapBloodLine.iTime = 3;
NPChar.Money = 0;
NPChar.Payment = true;
NPChar.DontClearDead = true;
AddPassenger(pchar, NPChar, false);
Pchar.Ship.Type = GenerateShip(GOF_SHIP_ARABELLA, true);
Pchar.Ship.name = "Cinco Liagas";
SetBaseShipData(Pchar);
Pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
SetCrewQuantity(Pchar, GetMinCrewQuantity(Pchar));
SetCharacterGoods(Pchar,GOOD_FOOD,70);
SetCharacterGoods(Pchar,GOOD_BALLS,300);
SetCharacterGoods(Pchar,GOOD_GRAPES,100);
SetCharacterGoods(Pchar,GOOD_KNIPPELS,100);
SetCharacterGoods(Pchar,GOOD_BOMBS,200);
SetCharacterGoods(Pchar,GOOD_POWDER,500);
SetCharacterGoods(Pchar,GOOD_WEAPON,50);
n = FindLocation("Bridgetown_town");
locations[n].reload.ship1.name = "reloadShip";
locations[n].reload.ship1.go = "Barbados";
locations[n].reload.ship1.emerge = "reload_1";
locations[n].reload.ship1.autoreload = "1";
locations[n].reload.ship1.label = "Sea";
Pchar.location.from_sea = "Bridgetown_town";
setWDMPointXZ("Bridgetown_town");
string sQuest = "CapBloodLaspEpisode";
pchar.quest.(sQuest).win_condition.l1 = "EnterToSea";
pchar.quest.(sQuest).win_condition = "CapBloodLaspEpisode";
pchar.quest.(sQuest).function = "CapBloodLaspEpisode";
AddDialogExitQuestFunction("SpaCrewAtack");
break;
case "GRStep_0":
dialog.text = "With all due respect, Doctor, which I have no doubt is ample - damn your urgent matters to the leviathan of hell!";
link.l1 = "I am sorry I caught you in an ill humor. Perhaps I can help somehow?";
link.l1.go = "GRStep_1";
break;
case "GRStep_1":
dialog.text = "Help me? You?! What can a willful slave do for me...";
link.l1 = "You underestimate me once again, Mr. Griffin. Well, soon you and all the others shall see of what I am capable...";
link.l1.go = "GRStep_2";
link.l2 = "Well... all right. I do need your help, and as things are now, all I can offer is my own in return.";
link.l2.go = "GRStep_3";
break;
case "GRStep_2":
AddQuestRecord("WeaponsForEscape", "4");
dialog.text = "Get lost, Doctor!";
link.l1.go = "Exit";
pchar.quest.PrepareToEscape2.win_condition.l1 = "location";
pchar.quest.PrepareToEscape2.win_condition.l1.location = "Bridgetown_town";
pchar.quest.PrepareToEscape2.function = "LoginSpain_spy";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2";
break;
case "GRStep_3":
dialog.text = "Well... Today, I was met by a Spaniard. He didn't give his name, but his eyes burned with desperation. I don't know where he came from or how he wound up here, but he needed weapons. And... well, you understand, Doctor, I was terrified. I can't go to the authorities now, since I should have done it right away. The Spaniard refused to wait for his weapons, and took my samples from the wall - a number of cutlasses, a long-barreled musket, and a couple of pistols. Damn the swarthy pig!";
link.l1 = "... I know, I know - 'to the sea devil.'";
link.l1.go = "GRStep_2";
NextDiag.TempNode = "GRStep_2";
link.l2 = "I take it he didn't pay for the weapons?";
link.l2.go = "GRStep_4";
break;
case "GRStep_4":
dialog.text = "To hell with the money! My name's engraved on the exhibits! If he fights with my weapons, surely someone will notice... Even if he doesn't fight, sooner or later he'll be caught. And the last thing I want is to end my life on the end of a rope.";
link.l1 = "All right. Tell me where the Spaniard went, and I'll try to solve your problem. In return, I just want what this man took.";
link.l1.go = "GRStep_5";
break;
case "GRStep_5":
dialog.text = "What the devil is the difference, the hands of a Spaniard or the hands of a slave? We'll be strung up together by sunrise...";
link.l1 = "I don't think the devil could say. So how about this. I return your weapons, and in return you prepare several cutlasses and pistols without your mark, by tonight. Deal?";
link.l1.go = "GRStep_6";
break;
case "GRStep_6":
dialog.text = "That Spaniard - you didn't see his eyes, Doctor. He'll butcher you. But I guess that's none of my business. You bring back my exhibits, I'll do whatever you like... for fifteen hundred piasters. He went to port, to the fisherman Hells's house, by Dan the apothecary's place.";
link.l1 = "I will return soon, dear Mr. Griffin. Make the necessary preparations.";
link.l1.go = "GRStep_7_1";
link.l2 = "Wait, hold on... I'm already risking my life to save your reputation. One thousand, not a penny more.";
link.l2.go = "GRStep_7_2";
sld = GetCharacter(NPC_GenerateCharacter("Spain_spy", "shipowner_13", "man", "man", 7, ENGLAND, -1, false, "quest"));
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart.c";
sld.name = "Spaniard";
sld.lastname = "";
GiveItem2Character(sld, "Griffins_Weapon");
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
LAi_SetActorTypeNoGroup(sld);
LAi_ActorSetLayMode(sld);
LAi_SetImmortal(sld, true);
ChangeCharacterAddressGroup(sld, "CommonRoom_MH2", "goto","goto2");
sld = &characters[GetCharacterIndex("Hells")];
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 1.0, 0);
break;
case "GRStep_7_1":
dialog.text = "Fine, but hurry.";
link.l1 = "It won't be long.";
link.l1.go = "Exit";
Pchar.questTemp.CapBloodLine.iMoney = 1500;
NextDiag.TempNode = "GRStep_8";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_1";
AddQuestRecord("WeaponsForEscape", "3");
AddQuestUserData("WeaponsForEscape", "iMoney", 1500);
break;
case "GRStep_7_2":
dialog.text = "Fine, but hurry.";
link.l1 = "It won't be long.";
link.l1.go = "Exit";
Pchar.questTemp.CapBloodLine.iMoney = 1000;
NextDiag.TempNode = "GRStep_8";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_1";
AddQuestRecord("WeaponsForEscape", "3");
AddQuestUserData("WeaponsForEscape", "iMoney", 1000);
break;
case "GRStep_8":
dialog.text = "That was fast. What happened?";
if (GetCharacterItem(pchar,"Griffins_Weapon") > 0)
{
link.l1 = "Here are your weapons, Mr. Griffin. All of them. That Spanish dog is no longer a threat.";
link.l1.go = "GRStep_9";
TakeItemFromCharacter(Pchar, "Griffins_Weapon");
}
else
{
link.l1 = "Just thought I'd swing by.";
link.l1.go = "Exit";
NextDiag.TempNode = "GRStep_8";
}
break;
case "GRStep_9":
dialog.text = "Hmm... very well, I'm not even going to ask how you did it or how many you had to kill along the way. Tonight, in one hour, a similar package will be ready for you. Now I ask that you leave me - after your advance payment, naturally.";
if (makeint(pchar.money) >= sti(Pchar.questTemp.CapBloodLine.iMoney))
{
link.l1 = "Certainly, my dear Griffin. Here is your money. I will return at the designated hour.";
link.l1.go = "Exit";
AddMoneyToCharacter(pchar, (-sti(Pchar.questTemp.CapBloodLine.iMoney)));
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_3";
NextDiag.TempNode = "GRStep_12";
}
else
{
link.l1 = "I don't have that kind of money on me. I'll be back later.";
link.l1.go = "Exit";
NextDiag.TempNode = "GRStep_13";
}
SaveCurrentQuestDateParam("questTemp.CapBloodLine.GriffinTime");
AddQuestRecord("WeaponsForEscape", "6");
break;
case "GRStep_10":
dialog.text = "Yes, I'm beginning to recall something of the sort. What the hell do you want here?";
link.l1 = "I... am interested in some of your wares.";
link.l1.go = "GRStep_11";
break;
case "GRStep_11":
dialog.text = "What?! Weapons ... for you?! Sea devil, you are crazy! Get out!";
link.l1 = "";
link.l1.go = "Exit";
pchar.quest.PrepareToEscape2.win_condition.l1 = "location";
pchar.quest.PrepareToEscape2.win_condition.l1.location = "Bridgetown_town";
pchar.quest.PrepareToEscape2.function = "LoginSpain_spy";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2";
break;
case "GRStep_12":
if (Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape1_3" && GetQuestPastTimeParam("questTemp.CapBloodLine.GriffinTime") >= 1)
{
dialog.text = "Here, take it - but remember, this did not come from me.";
link.l1 = "Thank you.";
link.l1.go = "Exit";
GiveItem2Character(Pchar, "Weapon_for_escape");
NextDiag.TempNode = "First time";
CloseQuestHeader("WeaponsForEscape");
Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";
}
else
{
dialog.text = "Your... goods are not yet ready. Come back later.";
link.l1 = "Oh, well. All right.";
link.l1.go = "Exit";
NextDiag.TempNode = "GRStep_12";
}
break;
case "GRStep_13":
dialog.text = "Did you bring the money?";
if (makeint(pchar.money) >= sti(Pchar.questTemp.CapBloodLine.iMoney))
{
link.l1 = "Yes, here you go. I will return later tonight.";
link.l1.go = "Exit";
NextDiag.TempNode = "GRStep_12";
AddMoneyToCharacter(pchar, (-sti(Pchar.questTemp.CapBloodLine.iMoney)));
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_3";
}
else
{
link.l1 = "I don't have that kind of money on me. I'll be back later.";
link.l1.go = "Exit";
NextDiag.TempNode = "GRStep_13";
}
break;
case "GRStep_14":
dialog.text = "Goodness gracious!";
link.l1 = "Not exactly. Nonetheless, I came to see if you have changed your mind...";
link.l1.go = "GRStep_15";
break;
case "GRStep_15":
dialog.text = "Ch-ch... changed my mind?";
link.l1 = "Weapons, my dear Mr. Griffin. I need weapons. Just a few cutlasses and a pair of pistols, if it's not too much trouble.";
link.l1.go = "GRStep_16";
break;
case "GRStep_16":
dialog.text = "I... I can't. You must understand. Even if I wanted... they would hang me!";
link.l1 = "Calm down, I don't want anything official. Quiet and peaceful - no branding on the hilt, no papers or reports. No one will ever know it happened.";
link.l1.go = "GRStep_17";
break;
case "GRStep_17":
dialog.text = "Hmm... All right then. I have these. Take them. I hope that's enough.";
link.l1 = "More than enough. Thank you very much.";
link.l1.go = "Exit";
GiveItem2Character(Pchar, "Weapon_for_escape");
AddQuestRecord("WeaponsForEscape", "9");
CloseQuestHeader("WeaponsForEscape");
Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";
NextDiag.TempNode = "First time";
break;
case "HStep_0":
dialog.text = "Doctor... What are you doing here?";
link.l1 = "I'm looking for the man whose lifeless body is lying at your feet.";
link.l1.go = "HStep_1";
break;
case "HStep_1":
dialog.text = "Burning to avenge your swarthy chum? Have at it, pup!";
link.l1 = "Nothing so dramatic, Mr. Hells. I have some nice tranquilizers that could do you well. Actually, I must thank you for making my task easier than I expected. This man stole some property from Mr. Griffin, and I have been sent to retrieve it.";
link.l1.go = "HStep_2";
break;
case "HStep_2":
dialog.text = "I won't give you a dime! First this mongrel attacked me, and now you want me to simply...";
link.l1 = "... collect the weapons that I imagine he used in the attack. Nothing more. His money belongs to you, as rightly as anyone.";
link.l1.go = "HStep_3";
break;
case "HStep_3":
dialog.text = "Oh. Well, get on with it, then. Doubt he'll be needing them any more.";
link.l1 = "Many thanks.";
link.l1.go = "HStep_4";
NextDiag.TempNode = "First time";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_2";
break;
case "HStep_4":
NextDiag.CurrentNode = NextDiag.TempNode;
sTemp = GetNationNameByType(ENGLAND) + "_citizens";
LAi_group_MoveCharacter(NPChar, sTemp);
LAi_SetOwnerTypeNoGroup(NPChar);
DialogExit();
Spain_spyDie("");
break;
case "HStep_5":
dialog.text = "Look, I've got some work for you, if you're interested. Well, sure you are. Everybody here needs money.";
link.l1 = "How much are we talking about?";
link.l1.go = "HStep_6";
break;
case "HStep_6":
dialog.text = "I'm prepared to pay you two thousand, if you can tell me something. You see, that damned Arnold Summerlight found... well, the mother lode of fishing spots. And now he's driving me to the poorhouse! Whatever it takes, find out where he gets his catch, and two thousand will be a drop in the bucket for me. Deal?";
link.l1 = "Sounds reasonable enough.";
link.l1.go = "HStep_7";
link.l2 = "That's not for me.";
link.l2.go = "Exit";
NextDiag.TempNode = "HStep_8";
break;
case "HStep_7":
AddQuestRecord("FishermanQuest", "1");
sld = &characters[GetCharacterIndex("Fisherman")];
sld.dialog.currentnode = "FStep_1";
NextDiag.TempNode = "HStep_9";
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "HStep_8":
dialog.text = "So you won't help me?";
link.l1 = "I will.";
link.l1.go = "HStep_7";
link.l2 = "No.";
link.l2.go = "Exit";
NextDiag.TempNode = "HStep_8";
break;
case "HStep_9":
dialog.text = "So?";
if(CheckAttribute(Pchar, "questTemp.CapBloodLine.fishplace"))
{
link.l1 = "I've got it Mr. Hells.";
link.l1.go = "HStep_10";
}
else
{
link.l1 = "So far no news.";
link.l1.go = "Exit";
NextDiag.TempNode = "HStep_9";
}
break;
case "HStep_10":
dialog.text = "Really? Where? Where are all the fish at?";
link.l1 = "He trawls by Rugged Point cape.";
link.l1.go = "HStep_11";
break;
case "HStep_11":
dialog.text = "The devil, how could I miss that! Here, here's your money.";
link.l1 = "Thank you.";
link.l1.go = "Exit";
NextDiag.TempNode = "First time";
AddMoneyToCharacter(pchar, 2000);
CloseQuestHeader("FishermanQuest");
break;
case "SSStep_0":
dialog.text = "I need a gunsmith. Where can I find one?";
link.l1 = "His house ain't far from here. Over yonder.";
link.l1.go = "SSStep_1";
link.l2 = "Why should I tell you? What do you want with a gunsmith?";
link.l2.go = "SSStep_2";
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2_1";
chrDisableReloadToLocation = false;
LocatorReloadEnterDisable("BridgeTown_town", "houseSp2", true);
break;
case "SSStep_1":
dialog.text = "Bwa-ha-ha-hurrr...";
link.l1 = "";
link.l1.go = "Exit_Away";
Pchar.questTemp.CapBloodLine.sLocator = "houseSp2";
Pchar.questTemp.CapBloodLine.iTime = 20;
AddQuestRecord("WeaponsForEscape", "7");
break;
case "SSStep_2":
dialog.text = "Then get gone before I say hello to your gizzard.";
link.l1 = "That would be difficult.";
link.l1.go = "Exit_Away";
Pchar.questTemp.CapBloodLine.sLocator = "houseSp2";
Pchar.questTemp.CapBloodLine.iTime = 20;
AddQuestRecord("WeaponsForEscape", "7");
break;
case "SSStep_3":
dialog.text = "English dog! I will kill every man in this city - starting with you, you stubborn old goat! Don't you understand, the 'Cinco Liagas' is practically here... Wait, what are you doing here?!";
link.l1 = "Pardon me for interrupting.";
link.l1.go = "SSStep_4";
break;
case "SSStep_4":
dialog.text = "Well fine, since you're here already, you're next!";
link.l1 = "Oh, can't I be even earlier than that?";
link.l1.go = "fight";
sld = &characters[GetCharacterIndex("Griffin")];
sld.dialog.currentnode = "GRStep_14";
break;
case "QSStep_0":
dialog.text = "Stop, stop, stop... To ask such a favor is no better than asking me to deliver you from this place. Even under threat of death, I wouldn't consider it. If I were learned, I would suffer far worse... But weapons! As a privileged slave, you must be not only bold but mad to speak openly in a tavern. And I would be even madder to help you...";
link.l1 = "Since you've clearly thought so much about this, you must be interested. All that's left is to agree on the price.";
link.l1.go = "QSStep_1";
break;
case "QSStep_1":
dialog.text = "You're quite astute, Doctor. Well, you're right; I shan't deny it. I do have my dreams... but forgive me if I question your commitment...";
link.l1 = "Could you be clearer?";
link.l1.go = "QSStep_2";
break;
case "QSStep_2":
dialog.text = "I know you have access to the Governor's mansion...";
link.l1 = "You can stop right there. I'm in a hurry, and I doubt the Governor or his wife will fall ill in the next few hours. And those are the only circumstances under which I am admitted.";
link.l1.go = "QSStep_3";
break;
case "QSStep_3":
dialog.text = "With ten cutlasses, several muskets, and... say, three thousand glistening coins on the line, I'm certain you will find a way in.";
link.l1 = "What would you ask of me?";
link.l1.go = "QSStep_4";
break;
case "QSStep_4":
dialog.text = "A small ring. No more.";
link.l1 = "A ring? On his wife's hand, I suppose? That could get grisly, though I suppose I could retrieve it for you...";
link.l1.go = "QSStep_5";
break;
case "QSStep_5":
dialog.text = "My dear Doctor, no. I doubt she wears it. Nonetheless, it is in her possession. The ring is plain, gold. Surely worth no more than two or three piasters, but it is extremely important to me. A fence won't give you a fifth of what I am offering I pray, no more questions. A simple yes or no.";
link.l1 = "All right. I'll be back as soon as I can. Get the goods and money ready.";
link.l1.go = "Exit";
NextDiag.TempNode = "QSStep_6";
sld = &characters[GetCharacterbyLocation("Bridgetown_town", "soldiers", "soldier2")];
sld.dialog.filename = "Coas_quests\CapBloodStart\CapBloodStart.c";
sld.Dialog.CurrentNode = "GStep_1";
sld.protector = true;
sld.protector.CheckAlways = 1 ;
LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", true);
LocatorReloadEnterDisable("Bridgetown_Townhall", "reload3", true);
LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", true);
sld = characterFromID("MisStid");
sld.Dialog.CurrentNode = "MSStep_3";
sld.talker = 10;
ChangeCharacterAddressGroup(sld, "Bridgetown_TownhallRoom", "barmen","bar1");
sld = characterFromID("Den");
LAi_SetCitizenTypeNoGroup(sld);
LAi_SetOwnerTypeNoGroup(sld);
sld.Dialog.CurrentNode = "DStep_3";
ChangeCharacterAddressGroup(sld, "CommonPirateHouse", "goto","goto6");
sld = ItemsFromID("MsStid_ring");
sld.shown = true;
sld.startLocation = "Bridgetown_TownhallRoom";
sld.startLocator = "item1";
pchar.quest.PrepareToEscape3.win_condition.l1 = "location";
pchar.quest.PrepareToEscape3.win_condition.l1.location = "Bridgetown_TownhallRoom";
pchar.quest.PrepareToEscape3.function = "FindMsStid_ring";
AddQuestRecord("WeaponsForEscape", "11");
Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape3";
break;
case "QSStep_6":
if (GetCharacterItem(pchar,"MsStid_ring") > 0)
{
dialog.text = "The Doctor returns! Excellent!";
link.l1 = "How did you learn about the ring?";
link.l1.go = "QSStep_7";
link.l2 = "Here's your trinket. So how about the gold and goods?";
link.l2.go = "QSStep_12";
}
else
{
dialog.text = "Something else?";
link.l1 = "No.";
link.l1.go = "Exit";
NextDiag.TempNode = "QSStep_6";
}
break;
case "QSStep_7":
dialog.text = "Learn? My dear Doctor, I haven't the foggiest what you're on about.";
link.l1 = "Okay... you're not making this easy for me. What kind of a ring is it? Where did it come from?";
link.l1.go = "QSStep_8";
break;
case "QSStep_8":
dialog.text = "This ring is of great importance to me, but of practically no value to you or anyone else. Don't mistake me, I'm grateful for its return - and I've got everything ready for you. I keep my promises, as clearly you keep your own.";
link.l1 = "Since you were unaware of the ring, perhaps I should inquire elsewhere? Try my luck in the market square, perhaps? Look at its luster...";
link.l1.go = "QSStep_10";
break;
case "QSStep_10":
dialog.text = "Waho! The jolly Captain Blood has already found a new taste for life... Come, give it here!";
link.l1 = "Captain'? Okay... I think, sir, you would be best to hand over the ring, then to explain yourself.";
link.l1.go = "QSStep_11";
TakeItemFromCharacter(Pchar, "MsStid_ring");
break;
case "QSStep_11":
dialog.text = "Time is life, Peter Blood. Don't waste it. Quick, now - your weapons and funds. Who knows, maybe our meeting like this was no accident.";
link.l1 = "All right, fine.";
link.l1.go = "Exit";
NextDiag.TempNode = "First time";
GiveItem2Character(Pchar, "Weapon_for_escape");
NextDiag.TempNode = "First time";
CloseQuestHeader("WeaponsForEscape");
AddMoneyToCharacter(pchar, 3000);
AddQuestRecord("WeaponsForEscape", "16");
CloseQuestHeader("WeaponsForEscape");
Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";
break;
case "QSStep_12":
dialog.text = "Thank you highly. Here is your money, and... well, the rest. Farewell.";
link.l1 = "All the best to you.";
link.l1.go = "Exit";
NextDiag.TempNode = "First time";
GiveItem2Character(Pchar, "Weapon_for_escape");
NextDiag.TempNode = "First time";
CloseQuestHeader("WeaponsForEscape");
AddMoneyToCharacter(pchar, 3000);
TakeItemFromCharacter(Pchar, "MsStid_ring");
AddQuestRecord("WeaponsForEscape", "16");
CloseQuestHeader("WeaponsForEscape");
Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";
break;
case "HTStep_0":
dialog.text = "This ring is of great importance to me, but of practically no value to you or anyone else. Don't mistake me, I'm grateful for its return - and I've got everything ready for you. I keep my promises, as clearly you keep your own.";
link.l1 = "Since you were unaware of the ring, perhaps I should inquire elsewhere? Try my luck in the market square, perhaps? Look at its luster...";
link.l1.go = "HTStep_1";
break;
case "HTStep_1":
dialog.text = "I have... some unfinished business, my friend.";
link.l1 = "You'll finish it now, with my help. I can't let you stay here, you old sea wolf. I will need you on this voyage.";
link.l1.go = "HTStep_2";
break;
case "HTStep_2":
dialog.text = "Waho! I respect the hell out of you, you know that. But this is a matter of honor, and I must finish what I started.";
link.l1 = "Then please tell me. What is the matter, and how can I help?";
link.l1.go = "HTStep_3";
break;
case "HTStep_3":
dialog.text = "Recently a man called Stewart Winterwood arrived here. I'm not sure you'll understand, but he is my blood enemy. Because of him, I lost everything - my family, my honor, my life. It's because of him that I'm left here!";
link.l1 = "What happened?";
link.l1.go = "HTStep_4";
break;
case "HTStep_4":
dialog.text = "To hell with the past! What matter is I thought I would never see his God-damned face again, that my last memory of him would be his vile, malicious smirk... But you know what memory I would prefer? Of that face, distorted with pain... stretched across a severed head!";
link.l1 = "Sound good to me. So where do I find him?";
link.l1.go = "HTStep_5";
break;
case "HTStep_5":
dialog.text = "I don't know, the tavern? Bordello? He's around somewhere. Having a merry old time, drinking, hustling... And on his finger, my very own wedding ring. In his house, my wife! Bring me the ring... along with its finger.";
link.l1 = "You want his head too? I can bring that, if you like.";
link.l1.go = "HTStep_13";
NextDiag.TempNode = "HTStep_10";
link.l2 = "You sure about this, Hagthorpe? Two wrongs don't make a right, you know.";
link.l2.go = "HTStep_6";
break;
case "HTStep_6":
dialog.text = "Do I sound like a man conflicted?";
link.l1 = "Still, we all make mistakes. Think about it, is all you have now worth the risk? Why, we could...";
link.l1.go = "HTStep_7";
break;
case "HTStep_7":
dialog.text = "Dammit, Blood! I told you it's a matter of honor! If you're too yellow for the job, just out and tell me! In that case you can visit Hell's leviathans without me!";
link.l1 = "All right, Hagthorpe. Just checking. Sure I'll kill him.";
link.l1.go = "HTStep_13";
link.l2 = "Without you? Not bloody likely. Listen to me, Hagthorpe. We're all set now to sail off and begin a new life. Sooner or later you'll meet this damned Winterwood again, and avenge yourself as you please - without needlessly risking your own hide. You can chop off all his fingers and hang him from the mizen-yard, if it pleases you!";
link.l2.go = "HTStep_8";
NextDiag.TempNode = "HTStep_10";
break;
case "HTStep_8":
dialog.text = "You... you're trying to talk me out of this, when the mongrel is right here under my nose?! After all this time?!";
if(Pchar.SPECIAL.Charisma >= 5)
{
link.l0 = "Well... yes, precisely.";
link.l0.go = "HTStep_9";
}
else
{
AddCharacterExpToSkill(pchar, "LeaderShip", 50);
}
link.l1 = "No... I'm just saying. All right, Hagthorpe. I'll kill him.";
link.l1.go = "HTStep_13";
break;
case "HTStep_9":
dialog.text = "Fine, you win. To hell with Winterwood, for now. I will join you.";
link.l1 = "Wonderful.";
link.l1.go = "Exit";
AddCharacterExpToSkill(pchar, "LeaderShip", 150);
NextDiag.TempNode = "HTStep_12";
Pchar.questTemp.CapBloodLine.Hugtorp = true;
Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
AddQuestRecord("HugtorpTrouble", "2");
CloseQuestHeader("HugtorpTrouble");
break;
case "HTStep_10":
dialog.text = "Back already? Is he dead?";
if (GetCharacterItem(pchar,"DOjeronRing") > 0)
{
link.l1 = "Can't be deader. This what you wanted?";
link.l1.go = "HTStep_11";
TakeItemFromCharacter(Pchar, "DOjeronRing");
}
else
{
link.l1 = "No, I just wanted to see if you'd changed your mind. Guess not, then.";
link.l1.go = "Exit";
NextDiag.TempNode = "HTStep_10";
}
break;
case "HTStep_11":
dialog.text = "At last... All right, Blood. I will join you in the escape. And thank you.";
link.l1 = "Wonderful.";
link.l1.go = "Exit";
NextDiag.TempNode = "HTStep_12";
Pchar.questTemp.CapBloodLine.Hugtorp = true;
Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
AddQuestRecord("HugtorpTrouble", "4");
CloseQuestHeader("HugtorpTrouble");
break;
case "HTStep_12":
dialog.text = "Is everything ready? What do you need of me?";
link.l1 = "Not yet. I'll let you know when.";
link.l1.go = "Exit";
NextDiag.TempNode = "HTStep_12";
break;
case "HTStep_13":
LoginWinterwood();
AddQuestRecord("HugtorpTrouble", "1");
NextDiag.CurrentNode = "HTStep_10";
DialogExit();
break;
case "HTStep_14":
dialog.text = "Bad news, Peter - Colonel Bishop's men nabbed Jeremy Pitt red-handed with our supplies. He just barely managed to tell me of some weapons he stashed in a chest, between the boards in the southern end of the plantation.";
link.l1 = "So what happened to him?";
link.l1.go = "HTStep_15";
chrDisableReloadToLocation = false;
break;
case "HTStep_15":
dialog.text = "That swine Bishop had Pitt lashed half to death, then gave orders to deny him food and water until he names his co-conspirators.";
link.l1 = "That is bad. And for some reason Bishop recalled me from the city... So I may also be under suspicion...";
link.l1.go = "HTStep_16";
break;
case "HTStep_16":
dialog.text = "Pitt is holding up, but you should steer clear of the Colonel; he'll just lock you up. Best wait 'til sundown. When it's dark, we'll get the weapons and free Jeremy.";
link.l1 = "Yes, that's exactly what we'll do. I'll deal with Pitt, while you take advantage of the commotion, to lead the men into the city. Think you can manage?";
link.l1.go = "HTStep_17";
break;
case "HTStep_17":
dialog.text = "Sure thing, Peter. We'll wait for you in the shipyard. Watch for patrols. Bishop's men don't need a reason to grab you, these days.";
link.l1 = "I'll be careful.";
link.l1.go = "Exit";
AddDialogExitQuestFunction("ReturnToPlantation3");
AddQuestRecord("EscapeFormBarbados", "1");
break;
case "HTStep_18":
dialog.text = "Bad news, Peter...";
if(Pchar.questTemp.CapBloodLine.SpainInBridgetown == false)
{
link.l1 = "What now?";
link.l1.go = "HTStep_19";
}
else
{
link.l1 = "I already know.";
link.l1.go = "HTStep_20";
}
break;
case "HTStep_19":
dialog.text = "Bridgetown has been captured by Spaniards. Today a huge ship entered our harbor under a foreign flag. The trick worked so well, they sailed unmolested straight into the harbor, and gave the fort a full twenty-cannon salute at point blank range.";
link.l1 = "This is what I call timing. Devil knows what will come from all this... But that's not such a bad thing!";
link.l1.go = "HTStep_20";
AddQuestRecord("EscapeFormBarbados", "3");
break;
case "HTStep_20":
dialog.text = "What about our escape plan? Nettall ran off, so we're out a sloop...";
link.l1 = "The plan has changed. We'll just have to capture another ship.";
link.l1.go = "HTStep_21";
break;
case "HTStep_21":
dialog.text = "What other ship?";
link.l1 = "How about the star of the moment? I'm guessing most of its crew are having a jolly old time committing atrocities, so we should be able to slip on board rather easily.";
link.l1.go = "HTStep_22";
break;
case "HTStep_22":
dialog.text = "We'd rather die fighting the Spanish than rot on Bishop's plantations! Lead us, Peter!";
link.l1 = "Trick is, getting to it unseen.";
link.l1.go = "Exit";
AddDialogExitQuestFunction("CapBloodOfficers");
AddQuestRecord("EscapeFormBarbados", "4");
NextDiag.TempNode = "HTStep_22b";
break;
case "HTStep_22b":
dialog.text = "What are your orders, Peter?";
link.l1 = "All with me, we're going to attack.";
link.l1.go = "Exit";
NextDiag.TempNode = "HTStep_22b";
AddDialogExitQuestFunction("CapBloodOfficers");
break;
case "HTStep_23":
dialog.text = "What other ship?";
link.l1 = "How about the star of the moment? I'm guessing most of its crew are having a jolly old time committing atrocities, so we should be able to slip on board rather easily.";
link.l1.go = "HTStep_22";
break;
case "HTStep_24":
dialog.text = "You were right, Peter. It all went as you said it would - we claimed this excellent ship with nigh nary a loss.";
link.l1 = "Yes, Hagthorpe... But I'm afraid we're just getting started. You seem like an excellent sailor. Will you be my officer?";
link.l1.go = "HTStep_25";
break;
case "HTStep_25":
dialog.text = "Unfortunately, no, since I'm not my own man. My past just will not let me go. If I leave with you, I will be forever leaving England behind me, and I still have unfinished business there. I'm sorry... but I just can't.";
link.l1 = "So be it. If that's your decision, I will let you ashore, first port we enter... provided we even make it out of here.";
link.l1.go = "Exit_RunAway";
Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
Pchar.questTemp.CapBloodLine.iTime = 3;
break;
case "DKStep_0":
dialog.text = "No, alas, I'm no good to you. It's possible he hasn't yet... but no, it doesn't matter anymore.";
link.l1 = "Doesn't matter? What do you mean? What hasn't happened?";
link.l1.go = "DKStep_1";
break;
case "DKStep_1":
dialog.text = "Colonel Bishop was about to sell me. Yesterday, a buyer rolled into the city looking for a slave well-versed in sailing. I'm afraid there's naught to be done.";
link.l1 = "Oh, really. Hmm... we shall see about that.";
link.l1.go = "exit";
NextDiag.TempNode = "DKStep_2";
sld = characterFromID("Bishop");
sld.Dialog.CurrentNode = "BStep_2";
AddQuestRecord("DiekeQuest", "1");
break;
case "DKStep_2":
dialog.text = "Oh, I'm so sorry.";
link.l1 = "Hold on, Nick. All is not yet lost.";
link.l1.go = "exit";
NextDiag.TempNode = "DKStep_2";
break;
case "DKStep_3":
dialog.text = "Recently, the man sent by a doctor to inspect me... It seems the deal is just about done.";
link.l1 = "Calm down, Nicolas. I've already claimed the gold intended for this deal. You will leave with us tomorrow night.";
link.l1.go = "exit";
Pchar.questTemp.CapBloodLine.Dieke = true;
Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
NextDiag.TempNode = "DKStep_4";;
CloseQuestHeader("DiekeQuest");
break;
case "DKStep_4":
dialog.text = "I can't wait that long!";
link.l1 = "Me neither, Nick.";
link.l1.go = "exit";
NextDiag.TempNode = "DKStep_4";
break;
case "DKStep_5":
dialog.text = "I didn't expect to spill so much blood, to win my freedom.";
link.l1 = "Nicolas, you are a great man and would make a fine officer. Will you join us?";
link.l1.go = "DKStep_6";
break;
case "DKStep_6":
dialog.text = "I'm afraid I'll have to turn you down, Peter. I had a notion of going to Curacao, and from there to Holland, where my fianc√©e is waiting for me. You understand where my priorities lie...";
link.l1 = "Pity, but we all have our own path. We'll drop you off wherever you please.";
link.l1.go = "Exit_RunAway";
Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
Pchar.questTemp.CapBloodLine.iTime = 3;
break;
case "OGLStep_0":
dialog.text = "What do you mean?";
link.l1 = "We're setting course for Curacao tomorrow night.";
link.l1.go = "OGLStep_1";
break;
case "OGLStep_1":
dialog.text = "You mean I should run away from Bishop? You think it's that easy? Not only is he a landowner and a sadist; he's also in charge of the Barbados militia!";
link.l1 = "Well, who isn't. But we've got a connection of our own, and through them we've got money to buy a sloop.";
link.l1.go = "OGLStep_2";
break;
case "OGLStep_2":
dialog.text = "Well, I can only envy you and your co-conspirators...";
link.l1 = "Don't lose heart, my dear cyclops. I'm here to offer you a seat on our voyage.";
link.l1.go = "OGLStep_3";
break;
case "OGLStep_3":
dialog.text = "Peter, I can't. However much I want to.";
link.l1 = "What's the hang-up?";
link.l1.go = "OGLStep_4";
break;
case "OGLStep_4":
dialog.text = "Er... well, it's money, you see.";
link.l1 = "Money? But...";
link.l1.go = "OGLStep_5";
break;
case "OGLStep_5":
dialog.text = "I took a loan some time ago. The moneylender took pity on me when I needed it most. He helped me, and I'm already of the age where I can't simply ignore that. \n I don't want a debt hanging over me.";
link.l1 = "But how did you leave the territory?";
link.l1.go = "OGLStep_6";
break;
case "OGLStep_6":
dialog.text = "I didn't. He was here; he came to see the Colonel, for some reason.";
link.l1 = "Okay, okay, but I need a gunner, and you're the only shot I have. How much do you owe?";
link.l1.go = "OGLStep_7";
break;
case "OGLStep_7":
dialog.text = "Five thousand, my friend. So you can pretty well forget it. Don't worry; you won't need a gunner to reach Curacao.";
link.l1 = "We shall see.";
link.l1.go = "Exit";
NextDiag.TempNode = "OGLStep_8";
Pchar.questTemp.CapBloodLine.Ogl = false;
AddQuestRecord("OglQuest", "1");
break;
case "OGLStep_8":
if(CheckAttribute(Pchar, "questTemp.CapBloodLine.Ogl") && Pchar.questTemp.CapBloodLine.Ogl == true)
{
dialog.text = "Yes, Peter?";
link.l1 = "You debt has been repaid, Ogle. So now, about that gunner position - I won't take no for an answer.";
link.l1.go = "OGLStep_9";
}
else
{
NextDiag.TempNode = "OGLStep_8";
dialog.text = "Yes, Peter?";
link.l1 = "I'm on my way now.";
link.l1.go = "Exit";
NextDiag.TempNode = "OGLStep_8";
}
break;
case "OGLStep_9":
dialog.text = "What? You... paid for me?";
link.l1 = "Wait for my orders tomorrow night.";
link.l1.go = "exit";
Pchar.questTemp.CapBloodLine.Ogl = true;
Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
NextDiag.TempNode = "OGLStep_10";
AddQuestRecord("OglQuest", "3");
CloseQuestHeader("OglQuest");
break;
case "OGLStep_10":
dialog.text = "What orders?";
link.l1 = "For now, Ned, nothing. Tomorrow night.";
link.l1.go = "exit";
NextDiag.TempNode = "OGLStep_10";
break;
case "OGLStep_11":
dialog.text = "That was some fight, Captain. It's been a while since I held a blade like I did today.";
link.l1 = "So, Ned. If I'm not mistaken, you used to be a gunner in the royal fleet?";
link.l1.go = "OGLStep_12";
break;
case "OGLStep_12":
dialog.text = "Fifteen years, I was the best gunner they had!";
link.l1 = "Then, speaking as captain of this vessel, would you be my head gunner?";
link.l1.go = "OGLStep_13";
break;
case "OGLStep_13":
dialog.text = "I'm not young any more, Peter, I've got no pretty notion of dying on foreign soil or becoming a pirate. Still... not like I've got much to lose, and I still replay my glory days in my mind... Yeah, why not.";
link.l1 = "Then let's hop to it!";
link.l1.go = "Exit_RunAway";
Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
Pchar.questTemp.CapBloodLine.iTime = 3;
NPChar.Money = 0;
NPChar.Payment = true;
NPChar.DontClearDead = true;
AddPassenger(pchar, NPChar, false);
AddDialogExitQuestFunction("OglAdd");
break;
}
}