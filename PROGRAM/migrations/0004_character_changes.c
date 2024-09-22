void ApplyMigration(ref migrationState) {
	// правки связанные со смертью фантомов
	if (firstFreeCharacter == -1) {
		for (int i = GlobalCharacters; i < MAX_CHARACTERS; i++) {
			ref chr = GetCharacter(i);
			if (!CheckAttribute(chr, "id") || chr.id == "0") {
				FreeCharacter(i);
			}
		}
		trace("Освободили " + (firstFreeCharacter + 1));
	}
	
	// правка бага инита предметов в бете
	ref sld = ItemsFromID("pistol2");
	sld.type.t1.bullet = "grapeshot";
	
	bool found = false;
	for (i = 0; i < ITEMS_QUANTITY; i++) {
		sld = &items[i];
		if (sld.id == "shamshir") {
			if (found) {
				sld.id = "Reserve_item";
			} else {
				found = true;
			}
		}
	}
}
