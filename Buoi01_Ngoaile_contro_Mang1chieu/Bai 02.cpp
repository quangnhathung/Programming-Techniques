#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int Tuoi(int yrs){
	time_t now = time(0);
	tm *x = localtime(&now);
	int NamHt = 1900 + x->tm_year;
	try {
		if (yrs <= 0 || yrs > NamHt){
			throw 101;
		}
		else {
			if (yrs < 1920){
				throw 102;
			}
			else
				return NamHt - yrs;
		}
	}
	catch (int errcode){
		if (errcode == 101){
			cout << "Nam sinh khong hop le" << endl;
		}
		else {
			cout << "Nam sinh <1920" << endl;
		}
		return -1;
	}
}
int main(){
	int yrs;
	cin >> yrs;
	if (Tuoi(yrs) < 0) {
		system("pause");
		return 0;
	}
	cout << "Tuoi cua ban la: " << Tuoi(yrs) << endl;
	system("pause");
	return 0;
}