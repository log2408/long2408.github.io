#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, int> mp;
map<string, int> Ten;
map<string, int> Nguoi;
string chuyen_doi(string s){
    string tmp = "";
    int i1 = 0, i2 = 0;
    for(int i = 0; i < s.size(); i++){ if(s[i] != ' '){ i1 = i; break; }}
    for(int i = s.size() - 1; i >= 0; i--){ if(s[i] != ' '){ i2 = i; break; }}
    for(int i = i1; i <= i2; i++){ tmp += s[i];}
    return tmp;
}
string chuanhoa(string s){             
    string res = "", tmp = "";     
    stringstream ss(s);        
    while(ss >> tmp){   
        res += toupper(tmp[0]); 
        for(int i = 1; i < tmp.size(); i++){ res += tolower(tmp[i]); }
        res += ' ';  
    }
    return res;    
} 
int chuyenchuoi(string s){    
    int res = 0; 
    for(int i = 0; i < s.size(); i++){ res = res*10 + (s[i] - '0'); }
    return res;         
} 
bool check(string s){        
    if(s[1] == '/'){ s = "0" + s; }   
    if(s[4] == '/'){ s.insert(3, "0"); }  
    if(s[2] != '/' || s[5] != '/') return false;  
    for(int i = 0; i < s.size(); i++){ if(i != 2 && i != 5){ if(!isdigit(s[i])) return false; } } 
    if(s[s.size() - 1] == '/') return false; 
    int ngay = chuyenchuoi(s.substr(0, 2)), thang = chuyenchuoi(s.substr(3, 2)), nam = chuyenchuoi(s.substr(6));
    if(nam < 0){ return false; } 
    else{
        if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
            if(ngay < 1 || ngay > 31){ return false; }
        } else if(thang == 4 || thang == 6 || thang == 9 || thang == 11){
            if(ngay < 1 || ngay > 30){ return false; }
        } else if(thang == 2){
            if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)){
                if(ngay < 1 || ngay > 29){ return false;}
            } else { if(ngay < 1 || ngay > 28){ return false; } }
        } else return false;
    }
    return true;  
}
bool check_choose(string s){    
    for(int i = 0; i < s.size(); i++){ if(!isdigit(s[i])) return false; }  
    return true; 
}
bool check_gia(string s){ 
    int x = -1;      
    if(!isdigit(s[0])) return false; 
    if(s[s.size() - 1] == '.') return false;
    for(int i = 0; i < s.size(); i++){ if(s[i] == '.'){ x = i; break; } } 
    for(int i = 0; i < s.size(); i++){ if(i != x){ if(!isdigit(s[i])) return false; } } 
    return true; 
}
class sach{
    private:
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
        string get_doituong(){ return dt; } 
        string get_tentacgia(){ return ten_tac_gia; } 
        string get_tensach(){ return ten_sach; }  
        string get_theloai(){ return the_loai; }   
        void set_sach(string tmp){ ten_sach = tmp; } 
        void set_tg(string tmp){ ten_tac_gia = tmp; } 
        void set_ngay(string tmp){ ngay_xuat_ban = tmp; } 
        void set_ma(string tmp){ ma_sach = tmp; }  
        void set_nxb(string tmp){ nha_xuat_ban = tmp; } 
        void set_gia(double tmp){ gia_tien = tmp; } 
        void set_dt(string tmp){ dt = tmp; } 
        void set_theloai(string tmp){ the_loai = tmp; } 
        string get_ma(){ return ma_sach; } 
        double get_gia(){ return gia_tien; } 
        string get_ngay(){ return ngay_xuat_ban; } 
        string get_nxb(){ return nha_xuat_ban; }
};
istream&operator>>(istream &in, sach &x){
    cout << "Nhap ten sach: "; 
    do{ getline(in, x.ten_sach); if(x.ten_sach.empty()){ cout << "Nhap lai: "; }
    } while(x.ten_sach.empty());
    Ten[x.ten_sach]++; 
    cout << "Nhap ma sach: "; 
    do{ getline(in, x.ma_sach); if(x.ma_sach.empty()){ cout << "Nhap lai: "; }
    } while(x.ma_sach.empty());
    cout << "Nhap ten tac gia: ";
    do{ getline(in, x.ten_tac_gia); if(x.ten_tac_gia.empty()){ cout << "Nhap lai: ";}
    } while(x.ten_tac_gia.empty());
    Nguoi[x.ten_tac_gia]++; 
    cout << "Nhap the loai: "; 
    do{ getline(in, x.the_loai); if(x.the_loai.empty()){cout << "Nhap lai: ";}
    } while(x.the_loai.empty());
    mp[chuanhoa(x.the_loai)]++; 
    cout << "Nhap ngay xuat ban(dang x/y/zzzz): "; 
    do{
        getline(in, x.ngay_xuat_ban);
        if(!check(chuyen_doi(x.ngay_xuat_ban))){
            cout << "Nhap sai ngay xuat ban!\n";
            cout << "Ngay xuat ban phai co dang x/y/zzzz!\n";
            cout << "Nhap lai: ";
        }
    } while(!check(chuyen_doi(x.ngay_xuat_ban)));  
    x.ngay_xuat_ban = chuyen_doi(x.ngay_xuat_ban);
    cout << "Nhap nha xuat ban: "; 
    do{ getline(in, x.nha_xuat_ban); if(x.nha_xuat_ban.empty()){cout << "Nhap lai: ";}
    } while(x.nha_xuat_ban.empty());
    cout << "Nhap gia tien: "; 
    string tmp; 
    do{
        getline(in, tmp);
        if(!check_gia(chuyen_doi(tmp))){
            cout << "Gia tien ban nhap khong hop le!\n";
            cout << "Nhap lai: ";
        }
    } while(!check_gia(chuyen_doi(tmp))); 
    x.gia_tien = stoi(chuyen_doi(tmp)); 
    cout << "Danh cho doi tuong(tre em/ nguoi lon/ tat ca): "; 
    do{
        getline(in, x.dt);
        if(chuanhoa(x.dt) != "Tre Em " && chuanhoa(x.dt) != "Nguoi Lon " && chuanhoa(x.dt) != "Tat Ca "){
            cout << "Phai la 1 trong 3 doi tuong!\n";
            cout << "Nhap lai: ";
        }
    } while(chuanhoa(x.dt) != "Tre Em " && chuanhoa(x.dt) != "Nguoi Lon " && chuanhoa(x.dt) != "Tat Ca "); 
    if(x.ngay_xuat_ban[1] == '/'){ x.ngay_xuat_ban = "0" + x.ngay_xuat_ban; } 
    if(x.ngay_xuat_ban[4] == '/'){ x.ngay_xuat_ban.insert(3, "0"); } 
    return in; 
}
ostream& operator<<(ostream& out, const sach& x) {
    out << "------------------------- Thong tin ------------------------" << endl;
    out << left << setw(20) << "Ten sach:" << setw(30) << chuanhoa(x.ten_sach) << endl;
    out << left << setw(20) << "Ma sach:" << setw(30) << x.ma_sach << endl;
    out << left << setw(20) << "Ten tac gia:" << setw(30) << chuanhoa(x.ten_tac_gia) << endl;
    out << left << setw(20) << "The loai:" << setw(30) << chuanhoa(x.the_loai) << endl;
    out << left << setw(20) << "Ngay xuat ban:" << setw(30) << x.ngay_xuat_ban << endl;
    out << left << setw(20) << "Nha xuat ban:" << setw(30) << chuanhoa(x.nha_xuat_ban) << endl;
    out << left << setw(20) << "Gia tien:" << setw(30) << x.gia_tien << endl;
    out << left << setw(20) << "Doi tuong:" << setw(30) << chuanhoa(x.dt) << endl;
    out << "------------------------------------------------------------" << endl;
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
        void update();
};
istream &operator>>(istream &in, danh_sach&x){
    while(1){
        cout << "\n==================== Nhap thong tin ====================\n";
        cout << "| 0. Thoat!                                             |\n";
        cout << "| 1. Nhap thong tin san pham!                           |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            getline(in, tmp);
            if(!check_choose(chuyen_doi(tmp))){ cout << "Nhap lai lua chon: "; }
        } while(!check_choose(chuyen_doi(tmp)));
        tmp = chuyen_doi(tmp);
        choose = chuyenchuoi(tmp);
        if(choose == 0){ break;}
        else if(choose == 1){
            cout << "\nNhap thong tin cua sach!\n";
            sach a;
            in >> a;
            x.l.push_front(a);
        } else cout << "Nhap lai lua chon: \n";
    }
    return in;
}
ostream &operator<<(ostream&out, const danh_sach&x){
    if(x.l.size() == 0){ cout << "Thu vien trong!!\n"; }
    else{
        while(1){
        out << "\n==================== Thong tin sach ====================\n";
        out << "| 0. Thoat!                                            |\n";
        out << "| 1. Tat ca cac loai sach!                             |\n";
        out << "| 2. Sach cho tre em!                                  |\n";
        out << "| 3. Sach cho nguoi lon!                               |\n";
        out << "========================================================\n";
        int choose = 0;
        string tmp;
        out << "Nhap lua chon: ";
        do{
            getline(cin, tmp);
            if(!check_choose(chuyen_doi(tmp))){ out << "Nhap lai lua chon: "; }
        } while(!check_choose(chuyen_doi(tmp)));
        tmp = chuyen_doi(tmp);
        choose = chuyenchuoi(tmp);
        if(choose == 0){ break; }
        else if(choose == 1){
            for(sach t : x.l){ out << t; }
        } else if(choose == 2){
            int cnt = 0;
            for(sach t : x.l){
                if(chuanhoa(t.get_doituong()) == "Tre Em " || chuanhoa(t.get_doituong()) == "Tat Ca "){
                    cnt++;
                    out << t;
                }
            }
            if(cnt == 0) cout << "Khong co sach danh cho tre em!\n";
        } else if(choose == 3){
            int cnt = 0;
            for(sach t : x.l){
                if(chuanhoa(t.get_doituong()) == "Nguoi Lon " || chuanhoa(t.get_doituong()) == "Tat Ca "){
                    cnt++;
                    out << t;
                }
            }
            if(cnt == 0) cout << "Khong co sach danh cho nguoi lon!\n";
        } else{ out << "Nhap lai lua chon: "; }
    }
    }
    return out;
}
void danh_sach::search(){
    if(l.size() == 0){ cout << "Thu vien trong!!\n"; }
    else{
        while(1){
        cout << "\n=============== Tim kiem thong tin theo: ===============\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Ten tac gia!                                      |\n";
        cout << "| 2. Ten sach!                                         |\n";
        cout << "| 3. The loai!                                         |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            getline(cin, tmp);
            if(!check_choose(chuyen_doi(tmp))){ cout << "Nhap lai lua chon: "; }
        } while(!check_choose(chuyen_doi(tmp)));
        tmp = chuyen_doi(tmp);
        choose = chuyenchuoi(tmp);
        if(choose == 0){ break; }
        else if(choose == 1){
            while(1){
                int cnt = 0;
                cout << "\n========================== Cac tac gia ==========================\n";
                cout << "0. Thoat!\n";
                for(auto i : Nguoi){
                    cnt++;
                    cout << cnt << ". " << i.first << endl;
                }
                cout << "=================================================================\n";
                map<int, string> tl;
                int k = 1;
                for(auto i : Nguoi){ tl[k] = i.first; k++; }
                string lc;
                cout << "Nhap lua chon: ";
                do{
                    getline(cin, lc);
                    if(!check_choose(chuyen_doi(lc))){ cout << "Nhap lai lua chon: "; }
                } while(!check_choose(chuyen_doi(lc)));
                lc = chuyen_doi(lc);
                int luachon = chuyenchuoi(lc);
                if(luachon == 0){ break; }
                else if(tl.count(luachon) != 0){
                    for(auto t : l){
                        if(chuanhoa(t.get_tentacgia()) == chuanhoa(tl[luachon])){ cout << t; }
                    }
                } else{ cout << "Nhap lai lua chon: "; }
            }
        } else if(choose == 2){
            while(1){
                int cnt = 0;
                cout << "\n========================== Cac sach ==========================\n";
                cout << "0. Thoat!\n";
                for(auto i : Ten){
                    cnt++;
                    cout << cnt << ". " << i.first << endl;
                }
                cout << "==============================================================\n";
                map<int, string> tl;
                int k = 1;
                for(auto i : Ten){ tl[k] = i.first; k++; }
                string lc;
                cout << "Nhap lua chon: ";
                do{
                    getline(cin, lc);
                    if(!check_choose(chuyen_doi(lc))){ cout << "Nhap lai lua chon: "; }
                } while(!check_choose(chuyen_doi(lc)));
                lc = chuyen_doi(lc);
                int luachon = chuyenchuoi(lc);
                if(luachon == 0){ break; }
                else if(tl.count(luachon) != 0){
                    for(auto t : l){
                        if(chuanhoa(t.get_tensach()) == chuanhoa(tl[luachon])){ cout << t; }
                    }
                } else{ cout << "Nhap lai lua chon: "; }
            }
        } else if(choose == 3){
            while(1){
                int cnt = 0;
                cout << "\n============= The loai gom: ============\n";
                cout << "0. Thoat\n";
                for(auto t : mp){
                    cnt++;
                    cout << cnt << ". " << t.first << endl; 
                }
                cout << "========================================\n\n";
                map<int, string> tl;
                int k = 1;
                for(auto i : mp){ tl[k] = i.first; k++; }
                string lc;
                cout << "Nhap lua chon: ";
                do{
                    getline(cin, lc);
                    if(!check_choose(chuyen_doi(lc))){ cout << "Nhap lai lua chon: "; }
                } while(!check_choose(chuyen_doi(lc)));
                lc = chuyen_doi(lc);
                int luachon = chuyenchuoi(lc);
                if(luachon == 0){ break;}
                else if(tl.count(luachon) != 0){
                    for(auto t : l){
                        if(chuanhoa(t.get_theloai()) == chuanhoa(tl[luachon])){ cout << t; }
                    }
                } else{ cout << "Nhap lai lua chon: "; }
            }
        } else { cout << "Nhap lai lua chon: "; }
    }
    }
} 
void danh_sach::sapxep(){
    if(l.size() == 0){ cout << "Thu vien trong!!\n"; }
    else {
        while(1){
        cout << "\n=========== Sap xep danh sach theo gia tien! ===========\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Tang dan!                                         |\n";
        cout << "| 2. Giam dan!                                         |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            getline(cin, tmp);
            if(!check_choose(chuyen_doi(tmp))){ cout << "Nhap lai lua chon: ";}
        } while(!check_choose(chuyen_doi(tmp)));
        tmp = chuyen_doi(tmp);
        choose = chuyenchuoi(tmp);
        if(choose == 0){ break; }
        else if(choose == 1){
            l.sort();
            for(sach t : l){ cout << t; }
        } else if(choose == 2){
            l.sort();
            l.reverse();
            for(sach t : l){ cout << t;}
        } else{ cout << "Nhap lai lua chon: "; }
    }
    }
}
void danh_sach::xoa(){
    if(l.size() == 0){ cout << "Thu vien trong!!\n"; }
    else {
        while(1){
        cout << "\n================ Thong tin sach can xoa ================\n";
        cout << "| 0. Thoat!                                            |\n";
        cout << "| 1. Chon ten sach can xoa!                            |\n";
        cout << "========================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            getline(cin, tmp);
            if(!check_choose(chuyen_doi(tmp))){ cout << "Nhap lai lua chon: "; }
        } while(!check_choose(chuyen_doi(tmp)));
        tmp = chuyen_doi(tmp);
        choose = chuyenchuoi(tmp);
        if(choose == 0){break;}
        else if(choose == 1){
            while(1){
                int cnt = 0;
                cout << "\n============= Cac loai sach gom: ============\n";
                cout << "0. Thoat\n";
                for(auto t : Ten){
                    cnt++;
                    cout << cnt << ". " << t.first << endl; 
                }
                cout << "=============================================\n\n";
                map<int, string> tl;
                int k = 1;
                for(auto i : Ten){ tl[k] = i.first; k++;}
                string lc;
                cout << "Nhap lua chon: ";
                do{
                    getline(cin, lc);
                    if(!check_choose(chuyen_doi(lc))){ cout << "Nhap lai lua chon: "; }
                } while(!check_choose(chuyen_doi(lc)));
                lc = chuyen_doi(lc);
                int luachon = chuyenchuoi(lc);
                if(luachon == 0){ break;}
                else if(tl.count(luachon) != 0){
                    for (auto it = l.begin(); it != l.end(); ) {
                        if (chuanhoa(it->get_tensach()) == chuanhoa(tl[luachon])) {
                            cnt++;
                            it = l.erase(it); 
                        } else { ++it; }
                    }
                    if(cnt == 0){ cout << "Khong thay sach nay!\n"; }
                    else {
                        cout << "Da xoa sach " << tl[luachon] << "!\n";
                        mp.clear();
                        Ten.clear();
                        Nguoi.clear();
                        for(auto j : l){
                            mp[j.get_theloai()]++;
                            Ten[j.get_tensach()]++;
                            Nguoi[j.get_tentacgia()]++;
                        }
                    }
                } else{ cout << "Nhap lai lua chon: "; }
            }
        } else{ cout << "Nhap lai lua chon: "; }
    }
    }
}
void danh_sach::newlist(){
    l.clear();
    cout << "Da tao danh sach moi!\n";
}
void danh_sach::update(){
    if(l.size() == 0){ cout << "Thu vien trong!!\n";}
    else{
        while(1){
            cout << "\n================ Thong tin sach can cap nhat ================\n";
            cout << "| 0. Thoat!                                                 |\n";
            cout << "| 1. Chon ten sach can cap nhat!                            |\n";
            cout << "=============================================================\n";
            int choose = 0;
            string tmp;
            cout << "Nhap lua chon: ";
            do{
                getline(cin, tmp);
                if(!check_choose(chuyen_doi(tmp))){ cout << "Nhap lai lua chon: "; }
            } while(!check_choose(chuyen_doi(tmp)));
            tmp = chuyen_doi(tmp);
            choose = chuyenchuoi(tmp);
            if(choose == 0){ break; }
            else if(choose == 1){
                while(1){
                    int cnt = 0;
                    cout << "\n============= Cac cuon sach gom: ============\n";
                    cout << "0. Thoat\n";
                    for(auto t : Ten){
                        cnt++;
                        cout << cnt << ". " << t.first << endl; 
                    }
                    cout << "=============================================\n\n";
                    map<int, string> tl;
                    int k = 1;
                    for(auto i : Ten){ tl[k] = i.first; k++; }
                    string lc;
                    cout << "Nhap lua chon: ";
                    do{
                        getline(cin, lc);
                        if(!check_choose(chuyen_doi(lc))){ cout << "Nhap lai lua chon: "; }
                    } while(!check_choose(chuyen_doi(lc)));
                    lc = chuyen_doi(lc);
                    int luachon = chuyenchuoi(lc);
                    if(luachon == 0){  break; }
                    else if(tl.count(luachon) != 0){
                        string tmpsach = tl[luachon];
                        sach tmptp;
                        for(sach i1 : l){
                            if(chuanhoa(i1.get_tensach()) == chuanhoa(tmpsach)){ tmptp = i1; }
                        }
                        while(1){
                            cout << "\n";
                            cout << "======================= Ban can sua gi? =======================\n";
                            cout << "| 0. Thoat!                                                   |\n";
                            cout << "| 1. Ten sach!                                                |\n";
                            cout << "| 2. Ten tac gia!                                             |\n";
                            cout << "| 3. Ma sach!                                                 |\n";
                            cout << "| 4. Ngay xuat ban!                                           |\n";
                            cout << "| 5. Nha xuat ban!                                            |\n";
                            cout << "| 6. The loai!                                                |\n";
                            cout << "| 7. Doi tuong!                                               |\n";
                            cout << "| 8. Gia tien!                                                |\n";
                            cout << "===============================================================\n";
                            string lct;
                            cout << "Nhap lua chon: ";
                            do{
                                getline(cin, lct);
                                if(!check_choose(chuyen_doi(lct))){ cout << "Nhap lai lua chon: "; }
                            } while(!check_choose(chuyen_doi(lct)));
                            lct = chuyen_doi(lct);
                            int luachont;
                            luachont = chuyenchuoi(lct);
                            if(luachont == 0){ break; }
                            else if(luachont == 1){
                                string namesach;
                                cout << "Nhap ten sach moi: ";
                                getline(cin, namesach);
                                if(namesach.empty()){
                                    cout << "Ban da nhap sai!";
                                } else {
                                    tmptp.set_sach(namesach);
                                }
                            } else if(luachont == 2){
                                string namesach;
                                cout << "Nhap ten tac gia moi: ";
                                getline(cin, namesach);
                                if(namesach.empty()){
                                    cout << "Ban da nhap sai!";
                                } else {
                                    tmptp.set_tg(namesach);
                                }
                            } else if(luachont == 3){
                                string namesach;
                                cout << "Nhap ten ma sach moi: ";
                                getline(cin, namesach);
                                if(namesach.empty()){
                                    cout << "Ban da nhap sai!";
                                } else {
                                    tmptp.set_ma(namesach);
                                }
                            } else if(luachont == 4){
                                string namesach;
                                cout << "Nhap ngay xuat ban moi(x/y/zzzz): ";
                                getline(cin, namesach);
                                namesach = chuyen_doi(namesach);
                                if(!check(namesach)){ cout << "Ngay khong hop le!\n"; }
                                else { tmptp.set_ngay(namesach); }
                            } else if(luachont == 5){
                                string namesach;
                                cout << "Nhap nha xuat ban moi: ";
                                getline(cin, namesach);
                                if(namesach.empty()){
                                    cout << "Ban da nhap sai!";
                                } else {
                                    tmptp.set_nxb(namesach);
                                }
                            } else if(luachont == 6){
                                string namesach;
                                cout << "Nhap the loai moi: ";
                                getline(cin, namesach);
                                if(namesach.empty()){
                                    cout << "Ban da nhap sai!";
                                } else {
                                    tmptp.set_theloai(namesach);
                                }
                            } else if(luachont == 7){
                                string namesach;
                                cout << "Nhap doi tuong moi(tre em/ nguoi lon/ tat ca): ";
                                getline(cin, namesach);
                                if((chuanhoa(namesach)) != "Tre Em " && chuanhoa(namesach) != "Nguoi Lon " && chuanhoa(namesach) != "Tat Ca "){
                                    cout << "Nhap doi tuong khong hop le!\n";
                                } else{ tmptp.set_dt(namesach); }
                            } else if(luachont == 8){
                                double namesach;
                                cout << "Nhap gia tien moi: ";
                                string tmpgia;
                                getline(cin, tmpgia);
                                tmpgia = chuyen_doi(tmpgia);
                                if(!check_gia(tmpgia)){ cout << "Gia tien khong hop le!\n"; }
                                else{
                                    namesach = stoi(tmpgia);
                                    tmptp.set_gia(namesach);
                                }
                            } else{ cout << "Nhap lai lua chon: "; }
                        }
                        for (auto it = l.begin(); it != l.end(); ) {
                            if (chuanhoa(it->get_tensach()) == chuanhoa(tmpsach)) { it = l.erase(it);  }
                        }
                        l.push_front(tmptp);
                        mp.clear();
                        Ten.clear();
                        Nguoi.clear();
                        for(sach tt : l){
                            mp[tt.get_theloai()]++;
                            Ten[tt.get_tensach()]++;
                            Nguoi[tt.get_tentacgia()]++;
                        }
                    } else{ cout << "Nhap lai lua chon: "; }
                }
            } else { cout << "Nhap lai lua chon: "; }
        }
    }
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
        cout << "\n            ============================================== MENU ==============================================\n";
        cout << "            | 0.Thoat!                                                                                       |\n";
        cout << "            | 1. Tao kho sach moi!                                                                           |\n";
        cout << "            | 2. Them san pham!                                                                              |\n";
        cout << "            | 3. Tim kiem san pham!                                                                          |\n";
        cout << "            | 4. Xoa san pham!                                                                               |\n";
        cout << "            | 5. Sap xep danh san pham!                                                                      |\n";
        cout << "            | 6. Cap nhat thong tin san pham!                                                                |\n";
        cout << "            | 7. In danh sach san pham hien co!                                                              |\n";
        cout << "            ==================================================================================================\n";
        int choose = 0;
        string tmp;
        cout << "Nhap lua chon: ";
        do{
            getline(cin, tmp);
            if(!check_choose(chuyen_doi(tmp))){ cout << "Nhap lai lua chon: "; }
        } while(!check_choose(chuyen_doi(tmp)));
        tmp = chuyen_doi(tmp);
        choose = chuyenchuoi(tmp);
        if(choose == 0){ break;} 
        else if(choose == 1){ temp.newlist(); system("pause"); }
        else if(choose == 2){ cin >> temp; system("pause"); }
        else if(choose == 3){ temp.search(); system("pause"); }
        else if(choose == 4){ temp.xoa(); system("pause"); }
        else if(choose == 5){ temp.sapxep(); system("pause"); }
        else if(choose == 6){ temp.update(); system("pause"); }
        else if(choose == 7){ cout << temp; system("pause"); }
        else{ cout << "Nhap sai!\n"; system("pause"); }
    }
}
int main(){
    app a;
    a.khoi_dong_app();
}