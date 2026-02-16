#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

class BinarySearchTree {

private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    int countLeaves(Node* node) {
        if (node == nullptr)
            return 0;

        if (node->left == nullptr && node->right == nullptr)
            return 1;

        return countLeaves(node->left) + countLeaves(node->right);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void BSTreeLevelOrder() {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }

    int countLeaves() {
        return countLeaves(root);
    }
};

int main() {

    srand(time(0));

    BinarySearchTree bst;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Generated numbers: ";

    for (int i = 0; i < n; i++) {
        int number = rand() % 100;
        cout << number << " ";
        bst.insert(number);
    }

    cout << endl;

    cout << "Level Order traversal: ";
    bst.BSTreeLevelOrder();

    cout << "Number of leaves: " << bst.countLeaves() << endl;

    return 0;
}