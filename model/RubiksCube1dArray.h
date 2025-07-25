#pragma once
#include "RubiksCube.h"

class RubiksCube1dArray : public RubiksCube {
private:
    char cube[54]{};

    static inline int getIndex(int face, int row, int col) {
        return face * 9 + row * 3 + col;
    }

    void rotateFace(int faceIndex);
    void rotateacwFace(int faceIndex);

public:
    RubiksCube1dArray();

    COLOR getColor(FACE face, unsigned row, unsigned col) const override;
    bool isSolved() const override;

    RubiksCube& u() override;
    RubiksCube& uPrime() override;
    RubiksCube& u2() override;

    RubiksCube& d() override;
    RubiksCube& dPrime() override;
    RubiksCube& d2() override;

    RubiksCube& f() override;
    RubiksCube& fPrime() override;
    RubiksCube& f2() override;

    RubiksCube& b() override;
    RubiksCube& bPrime() override;
    RubiksCube& b2() override;

    RubiksCube& r() override;
    RubiksCube& rPrime() override;
    RubiksCube& r2() override;

    RubiksCube& l() override;
    RubiksCube& lPrime() override;
    RubiksCube& l2() override;

    void printTopRow() const;
};
