/*
 * SLScene.h
 *
 *  Created on: Oct 14, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_SCENES_SLSCENE_H_
#define GAMECORE_SCENES_SLSCENE_H_

#include "MenuScene.h"

class SLScene : public MenuScene {
public:
	SLScene();
	virtual ~SLScene();

	// OVERRIDE
	void Init();
	void Update();
	void Destroy();
};

#endif /* GAMECORE_SCENES_SLSCENE_H_ */
