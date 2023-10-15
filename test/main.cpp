#include <gtest/gtest.h>
#include "ini_reader.h"

TEST(IniReader, parse_ini_file)
{
    std::string ini_file = "config/test1.ini";
    IniReader ini_reader(ini_file);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
