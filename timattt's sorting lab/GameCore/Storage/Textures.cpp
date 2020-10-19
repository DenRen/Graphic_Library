#include "Textures.h"

#include <string>

#include "../../Engine/Graphics/DrawData.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Utility/Coordinate.h"

// Redefine
int Textures::GRID = 0;
int Textures::NLOGN = 0;
int Textures::N2 = 0;
int Textures::BUBBLE = 0;

void Textures::LOAD_ALL_TEXTURES() {
	GRID = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/GRID.png"),
					Vector2F(616, 618), 1));
	NLOGN = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/NlogN.png"),
					Vector2F(800, 600), 1));
	N2 = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/N2.png"),
					Vector2F(800, 600), 1));
	BUBBLE = GraphicManager::LoadSprite(
			GraphicPrefabData(std::string("./Resources/Bubble.png"),
					Vector2F(800, 600), 1));
}
