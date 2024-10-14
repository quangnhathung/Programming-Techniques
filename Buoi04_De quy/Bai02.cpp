#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int UCLN(int a, int b) {
	if (a == b) return a;
	if (a < b) return UCLN(a, b - a);
	else return UCLN(b, a - b);
}
int main() {
	int a, b;
	cout << "Nhap: "; cin >> a >> b;
	cout << UCLN(a, b);
	return 0;
}