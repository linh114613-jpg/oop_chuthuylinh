#include <iostream>
#include <string>
using namespace std;
class Xe {
private:
    int maXe;
    string loaiXe;
    int gioVao;
    int thoiGianDo;
    double phiDoXe;
    bool dangChiemCho;
public:
    Xe();
    Xe(int ma, const string& loai, int gio, int thoiLuong);
    int layMaXe() const;
    string layLoaiXe() const;
    int layGioVao() const;
    int layThoiGianDo() const;
    double layPhiDoXe() const;
    bool layDangChiemCho() const;
    void ganMaXe(int ma);
    void ganLoaiXe(const string& loai);
    void ganGioVao(int gio);
    void ganThoiLuongDo(int thoiLuong);
    void ganPhiDoXe(double phi);
    void ganDangChiemCho(bool trangThai);
    static string chuanHoaLoaiXe(const string& loai);
    static bool laLoaiXeHopLe(const string& loai);
    void tinhPhiDoXe();
    void hienThi() const;
};
Xe::Xe() {
    maXe = 0;
    loaiXe = "";
    gioVao = 0;
    thoiGianDo = 0;
    phiDoXe = 0.0;
    dangChiemCho = false;
}
Xe::Xe(int ma, const string& loai, int gio, int thoiLuong) {
    maXe = ma;
    loaiXe = chuanHoaLoaiXe(loai);
    gioVao = gio;
    thoiGianDo = thoiLuong;
    phiDoXe = 0.0;
    dangChiemCho = true;
}
int Xe::layMaXe() const { return maXe; }
string Xe::layLoaiXe() const { return loaiXe; }
int Xe::layGioVao() const { return gioVao; }
int Xe::layThoiGianDo() const { return thoiGianDo; }
double Xe::layPhiDoXe() const { return phiDoXe; }
bool Xe::layDangChiemCho() const { return dangChiemCho; }
void Xe::ganMaXe(int ma) { maXe = ma; }
void Xe::ganLoaiXe(const string& loai) { loaiXe = chuanHoaLoaiXe(loai); }
void Xe::ganGioVao(int gio) { gioVao = gio; }
void Xe::ganThoiLuongDo(int thoiLuong) { thoiGianDo = thoiLuong; }
void Xe::ganPhiDoXe(double phi) { phiDoXe = phi; }
void Xe::ganDangChiemCho(bool trangThai) { dangChiemCho = trangThai; }
string Xe::chuanHoaLoaiXe(const string& loai) {
    if (loai.empty()) return "";
    string ketQua = loai;
    for (size_t i = 0; i < ketQua.length(); ++i) {
        ketQua[i] = tolower(ketQua[i]);
    }
    ketQua[0] = toupper(ketQua[0]);
    return ketQua;
}
bool Xe::laLoaiXeHopLe(const string& loai) {
    string loaiDaChuanHoa = chuanHoaLoaiXe(loai);
    return (loaiDaChuanHoa == "Car" ||
        loaiDaChuanHoa == "Motorcycle" ||
        loaiDaChuanHoa == "Bicycle");
}
void Xe::tinhPhiDoXe() {
    if (!dangChiemCho) return;
    double donGiaCoBan = 0.0;
    if (loaiXe == "Car") {
        donGiaCoBan = 6.00;
    }
    else if (loaiXe == "Motorcycle") {
        donGiaCoBan = 4.00;
    }
    else if (loaiXe == "Bicycle") {
        donGiaCoBan = 2.00;
    }
    bool laGioCaoDiem = (gioVao >= 6 && gioVao < 10) || (gioVao >= 15 && gioVao < 19);
    int soGioDau = (thoiGianDo > 2) ? 2 : thoiGianDo;
    int soGioSau = (thoiGianDo > 2) ? (thoiGianDo - 2) : 0;
    double phiGioDau = 0.0;
    if (laGioCaoDiem) {
        phiGioDau = soGioDau * (donGiaCoBan * 1.30);
    }
    else {
        phiGioDau = soGioDau * (donGiaCoBan * 0.95);
    }
    double phiGioSau = 0.0;
    if (soGioSau > 0) {
        phiGioSau = soGioSau * (donGiaCoBan * 0.90);
    }
    phiDoXe = phiGioDau + phiGioSau;
}
void Xe::hienThi() const {
    if (!dangChiemCho) {
        cout << "[-] Vi tri trong." << endl;
        return;
    }
    cout << "--- Thong tin xe ---" << endl;
    cout << "Ma xe         : " << maXe << endl;
    cout << "Loai xe       : " << loaiXe << endl;
    cout << "Gio vao       : " << gioVao << "h" << endl;
    cout << "Thoi luong do : " << thoiGianDo << " gio" << endl;
    cout << "Phi do xe     : " << phiDoXe << " VND" << endl;
    cout << "--------------------" << endl;
}
class baiDoXe {
private:
    int maBai;
    char kichCo;
    Xe xe1;
    Xe xe2;
    Xe xe3;
    bool coXe1;
    bool coXe2;
    bool coXe3;
public:
    int layMaBai() const { return maBai; }
    char layKichCo() const { return kichCo; }
    baiDoXe() {
        maBai = 0;
        kichCo = 'S';
        coXe1 = false;
        coXe2 = false;
        coXe3 = false;
    }
    baiDoXe(int ma, char kCo) {
        maBai = ma;
        kichCo = kCo;
        coXe1 = false;
        coXe2 = false;
        coXe3 = false;
    }
    bool themXe(const Xe& x) {
        if (kichCo == 'S') {
            if (coXe1 == false) {
                xe1 = x;
                coXe1 = true;
                return true;
            }
                return false;
        }
        else if (kichCo == 'M') {
            if (coXe1 == false) {
                xe1 = x;
                coXe1 = true;
                return true;
            }
            if (coXe2 == false) {
                xe2 = x;
                coXe2 = true;
                return true;
            }
                return false;
        }
        else if (kichCo == 'L') {
            if (coXe1 == false) {
                xe1 = x;
                coXe1 = true;
                return true;
            }
            if (coXe2 == false) {
                xe2 = x;
                coXe2 = true;
                return true;
            }
            if (coXe3 == false) {
                xe3 = x;
                coXe3 = true;
                return true;
            }
                return false;
        }
        return false;
    }
    bool xoaXe(int xMa) {
        if (coXe1 == true && xe1.layMaXe() == xMa) {
            coXe1 = false;
            return true;
        }
        if (coXe2 == true && xe2.layMaXe() == xMa) {
            coXe2 = false;
            return true;
        }
        if (coXe3 == true && xe3.layMaXe() == xMa) {
            coXe3 = false;
            return true;
        }
        return false;
    }
    void hienThiThongTin() const {
        cout << "=============================" << endl;
        cout << "Ma bai do : " << maBai << endl;
        cout << "Kich co   : " << kichCo << " (";
        if (kichCo == 'S') cout << "Toi da 1 xe";
        else if (kichCo == 'M') cout << "Toi da 2 xe";
        else if (kichCo == 'L') cout << "Toi da 3 xe";
        cout << ")" << endl;
        cout << "--- Danh sach xe trong bai ---" << endl;
        bool coXeTrongBai = false;
        if (coXe1) {
            xe1.hienThi();
            coXeTrongBai = true;
        }
        if (coXe2) {
            xe2.hienThi();
            coXeTrongBai = true;
        }
        if (coXe3) {
            xe3.hienThi();
            coXeTrongBai = true;
        }
        if (!coXeTrongBai) {
            cout << "[-] Bai do xe hien dang trong." << endl;
        }
        cout << "=============================" << endl;
    }
    int laySoLuongXe() const {
        int dem = 0;
        if (coXe1) dem++;
        if (coXe2) dem++;
        if (coXe3) dem++;
        return dem;
    }
    int laySucChuaToiDa() const {
        if (kichCo == 'S') return 1;
        if (kichCo == 'M') return 2;
        if (kichCo == 'L') return 3;
        return 0;
    }
    bool conChoTrong() const {
        return laySoLuongXe() < laySucChuaToiDa();
    }
    void hienThiTongQuan() const {
        cout << " - ID Bai: " << maBai << " | Kich co: " << kichCo
            << " | So xe hien tai: " << laySoLuongXe() << "/" << laySucChuaToiDa() << endl;
    }
    void thongKeTheoLoai(const string& loaiTimKiem, double& tongPhi, int& soLuong) const {
        if (coXe1 && xe1.layLoaiXe() == loaiTimKiem) {
            xe1.hienThi();
            tongPhi += xe1.layPhiDoXe();
            soLuong++;
        }
        if (coXe2 && xe2.layLoaiXe() == loaiTimKiem) {
            xe2.hienThi();
            tongPhi += xe2.layPhiDoXe();
            soLuong++;
        }
        if (coXe3 && xe3.layLoaiXe() == loaiTimKiem) {
            xe3.hienThi();
            tongPhi += xe3.layPhiDoXe();
            soLuong++;
        }
    }
};
class GDvaDH {
private:
    baiDoXe b1;
    baiDoXe b2;
    baiDoXe b3;
    bool coB1;
    bool coB2;
    bool coB3;
    bool kiemTraTrungIDBai(int id) const {
        if (coB1 && b1.layMaBai() == id) return true;
        if (coB2 && b2.layMaBai() == id) return true;
        if (coB3 && b3.layMaBai() == id) return true;
        return false;
    }
public:
    GDvaDH() {
        coB1 = false;
        coB2 = false;
        coB3 = false;
    }
    void runMenu() {
        int luaChon = 0;
        while (luaChon != 9) {
            cout << "\n========== HE THONG QUAN LY BAI DO XE ==========" << endl;
            cout << "1. Tao Bai do xe moi" << endl;
            cout << "2. Them xe vao bai do (Tu dong xep bai)" << endl;
            cout << "3. Xoa mot Bai do xe" << endl;
            cout << "4. Lay xe ra khoi bai do" << endl;
            cout << "5. Hien thi danh sach tong quan cac Bai do xe" << endl;
            cout << "6. Hien thi danh sach xe theo bai cu the" << endl;
            cout << "7. Liet ke xe theo loai phuong tien" << endl;
            cout << "8. Xem bao cao tom tat phi do xe trung binh" << endl;
            cout << "9. Thoat chuong trinh" << endl;
            cout << "================================================" << endl;
            cout << "Nhap lua chon (1-9): ";
            cin >> luaChon;
            if (luaChon == 1) {
                if (coB1 && coB2 && coB3) {
                    cout << "[-] He thong da dat toi da 3 bai do. Khong the tao them." << endl;
                    continue;
                }
                int maBai; char kichCo;
                cout << "Nhap ID bai do: "; cin >> maBai;

                if (kiemTraTrungIDBai(maBai)) {
                    cout << "[-] ID bai do da ton tai. Vui long chon ID khac." << endl;
                    continue;
                }
                cout << "Nhap kich co ('S', 'M', 'L'): "; cin >> kichCo;
                kichCo = toupper(kichCo);
                baiDoXe baiMoi(maBai, kichCo);
                if (!coB1) { b1 = baiMoi; coB1 = true; }
                else if (!coB2) { b2 = baiMoi; coB2 = true; }
                else if (!coB3) { b3 = baiMoi; coB3 = true; }
                cout << "[+] Tao bai do xe thanh cong." << endl;
            }
            else if (luaChon == 2) {
                if (!coB1 && !coB2 && !coB3) {
                    cout << "[-] Chua co bai do xe nao." << endl; continue;
                }
                int maXe, gioVao, thoiLuong; string loaiXe;
                cout << "Nhap ma xe: "; cin >> maXe;
                cout << "Nhap loai xe (Car, Motorcycle, Bicycle): "; cin >> loaiXe;
                cout << "Nhap gio vao (0-23): "; cin >> gioVao;
                cout << "Nhap thoi luong (gio): "; cin >> thoiLuong;
                if (!Xe::laLoaiXeHopLe(loaiXe)) {
                    cout << "[-] Loai xe khong hop le." << endl; continue;
                }
                Xe xeMoi(maXe, loaiXe, gioVao, thoiLuong);
                xeMoi.tinhPhiDoXe();
                bool daThem = false;
                if (!daThem && coB1 && b1.conChoTrong()) { daThem = b1.themXe(xeMoi); }
                if (!daThem && coB2 && b2.conChoTrong()) { daThem = b2.themXe(xeMoi); }
                if (!daThem && coB3 && b3.conChoTrong()) { daThem = b3.themXe(xeMoi); }
                if (daThem) cout << "[+] Xe da duoc xep vao bai tu dong." << endl;
                else cout << "[-] He thong da het cho trong phu hop." << endl;
            }
            else if (luaChon == 3) {
                int idXoa; cout << "Nhap ID bai do can xoa: "; cin >> idXoa;
                bool daXoa = false;
                if (coB1 && b1.layMaBai() == idXoa) { coB1 = false; daXoa = true; }
                else if (coB2 && b2.layMaBai() == idXoa) { coB2 = false; daXoa = true; }
                else if (coB3 && b3.layMaBai() == idXoa) { coB3 = false; daXoa = true; }
                if (daXoa) cout << "[+] Da xoa bai do xe." << endl;
                else cout << "[-] Khong tim thay ID bai do." << endl;
            }
            else if (luaChon == 4) {
                int idXeXoa; cout << "Nhap ma xe can lay ra: "; cin >> idXeXoa;
                bool daXoa = false;
                if (!daXoa && coB1) daXoa = b1.xoaXe(idXeXoa);
                if (!daXoa && coB2) daXoa = b2.xoaXe(idXeXoa);
                if (!daXoa && coB3) daXoa = b3.xoaXe(idXeXoa);
                if (daXoa) cout << "[+] Da lay xe ra khoi bai." << endl;
                else cout << "[-] Khong tim thay xe." << endl;
            }
            else if (luaChon == 5) {
                cout << "\n--- TONG QUAN CAC BAI DO XE ---" << endl;
                if (!coB1 && !coB2 && !coB3) cout << "Khong co bai do xe nao." << endl;
                if (coB1) b1.hienThiTongQuan();
                if (coB2) b2.hienThiTongQuan();
                if (coB3) b3.hienThiTongQuan();
            }
            else if (luaChon == 6) {
                int idXem; cout << "Nhap ID bai do can xem chi tiet: "; cin >> idXem;
                bool timThay = false;
                if (coB1 && b1.layMaBai() == idXem) { b1.hienThiThongTin(); timThay = true; }
                else if (coB2 && b2.layMaBai() == idXem) { b2.hienThiThongTin(); timThay = true; }
                else if (coB3 && b3.layMaBai() == idXem) { b3.hienThiThongTin(); timThay = true; }
                if (!timThay) cout << "[-] Khong tim thay bai do xe." << endl;
            }
            else if (luaChon == 7) {
                string loaiTK; cout << "Nhap loai xe can tim: "; cin >> loaiTK;
                loaiTK = Xe::chuanHoaLoaiXe(loaiTK);
                double tempPhi = 0; int tempSL = 0;
                cout << "\n--- DANH SACH XE " << loaiTK << " ---" << endl;
                if (coB1) { cout << "[Bai " << b1.layMaBai() << "]:\n"; b1.thongKeTheoLoai(loaiTK, tempPhi, tempSL); }
                if (coB2) { cout << "[Bai " << b2.layMaBai() << "]:\n"; b2.thongKeTheoLoai(loaiTK, tempPhi, tempSL); }
                if (coB3) { cout << "[Bai " << b3.layMaBai() << "]:\n"; b3.thongKeTheoLoai(loaiTK, tempPhi, tempSL); }
                if (tempSL == 0) cout << "Khong co xe loai nay trong he thong." << endl;
            }
            else if (luaChon == 8) {
                cout << "\n--- BAO CAO PHI DO XE TRUNG BINH ---" << endl;
                double tongPhiCar = 0, tongPhiMoto = 0, tongPhiBike = 0;
                int tongXeCar = 0, tongXeMoto = 0, tongXeBike = 0;
                if (coB1) b1.thongKeTheoLoai("Car", tongPhiCar, tongXeCar);
                if (coB2) b2.thongKeTheoLoai("Car", tongPhiCar, tongXeCar);
                if (coB3) b3.thongKeTheoLoai("Car", tongPhiCar, tongXeCar);
                if (coB1) b1.thongKeTheoLoai("Motorcycle", tongPhiMoto, tongXeMoto);
                if (coB2) b2.thongKeTheoLoai("Motorcycle", tongPhiMoto, tongXeMoto);
                if (coB3) b3.thongKeTheoLoai("Motorcycle", tongPhiMoto, tongXeMoto);
                if (coB1) b1.thongKeTheoLoai("Bicycle", tongPhiBike, tongXeBike);
                if (coB2) b2.thongKeTheoLoai("Bicycle", tongPhiBike, tongXeBike);
                if (coB3) b3.thongKeTheoLoai("Bicycle", tongPhiBike, tongXeBike);
                cout << "> Car: ";
                if (tongXeCar > 0) cout << "$" << (tongPhiCar / tongXeCar) << " / xe" << endl;
                else cout << "0 xe (Khong co du lieu)" << endl;
                cout << "> Motorcycle: ";
                if (tongXeMoto > 0) cout << "$" << (tongPhiMoto / tongXeMoto) << " / xe" << endl;
                else cout << "0 xe (Khong co du lieu)" << endl;
                cout << "> Bicycle: ";
                if (tongXeBike > 0) cout << "$" << (tongPhiBike / tongXeBike) << " / xe" << endl;
                else cout << "0 xe (Khong co du lieu)" << endl;
            }
            else if (luaChon == 9) {
                cout << "Thoat he thong." << endl;
            }
            else {
                cout << "[-] Lua chon khong hop le." << endl;
            }
        }
    }
};
int main() {
    GDvaDH heThong;
    heThong.runMenu();
    return 0;
}