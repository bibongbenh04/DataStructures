#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <chrono>
#include <thread>
#include <queue>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void quanLy() {
	system("cls");
	int color = 1;
	cout << "\t\t\t*\t\t\t\t\t*\n\n\n LOADING:";
	string loadDing = "[<3 <3 0% ========== 25% ============= 50% ============= 75% ========= 100% <3 <3]";
	for (auto c : loadDing) {
		if (color == 7) color = 1;
		setColor(color++);
		cout << c;
		this_thread::sleep_for(chrono::milliseconds(10)); // Đợi 50 ms (0.05 giây)
	}
	cout << "\n\n\n\t\t\t\t\tDANG NHAP THANH CONG";
	this_thread::sleep_for(chrono::milliseconds(2000));
	setColor(7);
	system("cls");
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "\t\t\t*\t\t\tMENU QUAN LY\t\t\t\t*" << endl;
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "1. Xy ly don hang\n";
	cout << "2. Quan ly hang hoa\n";
	int iChon;
	cin >> iChon;
	if (iChon == 1) {

	}
	else if (iChon == 2) {

	}

}

class NhanVien {
	string user;
	string password;
	
public: 
	NhanVien(){
		password.clear();
	}
	bool check() {
		return user == "Nhan" && password == "1810";
	}
	void login() {
		setColor(10);
		password.clear();
		user.clear();
		system("cls");
		cout << "\t\t\t*****************************************************************" << endl;
		cout << "\t\t\t*\t\t\tDANG NHAP HE THONG\t\t\t*" << endl;
		cout << "\t\t\t*****************************************************************" << endl;
		setColor(8);
		cout << " User: ";
		cin >> user;
		cout << " Password: ";
		char ch = ' ';
		int i = 0;
		while (ch != 13) {
			ch = _getch();  // Đọc một ký tự từ bàn phím mà không hiển thị lên màn hình
			password.push_back(ch);
			cout << '*';
		}
		password.pop_back();

		while (!check()) {
			password.clear();
			if (++i == 4) {
				char a;
				cout << "\n\nDang nhap lai (Y)";
				a = _getch();
				if (a == 'Y' || a == 'y') {
					login();
				}
				else exit(0);
			}

			ch = ' ';
			setColor(12);
			cout << " \n\nError: Mat khau sai, vui long nhap lai, Ban con " << 4-i << " lan thu !! \nPassword: ";
			setColor(8);
			while (ch != 13) {
				ch = _getch(); 
				if (ch == 27) {
					exit(0);
				}
				password.push_back(ch);
				cout << '*';
			}
			password.pop_back();
		}
		
		quanLy();
		
	}

	void xuat() {
		cout << user << endl;
		cout << password << endl;
	}
};

class HangHoa{
protected:
	string maHang, tenHang, noiSanXuat, mauSac, ngayNhapKho;
	int giaBan, soLuong;
public:
	friend istream& operator >> (istream& is, HangHoa& a) { 
		ofstream out("HangHoa.txt", ios::app);
		cout << "Nhap ma hang, ten hang, noi san xuat, mau sac, gia ban, ngay nhap kho, so luong\n";
		is >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;
		out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
			<< '*' << a.mauSac << '*' << a.giaBan << '*' 
			<< a.ngayNhapKho << '*' << a.soLuong;
		return is;
	}
	void hienThiHangHoa() {
		setColor(2);
		cout << setw(10) << "MA HANG" << setw(5) << "|"
			<< setw(10) << "TEN HANG" << setw(5) << "|"
			<< setw(10) << "NOI SXUAT" << setw(5) << "|"
			<< setw(10) << "MAU SAC" << setw(5) << "|"
			<< setw(10) << "GIA BAN" << setw(5) << "|"
			<< setw(10) << "NGAY NK" << setw(5) << "|"
			<< setw(10) << "SO LUONG" << setw(5) << "|";
		ifstream in("HangHoa.txt");
		string _str, str;
		setColor(11);
		cout << "\n\n==============================================================================================================\n";	
		setColor(9.5);
		while (getline(in, _str)) {
			this_thread::sleep_for(chrono::milliseconds(500));
			stringstream ss(_str);
			cout << "\n";
			while (getline(ss, str, '*')) {
				cout << setw(10) << str <<setw(5) << "|";
				this_thread::sleep_for(chrono::milliseconds(10));
			}
			cout << endl;
		}
		setColor(7);
	}
	void timKiemThongTin(string s) {
		setColor(2);
		cout << setw(10) << "MA HANG" << setw(5) << "|"
			<< setw(10) << "TEN HANG" << setw(5) << "|"
			<< setw(10) << "NOI SXUAT" << setw(5) << "|"
			<< setw(10) << "MAU SAC" << setw(5) << "|"
			<< setw(10) << "GIA BAN" << setw(5) << "|"
			<< setw(10) << "NGAY NK" << setw(5) << "|"
			<< setw(10) << "SO LUONG" << setw(5) << "|";
		ifstream in("HangHoa.txt");
		string _str, str;
		setColor(11);
		cout << "\n\n==============================================================================================================\n";
		setColor(9.5);
		while (getline(in, _str)){
			this_thread::sleep_for(chrono::milliseconds(500));
			stringstream ss(_str), ss2(_str);
			string tenHang;
			getline(ss2, tenHang, '*');
			getline(ss2, tenHang, '*');
			if (tenHang.find(s) > tenHang.size()) continue;
			cout << endl;
			while (getline(ss, str, '*')) {
				cout << setw(10) << str << setw(5) << "|";
				this_thread::sleep_for(chrono::milliseconds(50));
			}
			cout << endl;
			
		}
		setColor(7);
	}
	void datHang() {

	}
};

class DonHang : HangHoa{
	int soLuong = 1, tongTien = 0;
	string tenKhachHang, diaChiKhachHang, soDienThoai, ngayDatHang;
	vector<HangHoa> listHangHoa;
	
public:
	void xuLyHang() {

	}
	void datHang() {
		cout << "Ban muon dat hang, hay lua chon mat hang minh yeu thich";
		ofstream out("DonHang.txt", ios::app);
		cin >> maHang >> tenHang >> noiSanXuat >> mauSac >> giaBan >> ngayNhapKho >> soLuong;
	}

	//}
	//friend istream & operator >>(istream& is, DonHang& a) {
	//	ofstream out("DonHang.txt", ios::app);
	//	is >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;
	//	out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
	//		<< '*' << a.mauSac << '*' << a.giaBan << '*'
	//		<< a.ngayNhapKho << '*' << a.soLuong;
	//	cout << "Don hang dang cho duoc xu ly";
	//	return is;
	//}

};
class LISTDONHANCANXULY {
	queue<DonHang> listDonHang;
public:
	void xuLyDonHang() {
		if (listDonHang.empty()) {
			cout << "Khong co don hang can xu ly, vui long kiem tra lai";
			return;
		}
		listDonHang.front().xuLyHang();

		listDonHang.pop();
	}

};
void manHinhChinh() {
	HangHoa hhDauTien;
	NhanVien nvNhanVien;
	setColor(12);
	cout << "\t\t\t*************************************************************************";
	cout << "\n\t\t\t*\t\t\t1. Hien thi thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t2. Tim kiem thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t3. Dat hang\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t4. Dang nhap\t\t\t\t\t*";
	cout << "\n\t\t\t*************************************************************************";
	setColor(9);
	nhapLai:
	cout << "\nNhap lua chon cua ban\n";
	int iSo;
	string strTimKiem;
	cin >> iSo;
	switch (iSo) {
	case 1:
		hhDauTien.hienThiHangHoa();
		break;
	case 2:
		cout << "\nNhap ten hang hoa can tim\n";
		cin >> strTimKiem;
		hhDauTien.timKiemThongTin(strTimKiem);
		break;
	//case 3:
	//	
	case 4:
		nvNhanVien.login();
		break;
	default:
		cout << "Ban vua nhap sai, vui long nhap lai";
		goto nhapLai;
	}
	
}
int main() {
	//NhanVien a;
	//HangHoa hh;
	//DonHang dh;
	manHinhChinh();
	//hh.hienThiHangHoa();
	//cin >> hh;


	//hh.timKiemThongTin("a");
	//a.login();
}