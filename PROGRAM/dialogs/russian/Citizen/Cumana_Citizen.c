// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("What kind of questions?", "What would you like?");
			link.l1 = RandPhraseSimple("I have changed my mind...", "I have got nothing to say now.");
		    link.l1.go = "exit";
	if (CheckAttribute(pchar, "RomanticQuest.ShipToCumana"))
			{
                dialog.Text = "I'm listening.";
    			link.l1 = "You know if a ship called The Wounds of Christ has docked here?";
    			Link.l1.go = "RomanticQuest_1";
			}			
		break;
		case "RomanticQuest_1":
			dialog.Text = "Oh, yes, Se√±or, it's come back. They hit a storm and lost their mainmast. They're lucky they got back okay.";
			link.l1 = "And where might I find the Captain?";
			Link.l1.go = "RomanticQuest_2";
		break;		
		case "RomanticQuest_2":
			dialog.Text = "I reckon he slipped out to a shipyard, not long since...";
			link.l1 = "Thank you.";
			Link.l1.go = "exit";
			DeleteAttribute(pchar, "RomanticQuest.ShipToCumana");
			ref rChar = characterFromID("BrigCaptain");
			ChangeCharacterAddressGroup(rChar, "Cumana_Shipyard", "goto", "goto1");
		break;
		
		case "info":
        // заменить на описание неких НПС, по квестам
			dialog.text = "Do you think I work for the secret service of "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "Well... farewell then.";
			link.l1.go = "exit";
			link.l2 = "Another question then";
			link.l2.go = "new question";
		break;
		
		case "town":
        // заменить на описание как пройти, по квестам
			dialog.text = "Am I the information bureau for you? Don't know. Don't know a thing.";

            link.l1 = "You're such a muddle-headed! Bye.";
			link.l1.go = "exit";
			link.l2 = "Another question then";
			link.l2.go = "new question";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

