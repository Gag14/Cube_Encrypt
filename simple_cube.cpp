#ifndef __SCUBE__
#define __SCUBE__
#include <iostream>
#include <string>
#include <vector>
class Cube
{
private:
    std::vector<char> cube{'$', '$', '$', '$', '$', '$', '$', '$'};
    void to_left()
    {
        char tmp = cube[0];
        cube[0] = cube[1];
        cube[1] = cube[5];
        cube[5] = cube[4];
        cube[4] = tmp;
        tmp = cube[3];
        cube[3] = cube[2];
        cube[2] = cube[6];
        cube[6] = cube[7];
        cube[7] = tmp;
    }
    void to_right()
    {
        char tmp = cube[1];
        cube[1] = cube[0];
        cube[0] = cube[4];
        cube[4] = cube[5];
        cube[5] = tmp;
    }
    void up()
    {
        char tmp = cube[1];
        cube[1] = cube[2];
        cube[2] = cube[6];
        cube[6] = cube[5];
        cube[5] = tmp;
        tmp = cube[0];
        cube[0] = cube[3];
        cube[3] = cube[7];
        cube[7] = cube[4];
        cube[4] = tmp;
    }
    void down()
    {
        char tmp = cube[2];
        cube[2] = cube[1];
        cube[1] = cube[5];
        cube[5] = cube[6];
        cube[6] = tmp;
        tmp = cube[3];
        cube[3] = cube[0];
        cube[0] = cube[4];
        cube[4] = cube[7];
        cube[7] = tmp;
    }

public:
    Cube(const std::string &word)
    {
        for (int i = 0; i < cube.size(); ++i)
        {
            word[i] ? cube[i] = word[i] : cube[i] = '$';
        }
    }
    std::string getText() { 
        std::string tmp;
        int i = 0;
        while(i < 8) {
            tmp.push_back(cube[i++]);
        }
    }
    std::string rotate(char direction, int times)
    {
        while (times > 3)
        {
            times -= 4;
        }
        std::string key;
        key.push_back(direction);
        key += std::to_string(times);
        switch (direction)
        {
        case 'L':
            for (int i = 0; i < times; ++i)
            {
                to_left();
            }
            break;
        case 'R':
            for (int i = 0; i < times; ++i)
            {
                to_right();
            }
            break;
        case 'U':
            for (int i = 0; i < times; ++i)
            {
                up();
            }
            break;
        case 'D':
            for (int i = 0; i < times; ++i)
            {
                down();
            }
            break;
        default:
            down();
            break;
        }
        return key;
    }
};
#endif