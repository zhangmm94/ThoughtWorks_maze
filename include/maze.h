#ifndef PROBLEM_MAZE_H
#define PROBLEM_MAZE_H

#include <string>
#include <vector>
#include <ostream>

#include "accessgrid.h"

namespace zhangmi
{
class Maze
{
private:
    class Grid
    {
    public:
        Grid(const char _name): name(_name){}

        friend std::ostream& operator << (std::ostream& _os, const Grid& _grid)
        {
            _os << "[" << _grid.name << "]";
            return _os;
        }

        void change(const char _name){name = _name;}
        char get_name()
        {
            char _name;
            _name=name;
            return _name;
        }

    private:
        char name;
    };

public:
    Maze(std::vector<int> _grid_size);
    Maze(const int _row, const int _col);

    void print_maze();
    bool change_maze(const std::vector<zhangmi::AccessGrid> _access);
    bool hasPath(int i, int j, const std::string& str);

private:
    void create_maze(int _row, int _col);   //initialize maze
    bool find_answer(const zhangmi::AccessGrid& _access_grid, std::vector<int>& _answer_grid);
    bool moving(int i, int j, int k, std::string str, bool *visited);
private:
    std::vector<std::vector<Grid> > maze;
    int rows,cols;
};
}


#endif //PROBLEM_MAZE_H
