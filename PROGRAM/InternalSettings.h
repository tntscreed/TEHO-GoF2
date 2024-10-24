/////////////////////////
// GOF 1.2
/////////////////////////

#define USE_PARTICLES_CANNONS		2		// Sets the realism of the cannon visual effects.
											// 0: Low - Stock POTC cannon smoke
											// 1: Medium - Realistic cannon smoke
											// 2: High - Extremely Realistic cannon smoke, high-end computer recommended.
#define JRH_GUNSOUNDS				1			// BOOL - Off=0, Default=1, Jack Rackham's new cannon sounds. USE_REAL_CANNONS must be on for this to do anything.

int		MAX_WBALLAST =					25;		// INT - how far the weighting will swing in favor of current trend.. use positive integer between 0 and 50 - 0 is no swing - 50 is major swing.. this is for Windspeed
int		MAX_RBALLAST =					25;		// ^^DITTO for rain
int		MAX_FBALLAST =					25;		// ^^DITTO for fog
float	MAX_ABALLAST =					25.0;	// FLOAT - ^^DITTO for wind angle

int		MAX_WINDCHANGE =				5;		// INT - How much the wind CAN change in one hour - use positive integer between 0 and 20
int		MAX_FOGCHANGE =					5;		// INT - ^^DITTO for fog
int		MAX_RAINCHANGE =				5;		// INT - ^^DITTO for rain
int		TIMESCALAR_SEA =				5;			// INT - how many seconds of gametime one second of realtime is at sea
#define MAX_ANGLECHANGE					0.5		// FLOAT - ^^DITTO for wind angle

#define FREE_FOG						0		// BOOL - Allow fog during daylight hours 0 - false 1 - true
#define REALISTIC_WAVES					1			// BOOL - desc="Set to 0 to disable the realistic waves mod by KiwisDoFly."

