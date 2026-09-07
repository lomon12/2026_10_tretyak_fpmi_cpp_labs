#include <iostream>

int main(){
    int num;
    std::cout << "Введите четерхзначное натуральное число\n";
    std::cin >> num;
    int original = num;
    int reverse = 0;
    while (num >0){
int lastnum = num%10;
reverse = reverse*10 + lastnum;
num /= 10;
    }

    if ( original == reverse){
        std::cout << "палиндром";
    } else 
    std::cout << "не палиндром";
   
}