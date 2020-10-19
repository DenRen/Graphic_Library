#pragma once

#include "../../Engine/AllEngine.h"
#include "../Scenes/MenuScene.h"

class MenuScene;

class MenuWidget: public GameObject {
protected:
	//! A pointer to the menu scene where this object is situated
	MenuScene *current_scene;

	//! A sprite ID that is meant to be put in the DrawData
	unsigned sprite_id;

	// Size of the sprite
	Vector2F _size;

	// View id where this widget is situated
	unsigned view_id;

	// Layer(=0 by default)
	unsigned layer;
public:
	MenuWidget();

	//! Sets the scalar position
	void setScene(MenuScene *_scene);
	void setSpriteID(unsigned _id);

	//! Set and get size of the button
	void SetSize(Vector2F __size);
	Vector2F GetSize();

	virtual void Init(GameObject *owner) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;

	void debugPrint();

	//! Sets the view where this button is situated
	void SetView(unsigned id);

	//! Useless function for menu widgets
	GameObject* Clone() const override;

	virtual ~MenuWidget();

	void setLayer(unsigned layer) {
		this->layer = layer;
	}
};
