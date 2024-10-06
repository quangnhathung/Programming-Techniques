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
#include<tuple>
using namespace std;
int** Crreate(int n, int m) {
	int** pa = new int* [n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		pa[i] = new int[m];
		for (int j = 0; j < m; j++) {
			pa[i][j] = -99 + rand() % (-99 - 100 + 1);
		}
	}
	return pa;
}
void printArr(int** pa, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(03) << right << pa[i][j] << " ";
		}
		cout << endl << endl;
	}
}
int printSide(int** pa, int n, int m) {
	int max = -999;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				cout << setw(03) << right << pa[i][j] << " ";
				if (pa[i][j] > max) max = pa[i][j];
			}
			else
				cout << setw(04) << right << " ";
		}
		cout << endl << endl;
	}
	return max;
}
struct pos {
	int row;
	int col;
};
//phan tu cuc dai
void MaximumElement(int** pa, int n, int m) {
	cout << "Cac phan tu cuc dai la: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				if (j == 0) {
					if (pa[i][j] > pa[i + 1][j + 1]
						&& pa[i][j] > pa[i + 1][j]
						&& pa[i][j] > pa[i][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else if (j == m - 1) {
					if (pa[i][j] > pa[i][j - 1]
						&& pa[i][j] > pa[i + 1][j]
						&& pa[i][j] > pa[i + 1][j - 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else {
					if (pa[i][j] > pa[i][j - 1]
						&& pa[i][j] > pa[i][j + 1]
						&& pa[i][j] > pa[i + 1][j - 1]
						&& pa[i][j] > pa[i + 1][j]
						&& pa[i][j] > pa[i + 1][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
			}
			//i=n-1
			else if (i == n - 1) {
				if (j == 0) {
					if (pa[i][j] > pa[i - 1][j]
						&& pa[i][j] > pa[i - 1][j + 1]
						&& pa[i][j] > pa[i][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else if (j == m - 1) {
					if (pa[i][j] > pa[i - 1][j]
						&& pa[i][j] > pa[i - 1][j - 1]
						&& pa[i][j] > pa[i][j - 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else {
					if (pa[i][j] > pa[i - 1][j]
						&& pa[i][j] > pa[i - 1][j - 1]
						&& pa[i][j] > pa[i - 1][j + 1]
						&& pa[i][j] > pa[i][j - 1]
						&& pa[i][j] > pa[i][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
			}
			else if (j == 0 && i != 0 && i != n - 1) {
				if (pa[i][j] > pa[i - 1][j]
					&& pa[i][j] > pa[i - 1][j + 1]
					&& pa[i][j] > pa[i][j + 1]
					&& pa[i][j] > pa[i + 1][j + 1]
					&& pa[i][j] > pa[i + 1][j]) {
					cout << setw(03) << right << pa[i][j] << " ";
				}
			}
			else if (j == m - 1 && i != 0 && i != n - 1) {
				if (pa[i][j] > pa[i - 1][j]
					&& pa[i][j] > pa[i - 1][j - 1]
					&& pa[i][j] > pa[i][j - 1]
					&& pa[i][j] > pa[i + 1][j - 1]
					&& pa[i][j] > pa[i + 1][j]) {
					cout << setw(03) << right << pa[i][j] << " ";
				}
			}
			else {
				if (pa[i][j] > pa[i - 1][j]
					&& pa[i][j] > pa[i - 1][j - 1]
					&& pa[i][j] > pa[i][j - 1]
					&& pa[i][j] > pa[i + 1][j - 1]
					&& pa[i][j] > pa[i + 1][j]
					&& pa[i][j] > pa[i - 1][j + 1]
					&& pa[i][j] > pa[i][j + 1]
					&& pa[i][j] > pa[i + 1][j + 1]) {
					cout << setw(03) << right << pa[i][j] << " ";
				}
			}
			//cout << setw(03) << right << pa[i][j] << " ";
		}
	}
}
//phan tu cuc tieu
void MinimumElement(int** pa, int n, int m) {
	cout << "Cac phan tu cuc tieu la: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0) {
				if (j == 0) {
					if (pa[i][j] < pa[i + 1][j + 1]
						&& pa[i][j] < pa[i + 1][j]
						&& pa[i][j] < pa[i][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else if (j == m - 1) {
					if (pa[i][j] < pa[i][j - 1]
						&& pa[i][j] < pa[i + 1][j]
						&& pa[i][j] < pa[i + 1][j - 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else {
					if (pa[i][j] < pa[i][j - 1]
						&& pa[i][j] < pa[i][j + 1]
						&& pa[i][j] < pa[i + 1][j - 1]
						&& pa[i][j] < pa[i + 1][j]
						&& pa[i][j] < pa[i + 1][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
			}
			//i=n-1
			else if (i == n - 1) {
				if (j == 0) {
					if (pa[i][j] < pa[i - 1][j]
						&& pa[i][j] < pa[i - 1][j + 1]
						&& pa[i][j] < pa[i][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else if (j == m - 1) {
					if (pa[i][j] < pa[i - 1][j]
						&& pa[i][j] < pa[i - 1][j - 1]
						&& pa[i][j] < pa[i][j - 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
				else {
					if (pa[i][j] < pa[i - 1][j]
						&& pa[i][j] < pa[i - 1][j - 1]
						&& pa[i][j] < pa[i - 1][j + 1]
						&& pa[i][j] < pa[i][j - 1]
						&& pa[i][j] < pa[i][j + 1]) {
						cout << setw(03) << right << pa[i][j] << " ";
					}
				}
			}
			else if (j == 0 && i != 0 && i != n - 1) {
				if (pa[i][j] < pa[i - 1][j]
					&& pa[i][j] < pa[i - 1][j + 1]
					&& pa[i][j] < pa[i][j + 1]
					&& pa[i][j] < pa[i + 1][j + 1]
					&& pa[i][j] < pa[i + 1][j]) {
					cout << setw(03) << right << pa[i][j] << " ";
				}
			}
			else if (j == m - 1 && i != 0 && i != n - 1) {
				if (pa[i][j] < pa[i - 1][j]
					&& pa[i][j] < pa[i - 1][j - 1]
					&& pa[i][j] < pa[i][j - 1]
					&& pa[i][j] < pa[i + 1][j - 1]
					&& pa[i][j] < pa[i + 1][j]) {
					cout << setw(03) << right << pa[i][j] << " ";
				}
			}
			else {
				if (pa[i][j] < pa[i - 1][j]
					&& pa[i][j] < pa[i - 1][j - 1]
					&& pa[i][j] < pa[i][j - 1]
					&& pa[i][j] < pa[i + 1][j - 1]
					&& pa[i][j] < pa[i + 1][j]
					&& pa[i][j] < pa[i - 1][j + 1]
					&& pa[i][j] < pa[i][j + 1]
					&& pa[i][j] < pa[i + 1][j + 1]) {
					cout << setw(03) << right << pa[i][j] << " ";
				}
			}
			//cout << setw(03) << right << pa[i][j] << " ";
		}
	}
}
//queen
struct queen {
	bool Row = false;
	bool Col = false;
	bool Main = false;
	bool Extra = false;
};
//Ktra cootj
void MaxCol(int** pa, int n, int col, queen**& q) {
	pos a;
	a.row = 0;
	a.col = col;
	for (int i = 0; i < n - 1; i++) {
		if (pa[i + 1][col] > pa[a.row][col]) {
			a.row = i + 1;
		}
	}
	q[a.row][a.col].Col = true;
}
//ktra hangf
void MaxRow(int** pa, int row, int m, queen**& q) {
	pos a;
	a.row = row;
	a.col = 0;
	for (int i = 0; i < m - 1; i++) {
		if (pa[row][i + 1] > pa[row][a.col]) {
			a.col = i + 1;
		}
	}
	q[a.row][a.col].Row = true;
}
//ktra cheo chinh
void MaxMain(int** pa, int n, int m, queen**& q) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pos a;
			//a.row = i;
			//a.col = j;
			int x = i;
			int y = j;
			bool check = true;//ktra pt cos lon nhat hay k
			while (x > 0 && y > 0) {
				if (pa[x - 1][y - 1] > pa[i][j]) {
					check = false;
					break;
				}
				x--;
				y--;
			}
			if (check == false) {
				continue;
			}
			x = i;
			y = j;
			while (x < n - 1 && y < m - 1) {
				if (pa[x + 1][y + 1] > pa[i][j]) {
					check = false;
					break;
				}
				x++;
				y++;
			}
			if (check) {
				q[i][j].Main = true;
			}
		}
	}
}
//kiem tra cheo phu
void MaxExtra(int** pa, int n, int m, queen**& q) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pos a;
			//a.row = i;
			//a.col = j;
			int x = i;
			int y = j;
			bool check = true;//ktra pt cos lon nhat hay k
			while (x < n - 1 && y > 0) {
				if (pa[x + 1][y - 1] > pa[i][j]) {
					check = false;
					break;
				}
				x++;
				y--;
			}
			if (check == false) {
				continue;
			}
			x = i;
			y = j;
			while (x > 0 && y < m - 1) {
				if (pa[x - 1][y + 1] > pa[i][j]) {
					check = false;
					break;
				}
				x--;
				y++;
			}
			if (check) {
				q[i][j].Extra = true;
			}
		}
	}
}
void CheckQueen(int** pa, int n, int m) {
	queen** q = new queen * [n];
	for (int i = 0; i < n; i++) {
		q[i] = new queen[m];
	}
	for (int i = 0; i < m; i++) {//setupcot
		MaxCol(pa, n, i, q);
	}
	for (int i = 0; i < n; i++) {//setuphang
		MaxRow(pa, i, m, q);
	}
	MaxMain(pa, n, m, q);
	MaxExtra(pa, n, m, q);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q[i][j].Main == false)
				cout << setw(03) << right << "F ";
			else cout << setw(03) << right << "T ";
		}
		cout << endl << endl;
	}*/
	bool cnt = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q[i][j].Main && q[i][j].Extra && q[i][j].Col && q[i][j].Row) {
				cout << "Phan tu queen la: ";
				cout << "Phan tu co gia tri: " << pa[i][j] << " tai toa do: "
					<< i + 1 << " " << j + 1 << endl;
				cnt = true;
			}
		}
	}
	if (!cnt) cout << "Khong ton tai phan tu queen!" << endl;
	for (int i = 0; i < n; i++) {
		delete[] q[i];
	}
	delete[] q;
}
// phan tu yen ngua
struct Saddle {
	bool RowMin = false;
	bool ColMin = false;
	bool RowMax = false;
	bool ColMax = false;
};

void MinColSaddle(int** pa, int n, int col, Saddle**& q) {
	pos a;
	a.row = 0;
	a.col = col;
	for (int i = 0; i < n - 1; i++) {
		if (pa[i + 1][col] < pa[a.row][col]) {
			a.row = i + 1;
		}
	}
	q[a.row][a.col].ColMin = true;
}
void MaxColSaddle(int** pa, int n, int col, Saddle**& q) {
	pos a;
	a.row = 0;
	a.col = col;
	for (int i = 0; i < n - 1; i++) {
		if (pa[i + 1][col] > pa[a.row][col]) {
			a.row = i + 1;
		}
	}
	q[a.row][a.col].ColMax = true;
}
//ktra hangf
void MaxRowSaddle(int** pa, int row, int m, Saddle**& q) {
	pos a;
	a.row = row;
	a.col = 0;
	for (int i = 0; i < m - 1; i++) {
		if (pa[row][i + 1] > pa[row][a.col]) {
			a.col = i + 1;
		}
	}
	q[a.row][a.col].RowMax = true;
}
void MinRowSaddle(int** pa, int row, int m, Saddle**& q) {
	pos a;
	a.row = row;
	a.col = 0;
	for (int i = 0; i < m - 1; i++) {
		if (pa[row][i + 1] < pa[row][a.col]) {
			a.col = i + 1;
		}
	}
	q[a.row][a.col].RowMin = true;
}
void CheckSaddle(int** pa, int n, int m) {
	Saddle** s = new Saddle * [n];
	for (int i = 0; i < n; i++) {
		s[i] = new Saddle[m];
	}
	//set up
	for (int i = 0; i < n; i++) {
		MinRowSaddle(pa, i, m, s);
		MaxRowSaddle(pa, i, m, s);
	}
	for (int i = 0; i < m; i++) {
		MinColSaddle(pa, n, i, s);
		MaxColSaddle(pa, n, i, s);
	}
	bool check = false;//ktra co phan tu yen ngua hay k
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((s[i][j].ColMax && s[i][j].RowMin) //nho dong lon cot
				|| (s[i][j].RowMax && s[i][j].ColMin)) {//lon dong nho cot
				cout << "Phan tu gia tri: " << pa[i][j] << " co toa do la "
					<< i + 1 << " " << j + 1 << " la phan tu yen ngua." << endl;
				check = true;
			}
		}
	}
	if (check == false) cout << "Khong co phan tu yen ngua." << endl;
	for (int i = 0; i < n; i++) {
		delete[] s[i];
	}
	delete[] s;
}
//ktra 1 hangf co toan so chan hay khong
bool CheckEven(int m, int* a) {
	int i = 0;
	while (i < m) {
		if (a[i] % 2 != 0) return false;
		i++;
	}
	return true;
}
//ascending tang dần
void AscendingRow(int* a, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
////decending giam dần
void DecendingRow(int* a, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
//gia tri xuat hien nhieu nhat trong ma tran
//dung map
struct dou {
	int cnt = 0;
	int first[100];
	int second;
};
dou FreqMax(int** pa, int n, int m) {
	dou Element;
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			freq[pa[i][j]]++;
		}
	}
	Element.second = -1;
	for (auto it : freq) {
		if (it.second >= Element.second) {
			if (it.second == Element.second) {
				Element.first[Element.cnt] = it.first;
				Element.second = it.second;
				Element.cnt++;
			}
			else {
				Element.cnt = 1;
				Element.first[0] = it.first;
				Element.second = it.second;
				//Element.cnt++;
			}
		}
	}
	return Element;
}
//num
dou FreqMaxNum(int** pa, int n, int m) {
	dou Element;
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = pa[i][j];
			if (temp < 0) temp *= -1;
			while (temp) {
				freq[temp % 10]++;
				temp /= 10;
			}
		}
	}
	Element.second = -1;
	for (auto it : freq) {
		if (it.second >= Element.second) {
			if (it.second == Element.second) {
				Element.first[Element.cnt] = it.first;
				Element.second = it.second;
				Element.cnt++;
			}
			else {
				Element.cnt = 1;
				Element.first[0] = it.first;
				Element.second = it.second;
				//Element.cnt++;
			}
		}
	}
	return Element;
}
void menu() {
	cout << "                     Menu                  " << endl;
	cout << "*******************************************" << endl;
	cout << "0. Thoat." << endl;
	//	cout << "1. Xuat danh sach." << endl;
	cout << "1. Xuat cac gia tri bien ben ngoai cung" << endl;
	cout << "2. Phan tu cuc dai" << endl;
	cout << "3. Xuat phan tu queen" << endl;
	cout << "4. Xuat yen ngua" << endl;
	cout << "5. Xuat dong chi chua so chan" << endl;
	cout << "6. Sap tang theo tung dong" << endl;
	//**********
	cout << "7. Phan tu lon nhat bien." << endl;
	cout << "8. Phan tu cuc tieu cua ma tran" << endl;
	cout << "9. kiem tra ziczac" << endl;
	cout << "10. Gia tri xuat hien nhieu nhat trong ma tran" << endl;
	cout << "11. Chu so xuat hien nhieu nhat trong ma tran" << endl;
	cout << "12. Hoan vi 2 cot bat ki" << endl;
	cout << "********************************************" << endl;
	cout << "\tOPTION: ";
}
//hoan vi
void num12(int**& pa, int n, int m, int c, int v) {
	for (int i = 0; i < n; i++) {
		int temp = pa[i][c];
		pa[i][c] = pa[i][v];
		pa[i][v] = pa[i][c];
	}
}
int main() {
	int m, n;
	cout << "Nhap so hang va cot: ";
	cin >> n >> m;
	int** pa = Crreate(n, m);
	//printArr(pa, n, m);
	//cout << endl;
	//cout << endl;
	////printSide(pa, n, m);
	//MinimumElement(pa, n, m);
	//queen** q = new queen * [n];
	//for (int i = 0; i < m; i++) {
	//	q[i] = new queen[m];
	//}
	//for (int i = 0; i < n; i++) {//setupcot
	//	MaxRow(pa, i, m, q);
	//}
	//for (int i = 0; i < m; i++) {//setupcot
	//		MaxCol(pa, n, i, q);
	//	}
	/*MaxMain(pa, n, m, q);
	MaxExtra(pa, n, m, q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q[i][j].Main == false)
				cout << setw(03) << right << "F ";
			else cout << setw(03) << right << "T ";
		}
		cout << endl << endl;
	}*/
	/*MaxExtra(pa, n, m, q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q[i][j].Main == false)
				cout << setw(03) << right << "F ";
			else cout << setw(03) << right << "T ";
		}
		cout << endl << endl;
	}*/
	//CheckQueen(pa, n, m);
	/*do {
		int** pa = Crreate(5, 5);
		printArr(pa, 5, 5);
		cout << endl;
		cout << endl;
		CheckQueen(pa, 5, 5);
		cout << "\n\n" << endl;
		CheckSaddle(pa, 5, 5);
		system("pause");
		system("cls");
	} while (1);*/
	//cout << "\n\n" << endl;
	//CheckSaddle(pa, n, m);
	int z;
	do {
		printArr(pa, n, m);
		cout << endl;
		menu();
		cin >> z;
		cout << "\n\n";
		switch (z) {
		case 1: {
			printSide(pa, n, m);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			MaximumElement(pa, n, m);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			CheckQueen(pa, n, m);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			CheckSaddle(pa, n, m);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			int x = 0;
			for (int i = 0; i < n; i++) {
				if (CheckEven(m, pa[i])) {
					for (int j = 0; j < m; j++) {
						cout << pa[i][j] << " ";
					}
					x++;
					cout << endl;
				}
			}
			if (x == 0) cout << "Khong hang nao thoa dk!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			for (int i = 0; i < n; i++) {
				AscendingRow(pa[i], m);
			}
			cout << "Done!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			cout << "Phan tu lon nhat la: " << printSide(pa, n, m) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			MinimumElement(pa, n, m);
			system("pause");
			system("cls");
			break;
		}
		case 9: {
			cout << "Khong phai!" << endl;//=))
			system("pause");
			system("cls");
			break;
		}
		case 10: {
			dou element = FreqMax(pa, n, m);
			cout << "Cac phan tu xuat hien nhieu nhat: ";
			for (int i = 0; i < element.cnt; i++)
				cout << element.first[i] << " ";
			cout << "xuat hien " << element.second << " lan." << endl;
			system("pause");
			system("cls");
			break;
		}
		case 11: {
			dou element = FreqMaxNum(pa, n, m);
			cout << "Cac chu so xuat hien nhieu nhat: ";
			for (int i = 0; i < element.cnt; i++)
				cout << element.first[i] << " ";
			cout << "xuat hien " << element.second << " lan." << endl;
			system("pause");
			system("cls");
			break;
		}
		case 12: {
			int c, v;
			cout << "nhap 2 cot can hoan vi: "; cin >> c >> v;
			num12(pa, n, m, c - 1, v - 1);
			printArr(pa, n, m);
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