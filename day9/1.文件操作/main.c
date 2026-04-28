#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void use_fgetc(FILE* fp)
{
	int ret;
	//FILE* fp;//文件（结构体）类型指针
	fp = fopen("text.txt", "r+");//若此处文件名与创建的不一致，报错：No such file directory;
	//"w"会把文件清空;"r+"会把第一个字符覆盖成'H'
	if (NULL == fp)
	{
		perror("fopen");
		return;
	}
	ret = fputc('H', fp);//进行写操作
	if (-1 == ret)//等同于EOF==ret，判断fputc是否失败;若失败，报错：Bad file descriptor(错误的文件标识符，即"r"权限打开文件不可写）
	{
		perror("fputc");
	}
	rewind(fp);//主动刷新文件输入输出缓冲区

}

void use_fgets(FILE* fp)
{
	int ret;
	char buf[1024];//新建要读取的字符串（字符数组）

	//使用fseek文件（光标）偏移部分
	ret = fseek(fp, 0, SEEK_END);
	if (ret != 0)//返回值不为零则fseek失败
	{
		perror("fseek");
	}

	////使用fgets读取部分
	////fgets(buf, sizeof(buf), fp);//使用fgets读取字符串
	//while (fgets(buf, sizeof(buf), fp) != NULL)//把文件读空;默认文件尾加入换行'\n'和结束符'\0'
	//{
	//	//puts(buf);//打印读取到的字符串
	//	printf("%s", buf);//只有最后一行默认加换行
	//}

	//使用fputs写入部分
	ret = fputs("haha", fp);//前四个字符被写成haha，无\n
	if (EOF == ret)
	{
		perror("fputs");
		return;
	}
}

void use_getc_putc(FILE* fp)
{
	char buf[1024];
	int ret;
	fputc('H', fp);
	fseek(fp, 4, SEEK_CUR);//读写之间，刷新位置指针
	ret = ftell(fp);
	while (fgets(buf, sizeof(buf), fp) != NULL)
	{
		printf("%s", buf);
	}
}

int main()
{
	FILE* fp = fopen("text.txt", "r+");
	if (NULL == fp)
	{
		perror("fopen");
		return;
	}
	//use_fgetc(fp);
	//use_fgets(fp);
	use_getc_putc(fp);//读写交替
	fclose(fp);//关闭文件指针，之后，会刷新文件输入输出缓冲区，此时将内容写入文件（磁盘上）

	system("pause");
}