/*Да се напише програма, която установява, дали вектор от цели числа a0, a1, …,
 *an-1 се състои от различни елементи. Елементите на вектора да се въвеждат от клавиатурата. */

#include <iostream>
using namespace std;


class Vector {
private:
    int* data;
    int size;
public:
    Vector(int n) {
        size = n;
        data = new int[size];

    }
    ~Vector() {
        delete[] data;
    }
    void set(int index, int value) {
        data[index] = value;
    }
    int get(int index) const {
        return data[index];
    }
    int getSize()const {
       return size;
    }

};

int main() {
    int input;
    cout<<"Enter number of elements: ";
    cin>>input;

    Vector vec(input);

    cout<<"Enter "<<input<<" integers: "<<endl;
    for(int i=0;i<input;i++) {
        int x;
        cin>>x;
        vec.set(i,x);
    }
    bool different = true;

    for (int i=0;i<vec.getSize();i++) {
        for (int j=i+1;j<vec.getSize();j++) {
            if ( vec.get(i)==vec.get(j)) {
                different = false;
                break;
            }
        }
        if (!different) {
            break;
        }
    }
    if (different) {
        cout<<"All elements are different"<<endl;
    }else {
        cout<<"There are equal elements";
    }
    return 0;
}
