#pragma once

#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "Controls.h"

//! settings.cfg documentation:
//! RESOLUTION=1024x576 - the resolution of the game window
//! CONTROLS - start for the controls block.
//! RIGHT[0=84] - RIGHT is the abstract name (for people, not for computer),
//! "0" is the INDEX from the GAMEKEYS, "84" is the index from the ENGINE VIRTUAL KEYS

// Default settings
const Vector2U default_resolution = { 1024, 576 };
const KeyboardKey default_linking[keys_number] = { KeyboardKey::RIGHT,
		KeyboardKey::LEFT, KeyboardKey::UP, KeyboardKey::DOWN, KeyboardKey::E,
		KeyboardKey::ESC, KeyboardKey::EQUAL, KeyboardKey::MINUS };

class Settings {
public:
	Settings();

	static Vector2U resolution;

	// Loads all settings from the file "settings.cfg"
	static void LOAD_SETTINGS();
	// Loads default settings
	static void LOAD_DEFAULT();
	// Saves current settings into the file "settings.cfg"
	static void SAVE_SETTINGS();

	~Settings();
};
