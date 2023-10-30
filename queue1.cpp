//xay dung queue bang mang dong
#include<bits/stdc++.h>
using namespace std;
template<class T>
class Queue{
    private:
        int n, cap;
        T *p;
    public:
        Queue(){
            n = 0;
            cap = 0;
            p = nullptr;
        }
        ~Queue(){
            delete []p;
        }
        int size(){
            return n;
        }
        bool empty(){
            return n == 0;
        }
        void pop(){
            if(n == 0){
                return;
            }
            for(int i = 1; i < n; i++){
                p[i - 1] = p[i];
            }
            n--;
        }
        void push(T x){
            if(n == cap){
                cap = cap*2 + 1;
                T *tmp = new T [cap];
                for(int i = 0; i < n; i++){
                    tmp[i] = p[i];
                }
                delete []p;
                p = tmp;
            }
            p[n] = x;
            n++;
        }
        T &front(){
            return p[0];
        }
        T &back(){
            return p[n - 1];
        }
};
int main(){
    Queue<int> q;
    for(int i = 0; i < 10; i++){
        q.push(i);
    }
    cout << q.back() << endl;
    while(q.size()){
        cout << q.front() << " ";
        q.pop();
    }
}