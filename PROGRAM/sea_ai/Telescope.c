void Telescope_Request()
{
	int nTelescopeIn = GetEventData();
	if (FindCharacterItemByGroup(pchar, SPYGLASS_ITEM_TYPE) == "") return;

	if( GetCharacterEquipByGroup(pchar,SPYGLASS_ITEM_TYPE)=="" ) {
		nTelescopeIn = 0;
	}
	//if( nTelescopeIn!=0 && SeaCameras.Camera=="SeaDeckCamera" ) {
	if( nTeleScopeIn!=0 && Scene.Camera == DECK_CAMERA ) { // Vex Camera Fix
		SendMessage(&objISpyGlass, "ll", MSG_TELESCOPE_REQUEST,1);
	} 
	else 
	{
		SendMessage(&objISpyGlass, "ll", MSG_TELESCOPE_REQUEST,0);
	}
}

void Telescope_Off()
{
	SendMessage(&objISpyGlass, "ll", MSG_TELESCOPE_REQUEST, 0);
}