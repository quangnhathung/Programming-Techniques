#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
//dem chu so nguyen uong cua n
int Cnt(int n){
	if (n == 0) return 0;
	return 1 + Cnt(n / 10);
}
int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << "Co " << Cnt(n) << " chu so." << endl;
	system("pause");
	return 0;
}