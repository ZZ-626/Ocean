#include<iostream>
#include<string>
using namespace std;
#define Max 1000//最大人数


struct Person
{
	string m_Name;
	string m_Sex;
	int m_Age;
	int m_Phone;
	string m_Addr;

};
struct Addressbooks
{
	struct Person personArry[Max];
	int m_Size;


};

//1.添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size == Max)
	{
		cout << "通讯录已满，无法添加" << endl;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;

		//性别
		string sex;
		cout << "请输入性别" << endl;
		cin >> sex;
		abs->personArry[abs->m_Size].m_Sex = sex;

		//年龄
		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;

		//电话
		int phone = 0;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入住址" << endl;
		cin >> addr;
		abs->personArry[abs->m_Size].m_Addr = addr;

		//更新通讯录人数
		abs->m_Size++;
		//添加成功
		cout << "添加成功" << endl;

		system("pause");
		system("cls");//清屏

	}
}


//2.显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名:" << abs->personArry[i].m_Name << "\t";
			cout << "性别:" << abs->personArry[i].m_Sex << "\t";
			cout << "年龄:" << abs->personArry[i].m_Age << "\t";
			cout << "电话:" << abs->personArry[i].m_Phone << "\t";
			cout << "住址:" << abs->personArry[i].m_Addr << endl;
		}

	}

	system("pause");
	system("cls");


}


//检测联系人是否存在，如果存在，返回联系人具体位置，不存在返回-1；
//参数1 通讯录 //参数2 对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArry[i].m_Name == name)
		{
			return i;//返回当前人的序号
		}
	}
	return -1;//遍历结束没找到返回-1；

}

//3.删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你想要的删除的联系人" << endl;
	string name;
	cin >> name;
	//ret==-1  未查到
	int ret = isExist(abs, name);
	if (ret != -1)//要删除李四，将李四后的数据做向前移动，并让通讯录中记录的人员个数往前移动
	{

		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArry[i] = abs->personArry[i + 1];
		}
		abs->m_Size--;//更新人员信息
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4.查找联系人
void fingPerson(Addressbooks* abs)
{
	cout << "请输入你想要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名:" << abs->personArry[ret].m_Name << "\t";
		cout << "性别:" << abs->personArry[ret].m_Sex << "\t";
		cout << "年龄:" << abs->personArry[ret].m_Age << "\t";
		cout << "电话:" << abs->personArry[ret].m_Phone << "\t";
		cout << "住址:" << abs->personArry[ret].m_Addr << endl;

	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5.修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你想要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArry[ret].m_Name = name;

		//性别
		string sex;
		cout << "请输入性别" << endl;
		cin >> sex;
		abs->personArry[ret].m_Sex = sex;

		//年龄
		int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArry[ret].m_Age = age;

		//电话
		int phone = 0;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArry[ret].m_Phone = phone;

		//住址
		string addr;
		cout << "请输入住址" << endl;
		cin >> addr;
		abs->personArry[ret].m_Addr = addr;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//6.清空联系人

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
//菜单函数
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****	1.添加联系人	*****" << endl;
	cout << "*****	2.显示联系人	*****" << endl;
	cout << "*****	3.删除联系人	*****" << endl;
	cout << "*****	4.查找联系人	*****" << endl;
	cout << "*****	5.修改联系人	*****" << endl;
	cout << "*****	6.清空联系人	*****" << endl;
	cout << "*****	0.退出通讯录	*****" << endl;
	cout << "*****************************" << endl;
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化当前通讯录人数
	abs.m_Size = 0;
	int select = 0;
	while (1)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:                         //1.添加联系人
			addPerson(&abs);//利用地址传可以修改形参
			break;
		case 2:                         //2.显示联系人
			showPerson(&abs);
			break;
		case 3:                         //3.删除联系人
		{
			cout << "请输入删除联系人姓名" << endl;
			string name;
			cin >> name;
			isExist(&abs, name);
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
		}
		deletePerson(&abs);
		break;
		case 4:                         //4.查找联系人
			fingPerson(&abs);
			break;
		case 5:                         //5.修改联系人
			modifyPerson(&abs);
			break;
		case 6:                         //6.清空联系人
			cleanPerson(&abs);
			break;
		case 0:                         //0.退出通讯录    
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}
	system("pause");
	return 0;
}