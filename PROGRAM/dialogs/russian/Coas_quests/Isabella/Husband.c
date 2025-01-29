void ProcessDialogEvent()
{
ref NPChar, d, sld;
aref Link, NextDiag;
string NPC_Meeting;
int i;
DeleteAttribute(&Dialog,"Links");
makeref(NPChar,CharacterRef);
makearef(Link, Dialog.Links);
makeref(d, Dialog);
makearef(NextDiag, NPChar.Dialog);
string iDay, iMonth;
iDay = environment.date.day;
iMonth = environment.date.month;
string lastspeak_date = iday + " " + iMonth;
switch(Dialog.CurrentNode)
{
case "exit":
NextDiag.CurrentNode = NextDiag.TempNode;
NPChar.quest.meeting = NPC_Meeting;
DialogExit();
break;
case "Good_exit":
NextDiag.CurrentNode = NextDiag.TempNode;
NPChar.quest.meeting = NPC_Meeting;
DialogExit();
LAi_SetActorType(npchar);
LAi_ActorGoToLocator(npchar, "goto", "goto1", "RP_talkWithHusbandIsOver", 0);
break;
case "First time":
NextDiag.TempNode = "first time";
chrDisableReloadToLocation = false;
bDisableFastReload = false;
if (CheckAttribute(pchar, "quest.wasInBeedroom"))
{
if (CheckAttribute(NPChar, "quest.NiceMeet"))
{
dialog.text = "Hm. Don't you think you're taking a few liberties, walking into the owner's bedroom without knocking?";
link.l1 = "Sorry, pal. I just wandered in...";
link.l1.go = "Good_exit";
}
else
{
dialog.text = "Why the hell are you walking in my house? Protect yourself, villain!";
link.l1 = "Well, okay...";
link.l1.go = "Romantic_Battle_in_Bedroom_2";
}
DeleteAttribute(pchar, "quest.wasInBeedroom");
}
else
{
dialog.text = "Greetings stranger! May I inquire as to what I owe the honor of seeing you in my home?";
link.l1 = "My name is " + PChar.Name + " " + PChar.LastName +
". I'm a captain.";
link.l1.go = "Next_1";
link.l2 = "I'll ask you to forgive me. I think I'm at the wrong address.";
link.l2.go = "Good_exit";
}
break;
case "Next_1":
NextDiag.TempNode = "Usual_1";
dialog.text = "A captain... Or, more likely, a corsair? Judging from your appearance, I'd put my bets on the latter. Well, then. In our time, not one don worthy of esteem has claimed a decent estate by that method. And I'm no the exception.";
link.l1 = "You were a corsair?!";
link.l1.go = "Next_2";
link.l2 = "I'll ask you forgive me. Business, and all!";
link.l2.go = "Good_exit";
break;
case "Next_2":
NextDiag.TempNode = "Usual_1";
dialog.text = "And what's weird about that? It's a very quick and dependable way of getting rich. But after getting married, I thought about settling down. I wish you as much luck.";
link.l1 = "Understood. Thanks for the tip. I'll definitely follow it, have I the chance...";
link.l1.go = "Good_exit";
NPChar.quest.NiceMeet = true;
break;
case "Usual_1":
chrDisableReloadToLocation = false;
bDisableFastReload = false;
NextDiag.TempNode = "Usual_1";
dialog.text = "It's pleasant to see you again. What's brought you to me this time?";
link.l1 = "Nothing in particular. I just came by to visit.";
link.l1.go = "Good_exit";
if (CheckAttribute(pchar, "quest.VisitStep"))
{
if (sti(pchar.quest.VisitStep)>2 && !CheckAttribute(pchar, "quest.wasInBeedroom"))
{
dialog.text = "Oh, "+ GetFullName(pchar)+" is here again. Well, then. it's good to see you again. Why have you come?";
link.l1 = "Salvatore, I want to want to talk with your wife. Can I?";
link.l1.go = "Step_2";
}
if (sti(pchar.quest.VisitStep)>2 && CheckAttribute(pchar, "quest.wasInBeedroom"))
{
if (!CheckAttribute(pchar, "quest.already"))
{
dialog.text = "Don't you think you've become a bit too much of a regular visitor to my wife, buddy?";
link.l1 = "Everything's okay, friend Salvatore. I'm an acquaintance of her relatives. So don't worry.";
link.l1.go = "Step_1";
}
else
{
dialog.text = "Did you pass everything that was needed?";
link.l1 = "Yes, Salvatore. Everything's okay.";
link.l1.go = "Good_exit";
LocatorReloadEnterDisable("SanJuan_houseSp6", "reload2", true);
}
DeleteAttribute(pchar, "quest.wasInBeedroom");
}
}
break;
case "Step_1":
dialog.text = "All of that is good, but from now on be so kind as to ask my permission to see her. Let's just pretend this is a respectable household, shall we?";
link.l1 = "Fine, Salvatore. As you say.";
link.l1.go = "Good_exit";
LocatorReloadEnterDisable("SanJuan_houseSp6", "reload2", true);
pchar.quest.already = true;
break;
case "Step_2":
dialog.text = "And why?";
link.l1 = "I want to deliver her a note from her relatives.";
link.l1.go = "Step_3";
break;
case "Step_3":
dialog.text = "Okay, I'll allow it.";
link.l1 = "Thanks, Salvatore. I'll be quick.";
link.l1.go = "Good_exit";
if (pchar.RomanticQuest == "DelivMigel")
{
dialog.text = "Oh, please! Come in! You are a friend of the family now, what with your help to Miguel in Cumana...";
link.l1 = "Hm... I see, Salvatore. Thank you.";
}
LocatorReloadEnterDisable("SanJuan_houseSp6", "reload2", false);
break;
case "Romantic_Battle_in_Bedroom":
if (CheckAttribute(NPChar, "quest.NiceMeet"))
{
dialog.text = GetFullName(pchar) + " have you met my wife? " + Characters[GetCharacterIndex("Isabella")].Name + ", if you have no objection, I shall return to my work. I'll wait for you downstairs...";
link.l1 = "Oh yes... Now I see your advice in a different light.";
link.l1.go = "Romantic_Battle_in_Bedroom_3";
}
else
{
dialog.text = "What are you doing, in... my wife's bedroom?";
link.l1 = "Oh, is that what this is? I'm sorry, this is a big house... Believe me, the thought never crossed my mind...";
link.l1.go = "Romantic_Battle_in_Bedroom_1";
}
break;
case "Romantic_Battle_in_Bedroom_1":
dialog.text = "Defend yourself, fool, for you are about to die!";
link.l1 = "Oh? Well, we'll see about that!";
link.l1.go = "Romantic_Battle_in_Bedroom_2";
break;
case "Romantic_Battle_in_Bedroom_2":
DialogExit();
AddDialogExitQuest("Romantic_Battle_in_Bedroom_3");
break;
case "Romantic_Battle_in_Bedroom_3":
NextDiag.CurrentNode = "Usual_1";
Pchar.RomanticQuest.TalkInShop = true;
DialogExit();
AddDialogExitQuest("Romantic_Battle_in_Bedroom_4");
break;
case "WeWaitYouTonight":
NextDiag.CurrentNode = "WeWaitYouTonight";
dialog.text = "My wife and I will be glad to see you this evening, Captain.";
link.l1 = "I'll be there, Salvatore.";
link.l1.go = "exit";
chrDisableReloadToLocation = false;
bDisableFastReload = false;
break;
case "SeenMainHero":
dialog.text = "Ho! Your timing is perfect, " + GetFullName(pchar) + "... Kill this filthy pig. Let everyone think the two of them killed each other.";
link.l1 = "...";
link.l1.go = "SeenMainHero_1";
break;
case "SeenMainHero_1":
AddQuestRecord("Romantic_Line", "9");
LAi_SetActorType(npchar);
LAi_ActorRunToLocation(npchar, "reload", "houseSp6", "SanJuan_houseSp6", "goto", "goto1", "Romantic_DeadBrother_3", 2.0);
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
LAi_group_SetCheck("EnemyFight", "OpenTheDoors_R");
LAi_SetFightMode(pchar, true);
NextDiag.CurrentNode = "ArrestInHome_1";
DialogExit();
break;
case "ArrestInHome_1":
dialog.text = "Ah! There you are. Officer, this man killed poor Don Miguel de Valdez! And now, he means to to kill my wife and me! Look at his hands! The blood!";
link.l1 = "You fink! You're the one who killed Don Miguel!";
link.l1.go = "ArrestInHome_2";
break;
case "ArrestInHome_2":
AddDialogExitQuest("Romantic_ArrestInHouse");
NextDiag.CurrentNode = "Romantic_Battle_in_Bedroom_1";
DialogExit();
break;
case "TalkInCave":
dialog.text = "Wow, look at them bill and coo! Am I interrupting?";
link.l1 = "On the contrary, Salvatore. You 're just in time! If only you knew how glad I am to see you!";
link.l1.go = "TalkInCave_1";
break;
case "TalkInCave_1":
dialog.text = "Really?";
link.l1 = "Yes, yes, and no mistake. I have been searching the whole Caribbean for you... Tell me, did you bring a grill?";
link.l1.go = "TalkInCave_2";
break;
case "TalkInCave_2":
dialog.text = "I'm afraid this is not the time...";
link.l1 = "Oh come now. It's always time for barbecue. And this is the last chance you'll have. For tonight, Se√±ora Isabella becomes a widow.";
link.l1.go = "TalkInCave_3";
break;
case "TalkInCave_3":
dialog.text = "Why, aren't you the noble hero.";
link.l1 = "Aye, Salvatore. Aye...";
link.l1.go = "TalkInCave_4";
break;
case "TalkInCave_4":
dialog.text = "Then let us begin! Good luck in hell, " + GetFullName(pchar) + "!";
link.l1 = "You first! Let me know how it is. Incidentally, Salvatore, your wife is a fox. I don't think black suits her... maybe she'll have to mourn in white. In a church, next to me. With a new ring on her finger.";
link.l1.go = "TalkInCave_5";
break;
case "TalkInCave_5":
dialog.text = "Grahhh! When I'm done with you, I'll send that bitch into the abyss after you!";
link.l1 = "No, now. Is that any way to talk about your wife?";
link.l1.go = "TalkInCave_6";
break;
case "TalkInCave_6":
sld = CharacterFromID("Isabella");
LAi_SetActorType(sld);
LAi_ActorRunToLocator(sld, "goto", "goto5", "", -1);
LAi_group_MoveCharacter(npchar, "EnemyFight");
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
LAi_group_SetCheck("EnemyFight", "Romantic_SalvatorIsDead");
LAi_LockFightMode(pchar, true);
DialogExit();
break;
}
}