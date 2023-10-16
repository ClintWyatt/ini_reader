#ifndef H_INI_READER
#define H_INI_READER

#include<string>
#include<utility>
#include<unordered_map>

class IniReader
{

public:

    IniReader(const std::string& ini_file);

    /**
     *@brief - method prints the ini data
     *@param key - key for the ini data
     *@return none
     */
    std::string get_data(const std::string& key, const std::string& data_field);

private:

    /**
     *@brief - method attempts to read the ini file
     *@param ini_file - ini file
     *@return true on success, false on failure
     */
    bool read_ini_file(const std::string& ini_file);

    /**
     *@brief - method adds the ini data to the hash map
     *@param key - key for the ini data
     *@param data - ini data
     *@return none
     */
    void add_ini_data(const std::string& key, const std::string& data);

std::unordered_map<std::string, std::unordered_map <std::string, std::string>> ini_data_;


};

#endif
