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
int** Crreate(int n) {
	int** pa = new int* [n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		pa[i] = new int[n];
		for (int j = 0; j < n; j++) {
			pa[i][j] = -99 + rand() % (-99 - 100 + 1);
		}
	}
	return pa;
}
void printArr(int** pa, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(03) << right << pa[i][j] << "  ";
		}
		cout << endl << endl;
	}
}


struct pos {
	int row;
	int col;
};
//pt max tam giac tren
pos MaxTrig(int** pa, int n) {
	pos max;
	max.row = 0;
	max.col = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (pa[i][j] > pa[max.row][max.col]) {
				max.row = i;
				max.col = j;
			}
		}
	}
	return max;
}
//ascending tang dần
void AscendingArr(int**& pa, int n) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			int j = y;
			for (int i = x; i < n; i++) {
				for (j; j < n; j++) {
					if (pa[i][j] < pa[x][y]) {
						int temp = pa[x][y];
						pa[x][y] = pa[i][j];
						pa[i][j] = temp;
					}
				}
				j = 0;
			}
		}
	}
}

//decending giam dần
void DecendingRow(int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] < a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void Ziczac(int** pa, int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 != 0) DecendingRow(pa[i], n);
	}
}
void MainaAscen(int**& pa, int n) {//tang dan
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (pa[j][j] < pa[i][i]) {
				int temp = pa[i][i];
				pa[i][i] = pa[j][j];
				pa[j][j] = temp;
			}
		}
	}
}
//cheo phu giam dan
void ExtraDec(int**& pa, int n) {
	for (int i = 0, j = n - 1; i < n && j >= 0; j--, i++) {
		for (int x = i, y = j; y >= 0 && x < n; y--, x++) {
			if (pa[i][j] < pa[x][y]) {
				int temp = pa[x][y];
				pa[x][y] = pa[i][j];
				pa[i][j] = temp;
			}
		}
	}
}
//cheo chinh va song saong tang dan
void SortMain(int**& pa, int n) {
	//for (int i = 1, j = i - 1; j < n - i && i < n; j++, i++) {
	//	for (int x = i+1, y = j+1; y < n - x || x < n; y++, x++) {
	//		if (pa[i][j] > pa[x][y]) {
	//			int temp = pa[x][y];
	//			pa[x][y] = pa[i][j];
	//			pa[i][j] = temp;
	//		}
	//	}
	//}
	//MainaAscen(pa, n);
	//for (int i=1, y=i-1; i<n)
	for (int i = 1, j = 0; i < n; i++) {
		for (int i1 = i, j1 = 0; i1 < n; j1++, i1++) {
			for (int i2 = i1, j2 = j1; i2 < n; j2++, i2++) {
				if (pa[i1][j1] > pa[i2][j2]) {
					int temp = pa[i2][j2];
					pa[i2][j2] = pa[i1][j1];
					pa[i1][j1] = temp;
				}
			}
		}
	}
	MainaAscen(pa, n);
	for (int i = 0, j = 1; j < n; j++) {
		for (int i1 = 0, j1 = j; j1 < n; j1++, i1++) {
			for (int i2 = i1, j2 = j1; j2 < n; j2++, i2++) {
				if (pa[i1][j1] > pa[i2][j2]) {
					int temp = pa[i2][j2];
					pa[i2][j2] = pa[i1][j1];
					pa[i1][j1] = temp;
				}
			}
		}
	}
}
void menu() {
	cout << "                     Menu                  " << endl;
	cout << "*******************************************" << endl;
	cout << "0. Thoat." << endl;
	//	cout << "1. Xuat danh sach." << endl;
	cout << "1. Pha tu max tam giac tren cheo chinh" << endl;
	cout << "2. Zigzag" << endl;
	cout << "3. Cheo chinh giam gian tu tren xuong" << endl;
	//*
	cout << "4. Cheo phu giam dan" << endl;
	//	cout << "5. cot chan tang cot le giam" << endl; de qua
	cout << "5. Cheo chinh va song song tang dan" << endl;
	cout << "6. ktra doi xung qua cheo chinh" << endl;
	cout << "********************************************" << endl;
	cout << "\tOPTION: ";
}
//ktra doi xung
bool SymmetryCheck(int** pa, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (pa[i][j] != pa[j][i]) return false;
		}
	}
	return true;
}
int main() {
	int n;
	do {
		cout << "Ma tran cap(>=5): ";
		cin >> n;
	} while (n < 5);
	int** pa = Crreate(n);
	//AscendingArr(pa, n);
	//Ziczac(pa, n);
	//MainaAscen(pa, n);
	//ExtraDec(pa, n);
//	printArr(pa, n);
//	cout << endl;
//	SortMain(pa, n);
	//printArr(pa, 4);
	/*for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << pa[i][j]<<" ";
		}
		cout << endl;
	}*/
	//cout << MaxTrig(pa, n).row <<"  "<< MaxTrig(pa, n).col << endl;
	int z;
	do {
		printArr(pa, n);
		cout << endl;
		menu();
		cin >> z;
		cout << "\n\n";
		switch (z) {
		case 1: {
			cout << "Phan tu lon nhat phia tren duong cheo chinh la: "
				<< pa[MaxTrig(pa, n).row][MaxTrig(pa, n).col] << " toa do: "
				<< MaxTrig(pa, n).row + 1 << " " << MaxTrig(pa, n).col + 1 << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			AscendingArr(pa, n);
			Ziczac(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			MainaAscen(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			ExtraDec(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			SortMain(pa, n);
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			if (SymmetryCheck(pa, n)) cout << "Doi xung" << endl;
			else cout<<" Khong doi xung" << endl;
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