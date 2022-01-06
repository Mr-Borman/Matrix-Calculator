#include "Matrix.h"

Matrix::Matrix(){
  number_of_strings = 1;
  number_of_columns = 1;

  matrix_pointer = new int* [number_of_strings];
  for(int i = 0; i < number_of_strings; ++i){
    matrix_pointer[i] = new int[number_of_columns];
  }

  for(int i = 0; i < number_of_strings; ++i){
    for(int j = 0; j < number_of_columns; ++j){
      matrix_pointer[i][j] = 0;
    }
  }

}

Matrix::Matrix(int _number_of_strings, int _number_of_columns){
  number_of_strings = _number_of_strings;
  number_of_columns = _number_of_columns;

  matrix_pointer = new int* [number_of_strings];
  for(int i = 0; i< number_of_strings; ++i){
    matrix_pointer[i] = new int[number_of_columns];
  }

  for(int i = 0; i < number_of_strings; ++i){
    for(int j = 0; j < number_of_columns; ++j){
      matrix_pointer[i][j] = 0;
    }
  }
}

Matrix::Matrix(const Matrix &matrix_to_copy){
  number_of_strings = matrix_to_copy.number_of_strings;
  number_of_columns = matrix_to_copy.number_of_columns;

  matrix_pointer = new int* [number_of_strings];
  for(int i = 0; i< number_of_strings; ++i){
    matrix_pointer[i] = new int[number_of_columns];
  }

  for(int i = 0; i < number_of_strings; ++i){
    for(int j = 0; j < number_of_columns; ++j){
      matrix_pointer[i][j] = matrix_to_copy.matrix_pointer[i][j];
    }
  }
}

Matrix::~Matrix(){
  for(int i = 0; i< number_of_strings; ++i){
    delete matrix_pointer[i];
  }
  delete [] matrix_pointer;
}

std::istream& operator >> (std::istream &in, Matrix &matrix){
  for(int i = 0; i < matrix.number_of_strings; ++i){
    for(int j = 0; j < matrix.number_of_columns; ++j){
      in >> matrix.matrix_pointer[i][j];
    }
  }
  return in;
}

std::ostream& operator << (std::ostream &out, Matrix &matrix){
  for(int i = 0; i < matrix.number_of_strings; ++i){
    for(int j = 0; j < matrix.number_of_columns; ++j){
      out << matrix.matrix_pointer[i][j] << " ";
    }
    out << std::endl;
  }
  out << std::endl;
  return out;
}

bool Matrix::IsDimentionsEqual(Matrix &matrix_1, Matrix &matrix_2)
{
  if(matrix_1.number_of_strings == matrix_2.number_of_strings && matrix_1.number_of_columns == matrix_2.number_of_columns)
  return 1;
  return 0;
}

Matrix operator + (Matrix &matrix_1, Matrix &matrix_2){
  if (!(Matrix::IsDimentionsEqual(matrix_1, matrix_2)))
  {
    std::cout << "Ошибка! Матрицы разного размера!" << std::endl;
    return Matrix(0,0);
  }
  Matrix matrix_3(matrix_1.number_of_strings, matrix_2.number_of_columns);
  for(int i = 0; i < matrix_1.number_of_strings; ++i){
    for(int j = 0; j < matrix_1.number_of_columns; ++j){
      matrix_3.matrix_pointer[i][j] = matrix_1.matrix_pointer[i][j] + matrix_2.matrix_pointer[i][j];
    }
  }
  return matrix_3;
}

Matrix operator - (Matrix &matrix_1, Matrix &matrix_2){
  if (!(Matrix::IsDimentionsEqual(matrix_1, matrix_2)))
  {
    std::cout << "Ошибка! Матрицы разного размера!" << std::endl;
    return Matrix(0,0);
  }
  Matrix matrix_3(matrix_1.number_of_strings, matrix_2.number_of_columns);
  for(int i = 0; i < matrix_1.number_of_strings; ++i){
    for(int j = 0; j < matrix_1.number_of_columns; ++j){
      matrix_3.matrix_pointer[i][j] = matrix_1.matrix_pointer[i][j] - matrix_2.matrix_pointer[i][j];
    }
  }
  return matrix_3;
}

Matrix Matrix::operator += (Matrix &matrix){
  if (!(Matrix::IsDimentionsEqual(*this, matrix)))
  {
    std::cout << "Ошибка! Матрицы разного размера!" << std::endl;
    return *this;
  }
  for(int i = 0; i < matrix.number_of_strings; ++i){
    for(int j = 0; j < matrix.number_of_columns; ++j){
      this -> matrix_pointer[i][j] += matrix.matrix_pointer[i][j];
    }
  }
  return *this;
}

Matrix Matrix::operator = (Matrix &matrix_to_copy){
  if (!(Matrix::IsDimentionsEqual(*this, matrix_to_copy)))
  {
    std::cout << "Ошибка! Матрицы разного размера!" << std::endl;
    return *this;
  }
  for(int i = 0; i < matrix_to_copy.number_of_strings; ++i){
    for(int j = 0; j < matrix_to_copy.number_of_columns; ++j){
      this -> matrix_pointer[i][j] = matrix_to_copy.matrix_pointer[i][j];
    }
  }
  return *this;
}

bool Matrix::operator == (Matrix &matrix){
  if (!(Matrix::IsDimentionsEqual(*this, matrix)))
  {
    return false;
  }
  for(int i = 0; i < matrix.number_of_strings; ++i){
    for(int j = 0; j < matrix.number_of_columns; ++j){
      if(matrix_pointer[i][j] != matrix.matrix_pointer[i][j]) return false;
    }
  }

  return true;
}

Matrix Matrix::operator ! (){
  Matrix matrix(this -> number_of_columns, this -> number_of_strings);
  for(int i = 0; i < this -> number_of_strings; ++i){
    for(int j = 0; j < this -> number_of_columns; ++j){
      matrix.matrix_pointer[j][i] = this -> matrix_pointer[i][j];
    }
  }

  return matrix;
}

double Matrix::operator () (int string_number, int column_number){
  if(string_number < 0 || string_number > this -> number_of_strings){
  if(column_number < 0 || column_number > this -> number_of_columns)
    {
      std::cout << "Ошибка! Выход за пределы матрицы!" << std::endl;
      return 0;
    }
  }
  return this->matrix_pointer[string_number - 1][column_number - 1];
}
