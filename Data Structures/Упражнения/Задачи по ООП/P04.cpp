#include <iostream>
using namespace std;



class Edition{
  protected:
    string title;
    string releaser;
   string  year;
    public:
    Edition(){};
    Edition(string  title, string  releaser, string  year):title(title),releaser(releaser),year(year){};

    virtual void input(){
      cout<<"Enter the Title: ";
      cin>>title;
      cout<<"Enter the Releaser: ";
      cin>>releaser;
      cout<<"Enter the Year: ";
      cin>>year;

    }

   void print() const{
     cout<<title<<" "<<releaser<<" "<<year<<endl;
   }
};

