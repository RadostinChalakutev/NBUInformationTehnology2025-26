#include <iostream>
#include <vector>
#include <list>

using namespace std;

class HashMap {
private:
    int capacity;
    vector<list<pair<int,int>>> table;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashMap(int cap = 101) {
        capacity = cap;
        table.resize(capacity);
    }

    void put(int key) {
        int index = hashFunction(key);

        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second++;
                return;
            }
        }

        table[index].push_back({key, 1});
    }

    int get(int key) {
        int index = hashFunction(key);

        for (auto &p : table[index]) {
            if (p.first == key)
                return p.second;
        }

        return 0;
    }

    vector<pair<int,int>> getAll() {
        vector<pair<int,int>> result;

        for (int i = 0; i < capacity; i++) {
            for (auto &p : table[i])
                result.push_back(p);
        }

        return result;
    }
};


// =======================
// ЗАДАЧА А
// =======================

void removeOddOccurrences(vector<int>& arr) {

    HashMap map;

    // броим срещанията
    for (int x : arr)
        map.put(x);

    vector<int> result;

    for (int x : arr) {
        if (map.get(x) % 2 == 0)
            result.push_back(x);
    }

    arr = result;
}


// =======================
// ЗАДАЧА Б
// =======================

void countOccurrences(vector<int>& arr) {

    HashMap map;

    for (int x : arr)
        map.put(x);

    auto all = map.getAll();

    for (auto &p : all) {
        cout << p.first << " -> "
             << p.second << endl;
    }
}


// =======================

int main() {

    // -------- ЗАДАЧА А --------
    vector<int> arr1 = {4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 6, 6, 6};

    removeOddOccurrences(arr1);

 \
    for (int x : arr1)
        cout << x << " ";
    cout << endl << endl;


    // -------- ЗАДАЧА Б --------
    vector<int> arr2 = {3, 4, 4, 2, 3, 3, 4, 3, 2};


    countOccurrences(arr2);

    return 0;
}