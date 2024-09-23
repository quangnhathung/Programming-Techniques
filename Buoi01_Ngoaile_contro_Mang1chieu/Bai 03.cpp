#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	float a=2.3;
	float b=5.1;
	float* pa = &a;
	float* pb = &b;
	cout << *pa << "  "<< *pb << endl;
	system("pause");
	return 0;
}