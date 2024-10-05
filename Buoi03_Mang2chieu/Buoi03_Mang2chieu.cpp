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
void printSide(int** pa, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
				cout << setw(03) << right << pa[i][j] << " ";
			else
				cout << setw(04) << right << " ";
		}
		cout << endl << endl;
	}
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
	for (int i = 0; i < m; i++) {
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q[i][j].Main == false)
				cout << setw(03) << right << "F ";
			else cout << setw(03) << right << "T ";
		}
		cout << endl << endl;
	}
	bool cnt = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q[i][j].Main && q[i][j].Extra && q[i][j].Col && q[i][j].Row) {
				cout << "Phan tu queen la: ";
				cout << "Phan tu co gia tri: " << pa[i][j] << " tai toa do: "
					<< i+1 << " " << j+1 << endl;
				cnt = true;
			}
		}
	}
	if (!cnt) cout << "Khong ton tai phan tu queen!" << endl;
	//delete[] q;
}
int main() {
	int m, n;
	cin >> n >> m;
	int** pa = Crreate(n, m);
	printArr(pa, n, m);
	cout << endl;
	cout << endl;
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
	CheckQueen(pa, n, m);
	/*do {
		int** pa = Crreate(5, 5);
	printArr(pa, 5, 5);
	cout << endl;
	cout << endl;
	CheckQueen(pa, 5, 5);
	system("pause");
	system("cls");
	} while (1);*/
	return 0;
}