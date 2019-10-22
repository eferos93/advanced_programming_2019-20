#include <iostream>
#include <utility>
#include <array>

template <typename T>
void transpose(std::array<T, 4>& matrix, const unsigned int row, const unsigned int col);

int main()
{
    unsigned int row = 2;
    unsigned int col = 2;
    std::cout << "Inserisci il numero di righe: ";
    std::cin >> row;
    std::cout << "Inserisci il numero di colonne: ";
    std::cin >> col;
    std::array<double, 4> matrix{1,2,3,4};
}

template <typename T>
void transpose(std::array<T, 4>& matrix, const unsigned int row, const unsigned int col)
{
    
}