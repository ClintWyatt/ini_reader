#include "ini_reader.h"
#include <fstream>
#include <string>
#include <iostream>

IniReader::IniReader(const std::string& ini_file)
{

}

bool IniReader::read_ini_file(const std::string& ini_file)
{
    std::string line;
    std::ifstream input_file(ini_file);

    if (input_file.is_open())
    {
        while (getline(input_file,line))
        {
            std::cout << line << std::endl;
        }
    }
    return true;
}
