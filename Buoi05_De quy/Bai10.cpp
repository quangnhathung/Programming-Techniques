#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
//quicksort
int pattition(int*& a, int l, int r) {
	int pivot = (l + r) / 2;
	int x = a[pivot];
	while (l < r) {
		while (a[l] < x) {
			l++;
		}
		while (a[r] > x) {
			r--;
		}
		if (l <= r) {
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			l++; r--;
		}
	}
	return l;
}
void quicksort(int*& a, int n, int l, int r) {
	if (l >= r) return;
	int i = pattition(a, l, r);
	quicksort(a, n, l, i - 1);
	quicksort(a, n, i, r);
}
int BinarySearchArr(int* a, int x, int l, int r) {
	int i = (l + r) / 2;
	if (a[i] == x) return i;
	if (l > r) return -1;//k thay
	if (x < a[i]) return BinarySearchArr(a, x, l, i);
	else return BinarySearchArr(a, x, i, r);
}
void print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cout << "So luong phan tu: "; cin >> n;
	int* pa = new int[n];
	srand(time(NULL));
	delete[] pa;
	pa = new int[n];
	for (int i = 0; i < n; i++) {
		pa[i] = rand() % 100;
	}
	cout << "Mang: ";

	quicksort(pa, n, 0, n - 1);
	print(pa, n);
	int y; cout << "Phan tu can tim kiem: ", cin >> y;
	int x = BinarySearchArr(pa, y, 0, n - 1);
	if (x == -1) cout << "Khong ton tai trong mang";
	else
		cout << "Xuat hien o vi tri thu " << x + 1 << endl;
	return 0;
}