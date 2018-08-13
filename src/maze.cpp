#include <iostream>

#include "maze.h"

namespace zhangmi
{
Maze::Maze(const int _row, const int _col):row(_row), col(_col)
{
    create_maze(_row, _col);
}

Maze::Maze(std::vector<int> _grid_size)
{
    create_maze(_grid_size[0], _grid_size[1]);
}

void Maze::print_maze()
{
    for(int i = 0; i < maze.size(); ++i)
    {
        for(int j = 0; j < maze[i].size(); ++j)
        {
            std::cout << maze[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}

bool Maze::change_maze(const std::vector<std::vector<int> > _access)
{
    for(int i = 0; i < _access.size(); ++i)
    {
        std::vector<int> answer_grid;

        if(!find_answer(_access[i], answer_grid))
            return false;
        maze[answer_grid[0]][answer_grid[1]].change('R');
    }
    return true;
}

bool Maze::find_answer(const std::vector<int>& _access_grid, std::vector<int>& _answer_grid)
{
    int first_rows = _access_grid[0] * 2 + 1;
    int first_cols = _access_grid[1] * 2 + 1;
    int second_rows = _access_grid[2] * 2 + 1;
    int second_cols = _access_grid[3] * 2 + 1;

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

void Maze::create_maze(int _row, int _col)
{
    Grid grid_hinder('W');
    Grid grid_access('R');

    std::vector<Grid> hinder = {grid_hinder};
    std::vector<Grid> hinder_access = {grid_hinder};
    for(int i = 0; i < _col; ++i)
    {
        hinder.push_back(grid_hinder);
        hinder.push_back(grid_hinder);
        hinder_access.push_back(grid_access);
        hinder_access.push_back(grid_hinder);
    }

    maze.push_back(hinder);
    for(int j = 0; j < _row; ++j)
    {
        maze.push_back(hinder_access);
        maze.push_back(hinder);
    }
}
}

