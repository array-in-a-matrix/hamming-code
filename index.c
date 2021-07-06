#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define LOWER 0
#define UPPER 3

int random_number(int lower, int upper);
void print_matrix(int matrix[GRID_SIZE][GRID_SIZE]);
void induce_noise(int matrix[GRID_SIZE][GRID_SIZE]);
void parity_check(int matrix[GRID_SIZE][GRID_SIZE]);
int error_check(int matrix[GRID_SIZE][GRID_SIZE]);

void parity_check_1(int matrix[GRID_SIZE][GRID_SIZE]);
void parity_check_2(int matrix[GRID_SIZE][GRID_SIZE]);
void parity_check_3(int matrix[GRID_SIZE][GRID_SIZE]);
void parity_check_4(int matrix[GRID_SIZE][GRID_SIZE]);

int * error_check_1(int matrix[GRID_SIZE][GRID_SIZE]);
int * error_check_2(int matrix[GRID_SIZE][GRID_SIZE]);
int * error_check_3(int matrix[GRID_SIZE][GRID_SIZE]);
int * error_check_4(int matrix[GRID_SIZE][GRID_SIZE]);

int main()
{
	srand(time(0));

	int message[GRID_SIZE][GRID_SIZE] = {
		{1, 0, 0, 1},
		{0, 1, 0, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 1}};

	print_matrix(message);
	parity_check(message);
	printf("\n");
	print_matrix(message);
	printf("\n");
	printf("\n");
	printf("Message now corrupt!\n");
	induce_noise(message);
	print_matrix(message);
	printf("\n");
	printf("\n");
	error_check(message);
	return 0;
};

int random_number(int lower, int upper)
{
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
};

void print_matrix(int matrix[GRID_SIZE][GRID_SIZE])
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			printf("%3i", matrix[i][j]);
		}
		printf("\n");
	}
};

void induce_noise(int matrix[GRID_SIZE][GRID_SIZE])
{
	int random_X = random_number(LOWER, UPPER);
	int random_Y = random_number(LOWER, UPPER);

	printf("\n    (Y, X)");
	printf("\n    (%i, %i)\n\n", random_Y, random_X);

	if (matrix[random_Y][random_X] == 0)
	{
		matrix[random_Y][random_X] = 1;
	}
	else if (matrix[random_Y][random_X] == 1)
	{
		matrix[random_Y][random_X] = 0;
	};
};

void parity_check(int matrix[GRID_SIZE][GRID_SIZE])
{
	parity_check_1(matrix);
	parity_check_2(matrix);
	parity_check_3(matrix);
	parity_check_4(matrix);
};

int error_check(int matrix[GRID_SIZE][GRID_SIZE])
{
	int * sus_array_1 = error_check_1(matrix);
	int * sus_array_2 = error_check_2(matrix);
	int * sus_array_3 = error_check_3(matrix);
	int * sus_array_4 = error_check_4(matrix);

	printf("(%i, %i)\n", sus_array_1[0], sus_array_1[1]);
	printf("(%i, %i)\n", sus_array_2[0], sus_array_2[1]);
	printf("(%i, %i)\n", sus_array_3[0], sus_array_3[1]);
	printf("(%i, %i)\n", sus_array_4[0], sus_array_4[1]);

	return 0;
};


void parity_check_1(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int col_1[GRID_SIZE], col_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		col_1[i] = matrix[i][1];
		col_3[i] = matrix[i][3];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (col_1[i] == 1)
		{
			counter++;
		};
		if (col_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) == 0)
	{
		matrix[0][1] = 0;
	}
	else
	{
		matrix[0][1] = 1;
	};
};

void parity_check_2(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int col_2[GRID_SIZE], col_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		col_2[i] = matrix[i][2];
		col_3[i] = matrix[i][3];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (col_2[i] == 1)
		{
			counter++;
		};
		if (col_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) == 0)
	{
		matrix[0][2] = 0;
	}
	else
	{
		matrix[0][2] = 1;
	};
};

void parity_check_3(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int row_1[GRID_SIZE], row_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		row_1[i] = matrix[1][i];
		row_3[i] = matrix[3][i];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (row_1[i] == 1)
		{
			counter++;
		};
		if (row_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) == 0)
	{
		matrix[1][0] = 0;
	}
	else
	{
		matrix[1][0] = 1;
	};
};

void parity_check_4(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int row_2[GRID_SIZE], row_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		row_2[i] = matrix[2][i];
		row_3[i] = matrix[3][i];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (row_2[i] == 1)
		{
			counter++;
		};
		if (row_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) == 0)
	{
		matrix[2][0] = 0;
	}
	else
	{
		matrix[2][0] = 1;
	};
};


int * error_check_1(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int col_1[GRID_SIZE], col_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		col_1[i] = matrix[i][1];
		col_3[i] = matrix[i][3];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (col_1[i] == 1)
		{
			counter++;
		};
		if (col_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) != 0)
	{
		static int sus[2] = {1, 3};
		return sus;
	}
	else
	{
		static int sus[2] = {-1, -1};
		return sus;
	};
};

int * error_check_2(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int col_2[GRID_SIZE], col_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		col_2[i] = matrix[i][2];
		col_3[i] = matrix[i][3];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (col_2[i] == 1)
		{
			counter++;
		};
		if (col_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) != 0)
	{
		static int sus[2] = {2, 3};
		return sus;
	}
	else
	{
		static int sus[2] = {-1, -1};
		return sus;
	};
};

int * error_check_3(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int row_1[GRID_SIZE], row_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		row_1[i] = matrix[1][i];
		row_3[i] = matrix[3][i];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (row_1[i] == 1)
		{
			counter++;
		};
		if (row_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) != 0)
	{
		static int sus[2] = {1, 3};
		return sus;
	}
	else
	{
		static int sus[2] = {-1, -1};
		return sus;
	};
};

int * error_check_4(int matrix[GRID_SIZE][GRID_SIZE])
{
	int counter = 0;
	int row_2[GRID_SIZE], row_3[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		row_2[i] = matrix[2][i];
		row_3[i] = matrix[3][i];
	};

	for (int i = 0; i < GRID_SIZE; i++)
	{
		if (row_2[i] == 1)
		{
			counter++;
		};
		if (row_3[i] == 1)
		{
			counter++;
		};
	};

	if ((counter % 2) != 0)
	{
		static int sus[2] = {2, 3};
		return sus;
	}
	else
	{
		static int sus[2] = {-1, -1};
		return sus;
	};
};