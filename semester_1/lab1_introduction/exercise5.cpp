#include <iostream>

int main(){
    int n;
    int f = 0, s = 0,next;
    std::cout << "сколько чисел фибоначи вы хотите вывести\n";
    std::cin >> n;
    for (int i = 0 ; i <=n ; i++){
        if( n == f){
            std::cout<< f; 
        }else
        if (n == s){
            std::cout<< s; 
        }
        next = f+s;
        f = s;
        s = next;
        std::cout << next;
    }
    return 0;
}