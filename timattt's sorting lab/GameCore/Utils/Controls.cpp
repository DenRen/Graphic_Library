#include "Controls.h"

KeyboardKey Controls::linking[keys_number] = { };
std::string Controls::tags[keys_number] = { "RIGHT", "LEFT", "UP", "DOWN",
		"OPEN_INV", "BACK", "PLUS", "MINUS" };

void Controls::LOAD_ALL_GAMEKEYS() {
	for (unsigned i = 0; i < keys_number; i++) {
		InputManager::LinkToCode(linking[i], i);
	}
}
