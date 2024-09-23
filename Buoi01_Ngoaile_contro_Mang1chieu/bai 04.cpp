#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	int n;
	cout << "Nhap so luong phan tu: "; cin >> n;
	int *a = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++){
		a[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}