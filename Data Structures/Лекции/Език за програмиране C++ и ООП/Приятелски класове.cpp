#include <iostream>
using namespace std;

class Matrix;              // Matrix definition comes later
class Vector {             // a 3-element vector
private:
    double coord[3];
public:
    // ...
    friend class Matrix;     // allow Matrix access to coord
};
class Matrix {             // a 3x3 array
private:
    double a[3][3];
public:
    // ...
    Vector multiplyBy(const Vector& v) {  // multiply (a * v)
        Vector w(0, 0, 0);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                w.coord[i] += a[i][j] * v.coord[j]; // access private data
        return w;
    }
};
