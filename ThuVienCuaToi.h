#include "DoHoa.h"

int const SO_NGAY_CUA_NAM_NHUAN = 366;
int const SO_NGAY_CUA_NAM_THUONG = 365;
int const KI_TU_SO_9_TRONG_ASCII = 57;
int const KI_TU_SO_0_TRONG_ASCII = 48;
int const MAU_XANH_NGOC = 11;
int const MAU_XANH_LA_CAY = 10;
int const MAU_VANG = 14;
int const MAU_DO = 12;
typedef struct
{
	int ngay;
	int thang;
	int nam;
} NgayThang;

typedef struct
{
	NgayThang ngayTiem;
	char tenVaccine[50];
} Vaccine;

typedef struct
{
	char hoVaTen[50];
	NgayThang ngaySinh;
	char danToc[50];
	char SoDienThoai[50];
	char CCCD_CMND[50];
	char ngheNghiep[50];
	char soTheBHYT[50];
	char noiThuongTru[50];
	char khoaDieuTri[50];
	char soGiuong[50];
	NgayThang ngayNhapVien;
	int mucDo;
	Vaccine mui_1;
	Vaccine mui_2;
	Vaccine mui_3;
} BenhNhan;

// Ham lay ra ngay thang nam hien tai
NgayThang layRaNgayThangNamHienTai();

// Ham tinh so ngay trong nam
int soNgayTrongNam(int nam);

// Tinh so ngay tu nam 1900
int tinhSoNgayTuNam1900(NgayThang date);

// Tinh so ngay giua hai date
int chenhLechDate(NgayThang date_1, NgayThang date_2);

// Ham kiem tra nam nhuan
bool laNamNhuan(int ngay);

// Ham tra ve so ngay cho truoc
int tinhSoNgayTrongThang(int thang, int nam);

// Ham kiem tra dd / mm / yyyy co hop le khong
bool laNgayHopLe(int ngay, int thang, int nam);

// Ham kiem tra chuoi nhap vao co la so khong
bool kiemTraChuoiPhaiLaChuoiSo(char a[]);

// Ham lay ra ngay va sua
int getNgay(NgayThang date);
void setNgay(NgayThang &date);

// Ham lay ra thang va sua
int getThang(NgayThang date);
void setThang(NgayThang &date);

// Ham lay ra nam va sua
int getNam(NgayThang date);
void setNam(NgayThang &date);

// Ham lay ra ten vaccine va sua
char *getTenVaccine(Vaccine *vx);
void setTenVaccine(Vaccine &vx);

// Ham lay ra ten benh nhap va sua
char *getTenBenhNhan(BenhNhan *bn);
void setTenBenhNhan(BenhNhan &bn);

// Ham lay ra ten dan toc va sua
char *getDanToc(BenhNhan *bn);
void setDanToc(BenhNhan &bn);

// Ham lay ra so dien thoai va sua
char *getSoDienThoai(BenhNhan *bn);
void setSoDienThoai(BenhNhan &bn);

// Ham lay ra so CMND/CCCD va sua
char *getCCCD_CMND(BenhNhan *bn);
void setCCCD_CMND(BenhNhan &bn);

// Ham lay ra nghe nghiep va sua
char *getNgheNghiep(BenhNhan *bn);
void setNgheNghiep(BenhNhan &bn);

// Ham lay ra so bhyt va sua
char *getBhyt(BenhNhan *bn);
void setBhyt(BenhNhan &bn);

// Ham lay ra noi thuong tru va sua
char *getNoiThuongTru(BenhNhan *bn);
void setNoiThuongTru(BenhNhan &bn);

// Ham lay ra khoa dieu tri va sua
char *getKhoaDieuTri(BenhNhan *bn);
void setKhoaDieuTri(BenhNhan &bn);

// Ham lay ra so giuong va sua
char *getSoGiuong(BenhNhan *bn);
void setSoGiuong(BenhNhan &bn);

// Ham lay ra muc do nang nhe va sua
int getMucDo(BenhNhan bn);
void setMucDO(BenhNhan &bn);

// Ham nhap benh nhan
void nhapBenhNhan(BenhNhan &bn);

// Ham xuat benh nhan
void xuatBenhNhan(BenhNhan bn);

// Ham nhap danh sach benh nhan
void nhapDanhSachBenhNhan(BenhNhan *bn, int soLuong);

// Ham xuat danh sach benh nhan
void xuatDanhSachBenhNhan(BenhNhan *bn, int soLuong);

// Ham xuat thong tin vaccine
void xuatThongTinVaccine(BenhNhan bn);

// Ham xuat danh sach vaccine
void xuatDanhSachVaccine(BenhNhan *bn, int soLuong);

// Ham kiem so sanh 2 ngay
int soSanhNgay(NgayThang ngay_1, NgayThang ngay_2);

// Ham them dau
void themDau(BenhNhan *bn, int &soluong);

// Them cuoi
void themCuoi(BenhNhan *bn, int &soLuong);

// Them bat ky
void themBatKy(BenhNhan *bn, int &soLuong);

// Xoa dau
void xoaDau(BenhNhan *bn, int &soluong);

// Xoa cuoi
void xoaCuoi(BenhNhan *bn, int &soLuong);

// Xoa bat ky
void xoaBatKy(BenhNhan *bn, int &soLuong);

// Chuyen chu sang viet hoa
void vietHoachucai(char *x);

// Chuyen chu sang viet thuong
void vietThuongChuCai(char *x);

// Viet hoa chu cai dau
void vietHoaChuCaiDau(char *x);

// Sap xep benh nhan theo ten abc
void sapXepBenhNhanTheoTen(BenhNhan *bn, int &soLuong);

// Ham tra ve so ngay chenh lech
int soNgayChenhLech(NgayThang ngay_1, NgayThang ngay_2);

// Kiem tra tuoi 2 benh nhan
bool kiemTraTuoi(NgayThang bn_1, NgayThang bn_2);

// Ham sap xep benh nhan theo tuoi tang dan
void sapXepTangDanTheoTuoi(BenhNhan *bn, int soLuong);

// Ham sap xep benh nhan theo tuoi giam dan
void sapXepGiamDanTheoTuoi(BenhNhan *bn, int soLuong);

// Ham tim kiem theo ten
void timKiemBenhNhanTheoTen(BenhNhan *bn, int soLuong);

// Ham lay ra tien theo muc do
float layTienThuocTheoMucDo(BenhNhan bn);

// So tien vien phi
float soTienVienPhi(BenhNhan bn);

// xuat hoa don
void xuatHoaDon(BenhNhan bn);

// Xuat danh sach hoa don
void xuatDanhSachHoaDon(BenhNhan *bn, int soLuong);

// So tien tru bhyt
float soTienTruBHYT(BenhNhan bn);

// Thong ke benh nhan muc do 1
float thongKeBenhNhanMucDo1(BenhNhan *bn, int soLuong);

// Thong ke benh nhan muc do 2
float thongKeBenhNhanMucDo2(BenhNhan *bn, int soLuong);

// Thong ke benh nhan muc do 3
float thongKeBenhNhanMucDo3(BenhNhan *bn, int soLuong);

// Xuat danh sach thong ke benh nhan theo muc do benh
void xuatDanhSachThongKeBenhNhanTheoMucDoBenh(BenhNhan *bn, int soLuong);

// Doc file danh sach benh nhan
void docFileDanhSachBenhNhan(BenhNhan *&bn, int &soLuong, char *fname);

// Ghi file danh sach benh nhan
void ghiFileDanhSachBenhNhan(BenhNhan *bn, int soLuong, char *fname);
