#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int main() {
	int a, b, tong, hieu, tich;
	float thuong;
	int* pa = &a;
	int* pb = &b;
	int* ketqua= new int;
	float* pthg=new float;
	cout << "Nhap a, b:"; cin >> *pa >> *pb;
	*ketqua = *pa + *pb;
	cout << "Tong la: " << *ketqua << " Dia chi: " << ketqua << endl;
	*ketqua = *pa - *pb;
	cout << "Hieu la: " << *ketqua << " Dia chi: " << ketqua << endl;
	*ketqua = *pa * *pb;
	cout << "Tich la: " << *ketqua << " Dia chi: " << ketqua << endl;
	*pthg = 1.00 * *pa / (*pb);
	cout << "Thuong la: " << *pthg << " Dia chi: " << pthg << endl;
	return 0;
}