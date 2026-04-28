#include<stdio.h>
#include<stdlib.h>

int Find(int* matrix, int rows, int columns, int number)
{
	int found = 0;

	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)//?
			{
				found = 1;//?
				printf("the number %d is in row: %d and column: %d\n", number, row + 1, column + 1);
				break;
			}
			else if (matrix[row * columns + column] > number)
				--column;//列数减
			else
				++row;//行数加
		}
	}
	return found;
}

//1   2   8   9
//2   4   9   12
//4   7   10  13
//6   8   11  15

int main()
{
	int rows = 4;//存储行数
	int columns = 4;//存储列数
	int number = 5;//查找的数字
	int matrix[][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	int i, j, result;//i,j用于打印二维数组
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
			printf("%d\t", matrix[i][j]);

		printf("\n");
	}
	printf("\n");
	result = Find((int*)matrix, rows, columns, number);//判断结果
	if (result)
		printf("found.\n");
	else
		printf("not found.\n");
	system("pause");
	return 0;
}