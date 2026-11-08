#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
int nhap_so_nguyen() {
    int gia_tri;
    while (true) {
        if (cin >> gia_tri) {
            return gia_tri;
        }
        else {
            cout << "Loi kieu du lieu. Vui long nhap lai so: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
class phuong_tien {
private:
    int ma_xe;
    string loai_xe;
    int gio_vao;
    int tg_do;
public:
    phuong_tien();
    phuong_tien(int ma, string loai, int gio, int tg);
    int lay_ma_xe() const;
    string lay_loai_xe() const;
    double tinh_phi() const;
    void hien_thi() const;
};
phuong_tien::phuong_tien() : ma_xe(0), loai_xe(""), gio_vao(0), tg_do(0) {}
phuong_tien::phuong_tien(int ma, string loai, int gio, int tg)
    : ma_xe(ma), loai_xe(loai), gio_vao(gio), tg_do(tg) {
}
int phuong_tien::lay_ma_xe() const { return ma_xe; }
string phuong_tien::lay_loai_xe() const { return loai_xe; }
double phuong_tien::tinh_phi() const {
    double gia = (loai_xe == "Car") ? 6.0 : (loai_xe == "Motorcycle") ? 4.0 : 2.0;
    bool cao_diem = (gio_vao >= 6 && gio_vao <= 9) || (gio_vao >= 15 && gio_vao <= 18);
    double tong = 0;
    for (int h = 0; h < tg_do; ++h) {
        if (h < 2) tong += gia * (cao_diem ? 1.30 : 0.95);
        else       tong += gia * 0.90;
    }
    return tong;
}
void phuong_tien::hien_thi() const {
    cout << "  ID: " << ma_xe << " | " << loai_xe
        << " | " << gio_vao << "h | " << tg_do << "h"
        << " | Phi: $" << fixed << setprecision(2) << tinh_phi() << "\n";
}
class bai_xe {
private:
    int ma_bai;
    char kich_thuoc;
    static const int max_xe = 3;
    phuong_tien mang_xe[max_xe];
    int so_xe_hien_tai;
public:
    bai_xe();
    bai_xe(int ma, char kt);
    int lay_ma() const;
    bool day_chua() const;
    bool them(phuong_tien v);
    int tim_vi_tri_xe(int ma_xe) const;
    bool xoa(int ma_xe);
    bool chua(int ma_xe) const;
    void hien_thi() const;
    bool co_loai(string loai, int& dem, double& tong) const;
};
bai_xe::bai_xe() : ma_bai(0), kich_thuoc('S'), so_xe_hien_tai(0) {}
bai_xe::bai_xe(int ma, char kt) : ma_bai(ma), kich_thuoc(kt), so_xe_hien_tai(0) {}
int bai_xe::lay_ma() const { return ma_bai; }
bool bai_xe::day_chua() const {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    return so_xe_hien_tai >= cap;
}
bool bai_xe::them(phuong_tien v) {
    if (day_chua()) return false;
    mang_xe[so_xe_hien_tai] = v;
    so_xe_hien_tai++;
    return true;
}
int bai_xe::tim_vi_tri_xe(int ma_xe) const {
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        if (mang_xe[i].lay_ma_xe() == ma_xe) return i;
    }
    return -1;
}
bool bai_xe::xoa(int ma_xe) {
    int vi_tri = tim_vi_tri_xe(ma_xe);
    if (vi_tri == -1) return false;
    for (int i = vi_tri; i < so_xe_hien_tai - 1; ++i) {
        mang_xe[i] = mang_xe[i + 1];
    }
    so_xe_hien_tai--;
    return true;
}
bool bai_xe::chua(int ma_xe) const {
    return tim_vi_tri_xe(ma_xe) != -1;
}
void bai_xe::hien_thi() const {
    int cap = (kich_thuoc == 'S') ? 1 : (kich_thuoc == 'M') ? 2 : 3;
    cout << "Bai " << ma_bai << " [" << kich_thuoc << "] "
        << so_xe_hien_tai << "/" << cap << " xe\n";
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        mang_xe[i].hien_thi();
    }
}
bool bai_xe::co_loai(string loai, int& dem, double& tong) const {
    dem = 0; tong = 0;
    for (int i = 0; i < so_xe_hien_tai; ++i) {
        if (mang_xe[i].lay_loai_xe() == loai) {
            ++dem;
            tong += mang_xe[i].tinh_phi();
        }
    }
    return dem > 0;
}
class SystemInterface {
private:
    static const int max_bai = 10;
    bai_xe mang_bai[max_bai];
    int so_bai_hien_tai;
public:
    SystemInterface();
    void runMenu();
    bool kiem_tra_trung_ma_bai(int ma) const;
    bool kiem_tra_trung_ma_xe(int ma) const;
    int tao_ma_ngau_nhien() const;
};
SystemInterface::SystemInterface() : so_bai_hien_tai(0) {
    srand(time(NULL));
}
bool SystemInterface::kiem_tra_trung_ma_bai(int ma) const {
    for (int i = 0; i < so_bai_hien_tai; ++i) {
        if (mang_bai[i].lay_ma() == ma) return true;
    }
    return false;
}
bool SystemInterface::kiem_tra_trung_ma_xe(int ma) const {
    for (int i = 0; i < so_bai_hien_tai; ++i) {
        if (mang_bai[i].chua(ma)) return true;
    }
    return false;
}
int SystemInterface::tao_ma_ngau_nhien() const {
    return rand() % 9000 + 1000;
}
void SystemInterface::runMenu() {
    int chon;
    while (true) {
        cout << "\n===== QUAN LY BAI DO XE (GIAI DOAN 2) =====\n";
        cout << "1. Tao bai do (Toi da 10)\n";
        cout << "2. Them xe (Tu dong xep bai)\n";
        cout << "3. Xoa bai do\n";
        cout << "4. Lay xe ra\n";
        cout << "5. Hien thi tat ca bai do\n";
        cout << "6. Hien thi xe theo bai\n";
        cout << "7. Liet ke xe theo loai\n";
        cout << "8. Bao cao phi trung binh\n";
        cout << "9. Thoat\n";
        cout << "Chon: ";
        chon = nhap_so_nguyen();
        switch (chon) {
        case 1: {
            if (so_bai_hien_tai >= max_bai) {
                cout << "He thong da dat toi da 10 bai do. Khong the tao them!\n";
                break;
            }
            cout << "Ma bai: "; int ma = nhap_so_nguyen();
            if (kiem_tra_trung_ma_bai(ma)) {
                cout << "Canh bao: ID da ton tai! ";
                ma = tao_ma_ngau_nhien();
                cout << "He thong tu dong gán ID ngau nhien: " << ma << "\n";
            }
            char kt;
            cout << "Kich thuoc (S/M/L): "; cin >> kt;
            kt = toupper(kt);
            mang_bai[so_bai_hien_tai] = bai_xe(ma, kt);
            so_bai_hien_tai++;
            cout << "Da tao bai " << ma << "\n";
            break;
        }
        case 2: {
            if (so_bai_hien_tai == 0) {
                cout << "He thong hien chua co bai do nao. Vui long tao truoc!\n";
                break;
            }
            cout << "Ma xe: "; int ma = nhap_so_nguyen();
            if (kiem_tra_trung_ma_xe(ma)) {
                cout << "Canh bao: Ma xe da co trong he thong! ";
                ma = tao_ma_ngau_nhien();
                cout << "He thong tu dong gan ID ngau nhien: " << ma << "\n";
            }
            string loai;
            cout << "Loai (Car/Motorcycle/Bicycle): "; cin >> loai;
            cout << "Gio vao (0-23): "; int gio = nhap_so_nguyen();
            cout << "Thoi luong (1-23): "; int tg = nhap_so_nguyen();
            phuong_tien v(ma, loai, gio, tg);
            bool ok = false;
            for (int i = 0; i < so_bai_hien_tai; ++i) {
                if (!mang_bai[i].day_chua()) {
                    mang_bai[i].them(v);
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << "Da them xe " << ma << " | Phi: $" << fixed << setprecision(2) << v.tinh_phi() << "\n";
            }
            else {
                cout << "Tat ca bai do da day!\n";
            }
            break;
        }
        case 3: {
            cout << "Ma bai can xoa: "; int ma = nhap_so_nguyen();
            bool xoa_ok = false;

            for (int i = 0; i < so_bai_hien_tai; ++i) {
                if (mang_bai[i].lay_ma() == ma) {
                    for (int j = i; j < so_bai_hien_tai - 1; ++j) {
                        mang_bai[j] = mang_bai[j + 1];
                    }
                    so_bai_hien_tai--;
                    xoa_ok = true;
                    cout << "Da xoa bai " << ma << "\n";
                    break;
                }
            }
            if (!xoa_ok) cout << "Khong tim thay bai " << ma << "\n";
            break;
        }
        case 4: {
            cout << "Ma xe can lay ra: "; int ma = nhap_so_nguyen();
            bool xoa_ok = false;
            for (int i = 0; i < so_bai_hien_tai; ++i) {
                if (mang_bai[i].xoa(ma)) {
                    xoa_ok = true;
                    cout << "Da lay xe ra khoi he thong\n";
                    break;
                }
            }
            if (!xoa_ok) cout << "Khong tim thay xe tren he thong\n";
            break;
        }
        case 5: {
            if (so_bai_hien_tai == 0) {
                cout << "Khong co bai do nao de hien thi.\n";
            }
            for (int i = 0; i < so_bai_hien_tai; ++i) {
                mang_bai[i].hien_thi();
            }
            break;
        }
        case 6: {
            cout << "Ma bai: "; int ma = nhap_so_nguyen();
            bool tim_thay = false;
            for (int i = 0; i < so_bai_hien_tai; ++i) {
                if (mang_bai[i].lay_ma() == ma) {
                    mang_bai[i].hien_thi();
                    tim_thay = true;
                    break;
                }
            }
            if (!tim_thay) cout << "Khong tim thay bai do\n";
            break;
        }
        case 7: {
            string loai;
            cout << "Loai xe (Car/Motorcycle/Bicycle): "; cin >> loai;
            int dem; double tong;
            for (int i = 0; i < so_bai_hien_tai; ++i) {
                if (mang_bai[i].co_loai(loai, dem, tong)) {
                    mang_bai[i].hien_thi();
                }
            }
            break;
        }
        case 8: {
            string loai_arr[3] = { "Car", "Motorcycle", "Bicycle" };
            for (int t = 0; t < 3; ++t) {
                int dem = 0; double tong = 0;
                for (int i = 0; i < so_bai_hien_tai; ++i) {
                    int d; double s;
                    if (mang_bai[i].co_loai(loai_arr[t], d, s)) {
                        dem += d;
                        tong += s;
                    }
                }
                cout << loai_arr[t] << ": ";
                if (dem == 0) cout << "khong co xe\n";
                else cout << dem << " xe | TB: $" << fixed << setprecision(2) << tong / dem << "\n";
            }
            break;
        }
        case 9:
            return;
        default:
            cout << "Lua chon khong hop le!\n";
            break;
        }
    }
}
int main() {
    SystemInterface sys;
    sys.runMenu();
    return 0;
}