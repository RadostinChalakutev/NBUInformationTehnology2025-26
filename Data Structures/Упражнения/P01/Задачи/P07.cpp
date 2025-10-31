/* Задача 7. Да се дефинира клас Point с две член-данни - двете декартови координати на
точка и подходящи член-функции. Като се използва дефинираният клас да се
напише програма, която:
а) въвежда n различни точки от равнината, след което ги транслира с (2, 4) и
извежда получените точки;
б) намира разстоянието между всеки две точки (все едно старите или
новите);
√(𝑥2 − 𝑥1)2 + (𝑦2 − 𝑦1)2;
в) намира точките, разстоянието между които е най-малко (най-голямо).*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
template<class T>
class Point{
  private:
    T x;
    T y;

  public:
    Point (T x=0, T y=0) : x(x), y(y){}

    void translate( const Point& other){
      x+=other.x;
      y+=other.y;
    }
    double distance(const Point& other){
      return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));

    }
    void print(){
      cout<<"("<<x<<","<<y<<")"<<endl;
    }


};

int main(){
  int n;
  cout<<"Enter number of points: ";
  cin>>n;
  vector<Point<double>>points;

  for(int i=0;i<n;i++){
    double x,y;
    cout<<"Enter coordinates of point: ";
    cin>>x>>y;
    points.push_back(Point<double>(x,y));

    cout<<"Translatec points: "<<endl;
    for(Point<double>& point:points){
    point.translate(Point<double>(2,4));

    point.print();


    }
  }
  cout<<"Distance between points: "<<endl;
  double minDistance=numeric_limits<double>::max();
  double maxDistance=0;
}