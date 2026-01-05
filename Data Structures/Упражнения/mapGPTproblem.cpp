#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,pair<string,double> >students;

    int choice;

    cout<<"Welocome"<<endl;
    cout<<"1.Add student"<<endl;
    cout<<"2.Print all students"<<endl;
    cout << "3. Find student by student ID";
    cout << "4. Delete a student";
    cout << "5. Student with the highest competitions";
    cout << "6. Exit";
    cout << "Choose from 1 to 6 : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        {
            int studentID;
            string name;
            double grade;

            cout<<"Student ID : ";
            cin>>studentID;
            cout<<"Name : ";
            getline(cin,name);
            cout<<"Grade : ";
            cin>>grade;
            students[studentID] = make_pair(name,grade);
            cout<<"Student added succesfully";
            break;
        }

    }


}