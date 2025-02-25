// Quiet-Sun, ChezJfrey, Mirsaneli

#include "Weather\Init\WhrFogRainCheck.c"
#include "Weather\Init\WhrGenerateValues.c"
// #include "scripts\lagoon_mod.c"

#define GENERATIONDEBUG 0
#define RANDOMDEBUG 1

// wRain levels
#define WRAINOVERCAST 30
#define WRAINRAIN 50
#define WRAINSTORM 70
#define WRAINTORNADO 90
// Night and lagoon color properties
#define NIGHTCOLORBLEND 6.0
#define SHORECOLORDISTANCE 20.0

// Evolution of fog on the generator
#define MINIMUMFOG 2
#define FOG2TRANSPARENCY 150.0

#define WIND2WAVESPEED 0.22
#define WIND2WAVELENGTH 5.5
#define WIND2AMPLITUDE 0.45

#define RAIN2AMPLITUDE 2.0
#define RAIN2WIND 1.0

#define WIND2WAVELENGTH2 2.5
#define WIND2AMPLITUDE2 0.25
#define WIND2FOAMV 1.0

#define AMPLITUDERANDOM 0.25
#define SCALERANDOM 0.4
#define FOAMRANDOM 0.020

void Whr_ResetOvrd(){
	OWeatherAngle = -50.0;
	OWABallast = -50.0;
	OFog = -50;
	OFBallast = -50;
	ORain = -50;
	ORBallast = -50;
	OWind = -50;
	OWBallast = -50;
	gWeatherOvrd = false;
}

void Whr_Generator(int iHour){
// ====================================================================
// JL - Less Random Weather Generator -- hopefully
// ====================================================================

    bool morningFog = false; //Have no idea what this was supposed to be, doesn't exist in mine
	//Traceandlog("WhrInit.c : Whr_Generator() called -- gWeatherInit: " +gWeatherInit); //JL - Figuring out this weather system
	bool bWhrTornado = false;
	bool bWhrStorm = false;

	if(gWeatherInit == 1){
		goldRain = rand(100);
		goldFog = rand(20);
//		oldWind = rand(30);
		oldWind = rand(25) + 5;		// LDH 09Feb09
		fWeatherAngleOld = frand(PIm2);
		gWeatherInit = 0;
		fogBallast = 0;
		rainBallast = 0;
		windBallast = 0;
		windABallast = 0;
		Trace(" !gWeatherInit Whr_Generator() - Initialized ");
	}

	//Logit("BugTracker - goldFog: " + goldFog + " goldRain: " + goldRain + " oldWind: " + oldWind + " gWeatherInit: " + gWeatherInit);
	curTime = iHour; //MakeInt(GetHour()); //Causing problems
	//#20220311-01
	//bWeatherIsStorm = false; // screwface
	//bWeatherIsRain = false; // screwface

	rWind = rand(MAX_WINDCHANGE);
	rFog = rand(MAX_FOGCHANGE);
	rRain = rand(MAX_RAINCHANGE);
	rWindA = frand(MAX_ANGLECHANGE);

	Whr_GenerateValues(FREE_FOG);

	if(gWeatherOvrd){
		if(oWeatherAngle != -50.0){fWindA = OWeatherAngle;	}
		if(OWABallast != -50.0){windABallast = OWABallast; }
		if(OFog != -50){fog = OFog;}
		if(OFBallast != - 50){fogBallast = OFBallast;}
		if(ORain != -50){wRain = ORain;}
		if(ORBallast != -50){rainBallast = ORBallast;}
		if(OWind != -50){winds = OWind;}
		if(OWBallast != -50){windBallast = OWBallast;}
		Whr_ResetOvrd();
	}

	if (CheckAttribute(&WeatherParams,"Storm")) { bWhrStorm = sti(WeatherParams.Storm); }
	if (CheckAttribute(&WeatherParams,"Tornado")) { bWhrTornado = sti(WeatherParams.Tornado); }
	//#20220311-01
	//WeatherParams.Storm = false;
	//WeatherParams.Tornado = false;
	bool bStormAlreadyStarted = bWeatherIsStorm;
    if (bWeatherIsStorm) bWhrStorm = true;

	if(bWhrStorm && !bWeatherIsStorm){
		wRain = 95;
		winds = 25;
		windBallast = 10;
		rainBallast = 10;
		fog = 75; //Armada
		//WeathersNH.Fog.Color = argb(0,33,40,50);
		bWeatherIsStorm = true; // screwface
	}
	if(bWhrTornado){
		wRain = 100;
		winds = 30;
		windBallast = 20;
		rainBallast = 20;
		fog = 75; //Armada
		//WeathersNH.Fog.Color = argb(0,33,40,50);
	}
	btornado = bWhrTornado; //screwface
	bstorm = bWhrStorm; //screwface

	goldRain = wRain;
	goldFog = fog;
	oldWind = winds;
	fWeatherAngleOld = fWindA;

	if(windABallast >=  MAX_ABALLAST || windABallast <= -MAX_ABALLAST ){ windABallast = 0;}
	if(rainBallast  >=  MAX_RBALLAST )                                 { rainBallast = -MAX_RBALLAST;}
	if(rainBallast  <= -MAX_RBALLAST )                                 { rainBallast =  MAX_RBALLAST;}
	if(windBallast  >=  MAX_WBALLAST )                                 { windBallast = -MAX_WBALLAST;}
	if(windBallast  <= -MAX_WBALLAST )                                 { windBallast =  MAX_WBALLAST;}
	if(fogBallast   >=  MAX_FBALLAST )                                 { fogBallast  = -MAX_FBALLAST;}
	if(fogBallast   <= -MAX_FBALLAST )                                 { fogBallast  =  MAX_FBALLAST;}

	if(wRain >= 85 && winds <= 10){ windBallast = 15;}
	if(winds <= 25 && wRain >= 90){ rainBallast = -15;}
	if(fog > 0 && curTime >= 7 && curTime <= 20 && wRain <= 75){fogBallast = -30;}
	if(fogBallast < 0 && curTime > 20 || curTime < 7){fogBallast = 0;}
	if(fogBallast < 0 && curTime >= 7 && curTime <=20 && wRain > 75){fogBallast = 0;}

	minwind = winds - rand(2);
	maxwind = winds + rand(2);
	if(minwind < 5){minwind = 5;}	// LDH up from 0 - 12Feb09
	if(maxwind > 30){maxwind = 30;}
	if(minwind > maxwind){ minwind = maxwind; } // JL - Temporary catch all for weird wind bug

	// Whr_InitGValues(); //Setup generic values based on ToD
	Whr_FogRainCheck();	 //Set wRain and fog values

	// NK & Mith-->
	// LDH fixes - 16Mar09
	string direction1, direction2, direction3;

	fSeaA = PIm2 - fWindA;
	if (fSeaA >= (3.0 * PId2))
	{
		fSeaB = (fSeaA + PId2 - PIm2);
	}
	else
	{
		fSeaB = fSeaA + PId2;
	}
	WeathersNH.Wind.Angle = fWindA;
	WeathersNH.Wind.Speed.Min = minwind;
	WeathersNH.Wind.Speed.Max = maxwind;
	float seaWindSpeed = Whr_GetFloat(&WeathersNH,"Wind.Speed");
	WeathersNH.Wind.seaWindSpeed = seaWindSpeed;

	direction1 = fts(fSeaB, 4);
	direction2 = fts((fSeaB + (PId2 / 2.0)), 4);
	direction3 = fts((fSeaB - (PId2 / 2.0)), 4);

	float myWind = maxwind;
	if (maxwind > 25.0 && !bWhrStorm && !bWhrTornado)
		myWind = 25.0;

	float windStrength1 = myWind / 26.0;
	float windStrength2 = myWind / 30.0;
	float windStrength3 = myWind / 28.0;

	string seaStrength1 = f2s(windStrength1, 4);
	string seaStrength2 = f2s(windStrength2, 4);
	string seaStrength3 = f2s(windStrength3, 4);

	string waveSpeed = "-78.0";
	if(REALISTIC_WAVES == 1)
	{
		// Note on the piece of code below: each line, numbered 1, 2 and 3, are each separate "generators" of waves,
		// each controlling the different aspects of the harmonics model.
		// The first line controls the height, direction and speed of the wave.
		// The second line controls the direction, speed and height of the entire surface.
		// The third line controls the direction, height and speed of each wave.
		// The value changed is "waveLength#"
		// (waveLength1 is equal to 20 right now, wavelength2 is equal to 0.01, and wavelength3 is equal to 10).
		// For example, setting the second and third line to 0.01 (minimum value) while keeping the first line as the
		// same number would make the waves go in a single direction, without changing shape or breaking.
		// Setting all numbers for "generators" to an equal value would create perfect harmonic waves.
		// If you are not satisfied with the waves in this mod, please modify the values that right now say "20", "0.01" and "10"

		//WeathersNH.Sea.Harmonics.h1 = direction1 + ",20.0," + seaStrength1 + ",80.87," + waveSpeed;
		//WeathersNH.Sea.Harmonics.h2 = direction2 + ",0.01," + seaStrength2 + ",82.28," + waveSpeed;
		//WeathersNH.Sea.Harmonics.h3 = direction3 + ",10.0," + seaStrength3 + ",82.28," + waveSpeed;
		if(bWhrStorm) //screwface
		{
			 // screwface
			if(bSeaActive && !ownDeckStarted())
			{
			    //#20220311-01
			    if (!bStormAlreadyStarted)
                    iStormLockSeconds = 60;
				Seafoam.storm = "true";
				//bstorm = true;
				// Build 13 fog - Armada -> (fog effects changed and moved to lines 85 and 94)
				/*WeathersNH.Fog.Enable = true;
				WeathersNH.Fog.Height = 500.0;
				WeathersNH.Fog.Start = 0.0;
				WeathersNH.Fog.Density = 10.0;
				WeathersNH.Fog.SeaDensity = 0.019;
				WeathersNH.Fog.Color = argb(0,33,40,50);*/
				// Build 13 fog - Armada <-
				WeathersNH.Sea.Sky.Color = argb(0,255,255,255);
				WeathersNH.Sea2.SkyColor = argb(0,255,255,255);
				//WeathersNH.Sea.Water.Color = argb(0,0,0,10);
				//WeathersNH.Sea.Pena.Color = argb(0,100,100,100);
				//WeathersNH.Sea.Bump.Tile = 0.07;
				//WeathersNH.Sea.Bump.Ang = 2.0;
				//WeathersNH.Sea.Bump.Speed = 0.01;
				//WeathersNH.Sea.Bump.AnimSpeed = 23.0;
				//WeathersNH.Sea.Bump.Scale = 2.0;
				//WeathersNH.Sea.Harmonics.h1 = "0.0,10.0,0.1202,80.87,-68.00";
				//WeathersNH.Sea.Harmonics.h2 = "1.57,10.0,2.1002,82.28,88.00";
				//WeathersNH.Sea.Harmonics.h3 = "0.47,7.0,2.2002,82.28,68.00";
				//WeathersNH.Sea.Harmonics.h4 = "0.27,47.0,0.0502,82.28,288.00"; //
				//WeathersNH.Sea.Harmonics.h5 = "1.27,57.0,0.0702,82.28,188.00";
				//WeathersNH.Sea.Harmonics.h6 = "2.27,57.0,0.0302,82.28,88.00";
				//WeathersNH.Sea.Harmonics.h7 = "2.27,37.0,0.1402,82.28,188.00";
				//WeathersNH.Sea.Harmonics.h8 = "2.77,17.0,0.0502,82.28,288.00";
				//WeathersNH.Sea.Harmonics.h9 = "1.77,17.0,0.1002,82.28,188.00";
				//WeathersNH.Sea.Harmonics.h10 = "1.0,14.0,0.5002,82.28,28.00"; //
				if(Characters[GetMainCharacterIndex()].location !="")
				{
					Sea.MaxSeaHeight = 50.0;
				}
			}
		}
		/*
		else
		{
			if(bSeaActive && !ownDeckStarted())
			{
				Seafoam.storm = "false";
				//bstorm = false;
				if(Characters[GetMainCharacterIndex()].location !="")
				{
					//if(stf(Sea.MaxSeaHeight)!=3.0) {Sea.MaxSeaHeight = 3.0;traceandlog("waves heights restored");}
					float Maxheights = (wrain + winds) - 70;
					if(maxheights<3) Sea.MaxSeaHeight = 3.0;
					else Sea.MaxSeaHeight = Maxheights;
					if(wrain < 75) Sea.MaxSeaHeight = 3.0;
					//traceandlog("waves heights : " + Sea.MaxSeaHeight);
				}
			}
		} //screwface : end
		*/
	}
	//else
	//{
	//	float wave1 = 5  + windStrength2 * 3;
	//	float wave2 = 10 + windStrength1 * 3;
	//	float wave3 = 10 + windStrength3 * 3;

	//	string waveLength1 = f2s(wave1, 4);
	//	string waveLength2 = f2s(wave2, 4);
	//	string waveLength3 = f2s(wave3, 4);

	//	WeathersNH.Sea.Harmonics.h1 = direction1 + "," + waveLength1 + "," + seaStrength1 + ",0," + waveSpeed;
	//	WeathersNH.Sea.Harmonics.h2 = direction2 + "," + waveLength2 + "," + seaStrength2 + ",0," + waveSpeed;
	//	WeathersNH.Sea.Harmonics.h3 = direction3 + "," + waveLength3 + "," + seaStrength3 + ",0," + waveSpeed;
	//}

	// Whr_DebugInfo();


	float effectiveRain = (wRain-75)*RAIN2WIND;
	if (effectiveRain < 0) effectiveRain = 0;

	// Wave amplitude
	float Amp1rand = 2.0*(frnd()-0.5)*AMPLITUDERANDOM + 1.0;
	float Amp1 = (0.25 + WIND2AMPLITUDE*(seaWindSpeed*Amp1rand + RAIN2AMPLITUDE*effectiveRain));
	WeathersNH.Sea2.Amp1 = Amp1;
	WeathersNH.Sea2.AnimSpeed1 = 3.0;

	// Wave Length
	float Scale1rand = 2.0*(frnd()-0.5)*SCALERANDOM + 1.0;
	float scale1 = WIND2WAVELENGTH/(seaWindSpeed + effectiveRain);
	if (scale1 > 1.0) {scale1 = 1.0;}
	scale1 = scale1*Scale1rand;
	WeathersNH.Sea2.Scale1 = scale1;

	string waveSpeedX = f2s(-WIND2WAVESPEED*(winds + effectiveRain)*sin(fWindA), 2);
	string waveSpeedZ = f2s(-WIND2WAVESPEED*(winds + effectiveRain)*cos(fWindA), 2);
	WeathersNH.Sea2.MoveSpeed1 = waveSpeedX + ", 0.0, " + waveSpeedZ;

	// Amplitude 2
	float Amp2rand = 1.0*(frnd()-0.5)*AMPLITUDERANDOM + 1.0;
	float Amp2 = 0.5 + WIND2AMPLITUDE*WIND2AMPLITUDE2*(seaWindSpeed + effectiveRain);
	WeathersNH.Sea2.Amp2 = Amp2*Amp2rand;
	WeathersNH.Sea2.AnimSpeed2 = 3.0;

	// Wavelength 2
	float Scale2rand = 2.0*(frnd()-0.5)*SCALERANDOM + 1.0;
	WeathersNH.Sea2.Scale2 = WIND2WAVELENGTH*WIND2WAVELENGTH2/(seaWindSpeed + effectiveRain)*Scale2rand;


	// float randomDir = frnd()*PI;
	// trace("random dir: " + randomDir);
	string waveSpeed2X = f2s(-WIND2WAVESPEED*WIND2WAVELENGTH2*(seaWindSpeed + effectiveRain)*sin(fWindA), 2);
	string waveSpeed2Z = f2s(-WIND2WAVESPEED*WIND2WAVELENGTH2*(seaWindSpeed + effectiveRain)*cos(fWindA), 2);
	WeathersNH.Sea2.MoveSpeed2 = waveSpeed2X + ", 0.0, " + waveSpeed2Z;

	// Foam properties
	WeathersNH.Sea2.FoamEnable = true;
	
	// Storm foam generation
	if (bWeatherIsStorm) {
    float foamstorm = 4.0 * (frnd() - 1.5) * FOAMRANDOM;
    WeathersNH.Sea2.FoamV = Amp1 * (0.54 + foamstorm);
    WeathersNH.Sea2.FoamK = 0.062 - 0.05 * effectiveRain / RAIN2WIND / 25.0;
    WeathersNH.Sea2.FoamUV = 0.5;
    WeathersNH.Sea2.FoamTexDisturb = 0.7;
	}
	// Tornado foam generation
	else if (bWhrTornado) {
    float foamtornado = 4.0 * (frnd() - 1.5) * FOAMRANDOM;
    WeathersNH.Sea2.FoamV = Amp1 * (0.54 + foamtornado);
    WeathersNH.Sea2.FoamK = 0.062 - 0.05 * effectiveRain / RAIN2WIND / 25.0;
    WeathersNH.Sea2.FoamUV = 0.5;
    WeathersNH.Sea2.FoamTexDisturb = 0.7;
	}
	// Normal condition foam generation
	else {
    float foamrand = 2.5 * (frnd() - 0.5) * FOAMRANDOM;
    WeathersNH.Sea2.FoamV = Amp1 * (0.75 + foamrand);
    WeathersNH.Sea2.FoamK = 0.15 - 0.05 * effectiveRain / RAIN2WIND / 25.0;
    WeathersNH.Sea2.FoamUV = 0.5;
    WeathersNH.Sea2.FoamTexDisturb = 0.7;
	}

	// Sea properties
	WeathersNH.Sea2.Attenuation = 0.2;

	float fblend = 0;
	float fblend2 = 0;

	float transparency  = 0.5;

	// Evening

	if (curTime>=18 || curTime<=22)
	{
		fblend = 0.3;
	}
	if (curTime==23 || curTime==5)
	{
		fblend = 0.75;
	}
	// Morning
	if (curTime>=6 || curTime<=10)
	{
		fblend = 0.5;
	}
	// Night
	if (curTime <=5)
	{
		fblend = 1;
		transparency = 0;
	}

	// Apply fog and rain to transparency
	effectiveRain = (wRain-WRAINRAIN)/(100 - WRAINRAIN);
	if (effectiveRain < 0) effectiveRain = 0;

	SetNHFogValues();

	float fog2trans = (Whr_GetFloat(&WeathersNH, "Fog.SeaDensity")-MINIMUMFOG*FOGFACTOR)*FOG2TRANSPARENCY + effectiveRain;
	transparency = transparency - fog2trans;
	trace("Fog to transparency: " + fog2trans);

	if (transparency < 0) transparency = 0.0;
	if (fog2trans > 1) fog2trans = 1.0;

	// Create blending constant for water color and fog color
	fblend2 = 0.40 - fog2trans;

	// Assume that the water is shore water
	int WaterColor = waterColor_Get(true);

	// Darken and make opaque it for evening and night
	int darkWater = argb(0,28,28,28);
	int grayWater = argb(0,100,100,100);

	WaterColor = Whr_BlendColor( fog2trans*0.8, WaterColor, grayWater);

	// Correct it, if it open sea
	pchar = GetMainCharacter();
	float closestdist = 0.0;
	// if (CheckAttribute(worldMap, "directsail1.closestdist")){
	// 	if (RANDOMDEBUG) trace("weather Char location: " + pchar.location + " closest island: " + worldMap.closestisland + "Closest distance: " + worldMap.directsail1.closestdist);
	// 	closestdist = worldMap.directsail1.closestdist;
	// 	if (RANDOMDEBUG) trace("closestdist: " + closestdist + "conditional: " + SHORECOLORDISTANCE);
	// }else{
	// 	if (RANDOMDEBUG) trace("weather Char location: " + pchar.location);
	// }

	int darkgrayWater = argb(0,20,20,20);

	if (CheckAttribute(pchar, "location")){

		if (pchar.location == WDM_NONE_ISLAND || closestdist > SHORECOLORDISTANCE)
		{
			WaterColor = waterColor_Get(false);
			WaterColor = Whr_BlendColor( fog2trans*0.8, WaterColor, darkgrayWater);
		}else{
			// If not open sea reduce the amount of water color and fog color
			fog2trans = (Whr_GetFloat(&WeathersNH, "Fog.SeaDensity")-MINIMUMFOG*FOGFACTOR)*FOG2TRANSPARENCY + effectiveRain;
			transparency = 1.2 - fog2trans;
			if (transparency < 0) transparency = 0.0;
			if (fog2trans > 1) fog2trans = 1.0;
			fblend2 = fblend2 - 0.05;
		}

	}else{
		WaterColor = waterColor_Get(false);
		WaterColor = Whr_BlendColor( fog2trans*0.8, WaterColor, darkgrayWater);
	}

	WaterColor = Whr_BlendColor( fblend, WaterColor, darkWater);




	// Blend fog between day and night
	int lightfog = argb(0,160,160,180);
	int darkfog = argb(0,0,0,0);


	int fogcolor = Whr_BlendColor(fblend, lightfog, darkfog);

	// Tint it with the water color
	if (fblend2<0.0) fblend2 = 0.0;
	fogcolor = Whr_BlendColor(fblend2, fogcolor, WaterColor);

	int dawnduskfogcolor;
	int dawnDuskSky;
	// Dawn or dusk fogs and sun color
	if (!morningFog){
		if (curTime == 22 || curTime == 6)
		{
			dawndusk_fog(&dawnduskfogcolor, &dawnDuskSky);
			fogcolor = Whr_BlendColor(fog2trans, dawnduskfogcolor, fogcolor);
			WeathersNH.Fog.Height = Whr_GetFloat(&WeathersNH, "Fog.Height") + 1000.0;
			WeathersNH.SpecialSeaFog.Height = Whr_GetFloat(&WeathersNH, "SpecialSeaFog.Height") + 1000.0;
		}
	}
	WeathersNH.Fog.Color = fogcolor;
	WeathersNH.SpecialSeaFog.Color = fogcolor;
}

string f2s(float fl,int nDigAfterPoint)
{
	float fmul = pow(10.0,nDigAfterPoint);
	fl = fl + 0.5/fmul;
	int p1 = makeint(fl);
	int p2 = makeint((fl-p1)*fmul);
	if (p1 == 0 && p2 == 0) return fts(fl,nDigAfterPoint);
	string minusstr = ""; if(fl < 0) minusstr = "-";
	string decimal = "0000000000" + abs(p2);
	decimal = strRight(decimal,nDigAfterPoint);
	string retval = minusstr + abs(p1) + "." + decimal;
	while (strRight(retval,1) == "0") retval = strLeft(retval, strLen(retval)-1);
	if (strRight(retval,1) == ".")    retval = strLeft(retval, strLen(retval)-1);
	return retval;
}

int waterColor_Get(bool isShore)
{
    int waterColor = argb(0,50,70,90);
    if( iCurWeatherNum > -1) {
        waterColor = sti(Weathers[iCurWeatherNum].Sea2.WaterColor);
    }
    else {
        if (isShore)
            waterColor = argb(0,5,138,181);
    }

	return waterColor;
}

void SetNHFogValues()
{
    if( iCurWeatherNum > -1) {
        WeathersNH.Fog.Color = Weathers[iCurWeatherNum].Fog.Color;
        WeathersNH.SpecialSeaFog.Color = Weathers[iCurWeatherNum].SpecialSeaFog.Color;
    }
    else {
        WeathersNH.Fog.Color = argb(0,135,168,205);
        WeathersNH.SpecialSeaFog.Color = argb(0,135,168,205);
    }
}

//--------------------------------------------------------------------------------
// Dawn/dusk randomizers (Quiet-Sun)

void dawndusk_fog(ref dawnDuskFogColor, ref dawnDuskskyColor)
{
	// Random number for the case, if you add more skies be sure to match the number of cases
	int fogNumber = rand(1);
	//if (RANDOMDEBUG) Trace("dawndusk_fog random number: " + fogNumber);

	switch(fogNumber)
    {
    case 0:
        // dawnDuskFogColor = argb(0,143,68,58);
        dawnDuskFogColor = argb(0,153,113,107);
		dawnDuskskyColor = argb(0,255,221,179);
        break;
    case 1:
        dawnDuskFogColor = argb(0,85,85,105);
		dawnDuskskyColor = argb(0,216,216,255);
        break;
	}

}

//--------------------------------------------------------------------------------
// Color randomizers (Quiet-Sun)

int waterColor_shore()
{

	// Random number for the case, if you add more colors be sure to match the number of cases
	int colorNumber = rand(6);
	if (RANDOMDEBUG) Trace("waterColor_shore random number: " + colorNumber);

	int waterColor;
	switch(colorNumber)
    {
    case 0:
        waterColor = argb(0,0,145,137);
        break;
    case 1:
        waterColor = argb(0,2,147,153);
        break;
    case 2:
        waterColor = argb(0,2,147,153);
        break;
    case 3:
        waterColor = argb(0,8,144,177);
        break;
    case 4:
        waterColor = argb(0,5,138,181);
        break;
    case 5:
        waterColor = argb(0,12,134,183);
        break;
    case 6:
        waterColor = argb(0,94,123,151);
        break;
	}

	return waterColor;
}


int waterColor_openSea()
{

	// Random number for the case, if you add more colors be sure to match the number of cases
	int colorNumber = rand(11);
	if (RANDOMDEBUG) Trace("waterColor_openSea random number: " + colorNumber);

	int waterColor;
	switch(colorNumber)
    {
    case 0:
        waterColor = argb(0,25,55,80);
        break;
    case 1:
        waterColor = argb(0,23,84,128);
        break;
    case 2:
        waterColor = argb(0,70,95,120);
        break;
    case 3:
        waterColor = argb(0,33,49,73);
        break;
    case 4:
        waterColor = argb(0,11,53,64);
        break;
    case 5:
        waterColor = argb(0,50,70,90);
        break;
    case 6:
        waterColor = argb(0,45,80,90);
        break;
    case 7:
        waterColor = argb(0,20,65,90);
        break;
    case 8:
        waterColor = argb(0,60,95,110);
        break;
    case 9:
        waterColor = argb(0,55,85,95);
        break;
    case 10:
        waterColor = argb(0,2,77,141);
        break;
    case 11:
        waterColor = argb(0,7,84,103);
        break;
	}

	return waterColor;
}