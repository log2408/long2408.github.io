#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node {
public:
    T data;
    Node* next;
    Node(T x) {
        data = x;
        next = nullptr;
    }
};
template<class T>
class Stack {
private:
    Node<T>* topNode;
    int n;
public:
    Stack() {
        topNode = nullptr;
        n = 0;
    }
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
    int size() {
        return n;
    }
    bool empty() {
        return n == 0;
    }
    void push(T x) {
        Node<T>* newNode = new Node<T>(x);
        newNode->next = topNode;
        topNode = newNode;
        n++;
    }
    void pop() {
        if (!empty()) {
            Node<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
            n--;
        }
    }
    T& top() {
        return topNode->data;
    }
};
int main() {
    Stack<int> s;
    for (int i = 0; i < 10; i++) {
        s.push(i);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    s.push(0);
    s.top() = 101010;
    s.push(10);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
