#include<bits/stdc++.h>
using namespace std;
template<class T>
class node{
public:
    T data;
    node *next;
    node(){
        data = 0;
        next = nullptr;
    }
    node(T x){
        data = x;
        next = nullptr;
    }
};
template<class T>
class dslk_don{
private:
    int n;
    node<T> *head, *tail;
public:
    dslk_don(){
        n = 0;
        head = nullptr;
        tail = nullptr;
    }        
    dslk_don(int sl, node<T> *tmp1 = 0, node<T> *tmp2 = 0){
        n = sl;
        head = tmp1;
        tail = tmp2;
    }
    int size(){
        return n;
    }
    void push_front(T x){
        if(n == 0){
            tail = head = new node<T>(x);
        } else{
            node<T> *tmp = new node<T>(x);
            tmp->next = head;
            head = tmp;
            tmp = nullptr;
            delete tmp;
        }
        n++;
    }
    void push_back(T x){
        if(n == 0){
            return push_front(x);
        } else{
            node<T> *tmp = new node<T>(x);
            tail->next = tmp;
            tail = tmp;
            tmp = nullptr;
            delete tmp;
        }
        n++;
    }
    T &front(){
        return head->data;
    }
    T &back(){
        return tail->data; 
    }
    void duyet(){
        node<T> *tmp = head;
        while(tmp != nullptr){
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
    void insert(int k, T x){
        if(k < 0 || k > n){
            return;
        }
        if(k == 0){
            return push_front(x);
        } else if(k == n){
            return push_back(x);
        } else{
            node<T> *tmp = head;
            for(int i = 0; i <= k - 2; i++){
                tmp = tmp->next;
            }
            node<T> *newnode = new node<T>(x);
            newnode->next = tmp->next;
            tmp->next = newnode;
            newnode = nullptr;
            delete newnode;
        }
        n++;
    }
    void pop_front(){
        if(n == 0){
            return;
        } else{
            node<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
        n--;
    }
    void pop_back(){
        if(n == 0){
            return;
        } else if(n == 1){
            return pop_front();
        } else{
            node<T> *tmp = head;
            while(tmp->next->next != nullptr){
                tmp = tmp->next;
            }
            tail = tmp;
            tmp = tmp->next;
            tmp = nullptr;
            tail->next = tmp;
            delete tmp;
        }
        n--;
    }
    void earse(int k){
        if(k < 0 || k >= n){
            return;
        } 
        if(k == 0){
            return pop_front();
        } else if(k == n - 1){
            return pop_back();
        } else{
            node<T> *tmp = head;
            for(int i = 0; i <= k - 2; i++){
                tmp = tmp->next;
            }
            node<T> *p = tmp->next;
            tmp->next = p->next;
            delete p;
        }
        n--;
    }
    bool empty(){
        return n == 0;
    }
    void clear() {
        while (head != nullptr) {
            node<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        n = 0;
    }
    int count(T x){
        node<T> *tmp = head;
        int cnt = 0;
        while(tmp != nullptr){
            if(tmp->data == x){
                cnt++;
            }
            tmp = tmp->next;
        }
        return cnt;
    }
    void sort(function<bool(T, T)> cmp = less<T>()){
        if(!head || !head->next){
            return;
        } else{
            for(node<T> *p = head; p != nullptr; p = p->next){
                for(node<T> *q = p->next; q != nullptr; q = q->next){
                    if(!cmp(p->data, q->data)){
                        swap(p->data, q->data);
                    }
                }
            }
        }
    }
    dslk_don<T>& operator=(const dslk_don<T>& other) {
        if (this != &other) { 
            clear();
            node<T>* tmp = other.head;
            while (tmp != nullptr) {
                push_back(tmp->data);
                tmp = tmp->next;
            }
        }
        return *this;
    }
};
template<class T>
class Day{
    private:
        dslk_don<T> t;
    public:
        Day(){
            t.clear();
        }
        void push(T x){
            dslk_don<T> tmp;
            if(t.size() == 0){
                t.push_front(x);
            } else{
                if(t.count(x) == 0){
                    while(t.size()){
                        if(x < t.front()){
                            t.push_front(x);
                            break;
                        } else{
                            tmp.push_front(t.front());
                            t.pop_front();
                        }
                    }
                    if(t.empty()) t.push_front(x);
                    while(tmp.size()){
                        t.push_front(tmp.front());
                        tmp.pop_front();
                    }
                }
            }
        }
        void xuat(){
            t.duyet();
        }
        int size(){
            return t.size();
        }
        void tron_hai_danh_sach(dslk_don<T> c, dslk_don<T> d){
            t.clear();
            dslk_don<T> a, b;
            a = c;
            b = d;
            a.sort();
            b.sort();
            while(!a.empty() && !b.empty()){
                if(a.front() > b.front()){
                    t.push_back(b.front());
                    b.pop_front();
                } else{
                    t.push_back(a.front());
                    a.pop_front();
                }
            }
            while(a.size()){
                t.push_back(a.front());
                a.pop_front();
            }
            while(b.size()){
                t.push_back(b.front());
                b.pop_front();
            }
        }
        void tach_chan_le(dslk_don<T>& a, dslk_don<T>& b){
            while(t.size()){
                if(t.front() % 2 == 0){
                    a.push_front(t.front());
                } else{
                    b.push_front(t.front());
                }
                t.pop_front();
            }
        }
};
int main(){
    
}