#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H
#define NUM_SIZE 9

#include <fstream>
#include <vector>

class SudokuCell
{
public:
    SudokuCell();

    void setNum(unsigned int numer);
    int getNum();

    int setNumByProp();

    void setProb(int n, bool state);
    bool getProb(int n);
    int getNumOfProb() const;

    friend bool operator==(const SudokuCell& left, const SudokuCell& right);
    friend bool operator!=(const SudokuCell& left, const SudokuCell& right);
    friend std::ostream& operator<<(std::ostream& str, const SudokuCell& out);

private:
    std::vector<bool> num;
    int val;
};


#endif // SUDOKUCELL_H
