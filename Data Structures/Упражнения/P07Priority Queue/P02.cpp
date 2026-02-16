#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> lower;

    priority_queue<int> higher;

public:
    void addNumber(int number) {
        lower.push(number);
        if (lower.empty()|| number<=lower.top())
            lower.push(number);
        else
            higher.push(number);

        if (lower.size()>higher.size()+1) {
            higher.push(lower.top());
            lower.pop();
        }else if (higher.size()> lower.size()) {
            lower.push(higher.top());
            higher.pop();
        }
    }

    double getMedian() {
        if (lower.size()==higher.size()) {
            return(lower.top()+higher.top());
        }else {
            return lower.top();

        }
    }

};

int main() {
    MedianFinder mf;

    int n;
    cin>>n;

    for (int i=0;i<n;i++) {
        int x;
        cin>>x;
        mf.addNumber(x);
    }
    cout<<mf.getMedian()<<endl;
    return 0;
}