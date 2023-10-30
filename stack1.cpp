//bang mang dong
#include<bits/stdc++.h>
using namespace std;
template<class T>
class Stack{
    private:
        int n, cap;
        T *p;
    public:
        Stack() {
            n = cap = 0;
            p = nullptr;
        }
        ~Stack(){
            delete []p;
        }
        int size(){
            return n;
        }
        bool empty(){
            return n == 0;
        }
        T &top(){
            return p[n-1];
        }
        void pop(){
            n--;
        }
        void push(T x){
            if(n == cap){
                cap = cap*2 + 1;
                T *tmp;
                tmp = new T [cap];
                for(int i = 0; i < n; i++){
                    tmp[i] = p[i];
                }
                delete []p;
                p = tmp;
            } 
            p[n] = x;
            n++;
        }
};
int main(){
    Stack<int> a;
    for(int i = 0; i < 10; i++){
        a.push(i);
    }
    a.push(1000);
    cout << a.size() << endl;
    while(a.size()){
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
    Stack<string> s;
    for(string x : {"chao", "ban", "tre"}){
        s.push(x);
    }
    cout << s.size() << endl;
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }
}