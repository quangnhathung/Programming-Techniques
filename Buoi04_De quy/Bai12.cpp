#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int x(int n);
int y(int n);
int x(int n) {
	if (n == 0) return 1;
	return x(n - 1) + y(n - 1);
}
int y(int n) {
	if (n == 0) return 0;
	return 3*x(n - 1) + 2*y(n - 1);
}
int main() {
	cout << "Nhap n: "; int n; cin >> n;
	cout << "x: "<<x(n)<<endl;
	cout << "y: " << y(n) << endl;
	return 0;
}