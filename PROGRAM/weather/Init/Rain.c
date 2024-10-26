int Whr_InitRain(int n)
{
    // Ensure index is within valid bounds
    if (n < 0 || n >= MAX_WEATHERS) {
        Trace("Whr_InitRain: Invalid index " + n);
        return n;  // Return early if index is invalid
    }

    // Evening3
    Weathers[n].id = "21 Rain";
    Weathers[n].Hour.Min = 21;
    Weathers[n].Hour.Max = 21;
    Weathers[n].Lighting = "evening21";
    Weathers[n].LightingLm = "storm";
    Weathers[n].InsideBack = "e";

    Weathers[n].Storm = false;
    Weathers[n].Tornado = false;
    Weathers[n].Shark = true;
    Weathers[n].Lights = 0;
    Weathers[n].Night = true;

    Weathers[n].Shadow.Density.Head = argb(255,6,6,6);
    Weathers[n].Shadow.Density.Foot = argb(255,36,36,34);

    Weathers[n].Lightning.Enable = false;
    Weathers[n].Lightning.Texture = "Weather\\lightning\\lightning.tga.tx";
    Weathers[n].Lightning.FlickerTime = 32;
    Weathers[n].Lightning.SubTexX = 1;
    Weathers[n].Lightning.SubTexY = 1;

    Weathers[n].Sky.Dir = "weather\\skies\\21\\";
    Weathers[n].Sky.Color = argb(0,255,255,255);
    Weathers[n].Sky.Rotate.Min = 0.0;
    Weathers[n].Sky.Rotate.Max = 0.0;
    Weathers[n].Sky.Size = 512.0;
    Weathers[n].Sky.Angle = 0.0;

    Weathers[n].Fog.Enable = true;
    Weathers[n].Fog.Height = 2000;
    Weathers[n].Fog.Start = 10;
    Weathers[n].Fog.Density = 0.002;
    Weathers[n].Fog.IslandDensity = 0.001;
    Weathers[n].Fog.SeaDensity = 0.0015;
    Weathers[n].Fog.Color = argb(0,52,55,52);
    Weathers[n].SpecialSeaFog.Color = argb(0,52,55,52);
    Weathers[n].Bak.Fog.Color = argb(0,52,55,52);
    Weathers[n].Bak.SpecialSeaFog.Color = argb(0,52,55,52);

    Weathers[n].Rain.NumDrops = 6000;
    Weathers[n].Rain.Color = argb(0,23,23,23);
    Weathers[n].Rain.DropLength = 12;
    Weathers[n].Rain.Height = 30.0;
    Weathers[n].Rain.Radius = 30.0;
    Weathers[n].Rain.Speed = 18;
    Weathers[n].Rain.Jitter = 0.4;
    Weathers[n].Rain.WindSpeedJitter = 0.5;
    Weathers[n].Rain.MaxBlend = 49;
    Weathers[n].Rain.TimeBlend = 2000;

    Weathers[n].Rain.DropsNearNum = 500;
    Weathers[n].Rain.DropsFarNum = 500;
    Weathers[n].Rain.DropsNearRadius = 25.0;
    Weathers[n].Rain.DropsFarRadius = 75.0;
    Weathers[n].Rain.DropsLifeTime = 0.25;
    Weathers[n].Rain.DropsSize = 0.09;
    Weathers[n].Rain.DropsTexture = "weather\\rain_drops.tga.tx";
    Weathers[n].Rain.DropsColor = argb(63, 255, 255, 255);

    Weathers[n].Rainbow.Enable = false;
    Weathers[n].Rainbow.Texture = "weather\\rainbow\\rainbow.tga.tx";

    Weathers[n].Planets.Enable = false;

    Weathers[n].Stars.Enable = true;
    Weathers[n].Stars.Texture = "weather\\astronomy\\stars.tga.tx";
    Weathers[n].Stars.Color = argb(0, 255, 255, 255);
    Weathers[n].Stars.Radius = 2000.0;
    Weathers[n].Stars.Size = 15.0;
    Weathers[n].Stars.HeightFade = 200.0;
    Weathers[n].Stars.SunFade = 1.0;
    Weathers[n].Stars.VisualMagnitude = 8.0;

    Weathers[n].Sun.Color = argb(0,30,30,30);
    Weathers[n].Sun.Ambient = argb(0,45,45,40);
    //Weathers[n].Sun.AzimuthAngle = Degree2Radian(37.0);
    Weathers[n].Sun.AzimuthAngle = Degree2Radian(337.0);
    Weathers[n].Sun.HeightAngle = -1.00;
    Weathers[n].Sun.Glow.Enable = false;
    Weathers[n].Sun.Glow.Dist = 3500.0;
    Weathers[n].Sun.Glow.Size = 1250.0;
    Weathers[n].Sun.Glow.RotateSpeed = 1.0;
    Weathers[n].Sun.Glow.Texture = "weather\\sun\\glow\\sunglow.tga.tx";
    Weathers[n].Sun.Glow.DecayTime = 8.0;
    Weathers[n].Sun.Glow.TechniqueNoZ = "sunglow_noz";
    Weathers[n].Sun.Glow.TechniqueZ = "sunglow_z";
    Weathers[n].Sun.Glow.Color = argb(0,255,255,255);
    Weathers[n].Sun.Overflow.Enable = false;
    Weathers[n].Sun.Overflow.Texture = "Weather\\lightning\\flash.tga.tx";
    Weathers[n].Sun.Overflow.Color = argb(0, 100, 100, 100);
    Weathers[n].Sun.Overflow.Size = 5500.0;
    Weathers[n].Sun.Overflow.Technique = "sunoverflow";
    Weathers[n].Sun.Overflow.Start = 0.7;
    Weathers[n].Sun.Flare.Enable = false;
    Weathers[n].Sun.Flare.Texture = "weather\\sun\\flare\\allflares.tga.tx";
    Weathers[n].Sun.Flare.Dist = 3500.0;
    Weathers[n].Sun.Flare.TexSizeX = 2;
    Weathers[n].Sun.Flare.TexSizeY = 2;
    Weathers[n].Sun.Flare.Technique = "sunflare";
    Weathers[n].Sun.Flare.Scale = 2.0;
    Weathers[n].Sun.Flares.f1 = "1.0,200.0,0,0x0F0F0F";
    Weathers[n].Sun.Flares.f2 = "0.9,20.0,1,0x0F0F0F";
    Weathers[n].Sun.Flares.f3 = "0.8,30.0,2,0x0F0F0F";
    Weathers[n].Sun.Flares.f4 = "0.6,150.0,0,0x0F0F0F";
    Weathers[n].Sun.Flares.f5 = "0.5,50.0,0,0x0F0F0F";
    Weathers[n].Sun.Flares.f6 = "0.4,100.0,1,0x0F0F0F";
    Weathers[n].Sun.Flares.f7 = "0.3,200.0,0,0x0F0F0F";
    Weathers[n].Sun.Flares.f8 = "0.2,200.0,0,0x0F0F0F";

    Weathers[n].Sea.GF2MX.Sky.Color = argb(0,160,210,255);
    Weathers[n].Sea.GF2MX.Water.Color = argb(0,0,5,10);
    Weathers[n].Sea.GF2MX.Bump.Tile = 0.05;
    Weathers[n].Sea.GF2MX.Bump.AnimSpeed = 7.0;
    Weathers[n].Sea.GF2MX.Bump.Dir = "weather\\sea\\bump_g2mx\\";
    Weathers[n].Sea.Transparency = 0.9;
    Weathers[n].Sea.FrenelCoefficient = 0.5;
    Weathers[n].Sea.WaterReflection = 0.7;
    Weathers[n].Sea.WaterAttenuation = 0.9;
    Weathers[n].Sea.Sky.Color = argb(0,255,255,255);
    Weathers[n].Sea.Water.Color = argb(0,20,28,28);
    Weathers[n].Sea.Pena.Color = argb(0,175,175,155);
    Weathers[n].Sea.Bump.Dir = "resource\\textures\\weather\\sea\\bump_g3\\";
    Weathers[n].Sea.Bump.Tile = 0.04;
    Weathers[n].Sea.Bump.Ang = 0.0;
    Weathers[n].Sea.Bump.Speed = 0.01;
    Weathers[n].Sea.Bump.AnimSpeed = 16.0;
    Weathers[n].Sea.Bump.Scale = 2.0;
    Weathers[n].Sea.SunRoad.Start = 0.99;
    Weathers[n].Sea.SunRoad.Color1 = argb(0,55,55,100);
    Weathers[n].Sea.SunRoad.Color2 = argb(0,255,255,255);
    Weathers[n].Sea.SunRoad.Power = 0.2;
    Weathers[n].Sea.Harmonics.h1 = "0.0,2.0,3.0,0.0,10.00";
    Weathers[n].Sea.Harmonics.h2 = "1.57,4.0,1.5,50.0,10.00";
    Weathers[n].Sea.Harmonics.h3 = "0.47,7.0,2.5,200.0,10.00";
    Weathers[n].Sea.Harmonics.h4 = "1.47,9.0,2.5,200.0,10.00";
    Weathers[n].Sea.Harmonics.h5 = "0.27,7.0,1.0,10.0,10.00";
    Weathers[n].Sea.Harmonics.h6 = "2.27,8.0,2.0,200.0,2.00";
    Weathers[n].Sea.Harmonics.h7 = "2.27,8.0,2.0,200.0,1.00";
    Weathers[n].Sea.Harmonics.h8 = "0.07,8.0,2.0,200.0,1.00";

    Weathers[n].Wind.Angle = 2.0;
    Weathers[n].Wind.Speed.Min = 5.0;
    Weathers[n].Wind.Speed.Max = 14.0;

    n++;

    return n;
}