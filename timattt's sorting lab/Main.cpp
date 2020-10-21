#include "Engine/AllEngine.h"
#include "GameCore/SorterLab.h"

int main() {
	GraphicManager::ShowFPS(true);
	GameManager::Init();
	Scene* start = new SorterLab;
	start->Init();
	GameManager::Launch(start);
	return 0;
}
