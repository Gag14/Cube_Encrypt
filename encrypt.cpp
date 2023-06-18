#ifndef __Encrypt__
#define __Encrypt__
#include <iostream>
#include <string>
#include <vector>
#include "simple_cube.cpp"
#include "key.cpp"
class Encrypt
{
private:
    std::string text;
    std::vector<Key> keys;
    std::vector<Cube> cubes;

public:
    Encrypt(const std::string &inputText) : text{inputText} {}
    std::string &getEncryptedText() {}
    std::string &encryptText(const std::string &inputText) {}
    bool setKey(const std::string &givenKey) {}
    const std::string &getKey() {}

private:
    void textToCubes()
    {
        int j = 0;
        std::string cubeText{'$', '$', '$', '$', '$', '$', '$', '$'};
        for (int i = 0; i < text.size(); ++i)
        {
            if (j == 7)
            {
                cubes.push_back(Cube(cubeText));
                for (char c : cubeText)
                {
                    c = '$';
                }
            }
            cubeText[j++] = text[i];
        }
    }
    bool isvalidKey(const std::string &inputKey)
    {
        if (inputKey.size() < 2)
        {
            return 0;
        }
        for (int i = 0; i < inputKey.size(); ++i)
        {
            if (!((i + 1) % 3) && inputKey[i] == ':')
            {
                if (inputKey[i - 1] != 'L' && inputKey[i - 1] != 'R' && inputKey[i - 1] != 'U' && inputKey[i - 1] != 'D')
                {
                    return 0;
                }
                if (inputKey[i + 1] < '0' || inputKey[i + 1] > '9')
                {
                    return 0;
                }
            }
            else if (inputKey[i] != ':')
            {
                return 0;
            }
        }
        return 1;
    }
    bool parseToKeys(const std::string &suggestedKey)
    {
        if (isvalidKey(suggestedKey))
        {
            for (int i = 0; i < suggestedKey.size(); ++i)
            {
                if (!((i + 1) % 3))
                {
                    ++i;
                }
                keys.push_back(Key(suggestedKey[i], (int)(suggestedKey[i + 1] - '0')));
            }
        }
        else if (!isvalidKey(suggestedKey))
        {
            return 0;
        }
        return 1;
    }
    std::string encryptTheText(const std::string &suggestedKey)
    {
        textToCubes();
        if (parseToKeys(suggestedKey))
        {
            int j = 0;
            for (int i = 0; i < cubes.size(); ++i)
            {
                if (j == cubes.size())
                {
                    j = 0;
                }
                cubes[i].rotate(keys[j].direction, keys[j].times);
                ++j;
            }
        }
        std::string encryptedText;
        for (auto cube : cubes)
        {
            encryptedText += (cube.getText());
        }
        return encryptedText;
    }
};
#endif