#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int x(int n) {
	if (n == 0) return 0;
	return 1 + x(n / 10);
}
int main() {
	cout << "Nhap n: "; int n; cin >> n;
	cout << x(n);
	return 0;
}