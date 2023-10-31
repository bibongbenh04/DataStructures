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
#include <ctime>

using namespace std;
void sleepChorono(int milisecond) {
	this_thread::sleep_for(chrono::milliseconds(milisecond));
}
// Set Color text in Console
void setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

//Đen: 0 Xanh Navy : 1
//Xanh Lá Cây : 2 Xanh Biển Đậm : 3
//Đỏ : 4 Tím : 5
//Cam : 6 Xám Đậm : 8
//Xanh Lá Cây Đậm : 10 Xanh Biển : 11
//Hồng : 12 Vàng : 14 Trắng : 15


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
			this_thread::sleep_for(chrono::milliseconds(200));
			stringstream ss(_str);
			cout << "\n";
			while (getline(ss, str, '*')) {
				cout << setw(10) << str <<setw(5) << "|";
				this_thread::sleep_for(chrono::milliseconds(5));
			}
			cout << endl;
		}
		setColor(7);
	}
	void timKiemThongTin(string s) {
		setColor(2);
		cout << "\n\n" << setw(10) << "MA HANG" << setw(5) << "|"
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
			this_thread::sleep_for(chrono::milliseconds(200));
			stringstream ss(_str), ss2(_str);
			string tenHang;
			getline(ss2, tenHang, '*');
			getline(ss2, tenHang, '*');
			if (tenHang.find(s) > tenHang.size()) continue;
			cout << endl;
			while (getline(ss, str, '*')) {
				cout << setw(10) << str << setw(5) << "|";
				this_thread::sleep_for(chrono::milliseconds(5));
			}
			cout << endl;
			
		}
		setColor(7);
	}
	void datHang() {

	}
	vector<HangHoa> DocThongTinHangHoa() {
		vector<HangHoa> danhSachHangHoa;
		ifstream inFile("HangHoa.txt");
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

class DonHang : public HangHoa {
protected:
	int soLuong = 1, tongTien = 0;
	string tenKhachHang, diaChiKhachHang, soDienThoai, ngayDatHang;
	vector<HangHoa> listHangHoa;

public:
	bool xuLyDonHang(string MH, int SL) {
		ifstream in("HangHoa.txt");
		ofstream out("Temp.txt");
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
					remove("Temp.txt");
					return false;
				}
				str.replace(str.rfind('*') + 1, str.length() - (str.rfind('*') + 1), to_string(sl - SL));
				if (sl - SL == 0) str = "";
			}
			out << str << (str.empty() ? "" : "\n");
		}
		in.close();
		out.close();
		remove("HangHoa.txt");
		rename("Temp.txt", "HangHoa.txt");
		cout << "Da Xu Ly Don Hang\n";
		return true;

	}
	void taoDonHang() {
		char choooseUS = '0';
		do {
			system("cls");
			hienThiHangHoa();
			DocThongTinHangHoa();
			vector<HangHoa> danhSachHangHoa = DocThongTinHangHoa();
			ofstream out("DonHang.txt", ios::app);
			cout << "Nhap ma hang, so luong\n";
			cin >> maHang >> soLuong;
			bool coTonTai = false;
			for (HangHoa& hangHoa : danhSachHangHoa) {
				if (maHang == hangHoa.getMH()) {
					coTonTai = true;
					if (soLuong <= hangHoa.getSL()) {
						out << hangHoa.getMH() << '*' << hangHoa.getTH() << '*' << hangHoa.getNSX()
							<< '*' << hangHoa.getMS() << '*' << hangHoa.getGB() << '*'
							<< hangHoa.getNNK() << '*' << hangHoa.getSL() << "\n";
					}
					else {
						cout << "So luong don hang vuot qua so luong hang hoa co san." << endl;
					}
					break;
				}
			}
			if (!coTonTai) {
				cout << "Ma Hang Khong Ton Tai " << endl;
			}
			cout << "Ban Co Muon Tao Don Hang Moi (Y/N)\n";
			choooseUS = _getch();
		} while (choooseUS == 'Y' || choooseUS == 'y');
	}
};
class LISTDONHANCANXULY : DonHang {
	queue<DonHang*> listDonHang;
public:
	LISTDONHANCANXULY() {
	}
	void xuLyDonHangDauTien() {
		ifstream in("DonHang.txt");
		string str;
		(getline(in, str));
		cout << str << "\n";
		string mh = str.substr(0, str.find('*'));
		int sl = stoi(str.substr(str.rfind('*') + 1));
		xuLyDonHang(mh, sl);
		cout << "Da Xu Li Don Hang Thanh Cong Voi Ma Don Hang :" << mh << "\n";
		ofstream tempFile("TempDonHang.txt", ios::out);
		string line;
		while (getline(in, line)) tempFile << line << '\n';
		in.close();
		tempFile.close();
		remove("DonHang.txt");
		rename("TempDonHang.txt", "DonHang.txt");
	}
};
void manHinhChinh() {
	system("cls");
	HangHoa hhDauTien;
	NhanVien nvNhanVien;
	setColor(12);
	cout << "\t\t\t*************************************************************************\n";
	cout << "\t\t\t*                  QUAN LY BAN HANG ONLINE - NHOM THQ                   *\n";
	cout << "\t\t\t*                               MENU LENH                               *\n";
	cout << "\t\t\t*                                                                       *\n";
	cout << "\t\t\t*************************************************************************\n";
	cout << "\t\t\t*\t\t\t1. Hien thi thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t2. Tim kiem thong tin don hang\t\t\t*";
	cout << "\n\t\t\t*\t\t\t3. Dat hang\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t4. Dang nhap\t\t\t\t\t*";
	cout << "\n\t\t\t*\t\t\t0. Exit !!!!!!!!!!\t\t\t\t*";
	cout << "\n\t\t\t*************************************************************************";
	setColor(9);
	cout << "\nNhap lua chon cua ban\n";
	char iSo = ' ', temp, chooseUs;
	string strTimKiem;
	do {
		iSo = _getch();
	} while (iSo < '0' || iSo > '4');
	caseSw:
	system("cls");
	setColor(11);
	switch (iSo) {
		case '1':
			cout << "Tat Ca Thong Tin Don Hang Hien Co :\n\n\n";
			hhDauTien.hienThiHangHoa();
			setColor(12);
			cout << "\n\n\t\t\t\t\tAn nut bat ki de quay ve menu !";
			_getch();
			manHinhChinh();
			break;
		case '2':
			setColor(12);
			cout << "Tim Kiem Thong Tin Hang Hoa !\n\n\n";
			setColor(11);
			cout << "\nNhap ten hang hoa can tim: ";
			getline(cin, strTimKiem);
			hhDauTien.timKiemThongTin(strTimKiem);
			setColor(12);
			cout << "\n\t\tBan co muon thuc hien tim kiem lai khong ? (Y):";
			chooseUs = _getch();
			if (chooseUs == 'Y' || chooseUs == 'y') {
				goto caseSw;
			}
			manHinhChinh();
			break;
		//case 3:
				
		case '4':
			nvNhanVien.login();
			break;
		case '0':
			cout << "\nDo you readly want exit my program ? (Y):";
			chooseUs = _getch();
			if (chooseUs == 'Y' || chooseUs == 'y') exit(0);
			manHinhChinh();
		default:
			break;
	}
}

void HelloWorld() {
	setColor(2);
	string str = " <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 ONETHING SPEACIAL - COMING SOON <3 <3 <3 <3 <3 <3 <3 <3 <3 <3";
	for (auto c : str) {
		sleepChorono(10);
		cout << c;
	}
	setColor(4);
	cout << "\n\t\t\t\tCHUONG TRINH QUAN LI BAN HANG ONLINE\n\n";
	sleepChorono(1000);
	setColor(11);
	cout << "\t\t\t\t\tLE HONG QUAN\n"; sleepChorono(500);
	cout << "\t\t\t\t\tNGUYEN XUAN HUONG\n"; sleepChorono(500);
	cout << "\t\t\t\t\tNGUYEN NGOC HUONG TRA\n"; sleepChorono(3000);
	setColor(7);
	system("cls");
	manHinhChinh();
}

int main() {
	//HelloWorld();
	manHinhChinh();
}
