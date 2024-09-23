#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct Phanso
{
	int TuSo;
	int MauSo;
};
typedef Phanso ItemType;

void nhapPhanSo(ItemType& x);
void taoPhanSo(ItemType& x);
void xuatPhanSo(ItemType x);
void daoDauPhanSo(ItemType& x);
void rutGonPhanSo(ItemType& x);
void nhapSoNguyenDuong(int& n);
void Xuat_Cac_Phan_So_MAU_HON_TU(ItemType x);
void nhapMang1C_PhanSo(ItemType*& x, int& n);
void xuatMang1C_PhanSo(ItemType* a, int n);
void xuatPS_MauLonHonTu(ItemType* a, int n);
int dem_PSCoTuVaMauChan(ItemType* a, int n);
int TimUCLN(int x, int y);
void rutGonPhanSo(ItemType& x);
void xuatPhanSo_RutGon(ItemType x);
void xuatMang1C_PhanSo_RutGon(ItemType* a, int n);
ItemType congPhanSo(ItemType p1, ItemType p2);
void Tich_TatCaPhanTuCuaMang(ItemType* a, int n);
int soSanhPhanSo(ItemType x, ItemType y);
ItemType TimKiemTuyenTinh(ItemType* x, int n);

void showmenu()
{
	printf("\n*********************************************************");
	printf("\n*                         MENU                          *");
	printf("\n*********************************************************");
	printf("\n* 0.thoat chuong trinh                                  *");
	printf("\n* 1.Nhap phan so                                        *");
	printf("\n* 2.Xuat phan so tu lon hon mau                         *");
	printf("\n* 3.Dem so phan so co mau va tu chan                    *");
	printf("\n* 4.Rut gon phan so                                     *");
	printf("\n* 5.Tinh Tich cac phan tu trong mang                    *");
	printf("\n* 6.Tim so lon nhat trong mang                          *");
	printf("\n*********************************************************");
}
//=================================================================
void process()
{
	char TenTapTin[] = "dulieu_Mang1C.txt";
	ItemType* X, kq;
	int luachon, N, kqint;
	do
	{
		showmenu();
		printf("\nBan hay lua chon mot chuc nang:  ");
		nhapSoNguyenDuong(luachon);
		switch (luachon)
		{
		case 1:
			nhapMang1C_PhanSo(X, N);
			printf("Phan so vua nhap la : \n");
			xuatMang1C_PhanSo(X, N);
			break;
		case 2:
			printf("Cac so co mau lon hon tu la : ");
			xuatPS_MauLonHonTu(X, N);
			break;
		case 3:
			kqint = dem_PSCoTuVaMauChan(X, N);
			printf("So phan tu co tu va mau chan la : %d", kqint);
			break;
		case 4:
			printf("Phan so sau khi rut gon la : \n");
			xuatMang1C_PhanSo_RutGon(X, N);
			break;
		case 5:
			Tich_TatCaPhanTuCuaMang(X, N);
			break;
		case 6:
			printf("Phan so lon nhat la : ");
			kq = TimKiemTuyenTinh(X, N);
			xuatPhanSo(kq);
		}
	} while (luachon != 0);
	getch();
}
//=================================================================
void main()
{
	process();
	getch();
}
//============================================================================
//=================================================================
void nhapSoNguyenDuong(int& n)

{
	do
	{
		scanf("%d", &n);
		if (n < 0)
		{
			printf("ban phai nhap mot so nguyen duong");
		}
	} while (n < 0);
}
//=================================================================
void nhapMang1C_PhanSo(ItemType*& x, int& n)
{
	printf("Ban hay cho biet so phan tu cua mang : ");
	nhapSoNguyenDuong(n);
	x = new ItemType[n];
	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan so a[%d]", i);
		nhapPhanSo(x[i]);
	}
}
//============================================================================
void nhapPhanSo(ItemType& x)
{
	do {
		printf("\nnhap tu so: ");
		scanf("%d", &x.TuSo);
	} while (x.TuSo == 0);
	do {
		printf("nhap mau so: ");

		scanf("%d", &x.MauSo);
	} while (x.MauSo == 0);
	/*daoDauPhanSo(x);
	rutGonPhanSo(x);*/
}
//============================================================================
void xuatPhanSo(ItemType x)
{
	printf("%d/%d\t", x.TuSo, x.MauSo);
}
//============================================================================
void xuatPhanSo_RutGon(ItemType x)
{
	rutGonPhanSo(x);
	printf("%d/%d\t", x.TuSo, x.MauSo);
}
//============================================================================
void xuatMang1C_PhanSo(ItemType* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		xuatPhanSo(a[i]);
	}
}
//============================================================================
void xuatMang1C_PhanSo_RutGon(ItemType* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		xuatPhanSo_RutGon(a[i]);
	}
}
//============================================================================
void xuatPS_MauLonHonTu(ItemType* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].MauSo > a[i].TuSo)
		{
			xuatPhanSo(a[i]);
		}
	}
}
//============================================================================
int dem_PSCoTuVaMauChan(ItemType* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].MauSo % 2 == 0 && a[i].TuSo % 2 == 0)
		{
			count++;
		}
	}
	return count;
}
//============================================================================
//============================================================================
int TimUCLN(int x, int y)
{
	x = abs(x);
	y = abs(y);

	while (x != y)
	{
		if (x > y)
		{
			x = x - y;
		}
		if (y > x)
		{
			y = y - x;
		}
	}
	return x;
}
//============================================================================
void rutGonPhanSo(ItemType& x)
{
	int tmp = (TimUCLN(x.TuSo, x.MauSo));
	x.TuSo /= tmp;
	x.MauSo /= tmp;
}
//============================================================================
ItemType congPhanSo(ItemType p1, ItemType p2)
{
	ItemType ketQua;
	ketQua.TuSo = p1.TuSo * p2.MauSo + p2.TuSo * p1.MauSo;
	ketQua.MauSo = p1.MauSo * p2.MauSo;
	// Tối giản phân số
	int ucln = TimUCLN(ketQua.TuSo, ketQua.MauSo);
	ketQua.TuSo /= ucln;
	ketQua.MauSo /= ucln;
	return ketQua;
}

void Tich_TatCaPhanTuCuaMang(ItemType* a, int n)
{
	ItemType Tong;
	ItemType ketqua;
	Tong.TuSo = 1;
	Tong.MauSo = 1;
	for (int i = 0; i < n; i++)
	{
		Tong.TuSo = Tong.TuSo * a[i].TuSo;
		Tong.MauSo = Tong.MauSo * a[i].MauSo;
	}
	printf("tong cua cac phan tu la :  ");
	xuatPhanSo_RutGon(Tong);
}

int soSanhPhanSo(ItemType x, ItemType y)
{
	int tmp = x.TuSo * y.MauSo - y.TuSo * x.MauSo;
	if (tmp > 0)
	{
		return 1;
	}
	if (tmp < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

ItemType TimKiemTuyenTinh(ItemType* x, int n)
{
	ItemType tmp = x[0];
	for (int i = 0; i < n; i++)
	{
		if (soSanhPhanSo(tmp, x[i]) == -1)
		{
			tmp = x[i];
		}
	}
	return tmp;
}
