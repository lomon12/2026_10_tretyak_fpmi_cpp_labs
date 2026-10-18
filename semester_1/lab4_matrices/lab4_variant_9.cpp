#include <iostream>
#include <random>
#include <cstdlib>

int** AllovacateMatrix(int m, int n);
void FreeMatrix(int** Matrix, int m);
void ReadMatrix(int** Matrix, int m, int n);
void PrintMatrix(int** Matrix, int m, int n);
void FillMatrixRand(int** Matrix, int m, int n, int minValue, int maxValue);
int ChooseInputMethod();
void TryRead (int &number);
bool IsLocalMaximum(int** matrix, int i , int j);
void PrintLocalMaximum(int** matrix, int m, int n);



int main(){
    int m, n;

    std::cout << "Enter number of rows and columns: ";
    TryRead(m);
    TryRead(n);

    int** matrix = AllovacateMatrix(m, n);
    int choice = ChooseInputMethod();

    if (choice == 1) {
        std::cout << "Read Matrix:\n";
        ReadMatrix(matrix, m, n);
    } else 
    if (choice == 2) {
        int minValue, maxValue;
        std::cout << "Enter diapozon (a,b) ";

        TryRead(minValue);
        TryRead(maxValue);

        if (minValue > maxValue) {
            std::cout << "b must be bigger than a\n";
            FreeMatrix(matrix, m);
            return 1;
        }

        FillMatrixRand(matrix, m, n, minValue, maxValue);
    } else {
        std::cout << "enter 1 or 2\n";
        FreeMatrix(matrix, m);
        return 1;
    }

    std::cout << "Matrix:\n";
    PrintMatrix(matrix, m, n);
    PrintLocalMaximum(matrix, m, n);




    FreeMatrix(matrix, m);


}


int** AllovacateMatrix(int m, int n){

    int** matrix = new int*[m];

    for(int i = 0; i < m; i++){
        matrix[i] = new int[n];
    }

    return matrix;
}

void FreeMatrix(int** Matrix, int m){
    for(int i = 0; i < m; i++){
        delete[] Matrix[i];
    }
    delete[] Matrix;
}

void ReadMatrix(int** Matrix, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            TryRead(Matrix[i][j]);
        }
    }
}

void PrintMatrix(int** Matrix, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void FillMatrixRand(int** Matrix, int m, int n, int minValue, int maxValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Matrix[i][j] = dist(gen);
        }
    }
}

int ChooseInputMethod() {
    int choice;
    std::cout << "Choose input method:\n" << "1 - keyboard\n" << "2 - rand\n";
    TryRead(choice);
    return choice;
}

void TryRead (int &number){
    if(!(std::cin >> number)){
        std::cout << "pls enter number";
        std::exit(0);

    }
}

bool IsLocalMaximum(int** matrix, int i , int j){
    return matrix[i][j] > matrix[i-1][j] && matrix[i][j] > matrix[i+1][j] && matrix[i][j] > matrix[i][j-1] && matrix[i][j] > matrix[i][j+1];
}

void PrintLocalMaximum(int** matrix, int m, int n){
    bool found = false;
    std::cout << "Local maximum: ";
    for(int i = 1; i < m-1; i++){
        for(int j = 1; j < n-1; j++){
            if(IsLocalMaximum(matrix, i, j) == true){
                std::cout << matrix[i][j] << " ";
                found = true;
            }
        }
    }
    if(found == false){
        std::cout << "∅";
    }
}