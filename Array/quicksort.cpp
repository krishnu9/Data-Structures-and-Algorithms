#include <bits/stdc++.h>
using namespace std;
int i = 0;
int partition(int a[], int low, int high) {
	int pivot = a[low];
	int start = low, end = high;
	while (start < end) {
		while (a[start] <= pivot)
			start++;
		while (a[end] > pivot)
			end--;
		if (start < end)
			swap(a[start], a[end]);
	}
	swap(a[low], a[end]);
	return end;
}

void quicksort(int a[], int low, int high) {
	if (low < high) {
		int pi = partition(a, low, high);
		quicksort(a, low, pi - 1);
		quicksort(a, pi + 1, high);
	}
}

void printarr(int a[], int low, int high) {
	for (int i = low; i <= high; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

int main() {
	int a[] = {4, 3, 2, 1, 5, 7, 8, 6, 3, 2, 7, 8};
	int n = sizeof(a) / sizeof(int);
	quicksort(a, 0, n - 1);
	printarr(a, 0, n - 1);
	return 0;
}