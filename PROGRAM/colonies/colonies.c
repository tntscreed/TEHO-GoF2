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