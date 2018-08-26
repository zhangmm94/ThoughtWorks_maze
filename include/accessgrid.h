
#ifndef MAZE_ACCESSGRID_H
#define MAZE_ACCESSGRID_H

#include <vector>

namespace zhangmi
{
    class AccessGrid
    {
    public:
        AccessGrid(int _first_rows, int _first_cols, int _second_rows, int _second_cols);

        bool find_access(std::vector<int> &_answer_grid) const;

    private:
        int first_rows;
        int first_cols;
        int second_rows;
        int second_cols;
    };
}

#endif //MAZE_ACCESSGRID_H
