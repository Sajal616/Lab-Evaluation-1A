#include <iostream>
using namespace std;
int determinant(int** matrix, int size)
{
	int det = 0;
	int sign = 1;

	// Base Case
	if (size == 1) {
		det = matrix[0][0];
	}
	else if (size == 2) {
		det = (matrix[0][0] * matrix[1][1])
			- (matrix[0][1] * matrix[1][0]);
	}
	else {
		for (int i = 0; i < size; i++) {
			int** cofactor = new int*[size - 1];
			for (int j = 0; j < size - 1; j++) {
				cofactor[j] = new int[size - 1];
			}
			int sub_i = 0, sub_j = 0;
			for (int j = 1; j < size; j++) {
				for (int k = 0; k < size; k++) {
					if (k == i) {
						continue;
					}
					cofactor[sub_i][sub_j] = matrix[j][k];
					sub_j++;
				}
				sub_i++;
				sub_j = 0;
			}
			det += sign * matrix[0][i]
				* determinant(cofactor, size - 1);
			sign = -sign;
			for (int j = 0; j < size - 1; j++) {
				delete[] cofactor[j];
			}
			delete[] cofactor;
		}
	}

	return det;
}

int main()
{
	int** matrix = new int*[4];
	for (int i = 0; i < 4; i++) {
		matrix[i] = new int[4];
	}
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 2;
	matrix[0][3] = -1;
	matrix[1][0] = 3;
	matrix[1][1] = 0;
	matrix[1][2] = 0;
	matrix[1][3] = 5;
	matrix[2][0] = 2;
	matrix[2][1] = 1;
	matrix[2][2] = 4;
	matrix[2][3] = -3;
	matrix[3][0] = 1;
	matrix[3][1] = 0;
	matrix[3][2] = 5;
	matrix[3][3] = 0;
	int size = 4;

	int det = determinant(matrix, size);

	cout << "Determinant: " << det << endl;

	for (int i = 0; i < 4; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
