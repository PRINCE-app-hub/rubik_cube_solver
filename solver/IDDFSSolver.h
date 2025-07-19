//
// Created by princ on 19-07-2025.
//
#include<bits/stdc++.h>

#include "DFSSolver.h"
#include "../model/RubiksCube.h"
#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

template<typename T,typename H>
class IDDFSSolver {
private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;

  public:
    T rubiksCube;
    IDDFSSolver(T _rubiksCube,int max_depth=8) {
        rubiksCube = _rubiksCube;
        max_search_depth= max_depth;

    }
    vector<RubiksCube::MOVE> solve() {
        for (int i =1; i<=max_search_depth; i++) {
            DFSSolver<T,H> dfsSolver(rubiksCube,i);
            moves=dfsSolver.solve();
            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                return moves;
            }
        }
        return moves;
    }
};

#endif //IDDFSSOLVER_H
