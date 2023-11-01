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
#include <unordered_map>
#include <map>
#include <ctime>


using namespace std;

/*************************************
*									 *
*	   HÀM CHỈNH MÀU, LÀM MÀU 1      *
*									 *
**************************************/
void manHinhChinh();
void quanLy();
string removeSpace(string str) {
	stringstream ss(str);
	string newStr = "", temp;
	while (ss >> temp) newStr += temp;
	return newStr;
}

void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	//Đen: 0
	//Xanh Navy : 1
	//Xanh Lá Cây : 2
	//Xanh Biển Đậm : 3
	//Đỏ : 4
	//Tím : 5
	//Cam : 6
	//Xám Đậm : 8
	//Xanh Lá Cây Đậm : 10
	//Xanh Biển : 11
	//Hồng : 12
	//Vàng : 14
	//Trắng : 15
}

/*************************************
*									 *
*	HÀM CHỈNH ĐỘ DELAY, LÀM MÀU 2    *
*									 *
**************************************/
void sleepChrono(int milisecond) {
	this_thread::sleep_for(chrono::milliseconds(milisecond));
}

/*************************************
*									 *
*	   HÀM SAU KHI ĐĂNG NHẬP TC      *
*									 *
**************************************/
void themTk() {
	setColor(11);
loop:
	system("cls");
	ofstream out("nhanvien.txt", ios::app);
	string str;
	cout << "\nThem username nhan vien:";
	do {
		cin >> str;
	} while (removeSpace(str).empty());
	out << str << " ";
	cout << "\nThem password nhan vien:";
	do {
		cin >> str;
	} while (removeSpace(str).empty());
	out << str << "\n";
	cout << "Add more account ? (Y):";
	char choose = _getch();
	if (choose == 'y' || choose == 'Y') goto loop;
	setColor(7);
}



class NhanVien {
	string user;
	string password;

public:
	NhanVien() {
		password.clear();
	}

	/*************************************
	*									 *
	*	  HÀM CHECK TÀI KHOẢN ADIM       *
	*									 *
	**************************************/
	bool check() {
		string us, ps;
		ifstream in("nhanvien.txt");
		while (in >> us >> ps) {
			if (us == user && ps == password) return true;
		}
		return user == "Admin" && password == "Admin";
	}


	/*************************************
	*									 *
	*			 HÀM ĐĂNG NHẬP           *
	*									 *
	**************************************/
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
			cout << " \n\nError: Mat khau sai, vui long nhap lai, Ban con " << 4 - i << " lan thu !! \nPassword: ";
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
};
class HangHoa {
protected:
	string maHang, tenHang, noiSanXuat, mauSac, ngayNhapKho;
	int giaBan, soLuong;
public:

	/*************************************
	*									 *
	* GET, SETCÁCPHẦNTỬTRONGLỚPHÀNGHÓA   *
	*									 *
	**************************************/
	string getMH() { return maHang; }
	void setMH(string MH) { maHang = MH; }

	string getTH() { return tenHang; }
	void setTH(string MH) { tenHang = MH; }

	string getNSX() { return noiSanXuat; }
	void setNSX(string MH) { noiSanXuat = MH; }

	string getMS() { return mauSac; }
	void setMS(string MH) { mauSac = MH; }

	string getNNK() { return ngayNhapKho; }
	void setNNK(string MH) { ngayNhapKho = MH; }

	void setSL(int SL) { soLuong = SL; }
	int getSL() { return soLuong; }

	void setGB(int SL) { giaBan = SL; }
	int getGB() { return giaBan; }
	//***********************************************************************************************

		/*************************************
		*									 *
		*	    QUÁ TẢI NHẬP HÀNG HÓA        *
		*									 *
		**************************************/
	friend istream& operator >> (istream& is, HangHoa& a) {
		ofstream out("HangHoa.txt", ios::app);
		cout << "Nhap ma hang, ten hang, noi san xuat, mau sac, gia ban, ngay nhap kho, so luong\n";
		is >> a.maHang >> a.tenHang >> a.noiSanXuat >> a.mauSac >> a.giaBan >> a.ngayNhapKho >> a.soLuong;
		out << '\n' << a.maHang << '*' << a.tenHang << '*' << a.noiSanXuat
			<< '*' << a.mauSac << '*' << a.giaBan << '*'
			<< a.ngayNhapKho << '*' << a.soLuong;
		return is;
	}

	/*************************************
	*									 *
	*	    HÀM HIỂN THỊ HÀNG HÓA	     *
	*									 *
	**************************************/
	void hienThiHangHoa() {
		setColor(2);
		cout << setw(10) << "MA HANG" << setw(5) << "|"
			<< setw(10) << "TEN HANG" << setw(5) << "|"
			<< setw(10) << "NOI SXUAT" << setw(5) << "|"
			<< setw(10) << "MAU SAC" << setw(5) << "|"
			<< setw(10) << "GIA BAN" << setw(5) << "|"
			<< setw(10) << "NGAY NK" << setw(5) << "|"
			<< setw(10) << "SO LUONG" << setw(5) << "|";
		ifstream in("hanghoa.txt");
		string _str, str;
		setColor(11);
		cout << "\n\n==============================================================================================================\n";
		setColor(9.5);
		while (getline(in, _str)) {
			this_thread::sleep_for(chrono::milliseconds(100));
			stringstream ss(_str);
			cout << "\n";
			while (getline(ss, str, '*')) {
				cout << setw(10) << str << setw(5) << "|";
				this_thread::sleep_for(chrono::milliseconds(5));
			}
			cout << endl;
		}
		setColor(7);
	}

	/*************************************
	*									 *
	*	    HÀM TÌM KIÊM HÀNG HÓA	     *
	*									 *
	**************************************/
	void timKiemThongTin(string s) {
		setColor(2);
		cout << setw(10) << "MA HANG" << setw(5) << "|"
			<< setw(10) << "TEN HANG" << setw(5) << "|"
			<< setw(10) << "NOI SXUAT" << setw(5) << "|"
			<< setw(10) << "MAU SAC" << setw(5) << "|"
			<< setw(10) << "GIA BAN" << setw(5) << "|"
			<< setw(10) << "NGAY NK" << setw(5) << "|"
			<< setw(10) << "SO LUONG" << setw(5) << "|";
		ifstream in("hanghoa.txt");
		string _str, str;
		setColor(11);
		cout << "\n\n==============================================================================================================\n";
		setColor(9.5);
		while (getline(in, _str)) {
			sleepChrono(100);
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

	/*************************************
	*									 *
	*			HÀM ĐỌC FILE			 *
	*									 *
	**************************************/
	vector<HangHoa> DocThongTinHangHoa() {
		vector<HangHoa> danhSachHangHoa;
		ifstream inFile("hanghoa.txt");
		if (!inFile) {
			cerr << "Không thể mở tệp HangHoa.txt!" << endl;
			return danhSachHangHoa;  // Trả về danh sách rỗng nếu không mở được tệp
		}
		HangHoa hangHoa;
		string str;
		while (getline(inFile, str)) {
			stringstream ss(str);
			getline(ss, hangHoa.maHang, '*');
			getline(ss, hangHoa.tenHang, '*');
			getline(ss, hangHoa.noiSanXuat, '*');
			getline(ss, hangHoa.mauSac, '*');
			ss >> hangHoa.giaBan;  // Sử dụng >> để đọc số nguyên
			ss.ignore();  // Bỏ qua dấu '*'
			getline(ss, hangHoa.ngayNhapKho, '*');
			ss >> hangHoa.soLuong;  // Sử dụng >> để đọc số nguyên
			danhSachHangHoa.push_back(hangHoa);
		}
		inFile.close();
		return danhSachHangHoa;
	}
};

//STT, MaHang, SoLuong, TongTien, TenKhachHang, DiaChiKhachHang, SoDienThoaiKhachHang, NgayDatHang; 
// được lưu vào DonHang.txt
// mỗi đơn hàng gồm nhiều mã hàng

class DonHang : public HangHoa {
protected:
	double tongTien = 0;
	string tenKhachHang, diaChiKhachHang, soDienThoai, ngayDatHang;
	vector<HangHoa> listHangHoa;
public:

	/*
		HÀM XỮ LÝ ĐƠN HÀNG CỦA ADMIN
	*/
	bool xuLyDonHang(string MH, int SL) {
		ifstream in("hanghoa.txt");
		ofstream out("tempHangHoa.txt");
		string str, MaHang;
		while (getline(in, str)) {
			stringstream ss1(str);
			getline(ss1, MaHang, '*');
			if (MaHang == MH) {
				int sl = stoi(str.substr(str.rfind('*') + 1));
				if (sl < SL) {
					cout << "So luong don dat vuot qua so luong hien co !!!!!\n";
					in.close();
					out.close();
					remove("tempHangHoa.txt");
					return false;
				}
				str.replace(str.rfind('*') + 1, str.length() - (str.rfind('*') + 1), to_string(sl - SL));
				if (sl - SL == 0) str = "";
			}
			out << str << (str.empty() ? "" : "\n");
		}
		in.close();
		out.close();
		remove("hanghoa.txt");
		rename("tempHangHoa.txt", "hanghoa.txt");
		cout << "Da Xu Ly Don Hang\n";
		return true;
	}
	/*
		Hàm tạo đơn hàng
	*/
	void taoDonHang() {

		char choooseUS = '0';
		do {
			system("cls");
			hienThiHangHoa();
			int a[100];
			int i = 0;
			vector<HangHoa> danhSachHangHoa = DocThongTinHangHoa();
			int iSTT = 1;
			ifstream in("donhang.txt");
			string temp;
			while (getline(in, temp)) iSTT++;
			ofstream outt("donhang.txt", ios::app);
			cout << "Nhap cac ma hang ma ban muon mua, moi ma hang cach nhau bang dau phay ','\n";
			getline(cin, maHang);

			string str, maHang1, soLuong1;
			stringstream ss(maHang);
			map<string, int> mpHang;
			while (getline(ss, maHang1, ','))
				mpHang[removeSpace(maHang1)] = 0;
			cout << "\n";
			bool check_ = false;
			for (auto& it : mpHang) {
				bool check = false, checkTonTai = false;
				for (HangHoa& hangHoa : danhSachHangHoa) {
					if (it.first == hangHoa.getMH()) {
						if (!check_) outt << iSTT << '*';
						check_ = true;
						checkTonTai = true;
						do {
							setColor(12);
							cout << (check ? "\nQua So Luong Co The Dat !!!!!\n" : "");
							setColor(11);
							cout << "Nhap so luong cua Ma Hang ( " << it.first << " ): ";
							cin >> it.second;
							check = true;
						} while (it.second > hangHoa.getSL());
						tongTien += it.second * hangHoa.getGB();
						outt << it.first << ':' << it.second << ';';
					}
				}
				if (!checkTonTai) {
					cout << "Khong ton tai san pham: " << it.first << "\n";
				}
			}
			if (check_) {
				outt << "*" << tongTien << "$*";
				tongTien = 0;
				cin.ignore();
				cout << "\nNhap ten cua ban :";
				do {
					getline(cin, tenKhachHang);
				} while (removeSpace(tenKhachHang).empty());
				cout << "\nNhap dia chi cua ban :";
				do {
					getline(cin, diaChiKhachHang);
				} while (removeSpace(diaChiKhachHang).empty());
				cout << "\nNhap so dien thoai cua ban :";
				do {
					getline(cin, soDienThoai);
				} while (removeSpace(soDienThoai).empty());
				cout << "\nNhap ngay dat hang :";
				do {
					getline(cin, ngayDatHang);
				} while (removeSpace(ngayDatHang).empty());

				outt << '*' << tenKhachHang << '*' << diaChiKhachHang
					<< '*' << soDienThoai << '*' << ngayDatHang << "\n";
			}
			cout << "Ban Co Muon Tao Don Hang Moi (Y/N)";
			choooseUS = _getch();

		} while (choooseUS == 'Y' || choooseUS == 'y');
	}
	void xuLyDonHangDauTien() {
		ifstream in("donhang.txt");
		string str;
		(getline(in, str));
		cout << str << "\n";
		string mh = str.substr(0, str.find('*'));
		int sl = stoi(str.substr(str.rfind('*') + 1));
		xuLyDonHang(mh, sl);
		cout << "Da Xu Li Don Hang Thanh Cong Voi Ma Don Hang :" << mh << "\n";
		ofstream tempFile("Temphanghoa.txt", ios::out);
		string line;
		while (getline(in, line)) tempFile << line << '\n';
		in.close();
		tempFile.close();
		remove("hanghoa.txt");
		rename("Temphanghoa.txt", "hanghoa.txt");
	}
};



void manHinhChinh() {
	system("cls");
	HangHoa hhDauTien;
	NhanVien nvNhanVien;
	DonHang dhang;
	setColor(12);
	cout << "\n\n\n\n";
	cout << "\t\t\t*************************************************************************";
	cout << "\n\t\t\t*\t\t\t\t\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\tQUAN LY BAN HANG ONLINE\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t\t\t\t\t\t\t*";
	cout << "\n\t\t\t*************************************************************************";
	cout << "\n\t\t\t*\t\t\t1. Hien thi thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t2. Tim kiem thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t3. Dat hang\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t4. Dang nhap\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t0. Exit\t\t\t\t\t\t*";
	cout << "\n\t\t\t*************************************************************************\n\n\n";
	setColor(9);
nhapLai:
	cout << "Nhap lua chon cua ban: \n";
	char iSo, cChar;
	string strTimKiem;
	do {
		iSo = _getch();
	} while (iSo < '0' || iSo > '4');
casew:
	system("cls");
	switch (iSo) {
	case '1':
		cout << "\t\t\t\t*************************************************\n";
		cout << "\t\t\t\t*\t\tHIEN THI HANG HOA\t\t*";
		cout << "\n\t\t\t\t*************************************************\n";
		cout << "tat ca don hang hien co:\n\n\n";
		hhDauTien.hienThiHangHoa();
		cout << "\nAn nut bat ky de quay ve menu";
		_getch();
		manHinhChinh();
		break;
	case '2':
		cout << "\t\t\t\t*************************************************\n";
		cout << "\t\t\t\t*\t\tTIM THONG TIN HANG HOA\t\t*";
		cout << "\n\t\t\t\t*************************************************\n";
		cout << "\n\t\tNhap ten hang hoa can tim: ";
		getline(cin, strTimKiem);
		hhDauTien.timKiemThongTin(strTimKiem);
		cout << "\n\nBan co muon thuc hien tim kiem lai ? (Y) ";
		cChar = _getch();
		if (cChar == 'y' || cChar == 'Y') {
			goto casew;
		}
		manHinhChinh();
		break;
	case '3':
		system("cls");
		cout << "\t\t\t\t*************************************************\n";
		cout << "\t\t\t\t*\t\tDAT HANG\t\t*";
		cout << "\n\t\t\t\t*************************************************\n";
		dhang.taoDonHang();
		manHinhChinh();
		break;
	case '4':
		nvNhanVien.login();
		cout << "\nAn nut bat ky de quay ve menu";
		manHinhChinh();
		break;
	case '0':
		cout << "Do you readly want exit my program ? (Y)  ";
		cChar = _getch();
		if (cChar == 'Y' || cChar == 'y') exit(0);
		manHinhChinh();
		break;
	}
}
void quanLy() {
	system("cls");
	DonHang dh;
	HangHoa hh;
	int color = 1;
	cout << "\t\t\t*\t\t\t\t\t*\n\n\n LOADING:";
	string loadDing = "[<3 <3 0% ========== 25% ============= 50% ============= 75% ========= 100% <3 <3]";
	for (auto c : loadDing) {
		if (color == 7) color = 1;
		setColor(color++);
		cout << c;
		this_thread::sleep_for(chrono::milliseconds(5)); // Đợi 50 ms (0.05 giây)
	}
	cout << "\n\n\n\t\t\t\t\tDANG NHAP THANH CONG";
	this_thread::sleep_for(chrono::milliseconds(1000));
	setColor(7);
	system("cls");
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "\t\t\t*\t\t\tMENU QUAN LY\t\t\t\t*" << endl;
	cout << "\t\t\t*****************************************************************" << endl;
	cout << "1. Xy ly don hang\n";
	cout << "2. Quan ly hang hoa\n";
	cout << "3. (Danh Cho Admin) Them tai khoan admin\n";
	cout << "0. Quay Ve Menu Chinh\n";
	char iChon = _getch();
	if (iChon == '1') {
		dh.xuLyDonHangDauTien();
	}
	else if (iChon == '2') {
		system("cls");
		cout << "\t\t\t*****************************************************************" << endl;
		cout << "\t\t\t*\t\t\tQUAN LY HANG HOA\t\t\t\t*" << endl;
		cout << "\t\t\t*****************************************************************" << endl;
		cout << "1. THEM HANG HOA\n";
		cout << "2. XOA HANG HOA\n";
		cout << "3. CAP NHAT SO LUONG HANG HOA\n";
		char choose_ = _getch();
		switch (choose_)
	case '1':
		cin >> hh;
		/*case '2' :

		case '3' :*/

	}
	else if (iChon == '3') {
		int i = 0;
		bool check = false;
		string user, pass;
		cout << "\nInput UserName Admin: ";
		cin >> user;
		do {
			if (i++ == 3) break;
			(check ? "Wrong password or username, Try againt" : "");
			check = true;
			cout << "\nInput Password Admin: ";
			cin >> pass;

		} while (user == pass && pass == "admin");
		if (i < 3) themTk();
		i = 0;
	}
	else if (iChon == '0') manHinhChinh();
	quanLy();
}

/*************************************
*									 *
*			 HÀM LÀM MÀU 3	         *
*									 *
**************************************/
void helloWorld() {
	string str = "NHAN - DEPTRAI=================================\n";
	for (auto c : str) {
		sleepChrono(10);
		cout << c;
	}
	setColor(1);
	cout << "\t\t\t\CHUONG TRINH QUAN LY BAN HANG ONLINE\n";
	sleepChrono(2);
	cout << "\t\t\t\CHUONG TRINH QUAN LY BAN HANG ONLINE\n";
	sleepChrono(3000);
	system("cls");
	manHinhChinh();
}


int main() {
	helloWorld();
}
