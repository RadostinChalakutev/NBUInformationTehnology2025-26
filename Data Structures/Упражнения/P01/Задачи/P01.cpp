/*Задача 1. Напишете кратка C++ функция, която приема цяло число п и връща сумата от
всички цели числа по-малки от п.*/

#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

 int sum=0;

 for(int i=0;i<n;i++){
   sum+=i;
 }
 cout<<"Sum of numbers under n is: "<<sum;


}