/*Задача 4. Дефинирайте клас Student, който съдържа следната информация за
студентите: три имена, курс, специалност, университет, електронна поща и
телефонен номер. Декларирайте няколко конструктора за класа Student,
които имат различни списъци с параметри (за цялостната информация за
даден студент или част от нея). Данните, за които няма входна информация
да се инициализират съответно с null или 0. Добавете метод в класа Student,
който извежда пълна информация за студента. Създайте няколко обекта от
дадения клас и ги запазете в масив. Изведете информация за създадените
обекти.*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student{
  private:
    string name;
    int course;
    string degree;
    string university;
    string email;
    string phone;



    void readInfo() {
      cout<<"Enter your full name: ";
      getline(cin, name);
      cout<<"Enter your course number: ";
      cin>>course;
      cout<<"Enter your degree: ";
      cin>>degree;
      cout<<"Enter your university: ";
      cin>>university;
      cout<<"Enter your phone: ";
      cin>>phone;

    }
    void printInfo() const{
      cout<<"////////////"<<endl;
      cout<<"Name: "<<name<<endl;
      cout<<"Course Number: "<<course<<endl;
      cout<<"Degree: "<<degree<<endl;
      cout<<"University: "<<university<<endl;
      cout<<"Email: "<<email<<endl;
      cout<<"Phone: "<<phone<<endl;

    }
    const string& getName() const{return name;}
};

int main(){
  vector<Student> students;

  while(true){
    cout<<"1. Add Student"<<endl;
    Student s;

    students.push_back(s);
  }
}
