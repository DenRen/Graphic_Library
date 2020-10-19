/*
 * Algoses.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: timattt
 */

#include "Algoses.h"

#include "../SorterLab.h"

Algoses::Algoses() {
}

void Algoses::tswap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

sortResult Algoses::n2_sort(int *arr, int sz) {
	sortResult res = {0, 0};
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			res.total_compars++;
			if (arr[i] >= arr[j]) {
				tswap(arr + i, arr + j);
				res.total_swaps++;
			}
		}
	}



	return res;
}

sortResult Algoses::bubble_sort(int a[], int n) {
	sortResult res = {0, 0};
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			res.total_compars++;
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1]; /*Swap have been done here*/
				a[j + 1] = temp;
				res.total_swaps++;
			}
		}
	}

	return res;
}

sortResult Algoses::tQsort(int *arr, int sz) {
	return tQsort(arr, 0, sz);
}

sortResult Algoses::tQsort(int *arr, int a, int b) {
	sortResult res = {0, 0};
	int left = a, right = b;
	int piv = arr[(left + right) / 2];
	while (left <= right) {
		//arr[l] < piv
		while (arr[left] < piv) {
			res.total_compars++;
			left++;
		}
		//arr[right] > piv
		while (piv < arr[right]) {
			res.total_compars++;
			right--;
		}
		if (left <= right) {
			res.total_swaps++;
			tswap(&arr[left++], &arr[right--]);
		}
	}
	if (a < right) {
		sortResult r = tQsort(arr, a, right);
		res.total_compars += r.total_compars;
		res.total_swaps += r.total_swaps;
	}
	if (b > left) {
		sortResult r = tQsort(arr, left, b);
		res.total_compars += r.total_compars;
		res.total_swaps += r.total_swaps;
	}

	return res;
}
