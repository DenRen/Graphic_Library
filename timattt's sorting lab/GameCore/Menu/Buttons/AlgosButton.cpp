/*
 * AlgosButton.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: timattt
 */

#include "AlgosButton.h"

#include <stddef.h>

#include "../../../Engine/Utility/Coordinate.h"
#include "../../SorterLab.h"
#include "../../Storage/Textures.h"
#include "../../Storage/Views.h"

AlgosButton::AlgosButton(sortResult (*sort_func)(int * arr, int sz), int index, int texture) {
	this->sort_func = sort_func;
	this->_size.x = 200;
	this->_size.y = 200;
	this->_pos.x = -400;
	this->_pos.y =  400 - index * 300;
	this->sprite_id = Textures::GRID;
	this->view_id = Views::BASE_VIEW;
	this->sprite_id = texture;
}

AlgosButton::AlgosButton() {
	this->sort_func = NULL;
}

AlgosButton::~AlgosButton() {
}

void AlgosButton::Init() {
}

void AlgosButton::Destroy() {
}

void AlgosButton::leftClickReact() {
	SorterLab::recalculatePoints(sort_func);
}

void AlgosButton::rightClickReact() {
}

void AlgosButton::disfocusReact() {
}

void AlgosButton::focusReact() {
}

void AlgosButton::Init(GameObject *owner) {

}

