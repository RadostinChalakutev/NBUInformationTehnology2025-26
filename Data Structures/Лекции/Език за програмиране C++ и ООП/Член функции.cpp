#include <iostream>
using namespace std;





enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };
class Passenger {
private:
    string name;         // "John Smith"
    MealType mealPref;   // LOW_FAT
    bool isFreqFlyer;    // true
    string freqFlyerNo;  // "293145"
public:
    enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };
    class Passenger {
    private:
        string name;         // "John Smith"
        MealType mealPref;   // LOW_FAT
        bool isFreqFlyer;    // true
        string freqFlyerNo;  // "293145"
    public:
        Passenger();
        bool isFreqFlyer() const
        { return isFreqFlyer; }
        void makeFreqFlyer(const string &newFreqFlyerNo)
        {
            isFreqFlyer = true;
            freqFlyerNo = newFreqFlyerNo;
        }
    };
};

bool Passenger::isFreqFlyer() const
{
    return isFreqFlyer;
}
void Passenger::makeFreqFlyer(const string &newFreqFlyerNo)
{
    isFreqFlyer = true;
    freqFlyerNo = newFreqFlyerNo;
}
/*
Passenger pass;
//...
if (!pass.isFreqFlyer())          // OK
    pass.makeFreqFlyer("999999");  // OK
pass.name = "Joe Blow";           // ERROR: private member
*/