  /*Задача 3. Да се дефинира шаблон на клас “точка в равнината” с параметър Т за тип
(тип на координатите).
Да се дефинира шаблон  на производен клас, определящ точка в равнината с реални координати
и цвят. Дефинирайте обекти от двата класа и изведете информацията за тях.*/
#include <iostream>
  using namespace std;

  template<typename T>

  class Point{
    protected:
      T x,y;
      public:
        Point(T xVal=0, T yVal=0):x(xVal),y(yVal){ }

        void print() const{
          cout<<"Point: "<<x<<" "<<y<<endl;
        }
  };

  class ColoredPoint:public Point<double>{
    string color;
    public:
      ColoredPoint(double xVal, double yVal, const string& c):Point<double>(xVal,yVal),color(c){ }
      void print() const{
        cout<<"ColoredPoint: "<<x<<" "<<y<<" "<<color<<endl;
      }

  };

  int main(){

      double x,y;
      cout<<"Enter coordinates of the point:"<<endl;
      cin>>x>>y;

      Point<int> p1(x,y);
      p1.print();
      cout<<"Enter color of the point:"<<endl;
      string color;
      cin>>color;

      ColoredPoint cp(x,y,color);
      cp.print();

    return 0;
  }

