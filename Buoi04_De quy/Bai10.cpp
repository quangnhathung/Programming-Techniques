#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
int Fibo(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	return Fibo(n - 1) + Fibo(n - 2);
}
int main() {
	//cout << "Nhap n: "; int n; cin >> n;
	cout << "Nhap m: "; int m; cin >> m;
	cout << "Nhap n: "; int n; cin >> n;
	int i = 1;
	while (1) {
		int x = Fibo(i);
		if (x > n) break;
		if (x>m)
		cout << x << " ";
		i++;
	}
	return 0;
}