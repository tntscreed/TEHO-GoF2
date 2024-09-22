/************************************************************************************************
                              belamour Альтернативный модификатор

HKT_ = быстрый переход 
HKE_ = мушкет и ХО
HKB_ = боеприпас

*************************************************************************************************/

void HKT_Button(string sHKB) // быстрый переход
{
	int curLocIdx, i; 
	String locID, sCityID;
	bool bOk;
	
	curLocIdx = FindLoadedLocation();
	sCityID = Locations[curLocIdx].fastreload;
	locID = strcut(sHKB, 4 , strlen(sHKB)-1);
	// --> проверка запретов перехода
	bOk = true;
	if(LAi_group_IsActivePlayerAlarm()) bOk = false;
	if(!LAi_IsCharacterControl(pchar)) bOk = false;
	if(bDisableFastReload)	bOk = false;
	if(!IsEnableFastTravel()) bOk = false;
	if (chrDisableReloadToLocation) bOk = false;
	if (sHKB != "Fast_port" && !CheckFastJump(Locations[curLocIdx].id, sCityID + locID)) bOk = false;
	if (sHKB == "Fast_port" && !CheckFastJump(Locations[curLocIdx].id, pchar.location.from_sea)) bOk = false;
	if (!bBettaTestMode && bOk) // проверка города на враждебность
	{
		string sNation = Colonies[FindColony(loadedLocation.fastreload)].nation;
		if (sNation != "none")
		{
			i = sti(sNation);
			bOk = (GetNationRelation2MainCharacter(i) == RELATION_ENEMY) || GetRelation2BaseNation(i) == RELATION_ENEMY;
			if (bOk && (i != PIRATE))
			{
				bOk = false;
			}
			else
			{
				bOk = true;
			}
		}
	}
	// <--
	if(bOk)
	{
		if (sHKB == "Fast_port")
			PlayerFastTravel(curLocIdx, pchar.location.from_sea, "reload1");
			else PlayerFastTravel(curLocIdx, sCityID + locID, "");
	}	
	if(pchar.location == sCityID + locID) {Log_info(XI_ConvertString("You are already there")); PlaySound("interface\knock.wav");}
	if (sHKB == "Fast_port" && pchar.location == pchar.location.from_sea) {Log_info(XI_ConvertString("You are already there")); PlaySound("interface\knock.wav");}
}	

void HKE_Button(string sHKB) // мушкет и клинки
{
	string sGun, sItem, sBlade, BladeType, BladeInfo;
	ref rItem;
	aref aGun, arItems; 
	bool bOk;
	int i, p, iItemsNum; 

	int n = 0;
	
	BladeType = strcut(sHKB, 3 , strlen(sHKB)-1);
	sBlade = ""; 
	bOk = true;
	if(loadedLocation.type == "underwater") bOk = false;
	if(!LAi_IsCharacterControl(pchar)) bOk = false;
	
	if(bOk)
	{
		if (sHKB == "HK_Musket")
		{
			sGun = FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE);
			Items_FindItem(sGun, &aGun);
			if(sGun != "" && HasSubStr(aGun.id, "mushket") && IsCharacterPerkOn(pchar,"Gunman") && CanEquipMushketOnLocation(PChar.Location))
			{
				if(!CheckAttribute(PChar, "IsMushketer")) 
				{
					DoQuestCheckDelay("pchar_fast_mushket_fade", 0.8);
					DoQuestCheckDelay("pchar_fast_mushket", 1.5);
					LAi_SetActorType(pchar);
					pchar.GenQuest.MusId = aGun.id;
					log_info("Selected gun: "+GetConvertStr(aGun.name, "ItemsDescribe.txt"));
					PlaySound("PEOPLE\clothes1.wav");
				}
				else
				{
					Log_Info("Musket already equipped");
					PlaySound("interface\knock.wav");
				}
			}
			else
			{
				// предупреждалки
				if(!IsCharacterPerkOn(pchar,"Gunman")) Log_Info("In order to operate muskets you need a perk");
				if(!CanEquipMushketOnLocation(PChar.Location)) Log_Info("Cannot operate muskets"); // сейчас по факту это проверка модели героя
				if(pchar.model == "protocusto") Log_Info("Take off the diving suit");
				if(!HasSubStr(aGun.id, "mushket")) Log_Info("No musket in inventory");
				PlaySound("interface\knock.wav");
			}
		}
		else
		{
			makearef(arItems, pchar.items);
			iItemsNum = GetAttributesNum(arItems);
			for(i=0; i<iItemsNum; i++)
			{
				sItem = GetAttributeName(GetAttributeN(arItems, i));
				rItem = ItemsFromID(sItem);
				if(!CheckAttribute(rItem, "groupID")) continue;
				if(rItem.groupID != BLADE_ITEM_TYPE) continue;
				if(sItem != "" && rItem.groupID == BLADE_ITEM_TYPE && rItem.FencingType == BladeType) 
				{
					p = BladeNum(BladeType);		 
					n++;
					if(n == p-1)
					{
						sBlade = sItem; 
						BladeInfo = rItem.name; 
						break;
					}
					sBlade = sItem; 
					BladeInfo = rItem.name;
				}
			}
			if(sBlade != "")
			{
				if(CheckAttribute(pchar, "IsMushketer")) 
				{
					DoQuestCheckDelay("pchar_fast_mushket_fade", 0.1);
					DoQuestCheckDelay("pchar_fast_mushket", 0.6);
					LAi_SetActorType(pchar);
					PlaySound("PEOPLE FIGHT\Blade_Take_Out_01.wav");
					pchar.GenQuest.MusId = sBlade;
				}
				else
				{
					EquipCharacterbyItem(pchar, sBlade); 
					PlaySound("PEOPLE FIGHT\Blade_Take_In_0"+(rand(2)+1) +".wav"); 
				} 
				log_info("Selected weapon: "+GetConvertStr(BladeInfo, "ItemsDescribe.txt"));
			}
			else
			{
				Log_Info("No blade of this type found in inventory");
				PlaySound("interface\knock.wav");
			}
		}
	}		
}		

void HKB_Button(string sHKB) // боеприпас
{
	string BulletType = strcut(sHKB, 3 , strlen(sHKB)-1);
	LAi_SetCharacterUseBullet(pchar, BulletType);
	LAi_GunSetUnload(pchar);
	log_info("Ammo type selected - "+GetConvertStr("itmname_"+BulletType, "ItemsDescribe.txt")+"");
	
	// предупреждающие логи
	string GunBulletType = LAi_GetCharacterBulletType(pchar);
	string GunPowder = LAi_GetCharacterGunpowderType(pchar);
	int iGunPowder = GetCharacterItem(pchar, GunPowder);
	bool bOk = false; 
	bool bok1 = false;
	if(GunPowder != ""  && iGunPowder > 0) bOk = true;
	if(GunPowder == "") bok1 = true;
	
	if(GunBulletType != "" && GunBulletType == BulletType) 
	{
		if(bOk || bOk1) PlaySound("People Fight\reload1.wav");
	}
	else PlaySound("interface\notebook.wav");
	if(GunBulletType != BulletType) log_info("Warning!!! Selected ammo type is incompatible with your current weapon");
	if(GunPowder != ""  && iGunPowder < 1) {log_info("Warning!!! No gunpowder in inventory"); PlaySound("interface\notebook.wav");}
}

int BladeNum(string Type)
{
	int qty = 0;
	string sItem;
	ref rItem;
	aref arItems; 
		  
	int i, iItemsNum; 
	
	makearef(arItems, pchar.items);
	iItemsNum = GetAttributesNum(arItems);
	for(i=0; i<iItemsNum; i++)
	{
		sItem = GetAttributeName(GetAttributeN(arItems, i));
		rItem = ItemsFromID(sItem);
		if(!CheckAttribute(rItem, "groupID")) continue;
		if(rItem.groupID != BLADE_ITEM_TYPE) continue;
		if(sItem != "" && rItem.groupID == BLADE_ITEM_TYPE && rItem.FencingType == Type) 
		{
			qty++;
			if(IsEquipCharacterByItem(pchar, rItem.id)) return qty;
		}
	}
	return qty;
}
