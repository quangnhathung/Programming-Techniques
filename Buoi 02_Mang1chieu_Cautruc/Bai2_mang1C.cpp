#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<ostream>
using namespace std;
//Tao cau truc phan so
struct Honso {
	int Phannguyen;
	int tu;
	int mau;
};
void InputRandom(Honso a[], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		//random tu -99 -> 100
		Honso z;
		z.Phannguyen = rand() % 100;
		z.tu = -99 + rand() % (100 - -99 + 1);
		z.mau = -99 + rand() % (100 - -99 + 1);
		a[i] = z;
		while (z.mau == 0) {//random ra mau =0 thi nhap lai
			z.mau = -99 + rand() % (100 - -99 + 1);
		}
		a[i] = z;
	}
	cout << "successfully!!" << endl;
}
//toi gian phan so
int UCLN(int a, int b) {//tim ucln
	/*a = abs(a);
	b = abs(b);
	while (a != b) {
	if (a > b) {
	a -= b;
	}
	else {
	b -= a;
	}
	}
	return a;*/
	int ucln = 1;
	for (int i = 1; i <= a || i <= b; i++) {
		if (a % i == 0 && b % i == 0) ucln = i;
	}
	return ucln;
}
void SimplifyFraction(Honso& a) {
	while (UCLN(a.tu, a.mau) != 1) {
		int x = UCLN(a.tu, a.mau);
		a.tu /= x;
		a.mau /= x;
	}
}
//dinh dang phan so (tu +,mau- thi doi dau/tu, mau - thi doi thanh +
void format(Honso& a) {
	if (a.mau == 0) return;
	if (a.tu > 0 && a.mau < 0) {
		a.tu *= -1;
		a.mau *= -1;
	}
	if (a.tu < 0 && a.mau < 0) {
		a.tu *= -1;
		a.mau *= -1;
	}
	if (a.tu > a.mau) {
		a.tu /= a.mau;
		a.Phannguyen += a.tu % a.mau;
	}
	SimplifyFraction(a);
	return;
}
int tru(int a, int b, int c, int d) {
	return a * d - b * c;
}
int ssfraction(Honso a, Honso b) {
	if (a.Phannguyen > b.Phannguyen) {
		return 1;
	}
	else if (a.Phannguyen < b.Phannguyen) {
		return -1;
	}
	else {
		int x = tru(a.tu, a.mau, b.tu, b.mau);
		if (x < 0) return -1;
		if (x == 0) return 0;
		return 1;
	}
}

//Xuat dand sach hon so
void PrintList(Honso* a, int n) {
	for (int i = 0; i < n; i++) {
		format(a[i]);
		cout << a[i].Phannguyen << "(";
		if (a[i].mau == 1) cout << a[i].tu << " ";
		else if (a[i].tu == 0) cout << "0  ";
		else cout << a[i].tu << "/" << a[i].mau;
		cout << ")  ";
	}
	cout << endl;
}

void ConvertHtoFract(Honso a) {
	Honso b;
	a.tu += a.mau * a.Phannguyen;
	a.Phannguyen = 0;
	b = a;
	if (b.mau == 1) cout << b.tu << "  ";
	else if (b.tu == 0) cout << "0  ";
	else cout << b.tu << "/" << b.mau << "  ";
	cout << ")  ";
}

void ConvertFracttoH(Honso a) {
	Honso b;
	format(a);
	cout << a.Phannguyen << "(";
	if (a.mau == 1) cout << a.tu << "  ";
	else if (a.tu == 0) cout << "0  ";
	else cout << a.tu << "/" << a.mau << "  ";
	cout << ")";
}
Honso Convert(Honso a) {
	Honso b;
	a.tu += a.mau * a.Phannguyen;
	a.Phannguyen = 0;
	b = a;
	return b;
}
void calulate(Honso a, Honso b) {

	Honso c;
	cout << "Phep cong tru nhan chia co ket qua lan luot la: ";
	a = Convert(a);
	b = Convert(b);
	//cong
	c.tu = a.tu * b.mau + b.tu * a.mau;
	c.mau = a.mau * b.mau;
	format(c);
	cout << c.Phannguyen << "(";
	if (c.mau == 1) cout << c.tu << "  ";
	else if (c.tu == 0) cout << "0  ";
	else cout << c.tu << "/" << c.mau << "  ";
	cout << ")";
	//tru
	c.Phannguyen = 0;
	c.tu = a.tu * b.mau - b.tu * a.mau;
	c.mau = a.mau * b.mau;
	format(c);
	cout << c.Phannguyen << "(";
	if (c.mau == 1) cout << c.tu << "  ";
	else if (c.tu == 0) cout << "0  ";
	else cout << c.tu << "/" << c.mau << "  ";
	cout << ")";
	//nhan 
	c.Phannguyen = 0;
	c.tu = a.tu * b.tu;
	c.mau = a.mau * b.mau;
	format(c);
	cout << c.Phannguyen << "(";
	if (c.mau == 1) cout << c.tu << "  ";
	else if (c.tu == 0) cout << "0  ";
	else cout << c.tu << "/" << c.mau << "  ";
	cout << ")";
	//chia
	c.Phannguyen = 0;
	c.tu = a.tu * b.mau;
	c.mau = a.mau * b.tu;
	format(c);
	cout << c.Phannguyen << "(";
	if (c.mau == 1) cout << c.tu << "  ";
	else if (c.tu == 0) cout << "0  ";
	else cout << c.tu << "/" << c.mau << "  ";
	cout << ")";
}
void swap(Honso& a, Honso& b) {
	Honso temp = a;
	a = b;
	b = temp;
}
//quick sort
int Patition(Honso* a, int l, int r) {
	int pivot = (l + r) / 2;
	while (l <= r) {
		while (ssfraction(a[l], a[pivot]) == -1) {
			l++;
		}
		while (ssfraction(a[r], a[pivot]) == 1) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	return l;
}
void QuickSort(Honso* a, int l, int r) {
	int i = Patition(a, l, r);
	if (l >= r) return;
	if (l < i - 1) {
		QuickSort(a, l, i);
	}
	if (i < r) {
		QuickSort(a, i, r);
	}
}
//six

int Six(Honso* pa, Honso x, int n, int l, int r) {
	int pivot = (l + r) / 2;
	if (l > r) return -1;
	if (l<r && ssfraction(pa[pivot], x) == 0) return pivot;
	return Six(pa, x,n, 0, pivot);
	return Six(pa, x, n, pivot, n - 1);

}
void sevent(Honso* pa, int n) {
	int l = 0, r = n - 1;
	while (l < r) {
		while (pa[l].Phannguyen%2 == 0) {
			l++;
		}
		while (pa[r].Phannguyen%2 != 0) {
			r--;
		}
		if (l <= r) {
			swap(pa[l], pa[r]);
			l++;
			r--;
		}
	}
}
int* eight(Honso* pa, int n) {
	int* pb = new int[n];
	for (int i = 0; i < n; i++) {
		pb[i] = pa[i].Phannguyen;
	}
	return pb;
}
Honso* nine(Honso* pa, int &n, int k) {
	Honso* pb = new Honso[n - 1];
	n--;
	if (k < 0 || k >= n) return pa;
	int j = 0;
	for (int i = 0; i < n-1; i++) {
		if (i == k) {
			j++;
			pb[i] = pa[j];
			j++;
		}
		else {
			pb[i] = pa[j];
			j++;
		}
	}
	delete[] pa;
	return pb;
}
Honso* ten(Honso* pa, int &n, Honso x, int k) {
	Honso* pb = new Honso[n + 1];
	if (k < 0 || k >= n) return pa;
	int j = 0;
	for (int i = 0; i < n+1; i++) {
		if (i == k) {
			pb[i] = x;
		}
		else {
			pb[i] = pa[j];
			j++;
		}
	}
	delete[] pa;
	return pb;
}
void eleven(Honso* pa, int n) {
	cout << "Vi tri: ";
	for (int i = 0; i < n; i++) {
		if (pa[i].Phannguyen % 2 == 0) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}
void menu() {
	cout << "                     Menu                  " << endl;
	cout << "*******************************************" << endl;
	cout << "0. Thoat." << endl;
	//	cout << "1. Xuat danh sach." << endl;
	cout << "1. So sanh." << endl;
	cout << "2. chuyen hon so thanh phan so." << endl;
	cout << "3. Chuyen phan so thanh hon so." << endl;
	cout << "4. tinh toan 2 phan so." << endl;
	cout << "5. Sap xep tang dan" << endl;
	//******************
	cout << "6. Tim phan tu x (tim kiem nhi phan) "<< endl;
	cout << "7. Nguyeen chan len dau" << endl;
	cout << "8. Chia 2 mang nguyen_phanso " << endl;
	cout << "9.Xoa phan tu thu k" << endl;
	cout << "10.Them hon so x vao index" << endl;
	cout << "11. Vi tri cua phan tu co phan nguyen chan" << endl;
	cout << "********************************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	int n;
	srand(time(NULL));
	cout << "So luong phan tu ban can: "; cin >> n;
	Honso* pa = new Honso[n];
	InputRandom(pa, n);
	int z;
	do {
		PrintList(pa, n);
		menu();
		cin >> z;
		cout << "\n\n";
		switch (z) {
		case 1: {
			int i, j;
			cout << endl;
			cout << "Nhapj vi tri 2 so ban can so sanh: "; cin >> i >> j;
			if (ssfraction(pa[i], pa[i]) == 0) cout << "bang nhau";
			else if (ssfraction(pa[i], pa[i]) == -1) cout << "be how";
			else cout << "lon hon" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			Honso a;
			cout << "Nhap tu"; cin >> a.tu;
			cout << "nhap mau:"; cin >> a.mau;
			cout << "Nhap phan nguyen: "; cin >> a.Phannguyen;
			ConvertHtoFract(a);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			Honso a;
			cout << "Nhap tu"; cin >> a.tu;
			cout << "nhap mau:"; cin >> a.mau;
			a.Phannguyen = 0;
			ConvertFracttoH(a);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			int i, j;
			cout << endl;
			cout << "Nhapj vi tri 2 so ban can tinh toan: "; cin >> i >> j;
			calulate(pa[i], pa[j]);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			QuickSort(pa, 0, n - 1);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			Honso a;
			cout << "Nhap tu"; cin >> a.tu;
			cout << "nhap mau:"; cin >> a.mau;
			cout << "Nhap phan nguyen: "; cin >> a.Phannguyen;
			int pos = Six(pa, a, n, 0, n - 1);
			if (pos == -1) cout << "Khong ton tai" << endl;
			else cout << "O vi tri: " << pos+1 << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			sevent(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			int* b = eight(pa, n);
			for (int i = 0; i < n; i++) {
				cout << b[i] << " ";
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9: {
			int k;
			cout << "Nhap vi tri muon xoa: "; cin >> k;
			pa = nine(pa, n, k-1);
			system("pause");
			system("cls");
			break;
		}
		case 10: {
			Honso a;
			cout << "Nhap tu"; cin >> a.tu;
			cout << "nhap mau:"; cin >> a.mau;
			cout << "Nhap phan nguyen: "; cin >> a.Phannguyen;
			cout << "Nhap vi tri them: "; int k; cin >> k;
			pa = ten(pa, n, a, k-1);
			system("pause");
			system("cls");
			break;
		}
		case 11: {
			eleven(pa, n);
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