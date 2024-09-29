#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
struct KhachHang {
	string Ten;
	string SDT;
	int Adult;
	int Child;
	string Film;
	string room;
	string time;
	int Cost;
};
int profit = 0;
vector<KhachHang> input(string s) {
	fstream file(s);
	string str;
	vector<KhachHang> x;
	while (getline(file, str)) {
		KhachHang a;
		char temp;
		stringstream ss(str);
		getline(ss, a.Ten, ',');
		getline(ss, a.SDT, ',');
		ss >> a.Adult;
		ss >> temp;
		ss >> a.Child;
		ss >> temp;
		getline(ss, a.Film, ',');
		getline(ss, a.room, ',');
		getline(ss, a.time, ',');
		a.Cost = a.Adult * 40 + a.Child * 20;
		profit += a.Cost;
		x.push_back(a);
	}
	file.close();
	return x;
}
void printlist(vector<KhachHang> a) {
	//cout << "+ Danh sach: " << endl;
	cout << setw(5) << left << "STT" << setw(20) << "Ho va ten" << setw(20) << "So dien thoai"
		<< setw(11) << left << "Nguoi lon" << setw(10) << left << "Tre em"
		<< setw(27) << "Ten phim" << setw(15) << left << "phong chieu"
		<< setw(15) << left << "Xuat chieu"
		<< setw(15) << left << "Tong tien" << endl;
	cout << "*****************************************************************"
		<< "*******************************************************************" << endl;
	int pos = 1;
	for (int i = 0; i < a.size(); i++) {
		cout << setw(5) << left << pos << setw(20) << a[i].Ten << setw(24) << a[i].SDT
			<< setw(10) << left << a[i].Adult << setw(7) << left << a[i].Child
			<< setw(27) << a[i].Film << setw(15) << left << a[i].room
			<< setw(15) << left << a[i].time
			<< setw(15) << left << a[i].Cost << endl;
		pos++;
	}
}
void Profit(vector<KhachHang> a) {
	map<string, int> cost;
	for (int i = 0; i < a.size(); i++) {
		cost[a[i].Film] += a[i].Cost;
	}
	for (auto i : cost) {
		cout << i.first << " thu duoc " << i.second << " (VND)" << endl;
	}
}
//ss
void swap(KhachHang& a, KhachHang& b) {
	KhachHang temp = a;
	a = b;
	b = temp;
}
int Pattition(vector<KhachHang>& pa, int l, int r) {
	int pivot = (l + r) / 2;
	string x = pa[pivot].Ten;
	while (l <= r) {
		while (pa[l].Ten < x) {
			l++;
		}
		while (pa[r].Ten > x) {
			r--;
		}
		if (l <= r) {
			swap(pa[l], pa[r]);
			l++;
			r--;
		}
	}
	return l;
}
void Quicksort(vector<KhachHang>& pa, int l, int r) {
	int i = Pattition(pa, l, r);
	if (l >= r) return;
	if (l < i - 1) {
		Quicksort(pa, l, i - 1);
	}
	if (i < r) {
		Quicksort(pa, i, r);
	}
}
//ss2
int Pattition1(vector<KhachHang>& pa, int l, int r) {
	int pivot = (l + r) / 2;
	int x = pa[pivot].Cost;
	while (l <= r) {
		while (pa[l].Cost < x) {
			l++;
		}
		while (pa[r].Cost > x) {
			r--;
		}
		if (l <= r) {
			swap(pa[l], pa[r]);
			l++;
			r--;
		}
	}
	return l;
}
void Quicksort1(vector<KhachHang>& pa, int l, int r) {
	int i = Pattition1(pa, l, r);
	if (l >= r) return;
	if (l < i - 1) {
		Quicksort1(pa, l, i - 1);
	}
	if (i < r) {
		Quicksort1(pa, i, r);
	}
}
//macc dinh string
string Standard(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i])) s[i] = tolower(s[i]);
	}
	return s;
}
//search
int search(vector<KhachHang> a, string s, int l, int r) {
	int pivot = (l + r) / 2;
	if (l > r) return -1;
	if (Standard(a[pivot].Ten) == Standard(s)) {
		return pivot;
	}
	else {
		if (Standard(s) < Standard(a[pivot].Ten)) {
			return search(a, s, l, pivot - 1);
		}
		else
			return search(a, s, pivot, r);
	}
	//return search(pa, n, x, l, pivot - 1);
	//return search(pa, n, x, pivot, r);
}
void menu() {
	cout << "                     Menu                  " << endl;
	cout << "*******************************************" << endl;
	cout << "0. Thoat." << endl;
	//	cout << "1. Xuat danh sach." << endl;
	cout << "1. Ind danh sach khach hang" << endl;
	cout << "2. Tong danh thu tung bo phim" << endl;
	cout << "3. Tong danh thu cua rap." << endl;
	cout << "4. sap sep theo tien tra." << endl;
	cout << "5. Sap xep Theo ho" << endl;
	cout << "6. Tim \"Nguyen Van An\" " << endl;
	cout << "********************************************" << endl;
	cout << "\tOPTION: ";
}

int main() {
	vector<KhachHang> a = input("03.txt");
	int z;
	do {
		menu();
		cin >> z;
		cout << "\n\n";
		switch (z) {
		case 1: {
			printlist(a);
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			Profit(a);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			cout << "Tong doanh thu: " << profit;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			Quicksort1(a, 0, a.size()-1);
			printlist(a);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			Quicksort(a, 0, a.size()-1);
			printlist(a);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			Quicksort(a, 0, a.size() - 1);
			if (search(a, "Nguyen Van An", 0, a.size() - 1) == -1) cout << "Khong ton tai" << endl;
			else {
				cout << setw(5) << left << "STT" << setw(20) << "Ho va ten" << setw(20) << "So dien thoai"
					<< setw(11) << left << "Nguoi lon" << setw(10) << left << "Tre em"
					<< setw(27) << "Ten phim" << setw(15) << left << "phong chieu"
					<< setw(15) << left << "Xuat chieu"
					<< setw(15) << left << "Tong tien" << endl;
				cout << "*****************************************************************"
					<< "*******************************************************************" << endl;
				int pos = 1;
				cout << setw(5) << left << pos << setw(20) << a[search(a, "Nguyen Van An", 0, a.size() - 1)].Ten << setw(24) << a[search(a, "Nguyen Van An", 0, a.size() - 1)].SDT
					<< setw(10) << left << a[search(a, "Nguyen Van An", 0, a.size() - 1)].Adult << setw(7) << left << a[search(a, "Nguyen Van An", 0, a.size() - 1)].Child
					<< setw(27) << a[search(a, "Nguyen Van An", 0, a.size() - 1)].Film << setw(15) << left << a[search(a, "Nguyen Van An", 0, a.size() - 1)].room
					<< setw(15) << left << a[search(a, "Nguyen Van An", 0, a.size() - 1)].time
					<< setw(15) << left << a[search(a, "Nguyen Van An", 0, a.size() - 1)].Cost << endl;
			}
			//cout << a[search(a, "Nguyen Van An", 0, a.size())] << endl;
			//Profit(a);
			//system("pause");
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);

	return 0;
}