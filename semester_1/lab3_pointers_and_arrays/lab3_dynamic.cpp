#include <iostream>
#include <random>
#include <cstdlib>
//variant10
// 2 версии программы, можно раскоментить код и получить создание массива вручную а не рандомом

void TryRead (int &arr_lenght);
bool IsNormal (int &number);
void ReadArray(int* arr, size_t size);
void PrintArray(int* arr, size_t size);
void Compress (int* arr, size_t size);
bool EvenOrNot (int* arr, int elementnum);
void FillArrayRand (int* arr, size_t size, std::mt19937* gen, int min = -10000, int max = 10000);


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    int arr_lenght;
    std::cout << "enter the lenght of array \n"; 
    IsNormal(arr_lenght);
    int* arr = new int[arr_lenght];
    //std::cout << "enter your array \n"; 
    //ReadArray(arr, arr_lenght);
    FillArrayRand(arr,arr_lenght,&gen);
    PrintArray(arr, arr_lenght);
    Compress(arr, arr_lenght);
    PrintArray(arr, arr_lenght);
    delete[] arr;

    return 0;
}


void TryRead (int &arr_lenght){
    if(!(std::cin >> arr_lenght)){
        std::cout << "pls enter number";
        std::exit(0);
    }
}

bool IsNormal(int &number){
    TryRead(number);
    if (number <= 0){
        std::cout << "enter possitive number";
        std::exit(0);
    }
    return true;
}

void ReadArray(int* arr, size_t size){
    for(int i = 0; i < size; i++){
        TryRead(arr[i]); 
    }
}

void PrintArray(int* arr, size_t size) {
    std::cout << "\nYour array:\n";
    for (size_t  i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void FillArrayRand (int* arr, size_t size, std::mt19937* gen, int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    for (size_t i = 0; i < size; i++) {
        arr[i] = dist(*gen); 
    }
}
bool EvenOrNot (int* arr, int elementnum){
    int sum = 0; 
    int element = abs(arr[elementnum]);

    while (element != 0){
        sum += element % 2;
        element /=2;
    }
    return(sum % 2 == 0);
}

void Compress (int* arr, size_t size){
    int j = 0;
    for (int i = 0 ; i < size; i++){
        if(EvenOrNot(arr,i) == true){
            arr[j] = arr[i];
            j++;
        }
    }
    for (int i = j; i < size; i++){
        arr[i] = 0;
    }
}
