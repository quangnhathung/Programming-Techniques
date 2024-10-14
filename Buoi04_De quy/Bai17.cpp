#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
//a
int a(int n) {
	if (n == 1 || n == 2) return 1;
	return a(n - 1) + (n - 1) * a(n - 2);
}
int main() {
	int b;
	cout << "Nhap: "; cin >> b;
	cout << a(b);
	return 0;
}