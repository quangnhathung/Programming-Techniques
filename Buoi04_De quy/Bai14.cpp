#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int u(int n) {
	if (n < 6) return n;
	int kq = 0;
	for (int i = 1; i <= 5; i++) {
		kq += u(n-i);
	}
	return kq;
}
int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << u(n);
	return 0;

}