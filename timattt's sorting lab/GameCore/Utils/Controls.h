#pragma once

#include <string>

#include "../../Engine/Control/InputManager.h"

// ����������� ������� ������
const unsigned keys_number = 8;

// ����� ��� ���������� � �������� ����� ����������
class Controls {
public:
	Controls() {}

	// ����� ����������� ��� ������������ ������� � ����
	enum GameKeys {
		RIGHT, LEFT, UP, DOWN, OPEN_INV, BACK, PLUS, MINUS
	};
	// ������, ��� ������ - GAMEKEYS, � �������� - ENGINE VIRTUAL KEY
	static KeyboardKey linking[keys_number];

	// �������� ���� ����������� ������ (��� ����� � �����������)
	static std::string tags[keys_number];

	// ��������� ��� ������� (����� �������� ���� ������ � ������ linking)
	static void LOAD_ALL_GAMEKEYS();

	~Controls() {}

	friend class Settings;
};
