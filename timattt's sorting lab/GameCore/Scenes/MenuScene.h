#pragma once

#include <vector>

#include "../../Engine/AllEngine.h"
#include "../Menu/MenuWidget.h"

class MenuWidget;

//! Class MenuScene. Usage:
//! 1) Inherit your menu class from this class
//! 2) Overwrite Init(), Update() and Destroy
//! 3) Create all widgets in YOUR_MENU_SCENE::Init()
//! 4) Update and draw them in YOUR_MENU_SCENE::Update() and
//!	   call updateWidgets() and drawWidgets()
//! 5) Destroy them in YOUR_MENU_SCENE::Destroy() (more in comments in widgets)

class MenuScene : public Scene {
protected:
	//! Shows whether the scene is active (for correct switching scenes with buttons)
	bool is_active;
	//! Vector that contains all buttons of this menu
	std::vector<MenuWidget*> *widgets;
public:
	MenuScene();

	//! Draw all widgets from the vector
	void drawWidgets();
	//! Update all widgets from the vector
	void updateWidgets();
	//! Sets the 'is_active' variable to false
	void disableScene();
	//! Destroys all widgets
	void destroyWidgets();

	//! The Init() method should include creating all widgets and putting them into the suitable vector
	virtual void Init() = 0;
	virtual void Update() = 0;
	//! The Destroy() method should include deleting all widgets in order to free memory
	virtual void Destroy() = 0;

	virtual ~MenuScene();
};
