#include <iostream>

int main(){
    std::cout << "Ведите кол-во нечетных чисел сумму которых вы хотите посчитать\n" ;
    int count;
    int sum;
    std::cin >> count;
    sum = count*count;
    std::cout << "Сумма чисел :" << sum;
}