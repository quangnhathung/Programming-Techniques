#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>
using namespace std;
struct personal {
	string Ten; 
	string Sex;
	string Old;
};
personal Input() {
	personal x;
	cout << "Ten: "; getline(cin, x.Ten);
	cout << "Gioi tinh: "; getline(cin, x.Sex);
	cout << "Ngay thang nam sinh(dd/mm/yyyy): "; getline(cin, x.Old);
	return x;
}
int GetYrs(string s) {
	int Date, Month, yrs;
	char temp;
	stringstream ss(s);
	ss >> Date >> temp >> Month >> temp >> yrs;
	return yrs;
}
int Tuoi(int yrs) {
	time_t now = time(0);
	tm* x = localtime(&now);
	int NamHt = 1900 + x->tm_year;
	try {
		if (yrs <= 0 || yrs > NamHt) {
			throw 101;
		}
		else {
			if (yrs < 1920) {
				throw 102;
			}
			else
				return NamHt - yrs;
		}
	}
	catch (int errcode) {
		if (errcode == 101) {
			cout << "Nam sinh khong hop le" << endl;
		}
		else {
			cout << "Nam sinh <1920" << endl;
		}
		return -1;
	}
}
string Standard(string s) {
	string a = s;
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(a[i]) && isupper(a[i])) {
			a[i] = tolower(a[i]);
		}
	}
	return a;
}
int main() {
	personal a = Input();
	time_t now = time(0);
	tm* x = localtime(&now);
	int NamHt = 1900 + x->tm_year;
	int n=GetYrs(a.Old);
	if (Standard(a.Sex) == "nam") {
		if (Tuoi(n) == -1) {
			Tuoi(n);
		}
		else {
			int yrsold = NamHt + (62 - Tuoi(n));//nam nghi huu
			if (yrsold >= 2021 && yrsold <= 2028) {
				switch (yrsold) {
				case 2021: {
					cout << "Tuoi nghi huu cua ong ban la: 60 tuoi 3 thang" << endl;
					break;
				}
				case 2022: {
					cout << "Tuoi nghi huu cua ong ban la: 60 tuoi 6 thang" << endl;
					break;
				}case 2023: {
					cout << "Tuoi nghi huu cua ong ban la: 60 tuoi 9 thang" << endl;
					break;
				}case 2024: {
					cout << "Tuoi nghi huu cua ong ban la: 61 tuoi" << endl;
					break;
				}
				case 2025: {
					cout << "Tuoi nghi huu cua ong ban la: 61 tuoi 3 thang" << endl;
					break;
				}
				case 2026: {
					cout << "Tuoi nghi huu cua ong ban la: 61 tuoi 6 thang" << endl;
					break;
				}
				case 2027: {
					cout << "Tuoi nghi huu cua ong ban la: 61 tuoi 9 thang" << endl;
					break;
				}
				case 2028: {
					cout << "Tuoi nghi huu cua ong ban la: 62 tuoi" << endl;
					break;
				}
				}
			}
			else if (yrsold < 2021) {
				cout<< "Tuoi nghi huu cua ong ban la: 60 tuoi" << endl;
			}
			else {
				cout << "Tuoi nghi huu cua ong ban la: 62 tuoi" << endl;
			}
		}
	}
	else {
		if (Tuoi(n) == -1) {
			Tuoi(n);
		}
		else {
			int yrsold = NamHt + (60 - Tuoi(n));//nam nghi huu
			if (yrsold >= 2021 && yrsold <= 2035) {
				switch (yrsold) {
				case 2021: {
					cout << "Tuoi nghi huu cua ong ban la: 55 tuoi 4 thang" << endl;
					break;
				}
				case 2022: {
					cout << "Tuoi nghi huu cua ong ban la: 55 tuoi 8 thang" << endl;
					break;
				}case 2023: {
					cout << "Tuoi nghi huu cua ong ban la: 56 tuoi" << endl;
					break;
				}case 2024: {
					cout << "Tuoi nghi huu cua ong ban la: 56 tuoi 4 thang" << endl;
					break;
				}
				case 2025: {
					cout << "Tuoi nghi huu cua ong ban la: 56 tuoi 8 thang" << endl;
					break;
				}
				case 2026: {
					cout << "Tuoi nghi huu cua ong ban la: 57 tuoi" << endl;
					break;
				}
				case 2027: {
					cout << "Tuoi nghi huu cua ong ban la: 57 tuoi 4 thang" << endl;
					break;
				}
				case 2028: {
					cout << "Tuoi nghi huu cua ong ban la: 57 tuoi 8 thang" << endl;
					break;
				}
				case 2029: {
					cout << "Tuoi nghi huu cua ong ban la: 58 tuoi" << endl;
					break;
				}
				case 2030: {
					cout << "Tuoi nghi huu cua ong ban la: 58 tuoi 4 thang" << endl;
					break;
				}
				case 2031: {
					cout << "Tuoi nghi huu cua ong ban la: 58 tuoi 8 thang" << endl;
					break;
				}
				case 2032: {
					cout << "Tuoi nghi huu cua ong ban la: 59 tuoi" << endl;
					break;
				}
				case 2033: {
					cout << "Tuoi nghi huu cua ong ban la: 59 tuoi 4 thang" << endl;
					break;
				}
				case 2034: {
					cout << "Tuoi nghi huu cua ong ban la: 59 tuoi 8 thang" << endl;
					break;
				}
				case 2035: {
					cout << "Tuoi nghi huu cua ong ban la: 60 tuoi" << endl;
					break;
				}
				}
			}
			else if (yrsold < 2021) {
				cout << "Tuoi nghi huu cua ong ban la: 55 tuoi" << endl;
			}
			else {
				cout << "Tuoi nghi huu cua ong ban la: 60 tuoi" << endl;
			}
		}
	}
	system("pause");
	return 0;
}