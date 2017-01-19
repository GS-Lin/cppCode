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
		cout << "游戏失败，请重新来过！" << endl;
		system("pause");
		system("cls;");
	}
	m1.end1();
	m2.story2();
	while (1)
	{
		if (m2.start()) break;
		cout << "游戏失败，请重新来过！" << endl;
		system("pause");
		system("cls;");
	}
	m2.end2();
	m3.story3();
	while (1)
	{
		if (m3.start()) break;
		cout << "游戏失败，请重新来过！" << endl;
		system("pause");
		system("cls;");
	}
	m3.end3();
	m4.story4();
	while (1)
	{
		if (m4.start()) break;
		cout << "游戏失败，请重新来过！" << endl;
		system("pause");
		system("cls;");
	}
	m4.end4();
	m5.story5();
	while (!m5.start())
	{
		if (m5.start()) break;
		cout << "游戏失败，请重新来过！" << endl;
		system("pause");
		system("cls;");
	}
	m5.end5();
	system("pause");
	return 0;
}
void start()
{
	cout << "  历经多年来与波吉亚家族的斗争后，我们的刺客大师，艾吉奥·奥迪托雷明白，必须彻底推翻波吉亚家族在罗马的统治，才能真正给整个意大利带来和平。" << endl;
	cout << "  艾吉奥决定亲自去到罗马，彻底铲除波吉亚家族。" << endl<<endl;
	cout << "直到我们站起来反抗波吉亚家族，反抗圣殿骑士，是不会有和平的！" << endl;
	cout << "——艾吉奥" << endl;
	system("pause");
	system("cls");
	initgraph(1600, 900);
	IMAGE img;
	loadimage(&img, "start.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}