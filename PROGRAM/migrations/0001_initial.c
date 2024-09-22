// перенес багфиксеры и т.д.

extern int InitStdBlade( 	int		ItemIndex, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex,
					string  TargetGroup,
					int     Quality,
					string  BladeType,
					int     BladeNum,
					float   Lenght,
					float   Curve,
					bool    isGenerable,
					int     GenerationQty, 
					bool 	isGenerablePrice,
					int     Price);

extern int InitStdGun(	int		ItemIndex, 
				string 	id, 
				string 	ModelID, 
				string 	picTexture,
				int		picIndex, 
				float	Rare, 
				int 	MinLevel, 
				int		Price, 
				float 	DmgMin, 
				float 	DmgMax, 
				float 	Weight,
				int 	Charges, 
				int 	Quality );

extern void InitGunExt(string id,			
				string sAttr,       
				string sBullet,     
				string sGunPowder,  
				float  DmgMin_NC,   
				float  DmgMax_NC,   
				float  DmgMin_C,    
				float  DmgMax_C,    
				float  EnergyP_NC,  
				float  EnergyP_C,   
				bool   Stun_NC,     
				bool   Stun_C,      
				bool   MultiDamage, 
				int    MisFire,     
				bool   SelfDamage,  
				bool   Explosion,   
				float  Accuracy,    
				int    ChargeSpeed, 
				bool   isDefault );

void ApplyMigration(ref migrationState) {
	if(!CheckAttribute(pchar, "fix30032020")) {
		if(Migration_LoadSegment(migrationState, "items\initItems.c")) {
			int n = GetItemIndex("shamshir");
			if (n < 0) {
				n = GetItemIndex("Reserve_item_11");
				if(n >= 0) {
					trace("Reserve_item_11 found : " + n);
					InitStdBlade(n,"shamshir", "ITEMS_40", 1, TGT_PERSIAN, B_GOOD, "FencingS",4, 1.10, 1.05, 1, 10, 1, 0);
					GenerateGenerableItems();
				}
			}
			
			n = GetItemIndex("howdah");
			if (n < 0) {
				n = GetItemIndex("Reserve_item_12");
				if(n >= 0) {
					trace("Reserve_item_12 found : " + n);
					InitStdGun(n, "howdah","howdah_black","ITEMS_40", 2, 0.0001,1, 20000,45.0,160.0, 5.0, 2,B_EXCELLENT); 
					InitGunExt("howdah", "t1","grapeshot","gunpowder",  25.0,  50.0,  15.0,  30.0,  5.0,  5.0, 1, 1,     1, 0, 0, 1,                 50, 40, 1);		
					InitGunExt("howdah", "t2","GunEchin",          "", 115.0, 215.0, 115.0, 215.0, 20.0, 20.0, 0, 1,     1, 0, 0, 0,                 20, 40, 0);
				}
			}
    	}
	}
	
	if(!CheckAttribute(pchar,"questTemp.BigPatch_BugsFixer"))
	{
		log_Testinfo("Отработал багфиксер Большого Патча");
		pchar.questTemp.BigPatch_BugsFixer = "true";
		if (CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "end") // Почистить ДиС, если квест уже пройден
		{
			log_Testinfo("Отработал багфиксер ДиС");
			//  belamour убрать бессмертие с избранницы 
			if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1)
			{ 
				pchar.quest.Mary_giveme_sex.win_condition.l1 = "Timer";
				pchar.quest.Mary_giveme_sex.win_condition.l1.date.hour  = sti(GetTime());
				pchar.quest.Mary_giveme_sex.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 14);
				pchar.quest.Mary_giveme_sex.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
				pchar.quest.Mary_giveme_sex.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 14);
				pchar.quest.Mary_giveme_sex.function = "Mary_GiveMeSex"; // вернуть Мэри ее поведение
				sld = characterFromId("Mary");
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer") && GetCharacterIndex("Helena") != -1) 
			{
				sld = characterFromId("Helena");
				LAi_RemoveCheckMinHP(sld);
				LAi_SetImmortal(sld, false);
			}
		}
		if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "end") // почистить Дороже золота, если квест уже пройден
		{
			log_Testinfo("Отработал багфиксер Дороже Золота");
			if (GetCharacterIndex("Cortny") != -1) // убрать кортни, если такой иеется
			{
				sld = characterFromId("Cortny");
				//sld.LifeDay = 0; 
				ChangeCharacterAddressGroup(sld, "none", "", "");
			}
			// Вернуть Бото на место
			if(CheckAttribute(pchar, "questTemp.GoldenGirl.Julianna_Helper"))
			{
				sld = characterFromID("Julianna");
				RemovePassenger(pchar, sld);
				sld.dialog.currentnode = "Julianna_144";
				ChangeCharacterAddressGroup(sld, "FortFrance_SecBrRoom", "goto", "goto4");
				LAi_SetStayType(sld);
				LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			}
		}
		
		// belamour правка входа-выхода резиденции куманы
		n = Findlocation("Cumana_TownhallRoom");
		locations[n].reload.l2.name = "reload2";
		locations[n].reload.l2.go = "Cumana_town"; 
		locations[n].reload.l2.emerge = "reloadR1"; 
		locations[n].reload.l2.autoreload = "0";
		locations[n].reload.l2.label = "Street";

		locations[n].reload.l3.name = "reload3";
		locations[n].reload.l3.go = "CommonBedroom"; 
		locations[n].reload.l3.emerge = "reload1";
		locations[n].reload.l3.autoreload = "0";
		locations[n].reload.l3.label = "Street";
		
		n = Findlocation("Cumana_Town");
		locations[n].reload.lR1.name = "reloadR1";
		locations[n].reload.lR1.go = "Cumana_TownhallRoom";
		locations[n].reload.lR1.emerge = "reload2"; 
		
		// mitrokosta -->
		// снятие лишних прерываний на Тореро и Пуэблу
		if (!CheckAttribute(pchar, "questTemp.Trial")) {
			pchar.quest.Trial_Puebla_barque_abordage.over = "yes";
			pchar.quest.Trial_Puebla_barque_Sink.over = "yes";
		}
		
		if (!CheckAttribute(pchar, "questTemp.Mtraxx.Ignasio.Check")) {
			pchar.quest.mtraxx_corrida_sink.over = "yes";
			pchar.quest.mtraxx_corrida_capture.over = "yes";
		}
		
		// нужно для совместимости с моими правками мятежных оффов
		if (CheckAttribute(pchar, "questTemp.MunityOfficerIDX")) {
			DeleteAttribute(pchar, "questTemp.MunityOfficerIDX");
		}
		
		// второй шанс для карт диоса
		PrepareAdmiralMaps();
		
		// фикс бухты губернатора
		locations[FindLocation("Shore75")].reload.l2.emerge = "reload_1";
		
		// фикс поломки поручения капитана из-за дюнкерка, без ни
		aref arQuest;
		if (CheckAttribute(pchar, "GenQuest.CaptainComission")) {
			makearef(arQuest, pchar.GenQuest.CaptainComission);
			if (GetAttributesNum(arQuest) == 0) {
				DeleteAttribute(pchar, "GenQuest.CaptainComission");
			}
		}
		
		// фикс закрытой на ночь церкви Сент-Джонса
		DeleteAttribute(&locations[FindLocation("SentJons_town")], "reload.l7.close_for_night");
		// <--
	}
	if(!CheckAttribute(pchar,"questTemp.BigPatch_BugsFixer2"))
	{
		log_Testinfo("Отработал второй багфиксер Большого Патча");
		pchar.questTemp.BigPatch_BugsFixer2 = "true";
		// belamour -->
		sld = characterFromID("SentJons_Priest"); // священник в церковь
		LAi_RemoveLoginTime(sld); 
		if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "escape") // открыть тюрьму и бордель Сен Пьера
		{
			LocatorReloadEnterDisable("FortFrance_town", "reload_jail", false);
			LocatorReloadEnterDisable("FortFrance_town", "reload91", false);
		}
		if (pchar.questTemp.Mtraxx == "full_complete_end" || pchar.questTemp.Mtraxx == "fail") // убрать остатки пиратов Тесака из Бастиона
		{
			int i;
			for (i=1; i<=15; i++)
			{
				if (GetCharacterIndex("Mtr_CartahenaFort3Pirate_"+i) == -1) continue;
				sld = CharacterFromID("Mtr_CartahenaFort3Pirate_"+i); 
				sld.lifeday = 0; 
			}
		}
		// <-- belamour
		
		// mitrokosta фикс регаты без НИ
		if (!CheckAttribute(pchar, "questTemp.Regata") && CheckAttribute(pchar, "quest.Regata_PU")) {
			pchar.quest.Regata_PU.over = "yes";
		}
	}
	
	log_Testinfo("Отработал третий багфиксер Большого Патча");
	DeleteAttribute(pchar,"questTemp.BigPatch_BugsFixer");
	DeleteAttribute(pchar,"questTemp.BigPatch_BugsFixer2");
	if(CheckAttribute(pchar, "ItemsFix_Pistol2")) DeleteAttribute(pchar,"ItemsFix_Pistol2");
	// belamour уменьшить урон дробовику
	ref gun = ItemsFromID("pistol2");
	string sAttr = "t1";
	gun.type.(sAttr).multidmg = 1;
	gun.type.(sAttr).DmgMin_NC		= 30.0;
	gun.type.(sAttr).DmgMax_NC		= 80.0;
	gun.type.(sAttr).DmgMin_C		= 10.0;
	gun.type.(sAttr).DmgMax_C		= 50.0;
	// гауда
	gun = ItemsFromID("howdah");
	sAttr = "t1";
	gun.type.(sAttr).DmgMin_NC		= 25.0;
	gun.type.(sAttr).DmgMax_NC		= 70.0;
	gun.type.(sAttr).DmgMin_C		= 15.0;
	gun.type.(sAttr).DmgMax_C		= 40.0;
	sAttr = "t2";
	gun.type.(sAttr).ChargeSpeed    = 30.0;
	
	if (!CheckAttribute(pchar, "BigPatchControlReset")) {
		ControlsInit(GetTargetPlatform(),false); // mitrokosta принудительный сброс настроек
	}
}
