#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void use_fread(FILE* fp)
{
	char buf[1024] = { 0 };//初始化，否则打印5个字节即"hello"后会有“烫烫烫”
	int ret;
	ret = fread(buf, 1, 5, fp);//读取5个，每个元素（字符）的大小为1个字节;ret=5
	printf("buf=%s\n", buf);
}

//如果写到文件里是整型数、浮点数、结构体，文件不要双击打开去看，通过程序去读
void use_fwrite(FILE* fp)
{
	//char buf[1024] = { "HELLO"};//字符可以看到
	int i = 12345;//写入一个整数，txt文件中无法看到(浮点数、结构体同理）
	int ret;
	//ret = fwrite(buf, 1, strlen(buf), fp);//使用strlen统计字符串长度；文件内容（原为helloworld），变为HELLOworld
	ret = fwrite(&i, sizeof(i), 1, fp);
	i = 0;
	fseek(fp, -1, SEEK_CUR);
	fread(&i, sizeof(int), 1, fp);
	//通过fread去读，显示90（十六进制的12345为3039；十六进制30为十进制48，39为57，ASCII48和57对应0和9（小端存储）；
	//通过软件(vscode的插件等）去看，看到其十六进制形式3039（十进制为12345）
	printf("i=%d\n", i);

}

//微软的文本模式{内存是\n，写入磁盘是存储的是\r\n;磁盘存储的\r\n，打开才能看到回车即换行效果，同时读入内存时是\n}
//与二进制模式的区别{内存是\n，写入磁盘存储的\n;磁盘存储的\n,读入内存时是\n}
void use_text_binray(FILE* fp)
{
	char buf[100] = "123\n45";//字符串中含有换行，共6个字符;
	//"r+"和"rb+"的区别
	int ret;
	ret = fwrite(buf, strlen(buf), 1, fp);//以"r+"的方式写入，共两行：123 45；显示共7个字节;CRLF格式即文本模式
	//ret = fwrite(buf, strlen(buf), 1, fp);//以"rb+"的方式写入，共两行：123 45；显示共6个字节；LF格式即二进制模式
}

void use_text_fseek(FILE* fp)
{

	char buf[100] = { 0 };
	int ret;
	fseek(fp, 0, SEEK_SET);//光标回到开头
	ret = fread(buf, 1, 4, fp);//fread成功返回4
	printf("%s", buf);

	//ret=fseek(fp, -2, SEEK_CUR);//fseek成功返回0
	//ret=fputc('6',fp);//把第4位字符即原有的\n写为字符6;fputc成功返回写入的字符；
	////此时文件打开显示123 645（若只偏移一个字节），仍存在换行，原因是(只有）fseek偏移时根据磁盘存储情况进行
	////若偏移两个字节则新写入的6会把\r覆盖掉，\n即换行依旧存在，显示1236 45

	//文本模式下，偏移时，针对\n，要向前偏移2个字节，因为是按磁盘来偏移的
	ret = fseek(fp, -strlen(buf) - 1, SEEK_CUR);//多偏移一个
	ret = fwrite("456\n", 1, 4, fp);//显示456 45
}

void use_fprintf(FILE* fp)
{
	int ret;
	ret = fprintf(fp, "%d %5.2f %s", 66, 98.5, "hello");//将不同类型的数据写入文件中;此例中ret即fprintf的返回值为14即成功输出到文件中的字符数
	//ret = fprintf(stdout, "%d %5.2f %s", 66, 98.5, "hello");//通过stdout，直接输出在屏幕上，相当于使用printf

}

void use_fscanf(FILE* fp)//从文件中读取数据
{
	int i;
	float score;
	char buf[100] = { 0 };
	int ret;//通过ret查看fscanf读成功的数目
	ret = fscanf(fp, "%d%f%s", &i, &score, buf);
	//ret = fscanf(stdin, "%d%f%s", &i, &score, buf);//同理，通过stdin从屏幕上读取数据
}

int main()
{
	FILE* fp = fopen("text.txt", "r+");
	//FILE* fp = fopen("text.txt", "w+");//w+创建一个用于读写的文件，相当于把旧写入的清空
	if (NULL == fp)
	{
		perror("fopen");
		goto error;
	}
	//use_fread(fp);
	//use_fwrite(fp);
	//use_text_binray(fp);//理解二进制与文本格式的差异
	//use_text_fseek(fp);//文本模式下使用fseek
	//use_fprintf(fp);
	use_fscanf(fp);
	fclose(fp);//关闭
error:
	system("pause");
}