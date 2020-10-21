/*
 * AlgosButton.h
 *
 *  Created on: Oct 18, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_MENU_ALGOSBUTTON_H_
#define GAMECORE_MENU_ALGOSBUTTON_H_

#include "Button.h"

struct sortResult;

class AlgosButton: public Button {
public:
	sortResult (*sort_func)(int *arr, int sz);

	AlgosButton();
	AlgosButton(sortResult (*sort_func)(int *arr, int sz), int index, int texture);
	~AlgosButton();
	void Init();
	void Destroy();
	void leftClickReact();
	void rightClickReact();
	void disfocusReact();
	void focusReact();
	void Init(GameObject *owner);
};

#endif /* GAMECORE_MENU_ALGOSBUTTON_H_ */
