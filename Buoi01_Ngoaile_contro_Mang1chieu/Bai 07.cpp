#include<iostream>
#include<ctime>
#include<cstdlib>
#define DEFAULT 0
using namespace std;
int Max(int* pa, int n) {
	int Max = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] > pa[Max]) Max = i;
	}
	return Max;
}
void ban(int* a, int n) {
	int chanmax = DEFAULT;
	int lemin = DEFAULT;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0 && a[i] > a[chanmax]) {
			chanmax = i;
		}
		else if (a[i] % 2 != 0 && a[i] < a[lemin]) {
			lemin = i;
		}
	}
	if (a[chanmax] == DEFAULT && a[chanmax] % 2 != 0) {
		cout << "Khong co so chan trong mang";
	}
	else cout << "So chan lon nhat trong mang la: " << a[chanmax] << " Dia chi: " << &a[chanmax];
	if (a[lemin] == DEFAULT && a[lemin] % 2 == 0) {
		cout <<endl<< "Khong co so le trong mang";cout <<endl<< "So le lon nhat trong mang la: " << a[lemin] << " Dia chi: " << &a[lemin];
	}
	else cout << endl << "So le nho nhat trong mang la: " << a[lemin] << " Dia chi: " << &a[lemin];
}
int* insert(int* pa, int &n, int x) {
	int* pb = new int[n + 1];
	pb[0] = pa[0];
	for (int i = 1; i < n; i++) {
		pb[i+1] = pa[i];
	}
	pb[1] = x;
	delete[] pa;
	int* px = new int[n + 1];
	n++;
	for (int i = 0; i < n; i++) {
		px[i] = pb[i];
	}
	return px;
}

void xuat(int* pa, int n) {
	cout << "Cac so cuc dai la: ";
	for (int i = 0; i < (n-1); i++) {
		if ((i == 0 && pa[i] > pa[i + 1]) || (i == n - 1 && pa[i] > pa[i - 1])) {
			cout << pa[i] << " ";
		}
		else if (pa[i] > pa[i - 1] && pa[i] > pa[i + 1]) {
			cout << pa[i]<<" ";
		}
	}
}
void MeaNdU() {
	cout << "               Menu            "<<endl;
	cout << "*******************************" << endl;
	cout << "0. Thoat." << endl;
	cout << "1. Phan tu lon nhat." << endl;
	cout << "2. Chan lon nhat, le nho nhat." << endl;
	cout << "3. Them vao xau pt dau." << endl;
	cout << "4. Xuat cac so cuc dai." << endl;
	cout << "*******************************" << endl;
	cout << "\tOPTION: ";
}
int main() {
	int n;
	srand(time(NULL));
	cout << "So luong phan tu ban can: "; cin >> n;
	int* pa = new int[n];
	for (int i = 0; i < n; i++) {
		pa[i] = rand() % 100;
	}
	int z;
	do {
		cout << "Phan tu hien tai: ";
		for (int i = 0; i < n; i++) {
			cout << pa[i]<<" ";
		}
		cout << endl;
		MeaNdU();
		cin >> z;
		cout << "\n\n";
		switch (z) {
		case 1: {
			cout << "Phan tu thu " << Max(pa, n) +1<< " lon nhat" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			ban(pa, n);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			int x;
			cout << "Nhap phan tu can them: "; cin >> x;
			int* px = insert(pa,n,x);
			for (int i = 0; i < n; i++) {
				cout << px[i] << " ";
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			xuat(pa, n);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	} while (z != 0);
}