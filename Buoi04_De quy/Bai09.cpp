#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
long long s1(int n) {
	if (n == 1) return 1;
	return n + s1(n - 1);
}
double s2(int n) {
	if (n == 0) return 0;
	return sqrt((double)5 + s2(n - 1));
}
double s3(int n) {
	if (n == 1) return (double)1 / 2;
	return ((double)n / (n + 1)) + s3(n - 1);
}
double s4(int n) {
	if (n == 0) return 1;
	return (double)1 / (2 * n + 1) + s4(n - 1);
}
//giai thua
long long gt(int n) {
	if (n == 1) return 1;
	return n * gt(n - 1);
}

int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << s1(n) << endl;
	cout << s2(n) << endl;
	cout << s3(n) << endl;
	cout << s4(n) << endl;
	return 0;
}