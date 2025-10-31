/*Задача 5. Дефинирайте клас с име Flower, който има три член-променливи от типове
string, int и float, които съответно представляват име на цвят, брой листа и
цена. Класът трябва да включва конструктор, който инициализира всяка
променлива с подходяща стойност, както и функции за задаване и получаване
на стойности за всяка член- променлива. Създайте няколко обекта и изведете
информация за всеки един от тях.*/


#include <iostream>

using namespace std;

class Flower {
private:
    string name;
    int leaves;
    float price;

public:
    Flower(string n=" ", int leaves=0, float p=0.0f):name(n),leaves(leaves),price(p){}

    void setName(string& n) {
        name=n;
    }
    void setLeaves(int l) {
        leaves=l;

    }
    void setPrice(float p) {
        price=p;
    }

    string getName() {
        return name;

    }
    int getLeaves() {
        return leaves;
    }
    float getPrice() {
        return price;
    }

    void display()const {
        cout<<name<<" "<<leaves<<" "<<price<<endl;
    }
};

int main() {
    Flower rose("Rose",8,4.8f);
    Flower tupip("Tulip",12,2.5f);

    rose.display();
    tupip.display();

    return 0;


}

