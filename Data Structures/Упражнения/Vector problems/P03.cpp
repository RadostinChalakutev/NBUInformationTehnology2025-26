#include<iostream>
#include <vector>
using namespace std;

int main() {
    srand(time(nullptr));
    int n, m;

    cout<<"Enter numbers of vectors: ";
    cin>>n;
    cout<<"Enter size of each vector: ";
    cin>>m;

    vector<vector<int>>v(n, vector<int>(m));

    for(int i=0;i<n;i++) {
        cout<<"Vector "<<i<<" : ";
        for(int j=0;j<m;j++) {
            v[i][j]=rand()%100+1;
        }
        cout<<endl;
    }
    int x;
    cout<<"Enter x:";
    cin>>x;
    cout<<"Indexes of vectors containing "<<x<<" : ";
    bool found=false;

    for (int i=0;i<n;i++) {
        for (int j=0; j<m;j++) {
            if (v[i][j]==x) {
                cout<<i<<" ";
                found=true;
                break;
            }
        }
    }
    if (!found) {
        cout<<"none"<<endl;

    }
    cout<<endl;
    return 0;

}
