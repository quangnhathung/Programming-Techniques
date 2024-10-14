#include<iostream>
#include<cctype>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;

//ktr ki tu co toan so hay khong
bool CheckstringNum(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) return false;
	}
	return false;
}
//standard
string Dlt_space(string s) {
	string s1;
	bool space = true;
	//true cos roi khog them, false khong co nen them
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			if (space == true) {
				continue;
			}
			else {
				s1 += s[i];
				space = true;
			}
		}
		else {
			s1 += s[i];
			space = false;
		}
	}
	if (s1[s1.size() - 1] == ' ') {
		s1[s1.size() - 1] = '\0';
	}
	return s1;
}
string toLower_string(string s) {

	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) {
			s[i] = tolower(s[i]);
		}
	}
	return s;
}
string Proper(string s) {
	s = toLower_string(s);
	s = Dlt_space(s);
	s[0] = toupper(s[0]);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			s[i + 1] = toupper(s[i + 1]);
		}
	}
	return s;
}
//tach ho ten
struct Info {
	string Ho;
	string TenDem;
	string Ten;
};
//dem khoang trng
int Cnt_space(string s) {
	s = Proper(s);
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') cnt++;
	}
	return cnt;
}
Info GetInfor(string s) {
	s = Proper(s);
	Info a;
	stringstream ss(s);
	getline(ss, a.Ho, ' ');
	//cout << a.Ho << endl;
	int space = Cnt_space(s);
	int i = 2;
	string temp;
	getline(ss, a.TenDem, ' ');
	while (i < space) {
		getline(ss, temp, ' ');
		a.TenDem += " " + temp;
		i++;
	}
	getline(ss, a.Ten, ' ');
	return a;
}
//int find name
bool find(string s, string ten) {
	Info a = GetInfor(s);
	if (a.Ten == ten) return true;
	return false;
}
//tim chuoi p trong t
vector<int> pos;
void posfind(string s, string r) {//tim vi tri r xuat hien trong s
	//vector<int> pos;
	/*for (int i = 0; i < s.size(); i++) {
		int j = i;
		bool check = true;
		if ((s.size() - 1) < r.size()) {
			break;
		}
		for (int z = 0; z < r.size(); z++) {
			if (r[z] == s[j]) continue;
			else {
				check = false;
				break;
			}
		}
		if (check == true) pos.push_back(i);
	}
	return pos;*/
	bool check = false;
	for (int i = 0; i < s.size(); i++) {
		int z = 0;
		int j = 0;
		for (z = i, j; z < s.size() && j < r.size(); j++, z++) {
			if (s[z] != r[j]) {
				check = false;
				break;
			}
			else check = true;
		}
		if (check)
			pos.push_back(i);
		check = false;
	}
	//return pos;
}
//ktra doi xung
bool doixung(string s) {
	int l = 0;
	int r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}
//chen chuoi
void Insert(string& s, string& r, int k) {
	string temp;
	for (int i = k; i < s.size(); i++) {
		temp += s[i];
	}
	s[k - 1] = '\0';
	s += temp + r;
}
//xoa ki tu{
string Dltchar(string s, char a) {
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == a) continue;
		temp += s[i];
	}
	return temp;
}
//xuat mang chua cacs kis tu so
void PrintNum(string s) {
	cout << "Cac ki chuoi so: ";
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			cout << s[i];
			if (!isdigit(s[i + 1])) cout << " ";
		}
		else {
			continue;
		}
	}
	cout << endl;
}
//phep tinh
void process(string s, string r) {//s->r
	int cnt = 0;
	if (s.size() < r.size()) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != r[i]) cnt++;
		}
		cout << "Can co " << cnt + (r.size() - s.size()) << " phep doi la: " << endl;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != r[i]) {
				cout << "\tDoi " << s[i] << " thanh " << r[i] << endl;
			}
		}
		for (int i = s.length(); i < r.length(); i++) {
			cout << "\tThem " << r[i] << " vao cuoi " << endl;
		}
	}
	else {
		for (int i = 0; i < r.size(); i++) {
			if (s[i] != r[i]) cnt++;
		}
		cout << "Can co " << cnt + (s.size() - r.size()) << " phep doi la: " << endl;
		for (int i = 0; i < r.size(); i++) {
			if (s[i] != r[i]) {
				cout << "\tDoi " << s[i] << " thanh " << r[i] << endl;
			}
		}
		for (int i = r.length(); i < s.length(); i++) {
			cout << "\tXoa " << s[i] << endl;
		}
	}
}
int main() {
	//cout << Proper(s)<<endl;
	//Info a = GetInfor(s);
	//cout << a.Ho << endl;
	//cout << a.Ten << endl;
	//cout << a.TenDem << endl;
	//string r = "nhat";
	//posfind(s, r);
	//PrintNum(s);
	/*for (auto it : pos) {
		cout << it;
	}*/
	int z;
	do {
		cout << "Bai(1-12): ";
		cin >> z;
		cin.ignore();
		cout << "\n\n";
		switch (z) {
		case 1: {
			string s;
			cout << "Nhap chuoi: "; cin >> s;
			if (CheckstringNum(s)) cout << "Dung" << endl;
			else cout << "Khong" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			string s;
			cout << "Nhap chuoi can Proper: "; cin >> s;
			cout << Proper(s) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			string s;
			cout << "Nhap chuoi: "; cin >> s;
			cout << Dlt_space(s) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			string s;
			cout << "Nhap chuoi: "; cin >> s;
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			string s;
			cout << "Nhap ho ten: "; cin >> s;
			cout << "Nhap ten: "; string r; cin >> r;
			if (find(s, r)) cout << s;
			else cout << "Khong ton tai!" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			string s;
			cout << "Cho doan van ban: ";
			string r = "- Dr. Martinez, the lead paleontologist on the excavation team, described the find as extraordinary. “Desertusaurus appears to be a herbivore with distinctive horn-like structures on its skull,” he explained. The team also found well-preserved footprints near the fossil site, suggesting that Desertusaurus roamed in herds across the ancient landscape. The discovery is significant because it provides valuable insights into the biodiversity of dinosaurs during the late Cretaceous period.Researchers hope to learn more about Desertusaurus’s behavior and its role in the ecosystem.Excavations are ongoing, and scientists are optimistic that further discoveries will shed light on this remarkable creature’s history.";
			//string r = "quang nhat hung";
			cout << r << endl;
			cout << "Nhap chuoi can tim: "; cin >> s;
			posfind(r, s);
			if (pos.empty()) cout << "Khong Tim thay!" << endl;
			else {
				cout << "Vi tri xuat hien la: " << endl;
				for (auto it : pos) {
					cout << it << endl;
				}
			}
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			string s;
			cout << "Nhap chuoi: "; cin >> s;
			if (doixung(s)) cout << "Doi xung!" << endl;
			else cout << "KLhong" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8: {
			string s1;
			cout << "Nhap chuoi s1: "; cin >> s1;
			string s2;
			cout << "Nhap chuoi s2: "; cin >> s2;
			if (pos.empty()) {
				cout << "Khong Tim thay!" << endl;
				s1 += s2;
			}
			else {
				cout << "Vi tri xuat hien la: " << endl;
				for (auto it : pos) {
					cout << it << endl;
				}
			}
			cout << s1 << endl;;
			system("pause");
			system("cls");
			break;
		}
		case 9: {
			string s1;
			cout << "Nhap chuoi s1: "; cin >> s1;
			string s2;
			cout << "Nhap chuoi s2: "; cin >> s2;
			cout << "Nhap vi tri can chen: "; int k; cin >> k;
			Insert(s1, s2, k);
			cout << s1 << endl;
			system("pause");
			system("cls");
				break;
		}
		case 10: {
			string s1;
			cout << "Nhap chuoi: "; getline(cin, s1);
			char s2;
			cout << "Nhap ki tu can xoa: "; cin >> s2;
			s1 = Dltchar(s1, s2);
			cout << s1 << endl;
			system("pause");
			system("cls");
			break;
		}
		case 11: {
			string s1;
			cout << "Nhap chuoi: "; getline(cin, s1);
			PrintNum(s1);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 12: {
			string s1;
			cout << "Nhap chuoi s1: "; getline(cin, s1);
			string s2;
			cout << "Nhap chuoi s2: "; getline(cin, s2);
			process(s1, s2);
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