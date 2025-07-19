#include "model/RubiksCube.h"
#include <iostream>

#include "model/RubiksCube1dArray.h"
using namespace std;

int main() {
    RubiksCube1dArray cube;

    cout << "================ Before b() ================\n";
    cube.printTopRow();

    cube.b();  // Perform U move (top face clockwise)

    cout << "\n================ After b() ================\n";
    cube.printTopRow();

    return 0;
}
