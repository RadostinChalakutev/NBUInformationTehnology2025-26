/*Задача 1. Да се напише програма, която дефинира клас People, определящ човек по име
и единен граждански номер (ЕГН), а също производен клас Student на класа People,
 който определя понятието студент като човек, който има факултетен номер и среден успех.
  Да се дефинира клас PStudent, производен на класа Student, реализиращ понятието студент от
  платена форма на обучение. Да се дефинират и изведат обекти от класовете Student и PStudent.*/

#include <iostream>
#include <string>
using namespace std;

class People{

  public:
    string name;
    string id;
  public:
    People(){} //коснтруктор под подразбиране
    People(string name, string id):name(name),id(id){}

    virtual void input(){

      cout<<"Enter student name: ";
      getline(cin,name);
      cout<<"Enter student id: ";
      getline(cin,id);

    }

};

class Student:public People{
  public:
    string studentID;
    double averageGrade;

    public:
      Student(){}
      Student(string name, string id,string studentID,double averageGrade)
          :People(name, id), studentID(studentID),averageGrade(averageGrade){}

   virtual   void input() {
      People::input();
      cout<<"Enter student faculty ID:";
      getline(cin,studentID);
      cout<<"Enter average grade:";
      cin>>averageGrade;
      cin.ignore();//изчистване на буфера след cin

      }

};
class PStudent:public Student{
  public:
    double fee;
    public:
      PStudent(){}

      PStudent(string name,string id, string studentID, double averageGrade,double fee)
          :Student(name, id,studentID,averageGrade),fee(fee){}

      void input() override{
        Student::input();
        cout<<"Enter university fee: ";
        cin>>fee;
        cin.ignore();

      }
};

int main(){
  Student s;
  s.input();

  PStudent ps;
  ps.input();

  People person;


  cout<<s.name<< " with ID: "<<s.id<<"has faculty number "<<s.studentID<<" with average grade of "<<s.averageGrade<<
  "."<<endl;
  cout<<"Student pays "<<ps.fee<<"."<<endl;
}
