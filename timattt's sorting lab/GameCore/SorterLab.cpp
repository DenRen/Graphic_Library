#include "SorterLab.h"

#include <cstdlib>
#include <iostream>

#include "../Engine/SceneManagment/SceneManager.h"
#include "Scenes/SLScene.h"
#include "Storage/Algoses.h"
#include "Storage/Textures.h"
#include "Storage/Views.h"
#include "Utils/Controls.h"
#include "Utils/PTC.h"
#include "Utils/Settings.h"

class MainMenuScene;

sortResult SorterLab::result[TOTAL_POINTS];

void SorterLab::Init() {
	PTC::say("Sorter lab started!");
	PTC::say("Loading resources!");
	Textures::LOAD_ALL_TEXTURES();
	PTC::say("Textures loaded!");
	PTC::say("Loading views!");
	Views::LOAD_ALL_VIEWS();
	PTC::say("Views loaded!");
	PTC::say("Loading settings!");
	Settings::LOAD_SETTINGS();
	PTC::say("Settings loaded!");
	PTC::say("Loading controls!");
	Controls::LOAD_ALL_GAMEKEYS();
	PTC::say("Controls loaded!");

	SorterLab::recalculatePoints(Algoses::n2_sort);
}

void SorterLab::Update() {
	SceneManager::CreateScene(new SLScene());
	SceneManager::CloseScene(this);
}

void SorterLab::Destroy() {
	PTC::say("Start scene is terminated!");
}

void SorterLab::report_error(std::string mes) {
	std::cout << "Error reported!\n";
	std::cout << mes << "\n";
	exit(-2);
}

void SorterLab::recalculatePoints(sortResult (*sort_func)(int * arr, int sz)) {
	if (sort_func == NULL) {
		report_error("sorting function is null!");
	}

	int arr[TOTAL_POINTS];

	for (int n = 1; n < TOTAL_POINTS; n++) {
		for (int i = 0; i < n; i++) {
			arr[i] = (rand() % n);
		}

		result[n] = sort_func(arr, n);
	}
}
