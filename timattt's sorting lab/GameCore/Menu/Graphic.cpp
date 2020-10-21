/*
 * Graphic.cpp
 *
 *  Created on: Oct 14, 2020
 *      Author: timattt
 */

#include "Graphic.h"

#include "../../Engine/Debugger/Debugger.h"
#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../SorterLab.h"
#include "../Storage/Textures.h"
#include "../Storage/Views.h"

Graphic::Graphic() {
}

Graphic::~Graphic() {
}

void Graphic::Init() {
}

void Graphic::Draw() {
	drawAxis();
	drawPoints();
}

void Graphic::Destroy() {
}

void Graphic::Update() {
}

void Graphic::Init(GameObject *owner) {
}

GameObject* Graphic::Clone() const {
	return nullptr;
}

void Graphic::drawAxis() {
	DrawData axis = { };
	axis.size = { WIDTH, HEIGHT };
	axis.origin = { 0.5, 0.5 };
	axis.position = { 0, 0 };
	axis.spriteID = Textures::GRID;
	GraphicManager::Draw(axis, Views::BASE_VIEW);
}

void Graphic::drawPoints() {
	for (int i = 0; i < TOTAL_POINTS; i++) {
		float x = (int) ((float) WIDTH / (float) TOTAL_POINTS * (float) i)
				- WIDTH / 2;
		float y = (float) SorterLab::result[i].total_compars
				/ (float) MAX_ACTIONS * (float) HEIGHT - HEIGHT / 2;

		if (y < HEIGHT / 2)
			Debugger::DrawPoint( { x, y }, 3, Views::BASE_VIEW, { 255, 0, 0 }, 1);

		y = (float) SorterLab::result[i].total_swaps / (float) MAX_ACTIONS
		  * (float) HEIGHT - HEIGHT / 2;

		if (y < HEIGHT / 2)
			Debugger::DrawPoint( { x, y }, 3, Views::BASE_VIEW, { 0, 0, 255 }, 1);
	}
}
