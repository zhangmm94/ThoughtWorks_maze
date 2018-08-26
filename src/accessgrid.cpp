#include <iostream>

#include "accessgrid.h"

namespace zhangmi
{
    AccessGrid::AccessGrid(int _first_rows, int _first_cols, int _second_rows, int _second_cols)
    : first_rows(_first_rows), first_cols(_first_cols), second_rows(_second_rows), second_cols(_second_cols)
    {

    }

    bool AccessGrid::find_access(std::vector<int> &_answer_grid) const
    {
        if(first_rows == second_rows)
        {
            if(first_cols - 2 == second_cols)
            {
                _answer_grid.push_back(first_rows);
                _answer_grid.push_back(first_cols - 1);
                return true;// left
            }
            else if(second_cols - 2 == first_cols)
            {
                _answer_grid.push_back(first_rows);
                _answer_grid.push_back(first_cols + 1);
                return true;// right
            }
            else
            {
                std::cerr << "Maze format error.\n";
                return false;// wrong
            }
        }
        else if(first_cols == second_cols)
        {
            if(first_rows == second_rows - 2)
            {
                _answer_grid.push_back(first_rows + 1);
                _answer_grid.push_back(first_cols);
                return true;// down
            }
            else if(second_rows == first_rows - 2)
            {
                _answer_grid.push_back(first_rows - 1);
                _answer_grid.push_back(first_cols);
                return true;// up
            }
            else
            {
                std::cerr << "Maze format error.\n";
                return false;
            }
        }
        else
        {
            std::cerr << "Maze format error.\n";
            return false;
        }
    }
}
