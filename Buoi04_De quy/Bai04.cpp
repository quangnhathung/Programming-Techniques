#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
//a
int a(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (n == 2) return -1;
	return 2 * a(n - 1) - 3 * a(n - 2) - a(n - 3);
}
int main() {
	int b;
	cout << "Nhap: "; cin >> b;
	cout << a(b);
	return 0;
}