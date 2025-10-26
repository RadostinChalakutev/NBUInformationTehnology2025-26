 /*Задача 2. Да се напише програма, която дефинира шаблон на процедура за въвеждане елементите на масив
и шаблон на функция, намираща минималния елемент на масив от елементи, които могат да се сравняват.*/


#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
void inputArray(vector <T> &a, size_t n){
  a.resize(n);
  for(size_t i = 0; i < n; i++){
    cin>>a[i];
  }
}

template<typename T>
T minElement (const  vector<T> &a ){
  if(a.empty()) throw runtime_error("Empty input");
  T m=a[0];
  for(size_t i = 1; i < a.size(); ++i){
    if(a[i]<m){
      m=a[i];

    }
  }
  return m;
}


int main(){
 size_t n;
 cin>>n;
 vector<int>vi;
 cout<<"Enter "<<n<<" integers: ";
 inputArray(vi,n);
 cout<<minElement<int>(vi)<<endl;
 return 0;


}