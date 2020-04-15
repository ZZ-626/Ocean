#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char name[20];
	int age;
	char sex[5];
	char tel[20];
};
struct node
{
	struct student date;
	struct node*next; 
};
//创建表
struct node*createList()
{
	struct node*headnode=(struct node*)malloc(sizeof(struct node));
	headnode->next=NULL;
	return headnode;
	
 } 
 //创建节点
 struct node*createnode(struct student date)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->date=date;
	newnode->next=NULL;
	return newnode;
 } 
 
 //插入结点
  void insertnodeByHead(struct node*headnode,struct student date)
  {
  	struct node*newnode=createnode(date);
  	newnode->next=headnode->next;
  	headnode->next=newnode;
  }
  void deleteAppoinnode(struct node*headnode,char*name)
  {
  
struct node*posnode=headnode->next;
struct node*posFrontnode=headnode;
if(posnode==NULL)
{
	printf("数据为空，无法删除\n");
	return;
}
while(strcmp(posnode->date.name,name))
{
	posFrontnode=posnode;
	posnode=posFrontnode->next;
	if(posnode==NULL)
	{
		printf("未找到指定位置无法删除\n");
		return;
	}
	
	}
	posFrontnode->next=posnode->next;
	free(posnode);
}
//查找功能
struct node*searchInfoByDate(struct node*headnode,char*name)
{
	struct node*pMove=headnode->next;
	if(pMove==NULL)
	return NULL;
	while(strcmp(pMove->date.name,name))
	{
		pMove=pMove->next;
	}
	return pMove;
 }
 //文件读操作
 void readInfoFromFile(struct node*headnode,char*fileName)
 {
 	//1.打开 
 	FILE*fp;
 	struct student date;
 	fp=fopen(fileName,"r");
 	if(fp==NULL)
	 {
 		fp=fopen(fileName,"w+");	
	 }
	 //2.读文件 
	 while(fscanf(fp,"%s\t%d\t%s\t%s\n",date.name,&date.age,date.sex,date.tel)!=EOF)
	 {
	 	insertnodeByHead(headnode,date);
	 }
	 //3.关闭文件
  fclose(fp); 
  }
  //文件写操作
  void writeInfoToFile(struct node*headnode,char*fileName) 
  {
  	FILE*fp;
  	fp=fopen(fileName,"w");
  	struct node*pMove=headnode->next;
  	while(pMove)
  	{
  		fprintf(fp,"%s\t%d\t%s\t%s\n",pMove->date.name,pMove->date.age,pMove->date.sex,pMove->date.tel);
  		pMove=pMove->next;
	  }
	  fclose(fp);
  }
 //打印链表 
 void printList(struct node*headnode)
 {
 	struct node*pMove=headnode->next;
 	printf("姓名\t年龄\t性别\t电话\n");
 	while(pMove)
 	{
 		printf("%s\t%d\t%s\t%s\n",pMove->date.name,pMove->date.age,pMove->date.sex,pMove->date.tel);
 		pMove=pMove->next;
	 }
	 printf("\n");
  } 

void menu()
{
	printf("-----------【学生信息管理系统】---------");
	printf("\t\t0.退出系统\n"); 
    printf("\t\t1.录入信息\n");
    printf("\t\t2.浏览信息\n");
    printf("\t\t3.修改信息\n");
    printf("\t\t4.删除信息\n");
	printf("\t\t5.查找信息\n");
	printf("----------------------------------------");
	}
struct node*list=createList();
void keyDown()
{
	int choice=0;
	struct student date;
	struct node*pMove=NULL;
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
			printf("正常退出\n");
			system("pause");
			exit(0);
			break;
		case 1:
			printf("-------【录入信息】-------");
			printf("请输入学生姓名，年龄，性别，电话：");
			fflush(stdin);
			scanf("%s%d%s%s",date.name,&date.age,date.sex,date.tel);
			insertnodeByHead(list,date);
			
			break;
		case 2:
			printf("------- 【浏览信息】------");
			printList(list);
			break;
		case 3:
			printf("------- 【修改信息】------");
			printf("请输入要修改的姓名：");
			scanf("%s",date.name);
			if(searchInfoByDate(list,date.name)==NULL)
			{
				printf("未查找到相关信息！\n");
			}
			else
			{
				struct node*curnode=searchInfoByDate(list,date.name);
				printf("请输入学生姓名，年龄，性别，电话：");
				scanf("%s%d%s%s",curnode->date.name,&curnode->date.age,curnode->date.sex,curnode->date.tel);
			}
			
			break;
		case 4:
			printf("-------【删除信息】------");
				printf("请输入要删除的学生姓名：");
				scanf("%s",date.name);
				deleteAppoinnode(list,date.name);
			break;
		case 5:
			printf("-------【查找信息】------");
			printf("请输入要查找的学生姓名：");
			scanf("%s",date.name);
			pMove=searchInfoByDate(list,date.name);
			if(pMove==NULL)
			{
				printf("未查找到相关信息，无法删除：\n");
				system("pause");
			}
			else
			{
			printf("姓名\t年龄\t性别\t电话\n");
			printf("%s\t%d\t%s\t%s\n",pMove->date.name,pMove->date.age,pMove->date.sex,pMove->date.tel);	
			}
			break;
		default:
			printf("选择错误，重新输入\n");
			system("pause");
			break;	
	}
	writeInfoToFile(list,"1.txt");
}
int main()
{
	readInfoFromFile(list,"1.txt");
	while(1)
	{
		menu();
		keyDown();
		system("pause");
		system("cls");	
	}
	system("pause");
	return 0;
}
