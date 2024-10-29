void InitShips()
{
  ref refShip;

	for (int idx=0;idx<SHIP_TYPES_QUANTITY_WITH_FORT;idx++)
	{
		makeref(refShip,ShipsTypes[idx]);

		refship.index = idx;

		refship.InertiaAccelerationX = 0.2;		refship.InertiaBrakingX = 0.7;
		refship.InertiaAccelerationY = 0.4;		refship.InertiaBrakingY = 0.4;
		refship.InertiaAccelerationZ = 1.0;		refship.InertiaBrakingZ = 1.0;

		refship.Rocking.y 	= 0.5;
		refship.Rocking.az 	= 0.05;

		refship.NetGeraldSails = "";
		refship.Soundtype = "";

		refship.WaterLine 			= 0.0;
		refship.SpeedDependWeight 	= 0.0;
		refship.SubSeaDependWeight 	= 0.0;
		refship.TurnDependWeight 	= 0.0;
		refship.TurnDependSpeed 	= 0.0;

		refShip.Height.Bombs.Y		= 3.0;		refShip.Height.Bombs.DY		= 1.0;
		refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
		refShip.Height.Knippels.Y	= 25.0;		refShip.Height.Knippels.DY	= 15.0;
		refShip.Height.Balls.Y		= 3.0;		refShip.Height.Balls.DY		= 1.0;

        refship.WindAgainstSpeed   	= 1.0;//boal
		refship.CabinType          	= "Cabin_Small"; // потом припишем слово My_ и будет каютой для ГГ
        refShip.AbordageLocation	= "BOARDING_SMALL_DECK";
        refship.DeckType          	= "Low";
        
		refShip.MaxCaliber			= 6;
		refShip.Cannon				= CANNON_TYPE_CANNON_LBS6;
		refShip.CannonsQuantity		= 0;
		refShip.CannonsQuantityMin	= 0;

		aref cannonl, cannonr, cannonb, cannonf;

		refship.CanEncounter 	= true;
		refship.Type.Merchant 	= true;
		refship.Type.War 		= true;
		refship.Track.Enable 	= false;
		refShip.FireHeight 		= 3.0;

		refShip.Massa = 1500000.0;
		refShip.Volume = 900.0;
		refShip.lowpolycrew = 5;

		refShip.rcannon = 0;
		refShip.lcannon = 0;
		refShip.fcannon = 0;
		refShip.bcannon = 0;
		
		ShipsTypes[idx].Cannons.Borts.cannonl = "";
		ShipsTypes[idx].Cannons.Borts.cannonr = "";
		ShipsTypes[idx].Cannons.Borts.cannonf = "";
		ShipsTypes[idx].Cannons.Borts.cannonb = "";

		makearef(cannonl,ShipsTypes[idx].Cannons.Borts.cannonl);
		makearef(cannonr,ShipsTypes[idx].Cannons.Borts.cannonr);
		makearef(cannonf,ShipsTypes[idx].Cannons.Borts.cannonf);
		makearef(cannonb,ShipsTypes[idx].Cannons.Borts.cannonb);

		cannonf.FireZone	= Degree2Radian(30.0);
		cannonf.FireDir		= Degree2Radian(0.0);
		cannonf.FireAngMin	= -0.35;
		cannonf.FireAngMax	= 0.60;

		cannonr.FireZone	= Degree2Radian(80.0);
		cannonr.FireDir		= Degree2Radian(90.0);
		cannonr.FireAngMin	= -0.35;
		cannonr.FireAngMax	= 0.60;

		cannonb.FireZone	= Degree2Radian(30.0);
		cannonb.FireDir		= Degree2Radian(180.0);
		cannonb.FireAngMin	= -0.35;
		cannonb.FireAngMax	= 0.60;

		cannonl.FireZone	= Degree2Radian(80.0);
		cannonl.FireDir		= Degree2Radian(270.0);
		cannonl.FireAngMin	= -0.35;
		cannonl.FireAngMax	= 0.60;
	}
	
	///////////////////////////////////////////////////////////////////////////
	//// Лодка
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BOAT]);
	refShip.Name									= "Boat";
	refship.Soundtype								= "lugger";
	refShip.Class									= 6;
	refShip.Cannon									= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber								= 12;
	refShip.Weight									= Tonnes2CWT(10);
	refShip.Capacity								= 50;
	refShip.CannonsQuantity							= 0;
	refShip.CannonsQuantityMin						= 0;
	refShip.rcannon 								= 0;
	refShip.lcannon 								= 0;
	refShip.fcannon 								= 0;
	refShip.bcannon 								= 0;
	refShip.MaxCrew									= 10; 
	refShip.OptCrew									= 5; 
	refShip.MinCrew									= 1;
	refShip.SpeedRate								= 4;
	refShip.TurnRate								= 40;
	refShip.Price									= 100;
	refShip.HP										= 100;
	refShip.SP										= 100;
	refship.CanEncounter							= false;
	refship.Type.Merchant							= false;
	refship.Type.War								= false;
	refShip.lowpolycrew 							= 0;
	refship.WaterLine								= -0.3;

	refShip.Massa 									= 10000.0;
	refShip.Volume 									= 100.0;
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 0.4;	refship.InertiaBrakingY		= 0.2;
	refship.InertiaAccelerationZ	= 0.15;	refship.InertiaBrakingZ		= 0.05;
	
	//////////////////////////////////////////////////////////////////////////
	//// ОРДИНАРНЫЕ КОРАБЛИ
	//////////////////////////////////////////////////////////////////////////		
	///////////////////////////////////////////////////////////////////////////
	//// Баркас
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_TARTANE]);
	refShip.Name									= "Tartane";
	refship.Soundtype								= "lugger";
	refShip.Class									= 6;
	refShip.Cannon									= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber								= 3;
	refShip.Weight									= Tonnes2CWT(10);
	refShip.Capacity								= 80;
	refShip.CannonsQuantity							= 0;
	refShip.CannonsQuantityMin						= 0;
	refShip.rcannon 								= 0;
	refShip.lcannon 								= 0;
	refShip.fcannon 								= 0;
	refShip.bcannon 								= 0;
	refShip.MaxCrew									= 15;
	refShip.OptCrew									= 12;
	refShip.MinCrew									= 1;	
	refShip.SpeedRate								= 7.0;
	refShip.TurnRate								= 75;
	refShip.Price									= 2100;
	refShip.HP										= 150;
	refShip.SP										= 100;
	refship.CanEncounter							= false;
	refship.Type.Merchant							= false;
	refship.Type.War								= false;
	refShip.lowpolycrew 							= 3;

	refShip.Massa 									= 10000.0;
	refShip.Volume 									= 20.0;
	refship.WindAgainstSpeed   						= 1.0;
		
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 0.4;	refShip.Height.Bombs.DY		= 0.2;
	refShip.Height.Grapes.Y				= 1.3;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 6.5;	refShip.Height.Knippels.DY	= 5.8;
	refShip.Height.Balls.Y				= 0.4;	refShip.Height.Balls.DY		= 0.2;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Тартана
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WAR_TARTANE]);
	refShip.Name								= "WarTartane";
	refship.Soundtype							= "lugger";
	refShip.Class								= 6;
	refShip.Cannon								= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber							= 3;
	refShip.Weight								= Tonnes2CWT(30);
	refShip.Capacity							= 210;
	refShip.CannonsQuantity						= 6; // 0,0,3,3
	refShip.CannonsQuantityMin					= 6;
	refShip.rcannon 							= 3; 
	refShip.lcannon 							= 3; 
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew								= 25;
	refShip.OptCrew								= 20;
	refShip.MinCrew								= 3;
	refShip.SpeedRate							= 12.0;
	refShip.TurnRate							= 70;
	refShip.Price								= 4800;
	refShip.HP									= 400;
	refShip.SP									= 100;
	refship.CanEncounter						= true;
	refship.Type.Merchant						= true;
	refship.Type.War							= true;
	refShip.lowpolycrew							= 3;
	
	refShip.Massa 								= 50000.0;
	refShip.Volume 								= 100.0;

	refship.WaterLine							= 0.1;
	refship.SpeedDependWeight					= 0.2;
	refship.SubSeaDependWeight					= 0.4;
	refship.TurnDependWeight					= 0.2;
    refship.WindAgainstSpeed   					= 1.25;
    
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 1.8;	refShip.Height.Grapes.DY	= 0.9;
	refShip.Height.Knippels.Y			= 6.7;	refShip.Height.Knippels.DY	= 6.7;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Барк
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BARQUE]);
	refShip.Name            			= "Barque";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 6;
	refShip.Weight						= Tonnes2CWT(350);
	refShip.Capacity       				= 1500;
	refShip.CannonsQuantity				= 14; // 0,2,6,6    0,2,5,5
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2; 
	refShip.MaxCrew         			= 62;
	refShip.OptCrew         			= 50;
	refShip.MinCrew         			= 26;
	refShip.SpeedRate					= 9.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 23300;
	refShip.HP              			= 1500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 10;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.00;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.7;
	
	refShip.Height.Bombs.Y				= 3.3;	refShip.Height.Bombs.DY		= 1.6;
	refShip.Height.Grapes.Y				= 4.9;	refShip.Height.Grapes.DY	= 2.4;
	refShip.Height.Knippels.Y			= 15.8;	refShip.Height.Knippels.DY	= 12.4;
	refShip.Height.Balls.Y				= 3.3;	refShip.Height.Balls.DY		= 1.6;	
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 7.5;
	refship.Track1.Width	= "6.0, 7.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 5.0;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Торговая шхуна
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SCHOONER]);
	refShip.Name            			= "Schooner";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight						= Tonnes2CWT(250);
	refShip.Capacity        			= 1700;	

	refShip.CannonsQuantity				= 12; //	нуна буит 5/5/0/2
	refShip.CannonsQuantityMin			= 10;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2;

	refShip.MaxCrew         			= 75;
	refShip.OptCrew         			= 60;
	refShip.MinCrew         			= 32;	
	refShip.SpeedRate					= 12.5;	
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 24300;	
	refShip.HP              			= 1250;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 12;
	
	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.03;

	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.10;

	refship.CabinType          			= "Cabin_Medium";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.7;		refShip.Height.Bombs.DY		= 0.8;
	refShip.Height.Grapes.Y				= 2.9;		refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y			= 13.9;		refShip.Height.Knippels.DY	= 13.7;
	refShip.Height.Balls.Y				= 1.7;		refShip.Height.Balls.DY		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";

	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Баркентина
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BARKENTINE]);
	refShip.Name            			= "Barkentine";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight						= Tonnes2CWT(300);
	refShip.Capacity       				= 2000;
	refShip.CannonsQuantity				= 14; // 2,2,5,5     2,2,4,4
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 106;
	refShip.OptCrew         			= 85;
	refShip.MinCrew         			= 30;	
	refShip.SpeedRate       			= 11.0;
	refShip.TurnRate        			= 40.0;	
	refShip.Price           			= 31300;	
	refShip.HP              			= 2000;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 12;
	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	refship.WaterLine					= 1.15;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	
	refship.WindAgainstSpeed   			= 1.25;
	
	refship.CabinType          			= "Cabin_Medium";
		
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 3.5;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 4.8;		refShip.Height.Grapes.DY	= 2.4;
	refShip.Height.Knippels.Y			= 16.7;		refShip.Height.Knippels.DY	= 12.8;
	refShip.Height.Balls.Y				= 3.5;		refShip.Height.Balls.DY		= 1.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Шнява
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SHNYAVA]);
	refShip.Name            			= "Shnyava";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;
	refShip.Weight						= Tonnes2CWT(350);
	refShip.Capacity       				= 2250;
	refShip.CannonsQuantity				= 16;	// 2,0,7,7	2,0,6,6
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 0;
	refShip.MaxCrew         			= 150;
	refShip.OptCrew         			= 120;
	refShip.MinCrew         			= 28;	
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 35200;
	refShip.HP              			= 2200;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 1.15;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.10;
	refship.CabinType          			= "Cabin_Medium"; 
		
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 3.5;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 4.8;		refShip.Height.Grapes.DY	= 2.4;
	refShip.Height.Knippels.Y			= 16.7;		refShip.Height.Knippels.DY	= 12.8;
	refShip.Height.Balls.Y				= 3.5;		refShip.Height.Balls.DY		= 1.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Флейт  
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLEUT]);
	refShip.Name            			= "Fleut";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;	
	refShip.Weight						= Tonnes2CWT(450);	
	refShip.Capacity        			= 3000;	
	refShip.CannonsQuantity				= 16; // 2,2,6,6     2,2,5,5
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 175;
	refShip.OptCrew         			= 140;
	refShip.MinCrew         			= 40;	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 46800;
	refShip.HP              			= 3000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 1.2;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.65;
	
	refship.CabinType          			= "Cabin_Medium"; 
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 3.4;		refShip.Height.Bombs.DY		= 1.7;
	refShip.Height.Grapes.Y				= 5.0;		refShip.Height.Grapes.DY	= 2.5;
	refShip.Height.Knippels.Y			= 17.8;		refShip.Height.Knippels.DY	= 13.3;
	refShip.Height.Balls.Y				= 3.4;		refShip.Height.Balls.DY		= 1.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
		
	///////////////////////////////////////////////////////////////////////////
	//// Каравелла
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CARAVEL]);
	refShip.Name            			= "Caravel";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;
	refShip.Weight						= Tonnes2CWT(850);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity				= 20; // 2,2,8,8    2,2,7,7
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 225;
	refShip.OptCrew         			= 180;
	refShip.MinCrew         			= 48;	
	refShip.SpeedRate					= 11.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 53200;	
	refShip.HP              			= 3200;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	refship.CabinType          			= "Cabin_Medium"; 
	refship.DeckType           			= "Medium";
	
	refship.WaterLine					= 1.0;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.25;
	
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 2.7;	refShip.Height.Bombs.DY		= 1.3;
	refShip.Height.Grapes.Y				= 4.3;	refShip.Height.Grapes.DY	= 2.1;
	refShip.Height.Knippels.Y			= 13.0;	refShip.Height.Knippels.DY	= 11.7;
	refShip.Height.Balls.Y				= 2.7;	refShip.Height.Balls.DY		= 1.3;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 10;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Пинас
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACE]);
	refShip.Name            			= "Pinnace";
	refship.Soundtype					= "frigate";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 18;	
	refShip.Weight						= Tonnes2CWT(800);	
	refShip.Capacity        			= 4500;	
	refShip.CannonsQuantity				= 18; // 2,4,6,6	2,4,5,5
	refShip.CannonsQuantityMin			= 16;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew						= 200;
	refShip.OptCrew         			= 160;
	refShip.MinCrew         			= 42;	
	refShip.SpeedRate					= 14.0;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 68000;
	refShip.HP              			= 4200;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	
	refShip.lowpolycrew 				= 20;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;

	refship.WaterLine					= 0.4;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 1.3;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   			= 0.65;
    refship.CabinType          			= "Cabin_Medium2";
    refship.DeckType           			= "Medium";
	
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.5;		refShip.Height.Grapes.DY	= 2.7;
	refShip.Height.Knippels.Y			= 24.1;		refShip.Height.Knippels.DY	= 20.7;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.7, 7.9";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "10.0, 12.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Каракка
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CARACCA]);
	refShip.Name            			= "Caracca";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 18;	
	refShip.Weight						= Tonnes2CWT(750);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 20; // 2,2,8,8	2,2,7,7
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 250;
	refShip.OptCrew         			= 200;
	refShip.MinCrew         			= 52;	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 60900;
	refShip.HP              			= 3700;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.6;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.95;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.75;
	
	refship.CabinType          			= "Cabin_Medium2"; // boal 28.03.05
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 18.7;		refShip.Height.Knippels.DY	= 12.7;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Навио
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_NAVIO]);
	refShip.Name            			= "Navio";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 20;
	refShip.Weight						= Tonnes2CWT(1100);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity				= 36; // 2,4,14,14	2,4,13,13	2,4,12,12
	refShip.CannonsQuantityMin			= 32;
	refShip.rcannon 					= 15;
	refShip.lcannon 					= 15;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 350;
	refShip.OptCrew         			= 280;
	refShip.MinCrew         			= 62;	
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 77400;
	refShip.HP              			= 4800;
	refShip.SP              			= 100;
	refship.Type.Merchant				= true;
	refship.Type.War					= false;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= -0.2;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Ост-Индец
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_EASTINDIAMAN]);
	refShip.Name            			= "EastIndiaMan";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(1000);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity				= 36;	// 0,6,15,15	0,6,14,14	0,6,13,13
	refShip.CannonsQuantityMin			= 32;
	refShip.rcannon 					= 15;
	refShip.lcannon 					= 15;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 6;	
	refShip.MaxCrew         			= 425;
	refShip.OptCrew         			= 340;
	refShip.MinCrew         			= 76;	
	refShip.SpeedRate					= 13.5;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 88000;
	refShip.HP              			= 5200;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= false;	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= -0.5;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.55;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Курьерский люггер
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CAREERLUGGER]);
	refShip.Name            			= "LuggerQuest";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(120);	
	refShip.Capacity        			= 550;
	refShip.CannonsQuantity				= 10; // 0,2,4,4	0,2,3,3
	refShip.CannonsQuantityMin			= 8;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 37;
	refShip.OptCrew         			= 30;
	refShip.MinCrew         			= 8;	
	refShip.SpeedRate       			= 16.0;
	refShip.TurnRate        			= 65.0;
	refShip.Price           			= 10100;
	refShip.HP              			= 750;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;

	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.60;
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y				= 1.65;	refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 2.64;	refShip.Height.Grapes.DY	= 0.5;
	refShip.Height.Knippels.Y			= 14.64; refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 1.65;	refShip.Height.Balls.DY		= 1.35;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Люггер
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LUGGER]);
	refShip.Name            			= "Lugger";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 6;
	refShip.Weight						= Tonnes2CWT(150);
	refShip.Capacity        			= 670;
	refShip.CannonsQuantity				= 12;	//2,2,4,4	2,2,3,3
	refShip.CannonsQuantityMin			= 10;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;		
	refShip.MaxCrew         			= 50;
	refShip.OptCrew         			= 40;
	refShip.MinCrew         			= 8;	
	refShip.SpeedRate       			= 15.0;
	refShip.TurnRate        			= 60.0;
	refShip.Price           			= 10600;
	refShip.HP              			= 600;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;

	refship.WaterLine					= 0.2;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 1.50;
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y				= 2.1;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.1;	refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 10.5;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 2.1;	refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// Шлюп
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SLOOP]);
	refShip.Name            			= "Sloop";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(170);
	refShip.Capacity        			= 900;	
	refShip.CannonsQuantity				= 14; // 2,2,5,5	2,2,4,4
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 62;
	refShip.OptCrew         			= 50;
	refShip.MinCrew         			= 10;	
	refShip.SpeedRate					= 14.0;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 14500;
	refShip.HP              			= 900;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 8;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	
	refship.WindAgainstSpeed   			= 1.30;

	refShip.Height.Bombs.Y				= 1.6;	refShip.Height.Bombs.DY		= 1.25;
	refShip.Height.Grapes.Y				= 2.75;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 13.2;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 1.6;	refShip.Height.Balls.DY		= 1.25;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// Бригантина 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGANTINE]);
	refShip.Name            			= "Brigantine";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;	
	refShip.Weight						= Tonnes2CWT(320);	
	refShip.Capacity        			= 1800;
	refShip.CannonsQuantity				= 16; // 2,0,7,7	2,0,6,6
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 0;		
	refShip.MaxCrew         			= 175;
	refShip.OptCrew         			= 140;
	refShip.MinCrew         			= 16;	
	refShip.SpeedRate       			= 14.0;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 33900;
	refShip.HP              			= 2800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.40;
	
	refship.CabinType          			= "Cabin_Medium"; 

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y			= 13.2;		refShip.Height.Knippels.DY	= 11.6;
	refShip.Height.Balls.Y				= 2.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false
	refship.nation.spain	= true;;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;
    	
	///////////////////////////////////////////////////////////////////////////
	//// Бриг
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIG]);
	refShip.Name            			= "Brig";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;
	refShip.Weight						= Tonnes2CWT(300);
	refShip.Capacity        			= 1350;
	refShip.CannonsQuantity				= 16; // 2,2,6,6	2,2,5,5
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 150;
	refShip.OptCrew         			= 120;
	refShip.MinCrew         			= 20;
	
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 27700;
	refShip.HP              			= 2500;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.55;
	refship.CabinType          			= "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 3.3;		refShip.Height.Grapes.DY	= 1.6;
	refShip.Height.Knippels.Y			= 14.9;		refShip.Height.Knippels.DY	= 14.0;
	refShip.Height.Balls.Y				= 2.0;		refShip.Height.Balls.DY		= 2.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Военная шхуна
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SCHOONER_W]);
	refShip.Name            			= "Schooner_W";
	refship.Soundtype					= "lugger";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 18;	
	
	refShip.Weight						= Tonnes2CWT(220);
	refShip.Capacity        			= 1350;
	refShip.CannonsQuantity				= 18; // 2,2,7,7	2,2,6,6
	refShip.CannonsQuantityMin			= 16;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 122;
	refShip.OptCrew         			= 98;
	refShip.MinCrew         			= 18;
	refShip.SpeedRate					= 13.5;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 22300;
	refShip.HP              			= 1450;
	refShip.SP              			= 100;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.03;

	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.15;
	
	refship.CabinType          			= "Cabin_Medium";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.7;		refShip.Height.Bombs.DY		= 0.8;
	refShip.Height.Grapes.Y				= 2.9;		refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y			= 13.9;		refShip.Height.Knippels.DY	= 13.7;
	refShip.Height.Balls.Y				= 1.7;		refShip.Height.Balls.DY		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// Галеон 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON_L]);
	refShip.Name            			= "Galeon_l";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;
	refShip.Weight						= Tonnes2CWT(720);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity				= 20; // 2,2,9,9	2,2,8,8
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;	
	refShip.MaxCrew         			= 250;
	refShip.OptCrew         			= 200;
	refShip.MinCrew         			= 36;	
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 52500;
	refShip.HP              			= 4000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 16;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.85;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.95;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.60;
	
	refship.CabinType          			= "Cabin_Medium2"; 
	refship.DeckType           			= "Medium";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 4.3;		refShip.Height.Bombs.DY		= 2.1;
	refShip.Height.Grapes.Y				= 5.6;		refShip.Height.Grapes.DY	= 2.8;
	refShip.Height.Knippels.Y			= 18.7;		refShip.Height.Knippels.DY	= 12.7;
	refShip.Height.Balls.Y				= 4.3;		refShip.Height.Balls.DY		= 2.1;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
		
	///////////////////////////////////////////////////////////////////////////
	//// Корвет
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE]);
	refShip.Name            			= "Corvette";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;
	refShip.Weight						= Tonnes2CWT(600);
	refShip.Capacity        			= 2700;
	refShip.CannonsQuantity				= 20; // 2,2,8,8	2,2,7,7
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 225;
	refShip.OptCrew						= 180;
	refShip.MinCrew         			= 28;
	
	refShip.SpeedRate					= 14.5;
	refShip.TurnRate        			= 40.0;
	refShip.Price           			= 45500;
	refShip.HP              			= 3250;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.614;	refShip.Height.Bombs.DY		= 1.346;
	refShip.Height.Grapes.Y				= 4.694;	refShip.Height.Grapes.DY	= 0.666;
	refShip.Height.Knippels.Y			= 15.333;	refShip.Height.Knippels.DY	= 13.425;
	refShip.Height.Balls.Y				= 2.614;	refShip.Height.Balls.DY		= 1.346;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;

	//////////////////////////////////////////////////////////////////////////
	//// Шебека
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XebekVML]);
	refShip.Name						= "XebekVML";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber  				= 20;
	refShip.Weight						= Tonnes2CWT(500);
	refShip.Capacity   					= 2500;
	refShip.CannonsQuantity				= 22; // 4,2,6,6	4,2,5,5	4,2,4,4
	refShip.CannonsQuantityMin			= 20;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 181;
	refShip.OptCrew        				= 145;
	refShip.MinCrew        				= 22;
	
	refShip.SpeedRate      				= 15.5;
	refShip.TurnRate       				= 60.0;
	refShip.Price          				= 42000;
	refShip.HP             				= 3000;
	refShip.SP             				= 100;

	refship.CabinType          			= "Cabin_Medium2";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.55;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.10;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;
	
	///////////////////////////////////////////////////////////////////////////
	//// Полакр
	///////////////////////////////////////////////////////////////////////////	
	makeref(refShip,ShipsTypes[SHIP_POLACRE]);
	refShip.Name						= "Polacre";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber  				= 20;
	refShip.Weight						= Tonnes2CWT(550);
	refShip.Capacity   					= 2750;
	refShip.CannonsQuantity				= 22; // 2,2,9,9    2,2,8,8	2,2,7,7 
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 9;
	refShip.lcannon 					= 9;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 206;
	refShip.OptCrew        				= 165;
	refShip.MinCrew        				= 24;
	
	refShip.SpeedRate      				= 14.0;
	refShip.TurnRate       				= 50.0;
	refShip.Price          				= 45900;
	refShip.HP             				= 3250;
	refShip.SP             				= 100;

	refship.CabinType          			= "Cabin_Medium2";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.35;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;
		
		
	///////////////////////////////////////////////////////////////////////////
	//// Тяжелый Галеон
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON_H]);
	refShip.Name            			= "Galeon_h";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1050);
	refShip.Capacity        			= 5100;
	
	refShip.CannonsQuantity				= 54;	// 4,6,22,22	4,6,21,21	4,6,20,20	4,6,19,19    4,6,18,18
	refShip.CannonsQuantityMin			= 48;
	refShip.rcannon 					= 22;
	refShip.lcannon 					= 22;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 6;	
	
	refShip.MaxCrew         			= 525;
	refShip.OptCrew         			= 420;
	refShip.MinCrew         			= 60;	
	refShip.SpeedRate					= 11.5;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 80900;
	refShip.HP              			= 5000;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 0.45;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.Height.Bombs.Y				= 3.0;		refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.4;		refShip.Height.Grapes.DY	= 2.2;
	refShip.Height.Knippels.Y			= 21.4;		refShip.Height.Knippels.DY	= 19.8;
	refShip.Height.Balls.Y				= 3.0;		refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// Фрегат 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE]);
	refShip.Name            			= "Frigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(950);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 46;
	refShip.CannonsQuantityMin			= 40;
	refShip.rcannon 					= 20;
	refShip.lcannon 					= 20;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 400;
	refShip.OptCrew         			= 320;
	refShip.MinCrew         			= 52;	
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 66900;	
	refShip.HP              			= 4600;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.50;
	
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.7;	refShip.Height.Bombs.DY		= 1.8;
	refShip.Height.Grapes.Y				= 5.2;	refShip.Height.Grapes.DY	= 2.6;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 19.7;
	refShip.Height.Balls.Y				= 3.7;	refShip.Height.Balls.DY		= 1.8;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Тяжелый фрегат
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_H]);
	refShip.Name            			= "Frigate_h";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1200);
	refShip.Capacity        			= 4250;
	refShip.CannonsQuantity				= 50;	// 4,6,20,20	4,6,19,19	4,6,18,18
	refShip.CannonsQuantityMin			= 46;
	refShip.rcannon 					= 20;
	refShip.lcannon 					= 20;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 6;	
	refShip.MaxCrew         			= 437;
	refShip.OptCrew         			= 350;
	refShip.MinCrew         			= 56;
	
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 73700;
	refShip.HP              			= 5400;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 2.7;		refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 5.325;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;		refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 2.7;		refShip.Height.Balls.DY		= 1.35;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Военный корабль
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINESHIP]);
	refShip.Name            			= "Lineship";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;   // на деле это воен кор
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(2000);
	refShip.Capacity        			= 5700;
	refShip.CannonsQuantity				= 56;	// 2,4,25,25	2,4,24,24	2,4,23,23	2,4,22,22
	refShip.CannonsQuantityMin			= 48;
	refShip.rcannon 					= 25;
	refShip.lcannon 					= 25;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 750;
	refShip.OptCrew         			= 600;
	refShip.MinCrew         			= 80;	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 93800;
	refShip.HP              			= 7000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
		
	refship.WaterLine					= 1.6;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.15;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            = 0.40;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 6.7;		refShip.Height.Bombs.DY		= 3.3;
	refShip.Height.Grapes.Y				= 8.3;		refShip.Height.Grapes.DY	= 4.1;
	refShip.Height.Knippels.Y			= 32.1;		refShip.Height.Knippels.DY	= 25.8;
	refShip.Height.Balls.Y				= 6.7;		refShip.Height.Balls.DY		= 3.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;

	///////////////////////////////////////////////////////////////////////////
	//// Французский линейный корабль
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LSHIP_FRA]);
	refShip.Name            			= "Warship";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(2500);
	refShip.Capacity        			= 6850;
	refShip.CannonsQuantity				= 66;	
	refShip.CannonsQuantityMin			= 58;
	refShip.rcannon 					= 30;
	refShip.lcannon 					= 30;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew         			= 812;
	refShip.OptCrew         			= 650;
	refShip.MinCrew         			= 94;	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 28.0;
	refShip.Price           			= 110900;
	refShip.HP              			= 9000;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.35;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 7.2;		refShip.Height.Bombs.DY		= 3.6;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 28.3;		refShip.Height.Knippels.DY	= 22.0;
	refShip.Height.Balls.Y				= 7.2;		refShip.Height.Balls.DY		= 3.6;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";
	
	refship.nation.england	= false;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Голландский линейный корабль 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LSHIP_HOL]);
	refShip.Name            			= "Battleship";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(3200);
	refShip.Capacity        			= 7400;
	refShip.CannonsQuantity				= 80;	// 2,6,35,35      2,6,34,34     2,6,33,33     2,6,32,32     2,6,31,31      2,6,30,30
	refShip.CannonsQuantityMin			= 72;
	refShip.rcannon 					= 36;
	refShip.lcannon 					= 36;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 6;		
	refShip.MaxCrew         			= 875;
	refShip.OptCrew         			= 700;
	refShip.MinCrew         			= 120;
	
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 27.0;
	refShip.Price           			= 122000;
	refShip.HP              			= 9500;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	
	refShip.lowpolycrew 				= 24;
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
		
	refship.WaterLine					= -0.2;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.75;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.30;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 6.8;		refShip.Height.Bombs.DY		= 3.4;
	refShip.Height.Grapes.Y				= 8.2;		refShip.Height.Grapes.DY	= 4.1;
	refShip.Height.Knippels.Y			= 33.6;		refShip.Height.Knippels.DY	= 24.8;
	refShip.Height.Balls.Y				= 6.8;		refShip.Height.Balls.DY		= 3.4;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_b1				= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.7;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Испанский линейный корабль
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LSHIP_SPA]);
	refShip.Name            			= "Manowar";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(3700);
	refShip.Capacity        			= 8600;
	refShip.CannonsQuantity				= 102; // 4,4,40,40   4,4,39,39    4,4,38,38     4,4,37,37    4,4,36,36     4,4,35,35
	refShip.CannonsQuantityMin			= 92;
	refShip.rcannon 					= 45;
	refShip.lcannon 					= 45;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 8;		
	refShip.MaxCrew         			= 937;
	refShip.OptCrew         			= 750;
	refShip.MinCrew         			= 140;
	
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 26.0;
	refShip.Price           			= 139600;
	refShip.HP              			= 10000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 28;

	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02	;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.25;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.3;
	refShip.Height.Grapes.Y				= 12.5;		refShip.Height.Grapes.DY	= 6.2;
	refShip.Height.Knippels.Y			= 36.8;		refShip.Height.Knippels.DY	= 29.6;
	refShip.Height.Balls.Y				= 8.6;		refShip.Height.Balls.DY		= 4.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false;
	refship.nation.spain	= true;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// Английский линейный корабль
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LSHIP_ENG]);
	refShip.Name            			= "Manowar_e";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(4200);
	refShip.Capacity        			= 9200;
	refShip.CannonsQuantity				= 112;
	refShip.CannonsQuantityMin			= 102;
	refShip.rcannon 					= 50; // 6,8,40,40	6,8,39,39	6,8,38,38	6,8,37,37	6,8,36,36	6,8,35,35
	refShip.lcannon 					= 50;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 8;		
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 800;
	refShip.MinCrew         			= 160;	
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 151100;
	refShip.HP              			= 10800;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refShip.lowpolycrew 				= 28;

	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02	;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.25;
	refship.CabinType          			= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.Height.Bombs.Y				= 8.6;		refShip.Height.Bombs.DY		= 4.3;
	refShip.Height.Grapes.Y				= 12.5;		refShip.Height.Grapes.DY	= 6.2;
	refShip.Height.Knippels.Y			= 36.8;		refShip.Height.Knippels.DY	= 29.6;
	refShip.Height.Balls.Y				= 8.6;		refShip.Height.Balls.DY		= 4.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= false;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= false;
	
	//////////////////////////////////////////////////////////////////////////
	//// КВЕСТОВЫЕ КОРАБЛИ
	//////////////////////////////////////////////////////////////////////////	
	//////////////////////////////////////////////////////////////////////////
	//// Легкая шебека "Мэйфэнг" -квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MAYFANG]);
	refShip.Name					= "Mayfang";
	refship.Soundtype				= "lugger";
	refShip.Class					= 4;
	refShip.Cannon  				= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  			= 20;
	refShip.Weight					= Tonnes2CWT(270);
	refShip.Capacity   				= 1900;
	refShip.CannonsQuantity			= 20;	// 4,2,7,7
	refShip.CannonsQuantityMin		= 20;
	refShip.rcannon 				= 7;
	refShip.lcannon 				= 7;
	refShip.fcannon 				= 4;
	refShip.bcannon 				= 2;	
	refShip.MaxCrew        			= 137;
	refShip.OptCrew        			= 110;
	refShip.MinCrew        			= 20;
	
	refShip.SpeedRate      			= 17.0;
	refShip.TurnRate       			= 65.0;
	refShip.Price          			= 30500;
	refShip.HP             			= 1950;
	refShip.SP             			= 100;
	refship.CabinType          		= "Cabin_Medium";
	refship.Type.Merchant			= false;
	refship.Type.War				= true;
	refship.QuestShip				= true; 

	refShip.lowpolycrew				= 12;
	refship.WindAgainstSpeed   		= 1.60;
		
	refship.Rocking.y				= 0.5;
	refship.Rocking.az				= 0.04;
	
	refship.WaterLine				= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 2.5;			refShip.Height.Bombs.DY	= 1.5;
	refShip.Height.Grapes.Y	= 2.76;			refShip.Height.Grapes.DY	= 0.5;
	refShip.Height.Knippels.Y	= 14.4;		refShip.Height.Knippels.DY	= 7.8;
	refShip.Height.Balls.Y		= 2.5;		refShip.Height.Balls.DY	= 1.5;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	//////////////////////////////////////////////////////////////////////////
	//// Приватирский кеч "Мираж" - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MIRAGE]);
	refShip.Name				= "Mirage";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 20;
	refShip.Weight				= Tonnes2CWT(290);
	refShip.Capacity   			= 2300;
	refShip.CannonsQuantity		= 22;	//	4,2,6,6
	refShip.CannonsQuantityMin	= 22;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8
	refShip.fcannon 			= 4;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 200;
	refShip.OptCrew        		= 160;
	refShip.MinCrew        		= 16;	
	refShip.SpeedRate      		= 16.0;
	refShip.TurnRate       		= 45.0;
	refShip.Price          		= 36900;
	refShip.HP             		= 2350;
	refShip.SP             		= 100;
	
	refship.CabinType          	= "Cabin_Medium2"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.40;
	
	refship.Rocking.y			= 0.5;
	refship.Rocking.az			= 0.04;
	
	refship.WaterLine				= -0.02;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.2;		refShip.Height.Bombs.DY	= 0.6;
	refShip.Height.Grapes.Y		= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y	= 17.7;		refShip.Height.Knippels.DY	= 16.7;
	refShip.Height.Balls.Y		= 1.2;		refShip.Height.Balls.DY	= 0.6;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	//// Патрульный бриг "Валькирия"  - квестовый
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_VALCIRIA]);
	refShip.Name				= "Valciria";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 20;
	refShip.Weight				= Tonnes2CWT(310);
	refShip.Capacity   			= 2000;
	refShip.CannonsQuantity		= 20;	// 2,2,8,8
	refShip.CannonsQuantityMin	= 20;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 181;
	refShip.OptCrew        		= 145;
	refShip.MinCrew        		= 22;	
	refShip.SpeedRate      		= 15.5;
	refShip.TurnRate       		= 55.0;
	refShip.Price          		= 35300;
	refShip.HP             		= 2650;
	refShip.SP             		= 100;

	refship.CabinType          	= "Cabin_Medium"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.20;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.6;
	
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	//// Малый фрегат "Гриффондор" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE_QUEST]);
	refShip.Name            			= "Corvette_quest";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(780);
	refShip.Capacity        			= 3800;
	refShip.CannonsQuantity				= 34;	// 2,4,14,14
	refShip.CannonsQuantityMin			= 34;
	refShip.rcannon 					= 14;
	refShip.lcannon 					= 14;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 312;
	refShip.OptCrew         			= 250;
	refShip.MinCrew         			= 45;
	
	refShip.SpeedRate					= 15.75;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 61100;
	refShip.HP              			= 4000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.65;
	refship.CabinType          			= "Cabin_Medium2"; 

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.3;		refShip.Height.Bombs.DY		= 0.6;
	refShip.Height.Grapes.Y				= 3.1;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 14.7;		refShip.Height.Knippels.DY	= 15.0;
	refShip.Height.Balls.Y				= 1.3;		refShip.Height.Balls.DY		= 0.6;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// Полакр Тореро - квестовый
	///////////////////////////////////////////////////////////////////////////	
	makeref(refShip,ShipsTypes[SHIP_POLACRE_QUEST]);
	refShip.Name						= "Polacre_q";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber  				= 24;
	refShip.Weight						= Tonnes2CWT(600);
	refShip.Capacity   					= 3100;
	refShip.CannonsQuantity				= 24; 
	refShip.CannonsQuantityMin			= 24;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 220;
	refShip.OptCrew        				= 175;
	refShip.MinCrew        				= 25;
	
	refShip.SpeedRate      				= 14.25;
	refShip.TurnRate       				= 52.0;
	refShip.Price          				= 55000;
	refShip.HP             				= 3750;
	refShip.SP             				= 100;

	refship.CabinType          			= "Cabin_Medium2";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.35;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	///////////////////////////////////////////////////////////////////////////
	//// Быстрый фрегат "Фортуна" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_L]);
	refShip.Name            			= "ArabellaShip";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(920);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 42;	// 4,4,17,17
	refShip.CannonsQuantityMin			= 42;
	refShip.rcannon 					= 17;
	refShip.lcannon 					= 17;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 425;
	refShip.OptCrew         			= 340;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.25;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 67700;
	refShip.HP              			= 4800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";	

	// --> квестовые корабли - заглушки
	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №0 - 6-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST0]);
	refShip.Name									= "QuestShip0";
	refship.Soundtype								= "lugger";
	refShip.Class									= 6;
	refShip.Cannon									= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber								= 3;
	refShip.Weight									= Tonnes2CWT(10);
	refShip.Capacity								= 80;
	refShip.CannonsQuantity							= 0;
	refShip.CannonsQuantityMin						= 0;
	refShip.rcannon 								= 0;
	refShip.lcannon 								= 0;
	refShip.fcannon 								= 0;
	refShip.bcannon 								= 0;
	refShip.MaxCrew									= 15;
	refShip.OptCrew									= 12;
	refShip.MinCrew									= 1;	
	refShip.SpeedRate								= 7.0;
	refShip.TurnRate								= 75;
	refShip.Price									= 2100;
	refShip.HP										= 150;
	refShip.SP										= 100;
	refship.CanEncounter							= false;
	refship.Type.Merchant							= false;
	refship.Type.War								= false;
	refShip.lowpolycrew 							= 3;

	refShip.Massa 									= 10000.0;
	refShip.Volume 									= 20.0;
	refship.WindAgainstSpeed   						= 1.0;
		
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 0.4;	refShip.Height.Bombs.DY		= 0.2;
	refShip.Height.Grapes.Y				= 1.3;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 6.5;	refShip.Height.Knippels.DY	= 5.8;
	refShip.Height.Balls.Y				= 0.4;	refShip.Height.Balls.DY		= 0.2;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;


	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №1 - 5-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST1]);
	refShip.Name            			= "QuestShip1";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS6;
	refShip.MaxCaliber      			= 12;
	refShip.Weight						= Tonnes2CWT(170);
	refShip.Capacity        			= 900;	
	refShip.CannonsQuantity				= 14; // 2,2,5,5	2,2,4,4
	refShip.CannonsQuantityMin			= 12;
	refShip.rcannon 					= 5;
	refShip.lcannon 					= 5;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 62;
	refShip.OptCrew         			= 50;
	refShip.MinCrew         			= 10;	
	refShip.SpeedRate					= 14.0;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 14500;
	refShip.HP              			= 900;
	refShip.SP              			= 100;

	refship.Type.Merchant				= true;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	refShip.lowpolycrew 				= 8;
	
	refship.Rocking.y 					= 0.45;
	refship.Rocking.az 					= 0.02;
	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	
	refship.WindAgainstSpeed   			= 1.30;

	refShip.Height.Bombs.Y				= 1.6;	refShip.Height.Bombs.DY		= 1.25;
	refShip.Height.Grapes.Y				= 2.75;	refShip.Height.Grapes.DY	= 0.6;
	refShip.Height.Knippels.Y			= 13.2;	refShip.Height.Knippels.DY	= 8.5;
	refShip.Height.Balls.Y				= 1.6;	refShip.Height.Balls.DY		= 1.25;
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	
	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №2 - 4-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST2]);
	refShip.Name				= "QuestShip2";
	refship.Soundtype			= "lugger";
	refShip.Class				= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber  		= 20;
	refShip.Weight				= Tonnes2CWT(310);
	refShip.Capacity   			= 2000;
	refShip.CannonsQuantity		= 20;	// 2,2,8,8
	refShip.CannonsQuantityMin	= 20;
	refShip.rcannon 			= 8;
	refShip.lcannon 			= 8;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;	
	refShip.MaxCrew        		= 181;
	refShip.OptCrew        		= 145;
	refShip.MinCrew        		= 22;	
	refShip.SpeedRate      		= 15.5;
	refShip.TurnRate       		= 55.0;
	refShip.Price          		= 35300;
	refShip.HP             		= 2650;
	refShip.SP             		= 100;

	refship.CabinType          	= "Cabin_Medium"; 
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refship.QuestShip			= true; 
	refShip.lowpolycrew			= 12;

	refship.WindAgainstSpeed   	= 1.20;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= -0.6;
	
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.5;			refShip.Height.Bombs.DY	= 0.7;
	refShip.Height.Grapes.Y	= 2.8;			refShip.Height.Grapes.DY	= 1.4;
	refShip.Height.Knippels.Y	= 16.9;		refShip.Height.Knippels.DY	= 15.4;
	refShip.Height.Balls.Y		= 1.5;		refShip.Height.Balls.DY	= 0.7;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	
	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №3 - 4-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST3]);
	refShip.Name            			= "QuestShip2";
	refship.Soundtype					= "corvette";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 18;	
	refShip.Weight						= Tonnes2CWT(320);	
	refShip.Capacity        			= 1800;
	refShip.CannonsQuantity				= 16; // 2,0,7,7	2,0,6,6
	refShip.CannonsQuantityMin			= 14;
	refShip.rcannon 					= 7;
	refShip.lcannon 					= 7;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 0;		
	refShip.MaxCrew         			= 175;
	refShip.OptCrew         			= 140;
	refShip.MinCrew         			= 16;	
	refShip.SpeedRate       			= 14.0;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 33900;
	refShip.HP              			= 2800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;	
	refship.QuestShip					= true;
	refShip.lowpolycrew 				= 12;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.04;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 1.40;
	
	refship.CabinType          			= "Cabin_Medium"; 

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y			= 13.2;		refShip.Height.Knippels.DY	= 11.6;
	refShip.Height.Balls.Y				= 2.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= false;
	refship.nation.france	= false
	refship.nation.spain	= true;;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;
	
		
	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №4 - 3-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST4]);
	refShip.Name						= "QuestShip4";
	refship.Soundtype					= "lugger";
	refShip.Class						= 3;
	refShip.Cannon  					= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber  				= 24;
	refShip.Weight						= Tonnes2CWT(600);
	refShip.Capacity   					= 3100;
	refShip.CannonsQuantity				= 24; 
	refShip.CannonsQuantityMin			= 24;
	refShip.rcannon 					= 10;
	refShip.lcannon 					= 10;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew        				= 220;
	refShip.OptCrew        				= 175;
	refShip.MinCrew        				= 25;
	
	refShip.SpeedRate      				= 14.25;
	refShip.TurnRate       				= 52.0;
	refShip.Price          				= 55000;
	refShip.HP             				= 3750;
	refShip.SP             				= 100;

	refship.CabinType          			= "Cabin_Medium2";
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew					= 12;

	refship.WindAgainstSpeed   			= 1.35;
		
	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;
	
	refship.WaterLine	= 0.0;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y		= 1.7;		refShip.Height.Bombs.DY	= 0.8;
	refShip.Height.Grapes.Y		= 3.4;		refShip.Height.Grapes.DY	= 1.7;
	refShip.Height.Knippels.Y	= 10.1;		refShip.Height.Knippels.DY	= 9.2;
	refShip.Height.Balls.Y		= 1.7;		refShip.Height.Balls.DY	= 0.8;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";	

	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №5 - 3-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST5]);
	refShip.Name            			= "QuestShip5";
	refship.Soundtype					= "corvette";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 20;
	refShip.Weight						= Tonnes2CWT(600);
	refShip.Capacity        			= 2700;
	refShip.CannonsQuantity				= 20; // 2,2,8,8	2,2,7,7
	refShip.CannonsQuantityMin			= 18;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	
	refShip.MaxCrew         			= 225;
	refShip.OptCrew						= 180;
	refShip.MinCrew         			= 28;
	
	refShip.SpeedRate					= 14.5;
	refShip.TurnRate        			= 40.0;
	refShip.Price           			= 45500;
	refShip.HP              			= 3250;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	refShip.lowpolycrew 				= 16;

	refship.Rocking.y 					= 0.8;
	refship.Rocking.az 					= 0.025;
	
	refship.WaterLine					= 0.0;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin_Medium2";
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 2.614;	refShip.Height.Bombs.DY		= 1.346;
	refShip.Height.Grapes.Y				= 4.694;	refShip.Height.Grapes.DY	= 0.666;
	refShip.Height.Knippels.Y			= 15.333;	refShip.Height.Knippels.DY	= 13.425;
	refShip.Height.Balls.Y				= 2.614;	refShip.Height.Balls.DY		= 1.346;	
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= false;
	refship.nation.holland	= false;
	refship.nation.pirate	= true;
	
	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №6 - 2-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST6]);
	refShip.Name            			= "QuestShip6";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(920);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 42;	// 4,4,17,17
	refShip.CannonsQuantityMin			= 42;
	refShip.rcannon 					= 17;
	refShip.lcannon 					= 17;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	
	refShip.MaxCrew         			= 425;
	refShip.OptCrew         			= 340;
	refShip.MinCrew         			= 50;
	
	refShip.SpeedRate       			= 17.25;
	refShip.TurnRate        			= 37.25;
	refShip.Price           			= 67700;
	refShip.HP              			= 4800;
	refShip.SP              			= 100;

	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 

	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.60;
	refship.CabinType          			= "Cabin"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 3.4;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 5.3;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;	refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 3.4;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №7 - 2-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST7]);
	refShip.Name            			= "QuestShip7";
	refship.Soundtype					= "frigate";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1200);
	refShip.Capacity        			= 4250;
	refShip.CannonsQuantity				= 50;	// 4,6,20,20	4,6,19,19	4,6,18,18
	refShip.CannonsQuantityMin			= 46;
	refShip.rcannon 					= 20;
	refShip.lcannon 					= 20;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 6;	
	refShip.MaxCrew         			= 437;
	refShip.OptCrew         			= 350;
	refShip.MinCrew         			= 56;
	
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 73700;
	refShip.HP              			= 5400;
	refShip.SP              			= 100;
	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew 				= 20;
	
	refship.Rocking.y 					= 0.4;
	refship.Rocking.az 					= 0.035;	
	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 0.45;
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 2.7;		refShip.Height.Bombs.DY		= 1.35;
	refShip.Height.Grapes.Y				= 5.325;	refShip.Height.Grapes.DY	= 1.575;
	refShip.Height.Knippels.Y			= 19.5;		refShip.Height.Knippels.DY	= 13.5;
	refShip.Height.Balls.Y				= 2.7;		refShip.Height.Balls.DY		= 1.35;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= false;

	///////////////////////////////////////////////////////////////////////////
	//// квестовый корабль №8 - 1-ый класс
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QUEST8]);
	refShip.Name            			= "QuestShip8";
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;   // на деле это воен кор
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(2000);
	refShip.Capacity        			= 5700;
	refShip.CannonsQuantity				= 56;	// 2,4,25,25	2,4,24,24	2,4,23,23	2,4,22,22
	refShip.CannonsQuantityMin			= 48;
	refShip.rcannon 					= 25;
	refShip.lcannon 					= 25;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;	
	refShip.MaxCrew         			= 750;
	refShip.OptCrew         			= 600;
	refShip.MinCrew         			= 80;	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 93800;
	refShip.HP              			= 7000;
	refShip.SP              			= 100;
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true;
	
	refShip.lowpolycrew 				= 24;

	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
		
	refship.WaterLine					= 0.7;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.15;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            = 0.40;
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 6.7;		refShip.Height.Bombs.DY		= 3.3;
	refShip.Height.Grapes.Y				= 8.3;		refShip.Height.Grapes.DY	= 4.1;
	refShip.Height.Knippels.Y			= 32.1;		refShip.Height.Knippels.DY	= 25.8;
	refShip.Height.Balls.Y				= 6.7;		refShip.Height.Balls.DY		= 3.3;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";	
	
	refship.nation.england	= true;
	refship.nation.france	= true;
	refship.nation.spain	= true;
	refship.nation.holland	= true;
	refship.nation.pirate	= true;
	
	
	// <-- квестовые корабли - заглушки
	
	///////////////////////////////////////////////////////////////////////////
	//// Проклятый "Калеуче" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CURSED_FDM]);
	refShip.Name            			= "Flyingdutchman";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight						= Tonnes2CWT(1500);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity				= 56;	// 6,4,23,23
	refShip.CannonsQuantityMin			= 56;
	refShip.rcannon 					= 23;
	refShip.lcannon 					= 23;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew         			= 777;
	refShip.OptCrew         			= 622;
	refShip.MinCrew         			= 94;	
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 100000;
	refShip.HP              			= 6666;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships/parus_common.tga";	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 24;	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.45;
	
	refship.CabinType          			= "CabineFDM"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 6.4;		refShip.Height.Bombs.DY		= 3.2;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 27.4;		refShip.Height.Knippels.DY	= 23.4;
	refShip.Height.Balls.Y				= 6.4;		refShip.Height.Balls.DY		= 3.2;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	//// Копия "Калеуче" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FDM]);
	refShip.Name            			= "Flyingdutchman_l";  
	refship.Soundtype					= "lineship";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(1500);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity				= 56;	// 6,4,23,23
	refShip.CannonsQuantityMin			= 56;
	refShip.rcannon 					= 23;
	refShip.lcannon 					= 23;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 4;		
	refShip.MaxCrew         			= 777;
	refShip.OptCrew         			= 622;
	refShip.MinCrew         			= 94;	
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 100000;
	refShip.HP              			= 6600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships/parus_common.tga";	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	
	refShip.lowpolycrew 				= 24;	
	refship.Rocking.y 					= 0.5;
	refship.Rocking.az 					= 0.035;
	
	refship.WaterLine					= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   			= 0.45;
	
	refship.CabinType          			= "Cabin_Huge"; 
	refship.DeckType           			= "Big";
		
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.Height.Bombs.Y				= 6.4;		refShip.Height.Bombs.DY		= 3.2;
	refShip.Height.Grapes.Y				= 8.5;		refShip.Height.Grapes.DY	= 4.2;
	refShip.Height.Knippels.Y			= 27.4;		refShip.Height.Knippels.DY	= 23.4;
	refShip.Height.Balls.Y				= 6.4;		refShip.Height.Balls.DY		= 3.2;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	//// Линейный корабль "Реус де Сан-Педро" - квестовый
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LSHIP_QUEST]);
	refShip.Name            			= "Santisima";
	refship.Soundtype					= "manowar";
	refShip.Class						= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 42;
	refShip.Weight						= Tonnes2CWT(3500);
	refShip.Capacity        			= 8500;
	refShip.CannonsQuantity				= 106; // 6,8,38,38
	refShip.CannonsQuantityMin			= 106;
	refShip.rcannon 					= 46;
	refShip.lcannon 					= 46;
	refShip.fcannon 					= 6;
	refShip.bcannon 					= 8;	
	refShip.MaxCrew         			= 1000;
	refShip.OptCrew         			= 800;
	refShip.MinCrew         			= 190;
	
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 141600;
	refShip.HP              			= 12600;
	refShip.SP              			= 100;
	refship.EmblemedSails.normalTex 	= "ships\parus_silk.tga";

	refship.CanEncounter 				= false;	
	refship.Type.Merchant				= false;
	refship.Type.War					= true;
	refship.QuestShip					= true; 
	refShip.lowpolycrew 				= 28;

	refship.Rocking.y 					= 0.3;
	refship.Rocking.az 					= 0.02;

	refship.WaterLine					= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   			= 0.30;
	refship.CabinType          			= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 8.0;		refShip.Height.Bombs.DY		= 4.0;
	refShip.Height.Grapes.Y				= 9.7;		refShip.Height.Grapes.DY	= 4.8;
	refShip.Height.Knippels.Y			= 34.7;		refShip.Height.Knippels.DY	= 26.0;
	refShip.Height.Balls.Y				= 8.0;		refShip.Height.Balls.DY		= 4.0;
	
	refShip.GeraldSails.rey_b2				= 1;
	refShip.GeraldSails.rey_b3				= 1;
	refShip.GeraldSails.rey_c1				= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	///////////////////////////////////////////////////////////////////////////
	//// FORT
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FORT]);
	refShip.Name								= "Fort";
	refShip.isFort      						= true; // для удобства проверок на rRealShip
	refShip.Class								= 1;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber							= 48;
	refShip.Weight								= Tonnes2CWT(22500);
	refShip.Capacity							= 300000;
	refShip.CannonsQuantity						= 68;
	refShip.CannonsQuantityMin					= 68;
	refShip.rcannon 							= 68;
	refShip.lcannon 							= 0;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         					= 1800;
	refShip.OptCrew         					= 1600;
	refShip.MinCrew         					= 400;
	refShip.SpeedRate							= 0.0;
	refShip.TurnRate							= 0;
	refShip.Price								= 12000;
	refShip.HP									= 54000;
	refShip.SP									= 100;
	refShip.CanEncounter						= false;


	/////////////// GOF SHIPS /////////////////////////

	///////////////////////////////////////////////////////////////////////////
	//// bermsloop
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BERMSLOOP]);
	refShip.Name = "GOF_Bermsloop";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 4;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 740;
	refShip.CannonsQuantity		= 8;
	refShip.rcannon 							= 3;
	refShip.lcannon 							= 3;
	refShip.fcannon 							= 1;
	refShip.bcannon 							= 1;
	refShip.MaxCrew         		= 60;
	refShip.MinCrew         			= 4;
	refShip.OptCrew = 48;
	refShip.SpeedRate       			= 11.2;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 7000;
	refShip.HP              			= 1500;
	refShip.SP              			= 100;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 8.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= -0.0;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.5;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";	

	 //Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	/////////////////////////////////////////////////////////////////////////
	//// Schooner - Hannah
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_HANNAH]);
	refShip.Name = "GOF_Hannah";
	refship.Soundtype				= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      	= 4;
	refShip.Weight							= Tonnes2CWT(150);
	refShip.Capacity        			= 950;
	refShip.CannonsQuantity					= 4;
	refShip.rcannon 									= 2;
	refShip.lcannon 									= 2;
	refShip.fcannon 									= 0;
	refShip.bcannon 									= 0;
	refShip.MaxCrew         			= 52;
	refShip.MinCrew         				= 4;
	refShip.OptCrew = 41;
	refShip.SpeedRate					= 11.8;
	refShip.TurnRate        			= 11.0;
	refShip.Price           		= 15000;
	refShip.HP              	= 1800;
	refShip.SP              	= 100;
	refShip.AbordageLocation				= "Boarding Deck_02";
	refship.Type.Merchant						= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed	= 8.0;
	refShip.sea_enchantment		= 2.0;
	refShip.lowpolycrew 					= 10;
	refShip.buildtime 					= 40;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.15;

	refship.WaterLine		= 0.2;

	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.2;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 7.5;//boal
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 8;
	refship.Track1.Width		= "1.2, 2.2";
	refship.Track1.Speed		= "7.2, 8.2";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 6;
	refship.Track2.Width		= "2.2, 3.2";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	//// Ketch - Nonsuch
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_KETCH]);
	refShip.Name = "GOF_Ketch";
	refship.Soundtype				= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      	= 4;
	refShip.Weight							= Tonnes2CWT(150);
	refShip.Capacity        			= 850;
	refShip.CannonsQuantity					= 8;
	refShip.rcannon 									= 4;
	refShip.lcannon 									= 4;
	refShip.fcannon 									= 0;
	refShip.bcannon 									= 0;
	refShip.MaxCrew         		= 60;
	refShip.MinCrew         				= 4;
	refShip.OptCrew = 48;
	refShip.SpeedRate       			= 11.7;
	refShip.TurnRate        				= 10.0;
	refShip.Price           		= 8000;
	refShip.HP              	= 1950;
	refShip.SP              	= 100;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 7.0;
	refShip.sea_enchantment		= 2.0;
	refShip.lowpolycrew 		= 8;
	refShip.buildtime 		= 20;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.15;
	
	refship.WaterLine		= 0.0;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 10.0;//boal
	
	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;
	
	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 9;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "8.0, 10.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7;
	refship.Track2.Width		= "3.0, 4.5";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Bounty
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BOUNTY]);
	refShip.Name = "GOF_Bounty";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 4;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 1450;
	refShip.CannonsQuantity		= 4;
	refShip.rcannon 							= 2;
	refShip.lcannon 							= 2;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 76;
	refShip.MinCrew         			= 10;
	refShip.OptCrew = 60;
	refShip.SpeedRate       			= 10.5;
	refShip.TurnRate        			= 14.0;
	refShip.Price           			= 22000;
	refShip.HP              			= 2400;
	refShip.SP              			= 100;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 2;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.01;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Empress - Empress
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_EMPRESS]);
	refShip.Name = "GOF_Empress";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity       			= 3400;
	refShip.CannonsQuantity		= 10;
	refShip.rcannon 							= 5;
	refShip.lcannon 							= 5;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         		= 106;
	refShip.MinCrew         		= 8;
	refShip.OptCrew = 84;
	refShip.SpeedRate				= 9.7;
	refShip.TurnRate        			= 3.0;
	refShip.Price           			= 34000;
	refShip.HP              			= 1800;
	refShip.SP              			= 100;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant				= true;
	refship.Type.War				= false;
	refShip.fWindAgainstSpeed			= 1.0;
	refShip.sea_enchantment				= 1.8;
	refShip.lowpolycrew 				= 10;
	refShip.buildtime 				= 40;

	refship.Rocking.y 				= 0.4;
	refship.Rocking.az 				= 0.25;
	
	refship.WaterLine				= 0.04;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 7.5;
	refship.Track1.Width				= "6.0, 7.0";
	refship.Track1.Speed				= "7.2, 9.2";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 5.0;
	refship.Track2.Width				= "6.0, 8.0";
	refship.Track2.Speed				= "0.15, 0.25";

	 //Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	//// Lyon Hoy 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_LYON]);
	refShip.Name = "GOF_Lyon";
	refship.Soundtype					= "lugger";
	refShip.Class					= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 4;
	refShip.Weight						= Tonnes2CWT(170);
	refShip.Capacity        			= 1000;
	refShip.CannonsQuantity				= 8;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 0;
	refShip.MaxCrew         			= 70;
	refShip.MinCrew         			= 5;
	refShip.OptCrew = 56;
	refShip.SpeedRate					= 11.8;
	refShip.TurnRate        			= 7.0;
	refShip.Price           			= 20000;
	refShip.HP              			= 2200;
	refShip.SP              			= 100;
	//refShip.AbordageLocation			= "Boarding Deck_02";
	refship.CanEncounter					= true;
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 8.5;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;
	
	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.25;
	
	refship.WaterLine							= -0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 8.0;//boal
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //


	///////////////////////////////////////////////////////////////////////////
	//class 6
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	//// Lugger_h
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_LUGGER_H]);
	refShip.Name = "GOF_Lugger_h";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 990;
	refShip.CannonsQuantity		= 12;
	refShip.rcannon 							= 4;
	refShip.lcannon 							= 4;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 67;
	refShip.MinCrew         			= 5;
	refShip.OptCrew = 53;
	refShip.SpeedRate       			= 12.1;
	refShip.TurnRate        			= 11.0;
	refShip.Price           			= 9100;
	refShip.HP              			= 1250;
	refShip.SP              			= 150;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 7.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine							= 0.50;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 10.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

        ///////////////////////////////////////////////////////////////////////////
	//// Galeoth_h
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_GALEOTH_H]);
	refShip.Name = "GOF_Galeoth_h";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 4;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 850;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 75;
	refShip.MinCrew         			= 11;
	refShip.OptCrew = 60;
	refShip.SpeedRate       			= 12.8;
	refShip.TurnRate        			= 13.0;
	refShip.Price           			= 11000;
	refShip.HP              			= 1930;
	refShip.SP              			= 150;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= -0.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	//// Yacht
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_YACHT]);
	refShip.Name = "GOF_Yacht";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 980;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 83;
	refShip.MinCrew         			= 6;
	refShip.OptCrew = 66;
	refShip.SpeedRate       			= 11.6;
	refShip.TurnRate        			= 14.0;
	refShip.Price           			= 17000;
	refShip.HP              			= 1500;
	refShip.SP              			= 150;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= -0.3;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";	

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Brig - Merchant Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SPEEDY]);
	refShip.Name = "GOF_Speedy";
	refship.Soundtype			= "lugger";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      		= 8;
	refShip.Weight						= Tonnes2CWT(250);
	refShip.Capacity        			= 2200;
	refShip.CannonsQuantity							= 14;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 89;
	refShip.MinCrew         			= 8;
	refShip.OptCrew = 71;
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 14.0;
	refShip.Price           			= 27000;
	refShip.HP              			= 2900;
	refShip.SP              			= 150;
	refShip.AbordageLocation				= "Boarding Deck_02";
	refship.Type.Merchant		= true;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 4.0;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew 		= 16;
	refShip.buildtime 		= 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine		= 0.1;
	refship.SpeedDependWeight	= 0.27;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 3.3;//boal
	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 12;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "6.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "4.0, 6.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS SOPHIE
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SOPHIE]);
	refShip.Name = "GOF_Sophie";
	refship.Soundtype 			= "lugger";
	refShip.Class 			= 6;
	refShip.Cannon 			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber 			= 8;
	refShip.Weight 			= Tonnes2CWT(400);
	refShip.Capacity 			= 2400;
	refShip.CannonsQuantity 		= 18;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew 				= 98;
	refShip.MinCrew 				= 10;
	refShip.OptCrew = 78;
	refShip.SpeedRate 					= 12.5;
	refShip.TurnRate 				= 10.0;
	refShip.Price 					= 33000;
	refShip.HP 					= 3200;
	refShip.SP 					= 150;
	refShip.AbordageLocation 				= "Boarding Deck_02";
	refship.Type.Merchant 					= false;
	refship.Type.War 					= true;
	refShip.fWindAgainstSpeed = 4.0;
	refShip.sea_enchantment = 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.05;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.3;
	refship.WindAgainstSpeed = 3.3;//boal
	refship.CabinType = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX = 0.2; refship.InertiaBrakingX = 2.0;
	refship.InertiaAccelerationY = 12; refship.InertiaBrakingY = 9;
	refship.InertiaAccelerationZ = 6.0; refship.InertiaBrakingZ = 4.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 1.0;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 15.0; refShip.Height.Knippels.DY = 10.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 1.0;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b2.vscale = 0.8;
	refShip.GeraldSails.rey_b3.vscale = 0.8;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width = "2.0, 3.0";
	refship.Track1.Speed = "6.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width = "4.0, 6.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Castel Friedrichsburg - Brigantine Heavy
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_CASTELF]);
	refShip.Name = "GOF_Castelf";
	refship.Soundtype					= "corvette";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight								= Tonnes2CWT(650);
	refShip.Capacity        			= 2700;
	refShip.CannonsQuantity				= 16;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 102;
	refShip.MinCrew         			= 12;
	refShip.OptCrew = 81;
	refShip.SpeedRate       			= 11.5;
	refShip.TurnRate        			= 9.0;
	refShip.Price           			= 31000;
	refShip.HP              			= 3400;
	refShip.SP              			= 150;
	//refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 6.1;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Interceptor
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_INTERCEPTOR]);
	refShip.Name = "GOF_Interceptor";
	refship.Soundtype 			= "lugger";
	refShip.Class 			= 6;
	refShip.Cannon 			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber 			= 8;
	refShip.Weight 			= Tonnes2CWT(400);
	refShip.Capacity 			= 2100;
	refShip.CannonsQuantity 		= 18;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew 				= 96;
	refShip.MinCrew 				= 10;
	refShip.OptCrew = 76;
	refShip.SpeedRate 					= 12.8;
	refShip.TurnRate 				= 10.3;
	refShip.Price 					= 32000;
	refShip.HP 					= 2900;
	refShip.SP 					= 150;
	refShip.AbordageLocation 					= "Boarding Deck_02";
	refship.Type.Merchant 					= false;
	refship.Type.War					 = true;
	refShip.fWindAgainstSpeed = 4.0;
	refShip.sea_enchantment = 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.3;
	refship.WindAgainstSpeed = 3.3;//boal
	refship.CabinType = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 1.0;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 15.0; refShip.Height.Knippels.DY = 10.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 1.0;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b2.vscale = 0.8;
	refShip.GeraldSails.rey_b3.vscale = 0.8;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width = "2.0, 3.0";
	refship.Track1.Speed = "6.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width = "4.0, 6.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Fleut - Derfflinger
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_DERFFLINGER]);
	refShip.Name = "GOF_Derfflinger";
	refship.Soundtype		= "corvette";
	refShip.Class			= 6;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      	= 12;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity        	= 3900;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 		= 8;
	refShip.lcannon 		= 8;
	refShip.fcannon 		= 0;
	refShip.bcannon 		= 0;
	refShip.MaxCrew         	= 150;
	refShip.MinCrew         	= 12;
	refShip.OptCrew = 120;
	refShip.SpeedRate		= 8.0;
	refShip.TurnRate        	= 4.8;
	refShip.Price           	= 58000;
	refShip.HP              	= 3200;
	refShip.SP              	= 150;
	//refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 1.2;
	refShip.sea_enchantment		= 1.5;
	refShip.lowpolycrew 		= 16;
	refShip.buildtime 		= 60;
	
	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.35;
	
	refship.WaterLine		= -0.6;
	refship.SpeedDependWeight	= 0.15;
	refship.SubSeaDependWeight	= 0.8;
	refship.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   	= 4.0;//boal
	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           	= "Medium";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 12;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "8.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "6.0, 8.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Sloop of war
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_NEPTUNUS]);
	refShip.Name = "GOF_Neptunus";
	refship.Soundtype					= "corvette";
	refShip.Class					= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight								= Tonnes2CWT(190);
	refShip.Capacity        			= 1600;
	refShip.CannonsQuantity				= 16;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 96;
	refShip.MinCrew         			= 7;
	refShip.OptCrew = 76;
	refShip.SpeedRate					= 12.6;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 80000;
	refShip.HP              			= 3200;
	refShip.SP              			= 150;
	//refShip.IsSetupedGerald              		= true;
	//refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter					= true;
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.5;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= -0.6;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 2.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Caravel Redonda
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_CARAVELR]);
	refShip.Name = "GOF_CaravelR";
	refship.Soundtype		= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      	= 16;
	refShip.Weight			= Tonnes2CWT(500);
	refShip.Capacity        	= 4100;
	refShip.CannonsQuantity		= 10;
	refShip.rcannon 		= 4;
	refShip.lcannon 		= 4;
	refShip.fcannon 		= 0;
	refShip.bcannon 		= 2;
	refShip.MaxCrew         	= 195;
	refShip.MinCrew         	= 12;
	refShip.OptCrew = 156;
	refShip.SpeedRate		= 8.5;
	refShip.TurnRate        	= 7;
	refShip.Price           	= 42000;
	refShip.HP              	= 3300;
	refShip.SP              	= 150;
	//refShip.AbordageLocation	= "Boarding Deck_02";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 2;
	refShip.sea_enchantment		= 1.5;
	refShip.lowpolycrew 		= 16;
	refShip.buildtime 		= 40;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.35;
	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           	= "Medium";
	
	refship.WaterLine		= 0.0;
	refship.SpeedDependWeight	= 0.15;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 4.0;//boal
	
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 10;
	refship.Track1.Width		= "4.0, 5.0";
	refship.Track1.Speed		= "7.2, 9.2";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "5.0, 7.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= true; //


	///////////////////////////////////////////////////////////////////////////
	//class 5
	///////////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////////
	/// Dutch - Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_DUTCHPINNACE]);
	refShip.Name = "GOF_DutchPinnace";
	refship.Soundtype		= "frigate";
	refShip.Class			= 5;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      	= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        	= 5400;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 		= 8;
	refShip.lcannon 		= 8;
	refShip.fcannon 		= 2;
	refShip.bcannon 		= 2;
	refShip.MaxCrew			= 178;
	refShip.MinCrew         	= 14;
	refShip.OptCrew = 142;
	refShip.SpeedRate		= 8.6;
	refShip.TurnRate        	= 5.0;
	refShip.Price           	= 95000;
	refShip.HP              	= 4650;
	refShip.SP              	= 200;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 1.1;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 80;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.35;

	refship.WaterLine		= -0.4;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 1.3;
	refship.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   	= 6.0;//boal
    	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           	= "Medium";
    
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.85;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.30;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "5.7, 7.9";
	refship.Track1.Speed		= "6.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "10.0, 12.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Pinnace - Fregatte Berlin
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_PINNACEBERLIN]);
	refShip.Name = "GOF_PinnaceBerlin";
	refship.Soundtype		= "frigate";
	refShip.Class			= 5;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      	= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        	= 2450;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 		= 8;
	refShip.lcannon 		= 8;
	refShip.fcannon 		= 2;
	refShip.bcannon 		= 2;
	refShip.MaxCrew			= 120;
	refShip.MinCrew         	= 10;
	refShip.OptCrew = 96;
	refShip.SpeedRate		= 12.1;
	refShip.TurnRate        	= 6.0;
	refShip.Price           	= 98000;
	refShip.HP              	= 2850;
	refShip.SP              	= 200;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 1.3;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 28;
	refShip.buildtime 		= 80;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.35;

	refship.WaterLine		= -0.4;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 1.3;
	refship.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   	= 6.0;//boal
    	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           	= "Medium";
    
	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.85;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.30;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "5.7, 7.9";
	refship.Track1.Speed		= "6.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "10.0, 12.0";
	refship.Track2.Speed		= "0.15, 0.25";
	
	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS Greyhound - English Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_GREYHOUND]);
	refShip.Name = "GOF_Greyhound";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 2410;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 114;
	refShip.MinCrew         			= 12;
	refShip.OptCrew = 91;
	refShip.SpeedRate       			= 12.8;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 75000;
	refShip.HP              			= 2800;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.37;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// 28GUNFRIGATE - 28 Gun Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_28GUNFRIGATE]);
	refShip.Name = "GOF_28GunFrigate";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity				= 28;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 159;
	refShip.MinCrew         			= 13;
	refShip.OptCrew = 127;
	refShip.SpeedRate					= 12.9;
	refShip.TurnRate        			= 11.0;
	refShip.Price           			= 110000;
	refShip.HP              			= 2500;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// PDN - 24 gun privateer schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_PDN]);
	refShip.Name = "GOF_PDN";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity				= 24;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 125;
	refShip.MinCrew         			= 13;
	refShip.OptCrew = 100;
	refShip.SpeedRate					= 12.4;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 110000;
	refShip.HP              			= 2500;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= -1.0;
	refship.SpeedDependWeight			= 0.1;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// PacketBrig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_PACKET_BRIG]);
	refShip.Name = "GOF_Packet_Brig";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1800;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 103;
	refShip.MinCrew         			= 7;
	refShip.OptCrew = 82;
	refShip.SpeedRate       			= 12.7;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 39000;
	refShip.HP              			= 2500;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.49;
	refship.SpeedDependWeight			= 0.37;
	refship.SubSeaDependWeight			= 0.69;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //
	
	///////////////////////////////////////////////////////////////////////////
	/// ENTERPRISE - Frigate L'Enterprise
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_ENTERPRISE]);
	refShip.Name = "GOF_Enterprise";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 2150;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 115;
	refShip.MinCrew         			= 9;
	refShip.OptCrew = 92;
	refShip.SpeedRate       			= 11.5;
	refShip.TurnRate        			= 10.0;
	refShip.Price           			= 27000;
	refShip.HP              			= 2700;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	// Privateer
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SLOOPOFWAR]);
	refShip.Name = "GOF_SloopofWar";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity        			= 1850;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 						= 9;
	refShip.lcannon 						= 9;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         			= 110;
	refShip.MinCrew         			= 9;
	refShip.OptCrew = 88;
	refShip.SpeedRate					= 11.8;
	refShip.TurnRate        			= 13.0;
	refShip.Price           			= 33000;
	refShip.HP              			= 2100;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed			= 4.2;
	refShip.sea_enchantment				= 1.5;
	refShip.lowpolycrew 				= 12;
	refShip.buildtime 				= 80;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine = 0.34;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.74;
	refship.TurnDependWeight = 0.8;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// 20 Gun Brig - Light Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BRIG_20_GUN1_18]);
	refShip.Name = "GOF_Brig_20_Gun1_18";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1850;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 116;
	refShip.MinCrew         			= 12;
	refShip.OptCrew = 92;
	refShip.SpeedRate       			= 12.8;
	refShip.TurnRate        			= 13.0;
	refShip.Price           			= 31000;
	refShip.HP              			= 2100;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.57;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.87;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	//// schooner_L - Gaff Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SCHOONER_L]);
	refShip.Name = "GOF_Schooner_l";
	refship.Soundtype					= "lugger";
	refShip.Class						= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight						= Tonnes2CWT(300);
	refShip.Capacity        			= 1300;
	refShip.CannonsQuantity				= 20;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 103;
	refShip.MinCrew         			= 9;
	refShip.OptCrew = 82;
	refShip.SpeedRate					= 11.0;
	refShip.TurnRate        			= 14.5;
	refShip.Price           			= 24000;
	refShip.HP              			= 2900;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 9.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine					= -0.5;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 8.0;//boal
	
	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;		refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //


	///////////////////////////////////////////////////////////////////////////
	// Hooker1 - Fast Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_HOOKER1]);
	refShip.Name = "GOF_Hooker1";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity        			= 1300;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 						= 9;
	refShip.lcannon 						= 9;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         			= 105;
	refShip.MinCrew         			= 9;
	refShip.OptCrew = 84;
	refShip.SpeedRate       			= 12.1;
	refShip.TurnRate        			= 14.5;
	refShip.Price           			= 20500;
	refShip.HP              			= 2050;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.7;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.9;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 10.0;//boal
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Brig SS - Fast Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BRIG3]);
	refShip.Name = "GOF_Brig3";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1800;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 121;
	refShip.MinCrew         			= 12;
	refShip.OptCrew = 96;
	refShip.SpeedRate       			= 12.8;
	refShip.TurnRate        			= 13.0;
	refShip.Price           			= 29000;
	refShip.HP              			= 2300;
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.49;
	refship.SpeedDependWeight			= 0.37;
	refship.SubSeaDependWeight			= 0.69;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //


	///////////////////////////////////////////////////////////////////////////
	//class 4
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	/// Galeon - Apost�l Felipe
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_FELIPE]);
	refShip.Name = "GOF_Felipe";
	refship.Soundtype				= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      	= 12;
	refShip.Weight						= Tonnes2CWT(1100);
	refShip.Capacity        			= 5150;
	refShip.CannonsQuantity		= 30;
	refShip.rcannon 						= 14;
	refShip.lcannon 						= 14;
	refShip.fcannon 						= 0;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         	= 188;
	refShip.MinCrew         	= 22;
	refShip.OptCrew = 150;
	refShip.SpeedRate		= 7.8;
	refShip.TurnRate        		= 4.0;
	refShip.Price           	= 125000;
	refShip.HP              	= 4800;
	refShip.SP              	= 250;
	refShip.AbordageLocation		= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed		= 1.1;
	refShip.sea_enchantment		= 1.2;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 80;

	
	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.41;
	
	refship.WaterLine		= 0.0;

	refship.SpeedDependWeight	= 0.15;
	refship.SubSeaDependWeight	= 0.3;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 2.6;//boal
	refship.CabinType          	= "Cabin"; // boal 28.03.05
	refship.DeckType           	= "Big";
	
	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.98;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.0;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "5.2, 7.3";
	refship.Track1.Speed		= "5.5, 6.5";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "6.0, 8.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Frigate Surprise
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SURPRISE]);
	refShip.Name = "GOF_Surprise";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity				= 30;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 190;
	refShip.MinCrew         			= 24;
	refShip.OptCrew = 152;
	refShip.SpeedRate					= 11.8;
	refShip.TurnRate        			= 12.5;
	refShip.Price           			= 110000;
	refShip.HP              			= 4500;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Fast Frigate - Light Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_CORVFRIG2_50]);
	refShip.Name = "GOF_CorvFrig2_50";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 2600;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 179;
	refShip.MinCrew         			= 21;
	refShip.OptCrew = 143;
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 14.0;
	refShip.Price           			= 80000;
	refShip.HP              			= 4100;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.1;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.15;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// RaaFrigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_RaaFrigate]);
	refShip.Name = "GOF_RaaFrigate";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3400;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 15;
	refShip.lcannon 							= 15;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 175;
	refShip.MinCrew         			= 22;
	refShip.OptCrew = 140;
	refShip.SpeedRate					= 12.9;
	refShip.TurnRate        			= 11.6;
	refShip.Price           			= 113000;
	refShip.HP              			= 5500;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.3;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	// Nightmare
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_NIGHTMARE]);
	refShip.Name = "GOF_Nightmare";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 							= 18; //might be 14
	refShip.lcannon 							= 18; // might be 14
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 200;
	refShip.MinCrew         			= 21;
	refShip.OptCrew = 160;
	refShip.SpeedRate       			= 12.2;
	refShip.TurnRate        			= 11.0;
	refShip.Price           			= 140000;
	refShip.HP              			= 5800;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 3.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	///  Unicorn - Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_UNICORN]);
	refShip.Name = "GOF_Unicorn";
	refship.Soundtype						= "frigate";
	refShip.Class				= 4;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight									= Tonnes2CWT(1000);
	refShip.Capacity        		= 3200;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 									= 18;
	refShip.lcannon 									= 18;
	refShip.fcannon 									= 2;
	refShip.bcannon 									= 0;
	refShip.MaxCrew         		= 209;
	refShip.MinCrew         			= 22;
	refShip.OptCrew = 167;
	refShip.SpeedRate       				= 11.9;
	refShip.TurnRate        			= 12.0;
	refShip.Price           		= 230000;
	refShip.HP              	= 5400;
	refShip.SP              	= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant			= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 3.0;
	refShip.sea_enchantment		= 1.2;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 220;

	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine		= -0.35;

	refship.SpeedDependWeight	= 0.3;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed  	= 3.6;//boal
	refship.CabinType          	= "Cabin"; // boal 28.03.05
	refship.DeckType           	= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.9;
	refShip.GeraldSails.rey_b2.vscale	= 0.7;
	refShip.GeraldSails.rey_b3.vscale	= 0.7;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "3.7, 3.9";
	refship.Track1.Speed		= "7.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "8.0, 9.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Fast Galleon - Golden Hind
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_FASTGALLEON1]);
	refShip.Name = "GOF_FastGalleon1";
	refship.Soundtype					= "corvette";
	refShip.Class					= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 5900;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 220;
	refShip.MinCrew         			= 25;
	refShip.OptCrew = 176;
	refShip.SpeedRate					= 7.1;
	refShip.TurnRate        			= 4.7;
	refShip.Price           			= 111000;
	refShip.HP              			= 5400;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 1.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine							= -0.7;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Galeon1 - Carrack
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_GALEON1]);
	refShip.Name = "GOF_Galeon1";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 6150;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 223;
	refShip.MinCrew         			= 27;
	refShip.OptCrew = 178;
	refShip.SpeedRate					= 7.0;
	refShip.TurnRate        			= 5.0;
	refShip.Price           			= 124000;
	refShip.HP              			= 6800;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	
	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine							= 0.2;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";	

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Light Galleon - Whydah
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_PO_FLEUT50]);
	refShip.Name = "GOF_PO_Fleut50";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity        			= 6300;
	refShip.CannonsQuantity		= 30;
	refShip.rcannon 							= 12;
	refShip.lcannon 							= 12;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 230;
	refShip.MinCrew         			= 25;
	refShip.OptCrew = 184;
	refShip.SpeedRate					= 8.0;
	refShip.TurnRate        			= 5.0;
	refShip.Price           			= 69000;
	refShip.HP              			= 4100;
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 2.1;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.3;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 4.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// TheBlackPearl - Wicked Wench 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_THEBLACKPEARL]);
	refShip.Name = "GOF_TheBlackPearl";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 190;
	refShip.MinCrew         			= 20;
	refShip.OptCrew = 152;
	refShip.SpeedRate       			= 8.6;
	refShip.TurnRate        			= 6.0;
	refShip.Price           			= 70000;
	refShip.HP              			= 3900;
	refShip.SP              			= 250;
	refship.EmblemedSails.normalTex = "ships\sail_BlackPearl.tga";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter				= false;
	refship.Type.Merchant				= true;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 4.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew 				= 20;
	refShip.buildtime 				= 100;

	
	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine				= -0.7;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 14.5;
	refship.Track1.Width				= "3.7, 3.9";
	refship.Track1.Speed				= "7.0, 8.0";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 8.5;
	refship.Track2.Width				= "8.0, 9.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //
	
	///////////////////////////////////////////////////////////////////////////
	//class 3
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	/// Boussole
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BOUSSOLE]);
	refShip.Name = "GOF_Boussole";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 3;
	refShip.Cannon 			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber 			= 16;
	refShip.Weight 								= Tonnes2CWT(1000);
	refShip.Capacity 			= 3500;
	refShip.CannonsQuantity 		= 42;
	refShip.rcannon 					= 19;
	refShip.lcannon 					= 19;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew 			= 230;
	refShip.MinCrew 			= 27;
	refShip.OptCrew = 184;
	refShip.SpeedRate 				= 12.3;
	refShip.TurnRate 			= 11.0;
	refShip.Price 				= 145000;
	refShip.HP 				= 5500;
	refShip.SP  				= 300;
	refShip.AbordageLocation 	= "Boarding Deck_01";
	refship.Type.Merchant 				= false;
	refship.Type.War 					= true;
	refShip.fWindAgainstSpeed 	= 3.3;
	refShip.sea_enchantment 	= 1.2;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 100;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine 		= 0.50;
	refship.SpeedDependWeight 	= 0.3;
	refship.SubSeaDependWeight 	= 1.0;
	refship.TurnDependWeight 	= 0.8;
	refship.WindAgainstSpeed 	= 4.5;//boal
	refship.CabinType 		= "Cabin"; // boal 28.03.05
	refship.DeckType 		= "Big";

	refship.InertiaAccelerationX = 5.0; refship.InertiaBrakingX = 5.0;
	refship.InertiaAccelerationY = 4; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 5.0; refship.InertiaBrakingZ = 5.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;
	
	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	// Salamander
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SALAMANDER]);
	refShip.Name = "GOF_Salamander";
	refship.Soundtype					= "frigate";
	refShip.Class					= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity		= 44;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 230;
	refShip.MinCrew         		= 24;
	refShip.OptCrew = 184;
	refShip.SpeedRate       			= 10.8;
	refShip.TurnRate        			= 13.5;
	refShip.Price           			= 156000;
	refShip.HP              			= 5700;
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 3.3;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Linefrigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_LINEFRIGATE]);
	refShip.Name = "GOF_Linefrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(1700);
	refShip.Capacity        			= 3400;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 					= 17;
	refShip.lcannon 					= 17;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 240;
	refShip.MinCrew         			= 22;
	refShip.OptCrew = 192;
	refShip.SpeedRate       			= 10.5;
	refShip.TurnRate        			= 9.0;
	refShip.Price           			= 380000;
	refShip.HP              			= 7000;
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.86;
	
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";
	
	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //
	///////////////////////////////////////////////////////////////////////////
	// Dutch Two-decker
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_TWODECKER1_47]);
	refShip.Name = "GOF_TwoDecker1_47";
	refship.Soundtype			= "linship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity        			= 4100;
	refShip.CannonsQuantity		= 54;
	refShip.rcannon 							= 23;
	refShip.lcannon 							= 23;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         			= 257;
	refShip.MinCrew         			= 20;
	refShip.OptCrew = 205;
	refShip.SpeedRate       				= 12.3;
	refShip.TurnRate        			= 10.0;
	refShip.Price           			= 120000;
	refShip.HP              			= 6550;
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 1.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //
	
	///////////////////////////////////////////////////////////////////////////
	/// USS_CONSTITUTION - Constitution
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_USS_CONSTITUTION]);
	refShip.Name = "GOF_USS_Constitution";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 3;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber 				= 24;
	refShip.Weight 				= Tonnes2CWT(1000);
	refShip.Capacity 				= 4200;
	refShip.CannonsQuantity 			= 56;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew 				= 273;
	refShip.MinCrew 				= 20;
	refShip.OptCrew = 218;
	refShip.SpeedRate 					= 11.5;
	refShip.TurnRate 				= 12.0;
	refShip.Price 					= 180000;
	refShip.HP 					= 7000;
	refShip.SP 					= 300;
	refShip.AbordageLocation = "Boarding Deck_01";
	refship.Type.Merchant 				= false;
	refship.Type.War			        = true;
	refShip.fWindAgainstSpeed = 3.0;
	refShip.sea_enchantment = 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.50;

	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed = 5.2; //boal
	refship.CabinType = "Cabin"; // boal 28.03.05
	refship.DeckType = "Big";

	refship.InertiaAccelerationX = 0.2; refship.InertiaBrakingX = 2.0;
	refship.InertiaAccelerationY = 10; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 4.0; refship.InertiaBrakingZ = 2.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25"; 

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// La Licorne 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_LA_LICORNE]);
	refShip.Name = "GOF_La_Licorne";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 5100;
	refShip.CannonsQuantity				= 52;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         				= 258;
	refShip.MinCrew         				= 24;
	refShip.OptCrew = 206;
	refShip.SpeedRate       				= 10.7;
	refShip.TurnRate        			= 10.6;
	refShip.Price           			= 220000;
	refShip.HP              			= 7700;
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= -0.2;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// RN Battle Frigate - Fast Battle Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_RN_BATTLEFRIGATE]);
	refShip.Name = "GOF_RN_BattleFrigate";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 3;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber 				= 24;
	refShip.Weight 				= Tonnes2CWT(1000);
	refShip.Capacity 				= 4600;
	refShip.CannonsQuantity 			= 54;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew 				= 297;
	refShip.MinCrew 				= 29;
	refShip.OptCrew = 237;
	refShip.SpeedRate 					= 10.7;
	refShip.TurnRate 				= 12.0;
	refShip.Price 					= 230000;
	refShip.HP 					= 6800;
	refShip.SP 					= 300;
	refShip.AbordageLocation = "Boarding Deck_01";
	refship.Type.Merchant			 = false;
	refship.Type.War 			 = true;
	refShip.fWindAgainstSpeed = 3.5;
	refShip.sea_enchantment = 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.50;

	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed = 4.5;//boal
	refship.CabinType = "Cabin"; // boal 28.03.05
	refship.DeckType = "Big";

	refship.InertiaAccelerationX = 5.0; refship.InertiaBrakingX = 5.0;
	refship.InertiaAccelerationY = 4; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 5.0; refship.InertiaBrakingZ = 5.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	// Battle Frigate 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BATTLEFRIGATE]);
	refShip.Name = "GOF_BattleFrigate";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 28;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 2800;
	refShip.CannonsQuantity				= 42;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 250;
	refShip.MinCrew         			= 25;
	refShip.OptCrew = 200;
	refShip.SpeedRate					= 10.8;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 110000;

	refShip.HP              			= 6500;
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.3;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //


	///////////////////////////////////////////////////////////////////////////
	//class 2
	///////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////
	/// Warship 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_WARSHIP]);
	refShip.Name = "GOF_Warship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 5200;
	refShip.CannonsQuantity		= 66;
	refShip.rcannon 							= 30;
	refShip.lcannon 							= 30;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 520;
	refShip.MinCrew         		= 35;
	refShip.OptCrew = 416;
	refShip.SpeedRate					= 8.5;
	refShip.TurnRate        			= 7.2;
	refShip.Price           			= 250000;
	refShip.HP              			= 15900;
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.85;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.5;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //
	
	///////////////////////////////////////////////////////////////////////////
	/// Warship Poseidon
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_POSEIDON]);
	refShip.Name = "GOF_Poseidon";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 5200;
	refShip.CannonsQuantity		= 66;
	refShip.rcannon 				= 30;
	refShip.lcannon 				= 30;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 4;
	refShip.MaxCrew         		= 623;
	refShip.MinCrew         		= 32;
	refShip.OptCrew = 498;
	refShip.SpeedRate			= 8.1;
	refShip.TurnRate        			= 7.0;
	refShip.Price           			= 423000;
	refShip.HP              			= 16500;
	refShip.SP              			= 350;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 1.1;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 		= 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine		= 0.05;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.0;//boal
	refship.CabinType          	= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           	= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //
	
	///////////////////////////////////////////////////////////////////////////
	/// Couronne - La Couronne
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_COURONNE]);
	refShip.Name = "GOF_Couronne";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 36;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity        			= 5700;
	refShip.CannonsQuantity		= 64;
	refShip.rcannon 						= 24;
	refShip.lcannon 						= 24;
	refShip.fcannon 						= 8;
	refShip.bcannon 						= 8;
	refShip.MaxCrew         	= 560;
	refShip.MinCrew         		= 36;
	refShip.OptCrew = 448;
	refShip.SpeedRate		= 8.5;
	refShip.TurnRate        	= 6.0;
	refShip.Price           	= 250000;
	refShip.HP              	= 16800;
	refShip.SP              	= 350;
	refShip.AbordageLocation		= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 		= 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
		
	refship.WaterLine		= 0.1;
	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 0.75;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.0;//boal
	refship.CabinType          	= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           	= "Big";
	
	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.7;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 16.5;
	refship.Track1.Width		= "6.0, 8.2";
	refship.Track1.Speed		= "9.0, 9.0";

	refship.Track2.ZStart		= 0.0;
	refship.Track2.LifeTime 	= 13.5;
	refship.Track2.Width		= "8.0, 9.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	// Superior Warship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_FR_SUPERIORWARSHIP1]);
	refShip.Name = "GOF_FR_SuperiorWarship1";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(3200);
	refShip.Capacity        			= 5600;
	refShip.CannonsQuantity		= 74;
	refShip.rcannon 						= 34;
	refShip.lcannon 						= 34;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 4;
	refShip.MaxCrew         			= 660;
	refShip.MinCrew         			= 38;
	refShip.OptCrew = 528;
	refShip.SpeedRate					= 8.7;
	refShip.TurnRate        			= 6.5;
	refShip.Price           			= 430000;
	refShip.HP              			= 16800;
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine = 0.30;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 4.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 7.0;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 36.0;		refShip.Height.Knippels.DY	= 32.0;
	refShip.Height.Balls.Y				= 4.0;		refShip.Height.Balls.DY		= 2.0;
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship - Le Superbe
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SUPERBE]);
	refShip.Name = "GOF_Superbe";
	refship.Soundtype		= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      		= 42;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        		= 5200;
	refShip.CannonsQuantity		= 78;
	refShip.rcannon 			= 37;
	refShip.lcannon 			= 37;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;
	refShip.MaxCrew         		= 650;
	refShip.MinCrew         		= 38;
	refShip.OptCrew = 520;
	refShip.SpeedRate		= 8.5;
	refShip.TurnRate        		= 6.5;
	refShip.Price           		= 450000;
	refShip.HP              		= 17900;
	refShip.SP              		= 350;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 			= 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine			= -0.1;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.0;//boal
	refship.CabinType          		= "Cabin"; // boal 28.03.05
	refship.DeckType           		= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 		= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 		= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Link - 2nd Rate Ship of the line
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_LINK]);
	refShip.Name = "GOF_Link";
	refship.Soundtype					= "manowar";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(3500);
	refShip.Capacity        			= 5600;
	refShip.CannonsQuantity				= 78;
	refShip.rcannon 					= 37;
	refShip.lcannon 					= 37;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 670;
	refShip.MinCrew         			= 36;
	refShip.OptCrew = 536;
	refShip.SpeedRate					= 8.3;
	refShip.TurnRate        			= 6.1;
	refShip.Price           			= 550000;
	refShip.HP              			= 18500;
	refShip.SP              			= 350;;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine							= -0.2;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //


	///////////////////////////////////////////////////////////////////////////
	//class 1
	///////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////
	/// Battleship 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BATTLESHIP]);
	refShip.Name = "GOF_Battleship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity		= 80;
	refShip.rcannon 							= 36;
	refShip.lcannon 							= 36;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         		= 730;
	refShip.MinCrew         		= 45;
	refShip.OptCrew = 584;
	refShip.SpeedRate					= 7.9;
	refShip.TurnRate        			= 6.0;
	refShip.Price           			= 380000;
	refShip.HP              			= 19800;
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine							= 0.30;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.75;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.7;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship Bellona
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BELLONA]);
	refShip.Name = "GOF_Bellona";
	refship.Soundtype			= "lineship";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity		= 84;
	refShip.rcannon 				= 40;
	refShip.lcannon 				= 40;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew         		= 740;
	refShip.MinCrew         		= 47;
	refShip.OptCrew = 592;
	refShip.SpeedRate			= 7.5;
	refShip.TurnRate        			= 5.2;
	refShip.Price           			= 420000;
	refShip.HP              			= 20900;
	refShip.SP              			= 400;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 		= 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine		= 0.5;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.0;//boal
	refship.CabinType          	= "Cabin"; // boal 28.03.05
	refship.DeckType           	= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Neptune
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_NEPTUNE]);
	refShip.Name = "GOF_Neptune";
	refship.Soundtype		= "lineship";
	refShip.Class			= 1;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      		= 36;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        		= 5200;
	refShip.CannonsQuantity		= 82;
	refShip.rcannon 			= 37;
	refShip.lcannon 			= 37;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 6;
	refShip.MaxCrew         		= 730;
	refShip.MinCrew         		= 42;
	refShip.OptCrew = 584;
	refShip.SpeedRate		= 7.0;
	refShip.TurnRate        		= 5.0;
	refShip.Price           		= 465000;
	refShip.HP              		= 20000;
	refShip.SP              		= 400;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 			= 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine			= 0.2;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.0;//boal
	refship.CabinType          		= "Cabin"; // boal 28.03.05
	refship.DeckType           		= "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 		= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 		= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Manowar
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_MANOWAR]);
	refShip.Name = "GOF_Manowar";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(4000);
	refShip.Capacity        			= 6200;
	refShip.CannonsQuantity		= 102;
	refShip.rcannon 							= 45;
	refShip.lcannon 							= 45;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 8;
	refShip.MaxCrew         			= 821;
	refShip.MinCrew         			= 47;
	refShip.OptCrew = 656;
	refShip.SpeedRate					= 7.0;
	refShip.TurnRate        			= 4.5;
	refShip.Price           			= 500000;
	refShip.HP              			= 22500;
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS_Victory - Victory
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_HMS_VICTORY]);
	refShip.Name = "GOF_HMS_Victory";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(4000);
	refShip.Capacity        			= 6700;
	refShip.CannonsQuantity				= 104;
	refShip.rcannon 							= 50;
	refShip.lcannon 							= 50;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 821;
	refShip.MinCrew         			= 47;
	refShip.OptCrew = 656;
	refShip.SpeedRate					= 6.8;
	refShip.TurnRate        			= 4.2;
	refShip.Price           			= 570000;
	refShip.HP              			= 22500;
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Victory"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;
	
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_c1			= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	// Battle Manowar
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BATTLEMANOWAR]);
	refShip.Name = "GOF_BattleManowar";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(4100);
	refShip.Capacity        			= 6700;
	refShip.CannonsQuantity				= 102;
	refShip.rcannon 					= 46;
	refShip.lcannon 					= 46;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 8;
	refShip.MaxCrew         			= 884;
	refShip.MinCrew         			= 47;
	refShip.OptCrew = 707;
	refShip.SpeedRate					= 6.0;
	refShip.TurnRate        			= 4.0;
	refShip.Price           			= 570000;
	refShip.HP              			= 23000;
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 6.7;		refShip.Height.Bombs.DY		= 3.0;
	refShip.Height.Grapes.Y				= 11.0;		refShip.Height.Grapes.DY	= 3.0;
	refShip.Height.Knippels.Y			= 46.0;		refShip.Height.Knippels.DY	= 40.0;
	refShip.Height.Balls.Y				= 6.7;		refShip.Height.Balls.DY		= 3.0;
	
	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= false; //
	refShip.nation.spain	= true; //

	// fantasy ships

	///////////////////////////////////////////////////////////////////////////
	/// BlackPearl 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BLACKPEARL]);
	refShip.Name = "GOF_BlackPearl";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 4800;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 190;
	refShip.MinCrew         			= 20;
	refShip.OptCrew = 152;
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 8.0;
	refShip.Price           			= 70000;
	refShip.HP              			= 4800;
	refShip.SP              			= 250;
	refship.EmblemedSails.normalTex = "ships\sail_BlackPearl.tga";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter				= false;
	refship.Type.Merchant				= true;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 4.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew 				= 20;
	refShip.buildtime 				= 100;

	
	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine				= -0.7;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 14.5;
	refship.Track1.Width				= "3.7, 3.9";
	refship.Track1.Speed				= "7.0, 8.0";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 8.5;
	refship.Track2.Width				= "8.0, 9.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// QueenAnnesRevenge
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_QueenAnnesRevenge]);
	refShip.Name = "GOF_QueenAnnesRevenge";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity		= 44;
	refShip.rcannon 							= 20;
	refShip.lcannon 							= 20;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 230;
	refShip.MinCrew         			= 22;
	refShip.OptCrew = 184;
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 7.0;
	refShip.Price           			= 70000;
	refShip.HP              			= 5800;
	refShip.SP              			= 300;
	refship.EmblemedSails.normalTex = "ships\sail_QueenAnnesRevenge.tga";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter				= true;
	refship.Type.Merchant				= true;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 4.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew 				= 20;
	refShip.buildtime 				= 100;

	
	refship.Rocking.y 				= 0.4;
	refship.Rocking.az 				= 0.35;
	
	refship.WaterLine				= 0.5;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 14.5;
	refship.Track1.Width				= "3.7, 3.9";
	refship.Track1.Speed				= "7.0, 8.0";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 8.5;
	refship.Track2.Width				= "8.0, 9.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Revenge                       
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_REVENGE]);
	refShip.Name = "GOF_Revenge";
	refship.Soundtype				= "frigate";
	refShip.Class					= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber      			= 16;
	refShip.Weight					= Tonnes2CWT(1100);
	refShip.Capacity        			= 5200;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 				= 19;
	refShip.lcannon 				= 19;
	refShip.fcannon 				= 0;
	refShip.bcannon 				= 2;
	refShip.MaxCrew         			= 234;
	refShip.MinCrew         			= 27;
	refShip.OptCrew = 187;
	refShip.SpeedRate				= 9.0;
	refShip.TurnRate        			= 11.0;
	refShip.Price           			= 105000;
	refShip.HP              			= 5800;
	refShip.SP              			= 300;

	refship.CabinType                               = "Cabin_Small"; // boal 28.03.05
	refship.DeckType                                = "Low";
	refship.CabinType          			= "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           			= "Medium";
	refship.CabinType          	                = "Cabin"; // boal 28.03.05
    	refship.DeckType           	                = "Big";
	refShip.AbordageLocation			= "BOARDING_SMALL_DECK";
	refShip.AbordageLocation	                = "Boarding Deck_01";
	refShip.AbordageLocation			= "Boarding Deck_02";

	refship.Type.Merchant				= true;
	refship.Type.War				= true;

	refShip.fWindAgainstSpeed			= 1.6;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew                             = 20;
	refShip.buildtime                               = 80;


	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine				= 0.0;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed                        = 2.6;//boal

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	///////////////////////////////////////////////////////////////////////////
	/// Cursed Flying Dutchman - The Flying Dutchman
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_CURSEDDUTCHMAN]);
	refShip.Name = "GOF_CursedDutchman";
	refship.Soundtype 				= "manowar";
	refShip.Class 					= 3;
	refShip.Cannon 								= CANNON_TYPE_CANNON_LBS3;
	refShip.MaxCaliber 				= 24;
	refShip.Weight 								= Tonnes2CWT(2200);
	refShip.Capacity 				= 5300;
	refShip.CannonsQuantity 		= 58;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 6;
	refShip.bcannon 							= 0;
	refShip.MaxCrew 			= 280;
	refShip.MinCrew 			= 26;
	refShip.OptCrew = 224;
	refShip.SpeedRate 					= 13.5;
	refShip.TurnRate 				= 8.0;
	refShip.Price 					= 200000;
	refShip.HP 					= 5900;
	refShip.SP 					= 300;
	refship.EmblemedSails.normalTex = "ships\sail_Dutchman.tga";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter					= false;
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine							= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 3.8;//boal
	refship.CabinType          = "CabineFDM"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
	refShip.nation.england	= false; //
	refShip.nation.france	= false; //
	refShip.nation.holland	= false; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= false; //

	//quest ships

	///////////////////////////////////////////////////////////////////////////
	/// ����� ������
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_SOLEYRU]);
	refShip.Name = "GOF_SoleyRu";
	refship.Soundtype			= "manowar";
	refShip.Class 				= 1;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber 				= 48;
	refShip.Weight 				= Tonnes2CWT(4500);
	refShip.Capacity 				= 7000;
	refShip.CannonsQuantity				= 112;
	refShip.rcannon 							= 48;
	refShip.lcannon 							= 48;
	refShip.fcannon 							= 6;
	refShip.bcannon 							= 10;
	refShip.MaxCrew 			= 1200;
	refShip.MinCrew 			= 56;
	refShip.OptCrew = 960;
	refShip.SpeedRate 					= 9.6;
	refShip.TurnRate 				= 4.0;
	refShip.Price 					= 650000;
	refShip.HP 					= 24700;
	refShip.SP 					= 400;
	refship.EmblemedSails.normalTex = "ships\parus_SoleyRu.tga";
	refShip.AbordageLocation			= "Boarding Deck_01";

	refship.CanEncounter = false;
	
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.41;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 1.3;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";

	//////////////////////////////////////////////////////////////////////////
	// BrigQeen
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BRIGQEEN]);
	refShip.Name = "GOF_BrigQeen";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon  			= CANNON_TYPE_CULVERINE_LBS8;
	refShip.MaxCaliber 			 = 16;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity   			= 2500;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 				= 10;
	refShip.lcannon 				= 10;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew        		= 130;
	refShip.MinCrew        		= 12;
	refShip.OptCrew = 104;
	refShip.SpeedRate      		= 15.0;
	refShip.TurnRate       		= 12.0;
	refShip.Price          		= 67500;
	refShip.HP             		= 3500;
	refShip.SP             		= 200;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 4.3;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew			= 12;
	refShip.buildtime			= 60;

	refship.WindAgainstSpeed   = 4.5;//boal

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine	= 0.50;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.0;			refShip.Height.Bombs.DY	= 1.0;
	refShip.Height.Grapes.Y	= 2.0;			refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 16.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY	= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	// BrigSW
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_BRIGSW]);
	refShip.Name = "GOF_BrigSW";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber 			 = 16;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity   			= 2500;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 				= 10;
	refShip.lcannon 				= 10;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew        			= 130;
	refShip.MinCrew        			= 12;
	refShip.OptCrew = 104;
	refShip.SpeedRate      		= 15.5;
	refShip.TurnRate       		= 12.0;
	refShip.Price          		= 70500;
	refShip.HP             		= 3500;
	refShip.SP             		= 200;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 4.5;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew			= 12;
	refShip.buildtime			= 60;

	refship.WindAgainstSpeed   = 4.2;//boal

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;
	
	refship.WaterLine	= 0.50;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;
	
	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.0;			refShip.Height.Bombs.DY	= 1.0;
	refShip.Height.Grapes.Y	= 2.0;			refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 16.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY	= 1.0;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;
	
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";


	///////////////////////////////////////////////////////////////////////////
	/// Frigate Arabella
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_ARABELLA]);
	refShip.Name = "GOF_ArabellaShip";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity				= 52;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 300;
	refShip.MinCrew         			= 25;
	refShip.OptCrew = 240;
	refShip.SpeedRate       			= 15.4;
	refShip.TurnRate        			= 12.0;
	refShip.Price           			= 250000;
	refShip.HP              			= 6650;
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;
	
	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.15;

	refship.WaterLine							= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.29;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;
	
	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
	refShip.nation.england	= true; //
	refShip.nation.france	= true; //
	refShip.nation.holland	= true; //
	refShip.nation.pirate	= true; //
	refShip.nation.spain	= true; //

	///////////////////////////////////////////////////////////////////////////
	/// Flyingdutchman 
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[GOF_SHIP_FLYINGDUTCHMAN]);
	refShip.Name = "GOF_Flyingdutchman";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity						= 60;
	refShip.rcannon 							= 24;
	refShip.lcannon 							= 24;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 8;
	refShip.MaxCrew         			= 840;
	refShip.MinCrew         			= 47;
	refShip.OptCrew = 672;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 4.0;
	refShip.Price           			= 600000;
	refShip.HP              			= 25500;
	refShip.SP              			= 350;
	refship.EmblemedSails.normalTex = "ships\sail_Dutchman.tga";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.35;
	
	refship.WaterLine							= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 3.8;//boal
	refship.CabinType          = "CabineFDM"; // boal 28.03.05
	refship.DeckType           = "Big";
	
	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	/// Check
	for (int i=0; i<SHIP_TYPES_QUANTITY_WITH_FORT-1; i++)
	{
	  	makeref(refShip, ShipsTypes[i]);
		if (!CheckAttribute(refShip,"Name")) { continue; }
		if (!CheckAttribute(refShip,"TurnRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have TurnRate attribute");
		}
		if (!CheckAttribute(refShip,"SpeedRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have SpeedRate attribute");
		}
		if (!CheckAttribute(refShip,"Class"))
		{
			Trace("ERROR: Ship " + i + " doesn't have class attribute");
		}
		else
		{
			int iClass = sti(refShip.Class);
			if (iClass > 6) { Trace("ERROR: Ship " + i + " class > 6"); }
			if (iClass < 1) { Trace("ERROR: Ship " + i + " class < 1"); }
		}
		refship.InertiaAccelerationY = stf(refship.InertiaAccelerationY) / 6.0;
		// boal 10/11/05 пробить оптимальный экипаж
		//refShip.OptCrew = sti(refShip.MaxCrew);
		//refShip.MaxCrew = makeint(sti(refShip.MaxCrew) * 1.25 + 0.5); // перегруз
		/// как говаривал мой папа - нахрена попу гармонь?  Приходится приводить к каноническому виду, править все буковки по файлу мне лень
		refShip.cannonr  = refShip.rcannon;
		refShip.cannonl  = refShip.lcannon;
		refShip.cannonf  = refShip.fcannon;
		refShip.cannonb  = refShip.bcannon;
	}
}