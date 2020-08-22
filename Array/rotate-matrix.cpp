#include <bits/stdc++.h>
using namespace std;

void rotate(int** m, int n) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			int tmp = m[i][j];
			m[i][j] = m[j][n - i - 1];
			m[j][n - i - 1] = m[n - i - 1][n - j - 1];
			m[n - i - 1][n - j - 1] = m[n - j - 1][i];
			m[n - j - 1][i] = tmp;
		}
	}
}

void display_mat(int** m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	int** mat = new int*[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
		for (int j = 0; j < n; j++) {
			mat[i][j] = rand() % 90 + 10;
		}
	}
	cout << "Input:\n";
	display_mat(mat, n);
	cout << "Output:\n";
	rotate(mat, n);
	display_mat(mat, n);
	return 0;
}