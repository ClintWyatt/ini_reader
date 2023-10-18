#include <gtest/gtest.h>
#include "ini_reader.h"

TEST(IniReader, parse_ini_file)
{
    std::string ini_file = "config/test1.ini";
    IniReader ini_reader(ini_file);
    ASSERT_NE(ini_reader.get_data("entry1", "string").length(), 0);
    ASSERT_NE(ini_reader.get_data("entry1", "int").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entry1", "nope").length(), 0);
    ASSERT_EQ(ini_reader.get_data("entryy", "int").length(), 0);
}

TEST(IniReader, validate_data)
{
    std::string ini_file = "config/test1.ini";
    IniReader ini_reader(ini_file);
    ASSERT_EQ(ini_reader.get_ini_data<int>("entry1", "int"), 1);
    ASSERT_EQ(ini_reader.get_ini_data<double>("entry1", "double"), 1.0);
    ASSERT_EQ(ini_reader.get_ini_data<bool>("entry1", "bool"), true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
