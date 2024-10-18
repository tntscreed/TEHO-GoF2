#include "scripts\ColonyUpgrades.c"

#define COLONY_POPULATION_LIMIT_1	5000
#define COLONY_POPULATION_LIMIT_2	10000
#define COLONY_POPULATION_LIMIT_3	20000
#define COLONY_POPULATION_LIMIT_4	50000

extern void InitColonies();

void ColoniesInit()
{
	if(LoadSegment("Colonies\Colonies_init.c"))
	{
		InitColonies();
		UnloadSegment("Colonies\Colonies_init.c");
	}
}
 
int FindColony(string sColony)
{
	for (int i=0; i<MAX_COLONIES; i++)
	{
		if(Colonies[i].id == sColony)
		{
			return i;
		}
	}
	
	return -1;
}

ref GetColonyByIndex(int iColony);
{
	return &Colonies[iColony];
}

// Warship -->
ref GetColonyRefByID(string sColony)
{
	return GetColonyByIndex(FindColony(sColony));
}

int GetDistanceToColony2D(string _sColony) // Дистанция до колонии
{
	ref rColony = GetColonyRefByID(_sColony);
	string sColonyIslandID = rColony.Island;
	string sColonyTown = _sColony + "_town";

	if(_sColony == "FortOrange") sColonyTown = "Shore36";
	if(_sColony == "LaVega") sColonyTown = "LaVega_Port";
	
//	float X1 = makefloat(worldMap.playerShipX)+1000;
//	float Z1 = -makefloat(worldMap.playerShipZ)+980;
        float X1, Z1;
	if(IsEntity(&worldMap))
	{
		X1 =  stf(worldMap.playerShipX);
		Z1 = -stf(worldMap.playerShipZ);
	}
	else
	{
		X1 =  GetSeaShipX(stf(pchar.Ship.Pos.X))+1000;
		Z1 = -GetSeaShipZ(stf(pchar.Ship.Pos.Z))+1000;
	}
	float X2 = makefloat(worldMap.islands.(sColonyIslandID).(sColonyTown).position.x)+1000;
	float Z2 = -makefloat(worldMap.islands.(sColonyIslandID).(sColonyTown).position.z)+1000;
	
	return makeint(GetDistance2D(X1, Z1, X2, Z2));
}

// Jason: функция возвращает id маяка на текущем острове. Работает только в городских локациях.
string Colony_GetLighthouseId(string _colony) 
{
	string sMayak;
	int imay;
	int iColony = FindColony(_colony);
	ref rCol = &Colonies[iColony];
	if(CheckAttribute(rCol, "mayak"))
	{
		imay = sti(rCol.mayak);
		sMayak = "mayak"+imay;
		log_Testinfo(sMayak);
	}
	else
	{
		log_Testinfo("Lighthouse not found");
		sMayak = "";
	}
	return sMayak;
}
// <--

void SetUpgradesForColony(int i)
{
	if(colonies[i].nation != "none")
	{
		colonies[i].colonylevel = rand(iColonyState - 1) + 1;

		if(sti(colonies[i].colonylevel) > 0)
		{
			colonies[i].fort = 1;
			colonies[i].shipyard = 1;
			colonies[i].wheatfield = 1;
			colonies[i].fishingpier = 1;
			colonies[i].mill = 1;
		}
		if(sti(colonies[i].colonylevel) > 1)
		{
			colonies[i].fort = 2;
			colonies[i].shipyard = 2;
			colonies[i].huts = 1; 
			colonies[i].storehouse = 1;
		}
		if(sti(colonies[i].colonylevel) > 2)
		{		
			colonies[i].fort = 3;
			colonies[i].shipyard = 3;
			colonies[i].church = 1;

			colonies[i].huts = 1; 
			colonies[i].storehouse = 1;
		}
		
		if(sti(colonies[i].colonylevel) > 3)
		{
			colonies[i].academy = 1; 
			colonies[i].expedition = 0;
			colonies[i].church = 1;
		}

		int iMoneyForColony = sti(colonies[i].money);

		BuildUpgrade(i, UPGRADE_PIER, false);
		BuildUpgrade(i, UPGRADE_MILL, false);
		BuildUpgrade(i, UPGRADE_SHIPYARD, false);
		BuildUpgrade(i, UPGRADE_HUTS, false);
		BuildUpgrade(i, UPGRADE_ACADEMY, false);
		BuildUpgrade(i, UPGRADE_STOREHOUSE, false);
		BuildUpgrade(i, UPGRADE_CHURCH, false);
		BuildFortUpgrade(i);
		
		colonies[i].money = iMoneyForColony;
	}
}


void SetUpgrades()
{
	for(int i = 0; i < MAX_COLONIES; i++)
	{
		SetUpgradesForColony(i);
	}
		
}

void CreateColonyPopulation()
{
	ColonyUpgradesInit();
	SetUpgrades();
	FillColoniesInfo();
	for(int i = 0; i< MAX_COLONIES; i++)
	{		
		if (colonies[i].nation != "none" || colonies[i].id == "IslaMona")
		{
			switch (colonies[i].colonylevel)
			{
				case "0":
					colonies[i].population = 0;
					colonies[i].money = 0;
				break;
				
				case "1":
					colonies[i].population = 500+rand(250);
					colonies[i].money = 5000+rand(2500);
				break;

				case "2":
					colonies[i].population = 750+rand(500);
					colonies[i].money = 7500+rand(5000);
				break;

				case "3":
					colonies[i].population = 1000+rand(1000);
					colonies[i].money = 10000+rand(10000);
				break;

				case "4":
					colonies[i].population = 3000+rand(3000);
					colonies[i].money = 20000+rand(20000);
				break;
			}
		}
		colonies[i].population = sti(colonies[i].population) + 100 * iColonyState;
		colonies[i].money = sti(colonies[i].money) + 1000 * iColonyState;

		colonies[i].crew = makeint(sti(colonies[i].population)/10.0);
		colonies[i].crew.experience = 1;
	}
}

int GetGovernorOfColony(string sColony)
{
	int iColony = FindColony(sColony);
	if(iColony == -1) return -1;

	return sti(colonies[iColony].commander);
}

int RemoveGovernor(string sColony)
{
	int iColony = FindColony(sColony);
	if(iColony == -1)
	{
		Trace("RemoveGovernor: Colony not found: " + sColony);
		return -1;
	}

	int iOldGov = GetGovernorOfColony(sColony);

	if(iOldGov == -1)
	{
		Trace("RemoveGovernor: Governor not found: " + sColony);
		return -1;
	}

	characters[iOldGov].city = "none";
	characters[iOldGov].location = "none";
	characters[iOldGov].location.group   = "none";
	characters[iOldGov].location.locator = "none";
	characters[iOldGov].location.mayor = "none";
	DeleteAttribute(&characters[iOldGov], "mayor");

	DeleteAttribute(&colonies[iColony], "commander");

	return iOldGov;
}

int PlayerSetGovernor(aref chr, string sColony)
{
	RemoveGovernor(sColony);

	int iColony = FindColony(sColony);

	Colonies[iColony].nation = PIRATE;
	Colonies[iColony].capture_flag = 1;

	int iChar = GetCharacterIndex(chr.id);

	characters[iChar].from_sea = colonies[iColony].from_sea; // для захвата с суши
    characters[iChar].Default  = characters[iChar].location;  // чтоб сухопутные города вернули население
    characters[iChar].Default.BoardLocation = colonies[iColony].Default.BoardLocation;
    characters[iChar].Mayor = true; // признак мэра

	colonies[iColony].commander = iChar;

	//chr.id = sColony + "_Mayor"; // Might not be needed, might break some things
	chr.city = sColony;
	LAi_SetCurHPMax(chr);

	ReturnMayorPosition(chr);
	LAi_LoginInCaptureTown(chr, true);

	PlayerSetFortCommander(sColony, iChar);

	return iChar;
}

int PlayerSetFortCommander(string sColony, int iGovernor)
{
	int iColony = FindColony(sColony);
	if(iColony == -1) return -1;

	int iChar = iGovernor;

	if (CheckAttribute(&colonies[iColony], "HasNoFort"))
	{
        if (iChar != -1)
        {
			characters[iChar].Default.Crew.Quantity    = 1900;
			characters[iChar].Default.Crew.MinQuantity = 1200;
			characters[iChar].Default.nation = characters[iChar].nation;
		}
		return true;
	}

	ref newfortcommander = GetCharacter(NPC_GenerateCharacter("PlayerNewFortCommander_" + sColony, "panhandler_"+(rand(5)+1), "man", "man", 5, PIRATE, -1, false, "slave")); // TODO: obviously change
	ref fortcommander = GetCharacter(GetCharacterIndex(sColony + " Fort Commander")); // TODO: Change to "Player X Fort Commander" system.

	CreateFortCommander(fortcommander, newfortcommander);

	int iFortChar = GetCharacterIndex(newfortcommander);
	return iFortChar;
}

void PlayerCaptureColony(string sColony)
{
	SetCaptureTownByHero(sColony);
	
	/*
	pchar.quest.waithours = 47;
	DoQuestFunctionDelay("WaitNextHours", 0.1);

	UnloadLocation(&locations[FindLocation(sColony + "_town")]);
	LoadLocation(&locations[FindLocation(sColony + "_town")]);
	*/
}

bool PlayerHasColonies()
{
	for(int i = 0; i < MAX_COLONIES; i++)
	{
		if(CheckAttribute(&colonies[i], "capture_flag") && sti(colonies[i].capture_flag) == 1)
		{
			return true;
		}
	}
	return false;
}