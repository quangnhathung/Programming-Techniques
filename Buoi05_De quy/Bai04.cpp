#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int CntOdd(int n){
	if (n == 0) return 0;
	int x = n % 10;
	if (x% 2 == 0)
		return 1 + CntOdd(n / 10);
	else return 0 + CntOdd(n / 10);
}

int main() {
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << "Co " << CntOdd(n) << " chu soc chan." << endl;
	system("pause");
	return 0;
}