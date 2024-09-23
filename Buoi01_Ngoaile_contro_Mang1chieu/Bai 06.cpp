#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
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
string Standard(string s) {
	string a=s;
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(a[i]) && isupper(a[i])) {
			a[i]=tolower(a[i]);
		}
	}
	return a;
}
int main(){
	time_t now = time(0);
	tm* x = localtime(&now);
	int NamHt = 1900 + x->tm_year;
	cout << "Gioi tinh: ";
	string s;
	cin >> s;
	int n;
	cout << "Nhap Nam sinh: "; cin >> n;
	if (Standard(s) == "nam") {
		if (Tuoi(n) == -1) {
			Tuoi(n);
		}
		else {
			cout << "Nam nghi huu cua ban la: " << NamHt + (62 - Tuoi(n))<<endl;
		}
	}
	else {
		if (Tuoi(n) == -1) {
			Tuoi(n);
		}
		else {
			cout << "Nam nghi huu cua ban la: " << NamHt + (60 - Tuoi(n))<<endl;
		}
	}
	system("pause");
	return 0;
}