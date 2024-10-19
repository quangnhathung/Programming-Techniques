#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;

int MaxInt(int a, int b) {
	return a < b ? b : a;
}
int MaxArrRecursion(int* a, int n) {
	if (n == 1) return a[0];
	else return MaxInt(MaxArrRecursion(a, n - 1), a[n - 1]);
}
void print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	int n; cin >> n;
	int* a = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
	print(a, n);
	cout << MaxArrRecursion(a, n) << endl;
	system("pause");
	return 0;
}