int GofInitItems()
{
	InitButtons();
	InitRandItems();
	ref itm;
	int n;

	for(n=0; n<GOF_ITEMS_QUANTITY; n++)
	{
		makeref(itm,Items[n]);
		itm.id = "GOF_item"+(n+1);
		itm.describe = "";
		itm.index = n;
		itm.model = "";
		itm.shown = false;
		itm.startLocation = "";
		itm.startLocator = "";
		itm.useLocation = "";
		itm.useLocator = "";
		itm.Weight = 0.0; // boal
		itm.uniq  = false;
		itm.price = 1;
		itm.ItemType = "VARIETY";
	}
	n = 0;
	// � ������ ���� ��� ��� ���������� ������
	//==================PATENTS
	makeref(itm,Items[n]);
	itm.id = "GOF_patent_eng";
	itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "GOF_itmname_patent_england";
	itm.describe = "GOF_itmdescr_patent_england";
	itm.model = "";
	itm.quest = "eng_flag_rise";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Nation = ENGLAND; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_patent_fra";
	itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "GOF_itmname_patent_france";
	itm.describe = "GOF_itmdescr_patent_france";
	itm.model = "";
	itm.quest = "fra_flag_rise";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF4";
	//	itm.shown = 0;
	itm.price = 0;
	itm.Nation = FRANCE; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_patent_spa";
	itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "GOF_itmname_patent_spain";
	itm.describe = "GOF_itmdescr_patent_spain";
	itm.model = "";
	itm.quest = "spa_flag_rise";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF4";
	//	itm.shown = 0;
	itm.price = 0;
	itm.Nation = SPAIN; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_patent_hol";
	itm.groupID = PATENT_ITEM_TYPE;
	itm.name = "GOF_itmname_patent_holland";
	itm.describe = "GOF_itmdescr_patent_holland";
	itm.model = "";
	itm.quest = "hol_flag_rise";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF4";
	//	itm.shown = 0;
	itm.price = 0;
	itm.Nation = HOLLAND; //����� ������
	itm.TitulCur = 1; // ����� ������
	itm.TitulCurNext = 0; // ������� ������
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	/////////////////////////////////////////////////////////////////
	//									WEAPONS   ����� ������ � ������� ������� �� ���������� ����� � ������, � �� �� ��������!!!
	////////////////////////////////////////////////////////////////
	///////////////////////////  FencingLight   ////////////////////////////
	makeref(itm,Items[n]);
	itm.id = "GOF_unarmed"; // ����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_unarmed";
	itm.describe = "GOF_itmdescr_unarmed";
	itm.model = "GOF_unarmed";
	itm.folder = "items";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF1";
	itm.price = 1;
	itm.Weight = 0.0;
	itm.dmg_min = 1.0;
	itm.dmg_max = 15.0;
	itm.piercing = 1;
	itm.minlevel = 0;
	itm.rare = 0.0001;
	itm.block = 0;
	itm.param.time = 0.05;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	// boal 21.05.2004 -->
	makeref(itm,Items[n]);
	itm.id = "GOF_rabble"; // �������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_rabble";
	itm.describe = "GOF_itmdescr_rabble";
	itm.model = "GOF_kocherg";
	itm.folder = "items";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF10";
	itm.price = 3;
	itm.Weight = 4;
	itm.dmg_min = 1.0;
	itm.dmg_max = 25.0;
	itm.piercing = 5;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 19;
	itm.param.time = 0.05;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	// boal 21.05.2004 <--

	/*makeref(itm,Items[n]);
	itm.id = "GOF_Lead1"; // ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_lead1";
	itm.describe = "GOF_itmdescr_lead1";
	itm.model = "GOF_lead1";
	itm.folder = "items";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF1";
	itm.price = 25;
	itm.Weight = 0.5;
	itm.dmg_min = 2.0;
	itm.dmg_max = 30.0;
	itm.piercing = 7;
	itm.minlevel = 0;
	itm.rare = 0.0001;
	itm.block = 0;
	itm.param.time = 0.05;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;*/
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade5";  //������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade5";
	itm.describe = "GOF_itmdescr_blade5";
	itm.folder = "items";
	itm.model = "GOF_blade5";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 40;
	itm.Weight = 1;
	// boal 19.01.2004 <--
	itm.dmg_min = 3.0;
	itm.dmg_max = 35.0;
	itm.piercing = 50;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 5;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade2";  //������������ ������.   ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade2";
	itm.describe = "GOF_itmdescr_blade2";
	itm.folder = "items";
	itm.model = "GOF_blade2";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 60;
	itm.Weight = 3;
	// boal 19.01.2004 <--
	itm.dmg_min = 5.0;
	itm.dmg_max = 40.0;
	itm.piercing = 15;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	// Already in TEHO
	/*makeref(itm,Items[n]);
	itm.id = "GOF_blade6";  //��������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade6";
	itm.describe = "GOF_itmdescr_blade6";
	itm.folder = "items";
	itm.model = "GOF_blade6";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 100;
	itm.Weight = 2.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 8.0;
	itm.dmg_max = 46.0;
	itm.piercing = 15;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 15;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;*/
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade9"; //����������� ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade9";
	itm.describe = "GOF_itmdescr_blade9";
	itm.folder = "items";
	itm.model = "GOF_blade9";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 300;
	itm.Weight = 2.8;
	// boal 19.01.2004 <--
	itm.dmg_min = 10.0;
	itm.dmg_max = 45.0;
	itm.piercing = 20;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 15;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade14";  //����������� ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade14";
	itm.describe = "GOF_itmdescr_blade14";
	itm.folder = "items";
	itm.model = "GOF_blade14";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 200;
	itm.Weight = 3.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 11.0;
	itm.dmg_max = 48.0;
	itm.piercing = 20;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 60;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade19";   //���������� ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade19";
	itm.describe = "GOF_itmdescr_blade19";
	itm.folder = "items";
	itm.model = "GOF_blade19";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 350;
	itm.Weight = 2.6;
	// boal 19.01.2004 <--
	itm.dmg_min = 12.0;
	itm.dmg_max = 50.0;
	itm.piercing = 20;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 60;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade22"; //���������� ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade22";
	itm.describe = "GOF_itmdescr_blade22";
	itm.folder = "items";
	itm.model = "GOF_blade22";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 450;
	itm.Weight = 2.7;
	// boal 19.01.2004 <--
	itm.dmg_min = 13.0;
	itm.dmg_max = 53.0;

	//itm.Attack = itm.dmg_max; // TEMP VEX
	//itm.Balance = 1.5; // TEMP VEX

	itm.piercing = 44;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 73;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade23"; //��������� ������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade23";
	itm.describe = "GOF_itmdescr_blade23";
	itm.folder = "items";
	itm.model = "GOF_blade23";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 650;
	itm.Weight = 2.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 14.0;
	itm.dmg_max = 55.0;
	itm.piercing = 50;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 75;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	
	/*makeref(itm,Items[n]);
	itm.id = "GOF_arm1"; //������ �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_arm1";
	itm.describe = "GOF_itmdescr_arm1";
	itm.folder = "items";
	itm.model = "GOF_arm1";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 1650;
	itm.Weight = 3.7;
	// boal 19.01.2004 <--
	itm.dmg_min = 20.0;
	itm.dmg_max = 60.0;
	itm.piercing = 65.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 70.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;*/
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade27"; //������ ����� �������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade27";
	itm.describe = "GOF_itmdescr_blade27";
	itm.folder = "items";
	itm.model = "GOF_blade27";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF8";
	// boal 19.01.2004 -->
	itm.price = 5000;
	itm.Weight = 2.9;
	// boal 19.01.2004 <--
	itm.dmg_min = 18.0;
	itm.dmg_max = 65.0;
	itm.piercing = 99.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 99.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_cortblade";  //Sword of Cort�s <-----Officerpuppy 12/16/09
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_cortblade";
	itm.describe = "GOF_itmdescr_cortblade";
	itm.folder = "items";
	itm.model = "GOF_blade27";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF8";
	// boal 15.12.2009 -->
	itm.price = 12500;
	itm.Weight = 3.5;
	itm.shown = 1; 
	// boal 15.12.2009 <--
	itm.dmg_min = 30.0;
	itm.dmg_max = 60.0;
	itm.piercing = 90.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 80.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingLight";
	itm.ItemType = "WEAPON";
	n++;
	///////////////////////////  Fencing   ////////////////////////////
	makeref(itm,Items[n]);
	itm.id = "GOF_blade1"; //������ �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade1";
	itm.describe = "GOF_itmdescr_blade1";
	itm.model = "GOF_blade1";
	itm.folder = "items";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 25;
	itm.Weight = 4.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 6.0;
	itm.dmg_max = 45.0;
	itm.piercing = 10;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 5;
	itm.param.time = 0.05;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade4";  //���������� �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade4";
	itm.describe = "GOF_itmdescr_blade4";
	itm.folder = "items";
	itm.model = "GOF_blade4";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 50;
	itm.Weight = 4.6;
	// boal 19.01.2004 <--
	itm.dmg_min = 8.0;
	itm.dmg_max = 50.0;
	itm.piercing = 30;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 1;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_topor3";  //�������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_topor3";
	itm.describe = "GOF_itmdescr_topor3";
	itm.folder = "items";
	itm.model = "GOF_topor3";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 75;
	itm.Weight = 6;
	// boal 19.01.2004 <--
	itm.dmg_min = 10.0;
	itm.dmg_max = 60.0;
	itm.piercing = 14.0;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.block = 2.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade3"; //������   �������� ����� � ������� �������, ��������� ��������� ����� ��������.
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade3";
	itm.describe = "GOF_itmdescr_blade3";
	itm.folder = "items";
	itm.model = "GOF_blade3";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 100;
	itm.Weight = 5.3;
	// boal 19.01.2004 <--
	itm.dmg_min = 12.0;
	itm.dmg_max = 55.0;
	itm.piercing = 60;
	itm.minlevel = 0;
	itm.rare = 0.1;
	itm.block = 5;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade7"; //������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade7";
	itm.describe = "GOF_itmdescr_blade7";
	itm.folder = "items";
	itm.model = "GOF_blade7";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 125;
	itm.Weight = 4.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 13.0;
	itm.dmg_max = 55.0;
	itm.piercing = 18;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 5;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade12"; //���������� �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade12";
	itm.describe = "GOF_itmdescr_blade12";
	itm.folder = "items";
	itm.model = "GOF_blade12";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 150;
	itm.Weight = 6;
	// boal 19.01.2004 <--
	itm.dmg_min = 14.0;
	itm.dmg_max = 65.0;
	itm.piercing = 30;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade18"; //���������� ����� � ������ ��������� �������, ���������������� �� ������� �� �����.
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade18";
	itm.describe = "GOF_itmdescr_blade18";
	itm.folder = "items";
	itm.model = "GOF_blade18";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 200;
	itm.Weight = 5.4;
	// boal 19.01.2004 <--
	itm.dmg_min = 16.0;
	itm.dmg_max = 60.0;
	itm.piercing = 35;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 35;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade30";//����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade30";
	itm.describe = "GOF_itmdescr_blade30";
	itm.folder = "items";
	itm.model = "GOF_blade30";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 300;
	itm.Weight = 4.1;
	// boal 19.01.2004 <--
	itm.dmg_min = 18.0;
	itm.dmg_max = 63.0;
	itm.piercing = 55.0;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 40.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade31"; //��������� �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade31";
	itm.describe = "GOF_itmdescr_blade31";
	itm.folder = "items";
	itm.model = "GOF_blade31";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 400;
	itm.Weight = 4.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 19.0;
	itm.dmg_max = 64.0;
	itm.piercing = 50.0;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 65.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade24"; //������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade24";
	itm.describe = "GOF_itmdescr_blade24";
	itm.folder = "items";
	itm.model = "GOF_blade24";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF8";
	// boal 19.01.2004 -->
	itm.price = 750;
	itm.Weight = 4.3;
	// boal 19.01.2004 <--
	itm.dmg_min = 20.0;
	itm.dmg_max = 66.0;
	itm.piercing = 58.0;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 45.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade25";  //�������� �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade25";
	itm.describe = "GOF_itmdescr_blade25";
	itm.folder = "items";
	itm.model = "GOF_blade25";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF8";
	// boal 19.01.2004 -->
	itm.price = 850;
	itm.Weight = 4.2;
	// boal 19.01.2004 <--
	itm.dmg_min = 21.0;
	itm.dmg_max = 65.0;
	itm.piercing = 60.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 70.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade34"; //�����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade34";
	itm.describe = "GOF_itmdescr_blade34";
	itm.folder = "items";
	itm.model = "GOF_blade34";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 5.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 23.0;
	itm.dmg_max = 70.0;
	itm.piercing = 90.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 70.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade26";  //������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade26";
	itm.describe = "GOF_itmdescr_blade26";
	itm.folder = "items";
	itm.model = "GOF_blade26";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF8";
	// boal 19.01.2004 -->
	itm.price = 1250;
	itm.Weight = 4.7;
	// boal 19.01.2004 <--
	itm.dmg_min = 24.0;
	itm.dmg_max = 70.0;
	itm.piercing = 88.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 72.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;
	
	// Already in TEHO
	/*makeref(itm,Items[n]);
	itm.id = "GOF_blade32"; //������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade32";
	itm.describe = "GOF_itmdescr_blade32";
	itm.folder = "items";
	itm.model = "GOF_blade32";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 1500;
	itm.Weight = 4.4;
	// boal 19.01.2004 <--
	itm.dmg_min = 35.0;
	itm.dmg_max = 80.0;
	itm.piercing = 10.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 92.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "Fencing";
	itm.ItemType = "WEAPON";
	n++;*/
	
	///////////////////////////  FencingHeavy   ////////////////////////////
	makeref(itm,Items[n]);
	itm.id = "GOF_blade10"; //���������� �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade10";
	itm.describe = "GOF_itmdescr_blade10";
	itm.folder = "items";
	itm.model = "GOF_blade10";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 150;
	itm.Weight = 7;
	// boal 19.01.2004 <--
	itm.dmg_min = 10.0;
	itm.dmg_max = 60.0;
	itm.piercing = 50;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade35";  //�����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade35";
	itm.describe = "GOF_itmdescr_blade35";
	itm.folder = "items";
	itm.model = "GOF_blade35";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 200;
	itm.Weight = 9;
	// boal 19.01.2004 <--
	itm.dmg_min = 12.0;
	itm.dmg_max = 65.0;
	itm.piercing = 65.0;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 25.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade8";  //����������� ���
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade8";
	itm.describe = "GOF_itmdescr_blade8";
	itm.folder = "items";
	itm.model = "GOF_blade8";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 225;
	itm.Weight = 7.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 14.0;
	itm.dmg_max = 65.0;
	itm.piercing = 35;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade11"; //����������� �����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade11";
	itm.describe = "GOF_itmdescr_blade11";
	itm.folder = "items";
	itm.model = "GOF_blade11";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 250;
	itm.Weight = 8;
	// boal 19.01.2004 <--
	itm.dmg_min = 16.0;
	itm.dmg_max = 70.0;
	itm.piercing = 60;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 25;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade13"; //�����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade13";
	itm.describe = "GOF_itmdescr_blade13";
	itm.folder = "items";
	itm.model = "GOF_blade13";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 300;
	itm.Weight = 6.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 18.0;
	itm.dmg_max = 70.0;
	itm.piercing = 65;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 20;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_topor1";  //�����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_topor1";
	itm.describe = "GOF_itmdescr_topor1";
	itm.folder = "items";
	itm.model = "GOF_topor1";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 325;
	itm.Weight = 10;
	// boal 19.01.2004 <--
	itm.dmg_min = 20.0;
	itm.dmg_max = 80.0;
	itm.piercing = 70.0;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 3.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade15";  //����������� ���
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade15";
	itm.describe = "GOF_itmdescr_blade15";
	itm.folder = "items";
	itm.model = "GOF_blade15";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 350;
	itm.Weight = 8.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 22.0;
	itm.dmg_max = 75.0;
	itm.piercing = 55;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 25;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade16"; //��������� ���
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade16";
	itm.describe = "GOF_itmdescr_blade16";
	itm.folder = "items";
	itm.model = "GOF_blade16";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 400;
	itm.Weight = 9.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 22.0;
	itm.dmg_max = 80.0;
	itm.piercing = 45;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 35;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_blade17"; //��������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade17";
	itm.describe = "GOF_itmdescr_blade17";
	itm.folder = "items";
	itm.model = "GOF_blade17";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 450;
	itm.Weight = 11.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 24.0;
	itm.dmg_max = 90.0;
	itm.piercing = 65;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.block = 10;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade20"; //�����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade20";
	itm.describe = "GOF_itmdescr_blade20";
	itm.folder = "items";
	itm.model = "GOF_blade20";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 500;
	itm.Weight = 8.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 25.0;
	itm.dmg_max = 93.0;
	itm.piercing = 65;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 30;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade21"; //��������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade21";
	itm.describe = "GOF_itmdescr_blade21";
	itm.folder = "items";
	itm.model = "GOF_blade21";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF3";
	// boal 19.01.2004 -->
	itm.price = 550;
	itm.Weight = 10.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 26.0;
	itm.dmg_max = 100.0;
	itm.piercing = 75;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 25;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade33"; //����������� ���
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade33";
	itm.describe = "GOF_itmdescr_blade33";
	itm.folder = "items";
	itm.model = "GOF_blade33";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 650;
	itm.Weight = 9;
	// boal 19.01.2004 <--
	itm.dmg_min = 27.0;
	itm.dmg_max = 95.0;
	itm.piercing = 70.0;
	itm.minlevel = 1;
	itm.rare = 0.001;
	itm.block = 60.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_blade28";  //�����
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_blade28";
	itm.describe = "GOF_itmdescr_blade28";
	itm.folder = "items";
	itm.model = "GOF_blade28";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 1500;
	itm.Weight = 9.3;
	// boal 19.01.2004 <--
	itm.dmg_min = 28.0;
	itm.dmg_max = 100.0;
	itm.piercing = 85.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 75.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_topor2";  //������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_topor2";
	itm.describe = "GOF_itmdescr_topor2";
	itm.folder = "items";
	itm.model = "GOF_topor2";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 1650;
	itm.Weight = 12.5;
	// boal 19.01.2004 <--
	itm.dmg_min = 35.0;
	itm.dmg_max = 120.0;
	itm.piercing = 95.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 20.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_tritblade";  //Sword of Triton  <-----Officerpuppy 05/09/11
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_tritblade";
	itm.describe = "GOF_itmdescr_tritblade";
	itm.folder = "items";
	itm.model = "GOF_blade30";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF10";
	// boal 15.12.2009 -->
	itm.price = 12500;
	itm.Weight = 7.5;
	itm.shown = 1; 
	// boal 15.12.2009 <--
	itm.dmg_min = 30.0;
	itm.dmg_max = 110.0;
	itm.piercing = 75.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 80.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
   	 itm.FencingType = "FencingHeavy";
    	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_piranblade";  //St. Piran's Blade  <-----Officerpuppy 06/15/11
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_piranblade";
	itm.describe = "GOF_itmdescr_piranblade";
	itm.folder = "items";
	itm.model = "GOF_blade16";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF3";
	// boal 15.12.2009 -->
	itm.price = 12500;
	itm.Weight = 7.5;
	itm.shown = 1; 
	// boal 15.12.2009 <--
	itm.dmg_min = 40.0;
	itm.dmg_max = 100.0;
	itm.piercing = 55.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 80.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
   	 itm.FencingType = "FencingHeavy";
    	itm.ItemType = "WEAPON";
	n++;
	//GUNS

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol1";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol1";
	itm.describe = "GOF_itmdescr_pistol1";
	itm.folder = "items";
	itm.model = "GOF_pistol1";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 50;
	itm.Weight = 3;
	// boal 19.01.2004 <--
	itm.chargeQ = 1;
	itm.chargespeed = 8;
	itm.dmg_min = 20.0;
	itm.dmg_max = 100.0;
	itm.accuracy = 30;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol2";
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol2";
	itm.describe = "GOF_itmdescr_pistol2";
	itm.folder = "items";
	itm.model = "GOF_pistol2";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 200;
	itm.Weight = 4;
	// boal 19.01.2004 <--
	itm.chargeQ = 1;
	itm.chargespeed = 12;
	itm.dmg_min = 30.0;
	itm.dmg_max = 120.0;
	itm.accuracy = 50;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol3"; //�������
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol3";
	itm.describe = "GOF_itmdescr_pistol3";
	itm.folder = "items";
	itm.model = "GOF_pistol3";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 400;
	itm.Weight = 6;
	// boal 19.01.2004 <--
	itm.chargeQ = 1;
	itm.chargespeed = 22;
	itm.dmg_min = 50.0;
	itm.dmg_max = 175.0;
	itm.accuracy = 20;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol6";  // 2�
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol6";
	itm.describe = "GOF_itmdescr_pistol6";
	itm.folder = "items";
	itm.model = "GOF_pistol6";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 650;
	itm.Weight = 5;
	// boal 19.01.2004 <--
	itm.chargeQ = 2;
	itm.chargespeed = 20;
	itm.dmg_min = 35.0;
	itm.dmg_max = 110.0;
	itm.accuracy = 60;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol5"; //���������� ��������
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol5";
	itm.describe = "GOF_itmdescr_pistol5";
	itm.folder = "items";
	itm.model = "GOF_pistol5";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF6";
	itm.price = 1900;
	// boal 19.01.2004 -->
	itm.Weight = 3;
	// boal 19.01.2004 <--
	itm.chargeQ = 1;
	itm.chargespeed = 16;
	itm.dmg_min = 40.0;
	itm.dmg_max = 170.0;
	itm.accuracy = 80;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol4"; // 4�
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol4";
	itm.describe = "GOF_itmdescr_pistol4";
	itm.folder = "items";
	itm.model = "GOF_pistol4";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF6";
	itm.shown = 4;
	itm.price = 2500;
	// boal 19.01.2004 -->
	itm.Weight = 6;
	// boal 19.01.2004 <--
	itm.chargeQ = 4;
	itm.chargespeed = 28;
	itm.dmg_min = 30.0;
	itm.dmg_max = 120.0;
	itm.accuracy = 50;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mushket"; //��������
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_mushket";
	itm.describe = "GOF_itmdescr_mushket";
	itm.folder = "items";
	itm.model = "GOF_mushket";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF10";
	// boal 19.01.2004 -->
	itm.price = 5000;
	itm.Weight = 13;
	// boal 19.01.2004 <--
	itm.chargeQ = 1;
	itm.chargespeed = 10;
	itm.dmg_min = 85.0;
	itm.dmg_max = 270.0;
	itm.accuracy = 70;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

  	makeref(itm,Items[n]);
	itm.id = "GOF_mushket1"; //�������� <-----Officerpuppy 02/04/10
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_mushket1";
	itm.describe = "GOF_itmdescr_mushket1";
	itm.folder = "items";
	itm.model = "GOF_mushket1";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF14";
	// boal 19.01.2004 -->
	itm.price = 5500;
	itm.Weight = 13;
	// boal 19.01.2004 <--
	itm.chargeQ = 1;
	itm.chargespeed = 10;
	itm.dmg_min = 80.0;
	itm.dmg_max = 280.0;
	itm.accuracy = 80;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	// <<<< ---------------  QUEST ITEMS  --------------------

	makeref(itm,Items[n]);
	itm.id = "GOF_gold";
	itm.name = "GOF_itmname_gold";
	itm.describe = "GOF_itmdescr_gold";
	itm.model = "GOF_";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Chest";
	itm.name = "GOF_itmname_chest";
	itm.describe = "GOF_itmdescr_chest";
	itm.model = "GOF_stat1";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 12500; // ����� ���������� � �����
	itm.Weight = 15; // boal
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Coins";
	itm.name = "GOF_itmname_coins";
	itm.describe = "GOF_itmdescr_coins";
	itm.model = "GOF_purse";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF4";
	//	itm.shown = 0;
	// boal 19.01.2004 -->
	itm.price = 500;
	itm.Weight = 0.1;
	//itm.Monster.rare = 0.05;
	//itm.Monster.min = 1;
	//itm.Monster.max = 10;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_icollection";
	itm.name = "GOF_itmname_incas_collection";
	itm.describe = "GOF_itmdescr_incas_collection";
	itm.model = "GOF_";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF4";
	//	itm.shown = 0;
	itm.price = 22500;
	// boal 19.01.2004 -->
	itm.Weight = 50;
	// boal 19.01.2004 <--
	n++;

	// boal ��� ���������� -->
	makeref(itm,Items[n]);
	itm.id = "GOF_letter_1";
	itm.name = "GOF_itmname_letter_1";
	itm.describe = "GOF_itmdescr_letter_1";
	itm.model = "GOF_";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_letter_2";
	itm.name = "GOF_itmname_letter_2";
	itm.describe = "GOF_itmdescr_letter_2";
	itm.model = "GOF_";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_letter_open";
	itm.name = "GOF_itmname_letter_open";
	itm.describe = "GOF_itmdescr_letter_open";
	itm.model = "GOF_";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	// boal ��� ���������� <--

	makeref(itm,Items[n]); //�������
	itm.id = "GOF_letter_notes";
	itm.name = "GOF_itmname_letter_notes";
	itm.describe = "GOF_itmdescr_letter_notes";
	itm.model = "GOF_";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); //�������
	itm.id = "GOF_Order";
	itm.name = "GOF_itmname_order";
	itm.describe = "GOF_itmdescr_order";
	itm.model = "GOF_";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF8";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_letter_Albermal";
	itm.name = "GOF_itmname_letter_Albermal";
	itm.describe = "GOF_itmdescr_letter_Albermal";
	itm.model = "GOF_";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF12";
	itm.price = 0;
	itm.Weight = 0.1;
	n++; 

	// eddy �������� ������� <--
	makeref(itm,Items[n]);
	itm.id = "GOF_EngTradeLicence";
	itm.name = "GOF_itmname_EngTradeLicence";
	itm.describe = "GOF_itmdescr_EngTradeLicence";
	itm.model = "GOF_";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_FraTradeLicence";
	itm.name = "GOF_itmname_FraTradeLicence";
	itm.describe = "GOF_itmdescr_FraTradeLicence";
	itm.model = "GOF_";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_SpaTradeLicence";
	itm.name = "GOF_itmname_SpaTradeLicence";
	itm.describe = "GOF_itmdescr_SpaTradeLicence";
	itm.model = "GOF_";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_HolTradeLicence";
	itm.name = "GOF_itmname_HolTradeLicence";
	itm.describe = "GOF_itmdescr_HolTradeLicence";
	itm.model = "GOF_";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]); //����� ����������� ������� ��� �������.
	itm.id = "GOF_Trust";
	itm.name = "GOF_itmname_Trust";
	itm.describe = "GOF_itmdescr_Trust";
	itm.model = "GOF_";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF9";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	// eddy �������� ������� <--

	makeref(itm,Items[n]); //��������� ������ �� ������ ����
	itm.id = "GOF_sicretLetter";
	itm.name = "GOF_itmname_sicretLetter";
	itm.describe = "GOF_itmdescr_sicretLetter";
	itm.model = "GOF_";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF12";
	//	itm.shown = 0;
	itm.price = 0;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_LegransMap";
	itm.name = "GOF_itmname_LegransMap";
	itm.describe = "GOF_itmdescr_LegransMap";
	itm.model = "GOF_";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF10";
	itm.price = 0;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;  

	makeref(itm,Items[n]);
	itm.id = "GOF_Bible";
	itm.name = "GOF_itmname_bible";
	itm.describe = "GOF_itmdescr_bible";
	itm.model = "GOF_";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = 0;
	itm.price = 0;
	// boal 19.01.2004 -->
	itm.Weight = 2;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_ShipsJournal";
	itm.name = "GOF_itmname_ShipsJournal";
	itm.describe = "GOF_itmdescr_ShipsJournal";
	itm.model = "GOF_"; 
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF4";
	//	itm.shown = 0;
	itm.price = 0;
	// boal 19.01.2004 -->
	itm.Weight = 2;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;
	
	// ==> �������� �� ������ ��������
	makeref(itm,Items[n]);
	itm.id = "GOF_Powder_mummie";
	itm.name = "GOF_itmname_Powder_mummie";
	itm.describe = "GOF_itmdescr_Powder_mummie";
	itm.model = "GOF_pursel";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF12";
	//itm.shown = 0;
	// boal 19.01.2004 -->
	itm.Weight = 0.5;
	itm.price = 0;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;
	
	makeref(itm,Items[n]); // ����� ������� �� �����
	itm.id = "GOF_DeSouzaCross";
	itm.name = "GOF_itmname_DeSouzaCross";
	itm.describe = "GOF_itmdescr_DeSouzaCross";
	itm.model = "GOF_sapphire";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF12";
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	itm.price = 0;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_DOjeronRing";
	itm.name = "GOF_itmname_DOjeronRing";
	itm.describe = "GOF_itmdescr_DOjeronRing";
	itm.model = "GOF_RingJew";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF9";
	itm.Weight = 0.3;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_BlackLabel";
	itm.name = "GOF_itmname_BlackLabel";
	itm.describe = "GOF_itmdescr_BlackLabel";
	itm.model = "GOF_";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF8";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Term_arm";
	itm.name = "GOF_itmname_Term_arm";
	itm.describe = "GOF_itmdescr_Term_arm";
	itm.model = "GOF_pursel";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF12";
	itm.price = 0;
	itm.Weight = 5.5;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Malyava";
	itm.name = "GOF_itmname_Malyava";
	itm.describe = "GOF_itmdescr_Malyava";
	itm.model = "GOF_";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF12";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_PortmansBook";
	itm.name = "GOF_itmname_PortmansBook";
	itm.describe = "GOF_itmdescr_PortmansBook";
	itm.model = "GOF_";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF1";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mushket2x2"; //��������� ��������, ������������
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_questMushket";
	itm.describe = "GOF_itmdescr_questMushket";
	itm.folder = "items";
	itm.model = "GOF_mushket2x2";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF13";
	// boal 19.01.2004 -->
	itm.price = 50000;
	itm.Weight = 17;
	// boal 19.01.2004 <--
	itm.chargeQ = 2;
	itm.chargespeed = 12;
	itm.dmg_min = 90.0;
	itm.dmg_max = 290.0;
	itm.accuracy = 80;
	itm.minlevel = 20;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_toporAZ"; //����������
	itm.groupID = BLADE_ITEM_TYPE;
	itm.name = "GOF_itmname_toporAZ";
	itm.describe = "GOF_itmdescr_toporAZ";
	itm.folder = "items";
	itm.model = "GOF_maquahuitl";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF13";
	// boal 19.01.2004 -->
	itm.price = 7750;
	itm.Weight = 15.0;
	// boal 19.01.2004 <--
	itm.dmg_min = 45.0;
	itm.dmg_max = 140.0;
	itm.piercing = 95.0;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.block = 30.0;
	itm.param.time = 0.1;
	itm.param.colorstart = argb(64, 64, 64, 64);
	itm.param.colorend = argb(0, 32, 32, 32);
	itm.FencingType = "FencingHeavy";
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_map_LSC";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_LSC";
	itm.describe = "GOF_itmdescr_map_LSC";
	itm.model = "GOF_";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 100000;
	itm.Weight = 0.2;
	itm.imageTga = "LostShipsCity";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;

	//homo
	makeref(itm,Items[n]);
	itm.id = "GOF_Griffins_Weapon"; // ������ ��������
	itm.name = "GOF_itmname_Griffins_Weapon";
	itm.describe = "GOF_itmdescr_Griffins_Weapon";
	itm.model = "GOF_";
	itm.picIndex =14;
	itm.picTexture = "ITEMS_GOF13";
	itm.shown = 0;
	itm.Weight = 3.4;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	//homo
	makeref(itm,Items[n]);
	itm.id = "GOF_Weapon_for_escape"; //������ ��� ������ �����
	itm.name = "GOF_itmname_Weapon_for_escape";
	itm.describe = "GOF_itmdescr_Weapon_for_escape";
	itm.model = "GOF_";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF13";
	itm.shown = 0;
	itm.Weight = 10;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	////////////////////////////////////////////////////////////////////////////////////////////		
	//����� ���������� ��������� ��������, �������� � ��������� item
	//��������� ��� �������� ������ �����, �� ����� ������� ��������� ���������
	////////////////////////////////////////////////////////////////////////////////////////////

	ItemsForLocators_start = n; //��������� ����� ��� ����. ���������

	makeref(itm,Items[n]);
	itm.id = "GOF_Rock_letter";
	itm.name = "GOF_itmname_Rock_letter";
	itm.describe = "GOF_itmdescr_Rock_letter";
	itm.model = "GOF_StoneMap";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF4";
	itm.shown = 0; //������� �������� ��������, �.�. ����� �� ������ �� ����.������ ��������.
	string PutLocation, PutLocator;   //������ ���������.
	int WherePut = rand(4);
	switch(WherePut)
	{
		case 0:
			PutLocation = "Pearl_Grot";
			PutLocator  = "item"+(rand(2)+1);
		break;
		case 1:
			PutLocation = "Caiman_Grot";
			PutLocator  = "item"+(rand(2)+1);
		break;
		case 2:
			PutLocation = "Terks_Grot";
			PutLocator  = "item"+(rand(2)+1);
		break;
		case 3:
			PutLocation = "Dominica_Grot";
			PutLocator  = "item"+(rand(2)+1);
		break;
		case 4:
			PutLocation = "Temple";
			PutLocator  = "item1";
		break;
	}
	itm.startLocation = PutLocation;
	itm.startLocator = PutLocator;
	itm.useLocation = "Guadeloupe_Cave";
	itm.useLocator = "button01";
	itm.price = 0;
	// boal 19.01.2004 -->
	itm.Weight = 0.2;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;  
	
	makeref(itm,Items[n]);
	itm.id = "GOF_Azzy_bottle";
	itm.name = "GOF_itmname_Azzy_bottle";
	itm.describe = "GOF_itmdescr_Azzy_bottle";
	itm.model = "GOF_pursel";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF12";
	itm.shown = 1; //�� ���� ������� �� ��������� �� �������
	itm.useLocator = "button01";
	// boal 19.01.2004 -->
	itm.Weight = 2.5;
	itm.price = 0;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_ShipyardsMap";
	itm.name = "GOF_itmname_ShipyardsMap";
	itm.describe = "GOF_itmdescr_ShipyardsMap";
	itm.model = "GOF_shipyardsMap";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF12";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_MayorsRing";
	itm.name = "GOF_itmname_MayorsRing";
	itm.describe = "GOF_itmdescr_MayorsRing";
	itm.model = "GOF_RingSimGold";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF2";
	itm.Weight = 0.3;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_UsurersJew";
	itm.name = "GOF_itmname_UsurersJew";
	itm.describe = "GOF_itmdescr_UsurersJew";
	itm.model = "GOF_Diamond";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF2";
	itm.Weight = 0.1;
	itm.price = 0;
	itm.JevelType = xiDStr("diamond");
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_OpenBook";
	itm.name = "GOF_itmname_OpenBook";
	itm.describe = "GOF_itmdescr_OpenBook";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF4";
	itm.Weight = 0.2;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	itm.shown = false;
	itm.startLocation = "PuertoPrincipe_townhall";
	itm.startLocator = "item1";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Ladder";
	itm.name = "GOF_itmname_Ladder";
	itm.describe = "GOF_itmdescr_Ladder";
	itm.model = "GOF_Ladder";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF12";
	itm.Weight = 0.2;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_key1";
	itm.name = "GOF_itmname_Key1";
	itm.describe = "GOF_itmdescr_Key1";
	itm.model = "GOF_keysimple";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF12";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_key2";
	itm.name = "GOF_itmname_Key2";
	itm.describe = "GOF_itmdescr_Key2";
	itm.model = "GOF_keymiddle";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF12";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_key3";
	itm.name = "GOF_itmname_Key3";
	itm.describe = "GOF_itmdescr_Key3";
	itm.model = "GOF_keygrand";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF12";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);  //���� �� ������� �� ������ ������
	itm.id = "GOF_keyPanama";
	itm.name = "GOF_itmname_keyPanama";
	itm.describe = "GOF_itmdescr_keyPanama";
	itm.model = "GOF_keygrand";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF12";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);  //���� ��� ������� ���
	itm.id = "GOF_keyQuestLSC";
	itm.name = "GOF_itmname_keyQuestLSC";
	itm.describe = "GOF_itmdescr_keyQuestLSC";
	itm.model = "GOF_keymiddle";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF12";
	itm.shown = 0; //������� ���� �������
	itm.startLocation = "Villemstad_houseSp5";
	itm.startLocator = "item2";
	itm.Weight = 0.0;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);	//������ ��� ������� ���
	itm.id = "GOF_letter_LSC";
	itm.name = "GOF_itmname_letter_LSC";
	itm.describe = "GOF_itmdescr_letter_LSC";
	itm.model = "GOF_letter";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF4";
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;
	
	//homo ��������� �� ������� �����
	makeref(itm,Items[n]);
	itm.id = "GOF_migraine_potion"; // ��������� �� �������
	itm.name = "GOF_itmname_migraine_potion";
	itm.describe = "GOF_itmdescr_migraine_potion";
	itm.model = "GOF_balsam";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF1";
	itm.shown = 0;
	itm.Weight = 0.4;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;
	//homo
	makeref(itm,Items[n]);
	itm.id = "GOF_MsStid_ring"; // �������
	itm.name = "GOF_itmname_MsStid_ring";
	itm.describe = "GOF_itmdescr_MsStid_ring";
	itm.model = "GOF_RingJew";//pursel
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF7";
	itm.shown = 0;
	itm.Weight = 0.4;
	itm.price = 0;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);	//����������
	itm.id = "GOF_Pinion";
	itm.name = "GOF_itmname_pinion";
	itm.describe = "GOF_itmdescr_pinion";
	itm.model = "GOF_Pinion";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF12";
	itm.shown = 1; 
	itm.startLocation = "UnderWater";
	itm.startLocator = "item" + (rand(4)+1);
	itm.price = 0;
	itm.Weight = 0.1;
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_pistol7";  //������
	itm.groupID = GUN_ITEM_TYPE;
	itm.name = "GOF_itmname_pistol7";
	itm.describe = "GOF_itmdescr_pistol7";
	itm.folder = "items";
	itm.model = "GOF_pistol7";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF8";
	itm.shown = 1;
	itm.price = 12500;
	//����� � ����
	itm.shown = 1; 
	itm.startLocation = "Temple_round";
	itm.startLocator = "item1";
	// boal 19.01.2004 -->
	itm.Weight = 9;
	// boal 19.01.2004 <--
	itm.chargeQ = 4;
	itm.chargespeed = 52;
	itm.dmg_min = 100.0;
	itm.dmg_max = 300.0;
	itm.accuracy = 80;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "WEAPON";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Ascold_rabble"; // ����������
	itm.name = "GOF_itmname_Ascold_rabble";
	itm.describe = "GOF_itmdescr_Ascold_rabble";
	itm.model = "GOF_kocherg";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF12";
	itm.shown = 0;
	itm.useLocation = "Guadeloupe_Cave";
	itm.useLocator = "button02";
	// boal 19.01.2004 -->
	itm.Weight = 1;
	itm.price = 0;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	//��� �������� ������� ��������� ����� 
	//Totems_start = n;

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_1";
	itm.name = "GOF_itmname_Totem_1";
	itm.describe = "GOF_itmdescr_Totem_1";
	itm.model = "GOF_Totem_1";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Shore_ship1";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_1";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;  

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_2";
	itm.name = "GOF_itmname_Totem_2";
	itm.describe = "GOF_itmdescr_Totem_2";
	itm.model = "GOF_Totem_2";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Shore55";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_2";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_3";
	itm.name = "GOF_itmname_Totem_3";
	itm.describe = "GOF_itmdescr_Totem_3";
	itm.model = "GOF_Totem_3";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Marigo_Cave";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_3";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_4";
	itm.name = "GOF_itmname_Totem_4";
	itm.describe = "GOF_itmdescr_Totem_4";
	itm.model = "GOF_Totem_4";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "PortSpein_town";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_4";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_5";
	itm.name = "GOF_itmname_Totem_5";
	itm.describe = "GOF_itmdescr_Totem_5";
	itm.model = "GOF_Totem_5";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "FortFrance_Dungeon";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_5";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_6";
	itm.name = "GOF_itmname_Totem_6";
	itm.describe = "GOF_itmdescr_Totem_6";
	itm.model = "GOF_Totem_6";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Tortuga_town";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_6";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_7";
	itm.name = "GOF_itmname_Totem_7";
	itm.describe = "GOF_itmdescr_Totem_7";
	itm.model = "GOF_Totem_7";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Villemstad_townhall";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_7";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_8";
	itm.name = "GOF_itmname_Totem_8";
	itm.describe = "GOF_itmdescr_Totem_8";
	itm.model = "GOF_Totem_8";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Mayak8";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_8";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_9";
	itm.name = "GOF_itmname_Totem_9";
	itm.describe = "GOF_itmdescr_Totem_9";
	itm.model = "GOF_Totem_9";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Santiago_Incquisitio";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_9";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_10";
	itm.name = "GOF_itmname_Totem_10";
	itm.describe = "GOF_itmdescr_Totem_10";
	itm.model = "GOF_Totem_10";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_10";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_11";	//������ ����� �� ������ ����
	itm.name = "GOF_itmname_Totem_11";
	itm.describe = "GOF_itmdescr_Totem_11";
	itm.model = "GOF_Totem_11";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Tenochtitlan";
	itm.startLocator = "item1";
	itm.useLocation = "Tenochtitlan";
	itm.useLocator = "button04";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;  

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_12";	//���������� �� �������� ������ � ��������
	itm.name = "GOF_itmname_Totem_12";
	itm.describe = "GOF_itmdescr_Totem_12";
	itm.model = "GOF_Totem_12";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = 0; 
	itm.useLocation = "Temple_great";
	itm.useLocator = "button01";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_13";	//���� �� ���� ������� �� ������ ����
	itm.name = "GOF_itmname_Totem_13";
	itm.describe = "GOF_itmdescr_Totem_13";
	itm.model = "GOF_Totem_13";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Tenotchitlan_Jungle_06";
	itm.startLocator = "item1";
	itm.useLocation = "Tenochtitlan";
	itm.useLocator = "button02";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_14";	//���� �� ���� ������� �� ������ ����
	itm.name = "GOF_itmname_Totem_14";
	itm.describe = "GOF_itmdescr_Totem_14";
	itm.model = "GOF_Totem_14";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Panama_jungle_02";
	itm.startLocator = "item1";
	itm.useLocation = "Tenochtitlan";
	itm.useLocator = "button03";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	makeref(itm,Items[n]);
	itm.id = "GOF_Totem_15";	//���������� �� ������ �������� ������
	itm.name = "GOF_itmname_Totem_15";
	itm.describe = "GOF_itmdescr_Totem_15";
	itm.model = "GOF_Totem_15";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = true; 
	itm.startLocation = "Temple_Inside";
	itm.startLocator = "item1";
	itm.useLocation = "Temple_great";
	itm.useLocator = "button02";
	itm.price = (rand(8)+1)*1000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++; 

	//Totems_end = n;
	//��� �������� ������� �������� ����� 

	makeref(itm,Items[n]);
	itm.id = "GOF_SkullAztec";
	itm.name = "GOF_itmname_SkullAztec";
	itm.describe = "GOF_itmdescr_SkullAztec";
	itm.model = "GOF_SkullAztec";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOFAZTEC";
	itm.shown = 1; 
	itm.startLocation = "Temple_great";
	itm.startLocator = "item1";
	itm.price = 50000;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_KnifeAztec";
	itm.name = "GOF_itmname_KnifeAztec";
	itm.describe = "GOF_itmdescr_KnifeAztec";
	itm.model = "GOF_KnifeAztec";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF13";
	itm.shown = 0; 
	itm.useLocation = "Tenochtitlan";
	itm.useLocator = "button01";
	itm.price = 12500;
	// boal 19.01.2004 -->
	itm.Weight = 0.3;
	// boal 19.01.2004 <--
	itm.ItemType = "QUESTITEMS";
	n++;

	ItemsForLocators_end = n; //�������� ����� ��� ����. ���������

	// <<<< ---------------  QUEST ITEMS  --------------------

	// ����� //////////////////////////////////////////////////
	makeref(itm,Items[n]);
	itm.id = "GOF_map_bad";	// to del
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_bad";
	itm.describe = "GOF_itmdescr_map_bad";
	itm.model = "GOF_";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF10";
	//	itm.shown = 0;
	itm.price = 500;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	itm.imageTga = "map_1";
	itm.imageType = "cabin_map";
	// boal 19.01.2004 <--
	itm.rare = 0.005;
	itm.ItemType = "MAP";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_map_normal";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_normal";
	itm.describe = "GOF_itmdescr_map_normal";
	itm.model = "GOF_";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = 0;
	itm.price = 1525;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	itm.imageTga = "map_2";
	itm.imageType = "cabin_map";
	// boal 19.01.2004 <--
	itm.rare = 0.001;
	itm.ItemType = "MAP";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Map_Best"; // Warship. �������� �����
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_Map_Best";
	itm.describe = "GOF_itmdescr_Map_Best";
	itm.model = "GOF_";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = 0;
	itm.price = 15000;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	// boal 19.01.2004 <--
	itm.rare = 0.001;

	makeref(itm,Items[n]);
	itm.id = "GOF_map_good";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_good";
	itm.describe = "GOF_itmdescr_map_good";
	itm.model = "GOF_";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF14";
	//	itm.shown = 0;
	itm.price = 3050;
	// boal 19.01.2004 -->
	itm.Weight = 0.1;
	itm.imageTga = "map_3";
	itm.imageType = "cabin_map";
	// boal 19.01.2004 <--
	itm.rare = 0.0001;
	itm.ItemType = "MAP";
	n++;
		
	// boal 270904 -->
	makeref(itm,Items[n]);
	itm.id = "GOF_map_bermudas";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_bermudas";
	itm.describe = "GOF_itmdescr_map_bermudas";
	itm.model = "GOF_";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 650;
	itm.Weight = 0.2;
	itm.imageTga = "bermudas";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_jam";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_jam";
	itm.describe = "GOF_itmdescr_map_jam";
	itm.model = "GOF_";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "Jamaica";
	itm.imageType = "";
	itm.MapIsland = "Redmond";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_cayman";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_cayman";
	itm.describe = "GOF_itmdescr_map_cayman";
	itm.model = "GOF_";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 1000;
	itm.Weight = 0.2;
	itm.imageTga = "kayman";
	itm.imageType = "";
	itm.MapIsland = "Cayman";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_barbados";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_barbados";
	itm.describe = "GOF_itmdescr_map_barbados";
	itm.model = "GOF_";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "barbados";
	itm.imageType = "";
	itm.MapIsland = "Oxbay";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_TORTUGA";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_TORTUGA";
	itm.describe = "GOF_itmdescr_map_TORTUGA";
	itm.model = "GOF_";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "TORTUGA";
	itm.imageType = "";
	itm.MapIsland = "Oxbay";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);	////
	itm.id = "GOF_map_Curacao";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_Curacao";
	itm.describe = "GOF_itmdescr_map_Curacao";
	itm.model = "GOF_";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "curacao";
	itm.imageType = "";
	itm.MapIsland = "Douwesen";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_martiniqua";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_martiniqua";
	itm.describe = "GOF_itmdescr_map_martiniqua";
	itm.model = "GOF_";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "martinica";
	itm.imageType = "";
	itm.MapIsland = "FalaiseDeFleur";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_dominica";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_dominica";
	itm.describe = "GOF_itmdescr_map_dominica";
	itm.model = "GOF_";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 1000;
	itm.Weight = 0.2;
	itm.imageTga = "dominica";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_trinidad";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_trinidad";
	itm.describe = "GOF_itmdescr_map_trinidad";
	itm.model = "GOF_";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "trinidad";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_puerto";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_puerto";
	itm.describe = "GOF_itmdescr_map_puerto";
	itm.model = "GOF_";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 600;
	itm.Weight = 0.2;
	itm.imageTga = "p_rico";
	itm.imageType = "";
	itm.MapIsland = "IslaMuelle";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_cuba";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_cuba";
	itm.describe = "GOF_itmdescr_map_cuba";
	itm.model = "GOF_";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 3100;
	itm.Weight = 0.2;
	itm.imageTga = "cuba";
	itm.imageType = "";
	itm.MapIsland = "Cuba";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_Pearl";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_Pearl";
	itm.describe = "GOF_itmdescr_map_Pearl";
	itm.model = "GOF_";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 3250;
	itm.Weight = 0.2;
	itm.imageTga = "Pearl";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_hisp";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_hisp";
	itm.describe = "GOF_itmdescr_map_hisp";
	itm.model = "GOF_";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 2500;
	itm.Weight = 0.2;
	itm.imageTga = "hispaniola";
	itm.imageType = "";
	itm.MapIsland = "Gaity";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_nevis";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_nevis";
	itm.describe = "GOF_itmdescr_map_nevis";
	itm.model = "GOF_";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 450;
	itm.Weight = 0.2;
	itm.imageTga = "nevis";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_beliz";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_beliz";
	itm.describe = "GOF_itmdescr_map_beliz";
	itm.model = "GOF_";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 1100;
	itm.Weight = 0.2;
	itm.imageTga = "beliz";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);	/////
	itm.id = "GOF_map_guad";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_guad";
	itm.describe = "GOF_itmdescr_map_guad";
	itm.model = "GOF_";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "guadelupa";
	itm.imageType = "";
	itm.MapIsland = "Guadelupa";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);	/////
	itm.id = "GOF_map_santa";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_santa";
	itm.describe = "GOF_itmdescr_map_santa";
	itm.model = "GOF_";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 950;
	itm.Weight = 0.2;
	itm.imageTga = "santa";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_antigua";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_antigua";
	itm.describe = "GOF_itmdescr_map_antigua";
	itm.model = "GOF_";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "antigua";
	itm.imageType = "";
	itm.MapIsland = "Antigua";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_terks";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_terks";
	itm.describe = "GOF_itmdescr_map_terks";
	itm.model = "GOF_";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 1500;
	itm.Weight = 0.2;
	itm.imageTga = "terks";
	itm.imageType = "";
	itm.MapIsland = "Terks";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_sm";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_sm";
	itm.describe = "GOF_itmdescr_map_sm";
	itm.model = "GOF_";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "s_martin";
	itm.imageType = "";
	itm.MapIsland = "Sent";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_maine_1";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_maine_1";
	itm.describe = "GOF_itmdescr_map_maine_1";
	itm.model = "GOF_";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 5000;
	itm.Weight = 0.2;
	itm.imageTga = "maine_1";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_maine_2";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_maine_2";
	itm.describe = "GOF_itmdescr_map_maine_2";
	itm.model = "GOF_";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 5000;
	itm.Weight = 0.2;
	itm.imageTga = "maine_2";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_panama";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_panama";
	itm.describe = "GOF_itmdescr_map_panama";
	itm.model = "GOF_";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF13";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "panama";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_maracaibo";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_maracaibo";
	itm.describe = "GOF_itmdescr_map_maracaibo";
	itm.model = "GOF_";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "maracaibo";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_cumana";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_cumana";
	itm.describe = "GOF_itmdescr_map_cumana";
	itm.model = "GOF_";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF11";
	itm.price = 500;
	itm.Weight = 0.2;
	itm.imageTga = "cumana";
	itm.imageType = "";
	itm.MapIsland = "";
	itm.ItemType = "MAP";
	n++;
	// boal 270904 <--
	
	// boal ����� ���������� ����� -->
	makeref(itm,Items[n]);
	itm.id = "GOF_map_full";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_full";
	itm.describe = "GOF_itmdescr_map_full";
	itm.model = "GOF_";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF7";
	itm.price = 0; // 0 test
	itm.Weight = 0.4;
	itm.imageTga = "none";
	itm.imageType = "MapRead"; // ��������� �����
	itm.mapType = "Full";
	itm.ItemType = "MAP";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_map_part1";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_part1";
	itm.describe = "GOF_itmdescr_map_part1";
	itm.model = "GOF_";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF7";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.imageTga = "none";
	itm.imageType = "MapRead"; // ��������� �����
	itm.mapType = "Part";
	itm.ItemType = "MAP";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_map_part2";
	itm.groupID = MAPS_ITEM_TYPE;
	itm.name = "GOF_itmname_map_part2";
	itm.describe = "GOF_itmdescr_map_part2";
	itm.model = "GOF_";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF7";
	itm.price = 0;
	itm.Weight = 0.2;
	itm.imageTga = "none";
	itm.imageType = "MapRead"; // ��������� �����
	itm.mapType = "Part";
	itm.ItemType = "MAP";
	n++;
	// boal ����� ���������� ����� <--


	//  ���������� ������
	ItemDeadStartCount = n;
	trace("���������� ������ � �������� "+ItemDeadStartCount);
	
	
	makeref(itm,Items[n]);
	itm.id = "GOF_Statue1"; //+1
	itm.name = "GOF_itmname_statue1";
	itm.describe = "GOF_itmdescr_statue1";
	itm.model = "GOF_stat1";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF1";
	//itm.shown = false;
	itm.price = 10;
	itm.Weight = 35;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.001;
	n++;
	
	//SPYGLASSES
	
	makeref(itm,Items[n]);
	itm.id = "GOF_spyglass1";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "GOF_itmname_spyglass1";
	itm.describe = "GOF_itmdescr_spyglass1";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 25;
	itm.Weight = 1;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.15;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.folder = "items";
	itm.model = "GOF_spyglass4";
	itm.scope.texture = "eye_BadTub.tga";
	itm.scope.zoom = 2.5;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 0;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 0;
	itm.scope.show.sail = 0;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 0;
	itm.scope.show.cannontype = 0;
	itm.scope.show.captain_skills = 0;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_spyglass2";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "GOF_itmname_spyglass2";
	itm.describe = "GOF_itmdescr_spyglass2";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF6";
	// boal 19.01.2004 -->
	itm.price = 150;
	itm.Weight = 1.5;

	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.folder = "items";
	itm.model = "GOF_spyglass4";
	itm.scope.texture = "eye_CommonTub.tga";
	itm.scope.zoom = 4.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 0;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 0;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 0;
	itm.scope.show.cannontype = 0;
	itm.scope.show.captain_skills = 0;
	itm.minlevel = 1;
	itm.rare = 0.07;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_spyglass3";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "GOF_itmname_spyglass3";
	itm.describe = "GOF_itmdescr_spyglass3";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF6";
	itm.price = 450;
	// boal 19.01.2004 -->
	itm.Weight = 2;

    itm.Solder_o.rare = 0.15;
    itm.Solder_o.min = 1;
    itm.Solder_o.max = 1;
    // boal 19.01.2004 <--
	itm.folder = "items";
	itm.model = "GOF_spyglass4";
	itm.scope.texture = "eye_GoodTub.tga";
	itm.scope.zoom = 7.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 0;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 0;
	itm.scope.show.cannontype = 0;
	itm.scope.show.captain_skills = 0;
	itm.minlevel = 1;
	itm.rare = 0.05;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_spyglass4";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "GOF_itmname_spyglass4";
	itm.describe = "GOF_itmdescr_spyglass4";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF1";
	itm.folder = "items";
	itm.model = "GOF_spyglass4";
	itm.price = 1250;
	// boal 19.01.2004 -->
	itm.Weight = 4;

    itm.Solder_o.rare = 0.05;
    itm.Solder_o.min = 1;
    itm.Solder_o.max = 1;
    // boal 19.01.2004 <--
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 10.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.scope.show.cannontype = 0;
	itm.scope.show.captain_skills = 1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_spyglass5";
	itm.groupID = SPYGLASS_ITEM_TYPE;
	itm.name = "GOF_itmname_spyglass5";
	itm.describe = "GOF_itmdescr_spyglass5";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF1";
	itm.folder = "items";
	itm.model = "GOF_spyglass4";
	itm.price = 21250;
	// boal 19.01.2004 -->
	itm.Weight = 7;

    itm.Solder_o.rare = 0.0001;
    itm.Solder_o.min = 1;
    itm.Solder_o.max = 1;
    // boal 19.01.2004 <--
	itm.scope.texture = "eye_BestTub.tga";
	itm.scope.zoom = 15.0;
	itm.scope.time_activate = 500;
	itm.scope.time_update = 150;
	itm.scope.show.nation = 1;
	itm.scope.show.cannons = 1;
	itm.scope.show.ship_name = 1;
	itm.scope.show.ship_type = 1;
	itm.scope.show.hull = 1;
	itm.scope.show.sail = 1;
	itm.scope.show.crew = 1;
	itm.scope.show.speed = 1;
	itm.scope.show.charge = 1;
	itm.scope.show.cannontype = 1;
	itm.scope.show.captain_skills = 1;
	itm.minlevel = 1;
	itm.rare = 0.0001;
	itm.ItemType = "SUPPORT";
	n++;

	//POTIONS

	makeref(itm,Items[n]);
	itm.id = "GOF_potion1";
	itm.name = "GOF_itmname_potion1";
	itm.describe = "GOF_itmdescr_potion1";
	itm.model = "GOF_potion";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF1";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 50;
	itm.Weight = 0.8;

	itm.Solder_o.rare = 0.3;
	itm.Solder_o.min = 2;
	itm.Solder_o.max = 6;
	
	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 3;
	
	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 4;
 
	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 7;

  // boal 19.01.2004 <--
	itm.potion.pic = 21;
	itm.potion.tex = 0; // battle_interface\useditems1.tga
	itm.potion.health = 40.0;
	itm.minlevel = 0;
	itm.rare = 0.3;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_potion2";
	itm.name = "GOF_itmname_potion2";
	itm.describe = "GOF_itmdescr_potion2";
	itm.model = "GOF_potionbig";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF1";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 125;
	itm.Weight = 1;

	itm.Solder_o.rare = 0.3;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 3;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 3;
 
	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 5;

  // boal 19.01.2004 <--
	itm.potion.pic = 22;
	itm.potion.tex = 0; // battle_interface\useditems1.tga
	itm.potion.health = 150.0;
	itm.potion.health.speed = 10; // �������� ���������
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_potion3";
	itm.name = "GOF_itmname_potion3";
	itm.describe = "GOF_itmdescr_potion3";
	itm.model = "GOF_Antidote";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF1";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 100;
	itm.Weight = 0.4;

	itm.Solder_o.rare = 0.05;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.potion.pic = 23;
	itm.potion.tex = 0; // battle_interface\useditems2.tga
	itm.potion.antidote = true;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_potion4";
	itm.name = "GOF_itmname_potion4";
	itm.describe = "GOF_itmdescr_potion4";
	itm.model = "GOF_balsam";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF1";
	// boal 19.01.2004 -->
	itm.price = 225;
	itm.Weight = 0.4;

	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	
	itm.Solder_o.rare = 0.05;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 3;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	// boal 19.01.2004 <--
	itm.potion.pic = 24;
	itm.potion.tex = 0; // battle_interface\useditems1.tga
	itm.potion.health = 130.0;
	itm.potion.antidote = true;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	//-----------ADDED BY VERRUCKT BROTHEL MOD------------------
	makeref(itm,Items[n]);
	itm.id = "GOF_potionrum";
	itm.name = "GOF_itmname_potionrum";
	itm.describe = "GOF_itmdescr_potionrum";
	itm.model = "GOF_balsam";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF1";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 75;
	itm.Weight = 2;

	itm.Solder_o.rare = 0.1;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Solder.rare = 0.2;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.2;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.potion.pic = 25;
	itm.potion.tex = 0; // battle_interface\useditems3.tga
	itm.potion.health = 50.0;
	itm.potion.antidote = true;
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_potionwine";
	itm.name = "GOF_itmname_potionwine";
	itm.describe = "GOF_itmdescr_potionwine";
	itm.model = "GOF_balsam";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF1";
	// boal 19.01.2004 -->
	itm.price = 250;
	itm.Weight = 1;

	itm.Solder_o.rare = 0.3;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.potion.pic = 26;
	itm.potion.tex = 0; // battle_interface\useditems3.tga
	itm.potion.health = 175.0;
	itm.potion.health.speed = 7; // �������� ���������
	itm.minlevel = 1;
	itm.rare = 0.1;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_potion5";
	itm.name = "GOF_itmname_potion5";
	itm.describe = "GOF_itmdescr_potion5";
	itm.model = "GOF_balsam";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF7";
	// boal 19.01.2004 -->
	itm.price = 15;
	itm.Weight = 0.4;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 9;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 9;
	// boal 19.01.2004 <--
	itm.potion.pic = 27;
	itm.potion.tex = 0; // battle_interface\useditems3.tga
	itm.potion.health = 25.0;
	itm.minlevel = 1;
	itm.rare = 0.2;
	itm.SortIndex = 2;
	itm.ItemType = "SUPPORT";
	n++;

	//JEWELRY

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry1";
	itm.name = "GOF_itmname_jewelry1";
	itm.describe = "GOF_itmdescr_jewelry1";
	itm.model = "GOF_sapphire";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25;
	itm.Weight = 0.2;

	itm.Solder_o.rare = 0.1; 
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 4;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 4;
	
	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	
	itm.Citizen.rare = 0.05;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.05;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry2";
	itm.name = "GOF_itmname_jewelry2";
	itm.describe = "GOF_itmdescr_jewelry2";
	itm.model = "GOF_diamond";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 350;
	itm.Weight = 0.2;

	itm.Solder_o.rare = 0.1;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 4;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry3";
	itm.name = "GOF_itmname_jewelry3";
	itm.describe = "GOF_itmdescr_jewelry3";
	itm.model = "GOF_ruby";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 275;
	itm.Weight = 0.2;

	itm.Solder_o.rare = 0.1;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 4;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry4";
	itm.name = "GOF_itmname_jewelry4";
	itm.describe = "GOF_itmdescr_jewelry4";
	itm.model = "GOF_emerald";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 250;
	itm.Weight = 0.2;

	itm.Solder_o.rare = 0.1;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 4;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry5";  // Gold
	itm.name = "GOF_itmname_jewelry5";
	itm.describe = "GOF_itmdescr_jewelry5";
	itm.model = "GOF_sapphire";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 120;
	itm.Weight = 0.7;

	itm.Solder_o.rare = 0.2;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 4;

	itm.Monster.rare = 0.3;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 2;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry6";
	itm.name = "GOF_itmname_jewelry6";
	itm.describe = "GOF_itmdescr_jewelry6";
	itm.model = "GOF_sapphire";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 50;
	itm.Weight = 0.1;

	itm.Solder.rare = 0.01;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.3;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry7";
	itm.name = "GOF_itmname_jewelry7";
	itm.describe = "GOF_itmdescr_jewelry7";
	itm.model = "GOF_sapphire";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 100;
	itm.Weight = 0.1;

	itm.Solder_o.rare = 0.1;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry8"; // +1 sneak
	itm.name = "GOF_itmname_jewelry8";
	itm.describe = "GOF_itmdescr_jewelry8";
	itm.model = "GOF_sapphire";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 5;
	itm.Weight = 0.1;
	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	
	itm.Warrior.rare = 0.15;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.15;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.25;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry9"; // +1 sneak
	itm.name = "GOF_itmname_jewelry9";
	itm.describe = "GOF_itmdescr_jewelry9";
	itm.model = "GOF_sapphire";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 40;
	itm.Weight = 0.2;

	itm.Solder.rare = 0.01;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Warrior.rare = 0.03;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.2;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry10";
	itm.name = "GOF_itmname_jewelry10";
	itm.describe = "GOF_itmdescr_jewelry10";
	itm.model = "GOF_emerald";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 85;
	itm.Weight = 0.1;

	itm.Solder_o.rare = 0.2;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;
	
	itm.Monster.rare = 0.3;
	itm.Monster.min = 1;
	itm.Monster.max = 1;


	itm.Warrior.rare = 0.02;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.3;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry11";
	itm.name = "GOF_itmname_jewelry11";
	itm.describe = "GOF_itmdescr_jewelry11";
	itm.model = "GOF_pearlbig";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 45;
	itm.Weight = 0.3;

	itm.Solder_o.rare = 0.2;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 5;

	itm.Monster.rare = 0.2;
	itm.Monster.min = 1;
	itm.Monster.max = 6;


	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 6;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 5;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 5;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry12";
	itm.name = "GOF_itmname_jewelry12";
	itm.describe = "GOF_itmdescr_jewelry12";
	itm.model = "GOF_pearlsmall";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 20;
	itm.Weight = 0.1;

	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 5;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 20;

	itm.Citizen.rare = 0.15;
	itm.Citizen.min = 1;
	itm.Citizen.max = 15;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 5;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry13";
	itm.name = "GOF_itmname_jewelry13";
	itm.describe = "GOF_itmdescr_jewelry13";
	itm.model = "GOF_sapphire";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 75;
	itm.Weight = 0.3;

	itm.Solder_o.rare = 0.05;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Monster.rare = 0.01;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 2;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry14";
	itm.name = "GOF_itmname_jewelry14";
	itm.describe = "GOF_itmdescr_jewelry14";
	itm.model = "GOF_sapphire";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 100;
	itm.Weight = 0.1;

	itm.Solder_o.rare = 0.05;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Monster.rare = 0.01;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 2;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry15"; // +1 sneak
	itm.name = "GOF_itmname_jewelry15";
	itm.describe = "GOF_itmdescr_jewelry15";
	itm.model = "GOF_sapphire";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 150;
	itm.Weight = 0.5;

	itm.Solder_o.rare = 0.01;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Monster.rare = 0.02;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry16";
	itm.name = "GOF_itmname_jewelry16";
	itm.describe = "GOF_itmdescr_jewelry16";
	itm.model = "GOF_sapphire";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF2";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 5;
	itm.Weight = 0.3;

	itm.Monster.rare = 0.01;
	itm.Monster.min = 1;
	itm.Monster.max = 4;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 2;

	itm.Citizen_f.rare = 0.4;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 2;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry17";  // �������
	itm.name = "GOF_itmname_jewelry17";
	itm.describe = "GOF_itmdescr_jewelry17";
	itm.model = "GOF_pursel";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 55;
	itm.Weight = 0.5;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 5;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 3;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_jewelry18";
	itm.name = "GOF_itmname_jewelry18";
	itm.describe = "GOF_itmdescr_jewelry18";
	itm.model = "GOF_pursel";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 165;
	itm.Weight = 0.1;

	itm.Solder_o.rare = 0.2;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen_f.rare = 0.25;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bullet"; // boal ��� ���� "mineral1";
	itm.name = "GOF_itmname_bullet"; //"itmname_mineral1";
	itm.describe = "GOF_itmdescr_bullet";//"itmdescr_mineral1";
	itm.model = "GOF_pursel";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF8";
	//	itm.shown = false;
	itm.price = 4;//280;
	itm.Weight = 0.1;
	itm.minlevel =0;
	itm.rare = 0.3;
	itm.SortIndex = 1;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral2";
	itm.name = "GOF_itmname_mineral2";
	itm.describe = "GOF_itmdescr_mineral2";
	itm.model = "GOF_sapphire";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF8";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 300;
	itm.Weight = 6;

	itm.Solder.rare = 0.01;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	
	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.02;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral3";
	itm.name = "GOF_itmname_mineral3";
	itm.describe = "GOF_itmdescr_mineral3";
	itm.model = "GOF_sapphire";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF8";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 5;
	itm.Weight = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 4;
	
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral4"; // ������
	itm.name = "GOF_itmname_mineral4";
	itm.describe = "GOF_itmdescr_mineral4";
	itm.model = "GOF_pursel"; // ���� ��� �����
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF8";
	//	itm.shown = false;
	itm.price = 12;
	// boal 19.01.2004 -->
	itm.Weight = 2;

	itm.Solder.rare = 0.05;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	
	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.05;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral5";
	itm.name = "GOF_itmname_mineral5";
	itm.describe = "GOF_itmdescr_mineral5";
	itm.model = "GOF_pursel";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1;
	itm.Weight = 3;

	itm.Monster.rare = 0.01;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.02;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral6";
	itm.name = "GOF_itmname_mineral6";
	itm.describe = "GOF_itmdescr_mineral6";
	itm.model = "GOF_pursel";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 10;
	itm.Weight = 1;

	itm.Solder.rare = 0.001;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Monster.rare = 0.3;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.001;
	itm.Warrior.min = 1;
	itm.Warrior.max = 5;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 5;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.4;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral7";
	itm.name = "GOF_itmname_mineral7";
	itm.describe = "GOF_itmdescr_mineral7";
	itm.model = "GOF_pursel";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 70;
	itm.Weight = 0.8;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.3;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	
	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral8";
	itm.name = "GOF_itmname_mineral8";
	itm.describe = "GOF_itmdescr_mineral8";
	itm.model = "GOF_pursel";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 15;
	itm.Weight = 1;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel =4;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral9";
	itm.name = "GOF_itmname_mineral9";
	itm.describe = "GOF_itmdescr_mineral9";
	itm.model = "GOF_pursel";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 40;
	itm.Weight = 1;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.2;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel =2;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_mineral10";
	itm.name = "GOF_itmname_mineral10";
	itm.describe = "GOF_itmdescr_mineral10";
	itm.model = "GOF_pursel";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 2;
	itm.Weight = 1;

	itm.Solder.rare = 0.001;
	itm.Solder.min = 1;
	itm.Solder.max = 5;

	itm.Monster.rare = 0.001;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.001;
	itm.Warrior.min = 1;
	itm.Warrior.max = 5;
	// boal 19.01.2004 <--
	itm.minlevel =0;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_sculMa1";
	itm.name = "GOF_itmname_sculMa1";
	itm.describe = "GOF_itmdescr_sculMa1";
	itm.model = "GOF_pursel";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF9";
	itm.price = 2500;
	// boal 19.01.2004 -->
	itm.Weight = 3.5;
	// boal 19.01.2004 <--
	itm.minlevel =5;
	itm.rare = 0.01;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_sculMa2";
	itm.name = "GOF_itmname_sculMa2";
	itm.describe = "GOF_itmdescr_sculMa2";
	itm.model = "GOF_pursel";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF9";
	itm.price = 3500;
	// boal 19.01.2004 -->
	itm.Weight = 3.5;
	// boal 19.01.2004 <--
	itm.minlevel =1;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_sculMa3";
	itm.name = "GOF_itmname_sculMa3";
	itm.describe = "GOF_itmdescr_sculMa3";
 	itm.model = "GOF_pursel";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF9";
	itm.price = 5000;
	// boal 19.01.2004 -->
	itm.Weight = 3.5;
	// boal 19.01.2004 <--
	itm.minlevel =1;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_cat1";  // cat <-----Officerpuppy 02/04/10
	itm.name = "GOF_itmname_cat1";
	itm.describe = "GOF_itmdescr_cat1";
	itm.model = "GOF_";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF14";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 2500;
	itm.Weight = 1;
  	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.01;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_CursedCoin";  // Aztec gold <-----Officerpuppy 04/19/10
	itm.name = "GOF_itmname_CursedCoin";
	itm.describe = "GOF_itmdescr_CursedCoin";
	itm.model = "GOF_purse";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 500;
	itm.Weight = 0.1;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 10;
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Maokun";  // Mao Kun map <-----Officerpuppy 05/09/11
	itm.name = "GOF_itmname_Maokun";
	itm.describe = "GOF_itmdescr_Maokun";
	itm.model = "GOF_";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 4500;
	itm.Weight = 0.2;
	itm.imageTga = "books\maokun";
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Voodoo";  // Voodoo doll <-----Officerpuppy 05/09/11
	itm.name = "GOF_itmname_Voodoo";
	itm.describe = "GOF_itmdescr_Voodoo";
	itm.model = "GOF_";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 400;
	itm.Weight = 0.1;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 10;
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Chalices";  // Chalices of Cartagena <-----Officerpuppy 05/09/11
	itm.name = "GOF_itmname_Chalices";
	itm.describe = "GOF_itmdescr_Chalices";
	itm.model = "GOF_";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 5000;
	itm.Weight = 3;
	itm.minlevel = 1;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Cane";  // Cutler Beckett's cane <-----Officerpuppy 06/09/11
	itm.name = "GOF_itmname_Cane";
	itm.describe = "GOF_itmdescr_Cane";
	itm.model = "GOF_";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 2500;
	itm.Weight = 3;
	itm.minlevel = 1;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Keycloth";  // Drawing of the key to the Dead Man's Chest <-----Officerpuppy 06/09/11
	itm.name = "GOF_itmname_Keycloth";
	itm.describe = "GOF_itmdescr_Keycloth";
	itm.model = "GOF_";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 1250;
	itm.Weight = 1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Timekeeper";  // Timekeeper  <-----Officerpuppy 06/09/11
	itm.name = "GOF_itmname_Timekeeper";
	itm.describe = "GOF_itmdescr_Timekeeper";
	itm.model = "GOF_";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF14";
	itm.shown = 0;
	itm.price = 4250;
	itm.Weight = 1;
	itm.minlevel = 1;
	itm.rare = 0.01;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Pirata";  // Pirata Codex  <-----Officerpuppy 06/09/11
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_Pirata";
	itm.describe = "GOF_itmdescr_Pirata";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF14";
	itm.price = 4250;
	itm.Weight = 3;
	itm.rare = 0.01;
	itm.imageTga = "books\piratacodex_1";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_Malleus";  // Malleus Maleficarum  <-----Officerpuppy 06/09/11
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_Malleus";
	itm.describe = "GOF_itmdescr_Malleus";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF14";
	itm.price = 3250;
	itm.Weight = 3;
	itm.rare = 0.01;
	itm.imageTga = "books\Malleus_1";
	n++;

	//INDIAN TRINKETS

	makeref(itm,Items[n]);
	itm.id = "GOF_indian1"; // +1 sneak
	itm.name = "GOF_itmname_indian1";
	itm.describe = "GOF_itmdescr_indian1";
	itm.model = "GOF_pursel";
	itm.picIndex = 1;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 150;
	itm.Weight = 3;

	itm.Solder.rare = 0.001;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Monster.rare = 0.03;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.001;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian2";
	itm.name = "GOF_itmname_indian2";
	itm.describe = "GOF_itmdescr_indian2";
	itm.model = "GOF_pursel";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 100;
	itm.Weight = 1;

	itm.Solder.rare = 0.02;
	itm.Solder.min = 1;
	itm.Solder.max = 1;

	itm.Monster.rare = 0.03;
	itm.Monster.min = 1;
	itm.Monster.max = 3;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian3";
	itm.name = "GOF_itmname_indian3";
	itm.describe = "GOF_itmdescr_indian3";
	itm.model = "GOF_pursel";
	itm.picIndex = 3;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 50;
	itm.Weight = 0.6;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	
	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;
	
	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian4";
	itm.name = "GOF_itmname_indian4";
	itm.describe = "GOF_itmdescr_indian4";
	itm.model = "GOF_pursel";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 2;
	itm.Weight = 2;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.2;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian5"; // +1 sneak
	itm.name = "GOF_itmname_indian5";
	itm.describe = "GOF_itmdescr_indian5";
	itm.model = "GOF_sapphire";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 65;
	itm.Weight = 1.5;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.03;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 3;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian6";
	itm.name = "GOF_itmname_indian6";
	itm.describe = "GOF_itmdescr_indian6";
	itm.model = "GOF_sapphire";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 300;
	itm.Weight = 1;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.001;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 2;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian7"; // +1 sneak
	itm.name = "GOF_itmname_indian7";
	itm.describe = "GOF_itmdescr_indian7";
	itm.model = "GOF_sapphire";
	itm.picIndex = 7;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 75;
	itm.Weight = 3.6;

	itm.Monster.rare = 0.07;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.01;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.01;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 4;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian8";
	itm.name = "GOF_itmname_indian8";
	itm.describe = "GOF_itmdescr_indian8";
	itm.model = "GOF_sapphire";
	itm.picIndex = 8;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 70;
	itm.Weight = 0.6;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 4;
	itm.rare = 0.07;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian9";
	itm.name = "GOF_itmname_indian9";
	itm.describe = "GOF_itmdescr_indian9";
	itm.model = "GOF_sapphire";
	itm.picIndex = 9;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 10;
	itm.Weight = 1;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.2;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian11";  // rats god
	itm.name = "GOF_itmname_indian11";
	itm.describe = "GOF_itmdescr_indian11";
	itm.model = "GOF_";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 2500;
	itm.Weight = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.001;
	n++;
	
	makeref(itm,Items[n]);
	itm.id = "GOF_indian10";
	itm.name = "GOF_itmname_indian10";
	itm.describe = "GOF_itmdescr_indian10";
	itm.model = "GOF_sapphire";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 105;
	itm.Weight = 2;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 7;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian12";
	itm.name = "GOF_itmname_indian12";
	itm.describe = "GOF_itmdescr_indian12";
	itm.model = "GOF_sapphire";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 615;
	itm.Weight = 10;

	itm.Monster.rare = 0.3;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.1;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.2;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;

	itm.Solder.rare = 0.001;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 7;
	itm.rare = 0.001;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian13";
	itm.name = "GOF_itmname_indian13";
	itm.describe = "GOF_itmdescr_indian13";
	itm.model = "GOF_pursel";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 20;
	itm.Weight = 3;

	itm.Monster.rare = 0.05;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.1;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;

	itm.Solder.rare = 0.001;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.1;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian14";
	itm.name = "GOF_itmname_indian14";
	itm.describe = "GOF_itmdescr_indian14";
	itm.model = "GOF_pursel";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 105;
	itm.Weight = 3;

	itm.Monster.rare = 0.1;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.05;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.2;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;

	itm.Solder.rare = 0.001;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian15";
	itm.name = "GOF_itmname_indian15";
	itm.describe = "GOF_itmdescr_indian15";
	itm.model = "GOF_sapphire";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 250;
	itm.Weight = 30;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 3;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian16";
	itm.name = "GOF_itmname_indian16";
	itm.describe = "GOF_itmdescr_indian16";
	itm.model = "GOF_sapphire";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF5";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7;
	itm.Weight = 3;

	itm.Monster.rare = 0.001;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.001;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.2;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.2;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;

	itm.Solder.rare = 0.1;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 3;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian17"; // +1 sneak
	itm.name = "GOF_itmname_indian17";
	itm.describe = "GOF_itmdescr_indian17";
	itm.model = "GOF_sapphire";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF9";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25;
	itm.Weight = 2;

	itm.Monster.rare = 0.06;
	itm.Monster.min = 1;
	itm.Monster.max = 1;

	itm.Warrior.rare = 0.02;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Citizen.rare = 0.01;
	itm.Citizen.min = 1;
	itm.Citizen.max = 1;

	itm.Citizen_f.rare = 0.1;
	itm.Citizen_f.min = 1;
	itm.Citizen_f.max = 1;

	itm.Solder.rare = 0.01
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.05;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian18";
	itm.name = "GOF_itmname_indian18";
	itm.describe = "GOF_itmdescr_indian18";
	itm.model = "GOF_pursel";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 75;
	itm.Weight = 2;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.001;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian19";
	itm.name = "GOF_itmname_indian19";
	itm.describe = "GOF_itmdescr_indian19";
	itm.model = "GOF_pursel";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1200;
	itm.Weight = 2;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.001;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian20";
	itm.name = "GOF_itmname_indian20";
	itm.describe = "GOF_itmdescr_indian20";
	itm.model = "GOF_pursel";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 375;
	itm.Weight = 2;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.001;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian21";
	itm.name = "GOF_itmname_indian21";
	itm.describe = "GOF_itmdescr_indian21";
	itm.model = "GOF_sapphire";
	itm.picIndex = 15;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 12;
	itm.Weight = 2;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.001;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_indian22";
	itm.name = "GOF_itmname_indian22";
	itm.describe = "GOF_itmdescr_indian22";
	itm.model = "GOF_pursel";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF7";
	//	itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 2;
	itm.Weight = 2;

	itm.Monster.rare = 0.005;
	itm.Monster.min = 1;
	itm.Monster.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.001;
	n++;

	//books

	makeref(itm,Items[n]);
	itm.id = "GOF_bookleader_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookleader_1";
	itm.describe = "GOF_itmdescr_bookleader_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 9;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookleader_1";
   	itm.minlevel = 1;
	itm.rare = 0.03;
	
	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--

	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_booklight_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booklight_1";
	itm.describe = "GOF_itmdescr_booklight_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 10;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\booklight_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookfencing_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookfencing_1";
	itm.describe = "GOF_itmdescr_bookfencing_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 11;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookfencing_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookheavy_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookheavy_1";
	itm.describe = "GOF_itmdescr_bookheavy_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 12;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookheavy_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookleader_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookleader_2";
	itm.describe = "GOF_itmdescr_bookleader_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 5;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookleader_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_booklight_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booklight_2";
	itm.describe = "GOF_itmdescr_booklight_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 6;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\booklight_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookfencing_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookfencing_2";
	itm.describe = "GOF_itmdescr_bookfencing_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 7;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookfencing_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookheavy_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookheavy_2";
	itm.describe = "GOF_itmdescr_bookheavy_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 8;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookheavy_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookleader_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookleader_3";
	itm.describe = "GOF_itmdescr_bookleader_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 1;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookleader_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_booklight_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booklight_3";
	itm.describe = "GOF_itmdescr_booklight_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 2;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\booklight_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookfencing_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookfencing_3";
	itm.describe = "GOF_itmdescr_bookfencing_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 3;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookfencing_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookheavy_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookheavy_3";
	itm.describe = "GOF_itmdescr_bookheavy_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 4;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookheavy_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookpistols_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookpistols_1";
	itm.describe = "GOF_itmdescr_bookpistols_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 9;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookpistols_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookluck_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookluck_1";
	itm.describe = "GOF_itmdescr_bookluck_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 10;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookluck_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookstealth_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookstealth_1";
	itm.describe = "GOF_itmdescr_bookstealth_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 11;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookstealth_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_booknavigation_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booknavigation_1";
	itm.describe = "GOF_itmdescr_booknavigation_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 12;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\booknavigation_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookpistols_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookpistols_2";
	itm.describe = "GOF_itmdescr_bookpistols_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 5;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookpistols_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookluck_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookluck_2";
	itm.describe = "GOF_itmdescr_bookluck_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 6;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookluck_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookstealth_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookstealth_2";
	itm.describe = "GOF_itmdescr_bookstealth_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 7;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookstealth_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_booknavigation_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booknavigation_2";
	itm.describe = "GOF_itmdescr_booknavigation_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 8;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\booknavigation_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookpistols_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookpistols_3";
	itm.describe = "GOF_itmdescr_bookpistols_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 1;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookpistols_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookluck_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookluck_3";
	itm.describe = "GOF_itmdescr_bookluck_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 2;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookluck_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookstealth_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookstealth_3";
	itm.describe = "GOF_itmdescr_bookstealth_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 3;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookstealth_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_booknavigation_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booknavigation_3";
	itm.describe = "GOF_itmdescr_booknavigation_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 4;
	itm.picTexture = "BOOKS_2";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\booknavigation_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookaccurate_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookaccurate_1";
	itm.describe = "GOF_itmdescr_bookaccurate_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 9;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookaccurate_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookcannon_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookcannon_1";
	itm.describe = "GOF_itmdescr_bookcannon_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 10;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookcannon_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookgrapple_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookgrapple_1";
	itm.describe = "GOF_itmdescr_bookgrapple_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 11;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookgrapple_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookdefend_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookdefend_1";
	itm.describe = "GOF_itmdescr_bookdefend_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 12;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookdefend_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookaccurate_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookaccurate_2";
	itm.describe = "GOF_itmdescr_bookaccurate_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 5;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookaccurate_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookcannon_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookcannon_2";
	itm.describe = "GOF_itmdescr_bookcannon_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 6;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookcannon_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookgrapple_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookgrapple_2";
	itm.describe = "GOF_itmdescr_bookgrapple_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 7;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookgrapple_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookdefend_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookdefend_2";
	itm.describe = "GOF_itmdescr_bookdefend_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 8;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookdefend_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookaccurate_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookaccurate_3";
	itm.describe = "GOF_itmdescr_bookaccurate_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 1;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookaccurate_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookcannon_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookcannon_3";
	itm.describe = "GOF_itmdescr_bookcannon_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 2;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookcannon_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookgrapple_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookgrapple_3";
	itm.describe = "GOF_itmdescr_bookgrapple_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 3;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price =25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookgrapple_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookdefend_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookdefend_3";
	itm.describe = "GOF_itmdescr_bookdefend_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 4;
	itm.picTexture = "BOOKS_3";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookdefend_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookrepairs_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookrepairs_1";
	itm.describe = "GOF_itmdescr_bookrepairs_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 9;
	itm.picTexture = "BOOKS_4";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookrepairs_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookmoney_1";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookmoney_1";
	itm.describe = "GOF_itmdescr_bookmoney_1";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 10;
	itm.picTexture = "BOOKS_4";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 1000;
	itm.Weight = 3;
	itm.imageTga = "books\bookmoney_1";

	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;

	itm.Solder.rare = 0.03;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	// boal 19.01.2004 <--
	itm.minlevel = 1;
	itm.rare = 0.03;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookrepairs_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookrepairs_2";
	itm.describe = "GOF_itmdescr_bookrepairs_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 5;
	itm.picTexture = "BOOKS_4";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookrepairs_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookmoney_2";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookmoney_2";
	itm.describe = "GOF_itmdescr_bookmoney_2";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 6;
	itm.picTexture = "BOOKS_4";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 7500;
	itm.Weight = 3;
	itm.imageTga = "books\bookmoney_2";

	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.005;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookrepairs_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookrepairs_3";
	itm.describe = "GOF_itmdescr_bookrepairs_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 1;
	itm.picTexture = "BOOKS_4";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookrepairs_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookmoney_3";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookmoney_3";
	itm.describe = "GOF_itmdescr_bookmoney_3";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 2;
	itm.picTexture = "BOOKS_4";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 25000;
	itm.Weight = 3;
	itm.imageTga = "books\bookmoney_3";

	// boal 19.01.2004 <--
	itm.minlevel = 10;
	itm.rare = 0.0003;
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_bookwrestling";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookwrestling";
	itm.describe = "GOF_itmdescr_bookwrestling";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 13;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 37500;
	itm.Weight = 3;
	itm.imageTga = "books\bookwrestling";

	// boal 19.01.2004 <--
	itm.minlevel = 15;
	itm.rare = 0.0002;
	n++;

		makeref(itm,Items[n]);
	itm.id = "GOF_booklgtweapman";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_booklgtweapman";
	itm.describe = "GOF_itmdescr_booklgtweapman";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 13;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 37500;
	itm.Weight = 3;
	itm.imageTga = "books\booklgtweapman";

	// boal 19.01.2004 <--
	itm.minlevel = 15;
	itm.rare = 0.0002;
	n++;

		makeref(itm,Items[n]);
	itm.id = "GOF_bookmedweapman";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookmedweapman";
	itm.describe = "GOF_itmdescr_bookmedweapman";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 13;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 37500;
	itm.Weight = 3;
	itm.imageTga = "books\bookmedweapman";

	// boal 19.01.2004 <--
	itm.minlevel = 15;
	itm.rare = 0.0002;
	n++;

			makeref(itm,Items[n]);
	itm.id = "GOF_bookheavweapman";
	itm.groupID = MAPS_ITEM_TYPE
	itm.name = "GOF_itmname_bookheavweapman";
	itm.describe = "GOF_itmdescr_bookheavweapman";
	itm.model = "GOF_OpenBook";
	itm.picIndex = 13;
	itm.picTexture = "BOOKS_1";
	//itm.shown = false;
	// boal 19.01.2004 -->
	itm.price = 37500;
	itm.Weight = 3;
	itm.imageTga = "books\bookheavweapman";

	// boal 19.01.2004 <--
	itm.minlevel = 15;
	itm.rare = 0.0002;
	n++;

	// ������ 07.03.05
	makeref(itm,Items[n]);
	itm.id = "GOF_suit_1";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = true;
	itm.name = "GOF_itmname_suit_1";
	itm.describe = "GOF_itmdescr_suit_1";
	itm.folder = "items";
	itm.model = "GOF_6";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF9";
	itm.price = 10;
	itm.Weight = 6;
	itm.CirassLevel = 0.0;
	itm.minlevel = 20;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_suit_2";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = true;
	itm.name = "GOF_itmname_suit_2";
	itm.describe = "GOF_itmdescr_suit_2";
	itm.folder = "items";
	itm.model = "GOF_7";
	itm.picIndex = 16;
	itm.picTexture = "ITEMS_GOF1";
	itm.price = 10000;
	itm.Weight = 8;
	itm.CirassLevel = 0.0;
	itm.minlevel = 20;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_suit_3";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = true;
	itm.name = "GOF_itmname_suit_3";
	itm.describe = "GOF_itmdescr_suit_3";
	itm.folder = "items";
	itm.model = "GOF_8";
	itm.picIndex = 2;
	itm.picTexture = "ITEMS_GOF1";
	itm.price = 125000;
	itm.Weight = 7;
	itm.CirassLevel = 0.0;
	itm.minlevel = 20;
	itm.rare = 0.001;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_suit_4";// Privateer <-----Officerpuppy 03/02/10
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = true;
	itm.name = "GOF_itmname_suit_4";
	itm.describe = "GOF_itmdescr_suit_4";
	itm.folder = "items";
	itm.model = "GOF_6";
	itm.picIndex = 4;
	itm.picTexture = "ITEMS_GOF14";
	itm.price = 10;
	itm.Weight = 6;
	itm.CirassLevel = 0.0;
	itm.minlevel = 5;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_suit_5";// Capt. <-----Officerpuppy 03/02/10
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = true;
	itm.name = "GOF_itmname_suit_5";
	itm.describe = "GOF_itmdescr_suit_5";
	itm.folder = "items";
	itm.model = "GOF_7";
	itm.picIndex = 5;
	itm.picTexture = "ITEMS_GOF14";
	itm.price = 10000;
	itm.Weight = 7;
	itm.CirassLevel = 0.0;
	itm.minlevel = 10;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_suit_6";// Adm. <-----Officerpuppy 03/02/10
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = true;
	itm.name = "GOF_itmname_suit_6";
	itm.describe = "GOF_itmdescr_suit_6";
	itm.folder = "items";
	itm.model = "GOF_8";
	itm.picIndex = 6;
	itm.picTexture = "ITEMS_GOF14";
	itm.price = 125000;
	itm.Weight = 8;
	itm.CirassLevel = 0.0;
	itm.minlevel = 15;
	itm.rare = 0.01;
	itm.ItemType = "SUPPORT";
	n++;

	// �����
		makeref(itm,Items[n]);
	itm.id = "GOF_cirass1";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = false;
	itm.name = "GOF_itmname_cirass1";
	itm.describe = "GOF_itmdescr_cirass1";
	itm.folder = "items";
	itm.model = "GOF_1";
	itm.picIndex = 14;
	itm.picTexture = "ITEMS_GOF8";
	itm.price = 3500;
	// boal 19.01.2004 -->
	itm.Weight = 30;
	itm.CirassLevel = 0.10;
	// boal 19.01.2004 <--
	itm.minlevel = 2;
	itm.rare = 0.1;

	itm.Solder.rare = 0.01;
	itm.Solder.min = 1;
	itm.Solder.max = 1;
	
	itm.Warrior.rare = 0.01;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_cirass2";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = false;
	itm.name = "GOF_itmname_cirass2";
	itm.describe = "GOF_itmdescr_cirass2";
	itm.folder = "items";
	itm.model = "GOF_2";
	itm.picIndex = 11;
	itm.picTexture = "ITEMS_GOF8";
	itm.price = 12500;
	// boal 19.01.2004 -->
	itm.Weight = 25;
	itm.CirassLevel = 0.18;
	// boal 19.01.2004 <--
	itm.minlevel = 5;
	itm.rare = 0.1;

	itm.Solder_o.rare = 0.01;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;

	itm.Warrior.rare = 0.005;
	itm.Warrior.min = 1;
	itm.Warrior.max = 1;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_cirass3";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = false;
	itm.name = "GOF_itmname_cirass3";
	itm.describe = "GOF_itmdescr_cirass3";
	itm.folder = "items";
	itm.model = "GOF_3";
	itm.picIndex = 13;
	itm.picTexture = "ITEMS_GOF8";
	itm.price = 11000;
	// boal 19.01.2004 -->
	itm.Weight = 23;
	itm.CirassLevel = 0.27;
	// boal 19.01.2004 <--
	itm.minlevel = 9;
	itm.rare = 0.1;

	itm.Solder_o.rare = 0.003;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;
	itm.ItemType = "SUPPORT";
	n++;

	makeref(itm,Items[n]);
	itm.id = "GOF_cirass4";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = false;
	itm.name = "GOF_itmname_cirass4";
	itm.describe = "GOF_itmdescr_cirass4";
	itm.folder = "items";
	itm.model = "GOF_4";
	itm.picIndex = 12;
	itm.picTexture = "ITEMS_GOF8";
	itm.price = 9500;
	// boal 19.01.2004 -->
	itm.Weight = 20;
	itm.CirassLevel = 0.22;
	// boal 19.01.2004 <--
	itm.minlevel = 11;
	itm.rare = 0.1;
	
	itm.Solder_o.rare = 0.003;
	itm.Solder_o.min = 1;
	itm.Solder_o.max = 1;
	itm.ItemType = "SUPPORT";
	n++;
			
	makeref(itm,Items[n]);
	itm.id = "GOF_cirass5";
	itm.groupID = CIRASS_ITEM_TYPE;
	itm.Clothes = false;
	itm.name = "GOF_itmname_cirass5";
	itm.describe = "GOF_itmdescr_cirass5";
	itm.folder = "items";
	itm.model = "GOF_5";
	itm.picIndex = 10;
	itm.picTexture = "ITEMS_GOF8";
	itm.price = 15000;
	// boal 19.01.2004 -->
	itm.Weight = 17;
	itm.CirassLevel = 0.35;
	// boal 19.01.2004 <--
	itm.minlevel = 20;
	itm.rare = 0.001;
	itm.ItemType = "SUPPORT";
	n++;

	tempFixGofItems();

	// trace("����� ��������� (����������� �������) "+n);
	// trace("��������� ����������� �������: " + Items[ItemsForLocators_start].id);
	// trace("�������� ����������� �������: " + Items[ItemsForLocators_end].id);
	return n;
}

void tempFixGofItems()
{
	for(int i=0; i<GOF_ITEMS_QUANTITY; i++)
	{
		if(Items[i].ItemType == "WEAPON")
		{
			Items[i].target = TGT_SOLDIER;
			Items[i].quality = B_ORDINARY;
		}
	}
}

void InitButtons()
{
	/*aref lab3;
	makearef(lab3, Locations[FindLocation("Labirint_3")]);

	lab3.items.b_1.locator = "button01";
	lab3.items.b_1.model   = "b1";
	lab3.items.b_1.itemDeltaY  = 0.0;
	lab3.items.b_1.deltaY  = -0.05;
	lab3.items.b_1.trigged  = false;
	*/
}

/* void GofInitRandItems()
{
	ref rnditem;

	makeref(rnditem,RandItems[0]);
	rnditem.id = POTION;

	
	makeref(rnditem,RandItems[1]);
	rnditem.id = "Mineral9";  

	makeref(rnditem,RandItems[2]);
	rnditem.id = "Mineral10";  
	
	makeref(rnditem,RandItems[3]);
	rnditem.id = "jewelry16";
	
	makeref(rnditem,RandItems[4]);
	rnditem.id = "jewelry1";

	makeref(rnditem,RandItems[5]);
	rnditem.id = "jewelry2";

	makeref(rnditem,RandItems[6]);
	rnditem.id = "jewelry3";

	makeref(rnditem,RandItems[7]);
	rnditem.id = "jewelry5";

	makeref(rnditem,RandItems[8]);
	rnditem.id = "jewelry6";

	makeref(rnditem,RandItems[9]);
	rnditem.id = "jewelry7";

	makeref(rnditem,RandItems[10]);
	rnditem.id = "jewelry10";

	makeref(rnditem,RandItems[11]);
	rnditem.id = "jewelry11";

	makeref(rnditem,RandItems[12]);
	rnditem.id = "jewelry12";

	makeref(rnditem,RandItems[13]);
	rnditem.id = "jewelry13";

	makeref(rnditem,RandItems[14]);
	rnditem.id = "potion1";

	makeref(rnditem,RandItems[15]);
	rnditem.id = "indian4";

	makeref(rnditem,RandItems[16]);
	rnditem.id = "potion1";

	makeref(rnditem,RandItems[17]);
	rnditem.id = "potion2";

	makeref(rnditem,RandItems[18]);
	rnditem.id = "indian13";

	makeref(rnditem,RandItems[19]);
	rnditem.id = "potion3";

	makeref(rnditem,RandItems[20]);
	rnditem.id = "potion4";

	// boal -->
	makeref(rnditem,RandItems[21]);
	rnditem.id = "pistol3";

	makeref(rnditem,RandItems[22]);
	rnditem.id = "pistol2";

	makeref(rnditem,RandItems[23]);
	rnditem.id = "pistol1";

	makeref(rnditem,RandItems[24]);
	rnditem.id = "blade8";

	makeref(rnditem,RandItems[25]);
	rnditem.id = "blade7";

	makeref(rnditem,RandItems[26]);
	rnditem.id = "blade6";

	makeref(rnditem,RandItems[27]);
	rnditem.id = "blade5";

	makeref(rnditem,RandItems[28]);
	rnditem.id = "blade4";

	makeref(rnditem,RandItems[29]);
	rnditem.id = "blade3";

	makeref(rnditem,RandItems[30]);
	rnditem.id = "blade2";

	makeref(rnditem,RandItems[31]);
	rnditem.id = "spyglass1";

	makeref(rnditem,RandItems[32]);
	rnditem.id = "spyglass2";

	makeref(rnditem,RandItems[33]);
	rnditem.id = "blade1";

	makeref(rnditem,RandItems[34]);
	rnditem.id = "jewelry17";

	makeref(rnditem,RandItems[35]);
	rnditem.id = "jewelry18";

	makeref(rnditem,RandItems[36]);
	rnditem.id = "bullet"; // boal "Mineral1";

	makeref(rnditem,RandItems[37]);
	rnditem.id = "mineral3";

	makeref(rnditem,RandItems[38]);
	rnditem.id = "Mineral4";  

	makeref(rnditem,RandItems[39]);
	rnditem.id = "Mineral5";  

	makeref(rnditem,RandItems[40]);
	rnditem.id = "Mineral6";  

	makeref(rnditem,RandItems[41]);
	rnditem.id = "Mineral7";  

	makeref(rnditem,RandItems[42]);
	rnditem.id = "potion5";

	makeref(rnditem,RandItems[43]);
	rnditem.id = "potionwine";

	makeref(rnditem,RandItems[44]);
	rnditem.id = "potionrum";
	
	makeref(rnditem,RandItems[45]);
	rnditem.id = "bookleader_1";
	
	makeref(rnditem,RandItems[46]);
	rnditem.id = "booklight_1";

	makeref(rnditem,RandItems[47]);
	rnditem.id = "bookfencing_1";
	
	makeref(rnditem,RandItems[48]);
	rnditem.id = "bookheavy_1";

	makeref(rnditem,RandItems[49]);
	rnditem.id = "bookleader_2";
	
	makeref(rnditem,RandItems[50]);
	rnditem.id = "booklight_2";

	makeref(rnditem,RandItems[51]);
	rnditem.id = "bookfencing_2";
	
	makeref(rnditem,RandItems[52]);
	rnditem.id = "bookheavy_2";

	makeref(rnditem,RandItems[53]);
	rnditem.id = "bookleader_3";
	
	makeref(rnditem,RandItems[54]);
	rnditem.id = "booklight_3";

	makeref(rnditem,RandItems[55]);
	rnditem.id = "bookfencing_3";
	
	makeref(rnditem,RandItems[56]);
	rnditem.id = "bookheavy_3";
	
	makeref(rnditem,RandItems[57]);
	rnditem.id = "bookpistols_1";

	makeref(rnditem,RandItems[58]);
	rnditem.id = "bookluck_1";

	makeref(rnditem,RandItems[59]);
	rnditem.id = "bookstealth_1";

	makeref(rnditem,RandItems[60]);
	rnditem.id = "booknavigation_1";

	makeref(rnditem,RandItems[61]);
	rnditem.id = "bookpistols_2";

	makeref(rnditem,RandItems[62]);
	rnditem.id = "bookluck_2";

	makeref(rnditem,RandItems[63]);
	rnditem.id = "bookstealth_2";

	makeref(rnditem,RandItems[64]);
	rnditem.id = "booknavigation_2";

	makeref(rnditem,RandItems[65]);
	rnditem.id = "bookpistols_3";

	makeref(rnditem,RandItems[66]);
	rnditem.id = "bookluck_3";

	makeref(rnditem,RandItems[67]);
	rnditem.id = "bookstealth_3";

	makeref(rnditem,RandItems[68]);
	rnditem.id = "booknavigation_3";

	makeref(rnditem,RandItems[69]);
	rnditem.id = "bookaccurate_1";

	makeref(rnditem,RandItems[70]);
	rnditem.id = "bookcannon_1";

	makeref(rnditem,RandItems[71]);
	rnditem.id = "bookgrapple_1";

	makeref(rnditem,RandItems[72]);
	rnditem.id = "bookdefend_1";

	makeref(rnditem,RandItems[73]);
	rnditem.id = "bookaccurate_2";

	makeref(rnditem,RandItems[74]);
	rnditem.id = "bookcannon_2";

	makeref(rnditem,RandItems[75]);
	rnditem.id = "bookgrapple_2";

	makeref(rnditem,RandItems[76]);
	rnditem.id = "bookdefend_2";

	makeref(rnditem,RandItems[77]);
	rnditem.id = "bookaccurate_3";

	makeref(rnditem,RandItems[78]);
	rnditem.id = "bookcannon_3";

	makeref(rnditem,RandItems[79]);
	rnditem.id = "bookgrapple_3";

	makeref(rnditem,RandItems[80]);
	rnditem.id = "bookdefend_3";

	makeref(rnditem,RandItems[81]);
	rnditem.id = "bookrepairs_1";

	makeref(rnditem,RandItems[82]);
	rnditem.id = "bookmoney_1";

	makeref(rnditem,RandItems[83]);
	rnditem.id = "bookrepairs_2";

	makeref(rnditem,RandItems[84]);
	rnditem.id = "bookmoney_2";
	
	makeref(rnditem,RandItems[85]);
	rnditem.id = "bookrepairs_3";

	makeref(rnditem,RandItems[86]);
	rnditem.id = "bookmoney_3";
		
	makeref(rnditem,RandItems[87]);
	rnditem.id = "bookwrestling";
	
	makeref(rnditem,RandItems[88]);
	rnditem.id = "booklgtweapman";
		
	makeref(rnditem,RandItems[89]);
	rnditem.id = "bookmedweapman";
	
	makeref(rnditem,RandItems[90]);
	rnditem.id = "bookheavweapman";
	// boal <--
} */