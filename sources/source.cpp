// Copyright 2020 Anastasiya Smirnova nastya.asya08@yandex.ru

#include <FileSort.hpp>

int main(int argc, char *argv[]) {
    bf::path ftp_path;
    if (argc < 2)
        ftp_path = "../";
    else
        ftp_path = std::string(argv[1]);

 FileSort A(ftp_path);
 std::cout<< A.GetBrokers().size();
    return 0;
}
