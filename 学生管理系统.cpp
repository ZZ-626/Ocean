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
//������
struct node*createList()
{
	struct node*headnode=(struct node*)malloc(sizeof(struct node));
	headnode->next=NULL;
	return headnode;
	
 } 
 //�����ڵ�
 struct node*createnode(struct student date)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->date=date;
	newnode->next=NULL;
	return newnode;
 } 
 
 //������
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
	printf("����Ϊ�գ��޷�ɾ��\n");
	return;
}
while(strcmp(posnode->date.name,name))
{
	posFrontnode=posnode;
	posnode=posFrontnode->next;
	if(posnode==NULL)
	{
		printf("δ�ҵ�ָ��λ���޷�ɾ��\n");
		return;
	}
	
	}
	posFrontnode->next=posnode->next;
	free(posnode);
}
//���ҹ���
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
 //�ļ�������
 void readInfoFromFile(struct node*headnode,char*fileName)
 {
 	//1.�� 
 	FILE*fp;
 	struct student date;
 	fp=fopen(fileName,"r");
 	if(fp==NULL)
	 {
 		fp=fopen(fileName,"w+");	
	 }
	 //2.���ļ� 
	 while(fscanf(fp,"%s\t%d\t%s\t%s\n",date.name,&date.age,date.sex,date.tel)!=EOF)
	 {
	 	insertnodeByHead(headnode,date);
	 }
	 //3.�ر��ļ�
  fclose(fp); 
  }
  //�ļ�д����
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
 //��ӡ���� 
 void printList(struct node*headnode)
 {
 	struct node*pMove=headnode->next;
 	printf("����\t����\t�Ա�\t�绰\n");
 	while(pMove)
 	{
 		printf("%s\t%d\t%s\t%s\n",pMove->date.name,pMove->date.age,pMove->date.sex,pMove->date.tel);
 		pMove=pMove->next;
	 }
	 printf("\n");
  } 

void menu()
{
	printf("-----------��ѧ����Ϣ����ϵͳ��---------");
	printf("\t\t0.�˳�ϵͳ\n"); 
    printf("\t\t1.¼����Ϣ\n");
    printf("\t\t2.�����Ϣ\n");
    printf("\t\t3.�޸���Ϣ\n");
    printf("\t\t4.ɾ����Ϣ\n");
	printf("\t\t5.������Ϣ\n");
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
			printf("�����˳�\n");
			system("pause");
			exit(0);
			break;
		case 1:
			printf("-------��¼����Ϣ��-------");
			printf("������ѧ�����������䣬�Ա𣬵绰��");
			fflush(stdin);
			scanf("%s%d%s%s",date.name,&date.age,date.sex,date.tel);
			insertnodeByHead(list,date);
			
			break;
		case 2:
			printf("------- �������Ϣ��------");
			printList(list);
			break;
		case 3:
			printf("------- ���޸���Ϣ��------");
			printf("������Ҫ�޸ĵ�������");
			scanf("%s",date.name);
			if(searchInfoByDate(list,date.name)==NULL)
			{
				printf("δ���ҵ������Ϣ��\n");
			}
			else
			{
				struct node*curnode=searchInfoByDate(list,date.name);
				printf("������ѧ�����������䣬�Ա𣬵绰��");
				scanf("%s%d%s%s",curnode->date.name,&curnode->date.age,curnode->date.sex,curnode->date.tel);
			}
			
			break;
		case 4:
			printf("-------��ɾ����Ϣ��------");
				printf("������Ҫɾ����ѧ��������");
				scanf("%s",date.name);
				deleteAppoinnode(list,date.name);
			break;
		case 5:
			printf("-------��������Ϣ��------");
			printf("������Ҫ���ҵ�ѧ��������");
			scanf("%s",date.name);
			pMove=searchInfoByDate(list,date.name);
			if(pMove==NULL)
			{
				printf("δ���ҵ������Ϣ���޷�ɾ����\n");
				system("pause");
			}
			else
			{
			printf("����\t����\t�Ա�\t�绰\n");
			printf("%s\t%d\t%s\t%s\n",pMove->date.name,pMove->date.age,pMove->date.sex,pMove->date.tel);	
			}
			break;
		default:
			printf("ѡ�������������\n");
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
