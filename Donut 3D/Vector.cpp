#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <ostream>
#include <string>
#include <cmath>

#include "matrix.h"
#include "vector.h"
#include <windows.h>

using namespace std;

static void printErrorMessageAndExit(string message) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "ERROR: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << message << "\n";
    exit(EXIT_FAILURE);
}

ostream& operator<<(ostream& out, const VECTOR3& a) {
    return out << fixed << setprecision(2) << "" << a.x << " " << a.y << " " << a.z << "";
}

double VECTOR3::operator*(const VECTOR3& a) const {
    return (a.x*x + a.x*y + a.x*z + a.y*x + a.y*y + a.y*z + a.z*x + a.z*y + a.z*z);
}

VECTOR3 VECTOR3::operator*(const MATRIX3& mat) const {
    VECTOR3 ans;

    ans.x = mat[0][0]*x + mat[0][1]*y + mat[0][2]*z;
    ans.y = mat[1][0]*x + mat[1][1]*y + mat[1][2]*z;
    ans.z = mat[2][0]*x + mat[2][1]*y + mat[2][2]*z;

    return ans;
}

void VECTOR3::normalize() {
    x /= sqrt(x*x + y*y + z*z);
    y /= sqrt(x*x + y*y + z*z);
    z /= sqrt(x*x + y*y + z*z);
}

double& VECTOR3:: operator[](int index) {
    if (index < 0 || index > 3) printErrorMessageAndExit("TRYING TO ACCESS MEMORY OVER THE BOUNDARY");
    if (index == 0) return x;
    if (index == 1) return y;
    return z;
}
