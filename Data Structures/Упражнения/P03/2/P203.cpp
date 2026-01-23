#include<iostream>
using namespace std;

template<typename T>
class Stack {
    private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d,Node* n=nullptr): data(d), next(n) {}
    };
    Node* topNode;
    size_t sz;

    public:
        Stack():topNode(nullptr),sz(0) {}
    ~Stack(){clear();}
    Stack(const Stack&)=delete;
    Stack& operator=(const Stack&)=delete;

    bool empty() const {
        return topNode == nullptr;
    }
    size_t size() const {return sz;}

    void push(const T& value) {
        topNode= new Node(value,topNode);
        ++sz;
    }
    void pop() {
        if (empty())
        throw underflow_error("Stack is empty");
        Node* old=topNode;
        topNode=topNode->next;
        delete old;
        --sz;
    }
    T& top() {
        if (empty())
            throw underflow_error("Stack is empty");
        return topNode->data;

    }
    void clear() {
        while (!empty()) {
            pop();
        }
    }
};
bool isLetterOrDigit(char c) {
    return isalnum(static_cast<unsigned char>(c))!=0;
}
int main() {
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);

    if (s.size()<3||s.size()>103) {
        cout<<"Invalid input"<<endl;

    }
    for (char c:s) {
       if (!isLetterOrDigit(c)) {
           cout<<"Error: Only digit or letters are allowed"<<endl;
       }

    }

    Stack<char> st;

    for (char c:s) {
        st.push(c);
    }
    bool palindrome=true;

    for (size_t i=0;i<s.size();++i) {
        char fromStack=st.top();
        st.pop();

        if (s[i]!=fromStack) {
            palindrome=false;
            break;
        }

    }
    if (palindrome) {
        cout<<"Palindrome"<<endl;

    }else {
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}