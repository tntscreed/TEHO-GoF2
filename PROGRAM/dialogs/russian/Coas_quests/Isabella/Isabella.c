void ProcessDialogEvent()
{
ref NPChar, d, sld, rColony;
aref Link, NextDiag;
string NPC_Meeting;
int i, iMoney, iTemp;
DeleteAttribute(&Dialog,"Links");
makeref(NPChar,CharacterRef);
makearef(Link, Dialog.Links);
makeref(d, Dialog);
makearef(NextDiag, NPChar.Dialog);
string iDay, iMonth, sTemp;
iDay = environment.date.day;
iMonth = environment.date.month;
string lastspeak_date = iday + " " + iMonth;
if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
{
npchar.angry.ok = 1;
if (!CheckAttribute(npchar, "angry.first"))
{
NextDiag.TempNode = NextDiag.CurrentNode;
Dialog.CurrentNode = "AngryExitAgain";
npchar.angry.first = 1;
}
else
{
switch (npchar.angry.kind)
{
case "repeat":
if (npchar.angry.name == "NewLife_Budget_Add") Dialog.CurrentNode = "AngryRepeat_Budget_Add";
if (npchar.angry.name == "NewLife_Present") Dialog.CurrentNode = "AngryRepeat_Present";
break;
case "quest":
if (npchar.angry.name == "NewLife_Budget_Pay") Dialog.CurrentNode = "AngryRepeat_Budget_Pay";
if (npchar.angry.name == "NewLife_KnowPirates") Dialog.CurrentNode = "AngryRepeat_KnowPirates";
break;
}
}
}
switch(Dialog.CurrentNode)
{
case "exit":
NextDiag.CurrentNode = NextDiag.TempNode;
NPChar.quest.meeting = NPC_Meeting;
DialogExit();
break;
case "First time":
NextDiag.TempNode = "first time";
pchar.quest.wasInBeedroom = true;
bDisableFastReload = true;
pchar.quest.RP_afterVisitBedroom.win_condition.l1 = "ExitFromLocation";
pchar.quest.RP_afterVisitBedroom.win_condition.l1.location = pchar.location;
pchar.quest.RP_afterVisitBedroom.win_condition = "RP_afterVisitBedroom";
dialog.text = "How did you get in here? If you don't leave my bedroom immediately, I'll call my husband.";
link.l1 = "I'm " + GetFullName(pchar) + ". May I know the name of such a wonderful Señorita?";
link.l1.go = "Next_1";
link.l2 = "I'll ask you to forgive me. I'm already leaving...";
link.l2.go = "exit";
break;
case "Next_1":
NextDiag.TempNode = "Next_2";
dialog.text = "Señora, not Señorita. I'm the lady of this house, "+GetFullName(npchar)+". Why have you crept into my quarters?";
link.l1 = "Calm down, Señora. I'm your husband's associate. He suggested that I tour your new home, and there are so many rooms here that getting lost was quite easy.";
link.l1.go = "Next_4";
link.l2 = "Just curiosity! I'm already leaving.";
link.l2.go = "exit";
break;
case "Next_2":
NextDiag.TempNode = "Next_2";
dialog.text = "You're still here? Leave me alone!";
link.l1 = "May I inquire about something?";
link.l1.go = "Next_3";
link.l2 = "Sorry...";
link.l2.go = "exit";
break;
case "Next_3":
NextDiag.TempNode = "Next_2";
dialog.text = "What do you want from me? Talk with my husband. I don't want to talk to you now.";
link.l1 = "Fine. I'll do that.";
link.l1.go = "exit";
break;
case "Next_4":
dialog.text = "Yes, we did buy this house recently. And what common interests do you have with my husband?";
link.l1 = "Our interests intersect in the commercial sphere of influence of the Spanish crown.";
link.l1.go = "Next_5";
link.l2 = "We're old friends, me an' him.";
link.l2.go = "Next_6";
link.l3 = "I must be off. Forgive me.";
link.l3.go = "Next_7";
break;
case "Next_5":
dialog.text = "Oh. Well, I'm a bit distant from... influential commercial... er... insects... So, um. How do you like our house? I decorated it myself!";
link.l1 = "Absolutely one-of-a-kind! You've got such exquisite taste!";
link.l1.go = "Next_8";
link.l2 = "To be honest, it doesn't do much for me. I've seen something similar in an English colony.";
link.l2.go = "Next_9";
Pchar.RomanticQuest.TalkInShop = true;
break;
case "Next_6":
dialog.text = "Friends? I didn't think that my husband could have friends like this. "+ Characters[GetCharacterIndex("Husband")].Name + "!!!";
link.l1 = "Wait! I'll explain everything...";
link.l1.go = "Romantic_Battle_in_Bedroom";
break;
case "Next_7":
dialog.text = "I don't like you. I think it would be best if I called my husband. "+ Characters[GetCharacterIndex("Husband")].Name + "!!!";
link.l1 = "Wait! I'll explain everything...";
link.l1.go = "Romantic_Battle_in_Bedroom";
break;
case "Next_8":
NextDiag.TempNode = "Good_1";
dialog.text = "I'm flattered. You know how to bring a woman to your side, Señor.";
link.l1 = "I merely told the truth. And now allow me to bow out. I won't get in your way...";
link.l1.go = "exit";
ChangeCharacterReputation(pchar, 3);
break;
case "Next_9":
NextDiag.TempNode = "Next_2";
dialog.text = "To me, you're just an uncouth fool!";
link.l1 = "Well... Some think otherwise...";
link.l1.go = "exit";
ChangeCharacterReputation(pchar, -4);
break;
case "Good_1":
NextDiag.TempNode = "Good_1";
dialog.text = "Happy to meet you again. By what fate?";
link.l1 = "I just came to greet you, my dearest "+Npchar.Name+".";
link.l1.go = "exit";
if (!CheckAttribute(pchar, "quest.VisitStep")) pchar.quest.VisitStep = 1;
else pchar.quest.VisitStep = makeint(pchar.quest.VisitStep)+1;
pchar.quest.wasInBeedroom = true;
bDisableFastReload = true;
pchar.quest.RP_afterVisitBedroom.win_condition.l1 = "ExitFromLocation";
pchar.quest.RP_afterVisitBedroom.win_condition.l1.location = pchar.location;
pchar.quest.RP_afterVisitBedroom.win_condition = "RP_afterVisitBedroom";
break;
case "Romantic_Battle_in_Bedroom":
NextDiag.CurrentNode = "Next_2";
DialogExit();
AddDialogExitQuest("Romantic_Battle_in_Bedroom_1");
break;
case "Murder":
NextDiag.TempNode = "Murder";
dialog.text = "Leave me, you filthy murderer!";
link.l1 = "...";
link.l1.go = "exit";
PChar.quest.Romantic_TalkInShop.over = "yes";
break;
case "TalkInShop":
NextDiag.TempNode = "TalkInShop_2";
dialog.text = "Captain "+GetFullName(PChar)+"!";
link.l1 = "Señora! What a pleasant meeting!";
link.l1.go = "exit";
break;
case "TalkInShop_2":
dialog.text = "For the sake of God, Captain, leave him!";
link.l1 = "Not before this scoundrel asks for forgiveness!";
link.l1.go = "TalkInShop_3";
break;
case "TalkInShop_3":
dialog.text = "This is just a small misunderstanding.";
link.l1 = "Then tell me what's gone down!";
link.l1.go = "TalkInShop_4";
break;
case "TalkInShop_4":
dialog.text = "I came to find out why today's groceries failed to arrive as usual. I was sure that my spouse paid Señor "+
GetCharacterFullName("SanJuan_trader")+". But it looks like he forgot. It turns out that we have been running a tab for the last month, and I didn't have the 1200 gold on me. I said that I would bring it later, but Señor " +
GetCharacterFullName("SanJuan_trader")+" got it into his head that I would not pay at all.";
link.l1 = "Take your money, you worthless huckster!";
link.l1.go = "TalkInShop_5";
link.l2 = "Now he'll believe you, won't he?";
link.l2.go = "TalkInShop_6";
break;
case "TalkInShop_5":
AddMoneyToCharacter(pchar, -1200);
NextDiag.TempNode = "Good_1";
dialog.text = "I feel a bit awkward, Captain. I'll return the money to you at once. But it's time for me to go.";
link.l1 = "It's nothing, Señora Isabella. It's reward enough to have had the joy of seeing you again.";
link.l1.go = "TalkInShop_Go";
break;
case "TalkInShop_6":
NextDiag.CurrentNode = "TalkInShop_7";
DialogExit();
characters[GetCharacterIndex("SanJuan_trader")].dialog.currentnode = "Romantic_2";
AddDialogExitQuest("Romantic_TalkInShop_3");
break;
case "TalkInShop_7":
NextDiag.TempNode = "Good_1";
dialog.text = "I thank you. But it's time for me to go. Goodbye.";
link.l1 = "It's nothing, Señora Isabella. It's reward enough to have had the joy of seeing you again.";
link.l1.go = "TalkInShop_Go";
break;
case "TalkInShop_Go":
NextDiag.CurrentNode = "Good_1";
DialogExit();
LAi_ActorGoToLocation(NPChar, "reload", "reload1_back", "SanJuan_church", "goto", "goto1", "Romantic_TalkInShop_end", 4.0);
chrDisableReloadToLocation = true;
break;
case "TalkInChurch":
dialog.text = "Señor Captain, I'm happy to see you. Tell me, are you the captain of the brig they call the Five Holy Wounds of Christ?";
link.l1 = "The Five Holy Wounds of Christ? Gracious, a sinner like me would never have thought to call his tub by such a devout name. Still, for the sake of the wonderful Señora, I'd be ready to change not just my ship's name but my very own!";
link.l1.go = "TalkInChurch_1";
DeleteAttribute(npchar, "talker");
break;
case "TalkInChurch_1":
dialog.text = "Forgive me, Captain. I've made a mistake.";
link.l1 = "Wait, Señora! What are you so sorrowful? Who is this lucky captain, whose fate so worries you? Is it possible that I may have heard of him, and may help you?";
link.l1.go = "TalkInChurch_2";
break;
case "TalkInChurch_2":
dialog.text = "I remember. You're a captain too, right? There's a brig called the Five Holy Wounds of Christ, that should have dropped anchor at San Juan harbor. Maybe that recent storm reached them, on the way from Cumana?";
link.l1 = "Alas, Señora, I know nothing about the fate of this brig, yet I am prepared to search out your courageous captain - if you would but grant me a single smile.";
link.l1.go = "TalkInChurch_3";
break;
case "TalkInChurch_3":
dialog.text = "Oh, Señor. It's not the captain I want, may God preserve him. He has a passenger - my brother, Miguel de Valdez. I promise you a smile, if you can provide me good news about that ship.";
link.l1 = "I'm leaving for Cumana immediately, charming Señora!";
link.l1.go = "TalkInChurch_4";
break;
case "TalkInChurch_4":
dialog.text = "I'll wait anxiously for news of my brother. Do you remember where my house is located?";
link.l1 = "Yes, of course. All the best.";
link.l1.go = "TalkInChurch_Go";
break;
case "TalkInChurch_Go":
chrDisableReloadToLocation = true;
NextDiag.CurrentNode = "WaitShip";
Pchar.RomanticQuest.ShipToCumana = true;
DialogExit();
AddQuestRecord("Romantic_Line", "5");
LAi_SetActorType(NPChar);
LAi_ActorGoToLocation(NPChar, "reload", "reload1", "SanJuan_houseS1Bedroom", "goto", "goto4", "Romantic_TalkInChurch_end", 20.0);
TraderHunterOnMap();
break;
case "WaitShip":
NextDiag.TempNode = "WaitShip";
dialog.text = "Is there any news?";
link.l1 = "I'll report when I learn the fate of the Five Holy Wounds of Christ. 'Til we meet again, "+Npchar.Name+ ".";
link.l1.go = "exit";
if (!CheckAttribute(pchar, "quest.VisitStep")) pchar.quest.VisitStep = 1;
else pchar.quest.VisitStep = makeint(pchar.quest.VisitStep)+1;
bDisableFastReload = true;
pchar.quest.wasInBeedroom = true;
pchar.quest.RP_afterVisitBedroom.win_condition.l1 = "ExitFromLocation";
pchar.quest.RP_afterVisitBedroom.win_condition.l1.location = pchar.location;
pchar.quest.RP_afterVisitBedroom.win_condition = "RP_afterVisitBedroom";
break;
case "Brother_1":
dialog.text = "Miguel! How happy I am to see you! I was worried about you! It's been so long since I've heard from you! How is Father?";
link.l1 = "Isabella! Were it not for this courageous captain, I might never have reached San Juan. Terrible storms raged like demons around Cumana. I bring horrible news. Our father is dead, Isabella! He was forced to sell the family estate, to pay off your promissory notes. This was a real tragedy for him, and his heart couldn't bear it!";
link.l1.go = "Brother_2";
break;
case "Brother_2":
dialog.text = "But Miguel! I didn't give out any promissory notes! This is some kind of tragic misunderstanding!";
link.l1 = "Sister, you have yet to thank our remarkable captain for performing such a valiant favor. I think we can resolve our family questions later.";
link.l1.go = "exit";
AddDialogExitQuest("Romantic_Brother_House_3");
NextDiag.TempNode = "Brother_3";
break;
case "Brother_3":
dialog.text = "Oh, Captain "+GetFullName(pchar)+"! I'm grateful from the bottom of my heart! Forgive me! I was so shocked by my father's death that I forgot all about you! I'll be happy to see you at our house this evening!";
link.l1 = "Señora Isabella! I'm always at your service. I'll ask you to excuse me now. I must take my leave.";
link.l1.go = "Brother_4";
break;
case "Brother_4":
AddQuestRecord("Romantic_Line", "8");
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload2", "SanJuan_houseS1Bedroom", "goto", "goto4", "Romantic_TalkInChurch_end", 5.0);
NextDiag.CurrentNode = "Temp_Thanks";
DialogExit();
break;
case "Temp_Thanks":
NextDiag.TempNode = "Temp_Thanks";
dialog.text = "Oh, my courageous captain! I'll be waiting for you at dinner tonight!";
link.l1 = "I'll certainly be there, Señora Isabella.";
link.l1.go = "exit";
if (!CheckAttribute(pchar, "quest.VisitStep")) pchar.quest.VisitStep = 1;
else pchar.quest.VisitStep = makeint(pchar.quest.VisitStep)+1;
bDisableFastReload = true;
pchar.quest.wasInBeedroom = true;
pchar.quest.RP_afterVisitBedroom.win_condition.l1 = "ExitFromLocation";
pchar.quest.RP_afterVisitBedroom.win_condition.l1.location = pchar.location;
pchar.quest.RP_afterVisitBedroom.win_condition = "RP_afterVisitBedroom";
break;
case "BrigAbordage":
dialog.text = "IT'S YOU!! You murderer! You merciless hypocrite! You thief! You pirate!";
link.l1 = "Señora, though I may not be without sin, I will not allow even you to sully my honor!";
link.l1.go = "BrigAbordage_1";
break;
case "BrigAbordage_1":
dialog.text = "Don't feign your innocence! Salvatore told me personally how you foully killed my brother, Miguel! Yes! Murderer!";
link.l1 = "And you believed him? Señora! After all I'm prepared to do for your sake, still you presume that I would kill your brother? Señora...";
link.l1.go = "BrigAbordage_2";
break;
case "BrigAbordage_2":
dialog.text = "My brother's dead, and you ran from him! I don't want to hear your excuses!";
if (CheckCharacterItem(pchar, "Order"))
{
link.l1 = "I've nothing to excuse, for I saw how Salvatore stabbed your brother. Miguel learned that it was Salvatore who forged those promissory notes that killed your father. He was going to report this to the authorities, when Salvatore killed him. I found the fake promissory notes on your brother's body. They're soaked in the blood of Don Miguel, but still readable. Here they are. Take a look...";
link.l1.go = "BrigAbordage_8";
}
else
{
link.l1 = "I've nothing to excuse, for I saw how Salvatore cut down your brother. Your brother learned that it was Salvatore who forged those promissory notes that killed your father. Don Miguel was going to report this to the Governor, when Salvatore killed him. He tried to kill me as well, to hide his crime. You wouldn't have believed me anyway, so I decided to leave the city for a time.";
link.l1.go = "BrigAbordage_3";
}
break;
case "BrigAbordage_3":
dialog.text = "You, Captain, aren't just a bloody murderer, but also a dirty liar! With what can you prove the truth of your words?";
link.l1 = "Señora, I heard with my own ears how your brother bravely accused Salvatore of forging promissory notes, right to his face. And then saw with my own eyes how Salvatore and his two thugs stabbed poor Miguel! Unfortunately, I was not in time to help...";
link.l1.go = "BrigAbordage_4";
break;
case "BrigAbordage_4":
dialog.text = "You want me to believe your words? And where are these forged promissory notes for which my brother died?! Show them to me!";
link.l1 = "I don't have them, Señora...";
link.l1.go = "BrigAbordage_5";
break;
case "BrigAbordage_5":
dialog.text = "There's truly no end to how low humanity can sink. Listen, Captain! I hate and deeply despise you...";
link.l1 = "Señora Isabella, we have no time for talk. The ship will soon go to the bottom. I offer to continue this conversation on my ship.";
link.l1.go = "BrigAbordage_6";
break;
case "BrigAbordage_6":
dialog.text = "Listen, you foul pirate! No force in the world could force me to go with you. If I'm fated to die, then let it be here and now. As for you, Captain, I curse you for all the misfortune you've brought upon our family!";
link.l1 = "Dammit, Isabella...";
link.l1.go = "BrigAbordage_7";
break;
case "BrigAbordage_7":
dialog.text = "Farewell! I won't say another word...";
link.l1 = "...";
link.l1.go = "exit";
LAi_SetPlayerType(pchar);
LAi_CharacterDisableDialog(npchar);
npchar.location = "none";
npchar.location.group = "";
npchar.location.locator = "";
AddQuestRecord("Romantic_Line", "17");
QuestSetCurrentNode("Atilla", "Isabella_Sink");
break;
case "BrigAbordage_8":
dialog.text = "WHAT?! Salvatore?! What underhanded lies! Promissory notes! Salvatore loves me, the villain! But that letter... this ship... I'm completely mixed up. How I want for this to be merely a dream, Captain " + GetFullName(pchar) + ".";
link.l1 = "Letter? Ship? What are you talking about?";
link.l1.go = "BrigAbordage_9";
TakeItemFromCharacter(pchar, "Order");
break;
case "BrigAbordage_9":
dialog.text = "The captain of this ship showed up at my house, with a letter written in Salvatore's hand. My husband wrote of threat toward me. He asked me to flee San Juan in the ship of the captain who delivered the letter. But as soon as the ship left the harbor in San Juan, I was locked in the cabin. Only now I understand that I've been caught in a trap!";
link.l1 = "And where is Salvatore now? I think it's time to talk to him.";
link.l1.go = "BrigAbordage_10";
break;
case "BrigAbordage_10":
dialog.text = "I don't know where my husband is... God, this is just unbearable! To lose one's father and brother, and then to learn that one's husband is responsible for all of these misfortunes... May I ask a favor,Captain?";
link.l1 = "I'll be happy to serve you, Señora Isabella.";
link.l1.go = "BrigAbordage_11";
break;
case "BrigAbordage_11":
dialog.text = "Could you transport me to my cousin Rosita Fernandez, in Belize?";
link.l1 = "Of course, Señora. But first allow me to visit Portobelo, since we're right nearby. I'll try to find Salvatore, since he is waiting for your arrival.";
link.l1.go = "BrigAbordage_12";
break;
case "BrigAbordage_12":
dialog.text = "Fine, Captain. But afterwards, be so kind as to bring me to Rosita...";
link.l1 = "Everything will be done, Señora.";
link.l1.go = "exit";
LAi_SetPlayerType(pchar);
pchar.RomanticQuest = "SeekInPortoBello";
AddQuestRecord("Romantic_Line", "18");
AddPassenger(pchar, npchar, false);
SetCharacterRemovable(npchar, false);
Pchar.quest.Romantic_AmbushInPortoBello.win_condition.l1 = "location";
Pchar.quest.Romantic_AmbushInPortoBello.win_condition.l1.location = "PortoBello_houseF2";
Pchar.quest.Romantic_AmbushInPortoBello.win_condition = "Romantic_AmbushInPortoBello";
sld = GetCharacter(NPC_GenerateCharacter("Rosita", "AnnaDeLeiva", "woman", "towngirl", 5, SPAIN, -1, false, "quest"));
sld.talker = 10;
sld.name 	= "Rosita";
sld.lastname = "Fernandez";
sld.Dialog.Filename = "Coas_quests\Isabella\BrigCaptain.c";
sld.dialog.currentnode = "Rosita";
sld.greeting = "Gr_Dama";
LAi_SetStayType(sld);
ChangeCharacterAddressGroup(sld, "Beliz_houseS4", "goto", "goto2");
LocatorReloadEnterDisable("Beliz_town", "houseS4", false);
break;
case "AmbushPortoBello":
dialog.text = "Señor " + pchar.name + ", I went ashore to find out you were doing.";
link.l1 = "Señora Isabella,  that is a rather impulsive action...";
link.l1.go = "AmbushPortoBello_1";
break;
case "AmbushPortoBello_1":
dialog.text = "Oh God, what's happened here?!";
link.l1 = "Oh, Isabella, you weren't very lucky in marriage. These two bandits are who Salvatore hired to kill you.";
link.l1.go = "AmbushPortoBello_2";
break;
case "AmbushPortoBello_2":
dialog.text = "My murder?!";
link.l1 = "That's it. As one of these guys said, Choke her quietly. They got me mixed up with the captain of the brig that took you out of San Juan, and laid everything out to me. Señora, I can't tell you how glad I am that I learned about this, and could intercept you in time...";
link.l1.go = "AmbushPortoBello_3";
break;
case "AmbushPortoBello_3":
dialog.text = "That's the truth, Captain. That really is so. There is no doubt that I owe you my life...";
link.l1 = "It's nothing, Isabella. When I see you so scared and defenseless, a hitherto unseen feeling awakes in my soul...";
link.l1.go = "AmbushPortoBello_4";
break;
case "AmbushPortoBello_4":
dialog.text = "Ah, Señor " + pchar.name + ". Now is neither the time nor the place for this conversation. Forgive me, dear Captain. "+
"Let's leave this awful place!";
link.l1 = "Oh, it is you who must forgive me, Señora Isabella. You're right, my timing is pretty dreadful. Anyway, let's get going.";
link.l1.go = "AmbushPortoBello_5";
break;
case "AmbushPortoBello_5":
AddQuestRecord("Romantic_Line", "24");
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 2.0);
DialogExit();
break;
case "BelizTalk":
dialog.text = "Well, here we are. What do you say, Señor " + pchar.name + "?";
link.l1 = "Señora, I've completed your request. I've let Rosita know about your arrival, and she is waiting for you. Beyond that, I've checked the house and learned that they have not yet arrived in the area.";
link.l1.go = "BelizTalk_1";
break;
case "BelizTalk_1":
dialog.text = "Captain, you certainly are my guardian angel...";
link.l1 = "Say, Isabella... I don't suppose now I may speak more freely of my feelings?";
link.l1.go = "BelizTalk_2";
break;
case "BelizTalk_2":
dialog.text = "Go ahead, Señor...";
link.l1 = "Isabella, you know that I am a privateer - an occupation unworthy of a lady such as yourself. But I love you, Isabella, and want you to know that!";
link.l1.go = "BelizTalk_3";
break;
case "BelizTalk_3":
dialog.text = "Captain " + pchar.name + ", you are a noble man. A real knight. I owe you my life, but I want to say flat-out that my feelings for you are limited to gratitude for my rescue...";
link.l1 = "Señora, if I've understood you correctly... May I hope that one day you will say yes to me?";
link.l1.go = "BelizTalk_4";
break;
case "BelizTalk_4":
dialog.text = "You've understand everything correctly, my guardian angel.";
link.l1 = "Hot damn, I'm so happy I could just pop! I feel like a young boy! Oh... Forgive me, Señora, for my roughness. These things burst out sometimes...";
link.l1.go = "BelizTalk_5";
break;
case "BelizTalk_5":
dialog.text = "It's all right, Captain. I'll try to soften your manner, if I'm ever given such an opportunity.";
link.l1 = "Isabella, I'm yours - from my brain to my bones. But we've still got one matter to attend to: Salvatore.";
link.l1.go = "BelizTalk_6";
break;
case "BelizTalk_6":
dialog.text = "And what do you plan to do?";
link.l1 = "I don't know. There are no particular leads, Salvatore's always moving. But I have one acquaintance in common with him - a pirate named Attila. Salvatore owes him big...";
link.l1.go = "BelizTalk_7";
break;
case "BelizTalk_7":
dialog.text = "Okay, Captain. Well, I've got to rest a little bit after what's happened. I'll be waiting for you with the good news here, at my cousin's.";
link.l1 = "Goodbye, Isabella.";
link.l1.go = "BelizTalk_8";
break;
case "BelizTalk_8":
QuestSetCurrentNode("Atilla", "SalvatorNews");
NextDiag.CurrentNode = "BelizTalk_after";
AddQuestRecord("Romantic_Line", "19");
chrDisableReloadToLocation = false;
RemovePassenger(pchar, npchar);
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "houseS4", "Beliz_houseS4", "goto", "goto1", "Romantic_TalkInChurch_end", 3.5);
DialogExit();
break;
case "BelizTalk_after":
dialog.text = "Captain, what news do you have?";
link.l1 = "Nothing yet, Isabella.";
link.l1.go = "exit";
NextDiag.TempNode = "BelizTalk_after";
break;
case "IsabellaInCave":
dialog.text = "Oh! Here you are, " + pchar.name + "! I've finally seen you again!";
link.l1 = "Isabella, you're alive! Thank the Lord! In the jungle, I found a girl that looked exactly like the girl with whom you left Rosita's house yesterday.";
link.l1.go = "IsabellaInCave_1";
break;
case "IsabellaInCave_1":
dialog.text = "Poor Cancita, Salvatore killed her!";
link.l1 = "The villain! Tell me quickly, Isabella. What happened?";
link.l1.go = "IsabellaInCave_2";
break;
case "IsabellaInCave_2":
dialog.text = pchar.name + ", my husband is hellspawn! I must admit that I made myself more conspicuous than I should have. Every day, I took a stroll around the city. Yesterday, Salvatore attacked me with another bandit. Without a pause or a thought, that second man stabbed Cancita with a knife. My God!";
link.l1 = "Calm down, Isabella... What happened next?";
link.l1.go = "IsabellaInCave_3";
break;
case "IsabellaInCave_3":
dialog.text = "Next, they dragged me here. Salvatore tried to get me to sign over a warrant, giving him control of poor Miguel's estate. Going by the will, you see, everything was passed on to me.";
link.l1 = "So that's why he didn't kill you at once! Isabella, it's quite the unexpected bit of luck that Salvatore found out about Miguel's will.";
link.l1.go = "IsabellaInCave_4";
break;
case "IsabellaInCave_4":
dialog.text = "I understood that the minute I signed these papers I would be dead. I collected all of my strength and refused to sign them, no matter what he threatened to do. I was just hoping that Rosita would report my disappearance, and that you would be able to find me...";
link.l1 = "Well, Isabella, I'm to blame too! I left you alone in Belize with no protection! But I should have realized the danger...";
link.l1.go = "IsabellaInCave_5";
break;
case "IsabellaInCave_5":
dialog.text = "Don't diminish yourself, " + pchar.name + ". After all, you did save me again.";
link.l1 = "Isabella, I've dealt with your jailers. But where is Salvatore himself?";
link.l1.go = "IsabellaInCave_6";
break;
case "IsabellaInCave_6":
dialog.text = "He went to the city, and promised to bring a brazier back soon.";
link.l1 = "What brazier?";
link.l1.go = "IsabellaInCave_7";
break;
case "IsabellaInCave_7":
dialog.text = "A brazier with pliers, to burn the soles of my feet.";
link.l1 = "Damn! That really was good timing, on my part...";
link.l1.go = "exit";
LAi_SetActorType(npchar);
pchar.RomanticQuest = "FoundIsabella";
AddDialogExitQuest("Romantic_SalvatorInCave");
break;
case "SalvatorIsDead":
dialog.text = "It's all over!";
link.l1 = "Finally, Isabella...";
link.l1.go = "SalvatorIsDead_1";
break;
case "SalvatorIsDead_1":
dialog.text = "Señor " + pchar.name + ", I ask of you - please escort me to Rosita's house.";
link.l1 = "Señora Isabella... Now that all is said and done, and that I have rendered you a widow, permit me to offer you my hand... and my heart.";
link.l1.go = "SalvatorIsDead_2";
break;
case "SalvatorIsDead_2":
dialog.text = pchar.name + ", I accept your offer.";
link.l1 = "Excellent! And in the meantime I'll try to find what Salvatore stole from you.";
link.l1.go = "SalvatorIsDead_3";
break;
case "SalvatorIsDead_3":
dialog.text = "Do as you wish, Señor. I want to just forget what happened. Let's do this, then. I'll spent a few days at Rosita's, and then go to San Juan by myself, since nothing is threatening me now.";
link.l1 = "Yes, Isabella. I expect no danger for you anymore.";
link.l1.go = "SalvatorIsDead_4";
break;
case "SalvatorIsDead_4":
dialog.text = "I'll get my things in order in San Juan, reclaim my maiden name - de Valdez - and in a month or so, we can get married in a church in the city.";
link.l1 = "Very reasonable, Isabella...";
link.l1.go = "SalvatorIsDead_5";
break;
case "SalvatorIsDead_5":
dialog.text = "But you must promise me that you'll put down your life as a privateer.";
link.l1 = "Señora, that would be a serious step for me. This is how I earn my living. But for your sake, Isabella, I'm ready to try anything. So... All right. I agree!";
link.l1.go = "SalvatorIsDead_6";
break;
case "SalvatorIsDead_6":
dialog.text = "Very good, " + pchar.name + ". And now I'll ask you to escort me to my cousin's. I can't remain here any longer...";
link.l1 = "Fine, Isabella.";
link.l1.go = "SalvatorIsDead_7";
break;
case "SalvatorIsDead_7":
Pchar.quest.Romantic_DelivToRosita.win_condition.l1 = "location";
Pchar.quest.Romantic_DelivToRosita.win_condition.l1.location = "Beliz_houseS4";
Pchar.quest.Romantic_DelivToRosita.win_condition = "Romantic_DelivToRosita";
LAi_SetActorType(npchar);
LAi_ActorFollowEverywhere(npchar, "", -1);
DialogExit();
break;
case "RositaHouse":
dialog.text = "Captain " + GetFullName(pchar) + ", I'll wait for you at San Juan, in one month...";
link.l1 = "Fine, Isabella. But are you sure that you can find your way there on your own, without any problems?";
link.l1.go = "RositaHouse_1";
AddQuestRecord("Romantic_Line", "22");
break;
case "RositaHouse_1":
dialog.text = "I'll be in San Juan in a month. Be sure of that...";
link.l1 = "Fine, Isabella.";
link.l1.go = "exit";
NextDiag.TempNode = "RositaHouse_1";
break;
case "InSanJuanAgain":
dialog.text = "Señor " + pchar.name + "! You've arrived...";
link.l1 = "Yes, Señora Isabella. Is everything all right?";
link.l1.go = "InSanJuanAgain_1";
break;
case "InSanJuanAgain_1":
dialog.text = "Yes, everything is fine. Now, my guardian angel, are you ready for a quiet family life?";
link.l1 = "Yes, Isabella. I've had enough blood.";
link.l1.go = "InSanJuanAgain_2";
break;
case "InSanJuanAgain_2":
dialog.text = "And you still love me?";
link.l1 = "Isabella, dear, how can you ask that?! I'm mad about you!";
link.l1.go = "InSanJuanAgain_3";
break;
case "InSanJuanAgain_3":
dialog.text = "Fine, " + pchar.name + ". Then I'll tell you that everything is ready for the wedding ceremony. Tomorrow morning, I'll be waiting for you at the altar...";
link.l1 = "Isabella... Our fates will be joined in the morning!";
link.l1.go = "InSanJuanAgain_4";
break;
case "InSanJuanAgain_4":
dialog.text = "Yes. As for tonight, however... I must ask you to leave. You've got no place here, until the wedding...";
link.l1 = "Fine, Isabella. 'Til tomorrow...";
link.l1.go = "exit";
NextDiag.TempNode = "InSanJuanAgain_after";
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", true);
pchar.RomanticQuest = "WaitBeginWidding";
AddQuestRecord("Romantic_Line", "23");
break;
case "InSanJuanAgain_after":
dialog.text = NPCStringReactionRepeat("You've got no place here, until the wedding...", "Señor, be reasonable! Not until we're married! ", "No! No! And once again, no!",
"Señor, my beloved, I'm asking you to leave immediately!", "block", 1, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("Ah, Isabella, how can I stand it?! I want to see you know...", "Isabella, this is some kind of curse. I'll go mad before tomorrow!",
"?Caramba! What can I do? Though I'm happy that, for my fiancee at least, the laws of honor do not ring hollow... ", "Ahh, Isabella, I am forced to yield...", npchar, Dialog.CurrentNode);
link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "InSanJuanAgain_out", npchar, Dialog.CurrentNode);
NextDiag.TempNode = "InSanJuanAgain_after";
break;
case "InSanJuanAgain_out":
AddDialogExitQuest("Romantic_OutFromHouse");
DialogExit();
break;
case "Cancel_Widding":
dialog.text = "How dare you not turn up at the church?! I gave you my love, and you trampled it! How could you be so cruel, so ungrateful?!";
link.l1 = "Isabella...";
link.l1.go = "exit";
NextDiag.TempNode = "Cancel_Widding_1";
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", true);
CloseQuestHeader("Romantic_Line");
break;
case "Cancel_Widding_1":
dialog.text = "That's it! I've had enough! Leave, now!";
link.l1 = "Oh, Isabella..";
link.l1.go = "exit";
NextDiag.TempNode = "Cancel_Widding_1";
break;
case "TalkWidding":
dialog.text = "Hello, " + pchar.name + ".";
link.l1 = "Hello, Isabella... I've never seen you so wonderful...";
link.l1.go = "TalkWidding_1";
break;
case "TalkWidding_1":
dialog.text = "Thank you, " + pchar.name + ". Are you ready now? May we begin?";
link.l1 = "Of course!";
link.l1.go = "TalkWidding_2";
break;
case "TalkWidding_2":
dialog.text = "You may begin, Padre...";
link.l1 = "...";
link.l1.go = "exit";
LAi_SetActorType(npchar);
LAi_ActorTurnToLocator(npchar, "barmen", "stay");
AddDialogExitQuest("Romantic_Padre");
break;
case "AmbushInChurch":
dialog.text = "What's happening? " + pchar.name + ", I'm scared!";
link.l1 = "Isabella, move aside!";
link.l1.go = "exit";
AddDialogExitQuest("Romantic_fightInChurch_2");
break;
case "IsabellaIsMyWife":
dialog.text = "Were those Salvatore's people? But how can that be? You killed him before my eyes!";
link.l1 = "He must have hired them before I finished him off.";
link.l1.go = "IsabellaIsMyWife_1";
break;
case "IsabellaIsMyWife_1":
dialog.text = "Oh, Lord. Can it be that I'll continue to live in fear?";
link.l1 = "No, Isabella. It's over. Salvatore is gone, as are all his hired goons.";
link.l1.go = "IsabellaIsMyWife_2";
break;
case "IsabellaIsMyWife_2":
dialog.text = "I really hope you're right... " + pchar.name + ", I want to go home, as quickly as possible!";
link.l1 = "Go, my dear. I'll hold out for a short while, but I'll be home soon.";
link.l1.go = "IsabellaIsMyWife_3";
break;
case "IsabellaIsMyWife_3":
rColony = GetColonyByIndex(FindColony("SanJuan"));
dialog.text = "Dear, you need to go to the Governor and personally tell him about this incident. After something like this, we need to receive official approval to live in this city.";
if (sti(rColony.HeroOwn))
{
link.l1 = "Don't worry yourself, Isabella. I own this city - lock, stock, and barrel.";
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
}
else
{
link.l1 = "Fine, Isabella. I'll do everything...";
pchar.RomanticQuest.MayorOk = 1;
}
link.l1.go = "IsabellaIsMyWife_4";
break;
case "IsabellaIsMyWife_4":
chrDisableReloadToLocation = true;
LAi_SetActorType(npchar);
LAi_ActorRunToLocation(npchar, "reload", "reload1", "SanJuan_houseSp6", "goto", "goto1", "Romantic_TalkInChurch_end", 15.0);
NextDiag.TempNode = "NewLife_firstTime";
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "NewLife_firstTime":
rColony = GetColonyByIndex(FindColony("SanJuan"));
dialog.text = "Oh, dearest. How good that you've finally come home! Did you straighten out all the questions regarding the incident in the church?";
if (sti(rColony.HeroOwn))
{
dialog.text = "Oh, dearest. How good that you've finally come home! Is everything okay?";
link.l1 = "Yes, dear, everything is okay...";
}
else
{
dialog.text = "Oh, dearest. How good that you've finally come home! Did you straighten out all the questions regarding the incident in the church?";
link.l1 = "Yes, dear. I had an audience with the Governor. Everything's in order. He congratulates us, even.";
}
link.l1.go = "NewLife_firstTime_1";
break;
case "NewLife_firstTime_1":
dialog.text = "Well, then. That's very good. Now, if you don't mind, let's discuss the principles of joint living.";
link.l1 = "What principles can there be, Isabella? I love you! That's the basic principle!";
link.l1.go = "NewLife_firstTime_2";
break;
case "NewLife_firstTime_2":
dialog.text = "And I too, dear. But a family is not just love, but a combined way of life. In that way, apart from mutual love, there are at leas two principles by which this family must live.";
link.l1 = "Isabella, I'm in awe of your prudence! But, maybe for now we'll just tackle that first principle... and bring it to life, right here and now?";
link.l1.go = "NewLife_firstTime_3";
break;
case "NewLife_firstTime_3":
dialog.text = "Everything has its time, dear. Don't be so persistent. Let's discuss the other two, if you're not against it?";
link.l1 = "For you, dear, anything at all. All right, let's discuss the other two principles.";
link.l1.go = "NewLife_firstTime_4";
break;
case "NewLife_firstTime_4":
dialog.text = "Honey, I adore you... Now then, principle number two: finances. We must decide the family budget. Your home was your ship, but now your home is here - and you must understand that owning real estate is a particular financial burden, meaning city taxes. "+
"Apart from that, providing for our daily necessities also means certain expenses...";
link.l1 = "Isabella, I'm prepared to turn over everything that I have!";
link.l1.go = "NewLife_firstTime_5";
break;
case "NewLife_firstTime_5":
dialog.text = "Very good, but let's start with the small things... So let's add things up. On a monthly basis, you must bring into the house at least " + FindRussianMoneyString(MOD_SKILL_ENEMY_RATE*10000) + ".";
link.l1 = "As you say, Isabella. Anything for you! And what is the third principle?";
link.l1.go = "NewLife_firstTime_6";
break;
case "NewLife_firstTime_6":
dialog.text = "The third principle is your promise to stop privateering. Support the family in another area. Don't sink ships, or capture cities. The Lord won't forgive us that...";
link.l1 = "Well, then. I'll remember my promises very well. I agree with these conditions, dear.";
link.l1.go = "exit";
NextDiag.TempNode = "NewLife";
AddDialogExitQuest("Romantic_afterFirstTime");
break;
case "NewLife_hello":
iDay = GetQuestPastDayParam("RomanticQuest");
dialog.text = LinkRandPhrase("Hell, dear!", "Greetings, my husband.", "Happy to see my spouse.");
link.l1 = RandPhraseSimple("Hello, Isabella!", "Greetings, my dear....");
link.l1.go = "NewLife";
if (iDay > 40)
{
dialog.text = RandPhraseSimple("Hello, dear! And now please explain where you were for " + FindRussianDaysString(iDay) + "?", "Greetings, my husband... Who has been who-knows where, for " + FindRussianDaysString(iDay) + ". Perhaps you'll tell me, dear?");
link.l1 = RandPhraseSimple("Isabella, dear, all this time I've been taking care of affairs.", "Dear, everything sort of fell on me all at once...");
link.l1.go = "NewLife_hello_1";
}
if (GetQuestPastDayParam("RomanticQuest") > 3 && pchar.RomanticQuest == "OpenTheDoosOfHouse")
{
dialog.text = "Hello, loving husband. I've opened the door to you only because my cousin Rosita asked me to.";
link.l1 = "Isabella, I see what you're saying. But please understand me, too: I'm a sailor!";
link.l1.go = "NewLife_hello_2";
}
break;
case "NewLife_hello_1":
dialog.text = "Listen. Of course I understand that you're a captain. That's your work, rushing to and fro across the sea. But you should understand me, as well. I'm not going to sit at home alone, for months at a time! And note, if you ever intend to leave me here for so long again, I just won't open the door to you!";
link.l1 = RandPhraseSimple("I get you, Isabella... Well, I am sorry that I had to leave you alone for so long.", "Forgive me, that you had to remain alone for so long. I see how you must have felt...");
link.l1.go = "NewLife";
SaveCurrentQuestDateParam("RomanticQuest");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_3");
break;
case "NewLife_hello_2":
dialog.text = "I want you to understand just one thing - the interests of our family. If you think that you can just show up here from time to time, then you're deeply mistaken. We must have a family, not a farce.";
link.l1 = "Fine, Isabella. I'll try not to leave you for too long...";
link.l1.go = "NewLife";
SaveCurrentQuestDateParam("RomanticQuest");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_3");
break;
case "NewLife":
iMoney = IsabellaCheckBudgetMoney();
if (iMoney > 0)
{
dialog.text = NPCStringReactionRepeat("Dear, we have a problem. We are in debt, up to the gills. We have to deposit " + FindRussianMoneyString(iMoney) + ", so as to regulate our tax problems.",
"This is the second time today that I've told you about our financial problems. We need to pay off " + FindRussianMoneyString(iMoney) + ".",
"Look, this is third time I've told you about our debts. We owe " + FindRussianMoneyString(iMoney) + ".",
"How many times do I have to remind you you of the bigger picture? Our debt comes to all of " + FindRussianMoneyString(iMoney) + ".", "block", 3, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat(RandPhraseSimple("?Caramba! How could I have let this go?!", "Wow, things have really been going to seed around the house..."),
"Is this the second time? Oh. That's unfortunate. ",
"The third time now?! Oh, man...",
"Yes, Isabella. I remember...", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_Budget_Pay";
break;
}
if (CheckAttribute(pchar, "RomanticQuest.Cheking.GrabbingTown") && pchar.RomanticQuest.Cheking != "Ok")
{
if (rand(sti(pchar.RomanticQuest.Cheking.GrabbingTown)*150) >= GetCharacterSkill(pchar, "Sneak"))
{
dialog.text = RandPhraseSimple("Listen, everyone keeps saying that you looted some city. Is this true?", "Listen. I keep hearing rumors that you're back to your old ways, and looted some city. Is this true?");
link.l1 = LinkRandPhrase("Oh, please, dear. That's slander!", "My dear, I have done nothing of the sort.", "No, my dear. That is definitely a lie. I did promise, didn't I?");
link.l1.go = "NewLife_KnowPirates";
IsabellaSetCurrentState("GrabbingTown");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_2");
break;
}
}
if (CheckAttribute(pchar, "RomanticQuest.Cheking.TakeTown") && pchar.RomanticQuest.Cheking != "Ok")
{
if (rand(sti(pchar.RomanticQuest.Cheking.TakeTown)*140) >= GetCharacterSkill(pchar, "Sneak"))
{
dialog.text = RandPhraseSimple("Listen, everyone keeps saying that you captured some city. Is this true?", "Listen. I keep hearing rumors that you're back to your old ways, and captured some city. Is this true?");
link.l1 = LinkRandPhrase("Oh, please, dear. That's slander!", "My dear, I have done nothing of the sort.", "No, my dear. That is definitely a lie. I did promise, didn't I?");
link.l1.go = "NewLife_KnowPirates";
IsabellaSetCurrentState("TakeTown");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_2");
break;
}
}
if (CheckAttribute(pchar, "RomanticQuest.Cheking.KillFort") && pchar.RomanticQuest.Cheking != "Ok")
{
if (rand(sti(pchar.RomanticQuest.Cheking.KillFort)*130) >= GetCharacterSkill(pchar, "Sneak"))
{
dialog.text = RandPhraseSimple("Listen, everyone keeps saying that you captured some fort. Is this true?", "Listen. I keep hearing rumors that you're back to your old ways, and captured some fort. Is this true?");
link.l1 = LinkRandPhrase("Oh, please, dear. That's slander!", "My dear, I have done nothing of the sort.", "No, my dear. That is definitely a lie. I did promise, didn't I?");
link.l1.go = "NewLife_KnowPirates";
IsabellaSetCurrentState("KillFort");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_2");
break;
}
}
if (CheckAttribute(pchar, "RomanticQuest.Cheking.AbordShip") && pchar.RomanticQuest.Cheking != "Ok")
{
if (rand(sti(pchar.RomanticQuest.Cheking.AbordShip)*70) >= GetCharacterSkill(pchar, "Sneak"))
{
dialog.text = RandPhraseSimple("Listen, everyone keeps saying that you boarded someone else's ships. Is this true?", "Listen. I keep hearing rumors that you're back to your old ways, and boarded someone else's ships. Is this true?");
link.l1 = LinkRandPhrase("Oh, please, dear. That's slander!", "My dear, I have done nothing of the sort.", "No, my dear. That is definitely a lie. I did promise, didn't I?");
link.l1.go = "NewLife_KnowPirates";
IsabellaSetCurrentState("AbordShip");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_2");
break;
}
}
if (CheckAttribute(pchar, "RomanticQuest.Cheking.KillShip") && pchar.RomanticQuest.Cheking != "Ok")
{
if (rand(sti(pchar.RomanticQuest.Cheking.KillShip)*50) >= GetCharacterSkill(pchar, "Sneak"))
{
dialog.text = RandPhraseSimple("Listen, everyone keeps saying that you sunk some ships. Is this true?", "Listen. I keep hearing rumors that you're back to your old ways, and sunk some ships. Is this true?");
link.l1 = LinkRandPhrase("Oh, please, dear. That's slander!", "My dear, I have done nothing of the sort.", "No, my dear. That is definitely a lie. I did promise, didn't I?");
link.l1.go = "NewLife_KnowPirates";
IsabellaSetCurrentState("KillShip");
LAi_CharacterPlaySound(npchar, "Gr_Isabella_2");
break;
}
}
dialog.text = LinkRandPhrase("Yes, dear. I'm listening...", "What does my dear husband want?", "Señor " + pchar.lastname + ", your dearest wife is rapt with attention...");
link.l1 = "Oh, I just wanted to talk... Missed you, and all...";
link.l1.go = "NewLife_JustTalk";
link.l2 = "Let's see what shape our family budget is in...";
link.l2.go = "NewLife_Budget";
link.l3 = "Dear, I've brought you a present.";
link.l3.go = "NewLife_Present";
link.l4 = "Listen, dear. About the family debts...";
link.l4.go = "NewLife_Sex";
link.l5 = "I want to sleep. Have no strength...";
link.l5.go = "NewLife_Sleep";
break;
case "NewLife_Budget":
iMoney = IsabellaCheckBudgetMoney();
if (iMoney > -(MOD_SKILL_ENEMY_RATE*10000))
{
if (iMoney == 0)
{
dialog.text = RandPhraseSimple("No debts, dear, but money has run out...", "It seems that there are no debts, and it's not like the bailiff is bursting at the door... But all the money's run out.");
}
else
{
dialog.text = "No debts for now, but money's running out. I still have " + FindRussianMoneyString(-iMoney) + ".";
link.l1 = RandPhraseSimple("Well. When the time comes, we'll decide...", "That's not my concern, right now. Spend what there is.");
link.l1.go = "NewLife";
}
link.l2 = RandPhraseSimple("Well, then. Let me throw you a piaster, rich girl!", "We need to immediately replenish the budget. Let's focus on that!");
link.l2.go = "NewLife_Budget_Add";
LAi_CharacterPlaySound(npchar, "Gr_Isabella_4");
}
else
{
dialog.text = RandPhraseSimple("No problems, dear. I've still got " + FindRussianMoneyString(-iMoney) + ". Surely that's enough?", "Everything is normal, dear. We have enough money. Last I looked, there was " + FindRussianMoneyString(-iMoney) + ".");
link.l1 = RandPhraseSimple("Well, then. That cheers a man up.", "Wonderful, dear. Very good!");
link.l1.go = "NewLife";
link.l2 = "I want to leave you more money, so that you won't be in need.";
link.l2.go = "NewLife_Budget_Add";
}
break;
case "NewLife_Budget_Add":
dialog.text = NPCStringReactionRepeat("Okay, dear. How much money do you want to leave me?", "But you've already left me something today... I don't... Never mind, how much do you intend?", "Are you playing a game? This is your third time today. Can't you just save up and pay me all at once? ", "That's it. You're driving me insane. I shan't be speaking with you any more! ", "repeat", 10, npchar, Dialog.CurrentNode);
if (sti(pchar.money) >= 50000 && npchar.quest.repeat.NewLife_Budget_Add.ans != "3")
{
link.l1 = HeroStringReactionRepeat("Fifty thousand.", "Hm... I want to leave fifty thousand.", "Hm... I want to leave you fifty thousand.", "...", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_Budget_50";
}
if (sti(pchar.money) >= 100000 && npchar.quest.repeat.NewLife_Budget_Add.ans != "3")
{
link.l2 = HeroStringReactionRepeat("A hundred thousand.", "A hundred thousand... ", "A hundred thousand... ", "...", npchar, Dialog.CurrentNode);
link.l2.go = "NewLife_Budget_100";
}
if (sti(pchar.money) >= 200000 && npchar.quest.repeat.NewLife_Budget_Add.ans != "3")
{
link.l3 = HeroStringReactionRepeat("Two hundred thousand.", "Two hundred thousand... ", "Two hundred thousand... ", "...", npchar, Dialog.CurrentNode);
link.l3.go = "NewLife_Budget_200";
}
if (sti(pchar.money) >= 500000 && npchar.quest.repeat.NewLife_Budget_Add.ans != "3")
{
link.l4 = HeroStringReactionRepeat("Five hundred thousand.", "Five hundred thousand... ", "Five hundred thousand... ", "...", npchar, Dialog.CurrentNode);
link.l4.go = "NewLife_Budget_500";
}
link.l5 = HeroStringReactionRepeat("Ha... So far nothing, Isabella. Money is tight.", "That's how it worked out, dear... Sorry, there's no money.", "It didn't happen on the first try, Isabella... There's no money.", "Isabella, why is it so? ", npchar, Dialog.CurrentNode);
link.l5.go = "NewLife_Budget_No";
break;
case "NewLife_Budget_50":
dialog.text = "Fine, " + pchar.name + " thank you.";
link.l1 = "It's my duty, Isabella...";
link.l1.go = "NewLife";
IsabellaAddMoneyBudget(50000);
break;
case "NewLife_Budget_100":
dialog.text = "All right, dear. Thank you. A hundred thousand, that's no small change.";
link.l1 = "Oh, my pleasure, sweetheart...";
link.l1.go = "NewLife";
IsabellaAddMoneyBudget(100000);
break;
case "NewLife_Budget_200":
dialog.text = "Very well, dear. Two hundred thousand is a fine addition to the family coffer.";
link.l1 = "I am glad that you are happy, Isabella...";
link.l1.go = "NewLife";
IsabellaAddMoneyBudget(200000);
break;
case "NewLife_Budget_500":
dialog.text = "So much! Where did you find so much money?";
link.l1 = "Why, I earned it. Where else?";
link.l1.go = "NewLife";
IsabellaAddMoneyBudget(500000);
break;
case "NewLife_Budget_No":
dialog.text = LinkRandPhrase("Then why give it to me? ", "What are you talking about? " , "What are you trying to say, dear?");
link.l1 = LinkRandPhrase("Nothing, dear. It's my mistake. I am sorry... ", "I am sorry, dear. My memory is playing tricks on me... ", "My head is all wound up... ");
link.l1.go = "NewLife";
break;
case "NewLife_Budget_Pay":
iMoney = IsabellaCheckBudgetMoney();
dialog.text = NPCStringReactionRepeat("True, Captain " + pchar.lastname + ", you have ignored this thing for way too long! So now, pay up! ",
"You were supposed to find money to pay off your debt! ",
"Captain, how many times do I must ask you to pay off our tax debt! ",
"Captain, I am sick and tired of repeating myself. I keep talking and talking, but our financial burden remains. Listen to me, you little man. I can handle the problems by myself! And you don't dare show your face to me again! ", "quest", 30, npchar, Dialog.CurrentNode);
if (sti(pchar.money) >= iMoney)
{
link.l1 = HeroStringReactionRepeat("All right, dear. I'm ready to pay off the debt.", "I found it, Isabella! I'm ready to cover our debts! ", "Isabella, dear, I remember quite well. I've found our money, and am ready to pay off our debts.", "Isabella, now... ", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_Budget_Pay_2";
link.l2 = "Of course you understand, Isabella, at the moment I'm flat broke...";
link.l2.go = "NewLife_Budget_Pay_1";
}
else
{
link.l1 = HeroStringReactionRepeat("Darling, dear, listen... At the moment, I have no " + FindRussianMoneyString(iMoney) + "...", "I had to find it, but I didn't... ", "Isabella, I have no money right now! ", "Is that so... ", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_Budget_Pay_1";
}
break;
case "NewLife_Budget_Pay_1":
dialog.text = RandPhraseSimple("So go find it! I have no intention to go to a debtor's prison because of you! ", "Listen to me, you little man! I don't want a bailiff to come by my home every other day, pestering me for payment! Come up with the money! You're the man of the house, aren't you? ");
link.l1 = RandPhraseSimple("Fine, Isabella. As you say... ", "I understand, Isabella. I'll do my best... ");
link.l1.go = "NewLife_exit";
break;
case "NewLife_Budget_Pay_2":
dialog.text = RandPhraseSimple("Well, splendid! I am so happy that my husband is a responsible man.", "Wonderful, dear! You are a true man... ");
link.l1 = RandPhraseSimple("Yeah, well... ", "Yeah, you bet! ");
link.l1.go = "NewLife";
iMoney = IsabellaCheckBudgetMoney();
AddMoneyToCharacter(pchar, -iMoney);
IsabellaNullBudget();
break;
case "NewLife_KnowPirates":
pchar.RomanticQuest.Cheking = "Ok";
if (rand(12) < GetCharacterSPECIAL(pchar, "Charisma"))
{
dialog.text = LinkRandPhrase("Hm... I believe you, " + pchar.name + "...", "Well, I'd rather believe you than some rumor! ", "I'd like to believe you, " + pchar.name + ", and not some idle speculation... ");
link.l1 = RandPhraseSimple("That's great, dear.", "How wonderful! We cleared that mess in no time flat! ");
link.l1.go = "NewLife";
}
else
{
dialog.text = NPCStringReactionRepeat("You know, dear, I am forced to listen to all this rumor and speculation. Yes as I can prove nothing, consider this your first warning.",
"Sorry, I don't believe you. There is to much talk around the city about that. Consider this your second warning.",
"Well, listen, I don't understand, do you think I am dumb? The whole city is talking, and he stands here, denying! It looks like you aren't keeping your own word. This is your last warning, " + pchar.name + ".",
"That's it, Captain " + pchar.lastname + ". There's no more trusting you. You've been cheating me! I don't want to talk to you any more! ", "quest", 80, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("Fine, dear. I consider this my first warning.",
"Fine, dear. I consider this warning number two.",
"Mmm... Sure thing, Isabella. Consider me totally warned. ",
"Oh, Isabella...", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife";
}
break;
case "NewLife_Sex":
if (GetQuestPastMonthParam("RomanticQuest") > 2 && GetNpcQuestPastDayParam(npchar, "sex") != 0)
{
dialog.text = "What's up, sailor? Been at sea too long?";
link.l1 = "Er... something like that...";
link.l1.go = "NewLife_Sex_1";
}
else
{
dialog.text = NPCStringReactionRepeat("What are you talking about?",
"Oh... I think I see what you mean... ",
"In debt? And what do you think I owe you?",
"Hmm, I don't understand... ", "cycle", 0, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("It's all about love, Isabella, love... ",
"Yes, dear, about love... ",
"I'm talking about the debt of love, dear... ",
"Isabella, dear, I'm talking about love... ", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_Sex_5";
}
break;
case "NewLife_Sex_1":
SaveCurrentNpcQuestDateParam(npchar, "sex");
dialog.text = "If I were you, dear, I wouldn't stay away so long.";
link.l1 = "Why is that?";
link.l1.go = "NewLife_Sex_2";
break;
case "NewLife_Sex_2":
dialog.text = "Because you have a beautiful wife, in case you haven't noticed. And because not only women live in San Juan, but also many interesting caballeros...";
link.l1 = "What the hell, Isabella... What are you on about?";
link.l1.go = "NewLife_Sex_3";
break;
case "NewLife_Sex_3":
dialog.text = "I'm just saying, you would do to spend more time at home, dear!";
link.l1 = "All right, Isabella, I understand... Let's not fight...";
link.l1.go = "NewLife_Sex_4";
break;
case "NewLife_Sex_4":
if (rand(6) < 5)
{
dialog.text = "Okay... I'm going to the bedroom...";
link.l1 = "And I'm coming right after you!";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = "Fine, dear, we won't fight. But today I have a headache, so nothing will happen. I am sorry...";
link.l1 = "Yergh... what timing.";
link.l1.go = "NewLife_exit";
}
break;
case "NewLife_Sex_Late":
dialog.text = "You know what, buster... You blew it. I'm not going to wait for you here forever, primed and ready for your return.";
link.l1 = "Well, Isabella? What about you?";
link.l1.go = "NewLife_Sex_Late_1";
break;
case "NewLife_Sex_Late_1":
chrDisableReloadToLocation = true;
bDisableFastReload = true;
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload1", "SanJuan_houseSp6", "goto", "goto1", "Romantic_TalkInChurch_end", 3.5);
NextDiag.TempNode = "NewLife";
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "NewLife_Sex_5":
if (GetNpcQuestPastDayParam(npchar, "sex") > 3)
{
dialog.text = NPCStringReactionRepeat("Mm... I like such conversations... ",
"About love? All right then. Go on, dear... ",
"Love sounds interesting... So what about it?",
"Ah, love... I have been known to dally, from time to time! ", "block", 60, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("Isabella, I am burning with passion! ",
"Isabella, I am burning with desire to share my bed with you! ",
"Isabella, the desire to have you is stronger than me.",
"Isabella, what kind of nonsense is this?! Let's go to the bedroom quickly, dear... ", npchar, Dialog.CurrentNode);
link.l1.go = DialogGoNodeRepeat("NewLife_Sex_10", "NewLife_Sex_11", "NewLife_Sex_12", "NewLife_Sex_13", npchar, Dialog.CurrentNode);
}
else
{
dialog.text = LinkRandPhrase("Love shouldn't be the subject of frequent conversation, dear. I'm sorry, but nothing will come out of this... ", "No, dear, frequent conversation about love bring harm to the soul and body. Or so the padre says... ", "Oh dear, I don't want to discuss this topic too much. Let's not tire me, hmm? In a few days, dear... ");
link.l1 = RandPhraseSimple("Hrm... Hmm... A pity... ", "Well, that blows my evening.");
link.l1.go = "NewLife_exit";
}
SaveCurrentNpcQuestDateParam(npchar, "sex");
break;
case "NewLife_Sex_10":
dialog.text = "Then I'll wait for you in the bedroom, dear!";
link.l1 = "Isabella, I'm following you...";
link.l1.go = "NewLife_GoSex";
break;
case "NewLife_Sex_11":
if (rand(10) < 8)
{
dialog.text = "To share my bed? Well, fine. I'm going to the bedroom...";
link.l1 = "Oh, Isabella...";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("I have a headache, dear. Not today... ", "Oh, dear. I'm not feeling very well. Not today... ", "Dear, I feel ill... let's postpone this, shall we? Later, perhaps... ");
link.l1 = RandPhraseSimple("Urgh... Just at the wrong moment... ", "The devil! Oh... Oh forgive me, Isabella. It just shot out... ");
link.l1.go = "NewLife_exit";
}
break;
case "NewLife_Sex_12":
if (rand(10) < 5)
{
dialog.text = "Desire... Mmm, fine. I'll wait for you in the bedroom, dear...";
link.l1 = "In a moment, Isabella!";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("I have a headache, dear. Not today... ", "Oh, dear. I'm not feeling very well. Not today... ", "Dear, I feel ill... let's postpone this, shall we? Later, perhaps... ");
link.l1 = RandPhraseSimple("Urgh... Just at the wrong moment... ", "The devil! Oh... Forgive me, Isabella. It just came out... ");
link.l1.go = "NewLife_exit";
}
break;
case "NewLife_Sex_13":
if (rand(10) < 2)
{
dialog.text = "Dear, you are such a brute! Fine, you've convinced me...";
link.l1 = "Isabella...";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = "That's it, we're not going anywhere. And in the future, I'll thank you to stem the tide of such vulgar ejaculations!";
link.l1 = "I... heh... Ahem. I'm sorry, Isabella...";
link.l1.go = "NewLife_exit";
}
break;
case "NewLife_GoSex":
chrDisableReloadToLocation = true;
bDisableFastReload = true;
NextDiag.TempNode = "NewLife";
NextDiag.CurrentNode = NextDiag.TempNode;
SaveCurrentNpcQuestDateParam(npchar, "sex");
Pchar.quest.Romantic_Sex.win_condition.l1 = "location";
Pchar.quest.Romantic_Sex.win_condition.l1.location = "SanJuan_houseS1Bedroom";
Pchar.quest.Romantic_Sex.win_condition = "Romantic_Sex";
SetTimerCondition("Romantic_IsabellaBackToHall", 0, 0, 1, false);
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload2", "SanJuan_houseS1Bedroom", "goto", "goto6", "Romantic_TalkInChurch_end", 20.0);
DialogExit();
break;
case "NewLife_afterSex":
dialog.text = NPCStringReactionRepeat("Mmm... dear, that was... wonderful! ",
"So, how are you, sweetheart? Feel good?",
"You seem out of shape today... ",
"Oh... Love, it is grand... ", "block", 30, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("Thank you, darling... ",
"Wonderful, darling. You were simply amazing! ",
"Hmm... Forgive me, darling. It just didn't happen... ",
"I fully agree with you, darling.", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_afterSex_1";
break;
case "NewLife_afterSex_1":
chrDisableReloadToLocation = true;
bDisableFastReload = true;
NextDiag.TempNode = "NewLife";
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_SetActorType(npchar);
LAi_ActorGoToLocation(npchar, "reload", "reload1", "SanJuan_houseSp6", "goto", "goto2", "Romantic_TalkInChurch_end", 20.0);
Pchar.quest.Romantic_IsabellaBackToHall.over = "yes";
DialogExit();
break;
case "NewLife_Sleep":
dialog.text = "When would you like me to wake you up, dear?";
if(!isDay())
{
link.l1 = "In the morning, if you can...";
link.l1.go = "NewLife_Sleep_day";
}
else
{
link.l1 = "I'll have to get up at night, Isabella.";
link.l1.go = "NewLife_Sleep_night";
link.l2 = "I want to get a good sleep. Wake me up tomorrow morning.";
link.l2.go = "NewLife_Sleep_day";
}
break;
case "NewLife_Sleep_day":
dialog.text = "All right, I'll wake you up tomorrow.";
link.l1 = "Great. Then I'm going to the bedroom...";
link.l1.go = "room_day_wait";
link.l2 = "You know, I've changed my mind. I'm going to stay awake for a while.";
link.l2.go = "NewLife_exit";
break;
case "NewLife_Sleep_night":
dialog.text = "All right, I'll wake you up after midnight.";
link.l1 = "Great, my dear. Then I'm going to the bedroom...";
link.l1.go = "room_night_wait";
link.l2 = "You know, I changed my mind. I'd better spend this time on my feet.";
link.l2.go = "NewLife_exit";
break;
case "room_day_wait":
DialogExit();
NextDiag.TempNode = "NewLife_hello";
NextDiag.CurrentNode = NextDiag.TempNode;
TavernWaitDate("wait_day");
AddDialogExitQuest("sleep_in_home");
break;
case "room_night_wait":
DialogExit();
NextDiag.TempNode = "NewLife_hello";
NextDiag.CurrentNode = NextDiag.TempNode;
TavernWaitDate("wait_night");
AddDialogExitQuest("sleep_in_home");
break;
case "NewLife_JustTalk":
if (CheckAttribute(pchar, "RomanticQuest.Atilla"))
{
switch (pchar.RomanticQuest.Atilla)
{
case "YouAreBaster":
dialog.text = "Listen, I heard you treated your friend Attila badly. People say you gave him very little money; I know he did so much for us... I am simply shocked!";
link.l1 = "Dear, it's all in the past. We mustn't dwell...";
link.l1.go = "NewLife_exit";
break;
case "YouAreNormal":
dialog.text = "Dear, I heard you thanked your friend Attila. This is a noble act, and I'm happy my husband is a real man; a man of dignity!";
link.l1 = "Isabella, how could it be otherwise?";
link.l1.go = "NewLife_exit";
break;
case "YouAreGood":
dialog.text = "Dear, you never mentioned, but I've learned that you gave your friend Attila a very large amount of money. I suppose this is in gratitude for all that he did for us. Dear, you've given me yet more proof that you are the best man in the world!";
link.l1 = "Isabella, What're you talking about? It's not a big deal, really. All I did was pay off a debt...";
link.l1.go = "NewLife_exit";
break;
}
DeleteAttribute(pchar, "RomanticQuest.Atilla");
break;
}
switch (rand(1))
{
case 0:
dialog.text = LinkRandPhrase("Oh, dear, I am so flattered to have your attention... ", pchar.name + ", you're a true knight... ", "Oh God, I'm so fortunate you've sent me such a man as " + GetMainCharacterNameGen() + "...");
link.l1 = RandPhraseSimple("Yes, dear. You're pretty swell yourself. ", "You know, Isabella, I often think how wonderful it is that we chose to entangle our fates... ");
link.l1.go = "NewLife_exit";
break;
case 1:
dialog.text = LinkRandPhrase("Dear, did you know that the Governor was asking up about us?", "The Governor asked me recently how things are with you, dear.", "Yesterday I met the Governor in the street, and we talked. He was asking how things are with you.");
link.l1 = RandPhraseSimple("Ah, yes. Next time you see him, you can tell him I'm fine.", "The Governor seems to be paying a lot of attention to you...");
link.l1.go = "NewLife_exit";
break;
}
break;
case "NewLife_Present":
dialog.text = RandPhraseSimple("And what do you want to give me, dear?", "Come on, what's my present? Oh, I can't bear the suspense! ");
iTemp = 1;
for (i=18; i>=1; i--)
{
if (i==8 || i==9) continue;
if (CheckCharacterItem(pchar, "jewelry"+i))
{
sTemp = "l"+iTemp;
link.(sTemp) = XI_ConvertString("jewelry"+i+"Gen") + ".";
link.(sTemp).go = "NewLife_jewelry_"+i;
iTemp++;
}
}
if (iTemp == 1)
{
dialog.text = NPCStringReactionRepeat("And what do you want to give me, dear?",
"Oh, another present? Hmm... What is it?",
pchar.name + ", what is this? Why are you taunting me with these presents? What is it this time?",
"You moron! That's it, I'm sick and tired of you! Don't you talk to me anymore! ", "repeat", 20, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("Nothing of the sort... ",
"I'm sorry. I've nothing worthy of my wonderful wife's attention... Save myself, perhaps.",
"Isabella, forgive me. Again I failed to find anything suitable for you...",
"Isabella, I'm sorry! ", npchar, Dialog.CurrentNode);
link.l1.go = "NewLife_exit";
}
break;
case "NewLife_jewelry_1":
dialog.text = LinkRandPhrase("Thank you, darling. You're too kind. I do so like sapphires...", "Whee, see how it sparkles in the sun! Oh, thank you, my dearest... " , "What an amazing gem! Thank you, my dear... ");
link.l1 = LinkRandPhrase("Not at all, darling... ", "I want you to be the most beautiful woman on the world! ", "It's all for you, sweetheart... ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry1");
break;
case "NewLife_jewelry_2":
if (rand(4)==1)
{
dialog.text = "Oh, a diamond... I'm going to lose my mind! Sweetheart, let's go upstairs!";
link.l1 = "With pleasure, sweetheart.";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear. You're too good to me. I've always been fond of diamonds...", "Whee, see how it sparkles in the sun! Oh, thank you, my dearest... " , "What an amazing gem! Thank you, my dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on the world! ", "It's all for you, sweetheart... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry2");
break;
case "NewLife_jewelry_3":
if (rand(10)==1)
{
dialog.text = "Oh, a ruby! I do so love their color... like blood! Dear, you made very happy. Let's go upstairs, you and I...";
link.l1 = "That's just what I was thinking, missus me...";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear, you're very kind. I have always been fond of rubies.", "Whee, see how it sparkles in the sun! Oh, thank you, my dearest... " , "What an amazing gem! Thank you, my dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on the world! ", "It's all for you, sweetheart... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry3");
break;
case "NewLife_jewelry_4":
if (rand(3)==1)
{
dialog.text = "An emerald! Oh, this is my favorite stone... You're spoiling me, sweetheart... How about we go upstairs and I spoil you about, hmm?";
link.l1 = "Darling, you can destroy me if you like!";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear, you're very kind. I have always been fond of emeralds.", "Whee, see how it sparkles in the sun! Oh, thank you, my dearest... " , "What an amazing gem! Thank you, my dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on the world! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry4");
break;
case "NewLife_jewelry_5":
dialog.text = LinkRandPhrase("Mm, gold! A very good present. Thank you, dear.", "Whee, look at the size of this nugget! Thank you, dear." , "What a wonderful nugget! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the richest lass in the Caribbean! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry5");
break;
case "NewLife_jewelry_6":
dialog.text = LinkRandPhrase("Thank you, dear, you're so kind. Sapphires look so well on me...", "Oh, how great this sapphire looks in a silver setting! Thank you, sweetheart... " , "What an extraordinary ring! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry6");
break;
case "NewLife_jewelry_7":
if (rand(2)==1)
{
dialog.text = "Oh, a ring - with my favorite emerald! You're spoiling me, sweetheart... Hey, my big old rogue, how'd you like to take your woman upstairs?";
link.l1 = "Why, you saucy little wench!";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear. You're too kind. Emerald rings do so become me! ", "Oh, see how the sun glints off its gold setting! Thank you, sweetheart... " , "An amazing stone, in a noble setting! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry7");
break;
case "NewLife_jewelry_10":
dialog.text = LinkRandPhrase("Thank you, dear, you're so kind. Sapphires look so well on me...", "Oh, how well this sapphire looks in a gold setting! Thank you, sweetheart... " , "What an extraordinary ring! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry10");
break;
case "NewLife_jewelry_11":
dialog.text = LinkRandPhrase("Thank you, dear. You are too good to me. Such a huge pearl it is! ", "Oh, a pearl... I see that business is booming on the Coast. Thank you, dear." , "What a magnificent pearl! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry11");
break;
case "NewLife_jewelry_12":
dialog.text = LinkRandPhrase("Thank you, dear. You're too kind... ", "Oh, a pearl... I see that business is booming on the Coast. Thank you, dear." , "What a magnificent pearl! Thank you, dear... ");
link.l1 = RandPhraseSimple("Ha...", "Hm...");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry12");
break;
case "NewLife_jewelry_13":
dialog.text = LinkRandPhrase("Oh... What a precious little thing, this cameo... Thank you, dear.", "What a precious little thing, dear. Thank you... " , "A fine piece of jewelry! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry13");
break;
case "NewLife_jewelry_14":
if (rand(1)==1)
{
dialog.text = "Oh my. Oh dear, this brooch is worthy of a queen! I insist we go upstairs and try it out!";
link.l1 = "No argument here, your highness...";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear. You are too kind. This gold brooch is quite beautiful... ", "Oh, how it sparkles in the light! Thank you, dear... " , "Magnificent stones, in a fine setting! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry14");
break;
case "NewLife_jewelry_15":
if (rand(1)==1)
{
dialog.text = "Oh dear, this pendant... I am just crazy about you. I insist we go upstairs right this moment...";
link.l1 = "Why? What's up there? Oh... Oh, you sacy lady you!";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear. You are very kind. These pendants look just fine on me... ", "Oh, how these emeralds sparkle in the light! Thank you, sweetheart... " , "Magnificent stones, in a fine setting! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry15");
break;
case "NewLife_jewelry_16":
dialog.text = LinkRandPhrase("Er... That's all right, dear. You can keep it...", "Hrm. You seriously think I'd wear that? " , "Oh Lord, dear! What taste! You must have been raised in a barn if you think I'd ever wear that for you! ");
link.l1 = RandPhraseSimple("Oh? Oh... well... okay then... ", "Whoops...");
link.l1.go = "NewLife_exit";
break;
case "NewLife_jewelry_17":
dialog.text = LinkRandPhrase("Ah, silver! Well, fine. I'll take it. It may come in handy...", "Silver! Fine, give it here... " , "A silver nugget? Why would... well, hmm... Silver is quite valuable, in big enough quantities. Fine, I'll take it... ");
link.l1 = RandPhraseSimple("Not at all, darling...", "I want you to be the richest lady in the Caribbean! ");
link.l1.go = "NewLife_exit";
TakeItemFromCharacter(pchar, "jewelry17");
break;
case "NewLife_jewelry_18":
if (rand(8)==1)
{
dialog.text = "Emeralds and rubies - my two favorite stones! This ringlet is simply superb! You are spoiling me, dear... Hey, since you're here, let's you and I head upstairs...";
link.l1 = "Well, if you insist...";
link.l1.go = "NewLife_GoSex";
}
else
{
dialog.text = LinkRandPhrase("Thank you, dear. You are too kind. This ring is very pretty, with the ruby and all... ", "Oh, the gold setting does suit that ruby... Thank you, dear." , "Magnificent stones, in a fine setting! Thank you, dear... ");
link.l1 = LinkRandPhrase("Not at all, darling...", "I want you to be the most beautiful woman on Earth! ", "It's all for you, my dearest... ");
link.l1.go = "NewLife_exit";
}
TakeItemFromCharacter(pchar, "jewelry18");
break;
case "NewLife_exit":
NextDiag.TempNode = "NewLife";
NextDiag.CurrentNode = NextDiag.TempNode;
LAi_SetActorType(npchar);
LAi_ActorGoToLocator(npchar, "goto", "goto"+(rand(3)+1), "Romantic_TalkInChurch_end", -1);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "AngryRepeat_Budget_Add":
dialog.text = RandPhraseSimple("I have no desire to talk with such a bore! As if silk and gold ringlets and sapphire settings will melt my heart... ", "I don't wish to talk. I am mad at you, you cheap bore! I want silver and gold and sapphire rings... ");
link.l1 = "Oh, Isabella...";
link.l1.go = "AngryExitAgain";
if (CheckAttribute(npchar, "angry.terms"))
{
if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
{
dialog.text = "Oh, fine, my sweet husband. I can't stay mad at you. Just let's not be so cheap, hmm? And also, let's not spend money we don't have, all right?";
link.l1 = "All right, Isabella. I'll do my best...";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
}
else
{
if (CheckCharacterItem(pchar, "jewelry6") && CheckCharacterItem(pchar, "jewelry10"))
{
dialog.text = "Oh, this is just what I wanted - a gold and silver ring, with sapphires! Hmm... You do know how to please me... Well, all right. We are on speaking terms again...";
link.l1 = "Well, that's a mercy!";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
TakeItemFromCharacter(pchar, "jewelry6");
TakeItemFromCharacter(pchar, "jewelry10");
}
}
}
break;
case "AngryRepeat_Budget_Pay":
dialog.text = RandPhraseSimple("Listen, my little man, you are incapable of supporting your wife. I had to deal with our financial problems myself. That just won't do! ", "If you think about it, I have to deal with all our family problems myself! I am amazed with your inability to support your family! ");
link.l1 = "Signora Isabella, it's beyond my control...";
link.l1.go = "AngryExitAgain";
if (CheckAttribute(npchar, "angry.terms"))
{
if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
{
dialog.text = "All right, I'll forgive you this time - but make sure you repay the debt in full! And watch out for that interest!";
link.l1 = "Fine, Isabella. Whatever you say, Isabella.";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
}
else
{
if (CheckCharacterItem(pchar, "jewelry4") && CheckCharacterItem(pchar, "jewelry7") && CheckCharacterItem(pchar, "jewelry15"))
{
dialog.text = "You bastard, you know how much I like emeralds! Well... well, all right... I forgive you, but... But you make sure you repay the debt in full! And watch out for that interest!";
link.l1 = "All right, Isabella. All right...";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
TakeItemFromCharacter(pchar, "jewelry4");
TakeItemFromCharacter(pchar, "jewelry7");
TakeItemFromCharacter(pchar, "jewelry15");
}
}
}
break;
case "AngryRepeat_KnowPirates":
dialog.text = RandPhraseSimple("You broke your promise to me before the wedding! I have no more desire to see you...", "You promised you'd be done privateering and yet you didn't even think to stop spilling innocent blood!");
link.l1 = "Now, Isabella. It's not like I meant for this to happen...";
link.l1.go = "AngryExitAgain";
if (CheckAttribute(npchar, "angry.terms"))
{
if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
{
dialog.text = "Look, my husband... if I forgive you, you must agree to hold to your promise!";
link.l1 = "All right, Isabella. I'll do whatever you want me to. No more buccaneering, dear...";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
IsabellaSetCurrentState("All");
}
else
{
if (CheckCharacterItem(pchar, "jewelry1") && CheckCharacterItem(pchar, "jewelry2") && CheckCharacterItem(pchar, "jewelry3") && CheckCharacterItem(pchar, "jewelry18") && CheckCharacterItem(pchar, "jewelry11"))
{
dialog.text = "Oh, " + pchar.name + ", you do know how to placate me... But remember your promise! I'm going to hold you to it! No more piracy!";
link.l1 = "Oh, Isabella. Think no more of it. I can't live without you...";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
TakeItemFromCharacter(pchar, "jewelry1");
TakeItemFromCharacter(pchar, "jewelry2");
TakeItemFromCharacter(pchar, "jewelry3");
TakeItemFromCharacter(pchar, "jewelry18");
TakeItemFromCharacter(pchar, "jewelry11");
IsabellaSetCurrentState("All");
}
}
}
break;
case "AngryRepeat_Present":
dialog.text = RandPhraseSimple("No, it's simply impossible to live with such a man! And why must you so liberally shower me with these phantom gifts? For you, there are no words...", "You dolt! You insufferable moron! I don't want to talk with such a... such a brute! Thanks for all those empty boxes, dear. Empty boxes and empty promises! ");
link.l1 = RandPhraseSimple("Come on, Isabella. Be fair, won't you...", "Why are you angry? It wasn't deliberate...");
link.l1.go = "AngryExitAgain";
if (CheckAttribute(npchar, "angry.terms"))
{
if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
{
dialog.text = "Okay... all right, I forgive you. But stop making me promises you can't keep, you idiot!";
link.l1 = "Okay, my bunny. I'll be more careful...";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
}
else
{
if (CheckCharacterItem(pchar, "jewelry5") && CheckCharacterItem(pchar, "jewelry17"))
{
if (sti(pchar.items.jewelry5) >= 3 && sti(pchar.items.jewelry17) >=5)
{
dialog.text = "It's... it's incredible! And so you bring me the one thing I actually want right now - ingots, of gold and silver! Well... well, okay. We are on speaking terms again. But stop being so callous with your promises, won't you! There's only so much disappointment the heart can take!";
link.l1 = "Yes, Isabella. Whatever you say, Isabella...";
link.l1.go = NextDiag.TempNode;
CharacterDelAngry(npchar);
TakeNItems(pchar, "jewelry5", -3);
TakeNItems(pchar, "jewelry17", -5);
}
}
}
}
break;
case "AngryExitAgain":
DialogExit();
DeleteAttribute(npchar, "angry.ok");
break;
}
}