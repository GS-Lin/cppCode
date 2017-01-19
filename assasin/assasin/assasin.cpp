#include "assasin.h"
#include<string>
#include<cstdlib>
#include<ctime>
#include <graphics.h>
#include <conio.h>
using namespace std;

assasin::assasin()
	:hidenblade(20,5),
	arrow(10,10),
	firegun(15,7)
{
	hiden_statu = false;
	on_building = false;
	steps = 1;
}

void assasin::reset()
{
	hiden_statu = false;
	on_building = false;
	steps = 1;
}

void assasin::move()
{
	steps+=2;
}

void assasin::fastmove()
{
	steps += 4;
}

void assasin::climb()
{
	on_building = true;
}

void assasin::down()
{
	on_building = false;
}

void assasin::hide()
{
	hiden_statu = true;
}

void assasin::comeout()
{
	hiden_statu = false;
}

bool assasin::buildingstatu()
{
	return on_building;
}

bool assasin::hidestatu()
{
	return hiden_statu;
}

int assasin::getstep()
{
	return steps;
}

weapon & assasin::getblade()
{
	return hidenblade;
}

weapon & assasin::getarrow()
{
	return arrow;
}

weapon & assasin::getfiregun()
{
	return firegun;
}

weapon::weapon(int a, int b)
{
	setdamage(a);
	setdistance(b);
}

void weapon::attack(enemy & target)
{
	target.decHP(damage);
}

bool weapon::checkdistance(int d)
{
	if (d <= distance)
	{
		return true;
	}
	else
		return false;
}

void weapon::setdistance(int d)
{
	distance = d;
}

void weapon::setdamage(int d)
{
	damage = d;
}

enemy::enemy(int health, string n)
{
	setHP(health);
	setname(n);
	steps = 0;
	vigilance = 0;
	lookback_statu = 0;
}

void enemy::reset()
{
	steps = 0;
	vigilance = 0;
	lookback_statu = 0;
	setHP(original_HP);
}

void enemy::move()
{
	steps++;
}

void enemy::adddiatance(int d)
{
	steps += d;
}

void enemy::turnback()
{
	lookback_statu = true;
}

void enemy::lookforward()
{
	lookback_statu = false;
}

void enemy::addvigilance()
{
	vigilance++;
}

bool enemy::getstatu()
{
	return lookback_statu;
}

int enemy::getvigilance()
{
	return vigilance;
}

int enemy::getstep()
{
	return steps;
}

int character::gethp()
{
	return HP;
}

void character::setHP(int n)
{
	HP = n;
}

void character::decHP(int n)
{
	HP -= n;
}

string character::getname()
{
	return name;
}

void character::setname(string n)
{
	name = n;
}

mission1::mission1()
	:captain(5,"���������ӳ�")
{
	ori_length = 50;
	ori_building_length = 25;
	ori_distance = 30;
	ori_height = 5;
	ori_start = 1;
	ori_HP = 5;
	wmark = false;
	lmark = false;
}

void mission1::story1()
{
	cout << "----------����1��ʼ----------" << endl;
	cout << "     ����1 ������������      "<<endl;
	cout << "  ��������������֮�󣬷��ֲ����Ǽ����Ѿ���ȫ�ƿ�������ǣ������������䲻����ɢ����һ�־�����ζ�����������һ�е�������׾���������������ǡ��̻����ӵ�ͳ�죬ͬʱҲ�ǽ̻ʣ��޵���ˡ������ǵĴ��ӡ�" << endl;
	cout << "  �����������������ʵ��̫ǿ�󣬰����¾���������������������Կ������ǡ����ǣ����������������������ʶ�������أ������¾�������������д������Ǽ����������ͳ�ε����ӳ������ﵽ����Ŀ�ꡣ" << endl << endl;
	cout << "����Ľ�ſ�ʼ�ˡ�" << endl;
	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void mission1::reset()
{
	area_length = ori_length;
	building_height = ori_height;
	building_length = ori_building_length;
	building_start = ori_start;
	initial_distance = ori_distance;
	wmark = false;
	lmark = false;
	Ezio.reset();
	captain.reset();
	captain.setHP(ori_HP);
}


void mission1::end1()
{
	cout << "----------����1���----------" << endl;
	cout << "  �������ӳ������Լ��������һ�������ر���ɱ�������������ף��Լ�����������ʱ�����ˣ�һλҪ�����������ɵĴ̿͵����ˡ�" << endl;
	cout << "  һ���ڰ����¾�������������������е����˽����ֵܻᣬ����Ѱ��������䵥�Ĵ̿͡��̿�ѧͽ�ǲ�������������������¶Կ������ǣ������������ִ��������Զ�����ﵽ��ӡ�ȵĿ�������." << endl;
	system("pause");
	system("cls");
	initgraph(1280, 721);
	IMAGE img;
	loadimage(&img, "����1.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();

}

bool mission1::start()
{
	int option;
	reset();
	captain.adddiatance(initial_distance);
	while ((!wmark)&&(!lmark))
	{
		if ((captain.getstep() >= area_length) || (captain.getvigilance() >= 10))
		{
			lose();
			lmark = true;
			break;
		}
		printmessage();
		turnback();
		if (captain.getstatu())
		{
			if (!Ezio.hidestatu())
			{
				captain.addvigilance();
				cout << "���˻�ͷ�������ƺ������������Ӱ�����˾���ֵ���ӣ�" << endl;
			}
		}
		cout << "����һ�����ж���:" << endl;
		cout << "1:������Ϣ�ıƽ�" << endl;
		cout << "2:��ǰ���ټ���" << endl;
		cout << "3:������Χ�Ľ�����" << endl;
		cout << "4:�ӽ���������ص�����" << endl;
		cout << "5:Ѹ�ٶ��븽��������" << endl;
		cout << "6:��ʼ��ɱ��" << endl;
		cin >> option;
		choseact(option);
		system("pause");
		system("cls");
	}
	return wmark;
}

void mission1::move()
{
	if ((Ezio.buildingstatu()) && (Ezio.getstep()+2 > building_start + building_length))
	{
		cout << "���Ѿ�վ�ڽ������Ե��,�޷��ټ�����ǰ,������ѡ����һ���ж�" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		if (Ezio.getstep() <= captain.getstep()-1)
		{
			Ezio.move();
			cout << "��������Ϣ�ؽӽ���������ֽ���һ��" << endl;
			captain.move();
			cout << "Ŀ����ȫû�о�����Ľӽ�����Ȼ��ǰ����" << endl;
		}
		else
		{
			cout << "�������̫���ˣ��ٽӽ��Ļ��ᱻ���֣�" << endl;
		}
	}
}

void mission1::fastmove()
{
	if (Ezio.buildingstatu() && Ezio.getstep()+4 > building_start + building_length)
	{
		cout << "���Ѿ�վ�ڽ������Ե��,�޷��ټ�����ǰ,������ѡ����һ���ж�" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		if (Ezio.getstep() < captain.getstep() - 4)
		{
			Ezio.fastmove();
			cout << "�������ǰ����һ�ξ��룬����˽���һ��ξ���" << endl;
			captain.move();
			if (Ezio.buildingstatu())
			{
				cout << "�����ݶ��ϼ��ٱ��ܣ��������Է�������ټ�" << endl;
			}
			else
			{
				cout << "���ڼ���֮�£����ⷢ�����������˾���ֵ���" << endl;
				captain.addvigilance();
			}
		}
		else
		{
			cout << "�������̫���ˣ��ٽӽ��Ļ��ᱻ���֣�" << endl;
		}
	}
}

void mission1::climb()
{
	if (Ezio.buildingstatu())
	{
		cout << "���Ѿ����ݶ��ˣ�������ѡ����һ���ж�" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		for (int i = 0; i < building_height; i++)   //climb on the building will cost time 
			captain.move();
		Ezio.climb();
		cout << "���ֽŲ��ã�ת˲֮�����������ߵĽ�����" << endl;
	}
}

void mission1::down()
{
	if (!Ezio.buildingstatu())
	{
		cout << "���Ѿ��ڵ����ˣ�������ѡ����һ���ж�" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		Ezio.down();
		captain.move();
		cout << "��ʩչ����֮Ծ��˲����ص���" << endl;
	}
}

void mission1::win()
{
	if (captain.gethp() <= 0)
	{
		cout << "��������������������������սᣬ��ɱ�ж��ɹ���" << endl;
		wmark = true;
		system("pause");
	}
	else
	{
		cout << "����Ȼ�ش����ˣ�ȴ��������������óȻ�ĳ���Ҳ��¶������ټ�����ɱ�ж�����ʧ�ܣ�" << endl;
		lmark = true;
		system("pause");
	}
}

void mission1::hide()
{
	Ezio.hide();
	cout << "����Ӱ������ȣ�������Χ��������" <<endl;
	if (captain.getstatu())
	{
		captain.lookforward();
		cout << "�����Ĵ�̽��Ҳ�޷����������Ӱ��Ҳ��������Լ��Ĵ����ֻ�ü���ǰ��" << endl;
		captain.move();
	}
	captain.move();
}

void mission1::assassinate()
{
	int choseweapon;
	cout << "�����������" << captain.getstep() - Ezio.getstep() << "��" << endl;
	cout << "��ѡ����Ҫʹ�õ�����" << endl;
	cout << "1:�佣 2������ 3����ǹ 4:����ѡ��" << endl;
	cin >> choseweapon;
	switch (choseweapon)
	{
	case 1:blade(captain); break;
	case 2:arrow(captain); break;
	case 3:firegun(captain); break;
	case 4:
	{
		int option; cout << "������ѡ��ָ��" << endl;
		cout << "1:������Ϣ�ıƽ�" << endl;
		cout << "2:��ǰ���ټ���" << endl;
		cout << "3:������Χ�Ľ�����" << endl;
		cout << "4:�ӽ���������ص�����" << endl;
		cout << "5:Ѹ�ٶ��븽��������" << endl;
		cout << "6:��ʼ��ɱ��" << endl;
		cin >> option;
		choseact(option);
		break;
	}
	default:cout << "������ѡ����ȷ�Ĵ�ɱ��ʽ" << endl; assassinate(); break;
	}
}

void mission1::blade(enemy & e)
{
	if (Ezio.getblade().checkdistance(captain.getstep()-Ezio.getstep()))
	{
		if (!Ezio.buildingstatu())
		{
			Ezio.getblade().attack(captain);
			cout << "�������磬�佣˲�䵯�������˵������ѱ��̴���" << endl;
			win();
		}
		else
		{
			Ezio.getblade().attack(captain);
			cout << "��ӿ������䣬����ӥ��ʳ�����������٣����е��佣�Ѵ̴������ؿڣ�" << endl;
			win();
		}
	}
	else
	{
		cout << "��͵��˵ľ���̫��Զ�ˣ�����������������ɱ����" << endl;
		cout << "������ѡ���ɱ��ʽ" << endl;
		assassinate();
	}
}

void mission1::arrow(enemy &)
{
	if (Ezio.getarrow().checkdistance(captain.getstep() - Ezio.getstep()))
	{
			Ezio.getarrow().attack(captain);
			cout << "���ͳ�ʮ��Ӳ��ֻ��������磬���Ȼ��е���" << endl;
			win();
	}
	else
	{
		cout << "��͵��˵ľ���̫��Զ�ˣ�����������������ɱ����" << endl;
		cout << "������ѡ���ɱ��ʽ" << endl;
		assassinate();
	}
}

void mission1::firegun(enemy &)
{
	if (Ezio.getfiregun().checkdistance(captain.getstep() - Ezio.getstep()))
	{
		Ezio.getfiregun().attack(captain);
		cout << "������ұۣ�ǣ�����أ�����ǹһ�������������漴�е����أ�" << endl;
		win();
	}
	else
	{
		cout << "��͵��˵ľ���̫��Զ�ˣ�����������������ɱ����" << endl;
		cout << "������ѡ���ɱ��ʽ" << endl;
		assassinate();
	}
}

void mission1::lose()
{
	if (captain.getvigilance() >= 10)
	{
		cout << "����ټ������˷����ˣ���ɱ�ж�����ʧ�ܣ�" << endl;
		system("pause");
	}
	else
	{
		if (captain.getstep() > area_length)
		{
			cout << "�����Ѿ��߳���ɱ���򣬴�ɱ�ж�����ʧ�ܣ�" << endl;
			system("pause");
		}
	}
}

void mission1::printmessage()
{
	cout << "��������:    " << captain.getname()<< endl;
	cout << "����HP:    ";
	for (int i = 0; i < captain.gethp(); i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << "���˾���ֵ:    ";
	for (int i = 0; i < captain.getvigilance(); i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << "��ǰ����λ��Ϊ��" << Ezio.getstep() << "��" << endl;
	if (building_start > 0)
	{
		cout << "�ӵ�" << building_start << "������" << building_length + building_start << "���и߶�Ϊ" << building_height << "�Ľ�����" << endl;
	}
	else
	{
		cout << "��Χ����ƽ�أ���û�����������м��Ľ�����" << endl;
	}
	cout << "�������߳���ɱ������" << area_length - captain.getstep() << "��"<<endl;
	cout << "����˵ľ���Ϊ" << captain.getstep()- Ezio.getstep() << "��" << endl;
}

void mission1::choseact(int option)
{
	int option2;
	switch (option)
	{
	case 1:move(); break;
	case 2:fastmove(); break;
	case 3:
		if (Ezio.getstep() <= building_start + building_length)
		{
			climb();
		}
		else
		{
			cout << "��ǰλ���Ѿ�û�п��������м��Ľ�������" << endl;
		}
		break;
	case 4:down(); break;
	case 5:hide(); break;
	case 6:assassinate(); break;
	default:cout << "��ѡ����Чָ��,������ѡ��ָ��" << endl; cin >> option2; choseact(option2);
	}
}

void mission1::turnback()
{
	int randomnum;
	srand(time(0));
	randomnum = rand() % 10;
	if (captain.getvigilance() > randomnum && !captain.getstatu())
	{
		captain.turnback();
		cout << "���������е���������ʼ��ͷ�Ĵ�����" << endl;
		system("pause");
	}
}
mission5::mission5()
{
	captain.setname("�������������");
	captain.setHP(20);
	ori_length = 150;
	ori_building_length = 65;
	ori_distance = 80;
	ori_height = 10;
	ori_start = 5;
	ori_HP = 20;
}

void mission5::story5()
{
	cout << "----------����5��ʼ----------" << endl;
	cout << "       ����5 ����Ķ���      " << endl;
	cout << "  �������������֮��������У������º����Ĵ̿��������������������ڵĲ���ʥ����ʿ�����Լ���ǿ�̿���֯ʵ�������ǣ������������ͬ��Խ������Ϣ������ԭ����ƽ��" << endl;
	cout << "  ������ӳ���������Ȼ����ʵ���Լ��Ĳ���Ұ�ġ����ۼ������ʾ�Χ����������ά���ɡ��������׸�����������һ�Σ�����Ҫ�˽��������������" << endl<<endl;
	cout << "ɱ��������ɱ���Ǵ̿ͣ����Ǹ���������ʬ��Σ�" << endl;
	cout << "�������������԰�����ʱ˵"<<endl;
	system("pause");
	system("cls");
}

void mission5::end5()
{
	cout << "----------����5���----------" << endl;
	cout << "  ����������׷�𣬰����������������佣����������������ţ�ʹ����������ֹͣ�����������ˣ���������ڵ�ȫ�������������������������̿��ǣ����������ڰ����̷������Ϊ�����������������ɶ�ս����" << endl<<endl;
	cout << "һ������������ὫȨ��������ͳ�ε�����" << endl<<endl;
	cout << "�㶮ʲô���һ���������߽��µ�ʱ����" << endl<<endl;
	cout << "ϣ��������û���˼ǵ���Ķ���" << endl << endl;
	cout << "���������º������" << endl;
	system("pause");
	system("cls");
	initgraph(1920, 1200);
	IMAGE img;
	loadimage(&img, "����5.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}

mission3::mission3()
{
	captain.setname("�¡�����˹�о�");
	captain.setHP(15);
	area_length = 100;
	ori_length = 100;
	ori_building_length = 95;
	ori_distance = 70;
	ori_height = 3;
	ori_start = 5;
	ori_HP = 15;
}

void mission3::story3()
{
	cout << "----------����3��ʼ----------" << endl;
	cout << "      ����3 ��?����˹�о�    " << endl;
	cout << "  �������������������æ�����������������������û�ж���ı������Ը��������Լ����Ĵ̿��ǡ����ǣ������������ķ����������Ը����ǵĴ̿ʹ�ʦ��" << endl;
	cout << "  ��?����˹�о���һ������߹��Դ�����ķ������죬��������������ķ������ѡ����������ķ���������������ͼ���̿���һ���򾡡�" << endl;
	cout << "  ������ɱ����һЩ����ʿ�����������ǵķ�װ��������Ǳ���Ӫ��ɱ������ķ������ѡ�" << endl;
	system("pause");
	system("cls");
}

void mission3::end3()
{
	cout << "----------����3���----------" << endl;
	cout << "  �����о������ϸ߹���������ڰ����µ������սᣬ������ĵķ���������Ҳ��ͳ˧��ɱ�������ɾ�����?����˹�о�Ҳ�����벻�����Լ��߹��������ʵҲ�Ǵ����糣�����졣" << endl << endl;
	cout << "��ֻ��Ҫ���ء�" << endl;
	cout << "������?����˹�о���������ǰ"<<endl;
	cout << "�����ǿ�Ŭ��Ӯ�õģ����ǿ��̳л��ý�Ǯ�����ġ�" << endl;
	cout << "����������" << endl;
	system("pause");
	system("cls");
	initgraph(1280, 720);
	IMAGE img;
	loadimage(&img, "����3.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}

mission2::mission2()
{
	captain.setname("������������");
	captain.setHP(10);
	ori_length = 50;
	ori_building_length = 0;
	ori_distance = 30;
	ori_height = 0;
	ori_start = 0;
	ori_HP = 10;
}

void mission2::story2()
{
	cout << "----------����2��ʼ----------" << endl;
	cout << "          ����2 ���м�       " << endl;
	cout << "  �̿��Ǿ������ۺ�������ж�������ľ�����Դ��һ�����������мҡ����ˣ��Դ���������ʵ����" << endl;
	cout << "  ͨ������һ��Ƿ�����м����Ǯ����Ա������������������㳡���������ھ���һ��ʢ�����䡣������У������������ҵ������мң�ԭ����������������ֳ����޵���˵ĳ��ӣ������������ǡ����м��ݻ��ŵ�����������ử�¾�㡣" << endl;
	cout << endl;
	cout << "������ǰ�����������Դ������������ͻ�ʧȥ���ľ��ӣ�ֻ��һ�ˡ���ô���������ǣ�����������Դ�����" << endl;
	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void mission2::end2()
{
	cout << "----------����2���----------" << endl;
	cout << "  �����������ڰ����µ������սᡣ��֪��Ϣ���������Ȼ��ŭ������Ĵ̿������Ѿ�ǿ�������޷����ӵĳ̶ȡ�������������Щ���˵ĳ��ӡ�" << endl;
	system("pause");
	system("cls");
	initgraph(1280, 720);
	IMAGE img;
	loadimage(&img, "����2.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}

mission4::mission4()
{
	captain.setname("�޵���񡤲�����");
	captain.setHP(20);
	ori_length = 100;
	ori_building_length = 50;
	ori_distance = 60;
	ori_height = 10;
	ori_start = 5;
	ori_HP = 20;
}

void mission4::story4()
{
	cout << "----------����4��ʼ----------" << endl;
	cout << "    ����4 �����Ǽ��������   " << endl;
	cout << "  �������Ʒ������Ǽ���֮ǰ�������¾ۼ������д̿͡��̿����ƾ��˰�����Ϊ��һ���Ĵ̿͵�ʦ��������ʽ�󣬰����¸ϸ�ʥ��ʹ����׼����ɱ�޵������������" << endl << endl;;
	cout << "���õ��ģ������ǻ����ġ��ұ�֤" << endl;
	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void mission4::end4()
{
	cout << "----------����4���----------" << endl;
	cout << "  ���ս����޵�����ӵ�һ���󣬰��������̽�Ŀ��ת�������Ǹ����ˡ�����������������������֪�����µĵ��������ӵ��������⣬�������������������һ����" << endl;
	cout << "  �ڽ������ļ������У��̿���֯�������ײ����������������ԭ������ʣ��������������մ̿���֯����������������ض��š������ȴ��δ���ģ�����������ʱ�䣬�ȴ������Ԯ��������ȴ���ȵط��ֵ����������ν̻����ɵ���ʹ����ʹ�Խ̻ʵ�����������������һ��������Ҫ���������մ�һ����" << endl << endl;
	cout << "�������޷���ס�ҵģ�û�����ܹ�ɱ���ң�" << endl;
	cout << "�����������������ʱ˵��"<<endl;
	system("pause");
	system("cls");
	initgraph(1280, 720);
	IMAGE img;
	loadimage(&img, "����4.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}
