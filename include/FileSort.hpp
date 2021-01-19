// Copyright 2020 Anastasiya Smirnova nastya.asya08@yandex.ru


#ifndef INCLUDE_FILESORT_HPP_
#define INCLUDE_FILESORT_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <exception>
#include <boost/filesystem.hpp>
#include <utility>

#define bf boost::filesystem

class FileSort
{
    private:
    bf::path ftp_path;
    std::map<std::string, std::map<int, std::pair<int, int>>> Brokers;
    size_t NumBrokers;
    public:
    explicit FileSort(const bf::path& ftp_path);
    std::map<std::string, std::map<int, std::pair<int, int>>> GetBrokers();
    size_t GetNumBrokers();
    void filer(const bf::path &path);
    ~FileSort();
};


#endif // INCLUDE_FILESORT_HPP_
