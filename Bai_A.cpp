#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, int> mp;
string chuanhoa(string s){
    string res = "", tmp = "";
    stringstream ss(s);
    while(ss >> tmp){
        res += toupper(tmp[0]);
        for(int i = 1; i < tmp.size(); i++){
            res += tolower(tmp[i]);
        }
        res += ' ';
    }
    return res;
}
int chuyenchuoi(string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res*10 + (s[i] - '0');
    }
    return res;
}
bool check(string s){
    if(s[1] == '/'){
        s = "0" + s;
    }
    if(s[4] == '/'){
        s.insert(3, "0");
    }
    if(s[2] != '/' || s[5] != '/') return false;
    for(int i = 0; i < s.size(); i++){
        if(i != 2 && i != 5){
            if(!isdigit(s[i])) return false;
        }
    }
    if(s[s.size() - 1] == '/') return false;
    int ngay = chuyenchuoi(s.substr(0, 2)), thang = chuyenchuoi(s.substr(3, 2)), nam = chuyenchuoi(s.substr(6));
    if(nam < 0){
        return false;
    } else{
        if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
            if(ngay < 1 || ngay > 31){
                return false;
            }
        } else if(thang == 4 || thang == 6 || thang == 9 || thang == 11){
            if(ngay < 1 || ngay > 30){
                return false;
            }
        } else if(thang == 2){
            if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)){
                if(ngay < 1 || ngay > 29){
                    return false;
                }
            } else {
                if(ngay < 1 || ngay > 28){
                    return false;
                }
            }
        } else return false;
    }
    return true;
}
bool check_choose(string s){
    for(int i = 0; i < s.size(); i++){
        if(!isdigit(s[i])) return false;
    }
    return true;
}
bool check_gia(string s){
    int x = -1;
    if(!isdigit(s[0])) return false;
    if(s[s.size() - 1] == '.') return false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            x = i;
            break;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(i != x){
            if(!isdigit(s[i])) return false;
        }
    }
    return true;
}
class sach{
    protected:
        string ten_sach, ngay_xuat_ban, nha_xuat_ban, ma_sach, ten_tac_gia, the_loai, dt;
        double gia_tien;
    public:
        sach(){
            ten_sach = ngay_xuat_ban = nha_xuat_ban = ma_sach = ten_tac_gia = dt = the_loai = "";
            gia_tien = 0;
        }
        sach(string name, string date, string nxb, string ms, string tg, string oj, double gt, string tl){
            ten_sach = name;
            ngay_xuat_ban = date;
            nha_xuat_ban = nxb;     
            ma_sach = ms;
            ten_tac_gia = tg;
            dt = oj;
            gia_tien = gt;
            the_loai = tl;
        }
        friend istream&operator>>(istream&, sach&);
        friend ostream&operator<<(ostream&,const sach&);
        friend bool operator<(sach, sach);
        string get_doituong(){
            return dt;
        }
        string get_tentacgia(){
            return ten_tac_gia;
        }
        string get_tensach(){
            return ten_sach;
        }
        string get_theloai(){
            return the_loai;
        }
};
istream&operator>>(istream &in, sach &x){
    cout << "Nhap ten sach: ";
    getline(in, x.ten_sach);
    cout << "Nhap ma sach: ";
    in >> x.ma_sach;
    cout << "Nhap ten tac gia: ";
    in.ignore();
    getline(in, x.ten_tac_gia);
    cout << "Nhap the loai: ";
    getline(cin, x.the_loai);
    mp[chuanhoa(x.the_loai)]++;
    cout << "Nhap ngay xuat ban(dang x/y/zzzz): ";
    do{
        in >> x.ngay_xuat_ban;
        if(!check(x.ngay_xuat_ban)){
            cout << "Nhap sai ngay xuat ban!\n";
            cout << "Nhap lai: ";
        }
    } while(!check(x.ngay_xuat_ban));
    cout << "Nhap nha xuat ban: ";
    in.ignore();
    getline(in, x.nha_xuat_ban);
    cout << "Nhap gia tien: ";
    string tmp;
    do{
        in >> tmp;
        if(!check_gia(tmp)){
            cout << "Gia tien ban nhap khong hop le!\n";
            cout << "Nhap lai: ";
        }
    } while(!check_gia(tmp));
    x.gia_tien = stoi(tmp);
    in.ignore();
    cout << "Danh cho doi tuong(tre em/ nguoi lon/ tat ca): ";
    do{
        getline(in, x.dt);
        if(chuanhoa(x.dt) != "Tre Em " && chuanhoa(x.dt) != "Nguoi Lon " && chuanhoa(x.dt) != "Tat Ca "){
            cout << "Nhap lai: ";
        }
    } while(chuanhoa(x.dt) != "Tre Em " && chuanhoa(x.dt) != "Nguoi Lon " && chuanhoa(x.dt) != "Tat Ca ");
    if(x.ngay_xuat_ban[1] == '/'){
        x.ngay_xuat_ban = "0" + x.ngay_xuat_ban;
    }
    if(x.ngay_xuat_ban[4] == '/'){
        x.ngay_xuat_ban.insert(3, "0");
    }
    return in;
}
ostream&operator<<(ostream& out, const sach &x){
    out << chuanhoa(x.ten_sach) << right << setw(10) << x.ma_sach << right << setw(10) << chuanhoa(x.ten_tac_gia) << right << setw(10) << chuanhoa(x.the_loai) << right << setw(20) << x.ngay_xuat_ban <<  right << setw(20) << chuanhoa(x.nha_xuat_ban) << right << setw(20) << x.gia_tien << right << setw(20) << chuanhoa(x.dt) << endl;
    return out;
}
bool operator<(sach a, sach b) {
    return a.gia_tien < b.gia_tien;
}
class danh_sach{
    private: 
        list<sach> l;
    public:
        friend istream &operator>>(istream &, danh_sach&);
        friend ostream &operator<<(ostream&, const danh_sach&);
        void search();
        void sapxep();
        void xoa();
        void newlist();
};
istream &operator>>(istream &in, danh_sach&x){
    while(1){
        cout << "\n";
        cout << "==================== Nhap thong tin ====================\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Nhap thong tin san pham!                          |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            in >> tmp;
            if(!check_choose(tmp)){
                cout << "Nhap lai lua chon: ";
            }
        } while(!check_choose(tmp));
        choose = chuyenchuoi(tmp);
        if(choose == 0){
            break;
        } else if(choose == 1){
            cout << "\nNhap thong tin cua sach!\n";
            sach a;
            in.ignore();
            in >> a;
            x.l.push_front(a);
        }
    }
    return in;
}
ostream &operator<<(ostream&out, const danh_sach&x){
    if(x.l.size() == 0){
        cout << "Thu vien trong!!\n";
    } else{
        while(1){
        out << "\n";
        out << "==================== Thong tin sach ====================\n";
        out << "| 0. Thoat!                                            |\n";
        out << "| 1. Tat ca cac loai sach!                             |\n";
        out << "| 2. Sach cho tre em!                                  |\n";
        out << "| 3. Sach cho nguoi lon!                               |\n";
        out << "========================================================\n";
        int choose = 0;
        string tmp;
        out << "Nhap lua chon: ";
        do{
            cin >> tmp;
            if(!check_choose(tmp)){
                out << "Nhap lai lua chon: ";
            }
        } while(!check_choose(tmp));
        choose = chuyenchuoi(tmp);
        if(choose == 0){
            break;
        } else if(choose == 1){
            for(sach t : x.l){
                out << t;
            }
        } else if(choose == 2){
            int cnt = 0;
            for(sach t : x.l){
                if(chuanhoa(t.get_doituong()) == "Tre Em "){
                    cnt++;
                    out << t;
                }
            }
            if(cnt == 0) cout << "Khong co sach danh cho tre em!\n";
        } else if(choose == 3){
            int cnt = 0;
            for(sach t : x.l){
                if(chuanhoa(t.get_doituong()) == "Nguoi Lon "){
                    cnt++;
                    out << t;
                }
            }
            if(cnt == 0) cout << "Khong co sach danh cho nguoi lon!\n";
        } else{
            out << "Nhap lai lua chon: ";
        }
    }
    }
    return out;
}
void danh_sach::search(){
    if(l.size() == 0){
        cout << "Thu vien trong!!\n";
    } else{
        while(1){
        cout << "\n";
        cout << "=============== Tim kiem thong tin theo: ===============\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Ten tac gia!                                      |\n";
        cout << "| 2. Ten sach!                                         |\n";
        cout << "| 3. The loai!                                         |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            cin >> tmp;
            if(!check_choose(tmp)){
                cout << "Nhap lai lua chon: ";
            }
        } while(!check_choose(tmp));
        choose = chuyenchuoi(tmp);
        if(choose == 0){
            break;
        } else if(choose == 1){
            string name;
            int cnt = 0;
            cout << "Nhap ten tac gia: ";
            cin.ignore();
            getline(cin, name);
            for(sach t : l){
                if(chuanhoa(t.get_tentacgia()) == chuanhoa(name)){
                    cnt ++;
                    cout << t;
                }
            }
            if(cnt == 0){
                cout << "Tac gia nay hien chua co cuon sach nao!\n";
            }
        } else if(choose == 2){
            string name;
            int cnt = 0;
            cout << "Nhap ten sach: ";
            cin.ignore();
            getline(cin, name);
            for(sach t : l){
                if(chuanhoa(t.get_tensach()) == chuanhoa(name)){
                    cnt ++;
                    cout << t;
                }
            }
            if(cnt == 0){
                cout << "Khong co cuon sach nay!\n";
            }
        } else if(choose == 3){
            while(1){
                int cnt = 0;
                cout << "\n";
                cout << "============= The loai gom: ============\n";
                cout << "0. Thoat\n";
                for(auto t : mp){
                    cnt++;
                    cout << cnt << ". " << t.first << endl; 
                }
                cout << "========================================\n\n";
                map<int, string> tl;
                int k = 1;
                for(auto i : mp){
                    tl[k] = i.first;
                    k++;
                }
                string lc;
                cout << "Nhap lua chon: ";
                do{
                    cin >> lc;
                    if(!check_choose(lc)){
                        cout << "Nhap lai lua chon: ";
                    }
                } while(!check_choose(lc));
                int luachon = chuyenchuoi(lc);
                if(luachon == 0){
                    break;
                } else if(tl.count(luachon) != 0){
                    for(auto t : l){
                        if(chuanhoa(t.get_theloai()) == chuanhoa(tl[luachon])){
                            cout << t;
                        }
                    }
                } else{
                    cout << "Nhap lai lua chon: ";
                }
            }
        } else {
            cout << "Nhap lai lua chon: ";
        }
    }
    }
} 
void danh_sach::sapxep(){
    if(l.size() == 0){
        cout << "Thu vien trong!!\n";
    } else {
        while(1){
        cout << "\n";
        cout << "=========== Sap xep danh sach theo gia tien! ===========\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Tang dan!                                         |\n";
        cout << "| 2. Giam dan!                                         |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            cin >> tmp;
            if(!check_choose(tmp)){
                cout << "Nhap lai lua chon: ";
            }
        } while(!check_choose(tmp));
        choose = chuyenchuoi(tmp);
        if(choose == 0){
            break;
        } else if(choose == 1){
            l.sort();
            for(sach t : l){
                cout << t;
            }
        } else if(choose == 2){
            l.sort();
            l.reverse();
            for(sach t : l){
                cout << t;
            }
        } else{
            cout << "Nhap lai lua chon: ";
        }
    }
    }
}
void danh_sach::xoa(){
    if(l.size() == 0){
        cout << "Thu vien trong!!\n";
    } else {
        while(1){
        cout << "\n";
        cout << "================ Thong tin sach can xoa ================\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Nhap ten sach can xoa!                            |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            cin >> tmp;
            if(!check_choose(tmp)){
                cout << "Nhap lai lua chon: ";
            }
        } while(!check_choose(tmp));
        choose = chuyenchuoi(tmp);
        if(choose == 0){
            break;
        } else if(choose == 1){
            string tmp1;
            cout << "Ten sach can xoa: ";
            cin.ignore();
            getline(cin, tmp1);
            int cnt = 0;
            for (auto it = l.begin(); it != l.end(); ) {
                if (chuanhoa(it->get_tensach()) == chuanhoa(tmp1)) {
                    cnt++;
                    it = l.erase(it); 
                } else {
                    ++it;
                }
            }
            if(cnt == 0){
                cout << "Khong thay sach nay!\n";
            } else cout << "Da xoa sach " << tmp1 << "!\n";
        } else{
            cout << "Nhap lai lua chon: ";
        }
    }
    }
}
void danh_sach::newlist(){
    l.clear();
    cout << "Da tao danh sach moi!\n";
}
class app{
    private:
        danh_sach temp;
    public:
        void khoi_dong_app();
};
void app::khoi_dong_app(){
    while(1){
        system("cls");
        cout << "\n";
        cout << "============================================== MENU ==============================================\n";
        cout << "| 0.Thoat!                                                                                       |\n";
        cout << "| 1. Tao kho sach moi!                                                                           |\n";
        cout << "| 2. Them san pham!                                                                              |\n";
        cout << "| 3. Tim kiem san pham!                                                                          |\n";
        cout << "| 4. Xoa san pham!                                                                               |\n";
        cout << "| 5. Sap xep danh san pham!                                                                      |\n";
        cout << "| 6. In danh sach san pham hien co!                                                              |\n";
        cout << "==================================================================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            cin >> tmp;
            if(!check_choose(tmp)){
                cout << "Nhap lai lua chon: ";
            }
        } while(!check_choose(tmp));
        choose = chuyenchuoi(tmp);
        if(choose == 0){
            break;
        } else if(choose == 1){
            temp.newlist();
            system("pause");
        } else if(choose == 2){
            cin >> temp;
            system("pause");
        } else if(choose == 3){
            temp.search();
            system("pause");
        } else if(choose == 4){
            temp.xoa();
            system("pause");
        } else if(choose == 5){
            temp.sapxep();
            system("pause");
        } else if(choose == 6){
            cout << temp;
            system("pause");
        } else{
            cout << "Nhap lai lua chon: ";
            system("pause");
        }
    }
}
int main(){
    app a;
    a.khoi_dong_app();
}
