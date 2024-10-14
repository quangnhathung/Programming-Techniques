//error
#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int a(int n) {
	if (n == 1) return 1;
	if (n % 2 == 0) return n + a(n) + 2;
	else return n * n + a(n) * a(n + 1) + 1;
}
int main() {
	cout << "Nhap n: "; int n; cin >> n;
	cout << a(n);
	return 0;
}