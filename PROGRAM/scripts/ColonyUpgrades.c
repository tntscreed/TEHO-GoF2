#include "colonies\colonyupgradesinit.c"

void CheckColonyUpgrades()
{
	int i = rand(MAX_COLONIES-1);
	int iStep = 1;

	if(Colonies[i].nation != "none")
	{
		int iUpgradeType = rand(MAX_UPGRADES);

		switch(iUpgradeType)
		{
			case UPGRADE_WHEAT:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_WHEAT, true);
					// GenerateRumour("colony_upgrade", UPGRADE_WHEAT, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_PIER:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_PIER, true);
					//GenerateRumour("colony_upgrade", UPGRADE_PIER, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_MILL:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_MILL, true); 
					//GenerateRumour("colony_upgrade", UPGRADE_MILL, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_SHIPYARD:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_SHIPYARD, true);
					//GenerateRumour("colony_upgrade", UPGRADE_SHIPYARD, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_HUTS:
				if(CheckForUpdate(iUpgradeType,i))
				{
					colonies[i].crew.experience = sti(colonies[i].crew.experience) + sti(ColonyUpgrades[UPGRADE_HUTS].crewexpmodifier);
					iStep = BuildUpgrade(i, UPGRADE_HUTS, true);
					//GenerateRumour("colony_upgrade", UPGRADE_HUTS, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_ACADEMY:
				if(CheckForUpdate(iUpgradeType,i))
				{
					colonies[i].crew.experience = sti(colonies[i].crew.experience) + sti(ColonyUpgrades[UPGRADE_ACADEMY].crewexpmodifier);
					iStep = BuildUpgrade(i, UPGRADE_ACADEMY, true);
					//GenerateRumour("colony_upgrade", UPGRADE_ACADEMY, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_STOREHOUSE:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_STOREHOUSE, true);
					//GenerateRumour("colony_upgrade", UPGRADE_STOREHOUSE, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_FORT:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildFortUpgrade(i); 
					//GenerateRumour("colony_upgrade", UPGRADE_FORT, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_CHURCH:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_CHURCH, true);
					//GenerateRumour("colony_upgrade", UPGRADE_CHURCH, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_EXPEDITION:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_EXPEDITION, true);
					//GenerateRumour("colony_upgrade", UPGRADE_EXPEDITION, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_GOLDMINES:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_GOLDMINES, true);
					//GenerateRumour("colony_upgrade", UPGRADE_GOLDMINES, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;

			case UPGRADE_SILVERMINES:
				if(CheckForUpdate(iUpgradeType,i))
				{
					iStep = BuildUpgrade(i, UPGRADE_SILVERMINES, true);
					//GenerateRumour("colony_upgrade", UPGRADE_SILVERMINES, i, iStep); // TODO: reimplement with SD:TEHO system
				}
			break;
		}
	}
}

void BuildFortUpgrade(int iColony)
{
	string sColony = colonies[iColony].id;

	int iFortProgress = sti(colonies[iColony].fort);

	string sFortCommander = sColony + " Fort Commander";
	string sPlayerFortCommander = sColony + " Player Fort Commander";

	switch(iFortProgress)
	{
		case 1:
			
		break;
	}
}

bool CheckForUpdate(int iUpgradeType, int iColony)
{
	aref aUpgrades, rUpgrade;

	string sUpgrade = colonyupgrades[iUpgradeType].id;

	int iCurrentLevel = sti(colonies[iColony].(sUpgrade));

	int iNextLevel;

	if(iCurrentLevel < sti(ColonyUpgrades[iUpgradeType].maxlevel))
	{
		iNextLevel = iCurrentLevel + 1;
	}
	else
	{
		return false;//�������� ��������
	}

	if(iNextLevel == 0)
	{
		return false;//���������� ��������� ������ (��������� �������� -1)
	}

	string sStep = "l"+iNextLevel;
	string sResult;

	makearef(aUpgrades, ColonyUpgrades[iUpgradeType].requred.(sStep));
	int iStep = GetAttributesNum(aUpgrades);

	for(int i=0; i <iStep; i++)
	{
		rUpgrade = GetAttributeN(aUpgrades, i);

		sResult = GetAttributeName(rUpgrade);

		if(sti(colonies[iColony].(sResult)) < sti(ColonyUpgrades[iUpgradeType].requred.(sStep).(sResult)))
		{
			return false;
		}
		if(sti(colonies[iColony].money) < sti(ColonyUpgrades[iUpgradeType].(sStep).money))
		{
			return false;
		}
	}

	if(sti(colonies[iColony].colonylevel) < sti(ColonyUpgrades[iUpgradeType].colonylevel))
	{
		return false;
	}

	return true;
}

int BuildUpgrade(int iColony, int iUpgrade, bool isRealBuild)
{
	
	string sLocation = colonies[iColony].id + "_town";
	int iLocation = FindLocation(sLocation);

	string sBuildModel = ColonyUpgrades[iUpgrade].id;

	if(isRealBuild == true)
	{
		colonies[iColony].(sBuildModel) = sti(colonies[iColony].(sBuildModel)) + 1;
	}

	//if(sti(ColonyUpgrades[iUpgrade].model) == 1)
	if(false)
	{
		
		bool isBuild = false;
		int iBuildStep = 1;

		if(sti(colonies[iColony].(sBuildModel)) > 0)
		{
			isBuild = true;
			iBuildStep = sti(colonies[iColony].(sBuildModel));
		}

		if(isBuild == true)
		{
			Locations[iLocation].models.always.(sBuildModel) = "..\..\upgrades/" + sBuildModel + iBuildStep;
			trace("ColonyUpgrades.c: BuildUpgrade: sBuildModel:" + sBuildModel + ", iBuildStep" + iBuildStep + " ; location: " + Locations[iLocation].id + " ; " + Locations[iLocation].models.always.(sBuildModel));
		}
		else
		{
			Locations[iLocation].models.always.(sBuildModel) = "..\..\upgrades/" + sBuildModel + "_destroyed";
			trace("ColonyUpgrades.c: BuildUpgrade: sBuildModel:" + sBuildModel + " ; location: " + Locations[iLocation].id + " ; " + " ; " + Locations[iLocation].models.always.(sBuildModel));
		}
		Locations[iLocation].models.always.(sBuildModel).locator.group = "Upgrades";
		Locations[iLocation].models.always.(sBuildModel).locator.name = sBuildModel;
		
		Locations[iLocation].models.always.(sBuildModel).tech = "dLightModel";
		
		if(iUpgrade == UPGRADE_SHIPYARD)
		{
			string sShipyardLocation = colonies[iColony].id + "_shipyard";
			int iShipyardLocation = FindLocation(sShipyardLocation);
			string sNewString = "shipyard0" + colonies[iColony].(sBuildModel);
			Locations[iShipyardLocation].filespath.models = "locations/inside/" + sNewString;

			locations[iShipyardLocation].image = "loading/" + sNewString + ".tga";

			locations[iShipyardLocation].models.always.locators = sNewString + "_locators";
			locations[iShipyardLocation].models.always.shipyard = sNewString;
			locations[iShipyardLocation].models.day.charactersPatch = sNewString + "_patch";

			locations[iShipyardLocation].models.night.charactersPatch = sNewString + "_patch";

			locations[iShipyardLocation].models.always.window = sNewString + "_window";
			locations[iShipyardLocation].models.always.window.tech = "LocationWindows";
			locations[iShipyardLocation].models.always.window.level = 50;

			locations[iShipyardLocation].models.always.back = "..\inside_back";
		}
		

		string sTownLocation = colonies[iColony].id + "_town";
		int iTownLocation = FindLocation(sTownLocation);

		
		if(iUpgrade == UPGRADE_CHURCH && isBuild == true)
		{
			locations[iTownLocation].reload.l7.disable = false;
		}
		else
		{
			locations[iTownLocation].reload.l7.disable = true;
		}


		if(iUpgrade == UPGRADE_SHIPYARD && isBuild == true)
		{
			locations[iTownLocation].reload.l5.disable = false;
		}
		else
		{
			locations[iTownLocation].reload.l5.disable = true;
		}

		if(iUpgrade == UPGRADE_MILL && isBuild == true)
		{
			string sMovieModel = sBuildModel + "_movie";
			
			Locations[iLocation].models.always.(sMovieModel) = "..\..\upgrades/" + sMovieModel;
			Locations[iLocation].models.always.(sMovieModel).locator.group = "Upgrades";
			Locations[iLocation].models.always.(sMovieModel).locator.name = sMovieModel;

			Locations[iLocation].models.always.(sMovieModel).rotate.x = 0.0;
			Locations[iLocation].models.always.(sMovieModel).rotate.y = 0.0;
			Locations[iLocation].models.always.(sMovieModel).rotate.z = 1.0;
			Locations[iLocation].models.always.(sMovieModel).tech = "dLightModel";
		}
		
	}

	string sUpgrade = sBuildModel;

	colonies[iColony].(sUpgrade) = sti(colonies[iColony].(sUpgrade)) + 1;
	int iLevel = colonies[iColony].(sUpgrade);
	string sLevel = "l"+iLevel;
	if(isRealBuild)
	{
		colonies[iColony].money = sti(colonies[iColony].money) - sti(ColonyUpgrades[iUpgrade].(sLevel).money);
	}

	CheckForFirstLevelUp(iColony);
	CheckForSecondLevelUp(iColony);
	CheckForThirdLevelUp(iColony);
	return iLevel;
	
}

bool CheckForStoreHouseUpdate(int iColony)
{
	if(sti(colonies[iColony].storehouse) != 0)
	{
		return false;
	}

	if(sti(colonies[iColony].colonylevel) < sti(ColonyUpgrades[UPGRADE_STOREHOUSE].colonylevel))
	{
		return false;
	}

	if(sti(colonies[iColony].money) > sti(ColonyUpgrades[UPGRADE_STOREHOUSE].cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckForAcademyUpdate(int iColony)
{
	if(sti(colonies[iColony].academy) != 0)
	{
		return false;
	}

	if(sti(colonies[iColony].colonylevel) < sti(ColonyUpgrades[UPGRADE_ACADEMY].colonylevel))
	{
		return false;
	}

	if(sti(colonies[iColony].money) > sti(ColonyUpgrades[UPGRADE_ACADEMY].cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckForHutsUpdate(int iColony)
{
	if(sti(colonies[iColony].huts) != 0)
	{
		return false;
	}

	if(sti(colonies[iColony].colonylevel) < sti(ColonyUpgrades[UPGRADE_HUTS].colonylevel))
	{
		return false;
	}

	if(sti(colonies[iColony].money) > sti(ColonyUpgrades[UPGRADE_HUTS].cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckForWheatUpdate(int iColony)
{
	if(sti(colonies[iColony].wheatfield) != 0)
	{
		return false;
	}

	if(sti(colonies[iColony].money) > sti(ColonyUpgrades[UPGRADE_WHEAT].cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckForPierUpdate(int iColony)
{
	if(sti(colonies[iColony].fishingpier) != 0)
	{
		return false;
	}

	if(sti(colonies[iColony].money) > sti(ColonyUpgrades[UPGRADE_PIER].cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckForMillUpdate(int iColony)
{
	if(sti(colonies[iColony].mill) != 0)
	{
		return false;
	}

	if(sti(colonies[iColony].money) > sti(ColonyUpgrades[UPGRADE_MILL].cost))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CheckForFirstLevelUp(int iColony)
{
	/*if(sti(colonies[iColony].fort) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].shipyard) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].wheatfield) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].fishingpier) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].mill) < 1)
	{
		return;
	}

	if(sti(colonies[iColony].colonylevel) < 2)
	{
		colonies[iColony].colonylevel = 2;
	}*/

	if(!CheckAttribute(&colonies[iColony], "fort") || sti(colonies[iColony].fort) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "shipyard") || sti(colonies[iColony].shipyard) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "wheatfield") || sti(colonies[iColony].wheatfield) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "fishingpier") || sti(colonies[iColony].fishingpier) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "mill") || sti(colonies[iColony].mill) < 1)
	{
		return;
	}

	if(!CheckAttribute(&colonies[iColony], "colonylevel") || sti(colonies[iColony].colonylevel) < 2)
	{
		colonies[iColony].colonylevel = 2;
	}
}

void CheckForSecondLevelUp(int iColony)
{
	/*if(sti(colonies[iColony].huts) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].storehouse) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].fort) < 2)
	{
		return;
	}
	if(sti(colonies[iColony].shipyard) < 2)
	{
		return;
	}

	if(sti(colonies[iColony].colonylevel) < 3)
	{
		colonies[iColony].colonylevel = 3;
	}*/

	if(!CheckAttribute(&colonies[iColony], "huts") || sti(colonies[iColony].huts) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "storehouse") || sti(colonies[iColony].storehouse) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "fort") || sti(colonies[iColony].fort) < 2)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "shipyard") || sti(colonies[iColony].shipyard) < 2)
	{
		return;
	}

	if(!CheckAttribute(&colonies[iColony], "colonylevel") || sti(colonies[iColony].colonylevel) < 3)
	{
		colonies[iColony].colonylevel = 3;
	}
}

void CheckForThirdLevelUp(int iColony)
{
	/*if(sti(colonies[iColony].church) < 1)
	{
		return;
	}
	if(sti(colonies[iColony].fort) < 3)
	{
		return;
	}
	if(sti(colonies[iColony].shipyard) < 3)
	{
		return;
	}

	if(sti(colonies[iColony].colonylevel) < 4)
	{
		colonies[iColony].colonylevel = 4;
	}*/

	if(!CheckAttribute(&colonies[iColony], "church") || sti(colonies[iColony].church) < 1)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "fort") || sti(colonies[iColony].fort) < 3)
	{
		return;
	}
	if(!CheckAttribute(&colonies[iColony], "shipyard") || sti(colonies[iColony].shipyard) < 3)
	{
		return;
	}

	if(!CheckAttribute(&colonies[iColony], "colonylevel") || sti(colonies[iColony].colonylevel) < 4)
	{
		colonies[iColony].colonylevel = 4;
	}
}



bool CheckForFortUpgrade(int iColony)
{		
	int iCannonType;
	
	int iminCharacter = GetCharacterIndex("Bridgetown Fort Commander"); // vex TODO: I don't even know
	int imaxCharacter = GetCharacterIndex("SanAndres Fort Commander");
	
	int i = rand(iMaxCharacter-iMinCharacter) + iMinCharacter;
	
	characters[i].rank = sti(characters[i].rank)+rand(2);
	
	string sColony = characters[i].location;
	
	if (Colonies[FindColony(sColony)].nation != PIRATE)
	{
		//LAi_CreateCommander(&characters[i]); // TODO: investigate what this did
		iCannonType = sti(characters[i].Fort.Cannons.Type.2) + 1;
		if (iCannonType < 10)
		{
			characters[i].Fort.Cannons.Type.2 = iCannonType;
			characters[i].Fort.Cannons.Type.1 = iCannonType;
			//GenerateRumour("cannons_up", FindIsland(sColony), iCannonType, 0) // TODO: rewrite with SD:TEHO system
		}
	}

	return true;
}

void ColonyPopulationUp()
{
	int iColonyLevel, iLeadership;
	int iWheatField, iFishingPier, iMill;
	float fPop = 0.0;
	int iPopGrow = 0;
	ref chr;
	float fpluscrewquantity = 0.0;
	for(int i = 0; i< MAX_COLONIES; i++)
	{
		if (colonies[i].nation != "none" || colonies[i].id == "IslaMona")
		{
			iColonyLevel = sti(colonies[i].colonylevel);
			if(iColonyLevel == 1 && colonies[i].population > COLONY_POPULATION_LIMIT_1)
			{
				return;
			}
			if(iColonyLevel == 2 && colonies[i].population > COLONY_POPULATION_LIMIT_2)
			{
				return;
			}
			if(iColonyLevel == 3 && colonies[i].population > COLONY_POPULATION_LIMIT_3)
			{
				return;
			}
			if(iColonyLevel == 4 && colonies[i].population > COLONY_POPULATION_LIMIT_4)
			{
				return;
			}

			iWheatField = sti(colonies[i].wheatfield);
			iFishingPier = sti(colonies[i].fishingpier);
			iMill = sti(colonies[i].mill);

			if(iWheatField != 0)
			{
				iWheatField = rand(sti(ColonyUpgrades[UPGRADE_WHEAT].population_modifier));
			}

			if(iFishingPier != 0)
			{
				iFishingPier = rand(sti(ColonyUpgrades[UPGRADE_PIER].population_modifier));
			}

			if(iMill != 0)
			{
				iWheatField = rand(sti(ColonyUpgrades[UPGRADE_MILL].population_modifier));
			}

			switch (iColonyLevel)
			{
				case 4:
					iPopGrow = rand(20);
				break;

				case 3:
					iPopGrow = rand(15);
				break;
				
				case 2:
					iPopGrow = rand(10);
				break;
				
				case 1:
					iPopGrow = rand(5);
				break;

				case 0:
					iPopGrow = 0;
				break;
			}
			if(colonies[i].id == "IslaMona")
			{
				iPopGrow = rand(15);
			}

			fPop = iPopGrow;
			if(sti(colonies[i].capture_flag) == 1)
			{
				fPop = fPop + 0.5;
			}

			fPop = fPop + iWheatField + iFishingPier + iMill;
			
			colonies[i].population = sti(colonies[i].population) + fPop;

			colonies[i].crew.sailors = stf(colonies[i].crew.sailors) + fPop / 4;
			colonies[i].crew.soldiers = stf(colonies[i].crew.soldiers) + fPop / 3;
			colonies[i].crew.musketeers = stf(colonies[i].crew.musketeers) + fPop / 10;
			colonies[i].crew.cannoners = stf(colonies[i].crew.cannoners) + fPop / 5;

			

			if(GetCharacterIndex(Colonies[i].commander) != -1)
			{
				chr = CharacterFromID(Colonies[i].commander);

				iLeadership = GetSummonSkillFromName(chr, SKILL_LEADERSHIP);
				fPop = fPop + rand(iLeadership / 2) - rand(iLeadership / 2);
				if(fPop > 0.0)
				{
					fpluscrewquantity = fPop / 4.0;

					// 10% �� �������� ��������� ���� ����� �� ������ + ����� �� ����������
					fpluscrewquantity = fpluscrewquantity * (0.1 + (0.00125 * stf(Colonies[i].loyality)) + (0.00125 * stf(Colonies[i].morale)));
					if(fpluscrewquantity > fPop / 4.0)
					{
						fpluscrewquantity = fPop /4.0;
					}

					chr.ship.crew.BoardingCrew = stf(chr.ship.crew.BoardingCrew) + fpluscrewquantity;
					if(stf(chr.ship.crew.BoardingCrew) > stf(ShipsTypes[SHIP_FORT].BoardingCrew))
					{
						chr.ship.crew.BoardingCrew = ShipsTypes[SHIP_FORT].BoardingCrew;
					}

					chr.ship.crew.GunnerCrew = stf(chr.ship.crew.GunnerCrew) + fpluscrewquantity;
					if(stf(chr.ship.crew.GunnerCrew) > stf(ShipsTypes[SHIP_FORT].GunnerCrew))
					{
						chr.ship.crew.GunnerCrew = ShipsTypes[SHIP_FORT].GunnerCrew;
					}

					chr.ship.crew.SailorCrew = stf(chr.ship.crew.SailorCrew) + fpluscrewquantity;
					if(stf(chr.ship.crew.SailorCrew) > stf(ShipsTypes[SHIP_FORT].SailorCrew))
					{
						chr.ship.crew.SailorCrew = ShipsTypes[SHIP_FORT].SailorCrew;
					}

					chr.ship.crew.CannonerCrew = stf(chr.ship.crew.CannonerCrew) + fpluscrewquantity;
					if(stf(chr.ship.crew.CannonerCrew) > stf(ShipsTypes[SHIP_FORT].CannonerCrew))
					{
						chr.ship.crew.CannonerCrew = ShipsTypes[SHIP_FORT].CannonerCrew;
					}

					chr.ship.crew.quantity = stf(chr.ship.crew.BoardingCrew) + stf(chr.ship.crew.GunnerCrew) + stf(chr.ship.crew.SailorCrew) + stf(chr.ship.crew.CannonerCrew);

					if (sti(chr.ship.crew.quantity) > sti(ShipsTypes[SHIP_FORT].MaxCrew))
					{
						chr.ship.crew.quantity = sti(ShipsTypes[SHIP_FORT].MaxCrew);
					}
				}
			}
		}	
	}
}

void ColonyColonistsUp()
{
	int iColonies[MAX_COLONIES];
	int m = 0;
	
	for (int i =0; i < MAX_COLONIES; i++)
	{
		if (colonies[i].nation !="none" && colonies[i].disease != "1")
		{
			iColonies[m] = i;
			m++;
		}
	}
	
	m = rand(m-1);
	
	int iColonistsQuantity = rand(100) + rand(100);
	Colonies[m].population = sti(Colonies[m].population) + iColonistsQuantity;
	//colonies[m].crew = sti(colonies[m].crew) + makeint(iColonistsQuantity/10.0);
	colonies[m].crew.sailors = sti(colonies[m].crew.sailors) + makeint(iColonistsQuantity/10);
	colonies[m].crew.soldiers = sti(colonies[m].crew.soldiers) + makeint(iColonistsQuantity/10);
	colonies[m].crew.musketeers = sti(colonies[m].crew.musketeers) + makeint(iColonistsQuantity/20);
	colonies[m].crew.cannoners = sti(colonies[m].crew.cannoners) + makeint(iColonistsQuantity/15);
	
	//GenerateRumour("colony_colonists", m, sti(colonies[m].nation), 0); // TODO: rewrite with SD:TEHO system
	
	ref rStore = &Stores[FindStore(Colonies[m].id)];
		
	SetStoreGoods(rStore, GOOD_FOOD, 0);
	SetStoreGoods(rStore, GOOD_WHEAT, 0);
	
	Colonies[m].colonists = iColonistsQuantity/10;
}

/*void UpdateCrewInColonies()
{
	int iSailorsQ, iSoldiersQ, iMusketeersQ, iCannonersQ;

	for(int i = 0; i < MAX_COLONIES; i++)
	{
		//iCrewQ = sti(colonies[i].crew);
		iSailorsQ = sti(colonies[i].crew.sailors);
		iSoldiersQ = sti(colonies[i].crew.soldiers);
		iMusketeersQ = sti(colonies[i].crew.musketeers);
		iCannonersQ = sti(colonies[i].crew.cannoners);

		if(iSailorsQ < sti(colonies[i].population)/10)
		{
			iSailorsQ = iSailorsQ + rand(5);
			colonies[i].crew.sailors = iSailorsQ;
		}
		if(iSoldiersQ < sti(colonies[i].population)/10)
		{
			iSoldiersQ = iSoldiersQ + rand(5);
			colonies[i].crew.soldiers = iSoldiersQ;
		}
		if(iMusketeersQ < sti(colonies[i].population)/20)
		{
			iMusketeersQ = iMusketeersQ + rand(5);
			colonies[i].crew.musketeers = iMusketeersQ;
		}
		if(iCannonersQ < sti(colonies[i].population)/15)
		{
			iCannonersQ = iCannonersQ + rand(5);
			colonies[i].crew.cannoners = iCannonersQ;
		}
	}
}*/


int FindUpgrade(string sName)
{
	for(int i = 0; i < MAX_UPGRADES; i++)
	{
		if(ColonyUpgrades[i].id == sName)
		{
			return i;
		}
	}
	return -1;
}

string GetUpgradeNameFromColony(string sName, int iColony)
{
	int iUpgrade = FindUpgrade(sName);

	int iLevel = sti(colonies[iColony].(sName));

	if(iLevel < 1 )
	{
		return "error! upgrade not builded";
	}

	string sResult = GetUpgradeName(iUpgrade, iLevel);

	return sResult;
}


string GetNextUpgradeNameFromColony(string sName, int iColony)
{
	int iUpgrade = FindUpgrade(sName);

	int iLevel = sti(colonies[iColony].(sName));


	iLevel = iLevel + 1;

	if(iLevel > sti(ColonyUpgrades[iUpgrade].maxlevel))
	{
		iLevel = sti(ColonyUpgrades[iUpgrade].maxlevel);
	}

	if(iLevel < 1 )
	{
		iLevel = 1;
	}

	string sResult = GetUpgradeName(iUpgrade, iLevel);

	return sResult;
}

string GetUpgradeName(int iUpgrade, int iLevel)
{
	string sLevelText = "l"+iLevel;

	string sResult;

	if(CheckAttribute(&ColonyUpgrades[iUpgrade],sLeveltext + ".name"))
	{
		sResult = ColonyUpgrades[iUpgrade].(sLeveltext).name;
	}
	else
	{
		sResult = "-1";
	}

	return sResult;
}

string GetUpgradeText(int iUpgrade, int iColony)
{
	string sName = ColonyUpgrades[iUpgrade].id;

	int iLevel = sti(colonies[iColony].(sName));
	
	string sResult = GetUpgradeRealText(iUpgrade, iLevel);

	return sResult;
}

string GetUpgradeRealText(int iUpgrade, int iLevel)
{
	if(iLevel < 1)
	{
		iLevel = 1;
	}

	string sLevelText = "l"+iLevel;

	string sResult;

	if(CheckAttribute(&ColonyUpgrades[iUpgrade],sLeveltext + ".text"))
	{
		//sResult = ColonyUpgrades[iUpgrade].(sLeveltext).text;
		sResult = "Upgrade" + ColonyUpgrades[iUpgrade].id + iLevel;
		sResult = XI_ConvertString(sResult);
	}
	else
	{
		sResult = "-1";
	}

	return sResult;
}

string GetUpgradeNextText(int iUpgrade, int iColony)
{
	string sName = ColonyUpgrades[iUpgrade].id;

	int iLevel = sti(colonies[iColony].(sName));
	iLevel = iLevel + 1;

	string sResult = GetUpgradeRealText(iUpgrade, iLevel);

	if(sResult == "-1")
	{
		iLevel = iLevel - 1;
		sResult = GetUpgradeRealText(iUpgrade, iLevel);
	}

	return sResult;
}

bool CheckForCompletedUpgrade(int iUpgrade, int iColony)
{
	string sUpgrade = colonyupgrades[iUpgrade].id;

	if(sti(colonies[iColony].(sUpgrade)) > sti(ColonyUpgrades[iUpgrade].maxlevel)){
		trace("Max colony upgrade level exceeded: Colony: " + colonies[iColony].id + ", Upgrade: " + sUpgrade + ", Level: " + sti(colonies[iColony].(sUpgrade)) + ", Max level: " + sti(ColonyUpgrades[iUpgrade].maxlevel));
		colonies[iColony].(sUpgrade) = sti(ColonyUpgrades[iUpgrade].maxlevel);
	}

	if(sti(colonies[iColony].(sUpgrade)) == sti(ColonyUpgrades[iUpgrade].maxlevel))
	{
		return true;
	}
	return false;
}