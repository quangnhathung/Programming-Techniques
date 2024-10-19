#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
//tong chan
int SumEven(int* a, int n) {
	if (n == -1) return 0;
	if (a[n] % 2 == 0) return a[n] + SumEven(a, n - 1);
	else return 0 + SumEven(a, n - 1);
}
//sap xep quicksort
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int Pattition(int*& pa, int l, int r) {
	int pivot = (l + r) / 2;
	int x = pa[pivot];
	while (l < r) {
		while (pa[l] < x) {
			l++;
		}
		while (pa[r] > x) {
			r--;
		}
		if (l <= r) {
			swap(pa[l], pa[r]);
			l++;
			r--;
		}
	}
	return l;
}
void Quicksort(int*& pa, int l, int r) {
	int i = Pattition(pa, l, r);
	if (l >= r) return;
	if (l < i - 1) {
		Quicksort(pa, l, i - 1);
	}
	if (i - 1 < r) {
		Quicksort(pa, i, r);
	}
}
//tim kiem
int binarysearch(int* a, int l, int r, int x) {
	int z = (l + r) / 2;
	if (a[z] == x) return z;
	if (l > r) return -1;
	if (x < a[z]) return  binarysearch(a, l, z - 1, x);
	else return binarysearch(a, z, r, x);
	//return -1;
}
//max chan
int MaxInt(int a, int b) {
	return a < b ? b : a;
}
int MaxEven(int* a, int n) {
	if (n == -1 || n == -2) return -1;
	if (a[n - 1] % 2 == 0) return MaxInt(MaxEven(a, n - 1), a[n - 1]);
	return MaxEven(a, n - 1);
}
void print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}//tong le
int SumOdd(int* a, int n) {
	if (n ==-1 ) return 0;
	if (a[n] % 2 != 0) return a[n] + SumOdd(a, n - 1);
	return 0 + SumOdd(a, n - 1);
}
int PrintOdd(int* a, int n) {
	if (n < 0) return 0;
	PrintOdd(a, n - 1);
	if ((n+1) % 2 != 0) {
		cout << a[n] << " ";
	}
}
int main() {
	cout << "So luong phan tu: ";
	int n; cin >> n;
	int* a = new int[n];	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
	cout << "Mang: ";
	print(a, n);
	cout << "Tong phan tu chan: " << SumEven(a, n-1)<<endl;
	cout << "So chan lon nhat: " << MaxEven(a, n) << endl;
	cout << "Tong phan tu le: " << SumOdd(a, n-1) << endl;
	cout << "Phan tu vi tri le: ";
	PrintOdd(a, n - 1);
	cout << endl;
	system("pause");
	return 0;
}