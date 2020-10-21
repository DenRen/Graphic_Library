/*
 * Graphic.h
 *
 *  Created on: Oct 14, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_MENU_GRAPHIC_H_
#define GAMECORE_MENU_GRAPHIC_H_

const int WIDTH = 400;
const int HEIGHT = 400;

#include "MenuWidget.h"

class Graphic: public MenuWidget {
public:
	Graphic();
	virtual ~Graphic();
	void Init();
	void Draw();
	void Destroy();
	void Update();
	void Init(GameObject *owner);
	GameObject* Clone() const;

	// DRAW
	void drawAxis();
	void drawPoints();
};

#endif /* GAMECORE_MENU_GRAPHIC_H_ */
