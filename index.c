#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define LOWER 0
#define UPPER 3

void print_matrix(int matrix[GRID_SIZE][GRID_SIZE]);
int random_number(int lower, int upper);
void introduce_noise(int matrix[GRID_SIZE][GRID_SIZE]);

int main()
{
	srand(time(0));

	int message[GRID_SIZE][GRID_SIZE] = {
		{  1,  1,  0,  1},
		{  0,  1,  0,  0},
		{  1,  1,  0,  1},
		{  1,  0,  1,  1}};
	 // {  0,  1,  2,  3},
	 // {  4,  5,  6,  7},
	 // {  8,  9, 10, 11},
     // { 12, 13, 14, 15}};

	print_matrix(message);
	introduce_noise(message);
	print_matrix(message);

	return 0;
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

int random_number(int lower, int upper)
{
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
};

void introduce_noise(int matrix[GRID_SIZE][GRID_SIZE])
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

// void parity_check_1(int matrix[GRID_SIZE][GRID_SIZE]){
// 	int parity_bit = matrix[0][1];
	
// };

// void parity_check_2(int matrix[GRID_SIZE][GRID_SIZE]){
// 	int parity_bit = matrix[0][2];
	
// };

// void parity_check_3(int matrix[GRID_SIZE][GRID_SIZE]){
// 	int parity_bit = matrix[1][0];
	
// };

// void parity_check_4(int matrix[GRID_SIZE][GRID_SIZE]){
// 	int parity_bit = matrix[2][0];
	
// };

