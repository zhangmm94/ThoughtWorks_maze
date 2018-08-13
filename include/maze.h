#ifndef PROBLEM_MAZE_H
#define PROBLEM_MAZE_H

#include <string>
#include <vector>
#include <ostream>

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

        private:

        private:
            char name;
        };

    public:
        Maze(std::vector<int> _grid_size);
        Maze(const int _row, const int _col);

        void print_maze();
        bool change_maze(const std::vector<std::vector<int> > _access);

    private:
        void create_maze(int _row, int _col);   //initialize maze
        bool find_answer(const std::vector<int>& _access_grid, std::vector<int>& _answer_grid);

    private:
        int row;
        int col;
        std::vector<std::vector<Grid> > maze;
    };
}


#endif //PROBLEM_MAZE_H
