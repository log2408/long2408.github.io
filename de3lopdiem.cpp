#include<bits/stdc++.h>
using namespace std;
string chuanhoa(string s){
    string res = "";
    res += toupper(s[0]);
    for(int i = 1; i < s.size(); i++){
        res += tolower(s[i]);
    }
    return res;
}
class diem{
    private:
        string name, color;
        double x, y, z;
    public:
        diem() : name(""), color(""), x(0), y(0), z(0) {};
        diem(string ten, string mau, double hd, double td, double cd) : name(ten), color(mau), x(hd), y(td), z(cd){};
        friend void input(diem &a){
            cout << "Nhap diem!\n";
            cout << "Nhap ten: ";
            cin >> a.name;
            cout << "Nhap mau: ";
            do{
                cin >> a.color;
                if(chuanhoa(a.color) != "Do" && chuanhoa(a.color) != "Vang" && chuanhoa(a.color) != "Xanh" && chuanhoa(a.color) != "1" && chuanhoa(a.color) != "2" && chuanhoa(a.color) != "3"){
                    cout << "Nhap lai: ";
                }
            } while(chuanhoa(a.color) != "Do" && chuanhoa(a.color) != "Vang" && chuanhoa(a.color) != "Xanh" && chuanhoa(a.color) != "1" && chuanhoa(a.color) != "2" && chuanhoa(a.color) != "3");
            cout << "Nhap hoanh do: ";
            cin >> a.x;
            cout << "Nhap tung do: ";
            cin >> a.y;
            cout << "Nhap cao do: ";
            cin >> a.z;
        }
        friend istream &operator>>(istream &in, diem &a){
            cout << "Nhap diem!\n";
            cout << "Nhap ten: ";
            in >> a.name;
            cout << "Nhap mau: ";
            do{
                in >> a.color;
                if(chuanhoa(a.color) != "Do" && chuanhoa(a.color) != "Vang" && chuanhoa(a.color) != "Xanh" && chuanhoa(a.color) != "1" && chuanhoa(a.color) != "2" && chuanhoa(a.color) != "3"){
                    cout << "Nhap lai: ";
                }
            } while(chuanhoa(a.color) != "Do" && chuanhoa(a.color) != "Vang" && chuanhoa(a.color) != "Xanh" && chuanhoa(a.color) != "1" && chuanhoa(a.color) != "2" && chuanhoa(a.color) != "3");
            cout << "Nhap hoanh do: ";
            in >> a.x;
            cout << "Nhap tung do: ";
            in >> a.y;
            cout << "Nhap cao do: ";
            in >> a.z;
            return in;
        }
        friend ostream &operator<<(ostream &out, const diem &a){
            cout << "Toa do " << a.name << " la: (" << a.x << ", " << a.y << ", " << a.z << "), co mau la: " << a.color << endl;
            return out; 
        }
        double kc(){
            double sum = 0;
            sum = (abs(x) + abs(y) + abs(z));
            return sum*1.0/3;
        }
        friend double operator<(diem a, diem b){
            return a.kc() < b.kc();
        }
        string get_mau(){
            return color;
        }
};
class danhsach{
    private:
        diem *p;
        int n;
    public:
        danhsach() : p(nullptr), n(0) {};
        danhsach(diem *tmp, int ds) : p(tmp), n(ds) {};
        ~danhsach(){
            delete []p;
        }
        friend istream &operator>>(istream &in, danhsach &a){
            cout << "Nhap danh sach diem!\n";
            cout << "Nhap so luong diem: ";
            in >> a.n;
            a.p = new diem [a.n + 1];
            for(int i = 0; i < a.n; i++){
                in >> a.p[i];    
            }
            return in;
        }
        friend ostream &operator<<(ostream &out, const danhsach &a){
            out << "Danh sach diem:\n";
            for(int i = 0; i < a.n; i++){
                out << a.p[i] ;
            }
            return out;
        }
        double tong_kc_diem_vang(){
            double sum = 0;
            for(int i = 0; i < n; i++){
                if(chuanhoa(p[i].get_mau()) == "Vang" || p[i].get_mau() == "3"){
                    sum += p[i].kc();
                }
            }
            return sum;
        }
        void diem_do_xa_nhat(){
            diem a;
            int dem = 0;
            sort(p, p + n);
            for(int i = n - 1; i >= 0; i--){
                if(p[i].get_mau() == "1" || chuanhoa(p[i].get_mau()) == "Do"){
                    a = p[i];
                    dem++;
                    break;
                }
            }
            if(dem == 0) cout << "Khong co diem do!";
            else cout << "Diem do xa nhat co " << a;
        }
};
int main(){
    danhsach a;
    cin >> a;
    a.diem_do_xa_nhat();
    cout << endl;
    cout << "Tong khoang cach cua diem vang: " << a.tong_kc_diem_vang();
}