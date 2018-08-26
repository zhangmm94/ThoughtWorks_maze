#ifndef MAZE_PARSELINE_H
#define MAZE_PARSELINE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <regex>

#include "accessgrid.h"

namespace zhangmi
{
class Parseline
{
public:
    static Parseline& instance()
    {
        static std::shared_ptr<Parseline> parseline(new Parseline());
        return *parseline;
    }

    bool check_first_line(const std::string& _strin, std::vector<int>& _vout)
    {
        std::vector<std::string> gridSize;
        split_string(_strin, gridSize, " ");

        if(gridSize.size() != 2)
        {
            std::cerr << "Incorrect command format​.\n";
            return false;
        }

        if(is_digits(gridSize[0]) && is_digits(gridSize[1]))
        {
            int rows = std::atoi(gridSize[0].c_str());
            int cols = std::atoi(gridSize[1].c_str());

            if(rows <= 0 || cols <= 0 || rows > max_gridsize/2 || cols > max_gridsize/2)
            {
                std::cerr << "Number out of range​.​\n";
                return false;
            }
            _vout.push_back(rows);
            _vout.push_back(cols);
        }
        else
        {
            std::cerr << "Invalid number format​.\n";
            return false;
        }
        return true;
    }

    bool check_second_line(const std::string& _strin, std::vector<AccessGrid>& _vout)
    {
        std::vector<std::string> grid_connect_data;

        split_string(_strin, grid_connect_data, ";");

        for(int i = 0; i < grid_connect_data.size(); ++i)
        {
            std::vector<std::string> connect;
            grid_connect_data[i] = replace_all(grid_connect_data[i], ",", " ");
            split_string(grid_connect_data[i], connect, " ");

            if(connect.size() != 4)
            {
                std::cerr << "Incorrect command format.\n";
                return false;
            }

            if(is_digits(connect[0]) && is_digits(connect[1]) && is_digits(connect[2]) && is_digits(connect[3]))
            {
                int first_row = atoi(connect[0].c_str());
                int first_col = atoi(connect[1].c_str());
                int second_row = atoi(connect[2].c_str());
                int second_col = atoi(connect[3].c_str());

                if(first_row < 0 || first_col < 0 || first_row > max_gridsize/2 || first_col > max_gridsize/2 ||
                        second_row < 0 || second_col < 0 ||second_row > max_gridsize/2 || second_col >max_gridsize/2)
                {
                    std::cerr << "Number out of range​.​\n";
                    return false;
                }

                AccessGrid vout(first_row * 2 + 1, first_col * 2 + 1, second_row * 2 + 1, second_col * 2 + 1);
                _vout.push_back(vout);
            }
            else
            {
                std::cerr << "Invalid number format​.\n";
                return false;
            }
        }

        return true;
    }

    bool check_third_line(const std::string& _strin, std::vector<int>& _vstart,std::string& direction)
    {
        std::vector<std::string> command,begin_cell;
        split_string(_strin, command, " ");

        if(command.size() != 2)
        {
            std::cerr << "Incorrect command format​.\n";
            return false;
        }

        split_string(command[0],begin_cell,",");

        if(is_digits(begin_cell[0]) && is_digits(begin_cell[1]))
        {
            int row = std::atoi(begin_cell[0].c_str());
            int col = std::atoi(begin_cell[1].c_str());
            std::cout<<"startrow: "<<row<<"; startcol: "<<col<<std::endl;

            if(row < 0 || col < 0 || row > max_gridsize/2 || col > max_gridsize/2)
            {
                std::cerr << "Number out of range​.​\n";
                return false;
            }
            _vstart.push_back(row);
            _vstart.push_back(col);
        }
        else
        {
            std::cerr << "Invalid number format​.\n";
            return false;
        }
        if(command[1].empty()) return false;
        direction=command[1];
        std::cout<<"direction: "<<direction<<std::endl;
        return true;
    }



private:
    void split_string(const std::string& _strin, std::vector<std::string>& _vout, const std::string& _c)
    {
        std::string::size_type pos1, pos2;
        pos2 = _strin.find(_c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            _vout.push_back(_strin.substr(pos1, pos2-pos1));

            pos1 = pos2 + _c.size();
            pos2 = _strin.find(_c, pos1);
        }
        if(pos1 != _strin.length())
            _vout.push_back(_strin.substr(pos1));
    }

    bool is_digits(const std::string &str)
    {
        std::regex rx("(\\+|-)?[0-9]+");
        return std::regex_match(str.begin(),str.end(),rx);
    }

    std::string& replace_all(std::string& str,const std::string& old_value,const std::string& new_value)
    {
        while(true)
        {
            std::string::size_type  pos(0);
            if((pos=str.find(old_value))!=std::string::npos)
                str.replace(pos,old_value.length(),new_value);
            else
                break;
        }
        return str;
    }

private:
    static const int max_gridsize = 100;
};
}

#endif //MAZE_PARSELINE_H
