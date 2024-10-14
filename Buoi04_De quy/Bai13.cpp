#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int CSn(int n, int a, int r) {
	if (n == 1) return a;
	return r + CSn(n - 1, a, r);
}
int main() {
	int a, r, n;
	cout << "Nhap n a r: "; cin >> n >> a >> r;
	cout << CSn(n, a, q);
	return 0;
}