#include "model/RubiksCube.h"
#include <iostream>

#include "model/RubiksCube1dArray.h"
using namespace std;

int main() {
    RubiksCube1dArray cube;

    cout << "================ Before U() ================\n";
    cube.printTopRow();

    cube.u();  // Perform U move (top face clockwise)

    cout << "\n================ After U() ================\n";
    cube.printTopRow();

    return 0;
}
