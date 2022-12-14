#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "../kernel/shell.cpp"
#include "../kernel/drivers/tty.cpp"
#include "../kernel/drivers/keyboard.cpp"
#include "../kernel/common.cpp"
#include "../libc/string/string.cpp"
#include "../kernel/drivers/kb.cpp"



TEST(StringTest, StringLength) {
  
  char ch[] = "Hello";
  int len = str_length(ch);
  EXPECT_EQ(len, 5);
  EXPECT_NE(len, 6);
}

TEST(StringTest, StringRevers) {
  char ch[] = "Hello";
  reverse(ch);
  std::string str(ch);
  std::cout << str << std::endl;
  EXPECT_EQ("olleH", str);
  EXPECT_NE("olleHH", str);
}
