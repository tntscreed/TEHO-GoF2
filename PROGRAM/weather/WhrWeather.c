#include "weather\WhrUtils.c"
#include "weather\WhrLightning.c"
#include "weather\WhrRain.c"
#include "weather\WhrSea.c"
#include "weather\WhrSky.c"
#include "weather\WhrSun.c"
#include "weather\WhrTornado.c"
#include "weather\WhrAstronomy.c"
#include "weather\WhrGeneration.c"
#include "weather\WhrSeaPresets.c"

#define WIND_NORMAL_POWER		20.0	// 20.0
#define MAX_WEATHERS   35

object	Weather, WeatherParams, WhrCommonParams;
int		iNextWeatherNum = -1;
int		iCurWeatherNum = -1;
int		iBlendWeatherNum = -1;
int		iCurWeatherHour = -1;
bool	bCurWeatherStorm = false;
int		iTotalNumWeathers = 0;
string	sLightingPath = "day";
string	sLmLightingPath = "day";
string	sInsideBack = "";
int	sNewExecuteLayer, sNewRealizeLayer;
string	sCurrentFog;
float	fWeatherDelta = 0.0;
float	fWeatherAngle, fWeatherSpeed;
float	fFogDensity;
int		iShadowDensity[2];
int		iPrevWeather = -1;
int		sunIsShine = true;
bool	bWeatherLoaded = false;
bool	bWeatherIsNight = false;
bool	bWeatherIsLight = false;
bool	bWeatherIsRain = false;
bool	bWeatherIsStorm = false;
int wRain = 0;
int winds = 0;
int fog = 0;
int rWind, rRain, rFog;
float fWindA = 0.0;
float rWindA = 0.0;
float fSeaA;
float fSeaB;
int gWeatherInit = 1;
int goldRain, goldFog, oldWind;
float fWeatherAngleOld, fWeatherSpeedOld;
int fogBallast, rainBallast, windBallast;
float windABallast;
int curTime, minwind, maxwind;

// Values for overriding weather or setting it
// ----------------DO NOT CHANGE THESE VALUES HERE------------------------
float OWeatherAngle = -50.0;		 //Value between 0.0 and PIm2 - Determines the wind angle
float OWABallast = -50.0;			 //Value between 0.0 and the MAX defined in InternalSettings.h
int OFog = -50; 					 //Value between 0 and 20 - Determines fog density
int OFBallast = -50;				 //Value between 0 and the MAX defined in InternalSettings.h
int ORain = -50;					 //Value between 0 and 100 - Determines rain density and storm occurance
int ORBallast = -50;				 //Value between 0 and the MAX defined in InternalSettings.h
int OWind = -50;					 //Value between 0 and 30 - Determines the Wind speed
int OWBallast = -50;				 //Value between 0 and the MAX defined in InternalSettings.h
bool gWeatherOvrd = false;			 //This is the bool checked by the weather system, set to to if you've changed one of the above variables
//To set specific weather set the desired variables to the desired values in your code and set gWeatherOvrd to true the system takes care of the rest

object Weathers[MAX_WEATHERS];
object WeathersNH;  // Variable to use in NH generation

extern int InitWeather();

#event_handler("EWhr_GetWindAngle", "Whr_GetWindAngle");
#event_handler("EWhr_GetWindSpeed", "Whr_GetWindSpeed");
#event_handler("EWhr_GetShadowDensity", "Whr_GetShadowDensity");
#event_handler("EWhr_GetFogDensity", "Whr_GetFogDensity");
#event_handler("WeatherTimeUpdate", "Whr_TimeUpdate" );

void SetNextWeather(string sWeatherID)
{
	string sWeather = sWeatherID;
	if (sWeatherID == "Blue Sky" || sWeatherID == "Moon Night" || sWeatherID == "Red Sky") sWeather = "Clear";
	if (sWeatherID == "Day Storm")								sWeather = "Heavy Storm";
	if (sWeatherID == "alcove") sWeather = "inside";

	switch (sWeather)
	{
	case "Clear":
		wRain = 0;
		ORain = 0;
		ORBallast = 0;
		Fog = 0;
		OFog = 0;
		gWeatherOvrd = true;	// LDH make new weather in CreateWeatherEnvironment 17Feb09
		break;

	case "Cloudy":
		wRain = 60;		// clouds start at 50, overcast starts at 65
		ORain = 60;		// clouds start at 50, overcast starts at 65
		gWeatherOvrd = true;
		sWeatherID = "21 Rain";
		break;

	case "Overcast":
		wRain = 70;		// overcast starts at 65, rain starts at 75
		ORain = 70;		// overcast starts at 65, rain starts at 75
		gWeatherOvrd = true;
		break;

	case "Rainy":
		wRain = 80;		// rain starts at 75, storm starts at 95
		ORain = 80;		// rain starts at 75, storm starts at 95
		gWeatherOvrd = true;
		break;

	case "Heavy Rain":
		wRain = 90;		// rain starts at 75, storm starts at 95
		ORain = 90;		// rain starts at 75, storm starts at 95
		gWeatherOvrd = true;
		break;

	case "Stormy":		// this produces lightning
		wRain = 97;		// storm starts at 95
		ORain = 97;		// storm starts at 95
		OWind = 25;		// twisters start at minwind >= 28
		gWeatherOvrd = true;
		break;

	case "Heavy Storm":	// this produces twisters, "Day Storm"
		wRain = 100;	// storm starts at 95
		ORain = 100;	// storm starts at 95
		ORBallast = 15;
		OWind = 30;		// twisters start at minwind >= 28
		OWBallast = 15;
		gWeatherOvrd = true;
		break;

	case "Foggy":
		Fog = 25;		// produces fog density of 0.00375
		OFog = 25;		// produces fog density of 0.00375
		gWeatherOvrd = true;
		break;

	case "Heavy Fog":
		Fog = 40;		// produces fog density of 0.00625
		OFog = 40;		// produces fog density of 0.00625
		gWeatherOvrd = true;
		break;

	case "Black Pearl Fight":
		wRain = 90;
		Fog = 25;
		OFog = 25;
		OWind = 25;
		gWeatherOvrd = true;
		break;

	case "IslaDeMuerte":
		Fog = 80;		// produces fog density of 0.02
		OFog = 80;		// produces fog density of 0.02
		gWeatherOvrd = true;
		break;

	case "Super Fog":
		Fog = 999;
		OFog = 999;
		gWeatherOvrd = true;
		break;

	}
	
	// find weather
	iNextWeatherNum = -1;
	iCurWeatherNum = FindWeatherByHour(MakeInt(GetHour()));
	iBlendWeatherNum = FindBlendWeather( iCurWeatherNum );
	Whr_LoadNextWeather(0);
}

void SetNextWind(string sDir, int speed)
{
	int dir = -1;
	switch (sDir)
	{
	case "N":	dir =  0; break;
	case "NNE":	dir =  1; break;
	case "NE": 	dir =  2; break;
	case "ENE":	dir =  3; break;
	case "E":  	dir =  4; break;
	case "ESE":	dir =  5; break;
	case "SE": 	dir =  6; break;
	case "SSE":	dir =  7; break;
	case "S":  	dir =  8; break;
	case "SSW":	dir =  9; break;
	case "SW": 	dir = 10; break;
	case "WSW":	dir = 11; break;
	case "W":  	dir = 12; break;
	case "WNW":	dir = 13; break;
	case "NW": 	dir = 14; break;
	case "NNW":	dir = 15; break;
	}
	if (dir != -1)
	{
		OWeatherAngle = Degree2Radian(dir*22.5);
		gWeatherOvrd = true;
	}
	if (speed >= 0)
	{
		OWind = iclamp(5,30,speed);
		gWeatherOvrd = true;
	}
}

void WeatherInit()
{
	//DeleteAttribute(&WeatherParams,"");

	if (LoadSegment("weather\WhrInit.c"))
	{
		iTotalNumWeathers = InitWeather();
		UnloadSegment("weather\WhrInit.c");
	}
}

void DeleteWeatherEnvironment()
{
	iBlendWeatherNum = -1;
	if (isEntity(&Weather))
	{
		DeleteClass(&Weather);
	}
	DeleteAttribute(&Weather,"");
	//WeatherParams.Tornado = false;
	//DeleteAttribute(&WeatherParams,"");

	WhrDeleteRainEnvironment();
	WhrDeleteSkyEnvironment();
	WhrDeleteSunGlowEnvironment();
	WhrDeleteLightningEnvironment();
	WhrDeleteTornadoEnvironment();
	WhrDeleteSeaEnvironment();
	WhrDeleteAstronomyEnvironment();

	DelEventHandler(WEATHER_CALC_FOG_COLOR,"Whr_OnCalcFogColor");
	DelEventHandler("frame","Whr_OnWindChange");

	bWeatherLoaded = false;
}

aref GetCurrentWeather()
{
	//Boyer fix #20170318-50 for when iCurWeatherNum = -1...borrowed from function Whr_LoadNextWeather(int nPlus)
	if (iCurWeatherNum < 0)
		iCurWeatherNum = iTotalNumWeathers - 1;
	//End fix
	aref arWeather;
	makearef(arWeather,Weathers[iCurWeatherNum]);
	return arWeather;
}

aref GetTempWeatherObj()
{
	aref arWeather;
	makearef(arWeather, WeathersNH);

	return arWeather;
}

void CreateWeatherEnvironment()
{
    pchar = GetMainCharacter();
    DeleteAttribute(&Weather,"");

	string sAttrName;
	string sSky = "";
	int iWeatherFound[MAX_WEATHERS];
	int iNumWeatherFound = 0;
	int iHour = MakeInt(GetHour());

	bool bWhrStorm = false;
	bool bWhrTornado = false;
	bool bRain = false;

	bWeatherIsStorm = false; // screwface
	bWeatherIsRain = false; // screwface
	Whr_Generator(iHour);

	if (CheckAttribute(&WeatherParams,"Storm")) { bWhrStorm = sti(WeatherParams.Storm); }
	if (CheckAttribute(&WeatherParams,"Tornado")) { bWhrTornado = sti(WeatherParams.Tornado); }

	//bWeatherIsStorm = false; // screwface
	//bWeatherIsRain = false; // screwface
	//Whr_Generator(iHour);
    //WeatherParams.Storm = false;
	//WeatherParams.Tornado = false;

	int iMonth = GetDataMonth();
	int iTmp; //, iChance;
	if (CheckAttribute(&WeatherParams,"Rain")) { bRain = sti(WeatherParams.Rain); }
	if (!CheckAttribute(&WeatherParams, "Rain.ThisDay")) WeatherParams.Rain.ThisDay = false;
	//if (/*iHour >= 5 && iHour <= 15 &&*/ sti(WeatherParams.Rain.ThisDay))
	//{
		//????.
		//iChance = 0;
		//??... ??? ??????? ????? ??????!!!! ????! ?????????? 50/50 ?????, ???? ????? ?????????? - ????????/??????
		//if (iMonth > 4 && iMonth < 9) iChance = 30;
		//bRain = false; //((rand(50) + rand(50)) < (5 + iChance));

		//if (bRain || CheckAttribute(pchar, "questTemp.StartRain"))
		//{
			//??? ??????...
		//	WeatherParams.Rain.ThisDay   = true;
		//	WeatherParams.Rain.StartTime = iHour + 2 + rand(2);
			//????????????????? ? ??????? //1 ??? ???, ????? ???? ?? ??????.
		//	WeatherParams.Rain.Duration  = 60 + rand(120);

		//	iTmp = sti(WeatherParams.Rain.StartTime);

			// Weathers[iTmp].Bak.Fog.Color		= Weathers[iTmp].Fog.Color;
			// Weathers[iTmp].Bak.Fog.Height		= Weathers[iTmp].Fog.Height;
			// Weathers[iTmp].Bak.Fog.Density		= Weathers[iTmp].Fog.Density;
			// Weathers[iTmp].Bak.Fog.SeaDensity	= Weathers[iTmp].Fog.SeaDensity;

			// Weathers[iTmp].Bak.Sun.Glow.Enable		= Weathers[iTmp].Sun.Glow.Enable;
			// Weathers[iTmp].Bak.Sun.Overflow.Enable	= Weathers[iTmp].Sun.Overflow.Enable;

			// Weathers[iTmp].Fog.Color = argb(0,50,60,65);
			// Weathers[iTmp].Fog.Height = 250;
			// Weathers[iTmp].Fog.Density = 0.008;
			// Weathers[iTmp].Fog.SeaDensity = 0.008;

			// Weathers[iTmp].Sun.Glow.Enable = false;
			// Weathers[iTmp].Sun.Overflow.Enable = false;

	//		Log_TestInfo("Will raining in : " + WeatherParams.Rain.StartTime);
		//}
	//}

	//????????????? ??????? ?????, ???? ????? ??????????
	if (bRain)
	{
		iTmp = sti(WeatherParams.Rain.StartTime) + (sti(WeatherParams.Rain.Duration)/60 + 0.5);
		if (iHour > iTmp)
		{
			bRain = false;
			WeatherParams.Rain = false;
			WeatherParams.Rain.ThisDay = false;
		}
	}
//navy <-- Rain

if (iNextWeatherNum != -1)
	{
		if (iPrevWeather == -1) { iPrevWeather = iCurWeatherNum; }
		iCurWeatherHour = iHour;
		iCurWeatherNum = iNextWeatherNum;
		iNextWeatherNum = -1;
		//Trace("Weather: used preset weather " + iCurWeatherNum);
	}
	else
	{
		// search weather for hour
		for (int i=0;i<MAX_WEATHERS;i++)
		{
			//navy -->
			if (!bRain && sti(Weathers[i].Rain.NumDrops) > 0 && sti(Weathers[i].Rain.NumDrops) < 5100)
			{
				Weathers[i].Rain.NumDrops = 0;
				Weathers[i].Lightning.Enable = false;
			}
			if (CheckAttribute(&WeatherParams, "Rain.ThisDay") && !sti(WeatherParams.Rain.ThisDay) && CheckAttribute(&Weathers[i], "Bak"))
			{
				// Weathers[i].Fog.Color		= Weathers[i].Bak.Fog.Color;
				// Weathers[i].Fog.Height		= Weathers[i].Bak.Fog.Height;
				// Weathers[i].Fog.Density		= Weathers[i].Bak.Fog.Density;
				// Weathers[i].Fog.SeaDensity	= Weathers[i].Bak.Fog.SeaDensity;
				// Weathers[i].Fog.IslandDensity	= Weathers[i].Bak.Fog.IslandDensity;

				// Weathers[i].Sun.Glow.Enable		= Weathers[i].Bak.Sun.Glow.Enable;
				// Weathers[i].Sun.Overflow.Enable	= Weathers[i].Bak.Sun.Overflow.Enable;

				// DeleteAttribute(&Weathers[i], "Bak");
			}
			if (!bRain) Weathers[i].Rainbow.Enable = false;
			//navy <--
			if (!CheckAttribute(&Weathers[i], "hour")) { continue; }
			if (CheckAttribute(&Weathers[i], "skip"))
			{
				if (sti(Weathers[i].skip)) { continue; }
			}

			bool bCanStorm = sti(Weathers[i].Storm);
			bool bCanTornado = sti(Weathers[i].Tornado);
			int iMin = sti(Weathers[i].Hour.Min);
			int iMax = sti(Weathers[i].Hour.Max);
			if (iMin == iMax && iMin != iHour) { continue; }
			if (iMin > iMax)
			{
				if (iHour < iMin && iHour > iMax) { continue; }
			}
			if (iMin < iMax)
			{
				if (iHour < iMin || iHour > iMax) { continue; }
			}
			if (bWhrStorm != bCanStorm) { continue; }
			if (bWhrTornado == true && bWhrTornado != bCanTornado) { continue; }

			iWeatherFound[iNumWeatherFound] = i;
			iNumWeatherFound++;
		}
		iCurWeatherHour = iHour;

		if (iNumWeatherFound == 0)
		{
			Trace("Error: iNumWeatherFound = 0, for hour = " + iHour);
			iCurWeatherNum = 0;
		}
		else
		{
			iCurWeatherNum = iWeatherFound[rand(iNumWeatherFound-1)];
		}
	}
	int iCurLocation;
	int iTestWeather;
	bool bQuestlockWeather;
    float fGetTime = GetTime();

	bQuestlockWeather = false;
	sunIsShine = true;

	if(CheckAttribute(pchar, "location"))
	{
		iCurLocation = reload_location_index;
		if(iCurLocation != -1)
		{
			if(CheckAttribute(&locations[iCurLocation], "storm"))
			{
				bWhrStorm = 1;
			}
			if(CheckAttribute(&locations[iCurLocation], "tornado"))
			{
				bWhrTornado = 1;
			}
			if(CheckAttribute(&locations[iCurLocation], "alwaysStorm"))
			{
				if (fGetTime >= 6.0 && fGetTime < 10.0) locations[iCurLocation].QuestlockWeather = "Storm01_add";
				else { if (fGetTime >= 10.0 && fGetTime < 18.0) locations[iCurLocation].QuestlockWeather = "Storm02_add";
				else { if (fGetTime >= 18.0 && fGetTime < 22.0) locations[iCurLocation].QuestlockWeather = "Storm03_add";
				else { locations[iCurLocation].QuestlockWeather = "Storm04_add";
				}}}
				if (CheckAttribute(&locations[iCurLocation], "alwaysStorm.WaveHeigh")) locations[iCurLocation].MaxWaveHeigh = 2.5;
			}
			else { if(CheckAttribute(&locations[iCurLocation], "alwaysStorm_2")) //COAS escape
                {
                    if (fGetTime >= 6.0 && fGetTime < 10.0) locations[iCurLocation].QuestlockWeather = "Storm01";
                    else { if (fGetTime >= 10.0 && fGetTime < 18.0) locations[iCurLocation].QuestlockWeather = "Storm02";
                    else { if (fGetTime >= 18.0 && fGetTime < 22.0) locations[iCurLocation].QuestlockWeather = "Storm03";
                    else { locations[iCurLocation].QuestlockWeather = "Storm04";
                    }}}
                    if (CheckAttribute(&locations[iCurLocation], "alwaysStorm_2.WaveHeigh")) locations[iCurLocation].MaxWaveHeigh = 28.0; //40.0;
                }
			}
			if(CheckAttribute(&locations[iCurLocation], "QuestlockWeather"))
			{
				iTestWeather = FindWeather(locations[iCurLocation].QuestlockWeather);
				if(iTestWeather != -1)
				{
					iCurWeatherNum = iTestWeather;
					bQuestlockWeather = true;
					if (CheckAttribute(&locations[iCurLocation], "lockWeather") && locations[iCurLocation].lockWeather == "Inside")
					{
						sunIsShine = false;
					}
				}
			}
		}
		else
		{
			iCurLocation = FindIsland(pchar.location);
			if(iCurLocation != -1)
			{
				if(CheckAttribute(&Islands[iCurLocation], "storm"))
				{
					bWhrStorm = 1;
				}
				if(CheckAttribute(&Islands[iCurLocation], "tornado"))
				{
					bWhrTornado = 1;
				}
				if(CheckAttribute(&Islands[iCurLocation], "alwaysStorm"))
				{
					if (fGetTime >= 6.0 && fGetTime < 10.0) Islands[iCurLocation].QuestlockWeather = "Storm01";
					else { if (fGetTime >= 10.0 && fGetTime < 18.0) Islands[iCurLocation].QuestlockWeather = "Storm02";
					else { if (fGetTime >= 18.0 && fGetTime < 22.0) Islands[iCurLocation].QuestlockWeather = "Storm03";
					else { Islands[iCurLocation].QuestlockWeather = "Storm04";
					}}}
				}
				if(CheckAttribute(&Islands[iCurLocation], "QuestlockWeather"))
				{
					iTestWeather = FindWeather(Islands[iCurLocation].QuestlockWeather);
					if(iTestWeather != -1)
					{
						iCurWeatherNum = iTestWeather;
						bQuestlockWeather = true;
					}
				}
			}
		}
	}
	bWeatherIsStorm = bWhrStorm;
	bCurWeatherStorm = bWhrStorm;

	if (!bQuestlockWeather)
	{
		iBlendWeatherNum = FindBlendWeather(iCurWeatherNum);
	}
	else
	{
		iBlendWeatherNum = -1;
	}
	
	if (bMainMenu)
    {
        iTestWeather = sti(InterfaceStates.mainmenuweather);
        if(iTestWeather != -1)
        {
            iCurWeatherNum = iTestWeather;
            bQuestlockWeather = true;
        }
    }

	if (startGameWeather)
	{
		iTestWeather = sti(InterfaceStates.startGameWeather);
		if(iTestWeather != -1)
		{
			iCurWeatherNum = iTestWeather;
			bQuestlockWeather = true;
		}
		startGameWeather = false;
	}
	
	DeleteAttribute(&Weather,"");
	if (!isEntity(&Weather))
	{
		CreateEntity(&Weather, "Weather");
	}

	aref aCurWeather = GetCurrentWeather();

	sLightingPath = Whr_GetString(aCurWeather,"Lighting");
	sLmLightingPath = Whr_GetString(aCurWeather,"LightingLm");
	sInsideBack = Whr_GetString(aCurWeather,"InsideBack");
	bWeatherIsNight = Whr_GetLong(aCurWeather,"Night");
	bWeatherIsLight = Whr_GetLong(aCurWeather,"Lights");
	Weather.Wind.Speed = Whr_GetFloat(aCurWeather,"Wind.Speed");
	pchar.wind.speed = Weather.Wind.Speed;

	Weather.Wind.Angle = Whr_GetLong(&WeathersNH, "Wind.Angle");
	sCurrentFog = "Fog";
	if (bSeaActive)
	{
		if (CheckAttribute(aCurWeather, "SpecialSeaFog")) { sCurrentFog = "SpecialSeaFog"; }
	}
	FillWeatherData(iCurWeatherNum, iBlendWeatherNum, true);
	//FillWeatherData(iCurWeatherNum, -1);

	// trace("CWE Weather density: " + Whr_GetFloat(Weather, "Fog.Density"));
	// trace("CWE Weather islandDensity: " + Whr_GetFloat(Weather, "Fog.IslandDensity"));
	// trace("CWE Weather SeaDensity: " + Whr_GetFloat(Weather, "Fog.SeaDensity"));
	// trace("CWE Weather color: " + Whr_GetLong(Weather, "Fog.Color"));

	if (iBlendWeatherNum < 0 || bQuestlockWeather)
	{
		Weather.Time.time = fGetTime;
		Weather.Time.speed = 350.0;
		Weather.Time.updatefrequence = 12;
	} else {
		Weather.Time.time = fGetTime;
		Weather.Time.speed = 450;
		Weather.Time.updatefrequence = 15;
		if (bSeaActive && !bAbordageStarted)
		{
			
			if (iArcadeSails == 1)
            {
                Weather.Time.speed = 250;
                Weather.Time.updatefrequence = 10;
            }
		}
		else
		{
			Weather.Time.speed = 350;
			Weather.Time.updatefrequence = 12;
		}
	}
	Weather.isDone = "";

	SetEventHandler(WEATHER_CALC_FOG_COLOR,"Whr_OnCalcFogColor",0);
	SetEventHandler("frame","Whr_OnWindChange",0);


	fFogDensity = stf(WeathersNH.Fog.Density);



	fWeatherDelta = 0.0;
	fWeatherAngle = stf(Weather.Wind.Angle);
	//fWeatherAngle = GetAngleY(stf(worldMap.WindX), stf(worldMap.WindZ));
	fWeatherSpeed = stf(Weather.Wind.Speed);

    // // boal -->
	bRain = true; // Whr_isRainEnable();
    string sLocation = pchar.location;
	int iLocation = FindLocation(sLocation);

	if (bCabinStarted) bRain = false;
	if(iLocation != -1)
	{
		ref rLoc;
		rLoc = &Locations[iLocation];

		if (CheckAttribute(rLoc, "environment.weather.rain") && !sti(rLoc.environment.weather.rain))
		{
			bRain = false;
		}
		//navy
		else {
			if (CheckAttribute(rLoc, "type"))
			{
				// ??? ?????????
				if(rLoc.type == "residence"
					|| rLoc.type == "tavern"
					|| rLoc.type == "house"
					|| rLoc.type == "shop"
					|| rLoc.type == "shipyard"
					|| rLoc.type == "church" )
				{
					//??? ?????
					bRain = false;
				}
			}
		}
	}
	//trace("bRain " + bRain);
	//trace("iLocation " + iLocation);
	//trace("bCabinStarted " + bCabinStarted);
	//trace("loadedlocation " + Locations[iLocation].id);
	//trace("loadedlocation " + Locations[iLocation].type);
	if (bRain)
	{
		WhrCreateRainEnvironment();
	}
	else
	{
		ClearRainEnvironment();
	}

	WhrCreateSunGlowEnvironment();
	WhrCreateLightningEnvironment();
	WhrCreateAstronomyEnvironment();
	WhrCreateSkyEnvironment();
	WhrCreateSeaEnvironment();

	// if(iLocation != -1)
	// {
	// 	if(CheckAttribute(&Locations[iLocation], "lockWeather"))
	// 	{
	// 		bWhrTornado = false;
	// 	}
	// }
	if (bWhrTornado) { WhrCreateTornadoEnvironment(); }

	Particles.windpower = 0.025 * Clampf(Whr_GetWindSpeed() / WIND_NORMAL_POWER);
	Particles.winddirection.x = sin(Whr_GetWindAngle());
	Particles.winddirection.z = cos(Whr_GetWindAngle());

	bWeatherLoaded = true;
	// PB: Only show this if you've actually got a compass -->
	// FlayedOne
	bool ShowWindLog = false;
	string logstr = "";
	string compasstype = CheckCharacterEquipByGroup(pchar, COMPASS_ITEM_TYPE);
	/*
	if (winds == 0)			logstr = TranslateString("", "The air is calm");
	if (winds > 0 && winds <= 2)	logstr = TranslateString("", "There are light airs");
	if (winds > 2 && winds <= 6)	logstr = TranslateString("", "There is a light breeze");
	if (winds > 6 && winds <=10)	logstr = TranslateString("", "There is a gentle breeze");
	if (winds >10 && winds <=15)	logstr = TranslateString("", "There is a moderate breeze");
	if (winds >15 && winds <=20)	logstr = TranslateString("", "There is a fresh breeze");
	if (winds >20 && winds <=27)	logstr = TranslateString("", "There is a strong breeze");
	if (winds >27)			logstr = TranslateString("", "There is a near gale");

	if (winds>0)
	{
		switch (compasstype)
		{
			case "compass1":
				switch(LanguageGetLanguage())
				{
					case "Russian":
						logstr = TranslateString("", "wind_from_the") + " " + TranslateString("", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0))) + " " + logstr;
					break;
					logstr = logstr + " " + TranslateString("wind_from_the", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0)));
				}
			break;
			case "compass2":
				switch(LanguageGetLanguage())
				{
					case "Russian":
						logstr = TranslateString("", "wind_from_the") + " " + TranslateString("", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0))) + " " + TranslateString("", "Wind is from the") + " " + TranslateString("", "wind_at") + " " +  winds + " " + TranslateString("", "kts");
					break;
					logstr = TranslateString("Wind is from the", "") + " " + TranslateString(GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0)), "") + " " + TranslateString("", "wind_at") + " " + winds + " " + TranslateString("", "kts");
				}
			break;
			case "compass3":
				switch(LanguageGetLanguage())
				{
					case "Russian":
						logstr = TranslateString("", "wind_from_the") + " " + TranslateString("", GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0))) + " " + TranslateString("", "Wind is from the") + " " + TranslateString("", "wind_at") + " " +  winds + " " + TranslateString("", "kts");
					break;
					logstr = TranslateString("Wind is from the", "") + " " + TranslateString(GetCompassDirFromHeading16(fWindA + Degree2Radian(180.0)), "") + " " + TranslateString("", "wind_at") + " " + winds + " " + TranslateString("", "kts");
				}
			break;
			// In Russian translation, "Wind is from the" translates to "wind"
		}
	}
	*/
	if(bSeaActive && compasstype == "")			ShowWindLog = true;
	if(CheckAttribute(PChar, "skipWeatherLogs"))		ShowWindLog = false;
	// if(ShowWindLog)						LogIt(logstr);
	if (bSeaActive)
	{
		Island.LightingPath = GetLightingPath();
		Island.FogDensity = WeathersNH.Fog.IslandDensity;
		Sea.Fog.SeaDensity = WeathersNH.Fog.SeaDensity;
		SendMessage(&IslandReflModel, "lllf", MSG_MODEL_SET_FOG, 1, 1, stf(WeathersNH.Fog.IslandDensity));
	}
	//Trace("Whr: Select id = " + aCurWeather.id);
}

void Whr_UpdateWeather() // NK 04-09-21
{
	// LDH cleanup 16Feb09
//	Traceandlog("Whr_UpdateWeather start weather update " + "Time: " + GetStringTime(GetTime()) +" reinit: " +reinit_weather);	// LDH 05Sep06 trace for CTD

    WeatherInit(); // NK 04-09-21
    CreateWeatherEnvironment();
    MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);

	//trace("Whr_UpdateWeather finish weather update");

	if(bSeaActive && !ownDeckStarted())
	{
		Sea.Sea2.Transparency = 0;
		PlayStereoSound("nature\wind_sea4.wav"); // squall i.e. weatherchange
		// DirectsailCheck(true);	//  triggers change to other island and ship encounters, necessary to run here
	}
}

void Whr_LoadNextWeather(int nPlus)
{
	if (!isEntity(&Weather)) { return; }
	//WeatherInit();

	iCurWeatherHour = MakeInt(GetHour());
	iCurWeatherNum = iCurWeatherNum + nPlus;

	if (iCurWeatherNum < 0)
	{
		iCurWeatherNum = iTotalNumWeathers - 1;
	}
	if (iCurWeatherNum >= iTotalNumWeathers)
	{
		iCurWeatherNum = 0;
	}
	if (CheckAttribute(&Weathers[iCurWeatherNum], "Skip"))
	{
		if (sti(Weathers[iCurWeatherNum].skip))
		{
			Whr_LoadNextWeather(nPlus);
			return;
		}
	}
	// Log_TestInfo("Weather ID: " + Weathers[iCurWeatherNum].id + " Lighting: " + Weathers[iCurWeatherNum].Lighting);
	// Log_TestInfo("Sun: HeightAngle: " + Weathers[iCurWeatherNum].Sun.HeightAngle);

	iNextWeatherNum = iCurWeatherNum;
	CreateWeatherEnvironment();
	MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);

	//aref aCurWeather = GetCurrentWeather();
	//iCurWeatherHour = sti(aCurWeather.Hour.Min);

	//SetCurrentTime(iCurWeatherHour, 0);
	Weather.Time.time = GetTime();
}

void Whr_OnWindChange()
{
	//creates the constant minor wind fluctuations
	float fDeltaTime = MakeFloat(GetDeltaTime()) * 0.001;
	fWeatherDelta = fWeatherDelta + fDeltaTime;

	float fSpd = fWeatherSpeed + (fWeatherSpeed / 6.0) * 0.1 * (sin(fWeatherDelta) + sin(0.2 * fWeatherDelta) + sin(PI + 0.8 * fWeatherDelta) + cos(1.5 * fWeatherDelta));
	float fAng = fWeatherAngle + 0.02 * (sin(fWeatherDelta) + sin(0.2 * fWeatherDelta) + sin(PI + 0.8 * fWeatherDelta) + cos(1.5 * fWeatherDelta));

	WeathersNH.Wind.Angle = fAng;
	WeathersNH.Wind.Speed = fSpd;
}

int Whr_OnCalcFogColor()
{
	int		iAlpha, iColor;
	float	x, y, z;

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	
	int iFogColor = sti(Weather.Fog.Color);
	if( iBlendWeatherNum < 0 )
	{
        iAlpha = 255 - MakeInt(255.0 * Clampf(y / stf(WeathersNH.SpecialSeaFog.Height)));
	}
	else
	{
        float fBlend = stf(Environment.time) - sti(Environment.time);
        float fH = Whr_BlendFloat(fBlend, stf(Weathers[iCurWeatherNum].(sCurrentFog).Height), stf(Weathers[iBlendWeatherNum].(sCurrentFog).Height));

        iAlpha = 255 - MakeInt(255.0 * Clampf(y / fH));
	}

    iColor = or(shl(iAlpha, 24), iFogColor);
	return iColor;
}

float Whr_BlendFloat(float fBlend, float f1, float f2)
{
	float f = f1 + fBlend * (f2-f1);
	return f;
}

int Whr_BlendLong(float fBlend, int i1, int i2)
{
	int i = makeint(i1 + fBlend * (i2-i1));
	return i;
}

int Whr_BlendColor(float fBlend, int col1, int col2)
{
	int r1 = shr(and(col1,16711680), 16); // get red color 1
	int r2 = shr(and(col2,16711680), 16); // get red color 2

	int g1 = shr(and(col1,65280), 8); // get green color 1
	int g2 = shr(and(col2,65280), 8); // get green color 2

	int b1 = and(col1,255); // get blue color 1
	int b2 = and(col2,255); // get blue color 2

	int r = r1 + MakeInt(fBlend * (r2-r1));
	int g = g1 + MakeInt(fBlend * (g2-g1));
	int b = b1 + MakeInt(fBlend * (b2-b1));

	return argb(0,r,g,b);
}

void Whr_TimeUpdate()
{
	float fTime = GetEventData();
	//float fBlend = fTime - makeint(fTime);
	//
	//int nOldDay = GetDataDay();
	float oldTime = stf(Environment.time);
	int nOldHour = sti(Environment.date.hour);
	Environment.time = fTime;
	int nNewHour = makeint(fTime);
	int nNewMin = makeint((fTime - nNewHour)*60);
	int nNewSec = makeint(((fTime - nNewHour)*60 - nNewMin)*60);
	int nTimeR = GetTimeScale();
	if (nTimeR > 3) {
        if (nTimeR > 10) {
            oldTime -= 0.2;
        }
        else {
            if(nTimeR > 5) {
                oldTime -= 0.1;
            }
            else {
                oldTime -= 0.05;
            }
        }
        nOldHour = makeint(oldTime);
	}
	Environment.date.min = nNewMin;
	Environment.date.hour = nNewHour;
	Environment.date.sec = nNewSec;
	worldMap.date.hour = nNewHour;
	worldMap.date.min  = nNewMin;
	if( nNewHour < nOldHour )
	{
		AddDataToCurrent(0,0,1);
		Weather.Time.time = GetTime();
	} // to_do CalcLocalTime
    if( iBlendWeatherNum < 0 ) {return;}
	//navy --> Rain
	string sTmp;
	int iTmp, iTime;
	bool bRain = false;
	if (CheckAttribute(&WeatherParams,"Rain")) { bRain = sti(WeatherParams.Rain); }
	//navy <-- Rain
	aref oldWeather = GetCurrentWeather();
	bool isLagoon = CheckAttribute(oldWeather, "Sea.inlagoon");
	iCurWeatherNum = FindWeatherByHour( makeint(fTime) );
	iBlendWeatherNum = FindBlendWeather( iCurWeatherNum );

	if( iBlendWeatherNum < 0 ) {return;}

	if (bSeaActive)
	{
		Island.LightingPath = GetLightingPath();
		Island.FogDensity = WeathersNH.Fog.IslandDensity;
		Sea.Fog.SeaDensity = WeathersNH.Fog.SeaDensity;
	}
	//navy --> Rain
	bool  bIsRainEnable = Whr_isRainEnable();

	if (bIsRainEnable)
	{
		if (bRain)
		{
			int nRainDuration = sti(WeatherParams.Rain.Duration);
			iTmp = 3;

			iTime = GetQuestPastMinutesParam("Rain.Duration");
			if (iTime > nRainDuration)
			{
				iTmp = 3;
				bRain = false;
			}
			if (iTime < (4*nRainDuration/5))
			{
				iTmp = 2;
			}
			if (iTime < (2*nRainDuration/3))
			{
				iTmp = 1;
			}
			if (iTime < (nRainDuration/3))
			{
				iTmp = 0;
			}
			// Log_TestInfo("Is Raining...");
			switch (iTmp)
			{
				case 0:
					WeatherParams.Rain.Sound = true;
					break;
				case 1:
					if (rand(100) < 40)
					{
						// Log_TestInfo("Starting the Lightning...");
						Weathers[iCurWeatherNum].Lightning.Enable = true;
						Weathers[iCurWeatherNum].Lightning.SubTexX = 4;
						Weathers[iCurWeatherNum].Lightning.SubTexY = 1;
						Weathers[iCurWeatherNum].Lightning.ScaleX = 0.7;
						Weathers[iCurWeatherNum].Lightning.ScaleY = 1.0;
						Weathers[iCurWeatherNum].Lightning.Flash.Texture = "Weather\lightning\flash.tga.tx";
					}
					break;
				case 2:
					break;
				case 3:
					if (CheckAttribute(&WeatherParams, "Rain.Sound") && sti(WeatherParams.Rain.Sound))
					{
						WeatherParams.Rain = false;
						WeatherParams.Rain.Sound = false;
						Whr_SetRainSound(false, sti(Weathers[iCurWeatherNum].Night));
						Weathers[iCurWeatherNum].Lightning.Enable = false;
						if (nNewHour > 5 && nNewHour < 20) //navy -- 5.03.07
						{
							Weathers[iCurWeatherNum].Rainbow.Enable = true;
						}

						DeleteAttribute(&WeatherParams, "Rain.StartTime");
					}
					WeatherParams.Rain.ThisDay = false;
					break;
			}
			if (iTmp != 0)
			{
				Weathers[iCurWeatherNum].Rain.NumDrops = 3500 + rand(1500);
				Weathers[iCurWeatherNum].Rain.DropLength = 4 + rand(8);
				Weathers[iCurWeatherNum].Rain.Color = argb(0,23,23,23);
			}
			if (iTmp != 3)
			{
				Weathers[iBlendWeatherNum].Rain.NumDrops = 3500 + rand(1500);
				Weathers[iBlendWeatherNum].Rain.DropLength = 4 + rand(8);
				Weathers[iBlendWeatherNum].Rain.Color = argb(0,23,23,23);

				if (!CheckAttribute(&Weathers[iBlendWeatherNum], "Bak"))
				{
					Weathers[iBlendWeatherNum].Bak.Fog.Color		= Weathers[iBlendWeatherNum].Fog.Color;
					Weathers[iBlendWeatherNum].Bak.Fog.Height		= Weathers[iBlendWeatherNum].Fog.Height;
					Weathers[iBlendWeatherNum].Bak.Fog.Density		= Weathers[iBlendWeatherNum].Fog.Density;
					Weathers[iBlendWeatherNum].Bak.Fog.SeaDensity	= Weathers[iBlendWeatherNum].Fog.SeaDensity;
					Weathers[iBlendWeatherNum].Bak.Fog.IslandDensity	= Weathers[iBlendWeatherNum].Fog.IslandDensity;

					Weathers[iBlendWeatherNum].Bak.Sun.Glow.Enable		= Weathers[iBlendWeatherNum].Sun.Glow.Enable;
					Weathers[iBlendWeatherNum].Bak.Sun.Overflow.Enable	= Weathers[iBlendWeatherNum].Sun.Overflow.Enable;
				}
				Weathers[iBlendWeatherNum].Fog.Color = argb(0,50,60,65);
				Weathers[iBlendWeatherNum].Fog.Height = 1000;
				Weathers[iBlendWeatherNum].Fog.Density = 0.003;
				Weathers[iBlendWeatherNum].Fog.SeaDensity = 0.0022;
				Weathers[iBlendWeatherNum].Fog.IslandDensity = 0.0015;

				Weathers[iBlendWeatherNum].Sun.Glow.Enable = false;
				Weathers[iBlendWeatherNum].Sun.Overflow.Enable = false;
			}
		}
		else
		{
			if (CheckAttribute(&WeatherParams, "Rain.ThisDay") && sti(WeatherParams.Rain.ThisDay) && sti(WeatherParams.Rain.StartTime) <= nOldHour)
			{
				Weathers[iBlendWeatherNum].Rain.NumDrops = 2000 + rand(3000);
				Weathers[iBlendWeatherNum].Rain.DropLength = 2 + rand(10);
				Weathers[iBlendWeatherNum].Rain.Color = argb(0,23,23,23);

				if (!CheckAttribute(&Weathers[iBlendWeatherNum], "Bak"))
				{
					Weathers[iBlendWeatherNum].Bak.Fog.Color		= Weathers[iBlendWeatherNum].Fog.Color;
					Weathers[iBlendWeatherNum].Bak.Fog.Height		= Weathers[iBlendWeatherNum].Fog.Height;
					Weathers[iBlendWeatherNum].Bak.Fog.Density		= Weathers[iBlendWeatherNum].Fog.Density;
					Weathers[iBlendWeatherNum].Bak.Fog.SeaDensity	= Weathers[iBlendWeatherNum].Fog.SeaDensity;
					Weathers[iBlendWeatherNum].Bak.Fog.IslandDensity	= Weathers[iBlendWeatherNum].Fog.IslandDensity;

					Weathers[iBlendWeatherNum].Bak.Sun.Glow.Enable		= Weathers[iBlendWeatherNum].Sun.Glow.Enable;
					Weathers[iBlendWeatherNum].Bak.Sun.Overflow.Enable	= Weathers[iBlendWeatherNum].Sun.Overflow.Enable;
				}
				Weathers[iBlendWeatherNum].Fog.Color = argb(0,50,60,65);
				Weathers[iBlendWeatherNum].Fog.Height = 1000;
				Weathers[iBlendWeatherNum].Fog.Density = 0.003;
				Weathers[iBlendWeatherNum].Fog.SeaDensity = 0.0022;
				Weathers[iBlendWeatherNum].Fog.IslandDensity = 0.0015;

				Weathers[iBlendWeatherNum].Sun.Glow.Enable = false;
				Weathers[iBlendWeatherNum].Sun.Overflow.Enable = false;

				SaveCurrentQuestDateParam("Rain.Duration");
				WeatherParams.Rain = true;
				Whr_SetRainSound(true, sti(Weathers[iCurWeatherNum].Night));
				Log_TestInfo("Rain Started");
			}
		}
	}
	//navy <-- Rain
	if( nNewHour != nOldHour )
	{
	    if (isLagoon) {
            DeleteAttribute(oldWeather, "Sea.inlagoon");
            Weathers[iCurWeatherNum].Sea.inlagoon = 1;
	    }
		Whr_UpdateWeatherHour();
		FillWeatherData(iCurWeatherNum, iBlendWeatherNum, true);
		// Add for transparent water in ports/beaches
		if (IsEntity(&objLandInterface)) {
        Sea.Sea2.Transparency = 0.3;
		}
	}
	else {
        // update weather: sun lighting
        FillWeatherData(iCurWeatherNum, iBlendWeatherNum, false);
	}
	Weather.isDone = "";

	//update rain: rain drops, rain colors, rain size, rainbow
	//navy -- 5.03.07
	if (bIsRainEnable)
	{
		FillRainData(iCurWeatherNum, iBlendWeatherNum);
		Rain.isDone = "";
	}
	// update sun glow: sun\moon, flares
	WhrFillSunGlowData(iCurWeatherNum, iBlendWeatherNum);
	SunGlow.isDone = true;

	// update sky: fog
	Sky.TimeUpdate = fTime;
}

#event_handler("eChangeDayNight", "eChangeDayNight");

void Whr_UpdateWeatherHour()
{
	bool bOldIsDay = Whr_IsDay();
	//#20190211-01
	bool doLightChange = false;
	int i, j, iCharIdx;

	// Whr_addfog2weather(&Weather, iCurWeatherNum, iBlendWeatherNum);
    Whr_addWaves2weather(&Sea);

	bWeatherIsLight = Whr_GetLong(&Weathers[iCurWeatherNum],"Lights");
	bWeatherIsNight = Whr_GetLong(&Weathers[iCurWeatherNum],"Night");

	//#20191020-01
	aref aCurWeather = GetCurrentWeather();
	aref aStars;
	makearef(aStars, aCurWeather.Stars);
	FillStars(aStars);
	//FillAstronomyFadeValue();
	Astronomy.isDone = true;
	Astronomy.TimeUpdate = 1;

	if( Whr_IsDay() != bOldIsDay )
	{
		Whr_ChangeDayNight();
		Event("eChangeDayNight");
		//#20190211-01
        doLightChange = true;
 	}
 	if (bSeaActive && !bAbordageStarted)
	{
	    bool isSeaEnt = false;
	    if (IsEntity(&Sea))
            isSeaEnt = true;
        Whr_WindChange();
		i = FindIsland(pchar.location)
        if ( i != -1)
        {
            //#20190211-01
			/*if (isSeaEnt) {
                if(!CheckAttribute(&Sea, "MaxSeaHeight") || stf(Sea.MaxSeaHeight) != SetMaxSeaHeight(i)) {
                    WhrCreateSeaEnvironment();
					if(!bstorm) Sea.MaxSeaHeight = 7.0; // mirsaneli: added for normal waves between hour updates
                }
			*/
            if (isSeaEnt) {
                if(stf(Sea.MaxSeaHeight) != SetMaxSeaHeight(i))

					string sPreset = WhrGetSeaPresetFromWind(fWeatherSpeed);
					WhrSetSeaPreset(iCurWeatherNum, sPreset, fWeatherSpeed);
                    WhrCreateSeaEnvironment(); // boal смена волн на лету
	 		}
 		}
 		//#20190211-01
        if(doLightChange && isSeaEnt) {
            doShipLightChange(aCurWeather);
        }
 	}
}

void doShipLightChange(ref aCurWeather)
{
    int j, iCharIdx;

    ref rChar;
    Sea.Lights = aCurWeather.Lights;
    for(j = 0; j < iNumShips; j++) {
        iCharIdx = Ships[j];
        if (iCharIdx < 0 || iCharIdx >= TOTAL_CHARACTERS) continue;
        rChar = GetCharacter(Ships[j]);
        Ship_SetLightsAndFlares(rChar);
        SendMessage(&characters[iCharIdx], "l", MSG_SHIP_LIGHTSRESET);
    }
}

void Whr_ChangeDayNight()
{
	int loadLocationIndex = FindLoadedLocation();
	if( loadLocationIndex >= 0 )
	{
		LocationSetLights(&Locations[loadLocationIndex]);
		if( Whr_IsDay() )
		{
			SendMessage( &Locations[loadLocationIndex], "ls", MSG_LOCATION_EX_MSG, "DelFlys" );
		}
	}
}

void FillWeatherData(int nw1, int nw2, bool updateFog)
{
	if( nw1<0 || nw1>=MAX_WEATHERS ) {return;}

	string sCurFog = Whr_GetCurrentFog();
	if( nw2<0)
	{
        if (updateFog) {
            Weather.Fog.Enable = Whr_GetLong(&WeathersNH, sCurFog + ".Enable");
            Weather.Fog.Start = Whr_GetFloat(&WeathersNH, sCurFog + ".Start");
			Weather.Fog.Height = Whr_GetFloat(&Weathers[nw1], sCurFog + ".Height");
            Weather.Fog.Density = Whr_GetFloat(&WeathersNH, sCurFog + ".Density");
            Weather.Fog.Color = Whr_getCurrentBlendedFogColor();
            Weather.Fog.IslandDensity = Whr_GetFloat(&WeathersNH, "Fog.IslandDensity");
            Weather.Fog.SeaDensity = Whr_GetFloat(&WeathersNH, sCurFog + ".SeaDensity");
        }

		Weather.Sun.Color = Whr_GetColor(&Weathers[nw1],"Sun.Color");
		Weather.Sun.HeightAngle = Whr_GetFloat(&Weathers[nw1],"Sun.HeightAngle");
		Weather.Sun.AzimuthAngle = Whr_GetFloat(&Weathers[nw1],"Sun.AzimuthAngle");
		Weather.Sun.Ambient = Whr_GetColor(&Weathers[nw1],"Sun.Ambient");
		Sky.Color = Whr_GetColor(&Weathers[nw1], "Sky.Color");
	}
	else
	{
		float fBlend = stf(Environment.Time) - sti(Environment.Time);

        if (updateFog) {
            Weather.Fog.Enable = Whr_GetLong(&WeathersNH, sCurFog + ".Enable");
            Weather.Fog.Start = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".Start"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".Start") );
            Weather.Fog.Density = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".Density"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".Density") );
            Weather.Fog.Color = Whr_BlendColor( fBlend, Whr_getCurrentBlendedFogColor(), Whr_GetColor(&Weathers[nw2], sCurFog + ".Color") );
            Weather.Fog.IslandDensity = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, "Fog.IslandDensity"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".IslandDensity") );
            Weather.Fog.SeaDensity = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".SeaDensity"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".SeaDensity") );
			Weather.Fog.Height = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".Height"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".Height") );
        }
		Weather.Sun.Color = Whr_BlendColor( fBlend, Whr_GetColor(&Weathers[nw1],"Sun.Color"), Whr_GetColor(&Weathers[nw2],"Sun.Color") );
		Weather.Sun.HeightAngle = Whr_BlendFloat( fBlend, Whr_GetFloat(&Weathers[nw1],"Sun.HeightAngle"), Whr_GetFloat(&Weathers[nw2],"Sun.HeightAngle") );
		Weather.Sun.AzimuthAngle = Whr_BlendFloat( fBlend, Whr_GetFloat(&Weathers[nw1],"Sun.AzimuthAngle"), Whr_GetFloat(&Weathers[nw2],"Sun.AzimuthAngle") );
		Weather.Sun.Ambient = Whr_BlendColor( fBlend, Whr_GetColor(&Weathers[nw1],"Sun.Ambient"), Whr_GetColor(&Weathers[nw2],"Sun.Ambient") );
		Sky.Color = Whr_BlendColor( fBlend, Whr_GetColor(&Weathers[nw1],"Sky.Color"), Whr_GetColor(&Weathers[nw2],"Sky.Color") );
	}
	Whr_addwind2weather(&Weather);
    //arWeather.Lightning.Enable = false;
    Whr_addRain2weather(&Weather);
    //Whr_addfog2weather(&Weather);
    //Whr_addWaves2weather(&Sea);
}

int FindWeatherByHour(int nHour)
{
	// trace("getting weather by hour.  Stormy sky: " + WeathersNH.StormSky);
	for (int n=0; n<MAX_WEATHERS; n++)
	{
		if (!CheckAttribute(WeathersNH, "StormSky") || WeathersNH.StormSky==false){
			// trace("Calm weather");
			if (!CheckAttribute(&Weathers[n], "hour")) {continue;}
			if (CheckAttribute(&Weathers[n], "skip") && sti(Weathers[n].skip)==true) {continue;}
			if (CheckAttribute(&Weathers[n], "Storm") && sti(Weathers[n].Storm)==true) {continue;}
			if( sti(Weathers[n].hour.min) == nHour ) {return n;}

		}else{
			// trace("Stormy weather");
			if (CheckAttribute(&Weathers[n], "Storm") && sti(Weathers[n].Storm)==false) {continue;}
			if (sti(Weathers[n].hour.min) > sti(Weathers[n].hour.max))
			{
				if (nHour < sti(Weathers[n].hour.min) && nHour > sti(Weathers[n].hour.max)) {return n;}
			}
			if (sti(Weathers[n].hour.min) < sti(Weathers[n].hour.max))
			{
				if (nHour < sti(Weathers[n].hour.min) || nHour > sti(Weathers[n].hour.max)) {return n;}
			}
		}
	}
	return -1;
}

int FindBlendWeather(int iWeatherNum)
{
	if( iWeatherNum<0 || iWeatherNum>=MAX_WEATHERS ) {return -1;}

	if( !CheckAttribute(&Weathers[iWeatherNum], "hour") ) {return -1;}
	if( CheckAttribute(&Weathers[iWeatherNum],"Storm") && sti(Weathers[iWeatherNum].Storm)==true ) {return -1;}
	if( CheckAttribute(&Weathers[iWeatherNum],"skip") && sti(Weathers[iWeatherNum].skip)==true ) {return -1;}

	int nBlendWeatherHour = sti(Weathers[iWeatherNum].hour.min) + 1;
	if( nBlendWeatherHour>=24 ) {nBlendWeatherHour = 0;}

	return FindWeatherByHour(nBlendWeatherHour);
}

void CreateWeather(int sExecuteLayer, int sRealizeLayer)
{
	CreateWeatherEnvironment();
	MoveWeatherToLayers(sExecuteLayer, sRealizeLayer);
}

void DeleteWeather()
{
	DeleteWeatherEnvironment();
}

void MoveWeatherToLayers(int sExecuteLayer, int sRealizeLayer)
{
	LayerDelObject(EXECUTE,&Weather);
	LayerDelObject(REALIZE,&Weather);
	LayerDelObject(SEA_EXECUTE,&Weather);
	LayerDelObject(SEA_REALIZE,&Weather);

	sNewExecuteLayer = sExecuteLayer;
	sNewRealizeLayer = sRealizeLayer;

	LayerAddObject(sExecuteLayer,&Weather,1000000);
	LayerAddObject(sRealizeLayer,&Weather,65530);

	MoveRainToLayers(sExecuteLayer, sRealizeLayer);
	MoveLightningToLayers(sExecuteLayer, sRealizeLayer);
	MoveSkyToLayers(sExecuteLayer, sRealizeLayer);
	MoveSunGlowToLayers(sExecuteLayer, sRealizeLayer);
	MoveAstronomyToLayers(sExecuteLayer, sRealizeLayer);
}

float Whr_GetFogDensity() { return fFogDensity; }

float Whr_GetWindAngle()
{
	if (!CheckAttribute(&Weather,"Wind.Angle")) { return 0.0; }
	return stf(Weather.Wind.Angle);
}

float Whr_GetWindSpeed()
{
	if (!CheckAttribute(&Weather,"Wind.Speed")) { return 3.0; }
	return stf(Weather.Wind.Speed);
}

ref Whr_GetShadowDensity()
{
	aref	aCurWeather = GetCurrentWeather();

	iShadowDensity[0] = argb(255,96,96,96);
	iShadowDensity[1] = argb(255,96,96,64);

	if (bWeatherLoaded)
	{
		iShadowDensity[0] = Whr_GetColor(aCurWeather,"Shadow.Density.Head");
		iShadowDensity[1] = Whr_GetColor(aCurWeather,"Shadow.Density.Foot");
	}
	return &iShadowDensity;
}

string	Whr_GetCurrentFog() { return sCurrentFog; }

string	Whr_GetInsideBack() { return sInsideBack; }

string	GetLightingPath()
{
    //navy -->
	if (CheckAttribute(&WeatherParams, "Rain") && sti(WeatherParams.Rain))
	{
		return Whr_GetRainyLightningPath();
	}
    //navy <--

	return sLightingPath;
}

string	GetLmLightingPath()
{
    //navy -->
	if (CheckAttribute(&WeatherParams, "Rain") && sti(WeatherParams.Rain))
	{
	    int nLoc = FindLoadedLocation();
	    if(nLoc > -1 && !CheckAttribute(&Locations[nLoc], "QuestlockWeather"))
            return "storm";
	}
    //navy <--
	return sLmLightingPath;
}

bool	Whr_IsDay() { return !bWeatherIsNight; }
bool	Whr_IsNight() { return bWeatherIsNight; }
bool	Whr_IsLight() { return bWeatherIsLight; }
bool	Whr_IsRain() { return bWeatherIsRain; }
bool	Whr_IsStorm() { return bWeatherIsStorm; }

int FindWeather(string sWeatherID)
{
	for (int i=0;i<MAX_WEATHERS;i++)
	{
		if (!CheckAttribute(&Weathers[i], "id"))
		{
			continue;
		}
		if(Weathers[i].id == sWeatherID)
		{
			return i;
		}
	}
	return -1;
}

void Whr_SetRainSound(bool _set, bool _isNight)
{
//	return;
	string scheme = "land";
	if (!bSeaActive || bAbordageStarted)
	{
		if (IsEntity(loadedLocation) && CheckAttribute(loadedLocation, "type"))
		{
			switch (loadedLocation.type)
			{
			case "town":
				scheme = "town";
				break;
			case "land":
				scheme = "land";
				break;
			case "deck":
				scheme = "deck";
				break;
			}
		}
	}
	else
	{
		scheme = "sea";
	}
	if (_isNight)
    {
		scheme = scheme+"_night";
    }
	else
	{
		scheme = scheme+"_day";
	}
	if (_set)
	{
		scheme = scheme + "_rain";
	}
	//trace(": Set Rain Sound... " + _set);
	SetSoundScheme(scheme);
}

string Whr_GetRainyLightningPath()
{
	//trace("__GET__COL__");
	return "evening3"; //storm1";
}
//navy <--

void Whr_WindChange()
{
	aref aCurWeather = GetCurrentWeather();

    // if(CheckAttribute(pchar, "wind.angle"))
    // {
    // 	Weather.Wind.Angle = stf(pchar.wind.angle) +  frand((PI/4.0)) - (PI / 8.0);
    // 	if (stf(Weather.Wind.Angle) < 0)  Weather.Wind.Angle = PIm2 + stf(Weather.Wind.Angle);
    // }
    // else
    // {
	// 	Weather.Wind.Angle = frand(PIm2);
	// }
	Weather.Wind.Angle = Whr_GetLong(&WeathersNH, "Wind.Angle");
	pchar.wind.angle = Weather.Wind.Angle;



	Weather.Wind.Speed = Whr_GetFloat(aCurWeather,"Wind.Speed");
	//Weather.Wind.Speed = Whr_GetFloat(&WeathersNH,"Wind.Speed");
	pchar.wind.speed = Weather.Wind.Speed;

	pchar.quest.EraseWind.win_condition.l1 = "ExitFromSea";
	pchar.quest.EraseWind.win_condition = "EraseWind";

	fWeatherAngle = stf(Weather.Wind.Angle);
	fWeatherSpeed = stf(Weather.Wind.Speed);

	// CheckIslandChange();
}

bool Whr_isRainEnable()
{
	bool bRain  = true;

	if (bCabinStarted) bRain = false;
	if (CheckAttribute(GetMainCharacter(), "HeroParam") && IsEntity(&loadedLocation)) // pchar ??????????? ??? ?? ????
	{
        if (CheckAttribute(&loadedLocation, "environment.weather.rain") && !sti(loadedLocation.environment.weather.rain))
		{
			bRain = false;
		}
		else
		{
			if (CheckAttribute(loadedLocation, "type"))
			{
				if(loadedLocation.type == "residence"
					|| loadedLocation.type == "tavern"
					|| loadedLocation.type == "house"
					|| loadedLocation.type == "shop"
					|| loadedLocation.type == "shipyard"
					|| loadedLocation.type == "church" )
				{
					bRain = false;
				}
			}
		}
	}
	else
	{
		if (bSeaActive && bAbordageStarted ) // bLandInterfaceStart
		{
			if (IsEntity(&loadedLocation) && CheckAttribute(&loadedLocation, "environment.weather.rain") && !sti(loadedLocation.environment.weather.rain))
			{
				bRain = false;
			}
		}
	}
	return bRain;
}

void Whr_addwind2weather(ref tmpweather)
{
	tmpweather.Wind.Angle = Whr_GetFloat(&WeathersNH, "Wind.Angle");
	//tmpweather.Wind.Speed.Min = Whr_GetFloat(&WeathersNH, "Wind.Speed.Min");
	//tmpweather.Wind.Speed.Max = Whr_GetFloat(&WeathersNH, "Wind.Speed.Max");
	tmpweather.Wind.Speed = Whr_GetFloat(&WeathersNH, "Wind.Speed");

	// Weather.Wind.Angle = sti(WeathersNH.Wind.Angle;
	// Weather.Wind.Speed.Min = sti(WeathersNH.Wind.Speed.Min;
	// Weather.Wind.Speed.Max = sti(WeathersNH.Wind.Speed.Max;
}

void Whr_addfog2weather(ref tmpweather, int nw1, int nw2)
{
	// trace("Fog height: " + sti(WeathersNH.Fog.Height + " fog density:" + sti(WeathersNH.Fog.Density + " fog seadensity:" + sti(WeathersNH.Fog.SeaDensity)

    if( nw1<0 || nw1>=MAX_WEATHERS ) {return;}

	string sCurFog = Whr_GetCurrentFog();
	if( nw2<0)
	{
        tmpweather.Fog.Enable = Whr_GetLong(&WeathersNH, sCurFog + ".Enable");
        tmpweather.Fog.Start = Whr_GetFloat(&WeathersNH, sCurFog + ".Start");
        tmpweather.Fog.Density = Whr_GetFloat(&WeathersNH, sCurFog + ".Density"));
        tmpweather.Fog.Color = Whr_getCurrentBlendedFogColor();
        tmpweather.Fog.IslandDensity = Whr_GetFloat(&WeathersNH, "Fog.IslandDensity");
        tmpweather.Fog.SeaDensity = Whr_GetFloat(&WeathersNH, sCurFog + ".SeaDensity");
	}
	else
	{
		float fBlend = stf(Environment.Time) - sti(Environment.Time);

        tmpweather.Fog.Enable = Whr_GetLong(&WeathersNH, sCurFog + ".Enable");
		tmpweather.Fog.Start = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".Start"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".Start") );
		tmpweather.Fog.Density = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".Density"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".Density") );
		tmpweather.Fog.Color = Whr_BlendColor( fBlend, Whr_getCurrentBlendedFogColor(), Whr_GetColor(&Weathers[nw2], sCurFog + ".Color") );
		tmpweather.Fog.IslandDensity = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, "Fog.IslandDensity"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".IslandDensity") );
		tmpweather.Fog.SeaDensity = Whr_BlendFloat( fBlend, Whr_GetFloat(&WeathersNH, sCurFog + ".SeaDensity"), Whr_GetFloat(&Weathers[nw2], sCurFog + ".SeaDensity") );
	}

	int rainfogcolor;
	if (iCurWeatherHour<6 || iCurWeatherHour>19){
		rainfogcolor = argb(0,20,15,15);
	}else{
		int lightfog = argb(0,230,230,230);
		int darkfog = argb(0,50,60,65);
		fblend = MakeFloat(wRain)/100.0;
		rainfogcolor =  Whr_BlendColor(fblend, lightfog, darkfog);
	}
	// trace("light fog: " + lightfog + " dark fog: " + darkfog + " blended fog:" + rainfogcolor + " blend constant: " + fblend);


	float tmpdensity = Whr_GetFloat(&WeathersNH, "Fog.Density");
	// trace("sti(WeathersNH.Fog.Density: " + tmpdensity + " before clamp: " + tmpdensity*100.0);
	float fblend2 = Clampf(tmpdensity*100.0);

	//int rainfogcolor2 =  Whr_BlendColor(fblend2, tmpweather.Bak.Fog.Color, rainfogcolor);
	// trace("weather fog: " + tmpweather.Bak.Fog.Color + " lightdark fog:" + rainfogcolor + " blended fog:" + rainfogcolor2 + " blend constant: " + fblend2);

	tmpweather.Fog.Color = rainfogcolor;
	//tmpweather.SpecialSeaFog.Color = rainfogcolor;
}

int Whr_getCurrentBlendedFogColor()
{
	int rainfogcolor;
	int lightfog = argb(0,230,230,230);
	int darkfog = argb(0,50,60,65);
	float fblend = MakeFloat(wRain)/100.0*0.8;

	if (iCurWeatherHour<6 || iCurWeatherHour>19){
		rainfogcolor = argb(0,20,15,15);
	}else{

		rainfogcolor =  Whr_BlendColor(fblend, lightfog, darkfog);
	}
	// trace("light fog: " + lightfog + " dark fog: " + darkfog + " blended fog:" + rainfogcolor + " blend constant: " + fblend);


	float tmpdensity = Whr_GetFloat(&WeathersNH, "Fog.Density");
	// trace("sti(WeathersNH.Fog.Density: " + tmpdensity + " before clamp: " + tmpdensity*100.0 + "Current weather color: " + Whr_GetLong(Weathers[iCurWeatherNum], "Bak.Fog.Color"));
	float fblend2 = Clampf(tmpdensity*100.0);

	int rainfogcolor2 =  Whr_BlendColor(fblend2, Whr_GetLong(&Weathers[iCurWeatherNum], "Bak.Fog.Color"), rainfogcolor);
	// trace("final color: " + rainfogcolor2);

	return rainfogcolor2;
}

void Whr_addRain2weather(ref tmpweather)
{
//trace("Whr_addRain2weather called");
	// tmpweather.Sun.Glow.Enable = false;
	// tmpweather.Sun.Overflow.Enable = false;

	tmpweather.Rain.NumDrops = sti(WeathersNH.Rain.NumDrops);
	tmpweather.Rain.Color = sti(WeathersNH.Rain.Color);
	tmpweather.Rain.DropLength = sti(WeathersNH.Rain.DropLength);
	tmpweather.Rain.Height = sti(WeathersNH.Rain.Height);
	tmpweather.Rain.Radius = sti(WeathersNH.Rain.Radius);
	tmpweather.Rain.Speed = sti(WeathersNH.Rain.Speed);
	tmpweather.Rain.Jitter = sti(WeathersNH.Rain.Jitter);
	tmpweather.Rain.WindSpeedJitter = sti(WeathersNH.Rain.WindSpeedJitter);
	tmpweather.Rain.MaxBlend = sti(WeathersNH.Rain.MaxBlend);
	tmpweather.Rain.TimeBlend = sti(WeathersNH.Rain.TimeBlend);

	// trace("WeathersNH LE:" + sti(WeathersNH.Lightning.Enable);

	//if (CheckAttribute(&WeathersNH,"Lightning.Enable")) {WeathersNH.Lightning.Enable = sti(WeathersNH.Lightning.Enable);}
	Lightning.Texture = "Weather\lightning\lightning_storm.tga.tx";
	Lightning.FlickerTime = 32;
	Lightning.SubTexX = 4;
	Lightning.SubTexY = 1;
	Lightning.ScaleX = 0.7;
	Lightning.ScaleY = 1.0;
	Lightning.Flash.Texture = "Weather\lightning\flash.tga.tx";
}

void Whr_addWaves2weather(ref tmpweather){
//trace("Whr_addWaves2weather called");
	tmpweather.Sea2.BumpScale = Whr_GetFloat(&WeathersNH, "Sea2.BumpScale");
	tmpweather.Sea2.PosShift = Whr_GetFloat(&WeathersNH, "Sea2.PosShift");

	tmpweather.Sea2.Amp1 = Whr_GetFloat(&WeathersNH, "Sea2.Amp1");
	tmpweather.Sea2.AnimSpeed1 = Whr_GetFloat(&WeathersNH, "Sea2.AnimSpeed1");
	tmpweather.Sea2.Scale1 = Whr_GetFloat(&WeathersNH, "Sea2.Scale1");
	tmpweather.Sea2.MoveSpeed1 = Whr_GetString(&WeathersNH, "Sea2.MoveSpeed1");

	tmpweather.Sea2.Amp2 = Whr_GetFloat(&WeathersNH, "Sea2.Amp2");
	tmpweather.Sea2.AnimSpeed2 = Whr_GetFloat(&WeathersNH, "Sea2.AnimSpeed2");
	tmpweather.Sea2.Scale2 = Whr_GetFloat(&WeathersNH, "Sea2.Scale2");
	tmpweather.Sea2.MoveSpeed2 = Whr_GetString(&WeathersNH, "Sea2.MoveSpeed2");

	aref	aCurWeather = GetCurrentWeather();
	aref	aSea2; makearef(aSea2, aCurWeather.Sea2);
	aref	aSea; makearef(aSea, aCurWeather.Sea);

	tmpweather.Sea.Bump.Dir = Whr_GetString(aSea, "Bump.Dir");
	tmpweather.Sea.Bump.Tile = Whr_GetFloat(aSea, "Bump.Tile");
	tmpweather.Sea.Bump.Ang = Whr_GetFloat(aSea, "Bump.Ang");
	tmpweather.Sea.Bump.Speed = Whr_GetFloat(aSea, "Bump.Speed");
	tmpweather.Sea.Bump.Scale = Whr_GetFloat(aSea, "Bump.Scale");
	tmpweather.Sea.Bump.AnimSpeed = Whr_GetFloat(aSea, "Bump.AnimSpeed");
	tmpweather.Sea.Sky.Color = Whr_GetColor(aSea, "Sky.Color");
	tmpweather.Sea.Water.Color = Whr_GetColor(aSea,"Water.Color");

	tmpweather.Sea.Transparency = Whr_GetFloat(aSea,"Transparency");
	tmpweather.Sea.FrenelCoefficient = Whr_GetFloat(aSea,"FrenelCoefficient");
	tmpweather.Sea.WaterReflection = Whr_GetFloat(aSea,"WaterReflection");
	tmpweather.Sea.WaterAttenuation = Whr_GetFloat(aSea,"WaterAttenuation");

	tmpweather.Sea2.WaterColor = Whr_GetColor(aSea2, "WaterColor");
	tmpweather.Sea2.SkyColor = Whr_GetColor(aSea2, "SkyColor");
	tmpweather.Sea2.Reflection = Whr_GetFloat(aSea2, "Reflection");
	tmpweather.Sea2.Transparency = Whr_GetFloat(aSea2, "Transparency");
	tmpweather.Sea2.Attenuation = Whr_GetFloat(aSea2, "Attenuation");
	tmpweather.Sea2.Frenel = Whr_GetFloat(aSea2, "Frenel");
	tmpweather.Sea2.BumpScale = Whr_GetFloat(aSea2, "BumpScale");

	tmpweather.Sea2.FoamV = Whr_GetFloat(&WeathersNH, "Sea2.FoamV");
	tmpweather.Sea2.FoamK = Whr_GetFloat(&WeathersNH, "Sea2.FoamK");
	tmpweather.Sea2.FoamUV = Whr_GetFloat(&WeathersNH, "Sea2.FoamUV");
	tmpweather.Sea2.FoamTexDisturb = Whr_GetFloat(&WeathersNH, "Sea2.FoamTexDisturb");
}

// PB -->
string CheckCharacterEquipByGroup(ref chref, string groupID)
{
	string item = GetCharacterEquipByGroup(chref,groupID);
	if(CheckCharacterItem(chref,item)) return item;
	return "";
}
// PB <--

float GetTimeScale()
{
	float basetime = 1.0;
	ref pchar = GetMainCharacter();
	if(CheckAttribute(PChar,"basetime"))	basetime = stf(PChar.basetime);
	return basetime;
}

string Whr_getMoonTexture(){

	// PURSEON ========Begin Moon Phases at night code===========>
	string moonpic = "weather\sun\glow\moonglowfull.tga.tx";   //default in case moon state is not known
	switch (getMoonStateName(getMoonState())){
		case FULL_MOON:
			moonpic = "weather\sun\glow\moonglowfull.tga.tx";
		break;
		case NEW_MOON:
			moonpic = "weather\sun\glow\moonglownew.tga.tx";
		break;
		case QUARTER_ONE:
			moonpic = "weather\sun\glow\moonglowwaxc.tga.tx";
		break;
		case QUARTER_TWO:
			moonpic = "weather\sun\glow\moonglowwax.tga.tx";
		break;
		case QUARTER_THREE:
			moonpic = "weather\sun\glow\moonglowwan.tga.tx";
		break;
		case QUARTER_FOUR:
			moonpic = "weather\sun\glow\moonglowwanc.tga.tx";
		break;
	}

	return moonpic;
}

string getMoonStateName(float state)
{
	//Set a threshold for full and new moon
	float threshold = (FULL_MOON_DAYS/2.0)/MOON_CYCLE;
	//Check for full moon
	if(state >= (0.5-Threshold) && state <= (0.5+Threshold))
	{
		return FULL_MOON;
	}
	//Check for new moon
	if(state >= (1-Threshold) || state <= (0+Threshold))
	{
		return NEW_MOON;
	}
	//Else return a normal state
	if(state >= 0.75) return QUARTER_FOUR;
	if(state >= 0.5) return QUARTER_THREE;
	if(state >= 0.25) return QUARTER_TWO;
	return QUARTER_ONE;
}

float getMoonState()
{
	//This returns a value between 0 and 1 where 0 is a new moon and 0.5 is a full moon.
	int days_since_epoch = GetPastTime("day", GetDataYear(),GetDataMonth() ,GetDataDay(), GetTime(), 1900,1,1,GetTime());
	float state = (1.0-fmod2(MakeFloat(days_since_epoch), MOON_CYCLE))+0.5;
	if(state>=1)
	{
		state -= 1.0;
	}
	return state
}

float getMoonIntensity()
{
	//will return a value between 0 and 1 on how much light the moon produces with 1 being max.
	float state = getMoonState();
	state *= 2;
	if(state>1) state = 2-state;
	return state;
}

bool IsFullMoon(int accuracy)
{
	//accuray is a number of days which the full moon periode last. If put on 0 the default will be taken.
	if(accuracy<1)
	{
		accuracy = FULL_MOON_DAYS;
	}
	//Get the state of the moon.
	float cycle = getMoonState();
	//When the cycle gives 0.5 its a full moon we now calculate the Threshold value.
	float threshold = (accuracy/2.0)/MOON_CYCLE;
	if(threshold>0.5)
	{
		return true;
	}
	if(cycle >= (0.5-Threshold) && cycle <= (0.5+Threshold))
	{
		return true;
	}
	return false;
}

float fmod2(float x, float y)
{
	if (y == 0.0) return 0.0;
	return ((x / y) - (x % y));
}