#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

void ClearStr(std::string& str);
bool IsAnagram(std::string str1, std::string str2);
bool IsEmptyFile(std::ifstream& fin);
std::vector<std::string> ReadLinesFromFile(const std::string& filename);
void WriteResultsToFile(const std::string& filename, const std::vector<std::string>& results);
std::string GetTime();
void WriteLog(std::ofstream& log, const std::string& message);

int main() {
    std::ofstream log("log.txt", std::ios::app);

    if (!log.is_open()) {
        std::cout << "Cannot open log.txt" << std::endl;
        return 1;
    }

    try {
        WriteLog(log, "Program started");
        std::vector<std::string> lines = ReadLinesFromFile("input.txt");
        WriteLog(log, "Input file successfully read");

        if (lines.size() % 2 != 0) {
            throw std::string("The number of lines must be even");
        }

        std::vector<std::string> results;

        for (size_t i = 0; i < lines.size(); i += 2) {
            if (IsAnagram(lines[i], lines[i + 1])) {
                results.push_back("Anagram");
            }
            else {
                results.push_back("Not anagram");
            }

            WriteLog(log, "Pair " + std::to_string(i / 2 + 1) + " processed");
        }

        WriteResultsToFile("output.txt", results);
        WriteLog(log, "Results successfully written to output.txt");
        WriteLog(log, "Program finished");
        std::cout << "Program completed successfully!" << std::endl;
        std::cout << "Check output.txt for results." << std::endl;
    }
    catch (const std::string& error) {
        WriteLog(log, "ERROR: " + error);
        std::cout << "Error: " << error << std::endl;
    }

    log.close();

    return 0;
}

void ClearStr(std::string& str) {
    for (size_t i = 0; i < str.size();) {
        unsigned char c = static_cast<unsigned char>(str[i]);

        if (std::ispunct(c) || std::isspace(c)) {
            str.erase(i, 1);
        }
        else {
            str[i] = static_cast<char>(std::tolower(c));
            i++;
        }
    }
}

bool IsAnagram(std::string str1, std::string str2) {
    ClearStr(str1);
    ClearStr(str2);

    if (str1.size() != str2.size()) {
        return false;
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}

bool IsEmptyFile(std::ifstream& fin) {
    return fin.peek() == std::ifstream::traits_type::eof();
}

std::vector<std::string> ReadLinesFromFile(const std::string& filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        throw std::string("Cannot open file: ") + filename;
    }

    if (IsEmptyFile(fin)) {
        throw std::string("File is empty: ") + filename;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(fin, line)) {
        lines.push_back(line);
    }

    fin.close();

    return lines;
}

void WriteResultsToFile(const std::string& filename, const std::vector<std::string>& results) {
    std::ofstream fout(filename);

    if (!fout.is_open()) {
        throw std::string("Cannot open file: ") + filename;
    }

    for (const std::string& result : results) {
        fout << result << '\n';
    }

    fout.close();
}

std::string GetTime() {
    auto now = std::chrono::system_clock::now();

    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&time);

    std::ostringstream result;
    result << std::put_time(localTime, "%d.%m.%Y %H:%M:%S");

    return result.str();
}

void WriteLog(std::ofstream& log, const std::string& message) {
    log << GetTime() << " | " << message << '\n';
}
