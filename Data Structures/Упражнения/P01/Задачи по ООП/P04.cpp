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

class Book:public Edition{
  protected:
    string title;
    string releaser;
    string  year;
    string author;
    public:
      Book(){};
      Book(string title, string releaser, string year, string author):Edition(title,releaser, year)
      ,title (title),releaser(releaser),year(year),author(author){};
      virtual void input(){
        cout<<"Enter the Title: ";
          cin>>title;
          cout<<"Enter the Releaser: ";
          cin>>releaser;
        cout<<"Enter the Year: ";
         cin>>year;
        cout<<"Enter the Author: ";
        cin>>author;
       }
          void print() {
              cout<<title<<" "<<releaser<<" "<<year<<endl;
          }
};
class Magazine :public Edition{
  protected:
    string title;
    string releaser;
    string  year;
    string serialNumber;
    public:
      Magazine(){};
      Magazine(string title, string releaser, string year, string serialNumber):
     Edition(title,releaser,year) ,title(title),releaser(releaser),year(year),serialNumber(serialNumber){};

     virtual void input(){
       cout<<"Enter the Title: ";
       cin>>title;
       cout<<"Enter the Releaser: ";
       cin>>releaser;
       cout<<"Enter the Year: ";
       cin>>year;
       cout<<"Enter the Serial Number: ";
       cin>>serialNumber;

     }
     void print() const {
       cout<<title<<" "<<releaser<<" "<<year<<" "<<serialNumber;

     }
};
class Newspaper:public Edition{
  protected:
    string title;
    string releaser;
    string  year;
    string month;
    string day;
    string serialNumber;

    public:
      Newspaper(){};
      Newspaper(string title, string releaser, string year, string month, string day, string serialNumber):
      Edition(title,releaser, year),title(title),releaser(releaser),
  year(year),month(month),day(day),serialNumber(serialNumber){};

  void input() {
    cout<<"Enter the Title: ";
    cin>>title;
    cout<<"Enter the Releaser: ";
    cin>>releaser;
    cout<<"Enter the Year: ";
    cin>>year;
    cout<<"Enter the Month: ";
    cin>>month;
    cout<<"Enter the Day: ";
    cin>>day;
    cout<<"Enter the Serial Number: ";
    cin>>serialNumber;

  }
  void print () const {
    cout<<"Title: "<<title<<endl;
    cout<<"Releaser: "<<releaser<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<"Month: "<<month<<endl;
    cout<<"Day: "<<day<<endl;
    cout<<"Serial Number: "<<serialNumber<<endl;
  }


};

int main(){
  cout<<"Enter released edition"<<endl;
  string edition;
  cin>>edition;
  Edition ed;
  Newspaper newspaper;
  Magazine magazine;
  Book book;

  if ( edition=="Newspaper" ) {
    newspaper.input();
    newspaper.print();

  }else if (edition=="Magazine") {
    magazine.input();
    magazine.print();
  }else if (edition=="Book") {
    book.input();
    book.print();

  }
}


