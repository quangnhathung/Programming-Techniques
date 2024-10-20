#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

float laikep(float money,int nam,float phantram) {
	if (nam == 0) return money;
	return money * phantram + laikep(money, nam-1, phantram);
}
int main() {
	float a, b, c;
	cout << "So tien gui(nghin VND): "; cin >> a;
	cout << "So nam gui: "; cin >> b;
	cout << "Lai suat(%): "; cin >> c;
	c /= 100;
	cout << "Sao tien sau khi gui " << b << " nam la: " << (int)laikep(a, b, c) << endl;
	return 0;
}