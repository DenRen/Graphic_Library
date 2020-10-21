#include "MenuScene.h"

#include <cstdio>
#include <iostream>

MenuScene::MenuScene() {
	widgets = nullptr;
	is_active = true;
}

void MenuScene::drawWidgets() {
	for (auto widget : *widgets) {
		widget->Draw();
	}
}

void MenuScene::updateWidgets() {
	for (auto widget : *widgets) {
		widget->Update();
	}
}

void MenuScene::disableScene() {
	is_active = false;
}

MenuScene::~MenuScene() {
}

void MenuScene::destroyWidgets() {
	for (auto widget : *widgets) {
		widget->Destroy();
		delete widget;
	}
	widgets->clear();
	delete widgets;
}
