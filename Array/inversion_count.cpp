#include <bits/stdc++.h>
using namespace std;

int merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - l;
  int inv = 0;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = a[m + j + 1];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      a[k++] = L[i++];
    } else {
      a[k++] = R[j++];
      inv += (m - i);
    }
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
  return inv;
}

int inversion_count(int a[], int l, int r) {
  int inv = 0;
  if (l < r) {
    int m = l + (r - l) / 2;
    inv += inversion_count(a, l, m);
    inv += inversion_count(a, m + 1, r);
    inv += merge(a, l, m, r);
  }
  return inv;
}

int main() {
  int a[] = {3, 4, 2, 1, 5, 8, 6, 4, 9, 0, 7};
  int n = sizeof(a) / sizeof(int);
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
  cout << endl;
  cout << inversion_count(a, 0, n - 1) << endl;
  return 0;
}
