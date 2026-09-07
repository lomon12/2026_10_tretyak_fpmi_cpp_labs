#include <iostream>
int main (){
    int n,m ;
std::cout << "введите два числа натуральных числа для нахождения общих делителей\n";
std::cin >> n >> m;
if ( n<=0 || m<= 0){
    std::cout << "Введите положительное число ";
    return 0;
}else
std:: cout << "1" << " " ;

for( int i = 2; i <= std::min(n,m); i++ ){
    if ( n%i == 0 && m%i == 0 ){
std::cout << i << " ";
    }
}
return 0;
}