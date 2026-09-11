#include <iostream>

int main(){
    int a,b;
    int orig;
    std::cout << "Введите диапоз [a,b] на котором вы хотите найти все палиндромы\n";
    if (!(std::cin >> a >> b)){
        
        std::cout << "Введите пожалуйста число, а не слово " << std::endl;
    }else

    if (a <= 0 || b <= 0 || b <= a) {
        std::cout << "a и b должны быть больше нуля . a должно быть меньше b" << std::endl;
        
    }else

    for( int i = a; i <= b ; i++ ){
        orig = i;
        int temp = i;
        int reverse = 0;

        while (temp >0){
            int lastnum = temp % 10;
            reverse = reverse * 10 + lastnum;
            temp /= 10;
        }

        if ( orig == reverse){
            std::cout << orig << " ";
        }else;
    }





    return 0;
}
//