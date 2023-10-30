#include<bits/stdc++.h>
using namespace std;
class ptbacnhat{
    private:
        double a, b;
    public:
        ptbacnhat() : a(0), b(0) {};
        bool pt_vo_nghiem(){
            return (a == 0 && b != 0);
        }
        bool pt_vo_so_nghiem(){
            return (a == 0 && b == 0);
        }
        bool pt_1_nghiem(){
            return a != 0;
        }
        friend istream& operator>>(istream &in, ptbacnhat &x){
            cout << "Nhap a: ";
            in >> x.a;
            cout << "Nhap b: ";
            in >> x.b;
            return in;
        }
        friend ostream &operator<<(ostream &out, const ptbacnhat x){
            if(x.b > 0) {
                out << "Phuong trinh co dang: " << x.a << "x + " << x.b << endl;
            } else if(x.b == 0){
                out << "Phuong trinh co dang: " << x.a << "x" << endl;
            } else {
                out << "Phuong trinh co dang: " << x.a << "x - " << x.b << endl;
            }
            return out;
        }
        double get_b(){
            return b;
        }
};
class danh_sach{
    private:
        ptbacnhat *p;
        int n;
    public:
        danh_sach() : p(nullptr), n(0) {};
        danh_sach(ptbacnhat *tmp, int sl) : p(tmp), n(sl){};
        ~danh_sach(){
            delete []p;
        }
        friend void input(danh_sach &a){
            cout << "Nhap so luong phuong trinh: ";
            cin >> a.n;
            a.p = new ptbacnhat [a.n + 1];
            for(int i = 0; i < a.n; i++){
                cout << "Phuong trinh thu: " << i + 1 << ": " << endl;
                cin >> a.p[i];
            }
        }
        friend void phuong_trinh_vo_nghiem(const danh_sach &a){
            int cnt = 0;
            for(int i = 0; i < a.n; i++){
                if(a.p[i].pt_vo_nghiem()){
                    cnt++;
                    cout << a.p[i];
                }
            }
            if(cnt == 0) cout << "Khong co!\n";
        }
        friend void phuong_trinh_vo_so_nghiem(const danh_sach &a){
            int cnt = 0;
            for(int i = 0; i < a.n; i++){
                if(a.p[i].pt_vo_so_nghiem()){
                    cnt++;
                    cout << a.p[i];
                }
            }
            if(cnt == 0) cout << "Khong co!\n";
        }
        friend void phuong_trinh_co_1_nghiem(const danh_sach &a){
            int cnt = 0;
            for(int i = 0; i < a.n; i++){
                if(a.p[i].pt_1_nghiem()){
                    cnt++;
                    cout << a.p[i];
                }
            }
            if(cnt == 0) cout << "Khong co!\n";
        }
        friend void tong(const danh_sach &a){
            double sum = 0, cnt = 0;
            for(int i = 0; i < a.n; i++){
                if(a.p[i].pt_1_nghiem()){
                    cnt++;
                    sum += a.p[i].get_b();
                }
            }
            if(cnt == 0) cout << "Khong co phuong trinh co 1 nghiem!\n";
            else{
                cout << "Tong la: ";
                cout << sum*1.0/cnt << endl;
            }
        }
};
int main(){
    danh_sach a;
    input(a);
    while(1){
        cout << "===================================Cac muc===================================\n";
        cout << "0. Thoat!\n";
        cout << "1. Thong ke phuong trinh vo nghiem!\n";
        cout << "2. Thong ke phuong trinh co vo so nghiem!\n";
        cout << "3. Thong ke phuong trinh co 1 nghiem!\n";
        cout << "4. In ra trung binh cong cac he so tu do cua cac phuong trinh co 1 nghiem!\n";
        cout << "=============================================================================\n";
        int luachon;
        cout << "Nhap lua chon: ";
        cin >> luachon;
        if(luachon == 0){
            break;
        } else if(luachon == 1){
            phuong_trinh_vo_nghiem(a);
        } else if(luachon == 2){
            phuong_trinh_vo_so_nghiem(a);
        } else if(luachon == 3){
            phuong_trinh_co_1_nghiem(a);
        } else if(luachon == 4){
            tong(a);
        } else{
            cout << "Nhap sai!";
            break;
        }
    }
}