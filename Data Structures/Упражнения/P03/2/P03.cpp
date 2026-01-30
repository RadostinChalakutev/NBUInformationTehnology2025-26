#include <iostream>
using namespace std;

template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data) : data(data), prev(NULL), next(NULL) {};
    };
    Node* head;
    Node* tail;
    size_t sz;
public:
    Deque() : head(NULL), tail(NULL), sz(0) {};

    ~Deque() {clear();}

    bool empty() const {
        return sz==0;

    }
    size_t size() const {return sz;}

    void insertFront(const T& e) {
        Node* n =new Node(e);

        if (empty()) {
            head=tail=n;
        }else {
            n->next=head;
            head->prev=n;
            head=n;
        }
        sz++;
    }
    void insertBack(const T& e) {
        Node* n =new Node(e);
        if (empty()) {
            head=tail=n;

        }else {
            n->prev=tail;
            tail->next=n;
            tail=n;
        }
        sz++;
    }

    void eraseFront() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");

        }
        Node* old=head;
        if (head==tail) {
            head=tail=NULL;
        }else {
            head=head->next;
            head->prev=NULL;
        }
        delete old;
        sz--;
    }
    void eraseBack() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        Node* old=tail;
        if (head==tail){
            head=tail=NULL;

        }else {
            tail=tail->prev;
            tail->next=NULL;

        }
        delete old;
        sz--;
    }
    T& front() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");

        }
        return head->data;

    }
    T& back() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");

        }
        return tail->data;
    }
    void clear() {
        while (!empty()) {
            eraseFront();
        }

    }

};
int main() {
    Deque<int> dq;

    cout<<"Is deque empty?"<<(dq.empty()? "Yes" : "No")<<endl;
    dq.insertFront(10);
    dq.insertBack(10);
    dq.insertFront(20);
    dq.insertBack(20);
    dq.insertFront(4);

    cout<<"Number of elements: "<<dq.size()<<endl;
    cout<<"First element: "<<dq.front()<<endl;
    cout<<"Last element: "<<dq.back()<<endl;



}