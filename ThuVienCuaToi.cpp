#include "ThuVienCuaToi.h"

NgayThang layRaNgayThangNamHienTai()
{
	NgayThang localTime;
	time_t t = time(NULL);

	struct tm tm = *localtime(&t);
	localTime.nam = tm.tm_year + 1900; // Vi nam trong localTime tinh tu nam 1900
	localTime.thang = tm.tm_mon + 1;   // Vi thang trong localTime tinh tu 0 den 11
	localTime.ngay = tm.tm_mday;
	return localTime;
}

int soNgayTrongNam(int nam)
{
	return laNamNhuan(nam) ? SO_NGAY_CUA_NAM_NHUAN : SO_NGAY_CUA_NAM_THUONG;
}

int tinhSoNgayTuNam1900(NgayThang date)
{
	int ngayTraVe = date.ngay;
	for (int i = 1900; i < date.nam; i++)
	{
		ngayTraVe += soNgayTrongNam(i);
	}
	for (int i = 1; i < date.thang; i++)
	{
		ngayTraVe += tinhSoNgayTrongThang(i, date.nam);
	}
	return ngayTraVe;
}

int chenhLechDate(NgayThang date_1, NgayThang date_2)
{
	return tinhSoNgayTuNam1900(date_2) - tinhSoNgayTuNam1900(date_1);
}

bool laNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) // Dieu kien nam nhuan
	{
		return true;
	}
	return false;
}

int tinhSoNgayTrongThang(int thang, int nam)
{
	int ngayTraVe;

	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		ngayTraVe = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		ngayTraVe = 30;
		break;
	case 2:
		if (laNamNhuan(nam))
		{
			ngayTraVe = 29;
		}
		else
		{
			ngayTraVe = 28;
		}
		break;
	}

	return ngayTraVe;
}

bool laNgayHopLe(int ngay, int thang, int nam)
{
	if (nam < 0)
	{
		return false;
	}

	if (thang < 1 || thang > 12)
	{
		return false;
	}

	if (ngay < 1 || ngay > tinhSoNgayTrongThang(thang, nam))
	{
		return false;
	}

	return true;
}

bool kiemTraChuoiPhaiLaChuoiSo(char a[])
{
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] > KI_TU_SO_9_TRONG_ASCII || a[i] < KI_TU_SO_0_TRONG_ASCII)
		{
			return false;
		}
	}
	return true;
}

int getNgay(NgayThang date)
{
	return date.ngay;
}
void setNgay(NgayThang &date)
{
	scanf("%d", &date.ngay);
}

int getThang(NgayThang date)
{
	return date.thang;
}
void setThang(NgayThang &date)
{
	scanf("%d", &date.thang);
}

int getNam(NgayThang date)
{
	return date.nam;
}
void setNam(NgayThang &date)
{
	scanf("%d", &date.nam);
}

char *getTenVaccine(Vaccine *vx)
{
	return vx->tenVaccine;
}
void setTenVaccine(Vaccine &vx)
{
	fflush(stdin);
	gets(vx.tenVaccine);
}

char *getTenBenhNhan(BenhNhan *bn)
{
	return bn->hoVaTen;
}
void setTenBenhNhan(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.hoVaTen);
}

char *getDanToc(BenhNhan *bn)
{
	return bn->danToc;
}
void setDanToc(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.danToc);
}

char *getSoDienThoai(BenhNhan *bn)
{
	fflush(stdin);
	return bn->SoDienThoai;
}
void setSoDienThoai(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.SoDienThoai);
}

char *getCCCD_CMND(BenhNhan *bn)
{
	fflush(stdin);
	return bn->CCCD_CMND;
}
void setCCCD_CMND(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.CCCD_CMND);
}

char *getNgheNghiep(BenhNhan *bn)
{
	return bn->ngheNghiep;
}
void setNgheNghiep(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.ngheNghiep);
}

char *getBhyt(BenhNhan *bn)
{
	return bn->soTheBHYT;
}
void setBhyt(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.soTheBHYT);
}

char *getNoiThuongTru(BenhNhan *bn)
{
	return bn->noiThuongTru;
}
void setNoiThuongTru(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.noiThuongTru);
}

char *getKhoaDieuTri(BenhNhan *bn)
{
	return bn->khoaDieuTri;
}
void setKhoaDieuTri(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.khoaDieuTri);
}

char *getSoGiuong(BenhNhan *bn)
{
	return bn->soGiuong;
}
void setSoGiuong(BenhNhan &bn)
{
	fflush(stdin);
	gets(bn.soGiuong);
}

int getMucDo(BenhNhan bn)
{
	return bn.mucDo;
}
void setMucDo(BenhNhan &bn)
{
	scanf("%d", &bn.mucDo);
}

void nhapBenhNhan(BenhNhan &bn)
{
	NgayThang ngayHienTai = layRaNgayThangNamHienTai();
	do
	{
		printf("- Nhap ho va ten: ");
		setTenBenhNhan(bn);
		if (strlen(getTenBenhNhan(&bn)) > 25 || strlen(getTenBenhNhan(&bn)) < 1)
		{
			printf("Ten khong hop le vui long nhap lai !!!\n");
		}
	} while (strlen(getTenBenhNhan(&bn)) > 25 || strlen(getTenBenhNhan(&bn)) < 1);
	vietHoaChuCaiDau(bn.hoVaTen);

	do
	{
		printf("- Nhap ngay thang nam sinh: ");
		setNgay(bn.ngaySinh);
		setThang(bn.ngaySinh);
		setNam(bn.ngaySinh);
		if (!laNgayHopLe(getNgay(bn.ngaySinh), getThang(bn.ngaySinh), getNam(bn.ngaySinh)) || bn.ngaySinh.nam < 1900)
		{
			printf("Ngay nhap vao khong hop le vui long nhap lai !!!\n");
		}
		if (soSanhNgay(bn.ngaySinh, ngayHienTai) > 0)
		{
			printf("Ngay sinh vuot qua ngay hien tai vui long nhap lai !!!\n");
		}
	} while (!laNgayHopLe(getNgay(bn.ngaySinh), getThang(bn.ngaySinh), getNam(bn.ngaySinh)) || bn.ngaySinh.nam < 1900 || soSanhNgay(bn.ngaySinh, ngayHienTai) > 0);

	do
	{
		printf("- Nhap ngay thang nam nhap vien: ");
		setNgay(bn.ngayNhapVien);
		setThang(bn.ngayNhapVien);
		setNam(bn.ngayNhapVien);
		if (!laNgayHopLe(getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien)) || bn.ngayNhapVien.nam < 1900)
		{
			printf("Ngay khong hop le vui long nhap lai !!!\n");
		}
		if (soSanhNgay(bn.ngaySinh, bn.ngayNhapVien) > 0)
		{
			printf("Ngay nhap vien truoc ngay sinh vui long nhap lai !!!\n");
		}
		if (soSanhNgay(bn.ngayNhapVien, ngayHienTai) > 0)
		{
			printf("Ngay nhap vien vuot qua ngay hien tai vui long nhap lai !!!\n");
		}
	} while (!laNgayHopLe(getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien)) || bn.ngayNhapVien.nam < 1900 || soSanhNgay(bn.ngayNhapVien, bn.ngaySinh) < 0 || soSanhNgay(bn.ngayNhapVien, ngayHienTai) > 0);

	do
	{
		printf("- Dan toc: ");
		setDanToc(bn);
		if (strlen(getDanToc(&bn)) > 10 || strlen(getDanToc(&bn)) < 1)
		{
			printf("Dan toc khong hop len vui long nhap lai !!!\n");
		}
	} while (strlen(getDanToc(&bn)) > 10 || strlen(getDanToc(&bn)) < 1);

	do
	{
		printf("- Nhap so dien thoai: ");
		setSoDienThoai(bn);
		if (!kiemTraChuoiPhaiLaChuoiSo(getSoDienThoai(&bn)) || strlen(getSoDienThoai(&bn)) != 10)
		{
			printf("So dien thoai khong hop le !!!\n");
		}
	} while (!kiemTraChuoiPhaiLaChuoiSo(getSoDienThoai(&bn)) || strlen(getSoDienThoai(&bn)) != 10);

	do
	{
		fflush(stdin);
		printf("- Nhap so CCCD/CMND: ");
		setCCCD_CMND(bn);
		if (!kiemTraChuoiPhaiLaChuoiSo(getCCCD_CMND(&bn)) || (strlen(getCCCD_CMND(&bn)) != 9 && strlen(getCCCD_CMND(&bn)) != 12))
		{
			printf("Du lieu khong hop le\n");
		}
	} while (!kiemTraChuoiPhaiLaChuoiSo(getCCCD_CMND(&bn)) || (strlen(getCCCD_CMND(&bn)) != 9 && strlen(getCCCD_CMND(&bn)) != 12));

	do
	{
		printf("- Nhap nghe nghiep: ");
		setNgheNghiep(bn);
		if (strlen(getNgheNghiep(&bn)) > 15 || strlen(getNgheNghiep(&bn)) < 1)
		{
			printf("Nghe nghiep khong hop le vui long nhap lai !!! \n");
		}
	} while (strlen(getNgheNghiep(&bn)) > 15 || strlen(getNgheNghiep(&bn)) < 1);

	printf("- Thong tin bao hiem y te\n");
	char luaChon_baoHiem;
	do
	{
		printf("\t1. Co\n");
		printf("\t0. Khong\n");
		printf("\tNhap lua chon cua ban: ");
		fflush(stdin);
		scanf("%c", &luaChon_baoHiem);
		switch (luaChon_baoHiem)
		{
		case '1':
		{
			do
			{
				printf("\t- Nhap so the bao hiem y te: ");
				setBhyt(bn);
				if (strlen(getBhyt(&bn)) != 15)
				{
					printf("So the bao hiem y te khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getBhyt(&bn)) != 15);
			break;
		}
		case '0':
		{
			bn.soTheBHYT[0] = NULL;
			break;
		}
		default:
		{
			printf("\tLua chon khong hop le\n!!!");
			break;
		}
		}
	} while (luaChon_baoHiem != '1' && luaChon_baoHiem != '0');

	do
	{
		printf("- Nhap khoa dieu tri: ");
		setKhoaDieuTri(bn);
		if (strlen(getKhoaDieuTri(&bn)) > 25 || strlen(getKhoaDieuTri(&bn)) < 1)
		{
			printf("Khoa dieu tri khong hop le vui long nhap lai !!!\n");
		}
	} while (strlen(getKhoaDieuTri(&bn)) > 25 || strlen(getKhoaDieuTri(&bn)) < 1);

	do
	{
		printf("- Nhap dia chi thuong tru: ");
		setNoiThuongTru(bn);
		if (strlen(getNoiThuongTru(&bn)) > 25 || strlen(getNoiThuongTru(&bn)) < 1)
		{
			printf("Noi thuong tru khong hop le vui long nhap lai !!!\n");
		}
	} while (strlen(getNoiThuongTru(&bn)) > 25 || strlen(getNoiThuongTru(&bn)) < 1);

	do
	{
		printf("- Nhap so giuong: ");
		setSoGiuong(bn);
		if (strlen(getSoGiuong(&bn)) < 1 || strlen(getSoGiuong(&bn)) > 10 || !kiemTraChuoiPhaiLaChuoiSo(getSoGiuong(&bn)))
		{
			printf("So giuong khong hop le vui long nhap lai !!!\n");
		}
	} while (strlen(getSoGiuong(&bn)) < 1 || strlen(getSoGiuong(&bn)) > 10 || !kiemTraChuoiPhaiLaChuoiSo(getSoGiuong(&bn)));

	do
	{
		printf("- Muc do nhap vien: ");
		printf("\n\t1. Muc do nhe");
		printf("\n\t2. Muc do trung binh");
		printf("\n\t3. Muc do nang");
		printf("\n\tNhap lua lua chon: ");
		setMucDo(bn);
		if (getMucDo(bn) != 1 && getMucDo(bn) != 2 && getMucDo(bn) != 3)
		{
			printf("Muc do khong hop le vui long nhap lai !!!\n");
		}
	} while (getMucDo(bn) != 1 && getMucDo(bn) != 2 && getMucDo(bn) != 3);

	printf("- Thong tin vaccine\n");
	char luaChon;
	do
	{
		printf("\t1. Da tiem 1 mui\n");
		printf("\t2. Da tiem 2 mui\n");
		printf("\t3. Da tiem 3 mui\n");
		printf("\t0. Chua tiem\n");
		printf("\tNhap lua chon cua ban: ");
		fflush(stdin);
		scanf("%c", &luaChon);
		switch (luaChon)
		{
		case '1':
		{
			printf("\t- Mui 1\n");
			do
			{
				printf("\t\t+ Nhap ten vaccine: ");
				setTenVaccine(bn.mui_1);
				if (strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1)
				{
					printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1);
			do
			{
				printf("\t\t+ Ngay tiem: ");
				setNgay(bn.mui_1.ngayTiem);
				setThang(bn.mui_1.ngayTiem);
				setNam(bn.mui_1.ngayTiem);
				if (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)) || bn.mui_1.ngayTiem.nam < 1900)
				{
					printf("Ngay khong hop le vui long nhap lai !!!\n");
				}
				if (soSanhNgay(bn.ngaySinh, bn.mui_1.ngayTiem) > 0)
				{
					printf("Ngay tiem nho hon ngay sinh vui long nhap lai !!!\n");
				}
				if (soSanhNgay(bn.mui_1.ngayTiem, ngayHienTai) > 0)
				{
					printf("Ngay vuot qua ngay hien tai vui long nhap lai !!!\n");
				}
			} while (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)) ||
					 bn.mui_1.ngayTiem.nam < 1900 ||
					 soSanhNgay(bn.ngaySinh, bn.mui_1.ngayTiem) > 0 ||
					 soSanhNgay(bn.mui_1.ngayTiem, ngayHienTai) > 0);
			bn.mui_2.tenVaccine[0] = NULL;
			bn.mui_2.ngayTiem.nam = NULL;
			bn.mui_2.ngayTiem.ngay = NULL;
			bn.mui_2.ngayTiem.thang = NULL;
			bn.mui_3.tenVaccine[0] = NULL;
			bn.mui_3.ngayTiem.nam = NULL;
			bn.mui_3.ngayTiem.ngay = NULL;
			bn.mui_3.ngayTiem.thang = NULL;
			break;
		}
		case '2':
		{
			printf("\t- Mui 1\n");
			do
			{
				printf("\t\t+ Nhap ten vaccine: ");
				setTenVaccine(bn.mui_1);
				if (strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1)
				{
					printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1);
			do
			{
				printf("\t\t+ Ngay tiem: ");
				setNgay(bn.mui_1.ngayTiem);
				setThang(bn.mui_1.ngayTiem);
				setNam(bn.mui_1.ngayTiem);
				if (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)) || bn.mui_1.ngayTiem.nam < 1900)
				{
					printf("Ngay khong hop le vui long nhap lai !!!\n");
				}
				if (soSanhNgay(bn.ngaySinh, bn.mui_1.ngayTiem) > 0)
				{
					printf("Ngay tiem nho hon ngay sinh vui long nhap lai !!!\n");
				}
				if (soSanhNgay(bn.mui_1.ngayTiem, ngayHienTai) > 0)
				{
					printf("Ngay vuot qua ngay hien tai vui long nhap lai !!!\n");
				}
			} while (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)) ||
					 bn.mui_1.ngayTiem.nam < 1900 ||
					 soSanhNgay(bn.ngaySinh, bn.mui_1.ngayTiem) > 0 ||
					 soSanhNgay(bn.mui_1.ngayTiem, ngayHienTai) > 0);

			printf("\t- Mui 2\n");
			do
			{
				printf("\t\t+ Nhap ten vaccine: ");
				setTenVaccine(bn.mui_2);
				if (strlen(getTenVaccine(&bn.mui_2)) > 15 || strlen(getTenVaccine(&bn.mui_2)) < 1)
				{
					printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getTenVaccine(&bn.mui_2)) > 15 ||
					 strlen(getTenVaccine(&bn.mui_2)) < 1);
			do
			{
				printf("\t\t+ Ngay tiem: ");
				setNgay(bn.mui_2.ngayTiem);
				setThang(bn.mui_2.ngayTiem);
				setNam(bn.mui_2.ngayTiem);
				if (chenhLechDate(bn.mui_1.ngayTiem, bn.mui_2.ngayTiem) < 90)
				{
					printf("Mui 2 cua ban chua du 90 ngay tu luc tiem mui 1\n");
				}
				if (!laNgayHopLe(getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem)))
				{
					printf("Ngay khong hop le vui long nhap lai !!!\n");
				}
			} while (!laNgayHopLe(getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem)) || chenhLechDate(bn.mui_1.ngayTiem, bn.mui_2.ngayTiem) < 90);
			bn.mui_3.tenVaccine[0] = NULL;
			bn.mui_3.ngayTiem.nam = NULL;
			bn.mui_3.ngayTiem.ngay = NULL;
			bn.mui_3.ngayTiem.thang = NULL;
			break;
		}
		case '3':
		{
			printf("\t- Mui 1\n");
			do
			{
				printf("\t\t+ Nhap ten vaccine: ");
				setTenVaccine(bn.mui_1);
				if (strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1)
				{
					printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getTenVaccine(&bn.mui_1)) > 15 || strlen(getTenVaccine(&bn.mui_1)) < 1);
			do
			{
				printf("\t\t+ Ngay tiem: ");
				setNgay(bn.mui_1.ngayTiem);
				setThang(bn.mui_1.ngayTiem);
				setNam(bn.mui_1.ngayTiem);
				if (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)) || bn.mui_1.ngayTiem.nam < 1900)
				{
					printf("Ngay khong hop le vui long nhap lai !!!\n");
				}
				if (soSanhNgay(bn.ngaySinh, bn.mui_1.ngayTiem) > 0)
				{
					printf("Ngay tiem nho hon ngay sinh vui long nhap lai !!!\n");
				}
				if (soSanhNgay(bn.mui_1.ngayTiem, ngayHienTai) > 0)
				{
					printf("Ngay vuot qua ngay hien tai vui long nhap lai !!!\n");
				}
			} while (!laNgayHopLe(getNgay(bn.mui_1.ngayTiem), getThang(bn.mui_1.ngayTiem), getNam(bn.mui_1.ngayTiem)) ||
					 bn.mui_1.ngayTiem.nam < 1900 ||
					 soSanhNgay(bn.ngaySinh, bn.mui_1.ngayTiem) > 0 ||
					 soSanhNgay(bn.mui_1.ngayTiem, ngayHienTai) > 0);

			printf("\t- Mui 2\n");
			do
			{
				printf("\t\t+ Nhap ten vaccine: ");
				setTenVaccine(bn.mui_2);
				if (strlen(getTenVaccine(&bn.mui_2)) > 15 || strlen(getTenVaccine(&bn.mui_2)) < 1)
				{
					printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getTenVaccine(&bn.mui_2)) > 15 ||
					 strlen(getTenVaccine(&bn.mui_2)) < 1);
			do
			{
				printf("\t\t+ Ngay tiem: ");
				setNgay(bn.mui_2.ngayTiem);
				setThang(bn.mui_2.ngayTiem);
				setNam(bn.mui_2.ngayTiem);
				if (chenhLechDate(bn.mui_1.ngayTiem, bn.mui_2.ngayTiem) < 90)
				{
					printf("Mui 2 cua ban chua du 90 ngay tu luc tiem mui 1\n");
				}
				if (!laNgayHopLe(getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem)))
				{
					printf("Ngay khong hop le vui long nhap lai !!!\n");
				}
			} while (!laNgayHopLe(getNgay(bn.mui_2.ngayTiem), getThang(bn.mui_2.ngayTiem), getNam(bn.mui_2.ngayTiem)) || chenhLechDate(bn.mui_1.ngayTiem, bn.mui_2.ngayTiem) < 90);

			printf("\t- Mui 3\n");
			do
			{
				printf("\t\t+ Nhap ten vaccine: ");
				setTenVaccine(bn.mui_3);
				if (strlen(getTenVaccine(&bn.mui_3)) > 15 || strlen(getTenVaccine(&bn.mui_3)) < 1)
				{
					printf("Ten vaccine khong hop le vui long nhap lai !!!\n");
				}
			} while (strlen(getTenVaccine(&bn.mui_3)) > 15 || strlen(getTenVaccine(&bn.mui_3)) < 1);
			do
			{
				printf("\t\t+ Ngay tiem: ");
				setNgay(bn.mui_3.ngayTiem);
				setThang(bn.mui_3.ngayTiem);
				setNam(bn.mui_3.ngayTiem);
				if (!laNgayHopLe(getNgay(bn.mui_3.ngayTiem), getThang(bn.mui_3.ngayTiem), getNam(bn.mui_3.ngayTiem)))
				{
					printf("Ngay khong hop le vui long nhap lai !!!\n");
				}
				if (chenhLechDate(bn.mui_2.ngayTiem, bn.mui_3.ngayTiem) < 90)
				{
					printf("Mui 2 cua ban chua du 90 ngay tu luc tiem mui 2\n");
				}
			} while (!laNgayHopLe(getNgay(bn.mui_3.ngayTiem), getThang(bn.mui_3.ngayTiem), getNam(bn.mui_3.ngayTiem)) || chenhLechDate(bn.mui_2.ngayTiem, bn.mui_3.ngayTiem) < 90);
			break;
		}
		}
	} while (luaChon != '1' && luaChon != '2' && luaChon != '3' && luaChon != '0');
}

void xuatBenhNhan(BenhNhan bn)
{
	printf("%-25s", getTenBenhNhan(&bn));
	printf("%-2d/%-2d/%-4d\t", getNgay(bn.ngaySinh), getThang(bn.ngaySinh), getNam(bn.ngaySinh));
	printf("%-10s\t", getDanToc(&bn));
	printf("%-10s\t", getSoDienThoai(&bn));
	printf("%-15s", getCCCD_CMND(&bn));
	printf("%-15s", getNgheNghiep(&bn));
	printf("%-15s\t", strlen(getBhyt(&bn)) == 0 ? "Khong co" : getBhyt(&bn));
	printf("%-25s", getNoiThuongTru(&bn));
	printf("%-15s\t", getKhoaDieuTri(&bn));
	printf("%-10s\t", getSoGiuong(&bn));
	printf("%-2d/%-2d/%-4d\t", getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien));
	printf("%-10d\n", getMucDo(bn));
}

void nhapDanhSachBenhNhan(BenhNhan *bn, int soLuong)
{
	for (int i = 0; i < soLuong; i++)
	{
		textcolor(MAU_XANH_NGOC);
		if (i % 2 == 0)
		{
			textcolor(MAU_XANH_LA_CAY);
		}
		printf("===== NHAP THONG TIN BENH NHAN THU %d =====\n", i + 1);
		nhapBenhNhan(bn[i]);
	}
}

void xuatDanhSachBenhNhan(BenhNhan *bn, int soLuong)
{
	textcolor(MAU_VANG);
	printf("\t\t\t\t\t\t\t\t\t\t\t========== DANH SACH BENH NHAN ==========\n");
	printf("%-25s", "Ho va ten");
	printf("%-10s\t", "Ngay sinh");
	printf("%-10s\t", "Dan toc");
	printf("%-10s\t", "SDT");
	printf("%-15s", "So CMND/CCCD");
	printf("%-15s", "Nghe nghiep");
	printf("%-15s\t", "So BHYT");
	printf("%-25s", "Noi thuong tru");
	printf("%-15s\t", "Khoa dieu tri");
	printf("%-10s\t", "So giuong");
	printf("%-15s\t", "Ngay nhap vien");
	printf("%-10s\n", "Muc do");
	for (int i = 0; i < soLuong; i++)
	{
		textcolor(MAU_XANH_NGOC);
		if (i % 2 == 0)
		{
			textcolor(MAU_XANH_LA_CAY);
		}
		xuatBenhNhan(bn[i]);
	}
}

void xuatThongTinVaccine(BenhNhan bn)
{

	printf("\t%-25s", getTenBenhNhan(&bn));
	printf("\t%-15s", strlen(getTenVaccine(&bn.mui_1)) == 0 ? "Chua tiem" : getTenVaccine(&bn.mui_1));
	printf("\t\t%-2d/%-2d/%-4d", getNgay(bn.mui_1.ngayTiem) == NULL ? 0 : getNgay(bn.mui_1.ngayTiem),
		   getThang(bn.mui_1.ngayTiem) == NULL ? 0 : getThang(bn.mui_1.ngayTiem),
		   getNam(bn.mui_1.ngayTiem) == NULL ? 0 : getNam(bn.mui_1.ngayTiem));

	printf("\t\t\t%-15s", strlen(getTenVaccine(&bn.mui_2)) == 0 ? "Chua tiem" : getTenVaccine(&bn.mui_2));
	printf("\t\t%-2d/%-2d/%-4d", getNgay(bn.mui_2.ngayTiem) == NULL ? 0 : getNgay(bn.mui_2.ngayTiem),
		   getThang(bn.mui_2.ngayTiem) == NULL ? 0 : getThang(bn.mui_2.ngayTiem),
		   getNam(bn.mui_2.ngayTiem) == NULL ? 0 : getNam(bn.mui_2.ngayTiem));

	printf("\t\t\t%-15s", strlen(getTenVaccine(&bn.mui_3)) == 0 ? "Chua tiem" : getTenVaccine(&bn.mui_3));
	printf("\t\t%-2d/%-2d/%-4d\t\t\t\t", getNgay(bn.mui_3.ngayTiem) == NULL ? 0 : getNgay(bn.mui_3.ngayTiem),
		   getThang(bn.mui_3.ngayTiem) == NULL ? 0 : getThang(bn.mui_3.ngayTiem),
		   getNam(bn.mui_3.ngayTiem) == NULL ? 0 : getNam(bn.mui_3.ngayTiem));
}

void xuatDanhSachVaccine(BenhNhan *bn, int soLuong)
{
	textcolor(MAU_VANG);
	printf("\t\t\t\t\t\t\t\t ========== DANH SACH THONG TIN VACCINE CUA BENH NHAN ==========\n");
	printf("\t%-25s", "Ho va ten");
	printf("\t%-15s", "Mui 1");
	printf("\t\t%-15s", "Ngay tiem mui 1");
	printf("\t\t\t%-15s", "Mui 2");
	printf("\t\t%-15s", "Ngay tiem mui 2");
	printf("\t\t\t%-15s", "Mui 3");
	printf("\t\t%-15s\t\t\t\n", "Ngay tiem mui 3");
	for (int i = 0; i < soLuong; i++)
	{
		textcolor(MAU_XANH_NGOC);
		if (i % 2 == 0)
		{
			textcolor(MAU_XANH_LA_CAY);
		}
		xuatThongTinVaccine(bn[i]);
		printf("\n");
	}
}

int soSanhNgay(NgayThang ngay_1, NgayThang ngay_2)
{
	if (ngay_1.ngay == ngay_2.ngay && ngay_1.thang == ngay_2.thang && ngay_1.nam == ngay_2.nam)
	{
		return 0;
	}
	if (ngay_1.nam > ngay_2.nam)
	{
		return 1;
	}

	if (ngay_1.nam == ngay_2.nam)
	{
		if (ngay_1.thang > ngay_2.thang)
		{
			return 1;
		}

		if (ngay_1.thang == ngay_2.thang)
		{
			if (ngay_1.ngay > ngay_2.ngay)
			{
				return 1;
			}
		}
	}

	return -1;
}

void themDau(BenhNhan *bn, int &soLuong)
{
	BenhNhan giaTriThem;
	if (soLuong % 2 == 0)
	{
		textcolor(MAU_XANH_NGOC);
	}
	else
	{
		textcolor(MAU_XANH_LA_CAY);
	}
	printf("===== NHAP THONG TIN BENH NHAN CAN THEM VAO DANH SACH =====\n");
	nhapBenhNhan(giaTriThem);
	for (int i = soLuong; i > 0; i--)
	{
		bn[i] = bn[i - 1];
	}
	soLuong++;
	bn[0] = giaTriThem;
}

void themCuoi(BenhNhan *bn, int &soLuong)
{
	if (soLuong % 2 == 0)
	{
		textcolor(MAU_XANH_NGOC);
	}
	else
	{
		textcolor(MAU_XANH_LA_CAY);
	}
	BenhNhan giaTriThem;

	printf("===== NHAP THONG TIN BENH NHAN CAN THEM VAO DANH SACH =====\n");
	nhapBenhNhan(giaTriThem);
	soLuong++;
	bn[soLuong - 1] = giaTriThem;
}

void themBatKy(BenhNhan *bn, int &soLuong)
{
	if (soLuong % 2 == 0)
	{
		textcolor(MAU_XANH_NGOC);
	}
	else
	{
		textcolor(MAU_XANH_LA_CAY);
	}
	BenhNhan giaTriThem;
	if (soLuong == 0)
	{
		printf("===== DANH SACH DANG TRONG =====\n");
		themCuoi(bn, soLuong);
		return;
	}
	printf("===== NHAP THONG TIN BENH NHAN CAN THEM VAO DANH SACH =====\n");
	nhapBenhNhan(giaTriThem);
	int x;
	do
	{
		printf("\nNhap vi tri muon them: ");
		scanf("%d", &x);
		if (x < 0 || x >= soLuong)
		{
			printf("Vi tri muon them nam ngoai danh sach");
		}
	} while (x < 0 || x >= soLuong);

	for (int i = soLuong; i > x; i--)
	{
		bn[i] = bn[i - 1];
	}
	soLuong++;
	bn[x] = giaTriThem;
}

int soNgayChenhLech(NgayThang ngay_1, NgayThang ngay_2)
{
	return fabs(tinhSoNgayTrongThang(ngay_1.thang, ngay_1.nam) + ngay_1.ngay);
}

void xoaDau(BenhNhan *bn, int &soLuong)
{
	for (int i = 0; i < soLuong - 1; i++)
	{
		bn[i] = bn[i + 1];
	}
	soLuong--;
}

void xoaCuoi(BenhNhan *bn, int &soLuong)
{
	soLuong--;
}

void xoaBatKy(BenhNhan *bn, int &soLuong)
{
	int x;
	do
	{
		printf("\nNhap vi tri muon xoa:");
		scanf("%d", &x);
		if (x < 0 || x >= soLuong)
		{
			printf("Vi tri muon xoa nam ngoai danh sach\n");
		}
	} while (x < 0 || x >= soLuong);

	for (int i = x; i < soLuong - 1; i++)
	{
		bn[i] = bn[i + 1];
	}
	soLuong--;
}

void vietHoachucai(char *x)
{
	if (*x <= 122 && *x >= 97)
		*x = *x - 32;
}

void vietThuongChuCai(char *x)
{
	if (*x >= 65 && *x <= 90)
		*x = *x + 32;
}

void vietHoaChuCaiDau(char *x)
{
	for (int i = 0; i < strlen(x); i++)
	{
		if (i == 0 || (i > 0 && x[i - 1] == 32))
		{
			vietHoachucai(&x[i]);
		}
		else
		{
			vietThuongChuCai(&x[i]);
		}
	}
}
void sapXepBenhNhanTheoTen(BenhNhan *bn, int &soLuong)
{
	for (int i = 0; i < soLuong - 1; i++)
	{
		for (int j = i + 1; j < soLuong; j++)
		{
			if (strcmp((bn[i].hoVaTen), (bn[j].hoVaTen)) > 0)
			{
				BenhNhan temp = bn[i];
				bn[i] = bn[j];
				bn[j] = temp;
			}
		}
	}
}

bool kiemTraTuoi(NgayThang bn_1, NgayThang bn_2)
{
	if (bn_1.nam < bn_2.nam)
	{
		return true;
	}
	if (bn_1.nam == bn_2.nam)
	{
		if (bn_1.thang < bn_2.thang)
		{
			return true;
		}
		if (bn_1.thang == bn_2.thang)
		{
			if (bn_1.ngay < bn_2.ngay)
			{
				return true;
			}
		}
	}

	return false;
}

void sapXepGiamDanTheoTuoi(BenhNhan *bn, int soLuong)
{
	for (int i = 0; i < soLuong - 1; i++)
	{
		for (int j = i + 1; j < soLuong; j++)
		{
			if (!kiemTraTuoi(bn[i].ngaySinh, bn[j].ngaySinh))
			{
				BenhNhan temp = bn[i];
				bn[i] = bn[j];
				bn[j] = temp;
			}
		}
	}
}

void sapXepTangDanTheoTuoi(BenhNhan *bn, int soLuong)
{
	for (int i = 0; i < soLuong - 1; i++)
	{
		for (int j = i + 1; j < soLuong; j++)
		{
			if (kiemTraTuoi(bn[i].ngaySinh, bn[j].ngaySinh))
			{
				BenhNhan temp = bn[i];
				bn[i] = bn[j];
				bn[j] = temp;
			}
		}
	}
}

void timKiemBenhNhanTheoTen(BenhNhan *bn, int soLuong)
{
	char ten[25];
	printf("- Nhap ten cua benh nhan can tim kiem:");
	fflush(stdin);
	gets(ten);
	vietHoaChuCaiDau(ten);
	for (int i = 0; i < soLuong; i++)
	{
		if (strcmp((getTenBenhNhan(&bn[i])), ten) == 0)
		{
			textcolor(MAU_XANH_NGOC);
			printf("\t\t\t\t\t\t\t\t\t\t\t========== THONG TIN BENH NHAN TIM KIEM ==========\n");
			printf("%-25s", "Ho va ten");
			printf("%-10s\t", "Ngay sinh");
			printf("%-10s\t", "Dan toc");
			printf("%-10s\t", "SDT");
			printf("%-15s", "So CMND/CCCD");
			printf("%-15s", "Nghe nghiep");
			printf("%-15s", "So BHYT");
			printf("%-25s", "Noi thuong tru");
			printf("%-15s\t", "Khoa dieu tri");
			printf("%-10s\t", "So giuong");
			printf("%-15s\t\t", "Ngay nhap vien");
			printf("%-10s\n", "Muc do");
			textcolor(MAU_XANH_LA_CAY);
			xuatBenhNhan(bn[i]);
			textcolor(MAU_XANH_NGOC);
			printf("\n");
			printf("\t\t\t\t\t\t\t\t ========== THONG TIN VACCINE CUA BENH NHAN TIM KIEM ==========\n");
			printf("\t%-25s", "Ho va ten");
			printf("\t%-15s", "Mui 1");
			printf("\t\t%-15s", "Ngay tiem mui 1");
			printf("\t\t\t%-15s", "Mui 2");
			printf("\t\t%-15s", "Ngay tiem mui 2");
			printf("\t\t\t%-15s", "Mui 3");
			printf("\t\t%-15s\t\t\t\t\n", "Ngay tiem mui 3");
			xuatThongTinVaccine(bn[i]);
			printf("\n");
			textcolor(MAU_VANG);
			printf("\t\t\t\t\t\t========== THONG TIN TIEN VIEN PHI TINH DEN HOM NAY CUA CAC BENH NHAN ==========\n");
			printf("\t%-25s\t", "Ho va ten");
			printf("%-15s\t\t", "Ngay nhap vien");
			printf("%-10s\t", "Hom nay");
			printf("%-15s\t\t", "Nam vien(ngay)");
			printf("%-15s\t\t", "Thuoc(VND)");
			printf("%-15s\t", "Giuong(VND)");
			printf("%-15s\t\t", "Tong cong(VND)");
			printf("%-15s\t", "BHYT(VND)");
			printf("%-20s", "So tien phai tra(VND)\n");
			xuatHoaDon(bn[i]);
			printf("\n");
			return;
		}
	}
	textcolor(MAU_DO);
	printf("BENH NHAN KHONG TON TAI TRONG DANH SACH\n");
}

float layTienThuocTheoMucDo(BenhNhan bn)
{
	if (bn.mucDo == 1)
	{
		return 150000;
	}
	if (bn.mucDo == 2)
	{
		return 200000;
	}
	if (bn.mucDo == 3)
	{
		return 300000;
	}
}

float soTienTruBHYT(BenhNhan bn)
{
	return strlen(getBhyt(&bn)) != 0 ? (soTienVienPhi(bn) * 80) / 100 : 0;
}

float soTienVienPhi(BenhNhan bn)
{
	NgayThang ngayHienTai = layRaNgayThangNamHienTai();
	int soNgayNamVien = chenhLechDate(bn.ngayNhapVien, ngayHienTai);
	float soTienTra = (float)soNgayNamVien * TIEN_GIUONG + (float)soNgayNamVien * layTienThuocTheoMucDo(bn);
	return soTienTra;
}

void xuatHoaDon(BenhNhan bn)
{
	float bhyt = strlen(getBhyt(&bn)) != 1 ? 80 : 0;
	NgayThang ngayHienTai = layRaNgayThangNamHienTai();
	printf("\t%-25s\t", getTenBenhNhan(&bn));
	printf("%-2d/%-2d/%-4d\t\t", getNgay(bn.ngayNhapVien), getThang(bn.ngayNhapVien), getNam(bn.ngayNhapVien));
	printf("%-2d/%-2d/%-4d\t", getNgay(ngayHienTai), getThang(ngayHienTai), getNam(ngayHienTai));
	printf("%-10d\t\t", chenhLechDate(bn.ngayNhapVien, ngayHienTai));
	printf("%-15.f\t\t", layTienThuocTheoMucDo(bn) * (float)chenhLechDate(bn.ngayNhapVien, ngayHienTai));
	printf("%-15.f\t", TIEN_GIUONG * (float)chenhLechDate(bn.ngayNhapVien, ngayHienTai));
	printf("%-15.f\t\t", soTienVienPhi(bn));
	printf("%-15.f\t", -soTienTruBHYT(bn));
	printf("%-20.f\n", soTienVienPhi(bn) - soTienTruBHYT(bn));
}

void xuatDanhSachHoaDon(BenhNhan *bn, int soLuong)
{
	textcolor(MAU_VANG);
	printf("\t\t\t\t\t\t========== DANH SACH TIEN VIEN PHI TINH DEN HOM NAY CUA CAC BENH NHAN ==========\n");
	printf("\t%-25s\t", "Ho va ten");
	printf("%-15s\t\t", "Ngay nhap vien");
	printf("%-10s\t", "Hom nay");
	printf("%-15s\t\t", "Nam vien(ngay)");
	printf("%-15s\t\t", "Thuoc(VND)");
	printf("%-15s\t", "Giuong(VND)");
	printf("%-15s\t\t", "Tong cong(VND)");
	printf("%-15s\t", "BHYT(VND)");
	printf("%-20s", "So tien phai tra(VND)\n");
	for (int i = 0; i < soLuong; i++)
	{
		textcolor(MAU_XANH_NGOC);
		if (i % 2 == 0)
		{
			textcolor(MAU_XANH_LA_CAY);
		}
		xuatHoaDon(bn[i]);
	}
}

float thongKeBenhNhanMucDo1(BenhNhan *bn, int soLuong)
{
	int dem = 0;
	for (int i = 0; i < soLuong; i++)
	{
		if (bn[i].mucDo == 1)
		{
			dem++;
		}
	}
	return float(dem) / soLuong * 100;
}

float thongKeBenhNhanMucDo2(BenhNhan *bn, int soLuong)
{
	int dem = 0;
	for (int i = 0; i < soLuong; i++)
	{
		if (bn[i].mucDo == 2)
		{
			dem++;
		}
	}
	return float(dem) / soLuong * 100;
}

float thongKeBenhNhanMucDo3(BenhNhan *bn, int soLuong)
{
	int dem = 0;
	for (int i = 0; i < soLuong; i++)
	{
		if (bn[i].mucDo == 3)
		{
			dem++;
		}
	}
	return float(dem) / soLuong * 100;
}

void xuatDanhSachThongKeBenhNhanTheoMucDoBenh(BenhNhan *bn, int soLuong)
{
	textcolor(MAU_VANG);
	printf("\t\t\t\t\t%-50s\n", "=========== DANH SACH THONG KE BENH NHAN THEO MUC DO BENH ============");
	printf("\t\t\t\t\t\t\tMuc do benh\t\tTi le\n");
	textcolor(MAU_XANH_LA_CAY);
	printf("\t\t\t\t\t\t\tMuc do 1\t\t%.2f%c\n", thongKeBenhNhanMucDo1(bn, soLuong), 37);
	textcolor(MAU_XANH_NGOC);
	printf("\t\t\t\t\t\t\tMuc do 2\t\t%.2f%c\n", thongKeBenhNhanMucDo2(bn, soLuong), 37);
	textcolor(MAU_XANH_LA_CAY);
	printf("\t\t\t\t\t\t\tMuc do 3\t\t%.2f%c\n", thongKeBenhNhanMucDo3(bn, soLuong), 37);
}

void docFileDanhSachBenhNhan(BenhNhan *&bn, int &soLuong, char *fname)
{
	FILE *f;

	f = fopen(fname, "rb");
	if (f == NULL)
	{
		textcolor(MAU_DO);
		printf("Loi doc file !!!");
		fclose(f);
		return;
	}
	fread(&soLuong, sizeof(int), 1, f);
	bn = (BenhNhan *)malloc(soLuong * sizeof(BenhNhan));
	for (int i = 0; i < soLuong; i++)
	{
		fread(&bn[i], sizeof(BenhNhan), 1, f);
	}
	textcolor(MAU_XANH_LA_CAY);
	printf("DA DOC FILE THANH CONG");
	fclose(f);
}

void ghiFileDanhSachBenhNhan(BenhNhan *bn, int soLuong, char *fname)
{
	FILE *f;
	f = fopen(fname, "wb");
	if (f == NULL)
	{
		textcolor(MAU_DO);
		printf("\n\n\t\t Loi mo file !!!");
		fclose(f);
		return;
	}
	fwrite(&soLuong, sizeof(int), 1, f);

	for (int i = 0; i < soLuong; i++)
	{
		fwrite(&bn[i], sizeof(BenhNhan), 1, f);
	}
	fclose(f);
	textcolor(MAU_XANH_LA_CAY);
	printf("DA GHI FILE THANH CONG");
}

