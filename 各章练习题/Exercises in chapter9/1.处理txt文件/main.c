#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//?转换完成看不到。？尝试在后面加个结束符
void main(int argc, char* argv[])
{
	FILE* fp;
	char buf[2000],c;
	//打开文件，并判断打开是否成功
	fp = fopen("The_Holy_Bible.txt", "r+");
	if (NULL == fp)
	{
		perror("fopen");
		system("pause");
		return;
	}
	while (c = fgetc(fp) != EOF)
	{
		if (c <= 'Z' && c >= 'A')
		{
			c += 32;//大写字母变小写
			fseek(fp, -1, SEEK_CUR);//光标先往前偏移，再写入（覆盖原有的内容）
			fputc('c\0', fp);
		}
		else if ((c >= '0' && c <= '9') || (c <= 'z' && c >= 'a') || c == '\n' || c ==' ')
		{
			continue;
		}
		else
		{
			c = ' ';
			fseek(fp, -1, SEEK_CUR);
			fputc('c\0', fp);
		}
		//在Windows下，读写之间必须刷新位置
		fseek(fp, 0, SEEK_CUR);
	}
	fclose(fp);
	system("pause");
	return;
}