#include <iostream>
using namespace std;

template <typename T>

class Vector {
private:
    T* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];

        }
        delete[] data;
        data = new_data;
    }
    public:
    Vector(int cap=10) {
        capacity = cap;
        size = 0;
        data = new T[capacity];

    }
    ~Vector() {
        delete[] data;

    }
    void push_back(T value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
    }
    T get(int index)const {
        return data[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    int N;
    cout<<"Enter number of elements: ";
    cin>>N;

    Vector<double> v;
    cout<<"Enter "<<N<<" numbers: ";
    for (int i = 0; i < N; i++) {
        double x;
        cin>>x;
        v.push_back(x);

    }

    int K,L;
    cout<<"Enter K and L";
    cin>>K>>L;

    double sum=0;
    int count=0;

    for (int i = 0; i < K; i++) {
        sum+=v.get(i);
        count++;

    }
    double average=sum/count;
    cout<<"Average: "<<average<<endl;

    return 0;

}