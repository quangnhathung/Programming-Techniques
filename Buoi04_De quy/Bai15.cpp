#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int u(int n) {
	if (n == 1) return 1;
	int kq = 0;
	for (int i = 1; i < n; i++) {
		kq += u(i);
	}
	return n*kq;
}
int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << u(n);
	return 0;

}