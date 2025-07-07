//
// Created by princ on 07-07-2025.
//
#include "RubiksCube.h"

char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
        return 'B';
        case COLOR::GREEN:
        return 'G';
        case COLOR::RED:
        return 'R';
        case COLOR::WHITE:
        return 'W';
        case COLOR::ORANGE:
        return 'O';
        case COLOR::YELLOW:
        return 'Y';
    }
}

string RubiksCube::getMove(MOVE mov) {
    switch (mov) {
        case MOVE::F:
        return "F";
        case MOVE::B:
        return "B";
        case MOVE::R:
        return "R";
        case MOVE::U:
        return "U";
        case MOVE::D:
        return "D";
        case MOVE::L:
        return "L";
        case MOVE::F2:
            return "F2";
            case MOVE::B2:
            return "B2";
            case MOVE::R2:
            return "R2";
            case MOVE::U2:
            return "U2";
            case MOVE::D2:
            return "D2";
            case MOVE::L2:
            return "L2";
        case MOVE::FPRIME:
            return "FPRIME";
        case MOVE::BPRIME:
            return "BPRIME";
        case MOVE::RPRIME:
            return "RPRIME";
        case MOVE::UPRIME:
            return "UPRIME";
        case MOVE::DPRIME:
            return "DPRIME";
        case MOVE::LPRIME:
            return "LPRIME";
    }
}
RubiksCube &RubiksCube::move(MOVE mov) {
    switch (mov) {
        case MOVE::F:
            return this->f();
            case MOVE::B:
            return this->b();
            case MOVE::R:
            return this->r();
            case MOVE::U:
            return this->u();
            case MOVE::D:
            return this->d();
            case MOVE::L:
            return this->l();
            case MOVE::F2:
            return this->f2();
            case MOVE::B2:
            return this->b2();
            case MOVE::R2:
            return this->r2();
            case MOVE::U2:
            return this->u2();
            case MOVE::D2:
            return this->d2();
            case MOVE::L2:
            return this->l2();
            case MOVE::FPRIME:
            return this->fPrime();
            case MOVE::BPRIME:
            return this->bPrime();
            case MOVE::RPRIME:
            return this->rPrime();
            case MOVE::UPRIME:
            return this->uPrime();
            case MOVE::DPRIME:
            return this->dPrime();
            case MOVE::LPRIME:
            return this->lPrime();


    }
}

RubiksCube &RubiksCube::invert(MOVE mov) {
    switch (mov) {
        case MOVE::F:
            return this->fPrime();
            case MOVE::B:
            return this->bPrime();
            case MOVE::R:
            return this->rPrime();
            case MOVE::U:
            return this->uPrime();
            case MOVE::D:
            return this->dPrime();
            case MOVE::L:
            return this->lPrime();
            case MOVE::F2:
            return this->f2();
            case MOVE::B2:
            return this->b2();
            case MOVE::R2:
            return this->r2();
            case MOVE::U2:
            return this->u2();
            case MOVE::D2:
            return this->d2();
            case MOVE::L2:
            return this->l2();
            case MOVE::FPRIME:
            return this->f();
            case MOVE::BPRIME:
            return this->b();
            case MOVE::RPRIME:
            return this->r();
            case MOVE::UPRIME:
            return this->u();
            case MOVE::DPRIME:
            return this->d();
            case MOVE::LPRIME:
            return this->l();

    }
}

void RubiksCube::print() const {
    cout<<"RubiksCube:"<<"\n\n";
    for (int row =0 ; row<3; row++) {
        for (int space=0; space<8 ;space++) cout<<" ";
            for (int col=0; col<3; col++) {
                cout<< getColorLetter(getColor(FACE::UP,row,col))<<" ";
            }
            cout<<'\n';
    }
    cout<<"\n\n";
    for (int row =0 ; row<3; row++) {
        for (int col=0; col<3; col++) cout<<getColorLetter(getColor(FACE::LEFT,row,col))<<" ";
        for (int space=0; space<8 ;space++) cout<<" ";
        for (int col=0; col<3; col++) cout<<getColorLetter(getColor(FACE::FRONT,row,col))<<" ";
        for (int space=0; space<8 ;space++) cout<<" ";
        for (int col=0; col<3; col++) cout<<getColorLetter(getColor(FACE::RIGHT,row,col))<<" ";
        for (int space=0; space<8 ;space++) cout<<" ";
        for (int col=0; col<3; col++) cout<<getColorLetter(getColor(FACE::BACK,row,col))<<" ";
        cout<<'\n';
    }
    cout<<"\n\n";
    for (int row=0; row<3; row++) {
        for (int space=0; space<8 ;space++) cout<<" ";
        for (int col=0; col<3; col++) {
            cout<<getColorLetter(getColor(FACE::DOWN,row,col))<<" ";
        }
        cout<<'\n';
    }


}
vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int noOfTime) {
    vector<MOVE> moves_performed;
    srand(time(nullptr));
    for (unsigned int i = 0; i <noOfTime; i++) {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}

string RubiksCube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
        // UFR
        case 0:
            str+=getColorLetter(getColor(FACE::UP,2,2));
            str+=getColorLetter(getColor(FACE::FRONT,0,2));
            str+=getColorLetter(getColor(FACE::RIGHT,0,0));
            break;
// UFL
    case 1:
    str+=getColorLetter(getColor(FACE::UP,2,0));
    str+=getColorLetter(getColor(FACE::FRONT,0,0));
    str+=getColorLetter(getColor(FACE::LEFT,0,2));
            break;
// DFL
        case 2:
            str+=getColorLetter(getColor(FACE::DOWN,0,0));
            str+=getColorLetter(getColor(FACE::FRONT,2,0));
            str+=getColorLetter(getColor(FACE::LEFT,2,2));
            break;
// DFR
            case 3:
            str+=getColorLetter(getColor(FACE::DOWN,0,2));
            str+=getColorLetter(getColor(FACE::RIGHT,2,0));
            str+=getColorLetter(getColor(FACE::FRONT,2,2));
            break;

   // now rest 4 corners from the back
// BLU
        case 4:
            str+=getColorLetter(getColor(FACE::BACK,0,2));
            str+=getColorLetter(getColor(FACE::LEFT,0,0));
            str+=getColorLetter(getColor(FACE::UP,0,0));
            break;

 // BRU
            case 5:
            str+=getColorLetter(getColor(FACE::BACK,0,0));
            str+=getColorLetter(getColor(FACE::RIGHT,0,2));
            str+=getColorLetter(getColor(FACE::UP,0,2));
            break;
// BRD
            case 6:
            str+=getColorLetter(getColor(FACE::BACK,2,0));
            str+=getColorLetter(getColor(FACE::RIGHT,2,2));
            str+=getColorLetter(getColor(FACE::DOWN,2,2));
            break;
// BLD
            case 7:
            str+=getColorLetter(getColor(FACE::BACK,2,2));
            str+=getColorLetter(getColor(FACE::LEFT,2,0));
            str+=getColorLetter(getColor(FACE::DOWN,2,0));
                break;
                return str;
}
}
uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}
uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
   string corner = getCornerColorString(ind);

    string actual_str;

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}
