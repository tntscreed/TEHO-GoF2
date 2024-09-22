
void OSL_WriteGameOption()
{
	object gopt;
	PrepareDefaultOption(&gopt);
	GetRealOptions(&gopt);
	SaveSavedOptions(&gopt);
}

void OSL_ReadGameOption()
{
	object gopt;
	PrepareDefaultOption(&gopt);
	ReadSavedOptions(&gopt);
	SetCurentOptions(&gopt);
}

void PrepareDefaultOption(ref optref)
{   // belamour побережем уши )))
	optref.volume.music = 0.1;
	optref.volume.sound = 0.1;
	optref.volume.dialog = 0.1;
	optref.cameramode.follow_on = true;
	/*
	optref.arcademode.bArcadeSails = true;
	optref.arcademode.bArcadeShipSpeed = true;
	optref.arcademode.bArcadeCannonsReload = true;
	optref.arcademode.bArcadeCannonsAccuracy = true;
	optref.arcademode.bArcadeFencingAI = true;
	optref.arcademode.bArcadeFencingDamage = true;
	optref.arcademode.bArcadeFencingEquip = true;
	optref.arcademode.bArcadeSailTo = true;
	*/
	optref.alwaysrun = true;
	optref.video.grassquantity = 0;
	optref.seadetails = 1.0;
	
	SeaParametrs.MaxVertices = MaxVertices;
	SeaParametrs.MaxIndices = MaxIndices;
	SeaParametrs.GridStepX = GridStepX;
	SeaParametrs.GridStepPC = GridStepPC;
	SeaParametrs.LodScale = LodScale;
	SeaParametrs.MaxWaveDistance = MaxWaveDistance;
}

void GetRealOptions(ref optref)
{
	float ftmp1,ftmp2,ftmp3;

	ftmp1 = stf(optref.volume.sound);
	ftmp2 = stf(optref.volume.music);
	ftmp3 = stf(optref.volume.dialog);
	SendMessage(&sound,"leee", MSG_SOUND_GET_MASTER_VOLUME, &ftmp1, &ftmp2,	&ftmp3 );
	optref.volume.sound = ftmp1;
	optref.volume.music = ftmp2;
	optref.volume.dialog = ftmp3;

	/*
	optref.arcademode.bArcadeSails = bArcadeSails;
	optref.arcademode.bArcadeShipSpeed = bArcadeShipSpeed;
	optref.arcademode.bArcadeCannonsReload = bArcadeCannonsReload;
	optref.arcademode.bArcadeCannonsAccuracy = bArcadeCannonsAccuracy;
	optref.arcademode.bArcadeFencingAI = bArcadeFencingAI;
	optref.arcademode.bArcadeFencingDamage = bArcadeFencingDamage;
	optref.arcademode.bArcadeFencingEquip = bArcadeFencingEquip;
	optref.arcademode.bArcadeSailTo = bArcadeSailTo;
	*/

	optref.cameramode.follow_on = !locCameraEnableSpecialMode;

	optref.video.grassquantity = iGrassQuality;
	if( CheckAttribute(&InterfaceStates,"SeaDetails") ) {
		optref.seadetails = stf(InterfaceStates.SeaDetails);
	}

	if( CheckAttribute(&InterfaceStates,"InvertCameras") ) {
		optref.cameramode.InvertCameras = sti(InterfaceStates.InvertCameras);
	} else {
		optref.cameramode.InvertCameras = false;
	}

	if( CheckAttribute(&InterfaceStates,"ShowBattleMode") ) {
		optref.cameramode.ShowBattleMode = sti(InterfaceStates.ShowBattleMode);
	} else {
		optref.cameramode.ShowBattleMode = false;
	}

	if( CheckAttribute(&InterfaceStates,"EnabledAutoSaveMode") ) {
		optref.cameramode.EnabledAutoSaveMode = sti(InterfaceStates.EnabledAutoSaveMode);
	} else {
		optref.cameramode.EnabledAutoSaveMode = true;
	}

	if( CheckAttribute(&InterfaceStates,"EnabledQuestsMarks") ) {
		optref.cameramode.EnabledQuestsMarks = sti(InterfaceStates.EnabledQuestsMarks);
	} else {
		optref.cameramode.EnabledQuestsMarks = true;
	}

	if( CheckAttribute(&InterfaceStates,"EnabledShipMarks") ) {
		optref.cameramode.EnabledShipMarks = sti(InterfaceStates.EnabledShipMarks);
	} else {
		optref.cameramode.EnabledShipMarks = true;
	}
	bDrawBars = sti(optref.cameramode.EnabledShipMarks);

	if( CheckAttribute(&InterfaceStates,"SimpleSea") ) {
		optref.cameramode.SimpleSeaMode = sti(InterfaceStates.SimpleSea);
	} else {
		optref.cameramode.SimpleSeaMode = true;
	}
	// belamour -->
	if( CheckAttribute(&InterfaceStates,"DIRECTSAIL") ) {
		optref.cameramode.DIRECTSAILMode = sti(InterfaceStates.DIRECTSAIL);
	} else {
		optref.cameramode.DIRECTSAILMode = false;
	}
	
	if( CheckAttribute(&InterfaceStates,"CREWONDECK") ) {
		optref.cameramode.CREWONDECKMode = sti(InterfaceStates.CREWONDECK);
	} else {
		optref.cameramode.CREWONDECKMode = true;
	}
	
	if( CheckAttribute(&InterfaceStates,"CAMERASWING") ) {
		optref.cameramode.CAMERASWINGMode = sti(InterfaceStates.CAMERASWING);
	} else {
		optref.cameramode.CAMERASWINGMode = true;
	}
	
	if( CheckAttribute(&InterfaceStates,"ENHANCEDSAILING") ) {
		optref.cameramode.ENHANCEDSAILINGMode = sti(InterfaceStates.ENHANCEDSAILING);
	} else {
		optref.cameramode.ENHANCEDSAILINGMode = false;
	}
	
	if( CheckAttribute(&InterfaceStates,"ROTATESKY") ) {
		optref.cameramode.ROTATESKYMode = sti(InterfaceStates.ROTATESKY);
	} else {
		optref.cameramode.ROTATESKYMode = false;
	}
	if( CheckAttribute(&InterfaceStates,"DYNAMICLIGHTS") ) {
		optref.cameramode.DYNAMICLIGHTSMode = sti(InterfaceStates.DYNAMICLIGHTS);
	} else {
		optref.cameramode.DYNAMICLIGHTSMode = false;
	}
	// <-- belamour
	GetControlsOptions(optref);

	// mouse
	if( CheckAttribute(&InterfaceStates,"mouse.x_sens") ) {
		optref.mouse.x_sensitivity = InterfaceStates.mouse.x_sens;
	} else {
		optref.mouse.x_sensitivity = 0.5;
	}
	if( CheckAttribute(&InterfaceStates,"mouse.y_sens") ) {
		optref.mouse.y_sensitivity = InterfaceStates.mouse.y_sens;
	} else {
		optref.mouse.y_sensitivity = 0.5;
	}
	// video colors
	if( CheckAttribute(&InterfaceStates,"video.contrast") ) {
		optref.video.contrast = InterfaceStates.video.contrast;
	} else {
		optref.video.contrast = 1.0;
	}
	if( CheckAttribute(&InterfaceStates,"video.gamma") ) {
		optref.video.gamma = InterfaceStates.video.gamma;
	} else {
		optref.video.gamma = 1.0;
	}
	if( CheckAttribute(&InterfaceStates,"video.brightness") ) {
		optref.video.brightness = InterfaceStates.video.brightness;
	} else {
		optref.video.brightness = 0.0;
	}
	
	// Warship 07.07.09 Эффект свечения
	if(CheckAttribute(&InterfaceStates, "GlowEffect"))
	{
		optref.GlowEffect = InterfaceStates.GlowEffect;
	}
	else
	{
		optref.GlowEffect = 50;
	}
	
	SeaParametrs.MaxVertices = MaxVertices;
	SeaParametrs.MaxIndices = MaxIndices;
	SeaParametrs.GridStepX = GridStepX;
	SeaParametrs.GridStepPC = GridStepPC;
	SeaParametrs.MaxWaveDistance = MaxWaveDistance;
	SeaParametrs.LodScale = LodScale;

	// always run
	if( CheckAttribute(&InterfaceStates,"alwaysrun") ) {
		optref.alwaysrun = InterfaceStates.alwaysrun;
	} else {
		optref.alwaysrun = false;
	}
	// belamour перспектива морской камеры
	if(CheckAttribute(&InterfaceStates, "SEACAMPERSP"))
	{
		optref.SEACAMPERSP = InterfaceStates.SEACAMPERSP;
	}
	else
	{
		optref.SEACAMPERSP = 25;
	}
}

void SetCurentOptions(ref optref)
{
	SendMessage(&sound,"lfff", MSG_SOUND_SET_MASTER_VOLUME, stf(optref.volume.sound),	stf(optref.volume.music),	stf(optref.volume.dialog));

	/*bArcadeSails = sti(optref.arcademode.bArcadeSails);
	bArcadeShipSpeed = sti(optref.arcademode.bArcadeShipSpeed);
	bArcadeCannonsReload = sti(optref.arcademode.bArcadeCannonsReload);
	bArcadeCannonsAccuracy = sti(optref.arcademode.bArcadeCannonsAccuracy);
	bArcadeFencingAI = sti(optref.arcademode.bArcadeFencingAI);
	bArcadeFencingDamage = sti(optref.arcademode.bArcadeFencingDamage);
	bArcadeFencingEquip = sti(optref.arcademode.bArcadeFencingEquip);
	bArcadeSailTo = sti(optref.arcademode.bArcadeSailTo);
	*/
	locCameraEnableSpecialMode = !sti(optref.cameramode.follow_on);
	
	/*
	SeaMaxVertices
	SeaMaxIndices
	SeaGridStep
	SeaMaxWaveDistance
	*/

	if( CheckAttribute(optref,"cameramode.ShowBattleMode") ) {
		InterfaceStates.ShowBattleMode = optref.cameramode.ShowBattleMode;
	} else {
		InterfaceStates.ShowBattleMode = false;
	}

	if( CheckAttribute(optref,"cameramode.EnabledAutoSaveMode") ) {
		InterfaceStates.EnabledAutoSaveMode = optref.cameramode.EnabledAutoSaveMode;
	} else {
		InterfaceStates.EnabledAutoSaveMode = true;
	}

	if( CheckAttribute(optref,"cameramode.EnabledQuestsMarks") ) {
		InterfaceStates.EnabledQuestsMarks = optref.cameramode.EnabledQuestsMarks;
	} else {
		InterfaceStates.EnabledQuestsMarks = true;
	}

	if( CheckAttribute(optref,"cameramode.EnabledShipMarks") ) {
		InterfaceStates.EnabledShipMarks = optref.cameramode.EnabledShipMarks;
	} else {
		InterfaceStates.EnabledShipMarks = true;
	}

	if( CheckAttribute(optref,"cameramode.SimpleSeaMode") ) {
		InterfaceStates.SimpleSea = optref.cameramode.SimpleSeaMode;
	} else {
		InterfaceStates.SimpleSea = false;
	}
	// belamour
	if( CheckAttribute(optref,"cameramode.DIRECTSAILMode") ) {
		InterfaceStates.DIRECTSAIL = optref.cameramode.DIRECTSAILMode;
	} else {
		InterfaceStates.DIRECTSAIL = false;
	}
	
	if( CheckAttribute(optref,"cameramode.CREWONDECKMode") ) {
		InterfaceStates.CREWONDECK = optref.cameramode.CREWONDECKMode;
	} else {
		InterfaceStates.CREWONDECK = true; // заполнить чекбокс
	}
	
	if( CheckAttribute(optref,"cameramode.CAMERASWINGMode") ) {
		InterfaceStates.CAMERASWING = optref.cameramode.CAMERASWINGMode;
	} else {
		InterfaceStates.CAMERASWING = true;
	}
	
	if( CheckAttribute(optref,"cameramode.ENHANCEDSAILINGMode") ) {
		InterfaceStates.ENHANCEDSAILING = optref.cameramode.ENHANCEDSAILINGMode;
	} else {
		InterfaceStates.ENHANCEDSAILING = false;
	}
	
	if( CheckAttribute(optref,"cameramode.ROTATESKYMode") ) {
		InterfaceStates.ROTATESKY = optref.cameramode.ROTATESKYMode;
	} else {
		InterfaceStates.ROTATESKY = false;
	}
	if( CheckAttribute(optref,"cameramode.DYNAMICLIGHTSMode") ) {
		InterfaceStates.DYNAMICLIGHTS = optref.cameramode.DYNAMICLIGHTSMode;
	} else {
		InterfaceStates.DYNAMICLIGHTS = false;
	}

	// mouse
	if( CheckAttribute(optref,"cameramode.InvertCameras") ) {
		InterfaceStates.InvertCameras = optref.cameramode.InvertCameras;
	} else {
		InterfaceStates.InvertCameras = false;
	}
	if( CheckAttribute(optref,"mouse.x_sensitivity") ) {
		InterfaceStates.mouse.x_sens = optref.mouse.x_sensitivity;
	} else {
		InterfaceStates.mouse.x_sens = 0.5;
	}
	if( CheckAttribute(optref,"mouse.y_sensitivity") ) {
		InterfaceStates.mouse.y_sens = optref.mouse.y_sensitivity;
	} else {
		InterfaceStates.mouse.y_sens = 0.5;
	}
	// video colors
	if( CheckAttribute(optref,"video.contrast") ) {
		InterfaceStates.video.contrast = optref.video.contrast;
	} else {
		InterfaceStates.video.contrast = 1.0;
	}
	if( CheckAttribute(optref,"video.gamma") ) {
		InterfaceStates.video.gamma = optref.video.gamma;
	} else {
		InterfaceStates.video.gamma = 1.0;
	}
	if( CheckAttribute(optref,"video.brightness") ) {
		InterfaceStates.video.brightness = optref.video.brightness;
	} else {
		InterfaceStates.video.brightness = 0.0;
	}
	
	// Warship 07.07.09 Эффект свечения
	if(CheckAttribute(optref, "GlowEffect"))
	{
		InterfaceStates.GlowEffect = optref.GlowEffect;
	}
	else
	{
		InterfaceStates.GlowEffect = 50;
	}
	
	SetGlowParams(1.0, sti(InterfaceStates.GlowEffect), 2);
	
	if( CheckAttribute(optref,"video.grassquantity") ) {
		iGrassQuality = sti(optref.video.grassquantity);
	}
	if( CheckAttribute(optref,"seadetails") ) {
		InterfaceStates.SeaDetails = stf(optref.seadetails);
	}

	XI_SetColorCorrection(stf(InterfaceStates.video.contrast),stf(InterfaceStates.video.gamma),stf(InterfaceStates.video.brightness));

	aref arControls;
	makearef(arControls,optref.controls);
	RestoreKeysFromOptions(arControls);

	// always run
	if( CheckAttribute(&optref,"alwaysrun") ) {
		InterfaceStates.alwaysrun = optref.alwaysrun;
	} else {
		InterfaceStates.alwaysrun = false;
	}

	ControlsMakeInvert();
	SetRealMouseSensitivity();
	// belamour перспектива морской камеры
	if(CheckAttribute(optref, "SEACAMPERSP"))
	{
		InterfaceStates.SEACAMPERSP = optref.SEACAMPERSP;
	}
	else
	{
		InterfaceStates.SEACAMPERSP = 25;
	}
}

void ReadSavedOptions(ref gopt)
{
	string sFileName = "options";
	if( CheckAttribute(&PlayerProfile,"name") && PlayerProfile.name!="" ) {
		sFileName = "save\"+PlayerProfile.name+"\options\options";
	}
	SendMessage(&GameInterface, "lsa", MSG_INTERFACE_LOADOPTIONS, sFileName, gopt);
}

void SaveSavedOptions(ref gopt)
{
	string sFileName = "options";
	if( CheckAttribute(&PlayerProfile,"name") && PlayerProfile.name!="" ) {
		sFileName = "save\"+PlayerProfile.name+"\options\options";
	}
	SendMessage(&GameInterface, "lsa", MSG_INTERFACE_SAVEOPTIONS, sFileName, gopt);
}

void GetControlsOptions(ref optref)
{
	int ng,qg, nc,qc;
	aref arIn, arOut, arGrp, arCntrl;
	string grName, cntrlName;

	makearef(arOut,objControlsState.keygroups);
	optref.controls = true;
	makearef(arIn,optref.controls);

	qg = GetAttributesNum(arOut);
	for(ng=0; ng<qg; ng++)
	{
		arGrp = GetAttributeN(arOut,ng);
		grName = GetAttributeName(arGrp);
		if( CheckAttribute(&objControlsState,"grouplist."+grName) && sti(objControlsState.grouplist.(grName))==true )
		{
			qc = GetAttributesNum(arGrp);
			for(nc=0; nc<qc; nc++)
			{
				arCntrl = GetAttributeN(arGrp,nc);
				if( CheckAttribute(arCntrl,"remapping") && sti(arCntrl.remapping)==true )
				{
					cntrlName = GetAttributeName(arCntrl);
					arIn.(grName).(cntrlName) = GetAttributeValue(arCntrl);
					arIn.(grName).(cntrlName).state = arCntrl.state;
				}
			}
		}
	}
}
