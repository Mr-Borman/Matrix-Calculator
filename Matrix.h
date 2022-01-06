#ifndef _Matrix_
#define _Matrix_

class Matrix {
  int number_of_columns, number_of_strings;
  int **matrix_pointer;
public:
  Matrix();
  Matrix(int _number_of_strings, int _number_of_columns);
  Matrix(const Matrix &matrix_to_copy);
  ~Matrix();

  static bool IsDimentionsEqual(Matrix &matrix_1, Matrix &matrix_2);

  friend std::istream& operator >> (std::istream &in, Matrix &matrix);
  friend std::ostream& operator << (std::ostream &out, Matrix &matrix);
  friend Matrix operator + (Matrix &matrix_1, Matrix &matrix_2);
  friend Matrix operator - (Matrix &matrix_1, Matrix &matrix_2);
  Matrix operator += (Matrix &matrix);
  Matrix operator = (Matrix &matrix_to_copy);
  bool operator == (Matrix &matrix);
  Matrix operator ! ();
  double operator () (int number_of_strings, int number_of_columns);

};


#endif
