// Copyright 2020 Anastasiya Smirnova nastya.asya08@yandex.ru

#include <gtest/gtest.h>
#include <header.hpp>

TEST(Example, EmptyTest) {
  std::string ftp_path = "../";
  fillup(ftp_path);
  EXPECT_EQ(brokers.size(), 3);
}
