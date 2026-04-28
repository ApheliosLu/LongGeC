#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

jmp_buf envbuf;//定义envbuf(环境缓存存储）
//若要通过传参的方式实现，则将jmp_buf envbuf作为一个形参放入a中，各带2的注释句为具体实现，注释掉上一句

void b()//2void b(jmp_buf envbuf)
{
	printf("I am func b\n");
	longjmp(envbuf, 5);//longjmp函数本身无返回值（为void类型）；参数5的意义是i=5，此时回到setjmp（envbuf）处时，i!=0，因此结束
}
void a()//2void a(jmp_buf envbuf)
{
	printf("before b(),i am a func\n");
	b();//2b(envbuf);
	printf("after b(),i am a func\n");//不输出此语句
}

int main()
{
	int i;
	//2jmp_buf envbuf;     //定义一个jmp_buf envbuf的实参
	i = setjmp(envbuf);//（第一次）保存进程执行的上下文；并设定返回值i的初值为0
	if (i==0)//判断，（第一次）回到这里的时候，返回值为零的时候
	{
		a();//2a(envbuf);
	}
	system("pause");
	return;
}
