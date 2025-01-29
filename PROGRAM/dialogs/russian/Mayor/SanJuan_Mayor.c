// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What do you want? Ask away.", "I am listening to you, what's the question?"), "It is the second time you are trying to ask...", "It is the third time you are again trying to ask...",
                          "When is it going to end?! I am a busy man, working on the colony's matters and you are still trying to ask something!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I have changed my mind...", "Not now. Wrong place and time."), "True... But later, not now...",
                      " I'll ask... But a bit later...", "I am sorry, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "RomanticQuest.MayorOk"))
			{
				link.l1 = "Señor Governor, I am Captain " + GetFullName(pchar) + ". It was I who was wed in the city church, with widow Isabella Olevarez (born de Valdez).";
				link.l1.go = "Romantic_1";
			}
		break;
		case "Romantic_1":
			dialog.text = "You're just in time, Captain! I already sent the commandant for you. Well, since you're already here, for the love of God, won't you tell us why you've put on such a terrible massacre in our church!";
			link.l1 = "Señor " + npchar.lastname + ", I was simply defending my life, my honor, and Isabella, my wife...";
			link.l1.go = "Romantic_2";
		break;
		case "Romantic_2":
			dialog.text = "That sounds quite noble, Captain, but I'm still waiting on the details of the event that shook the whole city!";
			link.l1 = "Señor Governor, the deceased husband of Isabella, Salvatore Olevares, was grade A scum. He has a long history of abhorrent crimes, many of them murders...";
			link.l1.go = "Romantic_3";
		break;
		case "Romantic_3":
			dialog.text = "I am aware of that. When Isabella arrived from her cousin's, Fernandez in Belize, she visited me and told me all about it. So, I take it that you are her savior?";
			link.l1 = "Yes, Señor Governor. I trust there's nothing surprising in the fact that Isabella and I decided to get married as soon as we got the chance. However, before his death, that bastard Salvatore hired a whole gang of truly detestable rabble from all over the Caribbean to destroy us.";
			link.l1.go = "Romantic_4";
		break;
		case "Romantic_4":
			dialog.text = "And the people in the church were the assassins?";
			link.l1 = "Exactly right, Señor Governor. I reckon I've done a lot of good for the whole region by destroying so many bandits at once...";
			link.l1.go = "Romantic_5";
		break;
		case "Romantic_5":
			dialog.text = "No doubt about it, Captain, you have. Well, now the situation is quite clear. We will most likely use the public fund to consecrate the church.";
			link.l1 = "Señor Governor, thank you so much for understanding the situation...";
			link.l1.go = "Romantic_6";
		break;
		case "Romantic_6":
			dialog.text = "It is my duty to know what's what in such matters, Captain! Anyhow, I wish all the best to you and your spouse. Please accept my congratulations.";
			link.l1 = "Thank you, Señor Governor!";
			link.l1.go = "exit";
			AddQuestRecord("Romantic_Line", "27");
			DeleteAttribute(pchar, "RomanticQuest.MayorOk");
			LocatorReloadEnterDisable("SanJuan_town", "houseSp6", false);
			ref	sld1 = CharacterFromID("Isabella");
			sld1.talker = 10;
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

