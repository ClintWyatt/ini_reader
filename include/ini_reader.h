#ifndef H_INI_READER
#define H_INI_READER

#include<string>
#include<utility>
#include<unordered_map>
#include<concepts>
#include<type_traits>
#include<string_view>
#include<iostream>

template<typename T>
concept IniData = std::integral<T> || std::floating_point<T> || 
    std::convertible_to<T, bool>;

template<typename T>
concept IniString = std::same_as<T, std::string>; 

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

    template <typename T>
    requires IniData<T> 
    T get_ini_data(const std::string& key, const std::string& data_field)
    {
        T data_type;
        std::string data = get_data(key, data_field);
        if (std::is_same<T, bool>::value)
        {
            if (data == "True" || data == "true")
                data_type = true;
            else
                data_type = false;
        }
        else if (std::is_same<T, int>::value)
        {
            data_type = std::stoi(data);
        }
        else if (std::is_same<T, double>::value)
        {
            data_type = std::stod(data);
        }
        return data_type;
    }

    template <typename T>
    requires IniString<T>
    T get_ini_data_str(const std::string& key, const std::string& data_field)
    {
        T data_type;
        std::cout << get_data(key, data_field) << std::endl;
        data_type = get_data(key, data_field);
        return data_type;
    }
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
