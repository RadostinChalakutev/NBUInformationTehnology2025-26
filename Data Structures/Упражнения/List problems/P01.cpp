#include <iostream>
using namespace std;

struct Node {
    int digit;
    Node* next;
    Node* prev;
};

void pushBack(Node*& head,Node*& tail, int d ) {
    Node* n=new Node(d,tail,nullptr);

    if (head==nullptr) {
        head=tail=n;
    }else {
        tail->next=n;
        tail=n;
    }
}
void printForward(Node* head) {
    while (head) {
        cout<<head->digit<<" ";
        head=head->next;
    }
    cout<<endl;
}

void printBackward(Node* tail) {
    while (tail) {
        cout<<tail->digit<<" ";
        tail=tail->prev;
    }
    cout<<endl;
}

void countDigit(Node* head) {
    int cnt[10]={0};
    while (head) {
        cnt[head->digit]++;
        head=head->next;
    }
    for (int i=9;i>=0;i--,) {
        if (cnt[i]>0) {
            cout<<i<<" ";

        }
    }
    cout<<endl;
}
int main() {

    srand(time(NULL));
}