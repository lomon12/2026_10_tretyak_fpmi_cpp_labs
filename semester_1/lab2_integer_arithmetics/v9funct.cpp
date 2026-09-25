#include <iostream>

bool IsPalindrom (int n);
    

int main(){
    int a,b;
    std::cout << "Введите диапоз [a,b] на котором вы хотите найти все палиндромы\n";
    if (!(std::cin >> a >> b)){
        
        std::cout << "Введите пожалуйста число, а не слово " << std::endl;
    }else

    if (a <= 0 || b <= 0 || b <= a) {
        std::cout << "a и b должны быть больше нуля . a должно быть меньше b" << std::endl;
        
    }else

    for( int i = a; i <= b ; i++ ){
        if(IsPalindrom(i)){
            std::cout << i << " " ;
        }
    }

    return 0;
}



bool IsPalindrom (int n){

        int orig = n;
        int temp = n ;
        int reverse = 0;

        while (temp >0){
            int lastnum = temp % 10;
            reverse = reverse * 10 + lastnum;
            temp /= 10;
        }
        return orig == reverse;
    }
