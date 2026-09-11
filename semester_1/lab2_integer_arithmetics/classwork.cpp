#include <iostream>
#include <cmath>
#include <iomanip>

int main (){
int n = 8;
double cos = std::pow (10,-n);
double x ;

double res = 0.0;
double a_n = 1.0;
int k = 1;
std::cout << "введите x \n";
std::cin >> x;
double z = 7*x;
z =std::fmod(z,2*M_PI);

while(std::fabs(a_n) >= cos){
res +=a_n;
    a_n = -a_n * (z * z) / ((2 * k - 1) * (2 * k));
k++;
}
std::cout << std::setprecision(14);
std::cout << "my cos " << res << "\n";
std::cout << "stdcos " << std::cos(z) << " \n";

return 0;
}


