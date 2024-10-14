#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int x(int n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	int kq = 0;
	for (int i = 0; i < n; i++) {
		kq += (n-i) * x(i);
	}
	return kq;
}
int main() {
	cout << "Nhap n: "; int n; cin >> n;
	cout << x(n);
	return 0;
}
