#include <iostream>//bai toan chia keo....
using namespace std;

// Hàm tính giai thừa
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Hàm tính số tổ hợp C(n, k)
long long combination(int n, int k) {
    if (k > n || k < 0) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Hàm chính để tính số cách chia kẹo
long long waysToDistributeCandies(int m, int n) {
    // Điều kiện m >= 2 * n
    if (m < 2 * n) {
        cout << "Khong the chia keo theo yeu cau." << endl;
        return 0;
    }

    // Tính số cách chia kẹo cho n người
    // Số kẹo tối thiểu cho người cuối cùng là y, số kẹo còn lại là m - (n * y)
    int y = (m - n) / n; // Mỗi người ít nhất 1 viên
    int remainingCandies = m - (n * y);

    // Tính số cách
    return combination(remainingCandies + n - 1, n - 1);
}

int main() {
    int m, n;
    cout << "Nhap so keo (m): ";
    cin >> m;
    cout << "Nhap so nguoi (n): ";
    cin >> n;

    long long result = waysToDistributeCandies(m, n);
    cout << "So cach chia keo: " << result << endl;

    return 0;
}
