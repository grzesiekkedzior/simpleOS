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

TEST(StringCmp, StringCmp) {
  char ch[] = "Hello";
  char ch2[] = "Hello";
  string s;
  EXPECT_EQ(0, s.strcmp(ch, ch2));
}

TEST(ShellTest, ShellCommandChecker) {
  char *ch = "calendar";
  shell sh;
  int b = sh.is_command(ch);
  EXPECT_EQ(1, b);
  EXPECT_NE(0, b);
}

TEST(ShellTestProcess, ShellProcessChecker) {
  char *ch = "calendar";
  shell sh;
  int b = sh.start_process(ch);
  EXPECT_EQ(1, b);
  EXPECT_NE(0, b);
}