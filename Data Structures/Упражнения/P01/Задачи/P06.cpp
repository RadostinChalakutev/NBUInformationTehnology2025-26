/*Задача 6. Дефинирайте клас с име AllKinds, който има три член-променливи от типове
int, long и float. Класът трябва да съдържа конструктор, който инициализира
всяка променлива с ненулева стойност, както и функции за задаване и
получаване на стойност за всяка член-променлива. Също така класът трябва
да съдържа метод, който изчислява и връщане на сумата от всяка възможна
комбинация от дефинираните типове (член-променливи), както и метод,
който извежда пълна информация за обекти от класа. Създайте няколко
обекта, изведете сумата от всяка възможна комбинация между зададените
стойности за член-данните на всеки един обект и изведете пълна информация
за всеки обект.*/

#include <iostream>
using namespace std;

class AllKinds{

  private:
    int iVal;
    long lVal;
    float fVal;

    public:
      AllKinds(int i=1,long l=1,float f=1.0f):iVal(i),lVal(l),fVal(f){}

      void setVal(int i){
        iVal=i;

      }
      void setVal(long l){
        lVal=l;
      }
      void setVal(float f){
        fVal=f;
      }

      int getiVal(){
        return iVal;
      }
      long getlVal(){
        return lVal;
      }
      float getfVal(){
        return fVal;
      }

      float calculateCombinationSum(){
          return iVal+lVal+fVal+
          iVal+lVal+iVal+fVal+lVal+fVal;
      }
      void display(){
        cout<<iVal<<" "<<lVal<<" "<<fVal<<endl;
        cout<<calculateCombinationSum()<<endl;
      }

};
int main(){
  AllKinds a(1,5L,4.5f);

  a.display();

  return 0;
}