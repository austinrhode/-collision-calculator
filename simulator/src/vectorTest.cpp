#include <iostream>
#include <model/vect.hpp>
using namespace std;

int main(int argc, char **argv) {

    pbVector v1 = pbVector(1, 2);
    pbVector v2 = pbVector(2, 3);

    pbVector v3 = v1 + v2;
    pbVector v4 = v3 + v1;
    double dot = v1.dot_product(v2);

    cout << dot << endl;


    cout << v4.x << v4.y;

    return 0;
}
