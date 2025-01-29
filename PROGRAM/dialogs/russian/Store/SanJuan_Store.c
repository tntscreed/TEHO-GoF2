// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Go ahead, what do you want?",
                          "We were just talking about that. You must have forgotten...", "This is the third time today you're talking about some question...",
                          "Listen, this is a store. People buy stuff here. Don't disturb me!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("You know, " + NPChar.name + ", maybe next time.", "Right, I've forgotten for some reason...",
                      "Yes, it really is the third time...", "Hm, I wont...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
	
		case "Romantic_1":
            dialog.Text = "(To Isabella): So are you going to pay or should I call the soldiers?";
			Link.l1 = "How dare you, scoundrel! Apologize to Señora this very instant or I will pierce your fat body!";
		    Link.l1.go = "exit";
		    NextDiag.TempNode = "Second time";
		    AddDialogExitQuest("Romantic_TalkInShop_2");
		break;
		
		case "Romantic_2":
            dialog.Text = "Certainly, señor Capitan.";
			Link.l1 = "Now we're talking.";
		    Link.l1.go = "exit";
		    NextDiag.TempNode = "Second time";
		    AddDialogExitQuest("Romantic_TalkInShop_2");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}
