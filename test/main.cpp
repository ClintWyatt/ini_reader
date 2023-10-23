#include <gtest/gtest.h>
#include "ini_reader.h"

TEST(IniReader, parse_ini_file)
{
    std::string ini_file = "config/test1.ini";
    IniReader ini_reader(ini_file);
    ASSERT_NE(ini_reader.get_data("entry1", "string").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry1", "string"), "string1");
    ASSERT_NE(ini_reader.get_data("entry1", "int").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry1", "nope").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entryy", "int").length(), 0);

    //entry 2
    ASSERT_NE(ini_reader.get_data("entry2", "string").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry2", "string"), "string2");
    ASSERT_NE(ini_reader.get_data("entry2", "int").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry2", "nope").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entryy", "int").length(), 0);

    //entry 3
    ASSERT_NE(ini_reader.get_data("entry3", "string").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry3", "string"), "string3");
    ASSERT_NE(ini_reader.get_data("entry3", "int").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry3", "nope").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entryy", "int").length(), 0);
}

TEST(IniReader, validate_data)
{
    std::string ini_file = "config/test1.ini";
    IniReader ini_reader(ini_file);
    std::string string_entry = ini_reader.get_ini_data_str<std::string>("entry1", "string").substr();
    ASSERT_EQ(ini_reader.get_ini_data<int>("entry1", "int"), 1);
    ASSERT_EQ(ini_reader.get_ini_data<double>("entry1", "double"), 1.0);
    ASSERT_EQ(ini_reader.get_ini_data<bool>("entry1", "bool"), true);
    ASSERT_EQ(string_entry, "string1");

    string_entry = ini_reader.get_ini_data_str<std::string>("entry2", "string").substr();
    ASSERT_EQ(ini_reader.get_ini_data<int>("entry2", "int"), 2);
    ASSERT_EQ(ini_reader.get_ini_data<double>("entry2", "double"), 2.0);
    ASSERT_EQ(ini_reader.get_ini_data<bool>("entry2", "bool"), false);
    ASSERT_EQ(string_entry, "string2");

    string_entry = ini_reader.get_ini_data_str<std::string>("entry3", "string").substr();
    ASSERT_EQ(ini_reader.get_ini_data<int>("entry3", "int"), 3);
    ASSERT_EQ(ini_reader.get_ini_data<double>("entry3", "double"), 3.0);
    ASSERT_EQ(ini_reader.get_ini_data<bool>("entry3", "bool"), false);
    ASSERT_EQ(string_entry, "string3");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
