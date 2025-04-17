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

void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

class Person {
protected:
    string name, phone, gender, dob;
public:
	Person() {}
    Person(string n, string p, string g, string d)  {
		name = n;
		phone = p;
		gender = g;
		dob = d;
	}
	void input() {
		do {
			cout << "Nhap ho va ten : "; 
			cin >> ws;
			getline(cin, name);
			if (name.length() > 22) {
				cout << "Khong duoc qua 22 ky tu, hay nhap lai."
				<< endl;
			}
		} while (name.length() > 22);
		//Nhập điện thoại và kiểm tra độ dài không quá 11 ký tự
		do {
			cout << "Nhap so dien thoai: "; 
			cin >> phone;
			if (phone.length() > 11) {
				cout << "Khong duoc qua 11 ky tu, hay nhap lai." << endl;
			}
		} while (phone.length() > 11);
		
		cout << "Nhap gioi tinh : "; 
		cin >> ws;
		getline(cin, gender);
		
		cout << "Nhap ngay sinh : "; 
		cin >> ws;
		getline(cin, dob);

	}
	
	string getName() {
		return name;
	}
	
	string getPhone() {
		return phone;
	}
	
	string getGender() {
		return gender;
	}
	
	string getDob() {
		return dob;
	}
	
    void display() {
		cout << "Name: " << name << ", Phone: " << phone << endl;
	}
};

class Customer : public Person {
private:
    string address;
public:
	Customer() {}
    Customer(string n, string p, string g, string d, string addr) : Person(n, p, g, d) {
		address = addr;
	}
	void input() {
		Person::input();
		cout << "Nhap dia chi: ";
		cin >> address;
	}
    void display() {
    	cout << left << fixed << setprecision(2);
    	cout << "| " << setw(14) << getName();
    	cout << "| " << setw(14) << getPhone();
    	cout << "| " << setw(10) << getGender();
    	cout << "| " << setw(14) << address;
    	cout << "| " << setw(11) << getDob();
    	cout << "|" << endl;
	}
    void viewHistory() {
        cout << "Viewing purchase history for " << name << endl;
    }
};

class Pharmacist : public Person {
private:
	string username, password;
    int salary;
public:
	Pharmacist() {}
    Pharmacist(string u, string pw, string n, string p, string g, string d, int s) : Person(n, p, g, d) {
    	username = u;
    	password = pw;
		salary = s;
	}
	void input() {
	    Person::input();
	    cout << "Nhap ten nguoi dung: ";
	    cin >> username;
	    cout << "Nhap mat khau: ";
	    cin >> password;
	    cout << "Nhap luong: ";
	    cin >> salary;
	}
	
	int getSalary() {return salary; }
	
	string getUsername() { return username; }
	
	string getPassword() { return password; }
};

class Medicine {
protected:
    string id, name, manufacturer;
    int price;
public:
	Medicine() {}
    Medicine(string i, string n, int p, string m) {
    	id = i;
		name = n;
		price = p;
		manufacturer = m;
	}
	void input() {
		cout << "Nhap ma thuoc: ";
		cin >> id;
		cout << "Nhap ten thuoc: ";
		getline(cin, name);
		cout << "Nhap gia thuoc: ";
		cin >> price;
		cout << "Nhap nha san xuat: ";
		cin >> manufacturer;
	}
	string getId() const {
	    return id;
	}
	string getName() const {
	    return name;
	}
	string getManufacturer() const {
	    return manufacturer;
	}
    int getPrice() { 
		return price; 
	}
	
	void setName(string n) { name = n; }
	void setPrice(int p) { price = p; }
	void setManufacturer(string m) { manufacturer = m; }
	
	void display() {
		cout << "| " << setw(11) << left << id;
		cout << "| " << setw(23) << left << name;
		cout << "| " << setw(10) << left << price;
		cout << "| " << setw(19) << left << manufacturer;
		cout << "|" << endl;
	}
};

class OTCMedicine : public Medicine {
private:
    string note;
public:
    OTCMedicine(string i, string n, int p, string m, string note) : Medicine(i, n, p, m) {
		note = note;
	}
};

class PrescriptionMedicine : public Medicine {
private:
    string note;
public:
    PrescriptionMedicine(string i, string n, int p, string m, string note) : Medicine(i, n, p, m) {
		note = note;
	}
};

class InvoiceItem {
private:
    Medicine medicine;
    int quantity;
    double price;
public:
    InvoiceItem(Medicine med, int qty) {
		medicine = med;
		quantity = qty;
		price = medicine.getPrice();
	}
	Medicine getMedicine() {
		return medicine;
	}
	int getQuantity() {
		return quantity;
	}
    double getTotal() { 
		return quantity * price; 
	}
};

class Invoice {
private:
	int id;
    Customer customer;
    Pharmacist pharmacist;
    vector<InvoiceItem> invoiceItems;
    string date, paymentMethod, status;
public:
	Invoice() {}
    Invoice(Customer c, Pharmacist p, string d, string pay, string st) {
		customer = c; 
		pharmacist = p; 
		date = d; 
		paymentMethod = pay; 
		status = st;
	}
	
	void addInvoice(
		Pharmacist pharmacist,
		Customer listCustomers[],
		int countCustomer,
		Medicine listMedicines[],
		int countMedicine
	);
	
	void setCustomer(Customer c) {
		customer = c;
	}
	
	void setPharmacist(Pharmacist p) {
        pharmacist = p;
    }
    
    void setDate(string d) {
        date = d;
    }

    void addItem(InvoiceItem newItem) {
        invoiceItems.push_back(newItem);
    }
    
    int getId() {
    	return id;
	}
    
    Customer getCustomer() {
        return customer;
    }

    Pharmacist getPharmacist() {
        return pharmacist;
    }

    string getDate() {
        return date;
    }

    string getPaymentMethod() {
        return paymentMethod;
    }

    string getStatus() {
        return status;
    }

    vector<InvoiceItem> getInvoiceItems() {
        return invoiceItems;
    }

    double getTotalPrice() {
        double total = 0;
        for (InvoiceItem item : invoiceItems) {
        	total += item.getTotal();
		}
        return total;
    }
    
    
    void display() {
	    cout << "====================== INVOICE ======================" << endl;
	    cout << "Date: " << date << endl;
	    cout << "Customer: " << customer.getName() << endl;
	    cout << "Pharmacist: " << pharmacist.getName() << endl;
	    cout << "-----------------------------------------------------" << endl;
	    cout << left << setw(5) << "No."
	         << setw(20) << "Medicine"
	         << setw(10) << "Qty"
	         << setw(15) << "Unit Price"
	         << setw(15) << "Total" << endl;

	    cout << "+------------+------------------------+-----------+--------------------+\n";
	    cout << "| MA THUOC   | TEN THUOC              | GIA       | NHA SAN XUAT       |\n";
	    cout << "+------------+------------------------+-----------+--------------------+\n";

	    int index = 1;
	    for (InvoiceItem item : invoiceItems) {
	        Medicine med = item.getMedicine();
	        cout << setw(5) << index++
	             << setw(20) << med.getName()
	             << setw(10) << item.getQuantity()
	             << setw(15) << fixed << setprecision(2) << med.getPrice()
	             << setw(15) << fixed << setprecision(2) << item.getTotal()
	             << endl;
	    }
	
	    cout << "---------------------------------------------------------------------" << endl;
	    cout << right << setw(50) << "TOTAL: " << fixed << setprecision(2) << getTotalPrice() << endl;
	    cout << "=================================================" << endl;
	}
};

void showMenu() {
//    system("cls");
    cout << "+------------ HE THONG ------------+\n";
    cout << "|     QUAN LY QUAY THUOC           |\n";
    cout << "+----------------------------------+\n";
    cout << "| 1. Them hoa don ban thuoc        |\n";
    cout << "| 2. Hien thi hoa don              |\n";
    cout << "| 3. Tim kiem thuoc theo ten       |\n";
    cout << "| 4. Them thuoc moi                |\n";
    cout << "| 5. Hien thi tat ca thuoc         |\n";
    cout << "| 6. Sua thong tin thuoc           |\n";
    cout << "| 7. Xoa thuoc                     |\n";
	cout << "| 8. Them khach hang               |\n";
	cout << "| 9. Xem ds khach hang             |\n";
	cout << "| 10. Them duoc si                 |\n";
	cout << "| 11. Xem ds duoc si               |\n";
    cout << "| 12. Thoat chuong trinh           |\n";
    cout << "+----------------------------------+\n";
    cout << "Chon chuc nang: ";
}


void addMedicine(Medicine listMedicines[], int& count, int max_size) {
	if (count >= max_size) {
		cout << "Qua so luong thuoc cho phep" << endl;
		return;
	}	
	Medicine newMedicine;
	newMedicine.input();
	listMedicines[count] = newMedicine;
	count++;
}

void addCustomer(Customer listCustomers[], int& count, int max_size) {
	if (count >= max_size) {
		cout << "Qua so luong khach hang cho phep" << endl;
		return;
	}	
	Customer newCustomer;
	newCustomer.input();
	listCustomers[count] = newCustomer;
	count++;
}

void displayCustomers(Customer listCustomers[], int& count) {
	cout << "+-----+---------------+---------------+-----------+---------------+------------+" << endl;
	cout << "| STT | HO VA TEN     | SO DIEN THOAI | GIOI TINH | DIA CHI       | NGAY SINH  |" << endl;
	cout << "+-----+---------------+---------------+-----------+---------------+------------+" << endl;
	for (int i = 0; i < count; i++) {
		cout << "| " << left<< setw(4) << i + 1;
		listCustomers[i].display();
	}
	cout << "+-----+---------------+---------------+-----------+---------------+------------+" << endl;
}

void displayMedicines(Medicine listMedicines[], int count) {
    if (count == 0) {
        cout << "Chua co thuoc nao trong danh sach.\n";
        return;
    }

    cout << "+-----+------------+------------------------+-----------+--------------------+\n";
    cout << "| STT | MA THUOC   | TEN THUOC              | GIA       | NHA SAN XUAT       |\n";
    cout << "+-----+------------+------------------------+-----------+--------------------+\n";

    for (int i = 0; i < count; i++) {
    	cout << "| " << left<< setw(4) << i + 1;
		listMedicines[i].display();
    }

    cout << "+-----+------------+------------------------+-----------+--------------------+\n";
}

void addPharmacist(Pharmacist listPharmacists[], int& count, int max_size) {
    if (count >= max_size) {
        cout << "Qua so luong duoc si cho phep" << endl;
        return;
    }
	Pharmacist newPharmacist;
	newPharmacist.input();
	
    listPharmacists[count] = newPharmacist;
    count++;
}

void displayPharmacists(Pharmacist listPharmacists[], int count) {
    cout << "+---------------+---------------+-----------+------------+-------------+" << endl;
    cout << "| HO VA TEN     | SO DIEN THOAI | GIOI TINH | NGAY SINH  | LUONG       |" << endl;
    cout << "+---------------+---------------+-----------+------------+-------------+" << endl;

    cout << left << fixed << setprecision(2);
    for (int i = 0; i < count; i++) {
        cout << "| " << setw(14) << listPharmacists[i].getName();
        cout << "| " << setw(14) << listPharmacists[i].getPhone();
        cout << "| " << setw(10) << listPharmacists[i].getGender();
        cout << "| " << setw(11) << listPharmacists[i].getDob();
        cout << "| " << setw(12) << listPharmacists[i].getSalary();
        cout << "|" << endl;
    }

    cout << "+---------------+---------------+-----------+------------+-------------+" << endl;
}

void addDefaultMedicines(Medicine listMedicines[], int& count) {
    string ids[10] = {"T001", "T002", "T003", "T004", "T005", "T006", "T007", "T008", "T009", "T010"};
    string names[10] = {"Paracetamol", "Amoxicillin", "Cefuroxime", "Vitamin C", "Panadol",
                        "Decolgen", "Tiffy", "Efferalgan", "Zinnat", "Coldacmin"};
    int prices[10] = {5000, 8000, 10000, 3000, 7000, 6000, 4000, 5500, 9500, 4500};
    string manufacturers[10] = {"DHG", "Stada", "Traphaco", "Sanofi", "Imexpharm",
                                "Domesco", "Pymepharco", "Mekophar", "Rohto", "GSK"};

    for (int i = 0; i < 10; i++) {
        listMedicines[count++] = Medicine(ids[i], names[i], prices[i], manufacturers[i]);
    }
}

void addDefaultCustomers(Customer listCustomers[], int& count) {
    string names[10] = {"An", "Binh", "Cuong", "Dung", "Em", "Giang", "Hoa", "Khanh", "Linh", "Minh"};
    string phones[10] = {"0911000001", "0911000002", "0911000003", "0911000004", "0911000005",
                         "0911000006", "0911000007", "0911000008", "0911000009", "0911000010"};
    string genders[10] = {"Nam", "Nam", "Nam", "Nam", "Nu", "Nu", "Nu", "Nam", "Nu", "Nam"};
    string dobs[10] = {"2000-01-01", "1999-05-02", "2001-03-03", "1998-06-04", "2002-04-05",
                       "2001-07-06", "2000-08-07", "1997-09-08", "2003-10-09", "1996-11-10"};
    string addresses[10] = {"HN", "HCM", "DN", "CT", "BD", "HP", "QN", "TN", "NT", "PT"};

    for (int i = 0; i < 10; i++) {
        listCustomers[count] = Customer(names[i], phones[i], genders[i], dobs[i], addresses[i]);
        count++;
    }
}

void addDefaultPharmacists(Pharmacist listPharmacists[], int& count) {
    string usernames[10] = {"anh", "bao", "chi", "duc", "hien", "kien", "lan", "my", "nghia", "quang"};
    string passwords[10] = {"123456", "123456", "123456", "123456", "123456", "123456", "123456", "123456", "123456", "123456"};
    string names[10] = {"Anh", "Bao", "Chi", "Duc", "Hien", "Kien", "Lan", "My", "Nghia", "Quang"};
    string phones[10] = {"0912000001", "0912000002", "0912000003", "0912000004", "0912000005",
                         "0912000006", "0912000007", "0912000008", "0912000009", "0912000010"};
    string genders[10] = {"Nam", "Nam", "Nu", "Nam", "Nu", "Nam", "Nu", "Nu", "Nam", "Nam"};
    string dobs[10] = {"1990-01-01", "1988-02-02", "1992-03-03", "1985-04-04", "1991-05-05",
                       "1989-06-06", "1993-07-07", "1990-08-08", "1987-09-09", "1994-10-10"};
    int salaries[10] = {8000000, 9000000, 8500000, 9500000, 8200000, 8700000, 8800000, 8600000, 8900000, 9100000};

    for (int i = 0; i < 10; i++) {
        listPharmacists[count] = Pharmacist(usernames[i], passwords[i], names[i], phones[i], genders[i], dobs[i], salaries[i]);
        count++;
    }
}

Pharmacist login(Pharmacist listPharmacists[], int count) {
	while (true) {
		string usernameInput, passwordInput;
	    cout << "===== DANG NHAP =====" << endl;
	    cout << "Ten dang nhap: ";
	    cin >> usernameInput;
	    cout << "Mat khau: ";
	    cin >> passwordInput;
	
	    for (int i = 0; i < count; i++) {
	        if (listPharmacists[i].getUsername() == usernameInput &&
	            listPharmacists[i].getPassword() == passwordInput) {
	            cout << "Dang nhap thanh cong! Xin chao " << listPharmacists[i].getName() << endl;
	            return listPharmacists[i];
	        }
	    }
	    cout << "Dang nhap that bai. Vui long thu lai." << endl;
	}
}

void Invoice::addInvoice(
	Pharmacist pharmacist,
	Customer listCustomers[],
	int countCustomer,
	Medicine listMedicines[],
	int countMedicine
) {
	pharmacist = pharmacist;
	date = getCurrentDate();
	
	int choice;
	
	do {
		cout << "+=============================== INVOICE ==============================+\n";
		cout << "| MA HOA DON             : " << date << endl;
	    cout << "| NGAY TAO               : " << date << endl;
	    cout << "| KHACH HANG             : " << customer.getName() << endl;
	    cout << "| DUOC SI                : " << pharmacist.getName() << endl;
	    cout << "| PHUONG THUOC THANH TOAN: " << paymentMethod << endl;
	    cout << "| TRANG THAI             : " << status << endl;
	    cout << "+----------------------------------------------------------------------+\n";
		cout << "+-----+----------+----------------+-----------+----------+-------------+\n";
    	cout << "| STT | MA THUOC | TEN THUOC      | GIA       | SO LUONG | THANH TIEN  |\n";
    	cout << "+-----+----------+----------------+-----------+----------+-------------+\n";

	    int index = 1;
	    for (InvoiceItem item : invoiceItems) {
	        Medicine med = item.getMedicine();
	        cout << "| " << setw(4) << index++;
	        cout << "| " << setw(9) << med.getId();
	        cout << "| " << setw(15) << med.getName();
	        cout << "| " << setw(10) << fixed << setprecision(2) << med.getPrice();
	        cout << "| " << setw(9) << item.getQuantity();
	        cout << "| " << setw(12) << fixed << setprecision(2) << item.getTotal();
	        cout << "|\n";
	    }
	
	    cout << "+-----+------------+----------------------+-----------+----------------+\n";
	    cout << right << setw(50) << "TOTAL: " << fixed << setprecision(2) << getTotalPrice() << endl;
	    cout << "+======================================================================+\n";
	    cout << "| CHON CHUC NANG                                                       |\n";
	    cout << "| 1. Chon khach hang                                                   |\n";
	    cout << "| 2. Them thuoc                                                        |\n";
	    cout << "| 3. Thanh toan                                                        |\n";
	    cout << "| 0. Huy                                                               |\n";
		cout << "+----------------------------------------------------------------------+\n";	
	    cout << "Nhap lua chon: ";
	    cin >> choice;
	    
	    switch (choice) {
			case 1: {
				int customerIndex;
				displayCustomers(listCustomers, countCustomer);
				cout << "Nhap lua chon: ";
				cin >> customerIndex;
				customer = listCustomers[customerIndex];
				break;
			}
			case 2: {
				int medicineIndex, quantity;
				displayMedicines(listMedicines, countMedicine);
				cout << "Nhap lua chon: ";
				cin >> medicineIndex;
				cout << "Nhap so luong: ";
				cin >> quantity;
				InvoiceItem newItem(listMedicines[medicineIndex], quantity);
				addItem(newItem);
				break;
			}
			case 3: {
                cout << "Chon phuong thuc thanh toan\n";
                cout << "1: Tien mat\n";
                cout << "2: Chuyen khoan\n";
                int pay;
                cin >> pay;
                if (pay == 1) paymentMethod = "Tien mat\n";
                else paymentMethod = "Chuyen khoan";
                cout << "Xac nhan thanh toan\n";
                cout << "1: Xac nhan\n";
                cout << "0: Huy\n";
                int confirm;
                cin >> confirm;
                if (confirm == 1) {
                	status = "Da thanh toan\n";
                	return;
				} else {
					status = "Chua thanh toan\n";
				}
            }
		}
	} while (choice != 0);
} 

void displayInvoices(Invoice listInvoices[], int count) {
    cout << "+==========================================================================+\n";
    cout << "| STT | MA HOA DON | NGAY LAP  | KHACH HANG    | DUOC SI       | TONG TIEN |\n";
    cout << "+-----+------------+-----------+---------------+---------------+-----------+\n";

    int index = 1;
    for (int i = 0; i < count; i++) {
    	cout << left << fixed << setprecision(2);
        cout << "| " << setw(4) << index++
             << "| " << setw(11) << listInvoices[i].getId()
             << "| " << setw(10) << listInvoices[i].getDate()
             << "| " << setw(14) << listInvoices[i].getCustomer().getName()
             << "| " << setw(14) << listInvoices[i].getPharmacist().getName()
             << "| " << setw(9) << fixed << setprecision(2) << listInvoices[i].getTotalPrice() 
             << " |\n";
    }

    cout << "+-----+------------+-----------+---------------+---------------+-----------+\n";
}

void searchMedicineByName(Medicine listMedicines[], int count) {
    cin.ignore();
    string keyword;
    cout << "Nhap ten thuoc can tim: ";
    getline(cin, keyword);
    toLowerCase(keyword);

    bool found = false;
    cout << "\n=== Ket qua tim kiem ===" << endl;
    cout << "+-----+------------+------------------------+-----------+--------------------+\n";
    cout << "| STT | MA THUOC   | TEN THUOC              | GIA       | NHA SAN XUAT       |\n";
    cout << "+-----+------------+------------------------+-----------+--------------------+\n";
	
    for (int i = 0; i < count; ++i) {
		cout << "| " << left<< setw(4) << i + 1;
        string medName = listMedicines[i].getName();
        string tempName = medName;
        toLowerCase(tempName);
        if (tempName.find(keyword) != string::npos) {
            listMedicines[i].display();
            found = true;
        }
    }
    cout << "+-----+------------+------------------------+-----------+--------------------+\n";

    if (!found) {
        cout << "Khong tim thay thuoc nao phu hop.\n";
    }
}

void updateMedicine(Medicine listMedicines[], int count) {
	displayMedicines(listMedicines, count);
    cin.ignore();
    string id;
    cout << "Nhap ma thuoc can cap nhat: ";
    getline(cin, id);

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (listMedicines[i].getId() == id) {
            found = true;

            cout << "\n=== Thong tin hien tai ===\n";
            cout << "+------------+------------------------+-----------+--------------------+\n";
    		cout << "| MA THUOC   | TEN THUOC              | GIA       | NHA SAN XUAT       |\n";
    		cout << "+------------+------------------------+-----------+--------------------+\n";
            listMedicines[i].display();
            cout << "+------------+------------------------+-----------+--------------------+\n";

            string newName, newManufacturer;
            int newPrice;

            cout << "\n=== Nhap thong tin moi ===\n";

            cout << "Ten moi (bo qua neu giu nguyen): ";
            getline(cin, newName);
            if (!newName.empty()) {
                listMedicines[i].setName(newName);
            }

            cout << "Gia moi (-1 de giu nguyen): ";
            cin >> newPrice;
            if (newPrice >= 0) {
                listMedicines[i].setPrice(newPrice);
            }

            cin.ignore(); // Xóa bộ đệm
            cout << "Nha san xuat moi (bo qua neu giu nguyen): ";
            getline(cin, newManufacturer);
            if (!newManufacturer.empty()) {
                listMedicines[i].setManufacturer(newManufacturer);
            }

            cout << "\nCap nhat thuoc thanh cong!\n";
            listMedicines[i].display();
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay thuoc co ma \"" << id << "\".\n";
    }
}

void deleteMedicine(Medicine listMedicines[], int& count) {
	displayMedicines(listMedicines, count);
    cin.ignore();
    string id;
    cout << "Nhap ma thuoc can xoa: ";
    getline(cin, id);

    bool found = false;

    for (int i = 0; i < count; ++i) {
        if (listMedicines[i].getId() == id) {
            found = true;
            cout << "\nThong tin thuoc se bi xoa:\n";
            cout << "+------------+------------------------+-----------+--------------------+\n";
    		cout << "| MA THUOC   | TEN THUOC              | GIA       | NHA SAN XUAT       |\n";
    		cout << "+------------+------------------------+-----------+--------------------+\n";
            listMedicines[i].display();
            cout << "+------------+------------------------+-----------+--------------------+\n";

            // Xác nhận từ người dùng
            char confirm;
            cout << "Ban co chac muon xoa thuoc nay? (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                // Dời các phần tử phía sau lên để ghi đè phần tử bị xóa
                for (int j = i; j < count - 1; ++j) {
                    listMedicines[j] = listMedicines[j + 1];
                }
                count--; // giảm số lượng thuốc
                cout << "Da xoa thuoc thanh cong.\n";
            } else {
                cout << "Huy thao tac xoa.\n";
            }

            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay thuoc co ma \"" << id << "\".\n";
    }
}


int main() {
	const int MAX_SIZE = 100;
    Customer listCustomers[MAX_SIZE];
	Pharmacist listPharmacists[MAX_SIZE];
    Medicine listMedicines[MAX_SIZE];
    Invoice listInvoices[MAX_SIZE];
    
    int countCustomer = 0, countMedicine = 0, countInvoice = 0, countPharmacist = 0;
    int choice;
    
    addDefaultCustomers(listCustomers, countCustomer);
    addDefaultMedicines(listMedicines, countMedicine);
    addDefaultPharmacists(listPharmacists, countPharmacist);
    
    
    Pharmacist currentUser = login(listPharmacists, countPharmacist);

	do {
		showMenu();
		cin >> choice;
		switch (choice) {
			case 1: {
				Invoice newInvoice;
				newInvoice.addInvoice(currentUser, listCustomers, countCustomer, listMedicines, countMedicine);
				listInvoices[countInvoice] = newInvoice;
				countInvoice ++;
				break;
			}
			case 2:
				displayInvoices(listInvoices, countInvoice);
				break;
			case 3:
				searchMedicineByName(listMedicines, countMedicine);
				break;
			case 4:
				addMedicine(listMedicines, countMedicine, MAX_SIZE);
				break;
			case 5:
				displayMedicines(listMedicines, countMedicine);
				break;
			case 6:
				updateMedicine(listMedicines, countMedicine);
				break;
			case 7:
				deleteMedicine(listMedicines, countMedicine);
				break;
			case 8:
				addCustomer(listCustomers, countCustomer, MAX_SIZE);
				break;
			case 9:
				displayCustomers(listCustomers, countCustomer);
				break;
			case 10:
				addPharmacist(listPharmacists, countPharmacist, MAX_SIZE);
				break;
			case 11:
				displayPharmacists(listPharmacists, countPharmacist);
				break;
		}
	} while (choice != 12);

    return 0;
}