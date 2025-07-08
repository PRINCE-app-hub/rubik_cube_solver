#include "RubiksCube1dArray.h"
#include <iostream>

RubiksCube1dArray::RubiksCube1dArray() {
    for (int face = 0; face < 6; face++) {
        char color = getColorLetter(static_cast<COLOR>(face));
        for (int i = 0; i < 9; i++) {
            cube[face * 9 + i] = color;
        }
    }
}

void RubiksCube1dArray::rotateFace(int faceIndex) {
    char temp[9];
    for (int i = 0; i < 9; ++i)
        temp[i] = cube[faceIndex * 9 + i];

    cube[faceIndex * 9 + 0] = temp[6];
    cube[faceIndex * 9 + 1] = temp[3];
    cube[faceIndex * 9 + 2] = temp[0];
    cube[faceIndex * 9 + 3] = temp[7];
    cube[faceIndex * 9 + 4] = temp[4];
    cube[faceIndex * 9 + 5] = temp[1];
    cube[faceIndex * 9 + 6] = temp[8];
    cube[faceIndex * 9 + 7] = temp[5];
    cube[faceIndex * 9 + 8] = temp[2];
}

void RubiksCube1dArray::rotateacwFace(int faceIndex) {
    char temp[9];
    for (int i=0; i<9; i++ ) {
        temp[i] = cube[faceIndex * 9 + i];
    }
    cube[faceIndex * 9 + 0] = temp[2];
    cube[faceIndex * 9 + 1] = temp[5];
    cube[faceIndex * 9 + 2] = temp[8];
    cube[faceIndex * 9 + 3] = temp[1];
    cube[faceIndex * 9 + 4] = temp[4];
    cube[faceIndex * 9 + 5] = temp[7];
    cube[faceIndex * 9 + 6] = temp[0];
    cube[faceIndex * 9 + 7] = temp[3];
    cube[faceIndex * 9 + 8] = temp[6];
}

RubiksCube::COLOR RubiksCube1dArray::getColor(FACE face, unsigned row, unsigned col) const {
    char color = cube[getIndex(static_cast<int>(face), row, col)];
    switch (color) {
        case 'W': return COLOR::WHITE;
        case 'G': return COLOR::GREEN;
        case 'R': return COLOR::RED;
        case 'B': return COLOR::BLUE;
        case 'O': return COLOR::ORANGE;
        case 'Y': return COLOR::YELLOW;
        default:  return COLOR::WHITE;
    }
}

bool RubiksCube1dArray::isSolved() const {
    for (int face = 0; face < 6; face++) {
        char expected = getColorLetter(static_cast<COLOR>(face));
        for (int i = 0; i < 9; i++) {
            if (cube[face * 9 + i] != expected)
                return false;
        }
    }
    return true;
}

RubiksCube& RubiksCube1dArray::u() {
    rotateFace(0);
    char temp[3];
    for (int i = 0; i < 3; i++) temp[i] = cube[getIndex(4, 0, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(4, 0, i)] = cube[getIndex(1, 0, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(1, 0, i)] = cube[getIndex(2, 0, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(2, 0, i)] = cube[getIndex(3, 0, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(3, 0, i)] = temp[i];
    return *this;
}
// RubiksCube& RubiksCube1dArray::uPrime() {
//     rotateFace(0);
// }

RubiksCube& RubiksCube1dArray::uPrime() {
    rotateFace(0);
    char temp[3];
    for (int i=0; i<3; i++) temp[i]=cube[getIndex(4, 0, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(4, 0, i)] = cube[getIndex(3, 0, i)];
    for (int i=0; i<3; i++) cube[getIndex(3,0,i)]=cube[getIndex(2,0,i)];
    for (int i=0; i<3; i++) cube[getIndex(2,0,i)]=cube[getIndex(1,0,i)];
    for (int i=0; i<3; i++) cube[getIndex(1,0,i)] = temp[i];
}
// Dummy implementations (to prevent abstract error)

RubiksCube& RubiksCube1dArray::u2() { return *this; }
RubiksCube& RubiksCube1dArray::d() { return *this; }
RubiksCube& RubiksCube1dArray::dPrime() { return *this; }
RubiksCube& RubiksCube1dArray::d2() { return *this; }
RubiksCube& RubiksCube1dArray::f() { return *this; }
RubiksCube& RubiksCube1dArray::fPrime() { return *this; }
RubiksCube& RubiksCube1dArray::f2() { return *this; }
RubiksCube& RubiksCube1dArray::b() { return *this; }
RubiksCube& RubiksCube1dArray::bPrime() { return *this; }
RubiksCube& RubiksCube1dArray::b2() { return *this; }
RubiksCube& RubiksCube1dArray::r() { return *this; }
RubiksCube& RubiksCube1dArray::rPrime() { return *this; }
RubiksCube& RubiksCube1dArray::r2() { return *this; }
RubiksCube& RubiksCube1dArray::l() { return *this; }
RubiksCube& RubiksCube1dArray::lPrime() { return *this; }
RubiksCube& RubiksCube1dArray::l2() { return *this; }

void RubiksCube1dArray::printTopRow() const {
    std::cout << "Front: ";
    for (int i = 0; i < 3; i++) std::cout << cube[getIndex(1, 0, i)];
    std::cout << " <- Front" << std::endl;

    std::cout << "Right: ";
    for (int i = 0; i < 3; i++) std::cout << cube[getIndex(3, 0, i)];
    std::cout << " <- Right" << std::endl;

    std::cout << "Back:  ";
    for (int i = 0; i < 3; i++) std::cout << cube[getIndex(4, 0, i)];
    std::cout << " <- Back" << std::endl;

    std::cout << "Left:  ";
    for (int i = 0; i < 3; i++) std::cout << cube[getIndex(2, 0, i)];
    std::cout << " <- Left" << std::endl;
}
