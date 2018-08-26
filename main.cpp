
#include <iostream>
#include <vector>
#include <string>

#include "maze.h"
#include "parseline.h"
#include "accessgrid.h"

int main(void)
{
    while (true)
    {
        std::string str1 , str2 , str3;
        std::vector<int> grid_size;
        std::vector<zhangmi::AccessGrid> grid_connect_data;

        //input origin maze:rows cols

        std::getline(std::cin,str1);
        if(!zhangmi::Parseline::instance().check_first_line(str1, grid_size))
            continue;

        std::cout << "rows: " << grid_size[0] << "cols: " << grid_size[1] <<std::endl;

        zhangmi::Maze maze(grid_size);

        //input connected cell id
        std::getline(std::cin, str2);

        if(!zhangmi::Parseline::instance().check_second_line(str2, grid_connect_data))
            continue;

        if(!maze.change_maze(grid_connect_data))
            continue;

        std::vector<int> start;
        std::string direction;
        std::getline(std::cin,str3);
        if(!zhangmi::Parseline::instance().check_third_line(str3, start,direction))
            continue;

        if(maze.hasPath(start[0],start[1],direction))
            maze.print_maze();
    }

    return 0;
}

