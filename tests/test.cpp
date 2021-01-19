// Copyright 2020 Anastasiya Smirnova nastya.asya08@yandex.ru

#include <gtest/gtest.h>
#include "FileSort.hpp"


TEST(Example, EmptyTest) {
    bf::path ftp_path = "../";
    FileSort A(ftp_path);
    EXPECT_EQ(A.GetNumBrokers(), 3);
    int x = 0;
    std::map<std::string, std::map<int, std::pair<int, int>>>
            Brokers = A.GetBrokers();
    std::for_each(Brokers.begin(), Brokers.end(), [&x](auto i) {
        std::string name = i.first;
        if (x == 0) {
            EXPECT_EQ(name, "bcs");
        }
        if (x == 1) {
            EXPECT_EQ(name, "ib");
        }
        if (x == 2) {
            EXPECT_EQ(name, "otkritie");
        }
        x++;
    });
}
