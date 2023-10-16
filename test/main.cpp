#include <gtest/gtest.h>
#include "ini_reader.h"

TEST(IniReader, parse_ini_file)
{
    std::string ini_file = "config/test1.ini";
    IniReader ini_reader(ini_file);
    ini_reader.get_data("entry1", "string");
    ini_reader.get_data("entry1", "nope");
    ini_reader.get_data("entryy", "nope");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
