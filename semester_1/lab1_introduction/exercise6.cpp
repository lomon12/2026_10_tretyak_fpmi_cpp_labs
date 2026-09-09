#include <iostream>

int main(){
    int a1,b,d;
    
    std::cout << "введите промежуток [a,b]\n" ;
    std::cin >> a1 >> b;
    std::cout << "введите разность прогрессии\n" ;
    std::cin >> d;

    for ( int An = a1 ; An <= b; An +=d){
        if (An%3 == 0) {
            std::cout << An << " ";
        } 
    }

    return 0;

}



