#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c =65;//大写A的ASCII码，第65
	int i = 0;
	char* p = "helloword";
	printf("%c\n", c+32);
	printf("%d\n", c);
	char f = '\b';
	printf("abc%cd\n",f);//输出abd
	for (i = 0; i < 2; i++) 
	{
		printf("%c", 0xCC);//输出汉字“烫”
	}
	printf("abc\rd\n");//\r回到行首，d覆盖掉a，得到dbc
	printf("abc\bd\n");//\b退格；先退格，再空格，再退格
	printf("\123\n");//\ddd型转义字符，ddd表示1~3位八进制数，123等于83对应着S，此时打印出S！！！
	printf("\ta\n");//\t横向跳格（8个或4个空格）
	printf("\\\\");//要用两个反斜杠即\\来输出一个反斜杠即\，此时printf出\;以此类推，四个输出两个
	char q, w;
	q = 97;
	w = 'a';
	printf("q=%c,w=%c\n", q, w);
	printf("q=%d,w=%d\n", q, w);
	q = q - 32;
	printf("q=%c\n", q);
	system("pause");
	return 0;//return0
}