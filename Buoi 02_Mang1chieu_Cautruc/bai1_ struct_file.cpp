#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
struct sinhvien {
	string Ho;
	string holot;
	string ten;
	float tb;
	string Loai;
};
vector<sinhvien> input(string s) {
	fstream file(s);
	string str;
	vector<sinhvien> x;
	while (getline(file, str)) {
		sinhvien a;
		stringstream ss(str);
		getline(ss, a.Ho, ',');
		getline(ss, a.holot, ',');
		getline(ss, a.ten, ',');
		ss >> a.tb;
		if (a.tb >= 8) a.Loai = "Gioi";
		else if (a.tb >= 6.5 && a.tb < 8) a.Loai = "Kha";
		else if (a.tb >= 5 && a.tb < 6.5) a.Loai = "Trung Binh";
		x.push_back(a);
	}
	file.close();
	return x;
}
//macc dinh string
string Standard(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) s[i] = tolower(s[i]);
	}
	return s;
}
//xuat danh sach
void printlist(vector<sinhvien> a) {
	cout << "+ Danh sach: " << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << "\t" + a[i].Ho + " " + a[i].holot + " " + a[i].ten + "  Diem trung binh: " <<
			a[i].tb << "." << endl;
	}
	cout << endl << " + Danh sach kha/gioi: " << endl;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].Loai == "Kha" || a[i].Loai == "Gioi")
			cout << "\t" + a[i].Ho + " " + a[i].holot + " " + a[i].ten + "  Diem trung binh: " <<
			a[i].tb << " => " << a[i].Loai << endl;
	}

	cout << endl << " + Danh sach Ho Nguyen: " << endl;
	for (int i = 0; i < a.size(); i++) {
		if (Standard(a[i].Ho) == "nguyen")
			cout << "\t" + a[i].Ho + " " + a[i].holot + " " + a[i].ten + "  Diem trung binh: " <<
			a[i].tb << " => " << a[i].Loai << endl;
	}
	cout << endl << " + Sinh vien yeu nhat: " << endl;
	cout << "\t" + a[0].Ho + " " + a[0].holot + " " + a[0].ten + "  Diem trung binh: " <<
		a[0].tb << " => " << a[0].Loai << endl;
	cout << endl << " + Danh sach yeu nhat: " << endl;
	cout << "\t" + a.back().Ho + " " + a.back().holot + " " + a.back().ten + "  Diem trung binh: " <<
		a.back().tb << " => " << a.back().Loai << endl;
}
//sap xep
void swap(sinhvien& a, sinhvien& b) {
	sinhvien temp = a;
	a = b;
	b = temp;
}
int Pattion(vector<sinhvien>& a, int l, int r) {
	int pivot = (l + r) / 2;
	float x = a[pivot].tb;
	while (l <= r) {
		while (a[l].tb < x) {
			l++;
		}
		while (a[r].tb > x) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			r--;
			l++;
		}
	}
	return l;
}
void quicksort(vector<sinhvien>& a, int l, int  r) {
	int i = Pattion(a, l, r);
	if (l > r) return;
	if (l < i - 1)
		quicksort(a, l, i - 1);
	if (i - 1 < r)
		quicksort(a, i, r);
}
//
int main() {
	vector<sinhvien> list = input("01.txt");
	quicksort(list, 0, list.size() - 1);
	printlist(list);

	return 0;
}