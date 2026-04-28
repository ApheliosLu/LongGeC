#include <stdio.h>//printf函数需要使用该头文件
#include <stdlib.h>//system函数需要使用该头文件

int main()//主函数
{//函数体开始
    int i;//(先定义，关键字定义变量名)
    i = 10;//(后使用，给变量赋值)
    printf("厄斐琉斯，千万利器莫过于你的信念\n");//打印输出Hello world字符串，\n表示换行
    system("pause");//让黑色的控制台窗口停留;2012需要加，2017、2019不需要
    return 0;
}//函数体结束