/*
 * SLScene.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: timattt
 */

#include "SLScene.h"

#include <vector>

#include "../Menu/Buttons/AlgosButton.h"
#include "../Menu/Graphic.h"
#include "../Storage/Algoses.h"
#include "../Storage/Textures.h"

SLScene::SLScene() {

}

SLScene::~SLScene() {

}

void SLScene::Init() {
	widgets = new std::vector<MenuWidget*>;
	widgets->push_back(new Graphic);

	widgets->push_back(new AlgosButton(Algoses::n2_sort, 0, Textures::N2));
	widgets->push_back(new AlgosButton(Algoses::bubble_sort, 1, Textures::BUBBLE));
	widgets->push_back(new AlgosButton(Algoses::tQsort, 2, Textures::NLOGN));
}

void SLScene::Update() {
	updateWidgets();
	drawWidgets();
}

void SLScene::Destroy() {
	destroyWidgets();
}
