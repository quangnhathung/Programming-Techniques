#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

//int main() {
//	int n;
//	cout << "Nhap n: "; cin >> n;
//	
//	system("pause");
//	return 0;
//}
void permute(vector<int>& arr, int l, int r) {
	// Khi chỉ số trái (l) bằng chỉ số phải (r), in ra hoán vị hiện tại
	if (l == r) {
		for (int i = 0; i <= r; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else {
		// Duyệt qua các phần tử và thực hiện hoán vị
		for (int i = l; i <= r; i++) {
			swap(arr[l], arr[i]);  // Hoán đổi phần tử tại vị trí l với phần tử tại vị trí i
			permute(arr, l + 1, r);  // Đệ quy với l + 1
			swap(arr[l], arr[i]);  // Hoán đổi lại để quay về trạng thái ban đầu
		}
	}
}

int main() {
	// Tạo dãy số cần hoán vị
	vector<int> arr;
	int x, n;
	cout << "So luong: "; cin >> n;
	cout << "Nhap phan tu: ";
	while (n) {
		cin >> x;
		arr.push_back(x);
		n--;
	}
	int m = arr.size();

	// Gọi hàm hoán vị
	permute(arr, 0, m - 1);

	return 0;
}