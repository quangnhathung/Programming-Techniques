#include<iostream>
#include<cstdlib>
using namespace std;
void Chia(int a, int b){
	try {
		if (b == 0){
			throw "Loi chia 0";
		}
		cout << a << " / " << b << " = " << 1.00*a / b << endl;
	}
	catch (const char *str){
		cout << "Loi: " << str << endl;
	}
}
int main(){
	int a, b;
	cin >> a >> b;
	Chia(a, b);
	system("pause");
	return 0;
}