#include "sudokucell.h"

SudokuCell::SudokuCell()
{
    num.resize(NUM_SIZE, true);
    val = 0;
}

void SudokuCell::setNum(unsigned int numer)
{
    for(unsigned int i = 0; i < num.size(); ++i)
        num[i] = (i == (numer - 1) ? true : false);
    val = numer;
}

int SudokuCell::getNum()
{
    return val;
}

int SudokuCell::setNumByProp()
{
    if(val != 0)
        return val;
    int c = 0, buf;
    for(unsigned int i = 0; i < num.size(); ++i) {
        if(num[i] == true) {
            if(c == 0) {
                buf = i + 1;
                c++;
            } else {
                return 0;
            }
        }
    }

    val = buf;
    return val;
}

void SudokuCell::setProb(int n, bool state)
{
    num[n - 1] = state;
}

bool SudokuCell::getProb(int n)
{
    return num[n - 1];
}

int SudokuCell::getNumOfProb() const
{
    int c = 0;
    for(unsigned int i = 0; i < num.size(); ++i)
        if(num[i] == true)
            c++;
    return c;
}


std::ostream &operator<<(std::ostream& str, const SudokuCell &out)
{
    int n = out.val;
    if(n != 0) {
        str << n;
        return str;
    }
    if(out.getNumOfProb() == 0) {
        str << "?";
    } else {
        str << "-";
    }
    return str;
}

bool operator==(const SudokuCell &left, const SudokuCell &right)
{
    if(left.getNumOfProb() != right.getNumOfProb())
        return false;

    for(int i = 0; i < NUM_SIZE; ++i) {
        if(left.num[i] != right.num[i])
            return false;
    }

    return true;
}

bool operator!=(const SudokuCell &left, const SudokuCell &right)
{
    return !(left == right);
}
