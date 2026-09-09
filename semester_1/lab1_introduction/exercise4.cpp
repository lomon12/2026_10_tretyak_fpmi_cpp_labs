#include <iostream>

int main(){
int num;
    std::cout << "Введите шестизначное натуральное число\n";
    std::cin >> num;
    int elements[6];
 
    for (int i = 0; i < 6 ; i++) {
elements[i] = num%10;
num /=10;
    }
    int sum1 = elements[0] + elements[1] + elements[2];
    int sum2 = elements[3] + elements[4] + elements[5];
    
    if (sum1 == sum2){
        std::cout << "число счастливое";
    }else
        std::cout << "число ne счастливое";
return 0;
}