#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int Tohop(int n, int k) {
	if (k == 0 || k == n) return 1;
	return Tohop(n - 1, k) + Tohop(n - 1, k - 1);
}
int main() {
	int n, k;
	cout << "Nhap k "; cin >> k;
	cout << "n"; cin >> n;
	cout << "So cach chia la: " << Tohop(k,n) << endl;
	system("pause");
	return 0;
}