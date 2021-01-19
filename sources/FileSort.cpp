// Copyright 2020 Anastasiya Smirnova nastya.asya08@yandex.ru

#include <FileSort.hpp>
const size_t PositionOne = 8;
const size_t PositionTwo = 17;
const size_t Length = 8;
const size_t Line = 16;
const size_t ZeroPosition = 0;

FileSort::FileSort(const bf::path& ftp_p)
{
    this->ftp_path = ftp_p;

    if (bf::is_directory(ftp_path)) {
        filer(ftp_path);
        std::cout << "\n\tOverall:\n";
        if (!Brokers.empty()) {
            std::for_each(Brokers.begin(), Brokers.end(),
                    [](const auto &i) {
                for (const auto &j : i.second)
                                  std::cout << "broker: " << i.first
                                  << " account: "<< j.first
                                  << " files: "<< j.second.second
                                  << " lastdate: "<< j.second.first
                                  << std::endl;
                          });
        } else{
            std::cout << "\n!Empty!\n";
        }
    }
    this->NumBrokers = Brokers.size();
}


std::map<std::string, std::map<int, std::pair<int, int>>> FileSort::GetBrokers()
{
    return Brokers;
}

size_t FileSort::GetNumBrokers()
{
    return NumBrokers;
}
void FileSort::filer(const bf::path &path) {
    for (bf::directory_entry &x : bf::directory_iterator(path)) {
        if (bf::is_directory(x) || bf::is_symlink(x))
            filer(x.path());
        if (!bf::is_regular_file(x))
            continue;

        std::string file_name = x.path().filename().string(),
                extension = x.path().extension().string();

        if (file_name.find("balance_") != ZeroPosition)
            continue;

        if (file_name[Line] != '_')
            continue;

        if (extension != ".txt")
            continue;

        if (file_name.substr(file_name.length() - 3, 3) == "old")
            continue;

        int account;
        int date;
        try {
            account = stoi(file_name.substr(PositionOne, Length));
            date = stoi(file_name.substr(PositionTwo, Length));
        }
        catch (std::exception &e) {
            continue;
        }
        std::string broker_name = x.path().parent_path().filename().string();

        std::cout << broker_name << " " << file_name << std::endl;
        Brokers[broker_name][account].first =
                std::max(Brokers[broker_name][account].first, date);
        Brokers[broker_name][account].second++;
    }
}

    FileSort::~FileSort(){}

