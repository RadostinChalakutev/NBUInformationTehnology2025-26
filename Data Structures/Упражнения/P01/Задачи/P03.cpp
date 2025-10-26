
/*Задача 3. Напишете кратка C++ функция с име isMultiple, която приема две
положителни long стойности, п и т, и връща True ако и само ако п е кратно
на m, тоест п = т x i за цяло число i.*/

#include <iostream>
using namespace std;

bool isMultiple(long n, long t) {
  return (n % t) == 0;




}
int main() {
    long n,t;
    cin>>n>>t;
    if (isMultiple(n,t)) {
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
}