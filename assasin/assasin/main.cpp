#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"assasin.h"
using namespace std;
void start();
int main()
{
	bool pass;
	mission1 m1; mission2 m2; mission3 m3; mission4 m4; mission5 m5;
	start();
	m1.story1();
	while (1)
	{
		if (m1.start()) break;
		cout << "��Ϸʧ�ܣ�������������" << endl;
		system("pause");
		system("cls;");
	}
	m1.end1();
	m2.story2();
	while (1)
	{
		if (m2.start()) break;
		cout << "��Ϸʧ�ܣ�������������" << endl;
		system("pause");
		system("cls;");
	}
	m2.end2();
	m3.story3();
	while (1)
	{
		if (m3.start()) break;
		cout << "��Ϸʧ�ܣ�������������" << endl;
		system("pause");
		system("cls;");
	}
	m3.end3();
	m4.story4();
	while (1)
	{
		if (m4.start()) break;
		cout << "��Ϸʧ�ܣ�������������" << endl;
		system("pause");
		system("cls;");
	}
	m4.end4();
	m5.story5();
	while (!m5.start())
	{
		if (m5.start()) break;
		cout << "��Ϸʧ�ܣ�������������" << endl;
		system("pause");
		system("cls;");
	}
	m5.end5();
	system("pause");
	return 0;
}
void start()
{
	cout << "  �����������벨���Ǽ���Ķ��������ǵĴ̿ʹ�ʦ�������¡��µ��������ף����볹���Ʒ������Ǽ����������ͳ�Σ��������������������������ƽ��" << endl;
	cout << "  �����¾�������ȥ���������ײ��������Ǽ��塣" << endl<<endl;
	cout << "ֱ������վ�������������Ǽ��壬����ʥ����ʿ���ǲ����к�ƽ�ģ�" << endl;
	cout << "����������" << endl;
	system("pause");
	system("cls");
	initgraph(1600, 900);
	IMAGE img;
	loadimage(&img, "start.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}