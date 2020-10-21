#include "Settings.h"

#include <bits/types/FILE.h>
#include <cstdio>
#include <string>

#include "../../Engine/Graphics/GraphicManager.h"
#include "../Storage/Views.h"
#include "PTC.h"

Vector2U Settings::resolution = { 0, 0 };

Settings::Settings() {
	resolution = { 0, 0 };
}

void Settings::LOAD_SETTINGS() {
	FILE *settings_file = freopen("./settings.cfg", "r", stdin);

	if (settings_file == nullptr) {
		PTC::say("Failed to open the settings.cfg file", error, high);
		return;
	}

	// RESOLUTION SETTINGS
	if (scanf("RESOLUTION=%ux%u\n", &resolution.x, &resolution.y) != 2) {
		// ERROR
		PTC::say("Error loading resolution! Loading default settings...\n", error, high);
		LOAD_DEFAULT();
		return;
	}
	GraphicManager::SetResolution(resolution);
	Views::SET_RESOLUTION(resolution);

	// CONTROLS SETTINGS
	scanf("CONTROLS:\n");

	char junk[256] = { };

	for (unsigned i = 0; i < keys_number; i++) {
		unsigned int game_key = 0;
		unsigned int keyboard_key = 0;

		if (scanf("%[^(](%u:=%u)\n", junk, &game_key, &keyboard_key) != 3) {
			// ERROR
			PTC::say("Error loading controls! Loading default settings...\n", error, high);
			LOAD_DEFAULT();
			return;
		}

		Controls::tags[i] = junk;
		Controls::linking[game_key] = static_cast<KeyboardKey>(keyboard_key);
	}

	fclose(settings_file);
}

void Settings::SAVE_SETTINGS() {
	FILE *settings_file = fopen("./settings.cfg", "w");

	if (settings_file == nullptr) {
		PTC::say("Failed to open the settings.cfg file", error, high);
		return;
	}

	// RESOLUTION
	resolution = GraphicManager::GetResolution();
	fprintf(settings_file, "RESOLUTION=%ux%u\n", resolution.x, resolution.y);

	// CONTROLS
	fprintf(settings_file, "CONTROLS:\n");
	for (unsigned i = 0; i < keys_number; i++) {
		fprintf(settings_file, "%s(%u:=%u)\n", Controls::tags[i].c_str(), i, Controls::linking[i]);
	}

	fclose(settings_file);
}

void Settings::LOAD_DEFAULT() {
	// RESOLUTION
	GraphicManager::SetResolution(default_resolution);
	Views::SET_RESOLUTION(default_resolution);

	// CONTROLS
	for (unsigned i = 0; i < keys_number; i++) {
		Controls::linking[i] = default_linking[i];
	}
}

Settings::~Settings() {}
