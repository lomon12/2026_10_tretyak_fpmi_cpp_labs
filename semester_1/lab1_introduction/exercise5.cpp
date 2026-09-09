#include <iostream>

int main(){
    int n, next;
    int f = 0;
    int s = 1;
    std::cout << "сколько чисел фибоначи вы хотите вывести\n";
    std::cin >> n;
    for (int i = 0 ; i <n ; i++){
        std::cout << f << " ";
        next = f+s;
        f = s;
        s = next;
    }
    return 0;
}