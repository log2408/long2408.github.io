// cai dat queue bang danh sach lien ket 
#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
    public:
        T data;
        node *next;
        node(T x){
            data = x;
            next = nullptr;
        }
};
template<class T>
class Queue{
    private:
        int n;
        node<T> *head, *trail;
    public:
        Queue(){
            n = 0;
            head = nullptr;
            trail = nullptr;
        }
        ~Queue(){
            while(n){
                pop();
            }
        }
        void pop(){
            if(n == 0){
                return ;
            }
            node<T> *tmp = head;
            head = tmp->next;
            delete tmp;
            n--;
        }
        int size(){
            return n;
        }
        bool empty(){
            return n == 0;
        }
        T &front(){
            return head->data;
        }
        T &back(){
            return trail->data;
        }
        void push(T x){
            if(n == 0){
                head = trail = new node<T>(x);
            } else{
                trail = trail->next = new node<T>(x);
            }
            n++;
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