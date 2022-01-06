#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;

int main(){
  int exit, number;
  int number_of_string, number_of_columns;

  cout << endl;
  cout << "---Здравствуйте! Я программа для работы с матрицами---" << endl << endl;

  cout << "Введите количество строк матрицы: " << endl;
  cin >> number_of_string;
  cout << "Введите количество столбцов матрицы: " << endl;
  cin >> number_of_columns;
  cout << "Введите элементы матрицы #1 " << endl;
  Matrix matrix_1(number_of_string, number_of_columns);
  cin >> matrix_1;
  cout << "Введите количество строк матрицы: " << endl;
  cin >> number_of_string;
  cout << "Введите количество столбцов матрицы: " << endl;
  cin >> number_of_columns;
  cout << "Введите элементы матрицы #2 " << endl;
  Matrix matrix_2(number_of_string, number_of_columns);
  cin >> matrix_2;
  cout << endl;
  cout << "---Матрицы сохранены---" << endl << endl;

  while(exit != 8){
    cout << "Выберите из списка возможного:" << endl;
    cout << "1.Сложение двух матриц(+)" << endl;
    cout << "2.Сложение двух матриц с переписыванием первой(+=)" << endl;
    cout << "3.Вычитание двух матриц" << endl;
    cout << "4.Присвоение матрицы" << endl;
    cout << "5.Поэлементное сравнение" << endl;
    cout << "6.Транспонирование" << endl;
    cout << "7.Поиск элемента" << endl;
    cout << "8.Выход" << endl;
    cout << "[USER]: ";
    cin >> exit;
    cout << endl;
    switch (exit) {
        case 1:
        {
          if(!Matrix::IsDimentionsEqual(matrix_1,matrix_2)){
            cout << "---Ошибка! Матрицы должны быть одинакового размера!---" << endl << endl;
            continue;
          }
          cout << "Результат сложения двух матриц" << endl;
          Matrix matrix_3 = matrix_1 + matrix_2;
          cout << matrix_3;
          break;
        }
        case 2:
        {
          if(!Matrix::IsDimentionsEqual(matrix_1,matrix_2)){
            cout << "---Ошибка! Матрицы должны быть одинакового размера!---" << endl << endl;
            continue;
          }
          cout << "Результат сложения двух матриц" << endl;
          matrix_1 += matrix_2;
          cout << matrix_1;
          break;
        }
        case 3:
        {
          if(!Matrix::IsDimentionsEqual(matrix_1,matrix_2)){
            cout << "---Ошибка! Матрицы должны быть одинакового размера!---" << endl << endl;
            continue;
          }
          cout << "Результат вычитания двух матриц" << endl;
          Matrix matrix_3 = matrix_1 - matrix_2;
          cout << matrix_3;
          break;
        }
        case 4:
        {
          if(!Matrix::IsDimentionsEqual(matrix_1,matrix_2)){
            cout << "---Ошибка! Матрицы должны быть одинакового размера!---" << endl << endl;
            continue;
          }
          matrix_1 = matrix_2;
          cout << "Скопированная матрица" << endl;
          cout << matrix_1;
            cout << "Матрица от которой делали копию" << endl;
          cout << matrix_1;
        }
        case 5:
        {
          if(matrix_1 == matrix_2){
            cout << "---Матрицы равны!---";
          } else {
            cout << "---Матрицы не равны!---";
          }
          cout << endl << endl;
          break;
        }
        case 6:
        {
          cout << "Выберите номер матрицы для транспонирования: " << endl;
          cout << "#1" << endl;
          cout << "#2" << endl;
          cout << "[USER]: ";
          cin >> number;
          if(number == 1){
            cout << "Транспонированная матрица #1" << endl;
            Matrix matrix_3 = !matrix_1;
            cout << matrix_3;
          } else if(number ==2){
            cout << "Транспонированная матрица #2" << endl;
            Matrix matrix_3 = !matrix_2;
            cout << matrix_3;
          }
          break;
        }
        case 7:
        {
          int string_number, column_number;
          cout << "Введите номер строки:" << endl;
          cin >> string_number;
          cout << "Введите номер столбца:" << endl;
          cin >> column_number;
          cout << "Элемент " << string_number << " строки " << column_number << " столбца " << endl;
          cout << matrix_1(string_number, column_number) << endl;
        }
      }
    }
  cout << "---Завершаю работу---" << endl << endl;

  return 0;
}
