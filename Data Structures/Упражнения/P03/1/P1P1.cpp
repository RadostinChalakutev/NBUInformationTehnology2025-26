/*1. Реализирайте структура от данни Опашка, за да решите следните задачи:
1.1. Да се напише програма, която създава и извежда опашка от опашки от цели
числа.*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<queue<int>> mainQueue;
    queue<int>q1;
    queue<int>q2;
    queue<int>q3;
    queue<int>q4;
    queue<int>q5;

    q1.push(1);
    q2.push(2);
    q3.push(3);
    q4.push(4);
    q5.push(5);

    q1.push(55);
    q2.push(92);
    q3.push(99);
    q4.push(64);

    mainQueue.push(q1);
    mainQueue.push(q2);
    mainQueue.push(q3);
    mainQueue.push(q4);
    mainQueue.push(q5);

    while (!mainQueue.empty()) {
        queue<int> current=mainQueue.front();
        mainQueue.pop();

        while (!current.empty()) {
            cout << current.front() << " ";
            current.pop();
        }
    }
}