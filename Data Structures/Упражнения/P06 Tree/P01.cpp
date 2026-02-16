#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
int countOcurrences (Node* root, int target) {
    if (root == NULL) return 0;

    int count = 0;

    if (root->data==target) count=1;

    return count
    +countOcurrences(root->left, target)
    +countOcurrences(root->right, target);

}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    int number;
    cout<<"Enter element for search: "<<endl;
    cin>>number;
    int result = countOcurrences(root, number);
    cout<<result<<endl;
}