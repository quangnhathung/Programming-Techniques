#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
//chu so dau
int First(int n) {
	if (n / 10 == 0) return n;
	First(n / 10);
}
int x = 0;
int Dao(int n) {
	if (n == 0) return n;
	x = x * 10 + n % 10;
	Dao(n / 10);
	return x;
}
//so lon nhat
int nmas(int n) {
	int x = -1;
	while (n) {
		if (n % 10 > x) x = n % 10;
		n /= 10;
	}
	return x;
}
int nmas2(int n) {
	int x = 10;
	while (n) {
		if (n % 10 < x) x = n % 10;
		n /= 10;
	}
	return x;
}
bool Check1(int n) {
	if (n == 0) return true;
	if ((n % 10) % 2 == 0) return false;
	Check1(n / 10);
	//return true;
}
bool Check2(int n) {
	if (n == 0) return true;
	if ((n % 10) % 2 != 0) return false;
	Check2(n / 10);
	//return true;
}
int main() {
	int n; cout << "Nhap n:"; cin >> n;
	cout << "Chu so dau: " << First(n) << endl;
	cout << " Dao nguoc: " << Dao(n) << endl;
	cout << "Chu so lon nhat: " << nmas(n) << endl;
	cout << "Chu so Nho nhat: " << nmas2(n) << endl;
	if (Check1(n)) {
		cout << "Toan so le" << endl;
	}
	else cout << "Khong toan so le" << endl;
	if (Check2(n)) {
		cout << "Toan so Chan" << endl;
	}
	else cout << "Khong toan so Chan" << endl;
	system("pause");
	return 0;
}