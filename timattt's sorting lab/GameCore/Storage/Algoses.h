/*
 * Algoses.h
 *
 *  Created on: Oct 18, 2020
 *      Author: timattt
 */

#ifndef GAMECORE_ALGOSES_H_
#define GAMECORE_ALGOSES_H_
struct sortResult;

#define TOTAL_ALGOSES 3

class Algoses {
public:
	Algoses();

	static void tswap(int * a, int * b);

	static sortResult n2_sort(int * arr, int sz);
	static sortResult bubble_sort(int a[], int n);

	static sortResult tQsort(int *arr, int sz);
	static sortResult tQsort(int *arr, int a, int b);
};

#endif /* GAMECORE_ALGOSES_H_ */
