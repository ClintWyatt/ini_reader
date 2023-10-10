#ifndef H_INI_READER
#define H_INI_READER

#include<string>
#include<unordered_map>

class IniReader
{

public:

    IniReader(const std::string& ini_file);


private:

    /**
     *@brief - method attempts to read the ini file
     *@param ini_file - ini file
     *@return true on success, false on failure
     */
    bool read_ini_file(const std::string& ini_file);

std::unordered_map<std::string, std::unordered_map<std::string, std::string>> ini_data_;


};

#endif
