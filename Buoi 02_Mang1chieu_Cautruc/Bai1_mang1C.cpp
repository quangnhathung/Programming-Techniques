#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<ostream>
#include<map>
using namespace std;
int* Create(int n) {
	int* a = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = -99 + rand() % (-99 - 999 + 1);
	}
	return a;
}
//sap xep quicksort
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int Pattition(int* pa, int l, int r) {
	int pivot = (l + r) / 2;
	int x = pa[pivot];
	while (l <= r) {
		while (pa[l] < x) {
			l++;
		}
		while (pa[r] > x) {
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
void Quicksort(int* pa, int l, int r) {
	int i = Pattition(pa, l, r);
	if (l >= r) return;
	if (l < i - 1) {
		Quicksort(pa, l, i - 1);
	}
	if (i < r) {
		Quicksort(pa, i, r);
	}
}
//tim kiem nhi phan
int search(int* pa, int n, int x, int l, int r) {
	/*int* b = new int[n];
	for (int i = 0; i < n; i++) {
		pa[i] = b[i];
	}
	Quicksort(b, 0, n - 1);*/
	int pivot = (l + r) / 2;
	if (pa[pivot] == x) return pivot;
	if (l > r) return -1;
	return search(pa, n, x, l, pivot - 1);
	return search(pa, n, x, pivot, r);
}
//3
bool Primme(int n) {
	if (n < 1 || n == 1) return false;
	if (n == 2 || n == 3) return true;
	for (int i = 2; i < (int)sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void ListPrimme(int* pa, int n) {
	int x; cout << "Nhap n: "; cin >> x;
	for (int i = 0; i < n; i++) {
		if (Primme(pa[i]) && pa[i] < x) cout << pa[i] << " ";
	}
	cout << endl;
}
//4
void Frequence(int* pa, int n) {
	map<int, int> freq;//dung map de dem tan so
	for (int i = 0; i < n; i++) {
		freq[pa[i]]++;
	}
	for (auto i : freq) {
		cout << i.first << " xuat hien " << i.second << " lan " << endl;
	}
}
//5
void Arr(int* p, int n) {
	int l = 0, r = 0;
	int i = 0;
	int count = 0;
	int* arr = new int[n];
	int* arr1 = new int[n];
	int l1 = 0, r1 = 0, count1 = 0;
	while (i < n - 1) {
		if (p[i] > p[i + 1]) {
			if (count == 0) l = i;
			arr[count] = p[i];
			count++;
		}
		else {
			r = i;
			count++;
			arr[count] = p[i];
			if (count > count1) {
				l1 = l;
				r1 = r;
				count1 = count;
				for (int x = 0; x < count; x++) {
					arr1[x] = arr[x];
				}
			}
			count = 0;
		}
		i++;
	}
	cout << "Mang con dam dan co do dai dai nhat la: " << endl;
	for (int x = 0; x < count1; x++) {
		cout << arr1[x] << " ";
	}
	cout << endl << "Bat dau tu vi tri so " << l1 + 1 << " va ket thuc tai vi tri so " << r1 + 1 << endl;
}
void print(int* pa, int n) {
	for (int i = 0; i < n; i++) {
		cout << pa[i] << " ";
	}
}
void menu() {
	cout << "                     Menu                  " << endl;
	cout << "*******************************************" << endl;
	cout << "0. Thoat." << endl;
	//	cout << "1. Xuat danh sach." << endl;
	cout << "1. Quick sort." << endl;
	cout << "2. Search." << endl;
	cout << "3. Liet ke primme < n." << endl;
	cout << "4. So lan xuat hien cac so trong mang." << endl;
	cout << "5. Day con giam dai nhat" << endl;
	cout << "6. Phan tu co chua chu so cua x " << endl;
	cout << "********************************************" << endl;
	cout << "\tOPTION: ";
}
//6
int dem(int n) {
	int count = 0;
	while (n) {
		count++;
		n /= 10;
	}
	return count;
}
bool CheckHave(int a, int b) {//kt  cac chu so cua a co trong b
	if (b > -10 && b < 10) return false;
	int a1 = a % 10; bool check1 = false;
	a /= 10;
	int a2 = a % 10; bool check2 = false;
	//int c = 0;
	while (b) {
		int x = b % 10;
		if (x == a1) check1 = true;
		if (x == a2) check2 = true;
		b /= 10;
	}
	if (check1 == true && check2 == true) return true;
	return false;
}
int main() {
	int n;
	do {
		cout << "Nhap so luong phan tu (>15):"; cin >> n;
	} while (n < 15);
	int* pa = Create(n);
	int z;
	do {
		print(pa, n);
		cout << endl;
		menu();
		cin >> z;
		cout << "\n\n";
		switch (z) {
		case 1: {
			int* b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = pa[i];
			}
			Quicksort(b, 0, n - 1);
			print(b, n);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			int x;
			cout << "Nhap phan tu can tim kiem: "; cin >> x;
			int* b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = pa[i];
			}
			int pos = search(b, n, x, 0, n - 1);
			if (pos == -1) cout << "Khong ton tai!" << endl;
			else {
				cout << "Vi tri: " << pos + 1 << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			ListPrimme(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			Frequence(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			Arr(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			int x;
			cout << "Nhap so a: ", cin >> x;
			cout << "Cac so thoa dieu kien trong mang la: ";
			for (int i = 0; i < n; i++) {
				if (CheckHave(x, pa[i])) {
					cout << pa[i] << " ";
				}
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
	cout << "\n";
	system("pause");
	return 0;
}