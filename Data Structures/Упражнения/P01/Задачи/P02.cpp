/*Задача 2. Напишете кратка C++ функция, която приема цяло число п и връща сумата от
всички нечетни цели числа по-малки от n.*/

#include <iostream>
using namespace std;

int main(){

  int n;
  cin>>n;

  int sum=0;

  for(int i=0;i<n;i++){
    if(i%2!=0){
      sum+=i;
    }
  }
  cout<<sum;
  return 0;
}