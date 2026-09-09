#include <iostream>

int main(){
    int num;
    std::cout << "Введите четерхзначное натуральное число\n";
    std::cin >> num;
    int orig = num;
    int reverse = 0;
    while (num >0){
int lastnum = num%10;
reverse = reverse*10 + lastnum;
num /= 10;
    }

    if ( orig == reverse){
        std::cout << "палиндром";
    } else 
    std::cout << "не палиндром";
   return 0;
}