#include <iostream> 
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

void ClearStr (std::string &str);
void IsAnagram (std::string str1, std::string str2);
std::string ReadString();




int main(){
    
    std::string str1 = ReadString();
    std::string str2 = ReadString();
    ClearStr(str1);
    ClearStr(str2);
    //std::cout << str1 << "\n" << str2 << "\n";
    IsAnagram(str1, str2);


    return 0;
}


void ClearStr(std::string& str) {
    for (size_t i = 0; i < str.size();) {
        unsigned char c = static_cast<unsigned char>(str[i]);
        if (std::ispunct(c) || std::isspace(c)) {
            str.erase(i, 1);
        } else {
            str[i] = static_cast<char>(std::tolower(c));
            i++;
        }
    }
}


void IsAnagram (std::string str1, std::string str2){
    
    if(str1.size() != str2.size()){
        std::cout << " \n not anagram";
        return;
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    for(size_t i = 0; i < str1.size(); i++){
        if(str1[i] != str2[i]){
            std::cout << "not anagram";
            return;
        }
    }
    std::cout << "\n anagram";
}

std::string ReadString(){
    std::string str;
    getline(std::cin , str);
    return str;
}