#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Cell
{
    std::uint32_t _val;

public:
    Cell() : _val(0) {}
    Cell(std::uint32_t const &v) : _val(v) {}
    Cell(Cell const &) = default;
    Cell operator=(Cell const & copy) {
        this->_val = copy.getVal();
        return *this;
    }

    bool          isEmpty() const  { return _val == 0; }
    std::uint32_t getVal()  const  { return _val; }
    void          setVal(std::uint32_t v) { _val = v; }
    void          clear() { _val = 0; }

    Cell operator+(Cell const &rhs)
    {
        _val = rhs.getVal()*2;
        return *this;
    }
    Cell& operator+=(Cell const &rhs)
    {
        *this = *this + rhs;
        return *this;
    }
};

class Grid
{
    static const std::uint32_t gridS = 4;
    std::vector<std::vector<Cell>> _grid;

    //initialization stuff
    void _INIT() {} 

public:
    Grid() { _INIT(); }

    //disable copying
    Grid(Grid const &) = delete;
    Grid &operator=(Grid const &) {}

    enum Dir
    {
        U,
        D,
        L,
        R
    };

    //(0, 0) is the botton left corner of the grid.
    //coordinates are done as standard cartesian, except zero-based.
    //grid looks as follows:
    //
    //     |___|___|___|___|
    // x->   0   1   2   3
    //
    //    3|___
    //    2|___
    //    1|___
    //    0|___
    //  y-^
    void shift(Dir d)
    {
        if d == Dir::U
        {
            //iterate through columns. Start at second from top row.
            //i.e., (0, gridS-1)
            //move and combine Cell upwards. If combined,
            //set the combine flag in Cell for this shift so it is not
            //combined again.

            for(std::uint32_t x = 0; x < gridS; ++x)
            {
                for(std::uint32_t y = gridS-1; y >= 0; --y)
                {
                    //stopped here. TODO
                }
            }
        }
        for(std::uint32_t i = 0; i < gridS, ++i) //x iteration
        {

        }
    }

};


int main()
{
    Cell c, d;
    c.setVal(16);
    d.setVal(16);

    cout << "C: " << c.getVal() << "  D: " << d.getVal() << endl
         << "C+D: " << (c+d).getVal() << endl;

    return 0;
}