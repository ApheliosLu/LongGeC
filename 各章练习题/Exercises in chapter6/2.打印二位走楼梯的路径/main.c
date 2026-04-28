#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node //构造体类型变量
{
	int x, y;
}node;
int cnt;
node path[100]; //存储路径，即走过的每个点的坐标
int ff(int m, int n, int x, int y, int step) //点（m,n)为目的地，(x,y)记录当时走到的点的坐标，step记录到(m,n)的步数，每次打印时step=m+n
{
	int i;
	if (m == x && n == y) //即到达目的地后开始打印，step记录总步数
	{
		cnt++; //记录路径次数
		for (i = 0; i <= step; i++) //
		{
			printf("(%d,%d)", path[i].x, path[i].y); //打印每一次的路径
		}
		printf("\n");
		return;
	}
	else
	{
		if (x < m && y <= n)//这里使用了短路运算，当x等于m时，开始执行下面的if
		{
			path[step + 1].x = x + 1; //每走一步，通过全局变量path记录一步
			path[step + 1].y = y;
			ff(m, n, x + 1, y, step + 1); //然后对应横轴坐标加1，走下一步
		}
		if (y < n && x <= m)
		{
			path[step + 1].x = x;
			path[step + 1].y = y + 1;
			ff(m, n, x, y + 1, step + 1);
		}
	}
}
//统计路径数量，同时打印每一条路径
int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		cnt = 0; //初始化次数为零
		path[0].x = path[0].y = 0;
		ff(m, n, 0, 0, 0);
		printf("%d\n", cnt);
	}
	system("pause");
}