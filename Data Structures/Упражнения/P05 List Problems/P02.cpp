#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>

class DoublyLinkedList {
private:
    struct Node{;
        T data;
        Node* next;
        Node* prev;

        Node(T value):data(value),next(nullptr),prev(nullptr) {}


    };
    Node* head;
    Node* tail;
    int size;

    public:
    DoublyLinkedList():head(nullptr),tail(nullptr),size(0){}
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp=current;
            current=current->next;
            delete temp;
        }
    }
    void push_back(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head=tail=newNode;
        }else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        size++;
    }
    void print()const {
        Node* current = head;
        while (current) {
            cout<<current->data<<" ";
            if (current->next) cout<<", ";
            current = current->next;
        }
        cout<<endl;
    }
    bool isSortedAscending() const {
        if (!head || !head->next) return true;

        Node* current = head;
        while (current->next) {
            if (current->data > current->next->data)
                return false;
            current = current->next;
        }
        return true;
    }

    int countGreaterBeforeMin() const {
        if (!head) return 0;

        Node* current = head;
        Node* minNode = head;

        // намираме най-малкия елемент
        while (current) {
            if (current->data < minNode->data)
                minNode = current;
            current = current->next;
        }

        // броим колко по-големи са преди него
        int count = 0;
        current = head;
        while (current != minNode) {
            if (current->data > minNode->data)
                count++;
            current = current->next;
        }

        return count;
    }
};

int main() {
    srand(time(0));
    int N;
    do {
        cout<<"Please enter an integer: ";
        cin>>N;

    }while (N<5||N>100);

    DoublyLinkedList<int> list;

    cout<<"Genrated numbers: ";

    for (int i=0; i<N; i++) {
        int number=100+rand()%900;
        list.push_back(number);

    }

    list.print();

    if (list.isSortedAscending()) {
        cout<<"List has sorted in ascening row"<<endl;
    }else {
        cout<<"List has not sorted"<<endl;
        cout<<list.countGreaterBeforeMin()<<endl;
    }
    return 0;
}