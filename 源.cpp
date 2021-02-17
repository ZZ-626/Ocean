#include<iostream>
#include<string>
using namespace std;
#define Max 1000//�������


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

//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == Max)
	{
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;

		//�Ա�
		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		abs->personArry[abs->m_Size].m_Sex = sex;

		//����
		int age = 0;
		cout << "����������" << endl;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;

		//�绰
		int phone = 0;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;

		//סַ
		string addr;
		cout << "������סַ" << endl;
		cin >> addr;
		abs->personArry[abs->m_Size].m_Addr = addr;

		//����ͨѶ¼����
		abs->m_Size++;
		//��ӳɹ�
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");//����

	}
}


//2.��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����:" << abs->personArry[i].m_Name << "\t";
			cout << "�Ա�:" << abs->personArry[i].m_Sex << "\t";
			cout << "����:" << abs->personArry[i].m_Age << "\t";
			cout << "�绰:" << abs->personArry[i].m_Phone << "\t";
			cout << "סַ:" << abs->personArry[i].m_Addr << endl;
		}

	}

	system("pause");
	system("cls");


}


//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�˾���λ�ã������ڷ���-1��
//����1 ͨѶ¼ //����2 �Ա�����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArry[i].m_Name == name)
		{
			return i;//���ص�ǰ�˵����
		}
	}
	return -1;//��������û�ҵ�����-1��

}

//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "����������Ҫ��ɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret==-1  δ�鵽
	int ret = isExist(abs, name);
	if (ret != -1)//Ҫɾ�����ģ������ĺ����������ǰ�ƶ�������ͨѶ¼�м�¼����Ա������ǰ�ƶ�
	{

		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArry[i] = abs->personArry[i + 1];
		}
		abs->m_Size--;//������Ա��Ϣ
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4.������ϵ��
void fingPerson(Addressbooks* abs)
{
	cout << "����������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "����:" << abs->personArry[ret].m_Name << "\t";
		cout << "�Ա�:" << abs->personArry[ret].m_Sex << "\t";
		cout << "����:" << abs->personArry[ret].m_Age << "\t";
		cout << "�绰:" << abs->personArry[ret].m_Phone << "\t";
		cout << "סַ:" << abs->personArry[ret].m_Addr << endl;

	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5.�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "����������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArry[ret].m_Name = name;

		//�Ա�
		string sex;
		cout << "�������Ա�" << endl;
		cin >> sex;
		abs->personArry[ret].m_Sex = sex;

		//����
		int age = 0;
		cout << "����������" << endl;
		cin >> age;
		abs->personArry[ret].m_Age = age;

		//�绰
		int phone = 0;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArry[ret].m_Phone = phone;

		//סַ
		string addr;
		cout << "������סַ" << endl;
		cin >> addr;
		abs->personArry[ret].m_Addr = addr;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//6.�����ϵ��

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
//�˵�����
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****	1.�����ϵ��	*****" << endl;
	cout << "*****	2.��ʾ��ϵ��	*****" << endl;
	cout << "*****	3.ɾ����ϵ��	*****" << endl;
	cout << "*****	4.������ϵ��	*****" << endl;
	cout << "*****	5.�޸���ϵ��	*****" << endl;
	cout << "*****	6.�����ϵ��	*****" << endl;
	cout << "*****	0.�˳�ͨѶ¼	*****" << endl;
	cout << "*****************************" << endl;
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ����ǰͨѶ¼����
	abs.m_Size = 0;
	int select = 0;
	while (1)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:                         //1.�����ϵ��
			addPerson(&abs);//���õ�ַ�������޸��β�
			break;
		case 2:                         //2.��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:                         //3.ɾ����ϵ��
		{
			cout << "������ɾ����ϵ������" << endl;
			string name;
			cin >> name;
			isExist(&abs, name);
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
		}
		deletePerson(&abs);
		break;
		case 4:                         //4.������ϵ��
			fingPerson(&abs);
			break;
		case 5:                         //5.�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:                         //6.�����ϵ��
			cleanPerson(&abs);
			break;
		case 0:                         //0.�˳�ͨѶ¼    
			cout << "��ӭ�´�ʹ��" << endl;
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