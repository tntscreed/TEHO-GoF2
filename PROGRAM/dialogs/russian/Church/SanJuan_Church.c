// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What kind of questions, "+ GetSexPhrase("my son","my daughter") +"?", "Ask, I am listening to you..."), "I am listening, speak, "+ GetSexPhrase("my son","my daughter") +"...", "And it's the third time I tell you, "+ GetSexPhrase("my son","my daughter") +", ask your question.",
                          "A clergyman has a lot of work... and you are bothering me, "+ GetSexPhrase("my son","my daughter") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I've changed my mind...", "Not now, padre..."), "Have nothing to say, sorry...",
                      "I'll ask, I'll ask... but a bit later...", "Pardon me, holy father...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
            if (CheckAttribute(Pchar, "RomanticQuest.PriestAsk"))
			{
				link.l2 = "I would like to know how often you see Don Salvatore's wife in church?";
				link.l2.go = "Romantic_1";
			}
		break;

        case "Romantic_1":
			dialog.text = "Se√±ora Olevares? Quite often, my son, she's a fine parishioner... Why do you ask?";
			link.l1 = "Just curious, Padre. Thanks, I'll see ya.";
			link.l1.go = "exit";
			DeleteAttribute(Pchar, "RomanticQuest.PriestAsk");
		break;

        case "Romantic_2":
			dialog.text = GetFullName(pchar) + ", do you take Isabella de Valdez to be your lawfully wedded wife, and swear to love, honor and cherish her in sickness and in health, for as long as you both shall live?";
			link.l1 = "I do, Padre.";
			link.l1.go = "Romantic_3";
		break;
        case "Romantic_3":	
			locCameraToPos(3.64, 3.25, -7.84, false);
			LAi_SetActorType(npchar);
			LAi_ActorTurnToLocator(npchar, "goto", "goto5");
			dialog.text = "And do you, Isabella de Valdez, take " + GetMainCharacterNameGen() + " as your lawfully wedded husband, and swear to love and support him in sickness and in health, for as long as you both shall live?";
			link.l1 = "I do, Padre.";
			link.l1.go = "Romantic_4";
		break;
        case "Romantic_4":	
			locCameraToPos(-0.75, 3.85, -10.60, false);
			LAi_SetActorType(npchar);
			LAi_ActorTurnToLocator(npchar, "goto", "goto5");
			dialog.text = "If there's anyone here who knows a reason why this man and this woman should not be joined in holy matrimony, speak now or forever hold your peace.";
			link.l1 = "...";
			link.l1.go = "Romantic_5";
		break;
        case "Romantic_5":		
			dialog.text = "I hereby pronounce you husband and wife!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			AddDialogExitQuest("Romantic_Padre_3");			
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
