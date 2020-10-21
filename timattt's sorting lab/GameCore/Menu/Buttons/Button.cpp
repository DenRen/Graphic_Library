#include "Button.h"

#include "../../../Engine/Control/InputManager.h"
#include "../../../Engine/Graphics/DrawData.h"
#include "../../../Engine/Graphics/GraphicManager.h"
#include "../../../Engine/Utility/Coordinate.h"
#include "../../Storage/Views.h"

Button::Button()
{
	layer = 1;
}

bool Button::isLeftClicked() {
	bool _click = InputManager::IsPressed(MouseKey::Mouse_Left);
	Vector2F _mpos = GraphicManager::ConvertRealToView(
			InputManager::GetMousePos(), Views::BASE_VIEW);
	bool _res = (_mpos.x >= _pos.x - _size.x * 0.5)
			&& (_mpos.x <= 0.5 * _size.x + _pos.x)
			&& (_mpos.y >= _pos.y - _size.y * 0.5)
			&& (_mpos.y <= 0.5 * _size.y + _pos.y);
	return _res&& _click;
}

bool Button::isFocused() {
	Vector2F _mpos = GraphicManager::ConvertRealToView(
			InputManager::GetMousePos(), Views::BASE_VIEW);
	bool _res = (_mpos.x >= _pos.x - _size.x * 0.5)
			&& (_mpos.x <= 0.5 * _size.x + _pos.x)
			&& (_mpos.y >= _pos.y - _size.y * 0.5)
			&& (_mpos.y <= 0.5 * _size.y + _pos.y);

	return _res;
}

void Button::Draw() {
	DrawData info = { };

	info.position = _pos;

	info.size = _size;

	info.origin = { 0.5, 0.5 };

	info.frame = 0;
	info.layer = layer;

	info.spriteID = this->sprite_id;
	GraphicManager::Draw(info, view_id);
}

void Button::Update() {
	if (isFocused())
		focusReact();
	else
		disfocusReact();

	if (isRightClicked())
		rightClickReact();
	else if (isLeftClicked())
		leftClickReact();
}

Button::~Button() {}

bool Button::isRightClicked() {
	bool _click = InputManager::IsPressed(MouseKey::Mouse_Right);
	Vector2F _mpos = GraphicManager::ConvertRealToView(
			InputManager::GetMousePos(), Views::BASE_VIEW);
	bool _res = (_mpos.x >= _pos.x - _size.x * 0.5)
			&& (_mpos.x <= 0.5 * _size.x + _pos.x)
			&& (_mpos.y >= _pos.y - _size.y * 0.5)
			&& (_mpos.y <= 0.5 * _size.y + _pos.y) && _click;

	return _res;
}
