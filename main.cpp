#include "ThuVienCuaToi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char **argv)
{
	SetConsoleTitle("QUAN LI BENH VIEN");
	resizeConsole(2000, 1000);
	BenhNhan *DSBN;
	int soLuong = 0;
	int chon_1;
	do
	{
		textcolor(MAU_VANG);
		printf("\t\t\t\t\t\t   QUAN LI BENH VIEN\n");
		printf("\t\t\t\t-----------------------------------------------------------\n");
		printf("\t\t\t\t|\t%-50s%s\n", "0. Thoat", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "1. Nhap danh sach benh nhan", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "2. Xuat danh sach benh nhan", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "3. Xuat thong tin vaccine cua DSBN", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "4. Them", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "5. Xoa", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "6. Sap xep", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "7. Tim kiem theo ten", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "8. Tien vien phi cua DSBN den hom nay", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "9. Xuat danh sach thong ke theo muc do benh", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "10. Ghi file", "|");
		printf("\t\t\t\t|\t%-50s%s\n", "11. Doc file", "|");
		printf("\t\t\t\t-----------------------------------------------------------\n");
		printf("\t\t\t\t-\t%-48s", "Nhap lua chon cua ban: ");
		fflush(stdin);
		scanf("%d", &chon_1);
		switch (chon_1)
		{
		case 0:
		{
			XoaManHinh();
			textcolor(MAU_DO);
			printf("\t\t\t\t\t\t%-50s\n", "DA KET THUC CHUONG TRINH");
			break;
		}
		case 1:
		{
			printf("Nhap so luong benh nhan: ");
			scanf("%d", &soLuong);
			DSBN = (BenhNhan *)malloc((soLuong) * sizeof(BenhNhan));
			nhapDanhSachBenhNhan(DSBN, soLuong);
			XoaManHinh();
			textcolor(MAU_XANH_LA_CAY);
			printf("\t\t\t\t\t\t%-50s\n", "DA NHAP XONG DANH SACH BENH NHAN");
			system("pause");
			XoaManHinh();
			break;
		}
		case 2:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			XoaManHinh();
			xuatDanhSachBenhNhan(DSBN, soLuong);
			textcolor(MAU_VANG);
			printf("\n");
			system("pause");
			XoaManHinh();
			break;
		}
		case 3:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH VACCINE DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			XoaManHinh();
			xuatDanhSachVaccine(DSBN, soLuong);
			textcolor(MAU_VANG);
			printf("\n");
			system("pause");
			XoaManHinh();
			break;
		}
		case 4:
		{
			int chon_2;
			XoaManHinh();
			do
			{
				textcolor(MAU_VANG);
				printf("\t\t\t\t\t\t\tTHEM BENH NHAN\n");
				printf("\t\t\t\t-----------------------------------------------------------\n");
				printf("\t\t\t\t|\t%-50s%s\n", "0. Tro ve", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "1. Them vao dau", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "2. Them vao cuoi", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "3. Them vao bat ky", "|");
				printf("\t\t\t\t-----------------------------------------------------------\n");
				printf("\t\t\t\t-\t%-48s", "Nhap lua chon cua ban: ");
				fflush(stdin);
				scanf("%d", &chon_2);
				switch (chon_2)
				{
				case 0:
				{
					XoaManHinh();
					break;
				}
				case 1:
				{
					if (soLuong == 0)
					{
						DSBN = (BenhNhan *)malloc(sizeof(BenhNhan));
					}
					else
					{
						DSBN = (BenhNhan *)realloc(DSBN, (soLuong + 1) * sizeof(BenhNhan));
					}
					themDau(DSBN, soLuong);
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA THEM BENH NHAN VAO DAU");
					system("pause");
					XoaManHinh();
					break;
				}
				case 2:
				{
					if (soLuong == 0)
					{
						DSBN = (BenhNhan *)malloc(sizeof(BenhNhan));
					}
					else
					{
						DSBN = (BenhNhan *)realloc(DSBN, (soLuong + 1) * sizeof(BenhNhan));
					}
					themCuoi(DSBN, soLuong);
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA THEM BENH NHAN VAO CUOI");
					system("pause");
					XoaManHinh();
					break;
				}
				case 3:
				{
					if (soLuong == 0)
					{
						DSBN = (BenhNhan *)malloc(sizeof(BenhNhan));
					}
					else
					{
						DSBN = (BenhNhan *)realloc(DSBN, (soLuong + 1) * sizeof(BenhNhan));
					}
					themBatKy(DSBN, soLuong);
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA THEM BENH NHAN VAO VI TRI THEM");
					system("pause");
					XoaManHinh();
					break;
				}
				default:
				{
					XoaManHinh();
					textcolor(MAU_DO);
					printf("\t\t\t\t\t\t   %-50s\n", "LUA CHON SAI NHAP LAI");
					break;
				}
				}
			} while (chon_2 != 0);
			break;
		}

		case 5:
		{
			int chon_2;
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			XoaManHinh();
			do
			{
				if (soLuong < 1)
				{
					break;
				}
				textcolor(MAU_VANG);
				printf("\t\t\t\t\t%-50s\n", "XOA BENH NHAN");
				printf("\t\t\t\t-----------------------------------------------------------\n");
				printf("\t\t\t\t|\t%-50s%s\n", "0. Tro ve", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "1. Xoa dau", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "2. Xoa cuoi", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "3. Xoa vi tri bat ky", "|");
				printf("\t\t\t\t-----------------------------------------------------------\n");
				printf("\t\t\t\t-\t%-48s", "Nhap lua chon cua ban: ");
				fflush(stdin);
				scanf("%d", &chon_2);
				switch (chon_2)
				{
				case 0:
				{
					XoaManHinh();
					break;
				}
				case 1:
				{
					xoaDau(DSBN, soLuong);
					DSBN = (BenhNhan *)realloc(DSBN, (soLuong) * sizeof(BenhNhan));
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA XOA BENH NHANH DAU TIEN");
					system("pause");
					XoaManHinh();
					break;
				}
				case 2:
				{
					xoaCuoi(DSBN, soLuong);
					DSBN = (BenhNhan *)realloc(DSBN, (soLuong) * sizeof(BenhNhan));
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA XOA BENH NHANH CUOI CUNG");
					system("pause");
					XoaManHinh();
					break;
				}
				case 3:
				{
					xoaBatKy(DSBN, soLuong);
					DSBN = (BenhNhan *)realloc(DSBN, (soLuong) * sizeof(BenhNhan));
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA XOA BENH NHAN O VI TRI CHON");
					system("pause");
					XoaManHinh();
					break;
				}
				default:
				{
					XoaManHinh();
					textcolor(MAU_DO);
					printf("\t\t\t\t\t%-50s\n", "LUA CHON SAI NHAP LAI");
					break;
				}
				}
			} while (chon_2 != 0);
			break;
		}
		case 6:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			int chon_2;
			XoaManHinh();
			do
			{
				textcolor(MAU_VANG);
				printf("\t\t\t\t-----------------------------------------------------------\n");
				printf("\t\t\t\t|\t%-50s%s\n", "0. Tro ve", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "1. Sap xep theo tuoi", "|");
				printf("\t\t\t\t|\t%-50s%s\n", "2. Sap xep theo ten", "|");
				printf("\t\t\t\t-----------------------------------------------------------\n");
				printf("\t\t\t\t-\t%-48s", "Nhap lua chon cua ban: ");
				fflush(stdin);
				scanf("%d", &chon_2);
				switch (chon_2)
				{
				case 0:
				{
					XoaManHinh();
					break;
				}
				case 1:
				{
					int chon_3;
					XoaManHinh();
					do
					{
						textcolor(MAU_VANG);
						printf("\t\t\t\t\t%-50s\n", "SAP XEP THEO TUOI");
						printf("\t\t\t\t-----------------------------------------------------------\n");
						printf("\t\t\t\t|\t%-50s%s\n", "0. Tro ve", "|");
						printf("\t\t\t\t|\t%-50s%s\n", "1. Tang dan", "|");
						printf("\t\t\t\t|\t%-50s%s\n", "2. Giam dan", "|");
						printf("\t\t\t\t-----------------------------------------------------------\n");
						printf("\t\t\t\t-\t%-48s", "Nhap lua chon cua ban: ");
						fflush(stdin);
						scanf("%d", &chon_3);
						switch (chon_3)
						{
						case 0:
						{
							XoaManHinh();
							break;
						}
						case 1:
						{
							sapXepTangDanTheoTuoi(DSBN, soLuong);
							XoaManHinh();
							textcolor(MAU_XANH_LA_CAY);
							printf("\t\t\t\t\t%-50s\n", "DA SAP XEP TANG DAN THEO TUOI");
							system("pause");
							XoaManHinh();
							break;
						}
						case 2:
						{
							sapXepGiamDanTheoTuoi(DSBN, soLuong);
							XoaManHinh();
							textcolor(MAU_XANH_LA_CAY);
							printf("\t\t\t\t\t%-50s\n", "DA SAP XEP GIAM DAN THEO TUOI");
							system("pause");
							XoaManHinh();
							break;
						}
						default:
						{
							XoaManHinh();
							textcolor(MAU_DO);
							printf("\t\t\t\t\t%-50s\n", "LUA CHON SAI NHAP LAI");
							break;
						}
						}
					} while (chon_3 != 0);
					break;
				}
				case 2:
				{
					sapXepBenhNhanTheoTen(DSBN, soLuong);
					XoaManHinh();
					textcolor(MAU_XANH_LA_CAY);
					printf("\t\t\t\t\t%-50s\n", "DA SAP XEP TANG DAN THEO TEN");
					system("pause");
					XoaManHinh();
					break;
				}
				default:
				{
					XoaManHinh();
					textcolor(MAU_DO);
					printf("\t\t\t\t\t%-50s\n", "LUA CHON SAI NHAP LAI");
					break;
				}
				}
			} while (chon_2 != 0);
			break;
		}
		case 7:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			printf("\t\t\t\t\t%-50s\n", "TIM KIEM BENH NHAN BENH NHAN");
			timKiemBenhNhanTheoTen(DSBN, soLuong);
			system("pause");
			textcolor(15);
			XoaManHinh();
			break;
		}
		case 8:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			XoaManHinh();
			xuatDanhSachHoaDon(DSBN, soLuong);
			textcolor(MAU_VANG);
			printf("\n");
			system("pause");
			XoaManHinh();
			break;
		}
		case 9:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			XoaManHinh();
			xuatDanhSachThongKeBenhNhanTheoMucDoBenh(DSBN, soLuong);
			textcolor(MAU_VANG);
			printf("\n");
			system("pause");
			XoaManHinh();
			break;
		}
		case 10:
		{
			if (soLuong < 1)
			{
				XoaManHinh();
				textcolor(MAU_DO);
				printf("\t\t\t\t\t%-50s\n", "DANH SACH BENH NHAN DANG TRONG");
				system("pause");
				XoaManHinh();
				break;
			}
			XoaManHinh();
			char tenFile[50];
			printf("Nhap ten file can ghi:");
			fflush(stdin);
			gets(tenFile);
			int doDaiChuoi = strlen(tenFile);
			tenFile[doDaiChuoi] = '.';
			tenFile[doDaiChuoi + 1] = 'b';
			tenFile[doDaiChuoi + 2] = 'i';
			tenFile[doDaiChuoi + 3] = 'n';
			tenFile[doDaiChuoi + 4] = '\0';
			ghiFileDanhSachBenhNhan(DSBN, soLuong, (char *)tenFile);
			printf("\n");
			system("pause");
			XoaManHinh();
			break;
		}
		case 11:
		{
			XoaManHinh();
			textcolor(MAU_VANG);
			char tenFile[50];
			printf("Nhap ten file can doc:");
			fflush(stdin);
			gets(tenFile);
			int doDaiChuoi = strlen(tenFile);
			tenFile[doDaiChuoi] = '.';
			tenFile[doDaiChuoi + 1] = 'b';
			tenFile[doDaiChuoi + 2] = 'i';
			tenFile[doDaiChuoi + 3] = 'n';
			tenFile[doDaiChuoi + 4] = '\0';
			docFileDanhSachBenhNhan(DSBN, soLuong, (char *)tenFile);
			printf("\n");
			system("pause");
			XoaManHinh();
			break;
		}
		default:
		{
			XoaManHinh();
			textcolor(MAU_DO);
			printf("\t\t\t\t\t%-50s\n", "LUA CHON CUA BAN KHONG NAM TRONG DANH SACH");
			break;
		}
		}
	} while (chon_1 != 0);

	return 0;
}

