void ProcessDialogEvent()
{
ref NPChar, sld;
aref Link, NextDiag;
float locx, locy, locz;
DeleteAttribute(&Dialog,"Links");
makeref(NPChar,CharacterRef);
makearef(Link, Dialog.Links);
makearef(NextDiag, NPChar.Dialog);
switch(Dialog.CurrentNode)
{
case "First time":
NextDiag.TempNode = "First time";
dialog.text = "Buenas Dias, Señor. So, tell me... Wouldn't you be the captain of the ship that's standing for the raid?";
link.l1 = "And you are the captain of the Five Holy Wounds of Christ?";
link.l1.go = "ShipToDomingoTavenr_2";
link.l2 = "No, that's not me.";
link.l2.go = "exit";
break;
case "Exit":
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "ShipToDomingoTavenr_2":
dialog.text = "The same, Señor. Arr, cursed storm! My brig won't be out to sea for awhile. ?Caramba! And, just to spite me, I took a passenger. And Holy mother, he's really complaining..."+
"He's promising to skin me alive, but it's not like I can seal every crack at the bottom with my ass. He really needs to get to San Juan, and not one ship's sailing there. The man is a respected noble. I'd be happy to serve him, but I just can't!";
link.l1 = "Your passenger doesn't happen to be Don Miguel de Valdez? I would be able to transport him to San Juan.";
link.l1.go = "ShipToDomingoTavenr_3";
break;
case "ShipToDomingoTavenr_3":
NextDiag.TempNode = "ShipToDomingoTavenr_Temp";
dialog.text = "Yes, precisely! In the flesh! Don Miguel de Valdez! Oh, lord. God bless you!";
link.l1 = "Then rouse him, and quickly send him to my ship. I'll be waiting for him at port.";
link.l1.go = "exit";
DeleteAttribute(pchar, "RomanticQuest.ShipToCumanaTavenrn");
Pchar.quest.Romantic_Brother.win_condition.l1           = "location";
Pchar.quest.Romantic_Brother.win_condition.l1.location  = "Cumana_town";
Pchar.quest.Romantic_Brother.win_condition              = "Romantic_Brother";
Pchar.GenQuest.Hunter2Pause = true;
AddQuestRecord("Romantic_Line", "6");
npchar.LifeDay = 2;
SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");
DeleteAttribute(Pchar, "RomanticQuest.PriestAsk");
break;
case "ShipToDomingoTavenr_Temp":
NextDiag.TempNode = "ShipToDomingoTavenr_Temp";
dialog.text = "Oh, dear. May God bless you!";
link.l1 = "Stuff happens. We'll be square one day.";
link.l1.go = "exit";
break;
case "Romantic_Brother_1":
NextDiag.TempNode = "Romantic_Brother_2";
dialog.text = "Good day! You're Captain "+GetFullName(Pchar)+"? I'm Don Miguel de Valdez. I'm heading to San Juan.";
link.l1 = "Welcome aboard, Don Miguel. Yes, I'm Captain "+GetFullName(Pchar)+". I hope the journey will be pleasant for you.";
link.l1.go = "Step_1";
break;
case "Step_1":
AddQuestRecord("Romantic_Line", "7");
OfficersReaction("good");
AddCharacterExpToSkill(pchar, "Sailing", 40);
AddCharacterExpToSkill(pchar, "Leadership", 20);
AddPassenger(pchar, NPChar, false);
SetCharacterRemovable(NPChar, false);
Pchar.quest.Romantic_Brother_port.win_condition.l1           = "location";
Pchar.quest.Romantic_Brother_port.win_condition.l1.location  = "SanJuan_town";
Pchar.quest.Romantic_Brother_port.win_condition              = "Romantic_Brother_port";
TraderHunterOnMap();
LAi_SetActorType(npchar);
LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
chrDisableReloadToLocation = false;
bDisableFastReload = false;
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "Romantic_Brother_2":
NextDiag.TempNode = "Romantic_Brother_2";
dialog.text = "Thanks for the help!";
link.l1 = "Believe me, it's no hassle at all.";
link.l1.go = "exit";
break;
case "Romantic_Brother_port_1":
NextDiag.TempNode = "Romantic_Brother_2";
dialog.text = "Thank you. And now let's go visit my sister.";
link.l1 = "Please. Of course.";
link.l1.go = "Step_2";
break;
case "Step_2":
RemovePassenger(pchar, NPChar);
Pchar.quest.Romantic_Brother_House.win_condition.l1           = "location";
Pchar.quest.Romantic_Brother_House.win_condition.l1.location  = "SanJuan_houseSp6";
Pchar.quest.Romantic_Brother_House.win_condition              = "Romantic_Brother_House";
chrDisableReloadToLocation = false;
LAi_SetActorType(npchar);
LAi_ActorRunToLocation(npchar, "reload", "houseSp6", "", "goto", "goto4", "", -1);
NextDiag.CurrentNode = NextDiag.TempNode;
DialogExit();
break;
case "Romantic_Brother_Thanks":
NextDiag.TempNode = "Romantic_Brother_Thanks";
dialog.text = "Captain, huge thanks for the favor. How great that you turned up at Cumana. I can't count on any help from Salvatore...";
link.l1 = "Don't think too much about it, Miguel. Everything's okay. The important thing is for your sister to be happy...";
link.l1.go = "Step_3";
break;
case "Step_3":
dialog.text = "We'll be happy to see you this evening, Captain.";
link.l1 = "I'll surely come, Miguel.";
link.l1.go = "exit";
break;
case "TalkNearHouse_1":
dialog.text = "Swindler! It was you that stole my sister's money, using fake promissory notes! Thief and murderer!";
link.l1 = "Yes, it was me! I damn well needed the money! And you hold your tongue, you pup, or I'll clip it for you! That goes for your sister, too...";
link.l1.go = "TalkNearHouse_2";
break;
case "TalkNearHouse_2":
dialog.text = "Only if they don't string you up first, scoundrel! There are no formalities for your kind! You'll be behind bars tomorrow!";
link.l1 = "You yourself chose your fate, pup!";
link.l1.go = "TalkNearHouse_3";
break;
case "TalkNearHouse_3":
DialogExit();
AddDialogExitQuest("Romantic_DeadBrother_1");
break;
case "ArrestInHome_2":
ref rColony = GetColonyByIndex(FindColony("SanJuan"));
if (sti(rColony.HeroOwn))
{
dialog.text = "Captain?! Sorry, but we received a report that there's a murderer here!";
link.l1 = "Relax. The killer left just now. If only you hadn't held me up...";
link.l1.go = "ArrestInHome_5";
}
else
{
dialog.text = "Captain " + GetFullName(pchar) + ", in the name of the law, you're under arrest!";
link.l1 = "Officer, that scoundrel Salvatore Olevarez is the real killer. He bankrupted his wife, using fake promissory notes!";
link.l1.go = "ArrestInHome_3";
}
break;
case "ArrestInHome_3":
dialog.text = "Do you have evidence? Where are these promissory notes?";
if (CheckCharacterItem(pchar, "Order"))
{
link.l1 = "I have them, officer!";
link.l1.go = "ArrestInHome_Have";
}
else
{
link.l1 = "Miguel was talking about them. I heard it myself...";
link.l1.go = "ArrestInHome_NotHave";
}
break;
case "ArrestInHome_Have":
dialog.text = "Fine, we'll resolve it. I presume they'll be examined. For now, turn in your weapons and follow me!";
link.l1 = "Surrender into your mercy?! No, I've got some serious doubts whether everything will be examined properly.";
link.l1.go = "ArrestInHome_4";
break;
case "ArrestInHome_4":
dialog.text = "In that case, Captain, I'll be forced to use force.";
link.l1 = "And in that case, I will be forced to use resistance against an illegal arrest.";
link.l1.go = "FightInHouse";
break;
case "ArrestInHome_NotHave":
dialog.text = "Captain, the commandant will listen to your statement. So now, turn over your weapons and follow me!";
link.l1 = "Caramba, and I think my lot's bad... I've got nothing besides my word!";
link.l1.go = "ArrestInHome_4";
break;
case "ArrestInHome_4":
dialog.text = "The court will decide that... Turn your weapons over immediately!";
link.l1 = "Hm... Well, no, officer, I'll prefer to leave. And I'll recommend against stopping me.";
link.l1.go = "FightInHouse";
break;
case "FightInHouse":
DialogExit();
LAi_group_Attack(NPChar, Pchar);
LAi_SetWarriorTypeNoGroup(npchar);
LAi_LocationFightDisable(&Locations[FindLocation("SanJuan_houseSp6")], false);
AddQuestRecord("Romantic_Line", "10");
break;
case "ArrestInHome_5":
dialog.text = "Forgive me. I couldn't have known that it was you. Again, I empathize...";
link.l1 = "It's okay, I'll try to catch up to that scoundrel. And you're free!";
link.l1.go = "exit";
AddQuestRecord("Romantic_Line", "31");
break;
case "AmbushBandit":
dialog.text = "Oh, oh... It looks like we're in time...";
link.l1 = "You're in time for me? And with whom do I have the honor of speaking?";
link.l1.go = "AmbushBandit_1";
break;
case "AmbushBandit_1":
dialog.text = "We're in time for you, bro. You...";
link.l1 = "It feels so nice when someone's waiting for you...";
link.l1.go = "AmbushBandit_fight";
break;
case "AmbushBandit_fight":
LAi_LocationFightDisable(&locations[FindLocation("SanJuan_houseSp6")], false);
LAi_SetWarriorType(npchar);
LAi_group_MoveCharacter(npchar, "EnemyFight");
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
LAi_group_SetCheck("EnemyFight", "OpenTheDoors_R");
DialogExit();
AddDialogExitQuest("MainHeroFightModeOn");
AddQuestRecord("Romantic_Line", "12");
break;
case "BrigAbordage":
dialog.text = "Curses! Why the hell did you attack my ship?!";
link.l1 = "You've got two problems, Captain: you messed with the wrong person, and you took the wrong person aboard.";
link.l1.go = "BrigAbordage_1";
break;
case "BrigAbordage_1":
dialog.text = "Be clearer...";
link.l1 = "I'm taking Isabella Olevarez, and you'll tell me where Salvatore is. If you do that, you'll remain alive.";
link.l1.go = "BrigAbordage_2";
break;
case "BrigAbordage_2":
dialog.text = "And otherwise?";
link.l1 = "Otherwise, I'll finish you here and now, scoundrel!";
link.l1.go = "BrigAbordage_3";
break;
case "BrigAbordage_3":
dialog.text = "We'll see who finishes whom...";
link.l1 = "Hm. That last battle wasn't enough for you? Well, we'll see...";
link.l1.go = "BrigAbordage_4";
break;
case "BrigAbordage_4":
LAi_SetCurHPMax(npchar);
QuestAboardCabinDialogExitWithBattle("Romantic_TaklInCabinBrig");
pchar.quest.Romantic_BrigDieHard.over = "yes";
pchar.quest.Romantic_AfterBrigSunk.over = "yes";
Island_SetReloadEnableGlobal("PortoBello", true);
DialogExit();
AddDialogExitQuest("MainHeroFightModeOn");
break;
case "AmbushPotroBello":
dialog.text = "Finally! We were starting to get bored of waiting! Allow me to introduce the captain of the brig, Rapturous. And where's the lady?";
link.l1 = "Isabella?";
link.l1.go = "AmbushPotroBello_1";
break;
case "AmbushPotroBello_1":
dialog.text = "Yeah, Isabella.";
link.l1 = "On my ship.";
link.l1.go = "AmbushPotroBello_2";
break;
case "AmbushPotroBello_2":
dialog.text = "Then bring her over here... Or, wait. Don't, actually. Let's go to the ship ourselves, and quietly choke her. There's no need for her to be walking the city streets.";
link.l1 = "What was the point of dragging her from San Juan?";
link.l1.go = "AmbushPotroBello_3";
break;
case "AmbushPotroBello_3":
dialog.text = "That's not your concern, pal...";
link.l1 = "Hm. Right you are. That's Salvatore's business. And where's Salvatore himself? Doesn't he wish to say goodbye to his wife?";
link.l1.go = "AmbushPotroBello_4";
break;
case "AmbushPotroBello_4":
dialog.text = "He's not here. He's out on business. So we just handle our business, and we're free.";
link.l1 = "Understood... And where does Salvatore do his business? How can I find him?";
link.l1.go = "AmbushPotroBello_5";
break;
case "AmbushPotroBello_5":
dialog.text = "Salvatore finds who he needs, himself. Only Salvatore himself knows where Salvatore is... Hey, you're a bit too curious for your own good!";
link.l1 = "Correct, since I'm not the captain off the brig Rapturous, but rather the captain that sent the brig Rapturous to the bottom...";
link.l1.go = "AmbushPotroBello_6";
break;
case "AmbushPotroBello_6":
dialog.text = "How could they have messed up this badly?! Well, buddy, it's time for you to go to next world...";
link.l1 = "Thank you, but I think I'd rather stay a bit longer...";
link.l1.go = "AmbushPotroBello_7";
break;
case "AmbushPotroBello_7":
LAi_LocationFightDisable(&locations[FindLocation("PortoBello_houseF2")], false);
LAi_SetWarriorType(npchar);
LAi_group_MoveCharacter(npchar, "EnemyFight");
LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
LAi_group_SetCheck("EnemyFight", "Romantic_TalkPortoBello");
DialogExit();
AddDialogExitQuest("MainHeroFightModeOn");
break;
case "Rosita":
dialog.text = "Welcome to my home, Señor. Now, then: who are you?";
link.l1 = "Hello there, Señora. My name is Captain " + GetFullName(pchar) + ", though I imagine that means nothing to you?";
link.l1.go = "Rosita_1";
break;
case "Rosita_1":
dialog.text = "Yes, I'm not familiar with it. So to what do I owe the honor of seeing you in my house?";
link.l1 = "Well, Señora, I'm acting under an order from your cousin Isabella Olevarez.";
link.l1.go = "Rosita_2";
break;
case "Rosita_2":
dialog.text = "Pray, continue.";
link.l1 = "Señora, Isabella has shown a desire to come to you, and I've completed her wish with pleasure.";
link.l1.go = "Rosita_3";
break;
case "Rosita_3":
dialog.text = "God, Captain. Can it be that you're really brought Isabella here alive and  unharmed?!";
link.l1 = "It's as you say, Señora. She is on my ship, and is readying to step ashore.";
link.l1.go = "Rosita_4";
break;
case "Rosita_4":
dialog.text = "Oh, Señor! I don't even know how to thank you! A chain of tragic misfortunes has fallen on Isabella. She lost her father and brother, and now her husband has disappeared! You couldn't possibly imagine...";
link.l1 = "Not at all, Señora. I know about all of that. Say, has Salvatore Olevarez appeared at your place?";
link.l1.go = "Rosita_5";
break;
case "Rosita_5":
dialog.text = "No, he hasn't. He's disappeared without a trace. Why are you asking me, Captain?";
link.l1 = "I think it would be better if Isabella were to tell us everything herself. I'm convinced that your house is safe for Isabella, so we'll send her to you for now. Take her, Señora. She's had it pretty rough recently...";
link.l1.go = "Rosita_6";
break;
case "Rosita_6":
dialog.text = "Thank you for everything that you've done for Isabella, Señor " + pchar.name + ". I will pray for you...";
link.l1 = "Fine, Señora Rosita. I couldn't complain about that. God be with you!";
link.l1.go = "exit";
NextDiag.TempNode = "Rosita_after";
Pchar.quest.Romantic_BelizCityTalk.win_condition.l1 = "location";
Pchar.quest.Romantic_BelizCityTalk.win_condition.l1.location = "Beliz_town";
Pchar.quest.Romantic_BelizCityTalk.win_condition = "Romantic_BelizCityTalk";
pchar.quest.Romantic_AmbushInHouse.over = "yes";
pchar.quest.Romantic_AmbushInPortoBello.over = "yes";
break;
case "Rosita_after":
dialog.text = "Captain " + GetFullName(pchar) + "! I'm happy to see you.";
link.l1 = "Likewise, Señora.";
link.l1.go = "exit";
NextDiag.TempNode = "Rosita_after";
break;
case "BackRosita":
dialog.text = "Oh, it's you, Captain " + pchar.name + ". What good timing! Thank God for sending you!";
link.l1 = "What's happened, Rosita? Has Salvatore been here?";
link.l1.go = "BackRosita_1";
break;
case "BackRosita_1":
dialog.text = "No, I haven't seen Salvatore. But something's happened to Isabella! She's disappeared!";
link.l1 = "What do you mean, disappeared? When?";
link.l1.go = "BackRosita_2";
break;
case "BackRosita_2":
dialog.text = "Yesterday morning, she went off to the market with her servant. Sine then, no one's seen a trace of her!";
link.l1 = "Señora Rosita, I'll go and search at once!";
link.l1.go = "BackRosita_3";
break;
case "BackRosita_3":
dialog.text = "May Saint Francis help you!";
link.l1 = "Fine....";
link.l1.go = "exit";
NextDiag.TempNode = "BackRosita_after";
pchar.RomanticQuest = "SeekIsabella";
pchar.quest.SeekIsabella_exitTown.win_condition.l1 = "location";
pchar.quest.SeekIsabella_exitTown.win_condition.l1.location = "Beliz_ExitTown";
pchar.quest.SeekIsabella_exitTown.win_condition = "SeekIsabella_exitTown";
AddQuestRecord("Romantic_Line", "21");
sld = GetCharacter(NPC_GenerateCharacter("ServantGirl", "girl_6", "woman", "towngirl", 5, SPAIN, 30, false, "quest"));
LAi_SetActorType(sld);
LAi_ActorSetLayMode(sld);
sld.SaveItemsForDead = true;
sld.DontClearDead = true;
ChangeCharacterAddressGroup(sld, "Beliz_ExitTown", "goto", "goto17");
locations[FindLocation("Beliz_ExitTown")].DisableEncounters = true;
sld = GetCharacter(NPC_GenerateCharacter("Bandit", "officer_6", "man", "man", 35, PIRATE, -1, true, "quest"));
FantomMakeCoolFighter(sld, 35, 85, 75, "blade_15", "pistol3", LAi_GetCharacterBulletType(sld), 60);
LAi_SetWarriorType(sld);
LAi_warrior_SetStay(sld, true);
LAi_group_MoveCharacter(sld,LAI_GROUP_MONSTERS);
ChangeCharacterAddressGroup(sld, "Beliz_Cave_2", "goto", "goto4");
LAi_LocationDisableOfficersGen("Beliz_Cave_2", true);
LAi_LocationDisableMonstersGen("Beliz_Cave_2", true);
pchar.quest.Romantic_BanditIsDead.win_condition.l1 = "NPC_Death";
pchar.quest.Romantic_BanditIsDead.win_condition.l1.character = "Bandit";
pchar.quest.Romantic_BanditIsDead.win_condition = "Romantic_BanditIsDead";
sld = CharacterFromID("Isabella");
LAi_SetImmortal(sld, false);
break;
case "BackRosita_after":
dialog.text = "Have you found Isabella?";
link.l1 = "Not yet, Señora. I am looking...";
link.l1.go = "exit";
break;
case "IsabellaIsDead_Beliz":
dialog.text = "Captain, did you find Isabella?";
link.l1 = "Yes, Rosita, I did. But on our way to the city, we were attacked... And... Isabella was killed.";
link.l1.go = "IsabellaIsDead_Beliz_1";
NextDiag.TempNode = "IsabellaIsDead_Beliz_after";
break;
case "IsabellaIsDead_Beliz_1":
dialog.text = "I can't believe it... She put such trust in you! Lord rest her soul...";
link.l1 = "Rosita, I'm dying from grief!";
link.l1.go = "exit";
break;
case "IsabellaIsDead_Beliz_after":
dialog.text = "Captain, I don't want to see you. Farewell.";
link.l1 = "Farewell, Rosita...";
link.l1.go = "exit";
break;
case "SavedIsabella":
dialog.text = "Isabella!";
link.l1 = "Rosita!";
link.l1.go = "SavedIsabella_1";
break;
case "SavedIsabella_1":
dialog.text = "You're all right! Thank God!";
link.l1 = "Now, in days to come, and to the end of time...";
link.l1.go = "SavedIsabella_2";
break;
case "SavedIsabella_2":
dialog.text = "What happened? Where have you been? And where is Conchita?";
link.l1 = "Rosita, Salvatore kidnapped me. Conchita is dead, killed by my husband...";
link.l1.go = "SavedIsabella_3";
break;
case "SavedIsabella_3":
dialog.text = "Bastard! We must let the Governor know, such that he may arrests Salvatore immediately!";
link.l1 = "Salvatore is also dead. I was found and rescued by my guardian angel... Salvatore attacked him, but was killed in front of me.";
link.l1.go = "SavedIsabella_4";
break;
case "SavedIsabella_4":
dialog.text = "Isabella, is this nightmare really over?";
link.l1 = "Yes, Rosita, it's finished...";
link.l1.go = "SavedIsabella_5";
break;
case "SavedIsabella_5":
dialog.text = "And your loyal knight has again resolved all your problems... Isabella, you are lucky to have such an admirer!";
link.l1 = "Oh, cousin, that is true! Rosita, a bit later I'll tell you some more news, but for now let's not delay my rescuer.";
link.l1.go = "exit";
NextDiag.TempNode = "SavedIsabella_after";
AddDialogExitQuest("Romantic_DelivToRosita_2");
break;
case "SavedIsabella_after":
dialog.text = "You are a real man, Captain!";
link.l1 = "Hmm, thank you for the compliment, Rosita...";
link.l1.go = "exit";
NextDiag.TempNode = "SavedIsabella_after";
break;
case "AmbushInChurch":
dialog.text = "Greetings from Salvatore, Captain!";
link.l1 = "Simmer down, now. Salvatore is dead.";
link.l1.go = "AmbushInChurch_1";
break;
case "AmbushInChurch_1":
dialog.text = "Unfortunately, this party was paid for in advance - and only the client can cancel his order...";
link.l1 = "Look, genius, I told you - Salvatore is dead! Do you hold nothing sacred? This is a wedding, man. We are in the house of God!";
link.l1.go = "AmbushInChurch_2";
break;
case "AmbushInChurch_2":
dialog.text = "No time to talk...";
link.l1 = "Argh!";
link.l1.go = "exit";
AddDialogExitQuest("Romantic_fightInChurch_1");
break;
case "IsabellaIsDead":
dialog.text = "Captain " + GetFullName(pchar) + ", good to see you. What's news? Did you and Isabella get yourselves hitched, then?";
link.l1 = "The worst news possible, Rosita... Isabella is dead, killed at the altar, right beside me... They... There were just too many of them...";
link.l1.go = "IsabellaIsDead_1";
break;
case "IsabellaIsDead_1":
dialog.text = "Oh God, poor Isabella! She suffered so much, was so unlucky in marriage... "+
"But then you appeared, and I thought that her life would finally change for the better. But it seems a woman cannot escape her fate...";
link.l1 = "Oh, Rosita... I've been destitute...";
link.l1.go = "IsabellaIsDead_2";
break;
case "IsabellaIsDead_2":
dialog.text = "I understand, Captain... Excuse me, I must let our family know - we must dress for mourning...";
link.l1 = "Yes, Rosita, I understand...";
link.l1.go = "exit";
npchar.LifeDay = 0;
NextDiag.TempNode = "IsabellaIsDead_after";
break;
case "IsabellaIsDead_after":
dialog.text = "What do you want, Captain?";
link.l1 = "Nothing, Rosita. I just wanted to visit the cousin of my Isabella...";
link.l1.go = "exit";
NextDiag.TempNode = "IsabellaIsDead_after";
break;
case "IsabellaIsMyWife":
dialog.text = "Señor " + pchar.name + ", I'm glad to see you! We are relatives now!";
link.l1 = "Yes, Señora Rosita. Isabella and I got married...";
link.l1.go = "IsabellaIsMyWife_1";
break;
case "IsabellaIsMyWife_1":
dialog.text = "This is wonderful! Isabella deserves so much more than that bastard Salvatore!";
link.l1 = "I completely agree. I don't even want to think about Salvatore - I sent him to hell, and and am quite glad that I did...";
link.l1.go = "IsabellaIsMyWife_2";
break;
case "IsabellaIsMyWife_2":
dialog.text = "Señor " + pchar.name + ", you are a real knight! Take care of Isabella... By the way, if there's ever any trouble, like if you and her have a fight, you are always welcome here. I'll be glad to help.";
link.l1 = "Very well, my new cousin...";
link.l1.go = "exit";
NextDiag.TempNode = "IsabellaIsMyWife_after";
break;
case "IsabellaIsMyWife_after":
dialog.text = "I'm glad to see you, cousin " + pchar.name + "!";
link.l1 = "Same here, Señora Rosita.";
link.l1.go = "exit";
NextDiag.TempNode = "IsabellaIsMyWife_after";
break;
case "IsabellaIsWife":
dialog.text = NPCStringReactionRepeat("Hello, cousin. I'm so glad to see you! How is Isabella?",
"Back already, cousin? We just saw each other... ",
"What, again?! You'll hear nothing new from me, I can assure you! ",
"Listen, Captain. If you are this much of a bore at home, I pity my poor Isabella! ", "block", 1, npchar, Dialog.CurrentNode);
link.l1 = HeroStringReactionRepeat("Hello, cousin Rosita. Isabella is well.",
"Oh. So we did. Right you are. Sorry, Rosita, I shan't distract you further... ",
"Yes? All right then... ",
"No, Rosita. At home I am an angel, I swear... ", npchar, Dialog.CurrentNode);
link.l1.go = DialogGoNodeRepeat("IsabellaIsWife_1", "none", "none", "none", npchar, Dialog.CurrentNode);
NextDiag.TempNode = "IsabellaIsWife";
break;
case "IsabellaIsWife_1":
dialog.text = "Did you want to ask me something, Captain?";
link.l1 = "Not really, Rosita. Just came by to visit.";
link.l1.go = "exit";
if (pchar.RomanticQuest == "over")
{
link.l2 = "Rosita... I don't even know where to begin. Isabella... well, she locked me out.";
link.l2.go = "HorseCheck";
break;
}
if (pchar.RomanticQuest == "TheDoosIsClosed")
{
link.l2 = "Rosita... I don't even know where to begin. Isabella... well, she locked me out.";
link.l2.go = "TheDoosIsClosed";
}
sld = characterFromID("Isabella");
if (CheckAttribute(sld, "angry"))
{
if (sld.angry.name == "NewLife_Budget_Pay")
{
link.l3 = "You know, Rosita, I had some money problems recently, and Isabella is mighty mad at me...";
link.l3.go = "Budget";
}
if (sld.angry.name == "NewLife_KnowPirates")
{
link.l4 = "Rosita... If you can imagine it, Isabella somehow learned that I never quite quit piracy, as I promised before the wedding...";
link.l4.go = "KnowPirates";
}
if (sld.angry.name == "NewLife_Present")
{
link.l5 = "Thing is, Rosita... Isabella won't talk with me.";
link.l5.go = "Present";
}
}
break;
case "TheDoosIsClosed":
dialog.text = "I see... You must have been a bad boy, Captain. Did you not come home for a long time, or something?";
link.l1 = "Hmm, what can I say... Basically, the thing is... yes. But I am a sailor, Rosita! My job keeps me at sea most of the time.";
link.l1.go = "TheDoosIsClosed_1";
break;
case "TheDoosIsClosed_1":
dialog.text = "I understand, Captain... Well, I can probably resolve this. Go on home. Everything will be all right...";
link.l1 = "Rosita, you are a miracle!";
link.l1.go = "TheDoosIsClosed_2";
break;
case "TheDoosIsClosed_2":
dialog.text = "Stow the flattery, " + pchar.name + ", and smarten up. A woman needs to see her man, time to time.";
link.l1 = "I'll definitely keep that in mind, cousin. Goodbye...";
link.l1.go = "exit";
AddQuestRecord("Romantic_Line", "30");
LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
pchar.RomanticQuest = "OpenTheDoosOfHouse";
break;
case "Budget":
dialog.text = "What, you mean like debt?";
link.l1 = "Yes, exactly. Isabella asked me several times to pay off the debt, but at the time I just didn't have the money.";
link.l1.go = "Budget_1";
break;
case "Budget_1":
dialog.text = "Hmm, that's bad... All right, I'll tell you what to do. Make her a gift of emeralds - a ring, a necklace, and a solitaire. If emeralds won't melt her resolve, I don't know what will...";
link.l1 = "I guess that's what I'll do! Thank you, Rosita! Goodbye.";
link.l1.go = "exit";
break;
case "KnowPirates":
dialog.text = "Um, cousin... Forgive me for asking, but what do you mean by 'not quite?'";
link.l1 = "Well, I may be a civilian now, but that doesn't mean I'm going to just lie down. When I'm attacked, I'm going to defend myself. That's reasonable, isn't it?";
link.l1.go = "KnowPirates_1";
break;
case "KnowPirates_1":
dialog.text = "Hm, in theory... So I take it you haven't been provoking them?";
link.l1 = "Not at all! I just take what comes to me.";
link.l1.go = "KnowPirates_2";
break;
case "KnowPirates_2":
dialog.text = "I see... Well, then the only advice I can give you is to appease her.";
link.l1 = "Gladly, but how?";
link.l1.go = "KnowPirates_3";
break;
case "KnowPirates_3":
dialog.text = "Stones. A rainbow in a bucket. If I were you, I'd look at a sapphire, a diamond, a ruby, a large pearl... a big golden ring with a ruby wouldn't hurt, either.";
link.l1 = "Hmm, there's a thought... Thank you, Rosita. You've given me some ideas. Goodbye...";
link.l1.go = "exit";
break;
case "Present":
dialog.text = "What happened?";
link.l1 = "Nothing in particular... I wanted to buy her a present, but can't find anything suitable.";
link.l1.go = "Present_1";
break;
case "Present_1":
dialog.text = "Hm. That's no problem, then... on the surface. Is there something you're not telling me?";
link.l1 = "Well. Sort of. It's just that I've been so busy that I forgot I had already promised her a gift... So I promised her again. Which... makes four times, in all...";
link.l1.go = "Present_2";
break;
case "Present_2":
dialog.text = "Captain... You know you're really pressing your luck, buddy. How she can tolerate you is beyond me...";
link.l1 = "I know, I know. I screwed up. But what do I do?";
link.l1.go = "Present_3";
break;
case "Present_3":
dialog.text = "It's not that hard, Copernicus. Give her a present, already. And a good one. Say, three gold nuggets and five silver ingots? That would put her over the moon, I wager.";
link.l1 = "Oh, Rosita, what would I do without you! I'll go scrounge for that right now. Farewell...";
link.l1.go = "exit";
break;
case "HorseCheck":
dialog.text = "Yes, I am aware of this. And to you, Captain, I'll say this - your marriage has been dissolved, unilaterally.";
link.l1 = "What is going on? Did the Pope himself dissolve it?";
link.l1.go = "HorseCheck_1";
break;
case "HorseCheck_1":
dialog.text = "The annulment is de facto. You will never see Isabella again.";
link.l1 = "I don't understand. What the hell is going on?";
link.l1.go = "HorseCheck_2";
break;
case "HorseCheck_2":
dialog.text = "You really don't know. Then I'll tell you.";
link.l1 = "Please do!";
link.l1.go = "HorseCheck_3";
break;
case "HorseCheck_3":
dialog.text = "You should have spent less time in the bordellos, my dear! Isabella can forgive you much, but adultery - never!";
link.l1 = "What the hell? Who gave her that bright idea? That's slander!";
link.l1.go = "HorseCheck_4";
break;
case "HorseCheck_4":
dialog.text = "Oh hush up. The information is more than genuine, and you know it. Best of luck, Captain...";
link.l1 = "Well... Farewell, Rosita...";
link.l1.go = "exit";
npchar.LifeDay = 0;
NextDiag.TempNode = "HorseCheck_Bue";
CloseQuestHeader("Romantic_Line");
break;
case "HorseCheck_Bue":
dialog.text = "I have no more desire to speak with you.";
link.l1 = "...";
link.l1.go = "exit";
NextDiag.TempNode = "HorseCheck_Bue";
break;
}
}