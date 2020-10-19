#include "Views.h"

#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"
#include "../Utils/Settings.h"

// Define static variables
unsigned Views::BASE_VIEW = -1;

void Views::LOAD_ALL_VIEWS() {
	Vector2F cur_resolution = Vector2F(Settings::resolution.x, Settings::resolution.y);

	Views::BASE_VIEW = GraphicManager::AddView({{ 0, 0 }, cur_resolution,{ 0, 0 },{ 0, 0 },{ 1000, 1000 },{ 0.5, 0.5 },{ 1, -1 }});
}

void Views::SET_RESOLUTION(Vector2U new_size)
{
	GraphicManager::SetResolution(new_size);
	GraphicManager::GetView(BASE_VIEW)->real_size = Vector2F(new_size.x, new_size.y);
}
