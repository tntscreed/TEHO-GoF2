// правка переходов на мысе негрил

void ApplyMigration(ref migrationState) {
	ref colony = GetColonyRefByID("FortOrange");
	colony.from_sea = "Shore35";
	
	ref loc = &locations[FindLocation("Shore35")];
	loc.townsack = "FortOrange";
	loc.fastreload = "FortOrange";
	
	loc = &locations[FindLocation("FortOrange_ExitTown")];
	loc.fastreload = "FortOrange";
}
