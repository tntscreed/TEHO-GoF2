int InitStdItem( 	int		ItemIndex, 
					string 	id, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex,
					float	Rare, 
					int 	MinLevel, 
					int		Price, 
					int		PriceDublon, 			
					float 	Weight,
					string  TradeType)
{
	ref	rItem;
	int	itmIndex;
	
	itmIndex = ItemIndex;
	makeref(rItem, Items[itmIndex]);
	
	rItem.id				= id;		
	rItem.model				= ModelID;
	rItem.name				= "itmname_" + id;
	rItem.describe			= "itmdescr_" + id;		
	rItem.picTexture		= picTexture;
	rItem.picIndex			= picIndex;	
	rItem.price				= Price;	
	rItem.rare 				= Rare;
	rItem.minlevel 			= MinLevel;
	rItem.Weight 			= Weight;
	rItem.TradeType 		= TradeType;
	
	if(PriceDublon > 0) 
	{
		rItem.PriceDublon				= PriceDublon;	
	}
	
	itmIndex++;
	return itmIndex;
}


int InitStdBlade( 	int		ItemIndex, 
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
					int     Price)
{
	ref	blade;
	int	bladeIndex;
	float MaxAttack = 0.0;
	
	bladeIndex = ItemIndex;
	makeref(blade, Items[bladeIndex]);
	
	blade.id				= ModelID;		
	blade.groupID 			= BLADE_ITEM_TYPE;
	blade.model				= ModelID;
	blade.name				= "itmname_" + ModelID;
	blade.describe			= "itmdescr_" + ModelID;		
	blade.folder 			= "items";
	blade.picTexture		= picTexture;
	blade.picIndex			= picIndex;
	blade.param.time 		= 0.1;
	blade.param.colorstart 	= argb(64, 64, 64, 64);
	blade.param.colorend 	= argb(0, 32, 32, 32);
	blade.ItemType 			= "WEAPON";
	blade.lenght 			= Lenght;
	blade.curve				= Curve;
 	blade.FencingType       = BladeType;
	blade.quality			= Quality;
	blade.target			= TargetGroup;
	blade.TradeType 		= ITEM_TRADE_AMMUNITION;
		
	if(isGenerable)				blade.Generation.qty 	= GenerationQty;
	if(isGenerablePrice)    	
	{
		blade.Generation.price 	= true; // Флаг "генерить цену"	
	}
	else blade.price 	= Price;	
	
	switch (BladeType) 
	{
		case "FencingL" :
			blade.Weight 	= 2.0 + fRandSmall(1.0); 
			MaxAttack		= FencingL_MaxAttack;
		break;
		case "FencingS" :
			blade.Weight 	= 2.4 + fRandSmall(1.2);
			MaxAttack		= FencingS_MaxAttack;			
		break;
		case "FencingH" :
			blade.Weight 	= 3.0 + fRandSmall(1.5); 
			MaxAttack		= FencingH_MaxAttack;
		break;
	}
	
	blade.Balance = fRandSmall(2.0);
	if(ModelID == "unarmed") blade.Balance = 1.0;
	
	switch (Quality)
	{
		case B_POOR :
			blade.Attack 	= MaxAttack * (42.5 + fRandSmall(15.0))/100.0;			
			blade.rare 	 	= 0.1;
			blade.minlevel 	= 1;
			if(ModelID == "unarmed") blade.Attack = 15.0;
		break;
		case B_ORDINARY :
			blade.Attack 	= MaxAttack * (55.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.01;
			blade.minlevel 	= 1;
		break;
		case B_GOOD :
			blade.Attack 	= MaxAttack * (70.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.001;
			blade.minlevel 	= 10;
			if(TargetGroup == TGT_QUEST) // для квестового оружия атаку считаем по максимуму
			{
				blade.Attack 	= MaxAttack * 0.85;	
			}
		break;
		case B_EXCELLENT :
			blade.Attack 	= MaxAttack * (85.0 + fRandSmall(15.0))/100.0;
			blade.rare 	 	= 0.0001;
			blade.minlevel 	= 15;
			if(TargetGroup == TGT_QUEST) // для квестового оружия атаку считаем по максимуму
			{
				blade.Attack 	= MaxAttack;	
			}
		break;
	}
	
	switch (BladeType) 
	{
		case "FencingL" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(35.0 * (1.0/Curve + Lenght) * (stf(blade.Attack) * 2.0 - 30.0));
			}	
			else blade.price = Price;			
		break;
		case "FencingS" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(25.0 * (Curve + Lenght) * (stf(blade.Attack) * 2.0 - 40.0));
			}	
			else blade.price = Price;			
		break;
		case "FencingH" :
			if(isGenerablePrice) 
			{
				blade.price  = makeint(20.0 * ((Curve + 1.0) * 1.0/Lenght) * (stf(blade.Attack) * 2.0 - 50.0));
			}	
			else blade.price = Price;			
		break;
	}
	
	//trace("blade.id : " + blade.id + " blade.price : " + blade.price + " blade.Attack : " + blade.Attack + " blade.Balance : " + blade.Balance + " blade.Weight : " + blade.Weight);
	
	bladeIndex++;
	return bladeIndex;
}

int InitStdGun(	int		ItemIndex, 
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
				int 	Quality )
{
	ref	gun;
	int	gunIndex;
	
	gunIndex = ItemIndex;
	makeref(gun, Items[gunIndex]);
	
	gun.id				= id;		
	gun.groupID			= GUN_ITEM_TYPE;
	gun.name			= "itmname_" + id;
	gun.describe		= "itmdescr_" + id;		
	gun.model			= ModelID;
	gun.folder 			= "items";
	gun.chargeQ			= Charges;
	gun.picTexture		= picTexture;
	gun.picIndex		= picIndex;
	gun.dmg_min			= DmgMin;
	gun.dmg_max			= DmgMax;
	gun.price			= Price;	
	gun.ItemType 		= "WEAPON";
	gun.rare 			= Rare;
	gun.quality 		= Quality;
	gun.minlevel 		= MinLevel;
	gun.Weight 			= Weight;
	gun.ChargeSpeed 	= 10.0; // by default
	gun.accuracy 		= 50.0; // by default
	gun.TradeType 		= ITEM_TRADE_AMMUNITION;
	
	gunIndex++;
	return gunIndex;
}

int InitStdTalisman(	int		ItemIndex, 
						string 	id, 
						string 	ModelID, 
						string 	picTexture,
						int		picIndex, 
						int		Price, 
						float 	Weight,
						string	kind 	)
{
	ref	talisman;
	int	talismanIndex;
	
	talismanIndex = ItemIndex;
	makeref(talisman, Items[talismanIndex]);
	
	talisman.id				= id;		
	talisman.groupID		= TALISMAN_ITEM_TYPE;
	talisman.name			= "itmname_" + id;
	talisman.describe		= "itmdescr_" + id;		
	talisman.model			= ModelID;
	talisman.picTexture		= picTexture;
	talisman.picIndex		= picIndex;
	talisman.price			= Price + 10000;	
	talisman.rare 			= 0.0001;
	talisman.minlevel 		= 1;
	talisman.Weight 		= Weight;
	talisman.unique			= true;	
	talisman.ItemType 		= "ARTEFACT";
	talisman.kind			= kind;
	talisman.TradeType 		= ITEM_TRADE_JEWELRY;
	
	talismanIndex++;
	return talismanIndex;
}

int InitStdAmulet(	int		ItemIndex, 
					string 	id, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex, 
					int		Price, 
					float 	Weight,
					float	Rare, 
					int 	MinLevel, 
					int		Time,
					string  Type,
					bool	isMulti,
					int     outQty,
					string	kind,
					bool    reqAlchemy )
{
	ref	amulet;
	int	amuletIndex;
	
	amuletIndex = ItemIndex;
	makeref(amulet, Items[amuletIndex]);
	
	amulet.id				= id;		
	amulet.groupID			= ITEM_SLOT_TYPE;
	amulet.name				= "itmname_" + id;
	amulet.describe			= "itmdescr_" + id;		
	amulet.model			= ModelID;
	amulet.picTexture		= picTexture;
	amulet.picIndex			= picIndex;
	amulet.price			= Price;	
	amulet.rare 			= Rare;
	amulet.minlevel 		= MinLevel;
	amulet.Weight 			= Weight;
	amulet.time				= Time;
	amulet.ItemType 		= "ARTEFACT";
	amulet.Type				= Type;
	
	if(isMulti) 
	{
		amulet.multiobject		= true;
		amulet.multiobject.qty 	= outQty;
		if(reqAlchemy) 	amulet.multiobject.alchemy = true;
		else 			amulet.multiobject.alchemy = false;
	}	
	else
	{
		amulet.Monster.rare 	= Rare;
		amulet.Monster.min 		= 1;
		amulet.Monster.max 		= 1;
	}	
	if(kind != "") amulet.kind	= kind;	
	
	amulet.TradeType 		= ITEM_TRADE_ARTEFACT;
	
	amuletIndex++;
	return amuletIndex;
}					

int InitStdSuit(	int		ItemIndex, 
					string 	id, 
					string 	ModelID, 
					string 	picTexture,
					int		picIndex, 
					int		Price, 
					float 	Weight,
					float	Rare, 
					int 	MinLevel,
					bool    isClothes,
					float	CirassLevel_blade,
					float   CirassLevel_gun, 
					float   Critical)
{
	ref	suit;
	int	suitIndex;
	
	suitIndex = ItemIndex;
	makeref(suit, Items[suitIndex]);
	
	suit.id					= id;		
	suit.groupID			= CIRASS_ITEM_TYPE;
	suit.name				= "itmname_" + id;
	suit.describe			= "itmdescr_" + id;		
	suit.folder 			= "items";
	suit.model				= ModelID;
	suit.picTexture			= picTexture;
	suit.picIndex			= picIndex;
	suit.price				= Price;	
	suit.rare 				= Rare;
	suit.minlevel 			= MinLevel;
	suit.Weight 			= Weight;
	suit.Clothes 			= isClothes;
	suit.B_CirassLevel 		= CirassLevel_blade;
	suit.G_CirassLevel 		= CirassLevel_gun;
	
	if(Critical > 0.0)
	{
		suit.critical			= Critical;
	}	
	
	suit.ItemType 			= "SUPPORT";
	suit.TradeType 			= ITEM_TRADE_AMMUNITION;
	
	suitIndex++;
	return suitIndex;
}					

int InitStdMap(		int		ItemIndex, 
					string 	id, 
					string 	picTexture,
					int		picIndex, 				
					int		Price, 
					float 	Weight,
					float   Rare,
					string  ImageTga,
					string  ImageType,
					int	    toAtlas,
					string 	MapType)
{
	ref	map;
	int	mapIndex;
	
	mapIndex = ItemIndex;
	makeref(map, Items[mapIndex]);
	
	map.id					= id;		
	map.groupID				= MAPS_ITEM_TYPE;
	map.name				= "itmname_" + id;
	map.describe			= "itmdescr_" + id;		
	map.model				= "";
	map.picTexture			= picTexture;
	map.picIndex			= picIndex;
	map.price				= Price;
	map.Weight 				= Weight;	
	map.imageTga 			= ImageTga;
	map.imageType 			= ImageType;
	map.Atlas 				= toAtlas;
	map.MapType 			= MapType;
	map.ItemType 			= "MAP";
	map.TradeType 			= ITEM_TRADE_MAP;
	
	if(Rare > 0.0) 
	{
		map.Rare			= Rare;
	}	
	
	mapIndex++;
	return mapIndex;
}

int InitStdRecipies(int ItemIndex, string id, string result, int Price)
{
	ref	recipe;
	int	recipeIndex;
	
	recipeIndex = ItemIndex;
	makeref(recipe, Items[recipeIndex]);
	
	recipe.id			= id;	
	recipe.result 		= result;
	recipe.groupID		= SPECIAL_ITEM_TYPE;
	recipe.name			= "itmname_" + id;
	recipe.describe		= "itmdescr_" + id;		
	recipe.model		= "letter";
	recipe.picTexture	= "ITEMS_26";
	recipe.picIndex		= 16;
	recipe.price		= Price;	
	recipe.rare 		= 0.0001;
	recipe.minlevel 	= 1;
	recipe.Weight 		= 0.1;
	recipe.ItemType 	= "SUPPORT";
	//recipe.TradeType 	= ITEM_TRADE_POTION;
	
	recipeIndex++;
	return recipeIndex;
}

void InitGunExt(string id,			
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
				bool   isDefault )
{
	ref gun = ItemsFromID(id);
	gun.type.(sAttr).bullet 		= sBullet;
	gun.type.(sAttr).gunpowder 		= sGunPowder;
	gun.type.(sAttr).DmgMin_NC		= DmgMin_NC;
	gun.type.(sAttr).DmgMax_NC		= DmgMax_NC;
	gun.type.(sAttr).DmgMin_C		= DmgMin_C;
	gun.type.(sAttr).DmgMax_C		= DmgMax_NC;
	gun.type.(sAttr).EnergyP_NC		= EnergyP_NC;
	gun.type.(sAttr).EnergyP_C		= EnergyP_C;
	gun.type.(sAttr).Stun_NC		= Stun_NC;
	gun.type.(sAttr).Stun_C			= Stun_C;
	gun.type.(sAttr).multidmg       = MultiDamage;
	gun.type.(sAttr).misfire        = MisFire;
	gun.type.(sAttr).SelfDamage     = SelfDamage;
	gun.type.(sAttr).Explosion      = Explosion;
	gun.type.(sAttr).Accuracy       = Accuracy;
	gun.type.(sAttr).ChargeSpeed    = ChargeSpeed;
	gun.type.(sAttr).Default        = isDefault;
	
	if(Stun_NC || Stun_C) gun.stun = true;
}

void InitMushketExt(string id, 
					float  DmgMin_butt,  
					float  DmgMax_butt, 
					float  DmgMin_bayonet, 
					float  DmgMax_bayonet, 
					string sAttack_butt, 
					string sAttack_bayonet )
{
	ref gun = ItemsFromID(id);
	gun.DmgMin_butt 	= DmgMin_butt;
	gun.DmgMax_butt 	= DmgMax_butt;
	gun.DmgMin_bayonet 	= DmgMin_bayonet;
	gun.DmgMax_bayonet 	= DmgMax_bayonet;
	gun.sAttack_butt 	= sAttack_butt;
	gun.sAttack_bayonet = sAttack_bayonet;	
}	


void InitMultiObject(	string id,			
						string sAttr,       
						string component_id,
						string component_use,
						int    component_qty)
{
	ref rItem = ItemsFromID(id);
	rItem.component.(sAttr).id 	=  component_id;
	rItem.component.(sAttr).use =  component_use;
	rItem.component.(sAttr).qty =  component_qty;
}

void InitStdItemRarity(	string id,			
						string sAttr,
						float  Rare,
						int    minQ,
						int    maxQ)
{
	ref rItem = ItemsFromID(id);
	rItem.(sAttr).rare 	=  Rare;
	rItem.(sAttr).min   =  minQ;
	rItem.(sAttr).max 	=  maxQ;
}