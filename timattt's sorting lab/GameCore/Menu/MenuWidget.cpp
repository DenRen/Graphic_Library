#include "MenuWidget.h"

#include "../../Engine/Gameplay/GameObject.h"

#include <cstdio>

MenuWidget::MenuWidget()
{
	current_scene = nullptr;
	sprite_id = -1;
	_size = {0, 0};
	view_id = 0;
	layer = 0;
}

void MenuWidget::setScene(MenuScene* _scene)
{
	current_scene = _scene;
}

void MenuWidget::setSpriteID(unsigned _id)
{
	sprite_id = _id;
}

GameObject* MenuWidget::Clone() const
{
	printf("Error! Cloning MenuWidget isn't supported\n");

	return nullptr;
}

void MenuWidget::SetSize(Vector2F __size) {
	_size = __size;
}

Vector2F MenuWidget::GetSize() {
	return _size;
}

void MenuWidget::SetView(unsigned id)
{
	view_id = id;
}

MenuWidget::~MenuWidget() {
}

void MenuWidget::debugPrint()
{
	printf("==========================\n");
	printf("Size: %g %g\n", _size.x, _size.y);
	printf("Position: %g %g\n", _pos.x, _pos.y);
	printf("==========================\n");
}
