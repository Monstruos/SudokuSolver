#include "sudokusolver.h"

SudokuSolver::SudokuSolver()
{
    xsize = 9;
    ysize = 9;
    m.resize(xsize);
    for(unsigned int i = 0; i < m.size(); ++i)
        m[i].resize(ysize);
}

void SudokuSolver::solve()
{
    bool isChanged = true;
    while(isChanged) {
        isChanged = false;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                isChanged = isChanged | defNumInSqr(i, j);
            }
        }
    }
}

void SudokuSolver::setNewNum(int num, int posx, int posy)
{
    m[posx][posy].setNum(num);
    recalcForNewNum(num, posx, posy);
}

bool SudokuSolver::isSolved()
{
    for(int i = 0; i < xsize; ++i)
        for(int j = 0; j < ysize; ++j)
            if(m[i][j].getNum() == 0)
                return false;
    return true;
}

std::ostream& operator<<(std::ostream& str, const SudokuSolver &out)
{
    for(int i = 0; i < out.xsize; ++i) {
        if((i % 3) == 0)
            str << "+-------+-------+-------+" << std::endl;
        for(int j = 0; j < out.ysize; j += 3) {
            str << "| "
                << out.m[i][j] << " "
                << out.m[i][j+1] << " "
                << out.m[i][j+2] << " ";
        }
        str << "|" << std::endl;
    }
    str << "+-------+-------+-------+" << std::endl;
    return str;
}

std::istream& operator>>(std::istream& str, SudokuSolver &in)
{
    unsigned int buf;
    for(int i = 0; i < in.xsize; ++i) {
        for(int j = 0; j < in.ysize; ++j) {
            str >> buf;
            if(buf > 0 && buf < 10)
                in.setNewNum(buf, i, j);
        }
    }
    return str;
}

void SudokuSolver::newNumInRow(int newNum, int posx, int posy)
{
    for(int i = 0; i < ysize; ++i)
        if(i != posy)
            m[posx][i].setProb(newNum, false);
}

void SudokuSolver::newNumInCol(int newNum, int posx, int posy)
{
    for(int i = 0; i < xsize; ++i)
        if(i != posx)
            m[i][posy].setProb(newNum, false);
}

void SudokuSolver::newNumInSqr(int newNum, int posx, int posy)
{
    int xstart = (posx / 3) * 3;
    int xend = xstart + 3;
    int ystart = (posy / 3) * 3;
    int yend = ystart + 3;

    for(int i = xstart; i < xend; ++i) {
        for(int j = ystart; j < yend; ++j)
            if(!(i == posx && j == posy))
                m[i][j].setProb(newNum, false);
    }
}

void SudokuSolver::recalcForNewNum(int num, int posx, int posy)
{
    newNumInRow(num, posx, posy);
    newNumInCol(num, posx, posy);
    newNumInSqr(num, posx, posy);
}

bool SudokuSolver::defNumInSqr(int xsqr, int ysqr)
{
    bool ret = false;
    int c;
    int bufx, bufy;
    for(int n = 1; n < 10; ++n) {
        c = 0;
        bufx = -1;
        bufy = -1;
        for(int i = xsqr*3; i < xsqr*3 + 3; ++i) {
            for(int j = ysqr*3; j < ysqr*3 + 3; ++j) {
                if(m[i][j].getNum() == 0) { // not defined
                    if(m[i][j].getProb(n)) { // if n can be here
                        if(c == 0) {
                            c++;
                            bufx = i;
                            bufy = j;
                        } else {
                            c++;
                            break;
                        }
                    }
                } else {
                    if(m[i][j].getNum() == n) { // stop all;
                        c = -1;
                        break;
                    }
                }
            }
            if(c == -1)
                break;
        }
        if(c == 1) {
            cout << "Set " << n << " in (" << bufx + 1 <<", " << bufy + 1 << ")" << endl;
            setNewNum(n, bufx, bufy);
            ret = true;
        }
    }
    if(ret)
        cout << *this << endl;
    return ret;
}
