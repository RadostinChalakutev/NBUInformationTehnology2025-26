#include <iostream>
using namespace std;

struct Node {
        int digit;
        Node* next;
        Node *prev;

        Node(int d):digit(d),prev(nullptr),next(nullptr) {

        }

};

class DoublyLinkedList {
private:
        Node* head;
        Node* tail;
        int size;

public:
        DoublyLinkedList():head(nullptr),tail(nullptr),size(0){}

        ~DoublyLinkedList() {
                Node* current = head;
                while (current) {
                        Node* toDelete=current;
                        current=current->next;
                        delete toDelete;
                }

        }
        void push_back(int digit) {
                Node* newNode = new Node(digit);
                if (!head) {
                        head = tail = newNode;
                }else {
                        tail->next = newNode;
                        newNode->prev=tail;
                        tail=newNode;
                }
                size++;
        }
        string toStringForward() const {
                string s;
                s.reserve(size);
                Node* current=head;
                while (current) {
                        s.push_back(char('0'+current->digit));
                        current=current->next;
                }
                return s;


        }
        string toStringBackward()const {
                string s;
                s.reserve(size);
                Node* current=tail;
                while (current) {
                        s.push_back(char('0'+current->digit));
                        current=current->prev;
                }
                return s;
        }
        void countDigits(int counts[10])const {
                for (int i=0; i<10; i++) {
                        counts[i]=0;
                }
                Node* current=head;
                while (current) {
                        counts[current->digit]++;
                        current=current->next;
                }
        }

};


int main() {
        int n;
        cout<<"Enter number from 10 to 100"<<endl;
        cin>>n;

        srand(unsigned(time(0)));
        DoublyLinkedList list;

        for (int i=0; i<n; i++) {
                int digit=rand()%10;
                list.push_back(digit);
        }
        cout<<"N:"<<n<<list.toStringForward()<<endl;
        cout<<"Mirrored long number: "<<list.toStringBackward()<<endl;

        int counts[10];
        list.countDigits(counts);

        cout<<"Digit counts: ";
        bool first=true;
        for (int d=9;d>=0;d--) {
                if (counts[d]>0) {
                        if (!first)cout<<" ,";
                        cout<<d<<":"<<counts[d];
                        first=false;
                }
        }
        return 0;

}