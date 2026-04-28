#include"func.h"

//实现打印函数，链表的“遍历”
void list_print(pstu phead)
{

	while (phead)//结束条件：phead为假
	{
		printf("%3d %5.2f\n", phead->num, phead->score);
		phead = phead->pnext;//遍历时，打印一个后，让phead指向下一个，即给指针phead赋值phead中存储的下一个节点的地址pnext
	}
	printf("\n");
}

//！！！传入形参的指针均为一级指针类型
//头插法
void list_head_insert(pstu* pphead, pstu* pptail, int val)//pstu为一级指针，pstu*为二级指针，传入子函数内发生改变；val为插入的值
{                                                         //要改变一级指针的地址时，使用二级指针
	pstu pnew = (pstu)malloc(sizeof(stu));//申请空间；建立一个新的车厢(即stu类型)，名称为pnew,类型为pstu即一级指针作为其地址
	memset(pnew, 0, sizeof(stu));//初始化，赋0；pnew中包括int型的num和stu*（即pstu型）的*pNext，两位乘客，初始化
	pnew->num = val;//为num赋值
	//判断链表是否为空
	if (NULL == *pphead)//通过对pphead取值，间接访问，拿到pphead的值；
	{
		//若为空，证明是第一个火车车厢，此时“头插”
		*pphead = pnew;//将新加入的pnew的地址，既传给头指针也传给尾指针，头尾指针指向同一个节点；
		//*pphead表示的是一级指针*phead的地址；*phead表示的是链表头的地址
		*pptail = pnew;
	}
	else {//不为空时
		pnew->pnext = *pphead;//将*pphead即原本的头pphead的地址赋给pnew中的pnext项
		*pphead = pnew;//将新的头pnew赋给pphead的地址即*pphead；新节点作为头节点，pnew作为新的pphead
	}
}

//尾插法
void list_tail_insert(pstu* pphead, pstu* pptail, int val)
{
	pstu pnew = (pstu)calloc(1, sizeof(stu));//使用calloc申请空间时，自动实现memset即初始化空间；申请的空间大小为1*sizeof(stu)
	pnew->num = val;
	//依旧判断链表是否为空
	if (NULL == *pphead)//依旧通过对pphead取值，间接访问，拿到pphead的值；
	{
		//若为空，证明是第一个火车车厢，此时“尾插”
		*pphead = pnew;//将新加入的pnew的地址，既传给头指针也传给尾指针，头尾指针指向同一个节点
		*pptail = pnew;
	}
	else {//不为空时
		(*pptail)->pnext = pnew;//把新建立的pnew赋值给尾指针的pnext，让尾指针的pnext指向pnew即新建立的车厢的地址
		*pptail = pnew;//将新的尾pnew赋给pptail的地址即*pptail；新节点作为尾节点，pnew作为新的pptail
	}
}

//有序插入法
void list_sort_insert(pstu* pphead, pstu* pptail, int val)
{
	pstu pnew = (pstu)calloc(1, sizeof(stu));
	pstu pcur = *pphead;//定义变量"当前指针pcur"，指向pphead的地址
	pstu ppre = pcur;//再定义一个指针ppre，最开始和pcur同时指向头部
	pnew->num = val;
	//依旧判断链表是否为空
	if (NULL == *pphead)//依旧通过对pphead取值，间接访问，拿到pphead的值；
	{
		//若为空，证明是第一个火车车厢，此时“有序插入”
		*pphead = pnew;//将新加入的pnew的地址，既传给头指针也传给尾指针，头尾指针指向同一个节点
		*pptail = pnew;
	}
	//链表不为空时，分情况，按照大小顺序：若原链表包含2 5 8三个节点，共三种插入情况(按照从小到大的方式插入，若从大到小则将下列的“<”改为“>”即可）
	else if (val < pcur->num) //情况1：插入头部,假如插入“1”；pcur->num代表一级指针*pphead中的num变量
	{
		pnew->pnext = pcur;//将头指针的地址赋给新的节点的pnext
		*pphead = pnew;//新的节点作为新的头
	}
	else {//情况2：插入中间，假如插入“6”；判断以遍历，寻找插入时机
		while (pcur)//pucr不为NULL时，进行下列判断和遍历；若pcur为NULL即若插入“10”，因需val<pcur->num，而pcur只有8、需要继续移动而变成NULL
		{
			if (val < pcur->num)//若val小于此时pcur指向位置的num，即6<8，插入
			{//三者顺序：ppre pnew pcur
				ppre->pnext = pnew;
				pnew->pnext = pcur;
				break;//插入后break，无需继续遍历
			}
			//遍历，寻找插入时机
			ppre = pcur;//将pcur赋给ppre，在下一行两者同时移动
			pcur = pcur->pnext;//pucr后移，指向下一个
		}
		if (NULL == pcur)//情况3：此时遍历整个链表无法找到val<pcur->num的位置，pcur移动到末尾成为NULL，使用尾插法；此时val=10
		{
			(*pptail)->pnext = pnew;//写成ppre->pnext=pew;亦可，因为此时ppre指向pptail
			*pptail = pnew;
		}
	}
}

//删除
void list_delete(pstu* pphead, pstu* pptail, int del_val)//传入要删除的值“del_val”(形参）
{//依旧以链表2 5 8为例
	pstu pcur = *pphead;//定义pcur指向头部，便于遍历；
	pstu ppre = pcur;
	//1.考虑链表为空时的情况
	if (NULL == pcur)
	{
		printf("list is empty\n");
		return;
	}
	//2.删除头部
	if (del_val == pcur->num)//情1：若删除头部即“2”，写成del_val=(*pphead)->num亦可
	{
		*pphead = pcur->pnext;//将头部保存的pnext即下一项的地址赋值给pphead，使其成为新的头;pcur仍指向旧的头
		//free(pcur);//将pcur给free掉，达到删除头部的目的；删除此行，精简代码
		//pcur = NULL;//置NULL
		//!考虑尾节点被删除的情况1：头是空的
		if (NULL == *pphead)
		{
			*pptail = NULL;//则尾也是空的，链表为空
		}
	}
	//3.删除中间或尾部
	else {//情况2：若删除中间即“5”，以链表1 2 5 8为例；ppre指向2，pcur指向5
		while (pcur)//使用while遍历，若pcur存在，即pcur指向链表中的数据
		{
			if (pcur->num == del_val)//使用pcur来判断以遍历；此时5==5
			{
				ppre->pnext = pcur->pnext;//将5中存的8的地址赋给2来存，以达到将5去除的目的；
				//上一行同时可以达到删除情况3：即删除尾部“8”的目的
				//将pcur->pnext即NULL赋给ppre->pnext，使ppre指向NULL成为新的尾部
				//free(pcur);//删除此行精简代码
				break;//达到目的后break，无需下列的遍历
			}
			ppre = pcur;//大哥出去，小弟守城
			pcur = pcur->pnext;//大哥指向下一个
		}
	}
	//若pcur为NULL，说明没有找到对应节点；对应要删除“10”的情况
	if (pcur == NULL)
	{
		printf("this val is not in list\n");
		return;
	}
	//!考虑尾节点被删除的情况2：ppre->pnext=NULL时，即尾是空的
	if (ppre->pnext = NULL)
	{
		*pptail = ppre;//对应上列尾部被删，ppre->pnext=pcur->pnext时，将ppre赋给*pptail即修改尾指针
	}
	free(pcur);//两行free合并为此行，精简代码；在pcur!=NULL的情况下，return，在经过上述两种情况的删除后free
	pcur = NULL;//置NULL
}

//修改
void list_modify(pstu phead, int num, float score)//这里（函数的定义/实现）不光要传入形参变量的类型，更要传入形参变量的名称
{
	while (phead)//遍历数组
	{
		if (phead->num==num)//形参名（num）可与实参名（val）不同
		{
			phead->score = score;//修改成绩
			break;//找到后break
		}
		phead = phead->pnext;//若没找到，寻找下一个
	}
	if (NULL == phead)//若遍历后仍未找到
	{
		printf("没有找到这个学号\n");
	}
}