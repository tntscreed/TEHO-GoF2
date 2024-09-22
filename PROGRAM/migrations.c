// mitrokosta переработка контроля версий

extern void ApplyMigration(ref migrationState); // функция которую нужно переопределить в файле конкретной миграции

void ApplyMigrations() {
	trace("Applying migrations...");
	// построение списка миграций
	int migrationsNum = 0;
	string migrationsList[2];
	
    object fileFinder;
	fileFinder.dir = "PROGRAM\migrations";
	fileFinder.mask = "????_*.c";
	CreateEntity(&fileFinder, "FINDFILESINTODIRECTORY");
	DeleteClass(&fileFinder);
	
	aref fileList;
	makearef(fileList, fileFinder.filelist);
	int filesNum = GetAttributesNum(fileList);
	
	if (filesNum > 1) {
		SetArraySize(&migrationsList, filesNum);
	}
	
	string migrationDir = "migrations";
	for (int i = 0; i < filesNum; i++) {
		aref file = GetAttributeN(fileList, i);
		string fileName = GetAttributeValue(file);
		
		string numString = strcut(&fileName, 0, 3);
		int migrationIndex = sti(numString);
		
		// индексы пусть с 1 начинаются, т.к. 0 - признак облома
		if (migrationIndex < 1) {
			trace("Found invalid migration file " + fileName);
		}
		
		trace("Found migration file " + fileName);
		
		migrationsList[migrationIndex - 1] = migrationDir + "\" + fileName;
	}
	
	// последовательное применение миграций с сохранением загруженных сегментов
	object migrationState;
	aref migrations;
	makearef(migrations, pchar.migrations);
	for (i = 0; i < filesNum; i++) {
		fileName = migrationsList[i];
		if (fileName == "") {
			continue;
		}
		
		string migrationName = strcut(&fileName, strlen(migrationDir) + 6, strlen(fileName) - 3);
		
		// миграция уже применена
		string migrationId = "id" + (i + 1);
		if (CheckAttribute(migrations, migrationId) && migrations.(migrationId) == migrationName) {
			continue;
		}
		
		if (!LoadSegment(fileName)) {
			trace("Error! Can't load migration file " + fileName);
			continue;
		}
		
		trace("Applying " + fileName + "...");
		
		ApplyMigration(&migrationState);
		migrations.(migrationId) = migrationName;
		UnloadSegment(fileName);
		
		trace("Success...");
	}
	
	Migration_UnloadSegments(&migrationState);
}

// действуем в предположении того, что все имеющиеся миграции есть в инитах, как и должно быть по-хорошему
void InitMigrations() {
	trace("Initializing migrations...");
	
	object fileFinder;
	fileFinder.dir = "PROGRAM\migrations";
	fileFinder.mask = "????_*.c";
	CreateEntity(&fileFinder, "FINDFILESINTODIRECTORY");
	DeleteClass(&fileFinder);
	
	aref fileList;
	makearef(fileList, fileFinder.filelist);
	int filesNum = GetAttributesNum(fileList);
	
	aref migrations;
	makearef(migrations, pchar.migrations);
	for (int i = 0; i < filesNum; i++) {
		aref file = GetAttributeN(fileList, i);
		string fileName = GetAttributeValue(file);
		
		string numString = strcut(&fileName, 0, 3);
		int migrationIndex = sti(numString);
		
		// индексы пусть с 1 начинаются, т.к. 0 - признак облома
		if (migrationIndex < 1) {
			trace("Found invalid migration file " + fileName);
		}
		
		string migrationId = "id" + migrationIndex;
		string migrationName = strcut(&fileName, 5, strlen(fileName) - 3);
		migrations.(migrationId) = migrationName;
		
		trace("Marked migration " + fileName + " as complete...");
	}
}

bool Migration_LoadSegment(ref migrationState, string fileName) {
	aref segments;
	makearef(segments, migrationState.segments);
	
	int segmentsCount = GetAttributesNum(segments);
	for (int i = 0; i < segmentsCount; i++) {
		// сегмент уже загружен
		if (fileName == GetAttributeValue(GetAttributeN(segments, i))) {
			return true;
		}
	}
	
	if (!LoadSegment(fileName)) {
		return false;
	}
	
	string attr = "id" + (segmentsCount + 1);
	segments.(attr) = fileName;
	trace("Loaded segment " + fileName);
	return true;
}

void Migration_UnloadSegments(ref migrationState) {
	aref segments;
	makearef(segments, migrationState.segments);
	
	int segmentsCount = GetAttributesNum(segments);
	for (int i = 0; i < segmentsCount; i++) {
		string fileName = GetAttributeValue(GetAttributeN(segments, i));
		UnloadSegment(fileName);
		trace("Unloaded segment " + fileName);
	}
}
