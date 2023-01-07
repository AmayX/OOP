#include <iostream>
using namespace std;

class ThrowError
{
private:
int ErrorCode;
string Description;
public:
ThrowError(int code, string desc)
{
  ErrorCode=code;
  Description=desc;
}
void DisplayError()
{
  cout<<"Following exception was caught while performing an operation!\n";
  cout<<"Error Code: "<<ErrorCode;
  cout<<"\nDescription: "<<Description;
}
};

class matrix 
{
private:
int r,c,mat[5][5];
static int mat_count;
public:
void read();
void display();
inline friend bool check(matrix m1, matrix m2);
matrix operator + (const matrix &m);
matrix operator - (const matrix &m);
matrix operator * (const matrix &m);
};

int matrix::mat_count=0;

inline bool check(matrix m1, matrix m2)
{
  return (m1.r==m2.r && m1.c==m2.c);
}

void matrix::read()
{
  try {
    cout<<"Enter the number of rows and columns: ";
    cin>>r>>c;
    if (r>5 || c>5)
    {
      throw ThrowError(1,"The number of rows and columns of the matrix cannot be greater than 5!\n");
    }
    cout<<"Enter the elements for matrix "<< ++mat_count <<":\n";
      for (int i=0;i<r;i++)
    {
      for (int j=0;j<c;j++)
        {
          cout<<"Enter element "<<"("<<i+1<<","<<j+1<<"): ";
          cin>>mat[i][j];
        }
    }
  }
  catch (ThrowError temp)
    {
      temp.DisplayError();
    }
}

void matrix::display()
{
  for (int i=0;i<r;i++)
    {
      for (int j=0;j<c;j++)
        {
          cout<<mat[i][j]<<" ";
        }
      cout<<"\n";
    }
}

matrix matrix::operator + (const matrix &m)
{
  matrix res;
  try {
    if (check(*this, m))
    {
      res.c=m.c;
      res.r=m.r;
    for (int i=0;i<r;i++)
      {
        for (int j=0;j<c;j++)
          {
            res.mat[i][j]=0;
            res.mat[i][j]=mat[i][j]+m.mat[i][j];
          }
        }
    }
    else
    {
      throw ThrowError(2, "The dimensions of the matrices to be added, should be same!\n");
    }
  }
  catch(ThrowError temp)
    {
      temp.DisplayError();
    }
  return res;
}


matrix matrix::operator - (const matrix &m)
{
  matrix res;
  try {
    if (check(*this, m))
    {
      res.c=m.c;
      res.r=m.r;
    for (int i=0;i<r;i++)
      {
        for (int j=0;j<c;j++)
          {
            res.mat[i][j]=0;
            res.mat[i][j]=mat[i][j]-m.mat[i][j];
          }
      }
    }
    else
    {
      throw ThrowError(3, "The dimensions of the matrices to be subtracted, should be same!\n");
    }
  }
  catch(ThrowError temp)
    {
      temp.DisplayError();
    }
  return res;
}

matrix matrix::operator * (const matrix &m)
{
  matrix res;
  try {
    if (c==m.r)
    {
      res.c=m.c;
      res.r=m.r;
      for(int i=0; i<r; ++i)
        for(int j=0; j<m.c; ++j)
            {
                res.mat[i][j]=0;
              for(int k=0; k<c; ++k)
            {
                res.mat[i][j]+=mat[i][k]*m.mat[k][j];
            }
         }
    }
    else
    {
      throw ThrowError(4,"The number of columns of the first matrix should be equal to the number of rows of the second matrix!\n");
    }
  }
  catch (ThrowError temp)
    {
      temp.DisplayError();
    }
  return res;
}

int main() {
  matrix m1,m2,m3;
  m1.read();
  cout<<"1st Matrix:\n";
  m1.display();
  m2.read();
  cout<<"2nd Matrix:\n";
  m2.display();
  cout<<"Addition:\n";
  (m1+m2).display();
  cout<<"Subtraction:\n";
  (m1-m2).display();
  cout<<"Multiplication:\n";
  (m1*m2).display();
}