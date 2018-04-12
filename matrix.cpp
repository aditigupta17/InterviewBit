#include <bits/stdc++.h>
using namespace std;

class Matrix{
private:
	int A[100][100], row, col;
public:
	void getdata();
	int operator ==(Matrix);
	Matrix operator +(Matrix);
	Matrix operator -(Matrix);
	friend ostream & operator << (ostream &, Matrix &);
};

ostream & operator << (ostream &output, Matrix &m)
{
	int i, j;
	for(i=0; i<m.row; i++)
	{
		for(j=0; j<m.col; j++)
		{
			output<<m.A[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	return output;
}

void Matrix::getdata()
{
	int i, j;
	cout<<"Enter the number of rows and columns: ";
	cin>>row>>col;
	cout<<"Enter elements of the matrix:\n";
	for(i=0 ;i<row; i++)
		for(j=0; j<col; j++)
			cin>>A[i][j];
}

int Matrix::operator == (Matrix m)
{
	if(row == m.row && col == m.col) return 1;
	return 0;
}

Matrix Matrix::operator + (Matrix m)
{
	Matrix temp;
	int i, j;
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			temp.A[i][j] = A[i][j] + m.A[i][j];
	temp.row = row;
	temp.col = col;
	return temp;
}

Matrix Matrix::operator - (Matrix m)
{
	Matrix temp;
	int i, j;
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			temp.A[i][j] = A[i][j] - m.A[i][j];
	temp.row = row;
	temp.col = col;
	return temp;
}

int main()
{
	Matrix a, b, c, d;
	a.getdata();
	b.getdata();
	if(a == b) 		//Overloading == operator
	{
		c = a + b;	//Overloading + operator
		d = a - b;	//Overloading - operator
		cout<<"Addition of matrices: "<<endl;
		cout<<c;
		cout<<"Subtraction of matrices: "<<endl;
		cout<<d;
	}
	else
	{
		cout<<"Cannot perform operations as dimensions of matrices are not identical\n";
	}
}