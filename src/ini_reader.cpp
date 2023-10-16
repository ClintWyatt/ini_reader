#include "ini_reader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <utility>
#include <regex>

IniReader::IniReader(const std::string& ini_file)
{
    read_ini_file(ini_file);
}

bool IniReader::read_ini_file(const std::string& ini_file)
{
    std::string line;
    std::string current_key = "";
    std::ifstream input_file(ini_file);

    if (input_file.is_open())
    {
        while (getline(input_file,line))
        {
            if (line.length() > 0)
            {
                if (line[0] == '[' && line[line.length() - 1] == ']')
                {
                    line.erase(0, 1);
                    line.erase(line.length() - 1, 1);
                    current_key = line;
                }
                else
                {
                    add_ini_data(current_key, line);
                }
            }
        }
    }
    else
    {
        std::cout << "Failed to open ini file!" << std::endl;
        return false;
    }
    return true;
}

void IniReader::add_ini_data(const std::string& key, const std::string& data)
{
    std::regex pattern("[ ]*[=][ ]*");
    std::string pruned_data = std::regex_replace(data, pattern, "|");
    //std::cout << "replace string: " << pruned_data << std::endl;

    std::string::size_type data_mark = pruned_data.find('|');
    if (std::string::npos == data_mark)
        std::cout << "Failed to insert the following data: " << data << std::endl;
    else
    {
        std::string data_key(pruned_data, 0, data_mark);
        std::string data_entry(pruned_data, data_mark + 1, pruned_data.length() - 1);
        ini_data_[key][data_key] = data_entry;
    }
}

std::string IniReader::get_data(const std::string& key, const std::string& data_field)
{

    auto find_key = ini_data_.find(key);
    if (find_key != ini_data_.end())
    {
        std::cout << "Found key " << key << std::endl;
        if (find_key->second.find(data_field) != find_key->second.end())
        {
            std::cout << ini_data_[key][data_field] << std::endl;
        }
        else
            std::cout << "entry " << data_field << " does not exist" << std::endl;
    }
    else
        std::cout << "failed to find key "<< key << std::endl;
    return "0";
}
