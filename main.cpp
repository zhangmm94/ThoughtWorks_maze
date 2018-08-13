
#include <iostream>
#include <vector>
#include <string>

#include "maze.h"
#include "parseline.h"

int main(void)
{
    while (true)
    {
        std::string str1,str2;
        std::vector<int> grid_size;
        std::vector<std::vector<int> > grid_connect_data;

        std::getline(std::cin,str1);
        if(!zhangmi::Parseline::instance().check_first_line(str1, grid_size))
            continue;

//        std::cout << "rows: " << grid_size[0] << "cols: " << grid_size[1] <<std::endl;

        zhangmi::Maze maze(grid_size);

        std::getline(std::cin, str2);

        if(!zhangmi::Parseline::instance().check_second_line(str2, grid_connect_data))
            continue;

        if(!maze.change_maze(grid_connect_data))
            continue;

        maze.print_maze();
    }

    return 0;
}
