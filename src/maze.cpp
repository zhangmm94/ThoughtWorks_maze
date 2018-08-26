#include <iostream>
#include "maze.h"

namespace zhangmi
{
Maze::Maze(const int _row, const int _col)
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

bool Maze::change_maze(const std::vector<zhangmi::AccessGrid> _access)
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


bool Maze::hasPath( int i, int j, const std::string& str) {

    i=2*i+1;
    j=2*j+1;
    //    std::cout<<"rows:"<<rows<<"; cols:"<<cols<<std::endl;
    if (i < 0 || i >= rows || i < 0 || j >= cols) return false;
    bool *visited = new bool[rows * cols];
    for (int index = 0; index < rows * cols; index++)
        visited[index] = false;
    bool b = moving(i, j, 0, str, visited);
    if (!b)
        std::cerr << "the path is invalid.\n";
    delete []visited;
    return b;
}

bool Maze::moving(int i, int j, int k, std::string str, bool *visited) {
    if (i < 0 || i >= rows || i < 0 || j >= cols || maze[i][j].get_name() == 'W' || visited[i * cols + j] == true)
        return false;
    if (str[k] == '\0')
    {
        std::cout << "row: " << i << ",col: " << j << std::endl;
        maze[i][j].change('A');
        return true;
    }
    visited[i * cols + j] = true;
    bool OK;
    std::cout<<str[k]<<std::endl;
    if (str[k] == 'N')
        OK = moving(i - 1,j,k + 1,str,visited);
    else if (str[k] == 'S')
        OK = moving(i + 1,j,k + 1,str,visited);
    else if (str[k] == 'W')
        OK = moving(i,j - 1,k + 1,str,visited);
    else if (str[k] == 'E')
        OK = moving(i,j + 1,k + 1,str,visited);
    else
    {
        std::cerr << "please input valid direction.\n";
        return false;
    }
    return OK;

}


bool Maze::find_answer(const zhangmi::AccessGrid& _access_grid, std::vector<int>& _answer_grid)
{
    if(_access_grid.find_access(_answer_grid))
    {
        //add conditional
        if(_answer_grid[0] > maze.size() - 1 || _answer_grid[1] > maze[0].size() - 1)
        {
            std::cerr << "Number out of range.";
        }
        else
            return true;
    }
    return false;
}

void Maze::create_maze(int _row, int _col)
{
    rows=2*_row+1;
    cols=2*_col+1;
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

