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
	:captain(5,"波吉亚卫队长")
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
	cout << "----------序列1开始----------" << endl;
	cout << "     序列1 镇上新来的人      "<<endl;
	cout << "  艾吉奥来到罗马之后，发现波吉亚家族已经完全掌控了罗马城，整个城市破落不堪，散发着一种绝望的味道。而造成这一切的罪魁祸首就是西泽尔·波吉亚。教皇卫队的统领，同时也是教皇，罗德里克·波吉亚的次子。" << endl;
	cout << "  波吉亚在罗马的力量实在太强大，艾吉奥决定利用罗马人民的力量对抗波吉亚。但是，怎样才能是罗马的人民意识到反抗呢？艾吉奥决定铲除罗马城中代表波吉亚家族领地势力统治的卫队长们来达到他的目标。" << endl << endl;
	cout << "罗马的解放开始了。" << endl;
	cout << "——艾吉奥" << endl;
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
	cout << "----------序列1完成----------" << endl;
	cout << "  随着卫队长们在自己的领地中一个个神秘被暗杀，市民们逐渐明白：自己反抗暴政的时机到了，一位要带给他们自由的刺客到来了。" << endl;
	cout << "  一年内艾吉奥就吸收了许多罗马市民中的能人进入兄弟会，还搜寻到了许多落单的刺客。刺客学徒们不仅仅在罗马帮助艾吉奥对抗波吉亚，还到世界各地执行任务，最远甚至达到了印度的卡尔卡特." << endl;
	system("pause");
	system("cls");
	initgraph(1280, 721);
	IMAGE img;
	loadimage(&img, "序列1.jpg");
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
				cout << "敌人回头张望，似乎望见了你的身影，敌人警惕值增加！" << endl;
			}
		}
		cout << "你下一步的行动是:" << endl;
		cout << "1:悄无声息的逼近" << endl;
		cout << "2:向前快速疾奔" << endl;
		cout << "3:爬上周围的建筑物" << endl;
		cout << "4:从建筑物上落回到地面" << endl;
		cout << "5:迅速躲入附近的掩体" << endl;
		cout << "6:开始刺杀！" << endl;
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
		cout << "你已经站在建筑物边缘了,无法再继续向前,请重新选择下一步行动" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		if (Ezio.getstep() <= captain.getstep()-1)
		{
			Ezio.move();
			cout << "你悄无声息地接近，离敌人又近了一步" << endl;
			captain.move();
			cout << "目标完全没感觉到你的接近，仍然向前行走" << endl;
		}
		else
		{
			cout << "你离敌人太近了，再接近的话会被发现！" << endl;
		}
	}
}

void mission1::fastmove()
{
	if (Ezio.buildingstatu() && Ezio.getstep()+4 > building_start + building_length)
	{
		cout << "你已经站在建筑物边缘了,无法再继续向前,请重新选择下一步行动" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		if (Ezio.getstep() < captain.getstep() - 4)
		{
			Ezio.fastmove();
			cout << "你快速向前疾奔一段距离，离敌人近了一大段距离" << endl;
			captain.move();
			if (Ezio.buildingstatu())
			{
				cout << "你在屋顶上急速奔跑，敌人难以发现你的踪迹" << endl;
			}
			else
			{
				cout << "你在疾奔之下，难免发出动静，敌人警惕值提高" << endl;
				captain.addvigilance();
			}
		}
		else
		{
			cout << "你离敌人太近了，再接近的话会被发现！" << endl;
		}
	}
}

void mission1::climb()
{
	if (Ezio.buildingstatu())
	{
		cout << "你已经在屋顶了，请重新选择下一步行动" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		for (int i = 0; i < building_height; i++)   //climb on the building will cost time 
			captain.move();
		Ezio.climb();
		cout << "你手脚并用，转瞬之间就爬上了身边的建筑物" << endl;
	}
}

void mission1::down()
{
	if (!Ezio.buildingstatu())
	{
		cout << "你已经在地面了！请重新选择下一步行动" << endl;
		int option;
		cin >> option;
		choseact(option);
	}
	else
	{
		Ezio.down();
		captain.move();
		cout << "你施展信仰之跃，瞬间落回地面" << endl;
	}
}

void mission1::win()
{
	if (captain.gethp() <= 0)
	{
		cout << "敌人罪恶的生命终于在你的手中终结，刺杀行动成功！" << endl;
		wmark = true;
		system("pause");
	}
	else
	{
		cout << "你虽然重创敌人，却并不足以致命，贸然的出手也暴露了你的踪迹，刺杀行动宣告失败！" << endl;
		lmark = true;
		system("pause");
	}
}

void mission1::hide()
{
	Ezio.hide();
	cout << "你身影快如鬼魅，闪入周围的掩体中" <<endl;
	if (captain.getstatu())
	{
		captain.lookforward();
		cout << "敌人四处探索也无法发现你的身影，也许觉得是自己的错觉，只好继续前行" << endl;
		captain.move();
	}
	captain.move();
}

void mission1::assassinate()
{
	int choseweapon;
	cout << "敌人与你隔着" << captain.getstep() - Ezio.getstep() << "步" << endl;
	cout << "请选择你要使用的武器" << endl;
	cout << "1:袖剑 2：弓箭 3：火枪 4:重新选择" << endl;
	cin >> choseweapon;
	switch (choseweapon)
	{
	case 1:blade(captain); break;
	case 2:arrow(captain); break;
	case 3:firegun(captain); break;
	case 4:
	{
		int option; cout << "请重新选择指令" << endl;
		cout << "1:悄无声息的逼近" << endl;
		cout << "2:向前快速疾奔" << endl;
		cout << "3:爬上周围的建筑物" << endl;
		cout << "4:从建筑物上落回到地面" << endl;
		cout << "5:迅速躲入附近的掩体" << endl;
		cout << "6:开始刺杀！" << endl;
		cin >> option;
		choseact(option);
		break;
	}
	default:cout << "请重新选择正确的刺杀方式" << endl; assassinate(); break;
	}
}

void mission1::blade(enemy & e)
{
	if (Ezio.getblade().checkdistance(captain.getstep()-Ezio.getstep()))
	{
		if (!Ezio.buildingstatu())
		{
			Ezio.getblade().attack(captain);
			cout << "你出手如风，袖剑瞬间弹出，敌人的心脏已被刺穿！" << endl;
			win();
		}
		else
		{
			Ezio.getblade().attack(captain);
			cout << "你从空中跳落，如雄鹰扑食，更如死神降临，手中的袖剑已刺穿敌人胸口！" << endl;
			win();
		}
	}
	else
	{
		cout << "你和敌人的距离太过远了，难以用这种武器刺杀敌人" << endl;
		cout << "请重新选择刺杀方式" << endl;
		assassinate();
	}
}

void mission1::arrow(enemy &)
{
	if (Ezio.getarrow().checkdistance(captain.getstep() - Ezio.getstep()))
	{
			Ezio.getarrow().attack(captain);
			cout << "你掏出十字硬弩，只见箭出如风，稳稳击中敌人" << endl;
			win();
	}
	else
	{
		cout << "你和敌人的距离太过远了，难以用这种武器刺杀敌人" << endl;
		cout << "请重新选择刺杀方式" << endl;
		assassinate();
	}
}

void mission1::firegun(enemy &)
{
	if (Ezio.getfiregun().checkdistance(captain.getstep() - Ezio.getstep()))
	{
		Ezio.getfiregun().attack(captain);
		cout << "你举起右臂，牵动机关，袖中枪一触即发，敌人随即中弹倒地！" << endl;
		win();
	}
	else
	{
		cout << "你和敌人的距离太过远了，难以用这种武器刺杀敌人" << endl;
		cout << "请重新选择刺杀方式" << endl;
		assassinate();
	}
}

void mission1::lose()
{
	if (captain.getvigilance() >= 10)
	{
		cout << "你的踪迹被敌人发现了，刺杀行动宣告失败！" << endl;
		system("pause");
	}
	else
	{
		if (captain.getstep() > area_length)
		{
			cout << "敌人已经走出刺杀区域，刺杀行动宣告失败！" << endl;
			system("pause");
		}
	}
}

void mission1::printmessage()
{
	cout << "敌人姓名:    " << captain.getname()<< endl;
	cout << "敌人HP:    ";
	for (int i = 0; i < captain.gethp(); i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << "敌人警惕值:    ";
	for (int i = 0; i < captain.getvigilance(); i++)
	{
		cout << "| ";
	}
	cout << endl;
	cout << "当前所在位置为第" << Ezio.getstep() << "步" << endl;
	if (building_start > 0)
	{
		cout << "从第" << building_start << "步到第" << building_length + building_start << "步有高度为" << building_height << "的建筑物" << endl;
	}
	else
	{
		cout << "周围都是平地，并没有足以隐藏行迹的建筑物" << endl;
	}
	cout << "敌人离走出刺杀区域还有" << area_length - captain.getstep() << "步"<<endl;
	cout << "与敌人的距离为" << captain.getstep()- Ezio.getstep() << "步" << endl;
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
			cout << "当前位置已经没有可以隐藏行迹的建筑物了" << endl;
		}
		break;
	case 4:down(); break;
	case 5:hide(); break;
	case 6:assassinate(); break;
	default:cout << "请选择有效指令,请重新选择指令" << endl; cin >> option2; choseact(option2);
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
		cout << "敌人隐隐感到不安，开始回头四处搜索" << endl;
		system("pause");
	}
}
mission5::mission5()
{
	captain.setname("西泽尔·波吉亚");
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
	cout << "----------序列5开始----------" << endl;
	cout << "       序列5 人类的堕落      " << endl;
	cout << "  西泽尔身陷牢笼之后的数年中，艾吉奥和他的刺客们致力于清楚意大利境内的残余圣殿骑士势力以及增强刺客组织实力。但是，西泽尔和他的同党越狱的消息打破了原来的平静" << endl;
	cout << "  西泽尔逃出牢笼后，仍然不忘实现自己的勃勃野心。他聚集党羽，率军围攻西班牙的维亚纳。艾吉奥亲赴西班牙，这一次，他誓要了结西泽尔的性命。" << endl<<endl;
	cout << "杀了他！快杀了那刺客！把那个老杂种碎尸万段！" << endl;
	cout << "——西泽尔，面对艾吉奥时说"<<endl;
	system("pause");
	system("cls");
}

void mission5::end5()
{
	cout << "----------序列5完成----------" << endl;
	cout << "  经过漫长的追逐，艾吉奥终于用他的袖剑刺入了西泽尔的胸膛，使他疯狂的心脏停止了跳动。至此，意大利境内的全部波吉亚势力被彻底清理。而刺客们，则继续藏身黑暗，侍奉光明，为守卫人类文明的自由而战斗。" << endl<<endl;
	cout << "一个真正的领袖会将权力交予他统治的人民" << endl<<endl;
	cout << "你懂什么！我会带领人类走进新的时代！" << endl<<endl;
	cout << "希望你死后，没有人记得你的恶名" << endl << endl;
	cout << "——艾吉奥和西泽尔" << endl;
	system("pause");
	system("cls");
	initgraph(1920, 1200);
	IMAGE img;
	loadimage(&img, "序列5.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}

mission3::mission3()
{
	captain.setname("德·瓦洛斯男爵");
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
	cout << "----------序列3开始----------" << endl;
	cout << "      序列3 德?瓦洛斯男爵    " << endl;
	cout << "  西泽尔的主力部队正在忙于征服意大利的其他地区，没有多余的兵力来对付艾吉奥以及他的刺客们。于是，他请来了他的法国盟友来对付我们的刺客大师。" << endl;
	cout << "  德?瓦洛斯男爵是一个出身高贵，自大傲慢的法国将领，他就是西泽尔最大的法国盟友。他将和他的法国军团在罗马企图将刺客们一网打尽。" << endl;
	cout << "  艾吉奥杀死了一些法国士兵，换上他们的服装，并决定潜入军营暗杀西泽尔的法国盟友。" << endl;
	system("pause");
	system("cls");
}

void mission3::end3()
{
	cout << "----------序列3完成----------" << endl;
	cout << "  法国男爵那自认高贵的生命终在艾吉奥的手中终结，西泽尔的的法国盟友们也因统帅被杀而溃不成军。德?瓦洛斯男爵也许意想不到，自己高贵的生命其实也是脆弱如常人无异。" << endl << endl;
	cout << "我只想要尊重。" << endl;
	cout << "——德?瓦洛斯男爵，于临死前"<<endl;
	cout << "尊重是靠努力赢得的，不是靠继承或用金钱买来的。" << endl;
	cout << "——艾吉奥" << endl;
	system("pause");
	system("cls");
	initgraph(1280, 720);
	IMAGE img;
	loadimage(&img, "序列3.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}

mission2::mission2()
{
	captain.setname("胡安·波吉亚");
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
	cout << "----------序列2开始----------" << endl;
	cout << "          序列2 银行家       " << endl;
	cout << "  刺客们经过讨论后决定先切断西泽尔的经济来源，一个叫做‘银行家’的人，以此削弱他的实力。" << endl;
	cout << "  通过跟踪一个欠了银行家许多钱的议员，艾吉奥来到了罗马广场，这里正在举行一个盛大的庆典。在庆典中，艾吉奥终于找到了银行家，原来他就是西泽尔的兄长，罗德里克的长子，胡安·波吉亚。银行家奢华放荡的生活，今晚将会画下句点。" << endl;
	cout << endl;
	cout << "如果我们把他的收入来源砍掉，西泽尔就会失去他的军队，只身一人。那么，我问你们，他的收入来源在哪里？" << endl;
	cout << "——艾吉奥" << endl;
	system("pause");
	system("cls");
}

void mission2::end2()
{
	cout << "----------序列2完成----------" << endl;
	cout << "  胡安的生命在艾吉奥的手中终结。得知消息的西泽尔勃然大怒，罗马的刺客势力已经强大到了他无法忽视的程度。他决定铲除这些恼人的虫子。" << endl;
	system("pause");
	system("cls");
	initgraph(1280, 720);
	IMAGE img;
	loadimage(&img, "序列2.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}

mission4::mission4()
{
	captain.setname("罗德里格·波吉亚");
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
	cout << "----------序列4开始----------" << endl;
	cout << "    序列4 波吉亚家族的灭亡   " << endl;
	cout << "  在最终推翻波吉亚家族之前，艾吉奥聚集了所有刺客。刺客们推举了艾吉奥为新一代的刺客导师。经过仪式后，艾吉奥赶赴圣天使堡，准备刺杀罗德里格和西泽尔。" << endl << endl;;
	cout << "不用担心，波吉亚会死的。我保证" << endl;
	cout << "——艾吉奥" << endl;
	system("pause");
	system("cls");
}

void mission4::end4()
{
	cout << "----------序列4完成----------" << endl;
	cout << "  在终结了罗德里格复杂的一生后，艾吉奥立刻将目标转向最后的那个男人——西泽尔。但西泽尔早已料知艾吉奥的到来，他逃到了罗马郊外，集结最后的力量进行最后一搏！" << endl;
	cout << "  在接下来的几个月中，刺客组织几乎彻底铲除了西泽尔在罗马原本就所剩不多的势力。最终刺客组织和西泽尔终于面对面地对峙。西泽尔却仍未死心，而是在拖延时间，等待外面的援军。但他却惊讶地发现到来的是新任教皇所派的特使。特使以教皇的名义逮捕了西泽尔。一代枭雄终要在牢狱中终此一生！" << endl << endl;
	cout << "锁链是无法捆住我的，没有人能够杀死我！" << endl;
	cout << "——西泽尔，被逮捕时说。"<<endl;
	system("pause");
	system("cls");
	initgraph(1280, 720);
	IMAGE img;
	loadimage(&img, "序列4.jpg");
	putimage(0, 0, &img);
	system("pause");
	closegraph();
}
