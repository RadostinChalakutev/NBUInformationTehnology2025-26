#include <iostream>
#include <ctime>

#include <stack>
using namespace std;




int main() {
    int n;
    do {

        cout<<"Enter number from 10 to 100: ";
        cin>>n;

    }while (n<10||n>100);


    srand(time(0));

    stack<int>mainStack;//stack with random numbers

    for (int i=1; i<=n; i++) {
        int x = rand()%101+1;
        mainStack.push(x);
    }
    stack<int>evenNumbers;
    stack<int>oddNumbers;

    while (!mainStack.empty()) {
      int x = mainStack.top();
        mainStack.pop();
        if (x%2==0) {
            evenNumbers.push(x);
        }else {
            oddNumbers.push(x);
        }
    }
    cout<<"Even generated numbers are: ";
    stack<int>temp=evenNumbers;
    while (temp.empty()) {
        cout<<temp.top()<<" ";
        temp.pop();
    }



}