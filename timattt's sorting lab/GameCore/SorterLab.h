#pragma once

#include <string>

#include "../Engine/SceneManagment/Scene.h"

#define TOTAL_POINTS 300
#define MAX_ACTIONS 8000

struct sortResult {
	int total_swaps;
	int total_compars;
};

class SorterLab: public Scene {

	void Init();

	void Update();

	void Destroy();

public:

	// ALGOS
	static sortResult result[TOTAL_POINTS];

	static void recalculatePoints(sortResult (*sort_func)(int * arr, int sz));

	static void report_error(std::string mes);

};
