void ProcessDialogEvent()
{
ref NPChar, sld;
aref Link, NextDiag;
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
case "First time":
dialog.text = "Well, well, old timer! So how are you my good friend? It is good to see you, " + GetFullName(PChar) + "!";
link.l1 = "Attila! How are you, you old sea devil!";
link.l1.go = "port_1";
NextDiag.TempNode = "First time";
DeleteAttribute(npchar, "talker");
break;
case "port_1":
sld = characterFromID("Atilla");
dialog.text = "Look at you, dressed up all funny like a dandy! I bet the wind's not whistling in your pockets! Won't you offer a drink to an old pal?";
if (pchar.RomanticQuest == "")
{
link.l1 = "I'm damn happy to see you, but I can't now, buddy. Another time...";
link.l1.go = "Exit";
}
else
{
link.l1 = "Haw haw hah! It wouldn't be a sin to knock back a mug of good Jamaican rum, for a meeting like this!";
link.l1.go = "port_1_1";
}
break;
case "port_1_1":
dialog.text = "Pop my gut, we've got to have a drink for this meeting! Straight to the tavern...";
link.l1 = "Agreed! To the tavern!";
link.l1.go = "port_toTavern";
break;
case "port_toTavern":
DialogExit();
NextDiag.CurrentNode = "Tavern_1";
chrDisableReloadToLocation = true;
bDisableFastReload = true;
FreeSitLocator("Pirates_tavern", "sit3");
LAi_SetActorType(npchar);
LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "Pirates_tavern", "sit", "sit3", "Romantic_Pirat_toTavern", -1);
break;
case "Tavern_1":
LAi_SetSitType(Pchar);
dialog.text = "Dammit, "+GetFullName(PChar)+"! We pulled a glorious deal in Caracas, didn't we! Blow me down!";
link.l1 = "Yeah... You sent quite a few Catalonian devils to their forefathers in that battle. For such inspired butchery, they gave you the nickname - Attila... Since then, I see, luck hasn't often smiled upon you.";
link.l1.go = "Tavern_2";
break;
case "Tavern_2":
dialog.text = "Argh! I tell you, never trust those Catalonian dons! I was with one of them. We took some French tub. There was a jeweler among the passengers. I didn't care about his papers - some documents -- but I know something about trinkets. Holy Mother, they were enough to buy half of Hispaniola and a governor's house - with the governor himself in tow! We divided everything honestly, then we found five kegs of rum in the hold. So of course, we drank ourselves silly from happiness...";
link.l1 = "Heh, as always...";
link.l1.go = "Tavern_3";
break;
case "Tavern_3":
dialog.text = "So it was. And the morning after, it turns out our pal wasn't an honest decent scoundrel. Got his stuff together, grabbed all the trinkets, and was off.";
link.l1 = "And you let that go? May a shark swallow me! I'd have...";
link.l1.go = "Tavern_4";
break;
case "Tavern_4":
dialog.text = "What would you have done, greenhorn?! He ran off to a Spanish island. And my path isn't open, there. To hell with him. He could've slit my throat, me dead drunk and all, and nobody would've said a word.";
link.l1 = "Hm. You've become a tad too melancholy, buddy.";
link.l1.go = "Tavern_5";
break;
case "Tavern_5":
dialog.text = "Time goes on, and I'm getting older. It's not that easy to send a person to the next world... And Salvatore, they say, had a sweet wedding on my money. He lives in San Juan now...";
link.l1 = "Damn me to hell! Attila, my friend, maybe I should pay a visit to this quiet family nest? Maybe you'll find your trinkets in the wife's jewelry box, eh?";
link.l1.go = "Tavern_6";
break;
case "Tavern_6":
dialog.text = "Har! Methinks you wouldn't be climbing into her bedroom for some trinkets! Oh no, buddy. I let the prize slip out of my hands once. It was meant to be... Live and let live. If God sees to it, we'll meet again.";
link.l1 = "Farewell, Attila.";
link.l1.go = "Tavern_Out";
break;
case "Tavern_Out":
NextDiag.CurrentNode = "Tavern_Bye";
DialogExit();
AddDialogExitQuest("Romantic_Pirat_toTavern_end");
break;
case "Tavern_Bye":
NextDiag.TempNode = "Tavern_Bye";
dialog.text = "I'll finish my drink, and head to the ship...";
link.l1 = "I won't get in the way.";
link.l1.go = "exit";
break;
case "TalkingNews":
dialog.text = "Oh, who am I seeing? " + GetFullName(pchar) + ", in the flesh!";
link.l1 = "Hey, Attila! Things are looking up, I see! You bought a house...";
link.l1.go = "TalkingNews_1";
break;
case "TalkingNews_1":
dialog.text = "Some dough's come in, so I wanted to invest in real estate. Though to be honest, a house here is a far cry from a house on Tortuga...";
link.l1 = "Well, it's still a roof.";
link.l1.go = "TalkingNews_2";
break;
case "TalkingNews_2":
dialog.text = "Hm. Right you are! But tell me, why have you come here?";
link.l1 = "Well, there's this matter. It's a long story... Anyhow, I paid a visit to your buddy Salvatore Olevarez.";
link.l1.go = "TalkingNews_3";
break;
case "TalkingNews_3":
dialog.text = "Har, that's news! How's the old fox living? Is it true he's married?";
link.l1 = "Yeah, it's true. His wife, Isabella, is a very beautiful woman... And honest, to boot.";
link.l1.go = "TalkingNews_4";
break;
case "TalkingNews_4":
dialog.text = "Heh, how do you figure? Women are crafty people. Behind outside beauty, there can hide a big evil.";
link.l1 = "Evil that's Salvatore! I didn't tell you about what happened, so listen.";
link.l1.go = "TalkingNews_5";
break;
case "TalkingNews_5":
dialog.text = "With pleasure.";
link.l1 = "Anyhow, I showed up in San Juan after our talk, and started putting the pieces together. A lot of things happened there, but in the end it turned out that Salvatore robbed his wife and killed her brother - right in front of my eyes!";
link.l1.go = "TalkingNews_6";
break;
case "TalkingNews_6":
dialog.text = "Yeah, he's been going a bit too far, the villain...";
link.l1 = "He framed me, and they tried to arrest me... By the time I was able to sort out the situation, Salvatore had vanished. And Isabella locked herself inside her house, not letting anyone in...";
link.l1.go = "TalkingNews_7";
break;
case "TalkingNews_7":
dialog.text = "Well, friend... Thanks for trying to bring about justice. What do you plan to do next?";
link.l1 = "I'm thinking about finding Salvatore and gutting him. And I need to resolve things with Isabella... She still thinks I killed her brother.";
link.l1.go = "TalkingNews_8";
break;
case "TalkingNews_8":
dialog.text = "Uh, pal. Not to butt in, but does it make a difference to you?";
link.l1 = "No, Attila. Not anymore...";
link.l1.go = "TalkingNews_9";
break;
case "TalkingNews_9":
dialog.text = "L'amour... Qu'ici faire?..";
link.l1 = "What?";
link.l1.go = "TalkingNews_10";
break;
case "TalkingNews_10":
dialog.text = "It's French... Everything's in order.. And where do you intend to look?";
link.l1 = "I don't know, I can't wrap my head around it.";
link.l1.go = "TalkingNews_11";
break;
case "TalkingNews_11":
dialog.text = "Listen, you've smoked Salvatore out of San Juan - and that's very good! Now I can join in the search.";
link.l1 = "And you'll be able to find him?";
link.l1.go = "TalkingNews_12";
break;
case "TalkingNews_12":
dialog.text = "I think so. You're not the only one who respects Attila. This pirate still has a few friends...";
link.l1 = "Well, then. That would be great. And what should I do?";
link.l1.go = "TalkingNews_13";
break;
case "TalkingNews_13":
dialog.text = "Focus on your business, for now. And I'll focus on my search. You try to help, you'll just get in the way. Let's meet again here in two months, at my house. Then I'll tell you what I'd discovered.";
link.l1 = "Fine, Attila. Well, good luck to you.";
link.l1.go = "TalkingNews_14";
break;
case "TalkingNews_14":
SetTimerCondition("Romantic_AtillaToHouse", 0, 2, 0, false);
AddQuestRecord("Romantic_Line", "11");
LAi_SetActorType(npchar);
ChangeCharacterAddressGroup(npchar, pchar.location, "goto", "goto2");
LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
LocatorReloadEnterDisable("SanJuan_houseSp6", "reload2", false);
LocatorReloadEnterDisable("Pirates_town", "houseF1", true);
ChangeCharacterAddress(characterFromId("Isabella"), "none", "");
Pchar.quest.Romantic_AmbushInHouse.win_condition.l1 = "location";
Pchar.quest.Romantic_AmbushInHouse.win_condition.l1.location = "SanJuan_houseSp6";
Pchar.quest.Romantic_AmbushInHouse.win_condition = "Romantic_AmbushInHouse";
DialogExit();
break;
case "AtillaInHouse":
dialog.text = "And here you are, " + GetFullName(pchar) + ". Go on, happy to see you.";
link.l1 = "Attila, how are things going? Did you find anything new about our good friend?";
link.l1.go = "AtillaInHouse_1";
break;
case "AtillaInHouse_1":
dialog.text = "Of course I did, " + pchar.name + "! What did you expect?! In general, you've really stirred Salvatore up... He never sits still, he's always moving.";
link.l1 = "So how are we going to catch him, then?";
link.l1.go = "AtillaInHouse_2";
break;
case "AtillaInHouse_2":
dialog.text = "We need to think about it...";
link.l1 = "Listen, did you find out anything out about Isabella?";
link.l1.go = "AtillaInHouse_3";
break;
case "AtillaInHouse_3":
dialog.text = "I did, pal. It looks like Salvatore has lured her out of San Juan. He sent the pirate brig Rapturous to pick her up. Then, rumor has it, he plotted a course for Portobelo.";
link.l1 = "And what does he need her for? He defrauded her...";
link.l1.go = "AtillaInHouse_4";
break;
case "AtillaInHouse_4":
dialog.text = "Probably to put all the loose ends in the water, buddy. She won't live, your Isabella, if she falls into Salvatore's hands.";
link.l1 = "Argh. When did the brig leave San Juan? I must intercept it in time!";
link.l1.go = "AtillaInHouse_5";
break;
case "AtillaInHouse_5":
dialog.text = "If you want to see Isabella alive, then yes. The brig left San Juan about three days ago. By my calculations, it'll be at Portobelo in fifteen to sixteen days. No more than that.";
link.l1 = "That means that I must hurry... Thank you, Attila!";
link.l1.go = "AtillaInHouse_6";
break;
case "AtillaInHouse_6":
dialog.text = "Buddy, don't forget a very, very small detail... Somewhere in Porto Belle, Salvatore himself is located. He's waiting for Isabella there.";
link.l1 = "Ha! That's right... Attila, I must rush. If everything goes well, then I'll return the jewels you lost.";
link.l1.go = "AtillaInHouse_7";
break;
case "AtillaInHouse_7":
dialog.text = "Good, " + pchar.name + ". Good luck!";
link.l1 = "Thank you, Attila.";
link.l1.go = "exit";
NextDiag.TempNode = "AtillaInHouse_Again";
AddQuestRecord("Romantic_Line", "13");
pchar.RomanticQuest = "AttackBrig";
Pchar.quest.Romantic_AttackBrig.win_condition.l1 = "location";
Pchar.quest.Romantic_AttackBrig.win_condition.l1.location = "PortoBello";
Pchar.quest.Romantic_AttackBrig.win_condition = "Romantic_AttackBrig";
SetTimerCondition("Romantic_BrigTimeOver", 0, 0, 16, false);
break;
case "AtillaInHouse_Again":
dialog.text = "Well, how are things?";
link.l1 = "Nothing yet...";
link.l1.go = "exit";
break;
case "Brig_Late":
dialog.text = "Well, tell me. How are things?";
link.l1 = "None too good... I didn't catch that brig. Didn't even catch a glimpse of its stern...";
link.l1.go = "Brig_Late_1";
break;
case "Brig_Late_1":
dialog.text = "I see. Then it would seem Isabella is already dead...";
link.l1 = "My heart breaks to think of it... But you are probably right.";
link.l1.go = "Brig_Late_2";
break;
case "Brig_Late_2":
dialog.text = "Why torture yourself? Tears won't help anyone. So this adventure is over for you. But life goes on.";
link.l1 = "You're right, Attila. Thank you for your support. Goodbye...";
link.l1.go = "exit";
NextDiag.TempNode = "Last_Talk";
CloseQuestHeader("Romantic_Line");
DeleteAttribute(pchar, "RomanticQuest");
break;
case "Last_Talk":
dialog.text = "I will go to sea soon. must earn a living somehow...";
link.l1 = "Best of luck to you, Attila.";
link.l1.go = "exit";
NextDiag.TempNode = "Last_Talk";
break;
case "Brig_DieHard":
dialog.text = "Well, friend, what's news?";
link.l1 = "Noting good. I caught up with the brig at Puerto Bello, but was unable to take it...";
link.l1.go = "Brig_DieHard_1";
break;
case "Brig_DieHard_1":
dialog.text = "Yes, that is bad... Isabella is probably dead by now...";
link.l1 = "God, so it would seem... Oh, my heart... I can't think of it without... without...";
link.l1.go = "Brig_Late_2";
break;
case "Brig_Sunk":
dialog.text = "Well, tell me. How are things?";
link.l1 = "Not too well... I caught up the brig at Puerto Bello, but failed to board it. During the battle, well... she sank. With all hands on board...";
link.l1.go = "Brig_Sunk_1";
break;
case "Brig_Sunk_1":
dialog.text = "My friend, that is terrible! I envy no man who loses a woman he likes... but like that!";
link.l1 = "I can't speak of it... My heart begins to crumble, and I...";
link.l1.go = "Brig_Late_2";
break;
case "Isabella_Sink":
dialog.text = "Well, tell me. How are things?";
link.l1 = "Not too wonderful. I... I caught up the brig at Puerto Bello, and I boarded it.";
link.l1.go = "Isabella_Sink_1";
break;
case "Isabella_Sink_1":
dialog.text = "Well, was your Isabella aboard?";
link.l1 = "She was, but she wouldn't listen. I couldn't get her off the ship, and it sank, with her on board. So... That's how things are, Attila...";
link.l1.go = "Brig_Late_2";
break;
case "SalvatorNews":
dialog.text = "Who's that I see? Why, it's " + GetFullName(pchar) + ", in the flesh!";
link.l1 = "Hello, Attila! How are you, old chum?";
link.l1.go = "SalvatorNews_1";
break;
case "SalvatorNews_1":
dialog.text = "All right. Everything's all right. How are things?";
link.l1 = "Mixed. I can't find Salvatore, only catch his minions.";
link.l1.go = "SalvatorNews_2";
break;
case "SalvatorNews_2":
dialog.text = "Uh-huh...";
link.l1 = "Listen, have you heard anything about him?";
link.l1.go = "SalvatorNews_3";
break;
case "SalvatorNews_3":
dialog.text = "Not especially. He goes around dives, hiring various lowlifes. He pays them up-front, then he disappears. A hard man to catch.";
link.l1 = "You can say that again. How can I outsmart him?";
link.l1.go = "SalvatorNews_4";
break;
case "SalvatorNews_4":
dialog.text = "Go to Belize, and look for him there.";
link.l1 = "Why Belize?";
link.l1.go = "SalvatorNews_5";
break;
case "SalvatorNews_5":
dialog.text = "Because that's where he went, last I heard. That's literally just a couple of days ago.";
link.l1 = "I... took Isabella to Belize...";
link.l1.go = "SalvatorNews_6";
break;
case "SalvatorNews_6":
dialog.text = "Uh-oh. I see what's happening. I wouldn't waste time if I was you...";
link.l1 = "No. I... Goodbye, Attila. Thank you.";
link.l1.go = "exit";
NextDiag.TempNode = "AtillaInHouse_Again";
AddQuestRecord("Romantic_Line", "20");
sld = characterFromId("Isabella");
LAi_SetStayType(sld);
ChangeCharacterAddressGroup(sld, "Beliz_Cave_2", "goto", "goto5");
sld.dialog.currentnode = "IsabellaInCave";
QuestSetCurrentNode("Rosita", "BackRosita");
sld = characterFromId("Rosita");
sld.talker = 10;
break;
case "IsabellaIsDead":
dialog.text = "Oh, Captain " + GetFullName(pchar) + ". How you doing?";
link.l1 = "Attila, I lost Isabella...";
link.l1.go = "IsabellaIsDead_1";
break;
case "IsabellaIsDead_1":
dialog.text = "What happened?";
link.l1 = "I killed Salvatore, and was about to wed Isabella in San Juan. Then during the ceremony, a mob of cutthroats burst into the church and killed her... Salvatore hired them before he died...";
link.l1.go = "IsabellaIsDead_2";
break;
case "IsabellaIsDead_2":
dialog.text = "That's awful. My condolences. But, well, what can you do. You have to go on living...";
link.l1 = "Yes, Attila, that's... you're right...";
link.l1.go = "exit";
npchar.LifeDay = 0;
NextDiag.TempNode = "IsabellaIsDead_after";
CloseQuestHeader("Romantic_Line");
break;
case "IsabellaIsDead_after":
dialog.text = "Oh, Attila, it's been so hard...";
link.l1 = "I understand, my friend...";
link.l1.go = "exit";
NextDiag.TempNode = "IsabellaIsDead_after";
npchar.lifeDay = 0;
break;
case "IsabellaIsMyWife":
dialog.text = "Greetings, my friend! How's life?";
link.l1 = "Life is great, Attila! Everything is wonderful! Isabella and I got married! I am now, what you call, a family man!";
link.l1.go = "IsabellaIsMyWife_1";
npchar.lifeDay = 0;
break;
case "IsabellaIsMyWife_1":
dialog.text = "Congratulations. That's great. A pirate's life is rarely long, so it's good you can put that aside...";
link.l1 = "That is true. Isabella agreed to marry me only on the condition that I quit piracy.";
link.l1.go = "IsabellaIsMyWife_2";
break;
case "IsabellaIsMyWife_2":
dialog.text = "Maybe it's for the better, my friend...";
link.l1 = "Yeah... I guess so. 'Bye, Attila...";
link.l1.go = "exit";
link.l2 = "Attila, thing is... I'd like to thank you for everything you've done for me.";
link.l2.go = "IsabellaIsMyWife_3";
NextDiag.TempNode = "IsabellaIsMyWife_after";
pchar.RomanticQuest.Atilla = "YouAreBaster";
npchar.LifeDay = 0;
break;
case "IsabellaIsMyWife_after":
dialog.text = "Again, Captain " + pchar.name + " is before me. What does the Captain want with Attila?";
link.l1 = "Nothing in particular, my friend, just visiting...";
link.l1.go = "exit";
NextDiag.TempNode = "IsabellaIsMyWife_after";
break;
case "IsabellaIsMyWife_3":
dialog.text = "For what in general, then?";
link.l1 = "Well, for your help, and for all those times you pulled me out of hot water! And it's thanks to you that I met Isabella...";
link.l1.go = "IsabellaIsMyWife_4";
break;
case "IsabellaIsMyWife_4":
LocatorReloadEnterDisable("Pirates_town", "houseF1", true);
dialog.text = "Ha! That I won't deny, my friend...";
if (sti(pchar.money) >= 1000)
{
link.l1 = "Well, since I've got you on a roll, then accept a thousand of coins, Attila!";
link.l1.go = "AddRepa_1";
}
if (sti(pchar.money) >= 70000)
{
link.l2 = "I'm sure you won't deny seventy thousand coins, either...";
link.l2.go = "AddRepa_2";
}
if (sti(pchar.money) >= 150000)
{
link.l3 = "I've got a hundred fifty thousand coins for you.";
link.l3.go = "AddRepa_3";
}
if (sti(pchar.money) >= 300000)
{
link.l4 = "I have here three hundred thousand coins. They're yours.";
link.l4.go = "AddRepa_4";
}
break;
case "AddRepa_1":
dialog.text = "Well, " + pchar.name + "... That, I did not expect. Well, thank you. I suppose I should ask no further about this...";
link.l1 = "That's nothing, my friend! Be well...";
link.l1.go = "exit";
AddMoneyToCharacter(pchar, -1000);
ChangeCharacterReputation(pchar, -10);
break;
case "AddRepa_2":
dialog.text = "Splendid! I'm grateful to you, " + GetFullName(pchar) + ".";
link.l1 = "All is well, Attila. See you...";
link.l1.go = "exit";
AddMoneyToCharacter(pchar, -70000);
pchar.RomanticQuest.Atilla = "YouAreNormal";
ChangeCharacterReputation(pchar, 5);
break;
case "AddRepa_3":
dialog.text = "Wow! I really didn't do much...";
link.l1 = "Attila, you may not have broken a sweat, but I couldn't have done it without you. Goodbye...";
link.l1.go = "exit";
AddMoneyToCharacter(pchar, -150000);
pchar.RomanticQuest.Atilla = "YouAreNormal";
ChangeCharacterReputation(pchar, 15);
break;
case "AddRepa_4":
dialog.text = "Lord of my loins, are you sure? That's so much money! Thank you, my friend. This is a wonderful thing. I will buy myself a better corner... No, on further thought I will return to the Old World. I have been here for too long.";
link.l1 = "Do you as you please, my friend! Goodbye...";
link.l1.go = "exit";
AddMoneyToCharacter(pchar, -300000);
pchar.RomanticQuest.Atilla = "YouAreGood";
ChangeCharacterReputation(pchar, 30);
break;
}
}