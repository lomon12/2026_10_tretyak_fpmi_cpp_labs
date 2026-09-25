#include <iostream>
//variant9
const size_t MAX_LENGHT = 100000;

void TryRead (int &arr_lenght);
bool IsNormal (int &number);
void ReadArray(int* arr, size_t size);
void ArrayMix(int* arr, size_t size);
void PrintArray(int* arr, size_t size);


int main() {
    int arr_lenght;
    int arr[MAX_LENGHT];
    std::cout << "enter the lenght of array \n"; 
    IsNormal(arr_lenght);
    std::cout << "enter your array \n"; 
    ReadArray(arr, arr_lenght);
    ArrayMix(arr,arr_lenght);
    PrintArray(arr, arr_lenght);




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

void ArrayMix(int* arr, size_t size){
    int result[size];
    int k = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < 0 ){
            result[k] = arr[i];
            k++;
        }
    }

    for(int i = 0; i < size; i++){
        if(arr[i] > 0 ){
            result[k] = arr[i];
            k++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = result[i];
    }
}

void PrintArray(int* arr, size_t size) {
    std::cout << "\nYour array:\n";
    for (size_t  i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}