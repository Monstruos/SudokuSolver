#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include "sudokucell.h"
#include <fstream>
#include <iostream>

using namespace std;

class SudokuSolver
{
public:
    SudokuSolver();

    void solve();

    void setNewNum(int num, int posx, int posy);
    bool isSolved();

    friend std::ostream& operator<<(std::ostream& str, const SudokuSolver& out);
    friend std::istream& operator>>(std::istream& str, SudokuSolver& in);

private:
    // dont change the value, only prob!!
    void newNumInRow(int newNum, int posx, int posy);
    void newNumInCol(int newNum, int posx, int posy);
    void newNumInSqr(int newNum, int posx, int posy);
    void recalcForNewNum(int num, int posx, int posy);

    bool defNumInSqr(int xsqr, int ysqr);
//    bool calcNudeBin(int xsqr, int ysqr);

    std::vector< std::vector<SudokuCell> > m;
    int xsize;
    int ysize;
};

#endif // SUDOKUSOLVER_H
