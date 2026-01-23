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
    Deque(const)
};