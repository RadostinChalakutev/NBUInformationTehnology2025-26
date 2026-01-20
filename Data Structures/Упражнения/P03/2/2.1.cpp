#include <iostream>
using namespace std;
  const  int MAX=100;
struct Stack {
    int data[MAX];
    int top;
    Stack() {
        top=-1;
    }
    bool isEmpty() {
        return top==-1;
    }
    bool isFull() {
        return top==MAX-1;

    }
    void push(int x) {
        if (!isFull()) {
          data[++top]=x;
        }
    }
    int pop() {
        if (!isEmpty()) {
            return data[top--];
        }
        return -1;
    }

};




int main() {
int n;
    cout<<"Enter natural numbers: ";
    cin>>n;
    Stack s;

    if (n==0) {
        cout<<"Binary: 0"<<endl;
        return 0;

    }
    while (n>0) {
        s.push(n%2);
        n/=2;
    }
    cout<<"Binary:"<<endl;
    while (!s.isEmpty()) {
        cout<<s.pop();

    }
    return 0;
}