#include <iostream>
#include "sudokusolver.h"

using namespace std;

int main()
{

    ifstream inp("sudoku2.txt");
    SudokuSolver a;
    inp >> a;
    a.solve();
    cout << "Result:" << endl << a;
    return 0;
}
