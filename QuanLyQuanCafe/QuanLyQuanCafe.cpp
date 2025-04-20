#include <bits/stdc++.h>
using namespace std;

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << setw(2) << setfill('0') << ltm->tm_mday << "/"
       << setw(2) << setfill('0') << 1 + ltm->tm_mon << "/"
       << 1900 + ltm->tm_year;

    return ss.str();
}


class DoUong {
	private:
	    string maDoUong;
	    string tenDoUong;
	    int gia;
	    string loai;
	
	public:
	    DoUong() {}
	    DoUong(string ma, string ten, int g, string l) {
	    	maDoUong = ma; 
			tenDoUong = ten;
			gia = g;
			loai = l;
		}
	
	    friend istream& operator>>(istream& in, DoUong& d) {
	        cout << "Nhap ma do uong  : ";
	        in >> d.maDoUong;
	        cout << "Nhap ten do uong : ";
	        in.ignore();
	        getline(in, d.tenDoUong);
	        cout << "Nhap gia         : ";
	        in >> d.gia;
	        cout << "Nhap loai do uong: ";
	        in.ignore();
	        getline(in, d.loai);
	        return in;
	    }
	
	    friend ostream& operator<<(ostream& out, const DoUong& d) {
	        out << left << fixed << setprecision(0);
	        out << "| " << setw(14) << d.maDoUong;
	        out << "| " << setw(19) << d.tenDoUong;
	        out << "| " << setw(10) << d.gia;
	        out << "| " << setw(15) << d.loai;
	        out << "|" << endl;
	        return out;
	    }
	
	    int getGia() {
	        return gia;
	    }
	
	    string getMaDoUong() {
	        return maDoUong;
	    }
	    
		string getTenDoUong() {
		    return tenDoUong;
		}
		
		string getLoai() {
		    return loai;
		}
	};

bool cmp(DoUong a, DoUong b) {
	return a.getGia() > b.getGia();
}

class DanhSachDoUong {
	private:
	    vector<DoUong> danhSach;
	
	public:
	    void nhapDanhSach(int n) {
	        for (int i = 0; i < n; ++i) {
	            DoUong d;
	            cout << "\nNhap thong tin do uong thu " << i + 1 << ":\n";
	            cin >> d;
	            danhSach.push_back(d);
	        }
	    }
		
		DoUong getDoUong(int stt) {
			return danhSach[stt];
		}
	
	    void hienThi() {
	        if (danhSach.empty()) {
	            cout << "Danh sach do uong rong.\n";
	        } else {
	        	cout << "+------+---------------+--------------------+-----------+----------------+" << endl;
			    cout << "| STT  | MA DO UONG    | TEN DO UONG        | GIA       | LOAI           |" << endl;
			    cout << "+------+---------------+--------------------+-----------+----------------+" << endl;
				int stt = 1;
			    for (const auto& d : danhSach) {
			    	cout << "| " << left << setw(5) << stt++;
	                cout << d;
	            }
			    cout << "+------+---------------+--------------------+-----------+----------------+" << endl;

	        }
	    }
	
	    void sapXepDanhSach() {
	        sort(danhSach.begin(), danhSach.end(), cmp);
	    }
	
	    DoUong timMax() {
	        return *max_element(danhSach.begin(), danhSach.end(), [](DoUong& a, DoUong& b) {
	            return a.getGia() < b.getGia();
	        });
	    }
	
	    DoUong timMin() {
	        return *min_element(danhSach.begin(), danhSach.end(), [](DoUong& a, DoUong& b) {
	            return a.getGia() < b.getGia();
	        });
	    }
	
	    void timKiemTheoMa(string ma) {
	        bool found = false;
	        for (DoUong d : danhSach) {
	            if (d.getMaDoUong() == ma) {
	            	cout << "+---------------+--------------------+-----------+----------------+" << endl;
				    cout << "| MA DO UONG    | TEN DO UONG        | GIA       | LOAI           |" << endl;
				    cout << "+---------------+--------------------+-----------+----------------+" << endl;
	                cout << d;
		    		cout << "+---------------+--------------------+-----------+----------------+" << endl;
	                found = true;
	                break;
	            }
	        }
	        if (!found) {
	            cout << "Khong tim thay do uong voi ma: " << ma << endl;
	        }
	    }
	
	    void xoaTheoMa(string ma) {
	        auto it = remove_if(danhSach.begin(), danhSach.end(), [&](DoUong d) {
	            return d.getMaDoUong() == ma;
	        });
	        if (it != danhSach.end()) {
	            danhSach.erase(it, danhSach.end());
	            cout << "Da xoa do uong co ma: " << ma << endl;
	        } else {
	            cout << "Khong tim thay do uong can xoa!" << endl;
	        }
	    }
	
	    void themDoUong() {
	    	DoUong d;
	    	cin >> d;
	        danhSach.push_back(d);
	    }
	    
	    void themDoUongMacDinh() {
		    danhSach.push_back(DoUong("DU01", "Tra sua tran chau", 25000, "Tra sua"));
		    danhSach.push_back(DoUong("DU02", "Ca phe sua", 20000, "Ca phe"));
		    danhSach.push_back(DoUong("DU03", "Sinh to xoai", 30000, "Sinh to"));
		    danhSach.push_back(DoUong("DU04", "Nuoc ep cam", 28000, "Nuoc ep"));
		    danhSach.push_back(DoUong("DU05", "Tra dao cam sa", 32000, "Tra trai cay"));
		    danhSach.push_back(DoUong("DU06", "Coca Cola", 15000, "Nuoc ngot"));
		    danhSach.push_back(DoUong("DU07", "Pepsi", 15000, "Nuoc ngot"));
		    danhSach.push_back(DoUong("DU08", "Matcha da xay", 35000, "Da xay"));
		    danhSach.push_back(DoUong("DU09", "Cacao nong", 22000, "Do nong"));
		    danhSach.push_back(DoUong("DU10", "Cafe den", 18000, "Ca phe"));
		}
	};

class NhanVien {
	private:
	    string maNV;
	    string tenNV;
	    string chucVu;
	    int luong;
	
	public:
	    NhanVien() {}
	    NhanVien(string ma, string ten, string cv, int l) {
	        maNV = ma;
	        tenNV = ten;
	        chucVu = cv;
	        luong = l;
	    }
	
	    string getMaNV() { return maNV; }
	    string getTenNV() { return tenNV; }
	    string getChucVu() { return chucVu; }
	    double getLuong() { return luong; }
	
	    friend istream& operator>>(istream& in, NhanVien& nv) {
	        cout << "Nhap ma nhan vien  : "; in >> nv.maNV;
	        cout << "Nhap ten nhan vien : "; in.ignore(); getline(in, nv.tenNV);
	        cout << "Nhap chuc vu       : "; getline(in, nv.chucVu);
	        cout << "Nhap luong         : "; in >> nv.luong;
	        return in;
	    }
	
	    friend ostream& operator<<(ostream& out, const NhanVien& nv) {
	        out << left << fixed << setprecision(0);
	        out << "| " << setw(11) << nv.maNV;
	        out << "| " << setw(21) << nv.tenNV;
	        out << "| " << setw(14) << nv.chucVu;
	        out << "| " << setw(12) << nv.luong;
	        out << "|" << endl;
	        return out;
	    }
	};

	
class DanhSachNhanVien {
private:
    vector<NhanVien> danhSachNV;

public:
    void themNhanVien() {
        NhanVien nv;
        cin >> nv;
        danhSachNV.push_back(nv);
        cout << "Da them nhan vien!\n";
    }

    void hienThi() {
        if (danhSachNV.empty()) {
            cout << "Danh sach nhan vien rong!\n";
            return;
        }

        cout << "+------------+----------------------+---------------+-------------+\n";
        cout << "| Ma NV      | Ten Nhan Vien        | Chuc Vu       | Luong       |\n";
        cout << "+------------+----------------------+---------------+-------------+\n";
        for (const auto& nv : danhSachNV) {
            cout << nv;
        }
        cout << "+------------+----------------------+---------------+-------------+\n";
    }
    
	void themNhanVienMacDinh() {
	    danhSachNV.push_back(NhanVien("NV01", "Nguyen Van A", "Pha che", 5000000));
	    danhSachNV.push_back(NhanVien("NV02", "Tran Thi B", "Thu ngan", 5500000));
	    danhSachNV.push_back(NhanVien("NV03", "Le Van C", "Phuc vu", 4000000));
	    danhSachNV.push_back(NhanVien("NV04", "Pham Thi D", "Quan ly", 8000000));
	    danhSachNV.push_back(NhanVien("NV05", "Hoang Van E", "Bao ve", 3500000));
	    cout << "Da them danh sach nhan vien mac dinh!\n";
	}

};

class ChiTietHoaDon {
	private:
		DoUong doUong;
		int soLuong;
	public:
		ChiTietHoaDon(DoUong d, int s) {
			doUong = d;
			soLuong = s;
		}
		
		void setDoUong(DoUong d) {
        	doUong = d;
	    }
	
	    void setSoLuong(int sl) {
	        soLuong = sl;
	    }
	
	    DoUong getDoUong() {
	        return doUong;
	    }
	
	    int getSoLuong() {
	        return soLuong;
	    }
	    
	    int getThanhTien() {
	        return soLuong * doUong.getGia();
	    }
	
};
	
class HoaDon {
	private:
	    string maHoaDon;
	    NhanVien nhanVien;
	    vector<ChiTietHoaDon> danhSachDoUong;
	    string ngayLap;
	    string phuongThucThanhToan;
	    string trangThai;
	
	public:
	    HoaDon() {}

	    void setMaHoaDon(string ma) {
	        maHoaDon = ma;
	    }
	
	    void setNgayLap(string ngay) {
	        ngayLap = ngay;
	    }
	
	    void setNhanVien(NhanVien nv) {
	    	nhanVien = nv;
		}

		void setPhuongThucThanhToan(string p) {
	    	phuongThucThanhToan = p;
		}
		
		void setTrangThai(string t) {
	    	trangThai = t;
		}
	
	    string getMaHoaDon() {
	        return maHoaDon;
	    }
	
	    string getNgayLap() {
	        return ngayLap;
	    }
	    
	    NhanVien getNhanVien() {
	    	return nhanVien;
		}
		
		string getPhuongThucThanhToan() {
			return phuongThucThanhToan;
		}
		
		string getTrangThai() {
			return trangThai;
		}
		
		vector<ChiTietHoaDon> getDanhSachDoUong() {
			return danhSachDoUong;
		}
		
		int getTongTien() {
			int tongTien = 0;
			for (ChiTietHoaDon i : danhSachDoUong) {
				tongTien += i.getThanhTien();
			}
			return tongTien;
		}
		
		void themDoUong(ChiTietHoaDon c) {
			danhSachDoUong.push_back(c);
		}
		
		void hienThi() {
			cout << left << fixed << setprecision(0);
			cout << "+================================ HOA DON ===============================+\n";
			cout << "| MA HOA DON              : " << setw(45) << maHoaDon << "|" << endl;
		    cout << "| NGAY TAO                : " << setw(45) << ngayLap << "|" << endl;
		    cout << "| NHAN VIEN               : " << setw(45) << nhanVien.getTenNV() << "|" << endl;
		    cout << "| PHUONG THUOC THANH TOAN : " << setw(45) << phuongThucThanhToan << "|" << endl;
		    cout << "| TRANG THAI              : " << setw(45) << trangThai << "|" << endl;
		    cout << "+------------------------------------------------------------------------+\n";
			cout << "+-----+------------+----------------+-----------+----------+-------------+\n";
	    	cout << "| STT | MA DO UONG | TEN DO UONG    | GIA       | SO LUONG | THANH TIEN  |\n";
	    	cout << "+-----+------------+----------------+-----------+----------+-------------+\n";
	
		    int stt = 1;
		    for (ChiTietHoaDon chiTietHoaDon : danhSachDoUong) {
		        DoUong doUong = chiTietHoaDon.getDoUong();
		        cout << "| " << setw(4) << stt++;
		        cout << "| " << setw(11) << doUong.getMaDoUong();
		        cout << "| " << setw(15) << doUong.getTenDoUong();
		        cout << "| " << setw(10) << doUong.getGia();
		        cout << "| " << setw(9) << chiTietHoaDon.getSoLuong();
		        cout << "| " << setw(12) << chiTietHoaDon.getThanhTien();
		        cout << "|\n";
		    }
		
		    cout << "+-----+------------+----------------+-----------+----------+-------------+\n";
		    cout << right << setw(50) << "TONG TIEN: " << getTongTien() << endl;
		    cout << "+========================================================================+\n";
		}
	};
	
class DanhSachHoaDon {
	private:
		vector<HoaDon> danhSachHoaDon;
	public:
		void themHoaDon(string maHD, NhanVien nv, DanhSachDoUong dsDoUong) {
		    HoaDon hoaDon;
		    hoaDon.setMaHoaDon(maHD);
		    hoaDon.setNgayLap(getCurrentDate());
		    hoaDon.setNhanVien(nv);
		    int luaChon;
		    do {
		    	cout << left << fixed << setprecision(0);
				cout << "+================================ HOA DON ===============================+\n";
				cout << "| MA HOA DON              : " << setw(45) << hoaDon.getMaHoaDon() << "|" << endl;
			    cout << "| NGAY TAO                : " << setw(45) << hoaDon.getNgayLap() << "|" << endl;
			    cout << "| NHAN VIEN               : " << setw(45) << hoaDon.getNhanVien().getTenNV() << "|" << endl;
			    cout << "| PHUONG THUOC THANH TOAN : " << setw(45) << hoaDon.getPhuongThucThanhToan() << "|" << endl;
			    cout << "| TRANG THAI              : " << setw(45) << hoaDon.getTrangThai() << "|" << endl;
			    cout << "+------------------------------------------------------------------------+\n";
				cout << "+-----+------------+----------------+-----------+----------+-------------+\n";
		    	cout << "| STT | MA DO UONG | TEN DO UONG    | GIA       | SO LUONG | THANH TIEN  |\n";
		    	cout << "+-----+------------+----------------+-----------+----------+-------------+\n";
		
			    int stt = 1;
			    for (ChiTietHoaDon chiTietHoaDon : hoaDon.getDanhSachDoUong()) {
			        DoUong doUong = chiTietHoaDon.getDoUong();
			        cout << "| " << setw(4) << stt++;
			        cout << "| " << setw(11) << doUong.getMaDoUong();
			        cout << "| " << setw(15) << doUong.getTenDoUong();
			        cout << "| " << setw(10) << doUong.getGia();
			        cout << "| " << setw(9) << chiTietHoaDon.getSoLuong();
			        cout << "| " << setw(12) << chiTietHoaDon.getThanhTien();
			        cout << "|\n";
			    }
			
			    cout << "+-----+------------+----------------+-----------+----------+-------------+\n";
			    cout << right << setw(50) << "TONG TIEN: " << hoaDon.getTongTien() << endl;
			    cout << "+========================================================================+\n";
			    cout << "| CHON CHUC NANG                                                         |\n";
			    cout << "| 1. Them do uong                                                        |\n";
			    cout << "| 2. Thanh toan                                                          |\n";
			    cout << "| 0. Huy                                                                 |\n";
				cout << "+------------------------------------------------------------------------+\n";	
			    cout << "Nhap lua chon: ";
			    cin >> luaChon;
			    
			    switch (luaChon) {
					case 1: {
						int sttDoUong, soLuong;
						dsDoUong.hienThi();
						cout << "Nhap lua chon: ";
						cin >> sttDoUong;
						DoUong d = dsDoUong.getDoUong(sttDoUong - 1);
						cout << "Nhap so luong: ";
						cin >> soLuong;
						ChiTietHoaDon c(d, soLuong);
						hoaDon.themDoUong(c);
						break;
					}
					case 2: {
		                cout << "Chon phuong thuc thanh toan\n";
		                cout << "1: Tien mat\n";
		                cout << "2: Chuyen khoan\n";
		                int pay;
		                cin >> pay;
		                if (pay == 1) {
		                	hoaDon.setPhuongThucThanhToan("Tien mat");
						} else {
		                	hoaDon.setPhuongThucThanhToan("Chuyen khoan");
						}
						
		                cout << "Xac nhan thanh toan\n";
		                cout << "1: Xac nhan\n";
		                cout << "0: Huy\n";
		                int confirm;
		                cin >> confirm;
		                if (confirm == 1) {
		                	hoaDon.setTrangThai("Da thanh toan");
		                	danhSachHoaDon.push_back(hoaDon);
		                	return;
						} else {
							hoaDon.setTrangThai("Chua thanh toan");
						}
		            }
				}
			} while (luaChon != 0);
			
			
		}
		
		void hienThi() {
			cout << "+=================================================================+\n";
		    cout << "| STT | MA HOA DON | NGAY LAP  | NHAN VIEN       | TONG TIEN      |\n";
		    cout << "+-----+------------+-----------+-----------------+----------------+\n";
		
		    int stt = 1;
		    for (HoaDon hoaDon : danhSachHoaDon) {
		    	cout << left << fixed << setprecision(0);
		        cout << "| " << setw(4) << stt++
		             << "| " << setw(11) << hoaDon.getMaHoaDon()
		             << "| " << setw(10) << hoaDon.getNgayLap()
		             << "| " << setw(16) << hoaDon.getNhanVien().getTenNV()
		             << "| " << setw(14) << hoaDon.getTongTien() 
		             << " |\n";
		    }
		
		    cout << "+-----+------------+-----------+-----------------+----------------+\n";
		}

		string taoMaHoaDon() {
			return "HD" + to_string(danhSachHoaDon.size());
		}
		
		void xemChiTietHoaDon(int stt) {
			danhSachHoaDon[stt].hienThi();
		}

	};

class UngDung {
	private:
	    DanhSachDoUong dsDoUong;
		DanhSachNhanVien dsNhanVien;
		NhanVien nhanVien = NhanVien("NV01", "Nguyen Van A", "Pha che", 5000000);
		DanhSachHoaDon dsHoaDon;
	
	public:
		UngDung() {
			dsDoUong.themDoUongMacDinh();
			dsNhanVien.themNhanVienMacDinh();
		}
		
		void hienThiMenu() {
		    cout << "+--------------------------- HE THONG ----------------------------+\n";
		    cout << "|                        QUAN LY QUAN CAFE                        |\n";
		    cout << "+=================================================================+\n";
		    cout << "| 1. Them hoa don ban hang                                        |\n";
		    cout << "| 2. Them do uong                                                 |\n";
		    cout << "| 3. Xuat danh sach do uong                                       |\n";
		    cout << "| 4. Sap xep theo gia                                             |\n";
		    cout << "| 5. Tim do uong gia cao nhat                                     |\n";
		    cout << "| 6. Tim do uong gia thap nhat                                    |\n";
		    cout << "| 7. Tim kiem theo ma                                             |\n";
		    cout << "| 8. Xoa do uong theo ma                                          |\n";
		    cout << "| 9. Them do uong moi                                             |\n";
		    cout << "| 10. Hien thi hoa don ban                                        |\n";
		    cout << "| 11. Them nhan vien                                              |\n";
		    cout << "| 12. Xem danh sach nhan vien                                     |\n";
		    cout << "| 13. Xem danh sach hoa don                                       |\n";
		    cout << "| 14. Xem chi tiet hoa don                                        |\n";
		    cout << "| 15. Thoat ung dung                                              |\n";
		    cout << "+-----------------------------------------------------------------+\n";
		}
	
	    void chayUngDung() {
	        int luaChon;
	        do {
	            hienThiMenu();
	            cout << "Chon chuc nang: ";
	            cin >> luaChon;
	            cout << "+-----------------------------------------------------------------+\n";
	
	            switch (luaChon) {
	                case 1: {
	                	string maHoaDon = dsHoaDon.taoMaHoaDon();
	                    dsHoaDon.themHoaDon(maHoaDon, nhanVien, dsDoUong);
	                    break;
	                }
	                case 2: {
	                	cout << "THEM DO UONG" << endl;
	                    dsDoUong.themDoUong();
	                    break;
	                }
	                case 3: {
	                    cout << "DANH SACH DO UONG" << endl;
	                    dsDoUong.hienThi();
	                    break;
	                }
	                case 4: {
	                    cout << "SAP XEP DO UONG THEO GIA" << endl;
	                    dsDoUong.sapXepDanhSach();
	                    dsDoUong.hienThi();
	                    break;
	                }
	                case 5: {
	                    DoUong max = dsDoUong.timMax();
	                    cout << "DO UONG CO GIA CAO NHAT" << endl;
	                    cout << "+---------------+--------------------+-----------+----------------+" << endl;
					    cout << "| MA DO UONG    | TEN DO UONG        | GIA       | LOAI           |" << endl;
					    cout << "+---------------+--------------------+-----------+----------------+" << endl;
			            cout << max;
			    		cout << "+---------------+--------------------+-----------+----------------+" << endl;
	                    break;
	                }
	                case 6: {
	                    DoUong min = dsDoUong.timMin();
	                    cout << "DO UONG CO GIA THAP NHAT"<< endl;
	                    cout << "+---------------+--------------------+-----------+----------------+" << endl;
					    cout << "| MA DO UONG    | TEN DO UONG        | GIA       | LOAI           |" << endl;
					    cout << "+---------------+--------------------+-----------+----------------+" << endl;
			            cout << min;
			    		cout << "+---------------+--------------------+-----------+----------------+" << endl;
	                    break;
	                }
	                case 7: {
	                    string ma;
	                    cout << "Nhap ma do uong can tim: ";
	                    cin >> ma;
	                    dsDoUong.timKiemTheoMa(ma);
	                    
	                    break;
	                }
	                case 8: {
	                    string ma;
	                    cout << "Nhap ma do uong can xoa: ";
	                    cin >> ma;
	                    dsDoUong.xoaTheoMa(ma);
	                    break;
	                }
	                case 9: {
	                    cout << "Nhap thong tin do uong can them:\n";
	                    dsDoUong.themDoUong();
	                    break;
	                }
	                case 11: {
	                    cout << "THEM NHAN VIEN.\n";
	                    dsNhanVien.themNhanVien();
	                    break;
	                }
	                case 12: {
	                    cout << "DANH SACH NHAN VIEN.\n";
	                    dsNhanVien.hienThi();
	                    break;
	                }
	                case 13: {
	                    cout << "DANH SACH HOA DON.\n";
	                    dsHoaDon.hienThi();
	                    break;
	                }
	                case 14: {
	                	dsHoaDon.hienThi();
	                    cout << "Chon hoa don: ";
	                    int stt;
	                    cin >> stt;
	                    dsHoaDon.xemChiTietHoaDon(stt - 1);
	                    break;
	                }
					case 15: {
	                    cout << "Thoat khoi ung dung.\n";
	                    break;
	                }
	                default:
	                    cout << "Lua chon khong hop le! Vui long chon lai.\n";
	            }
	
	        } while (luaChon != 15);
	    }
	};


int main() {
    UngDung ungDung;
    ungDung.chayUngDung();
    return 0;
}
