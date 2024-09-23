#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int main() {
	int a[100], b[100];
	srand(time(NULL));
	cout << "So luong phan tu: "; int n; cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
		b[i] = rand() % 1000;
	}
	cout << "\na: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\nb: ";
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			try {
				if (b[j] == 0) {
					throw "Loi chia 0";
				}
				else {
					cout << a[i] << " / " << b[i] << " = " << 1.00 * a[i] / b[j]<<endl;
				}
			}
			catch (const char* str) {
				cout << a[i] << " / " << b[i] << " = ";
				cout << str;
			}
		}
	}
	return 0;
}