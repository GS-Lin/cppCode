#include<iostream>
#include<string>
using namespace std;
class character
{
public:
	int gethp();
	void setHP(int);
	void decHP(int);
	string getname();
	void setname(string);
protected:
	int HP;
	string name;
};
class enemy :public character
{
	friend class weapon;
public:
	enemy(int, string);
	void reset();//reset all data;
	void move();
	void adddiatance(int);//add the distance to steps
	void turnback();//look back and search for the assasin
	void lookforward();
	void addvigilance();
	bool getstatu();
	int getvigilance();
	int getstep();
private:
	int vigilance,original_HP;//vigilance value;
	bool lookback_statu;//1 for looking back and 0 for not;
	int steps;//steps that the enemy escape;
};
class weapon
{
public:
	weapon(int, int);
    void attack(enemy &);//attack the enemy;
	bool checkdistance(int);//check that if this weapon can attack the enemy;
	void setdistance(int);
	void setdamage(int);
private:
	int distance;//the distance that this weapon can be used;
	int damage;//the damage of this weapon;
};
class assasin:public character
{
public:
	assasin();
	void reset();//reset all data;
	void move();
	void fastmove();
	void climb();//climb up the building
	void down();//climb down the building
	void hide();//hide to avoid being found
	void comeout();//come out to end hiding state
	bool buildingstatu();
	bool hidestatu();
	int getstep();
	weapon & getblade();
	weapon & getarrow();
	weapon & getfiregun();
private:
	weapon hidenblade, arrow, firegun;
	bool on_building;//1 for on the building and 0 for not;
	bool hiden_statu;//1 for hiden and 0 for not;
	int steps;
};
class mission1
{
public:
	mission1();
	void story1();
	void reset();//reset all data;
	void end1();
	bool start();//the interface of the mission and return the result of the game(true for win and false for lose)
	void move();
	void fastmove();
	void climb();
	void down();
	void hide();
	void assassinate();
	void blade(enemy &);
	void arrow(enemy &);
	void firegun(enemy &);
	void win();
	void lose();
	void printmessage();
	void choseact(int);
	void turnback();//enemy will randomly look back when he feels that he is in danger;
protected:
	enemy captain;
	assasin Ezio;
	bool wmark, lmark;//marks for win or lose;
	int area_length, building_height, initial_distance,building_start,building_length;
	int ori_length, ori_height, ori_distance, ori_start, ori_building_length,ori_HP;
};
class mission2 :public mission1
{
public:
	mission2();
	void story2();
	void end2();
};
class mission3 :public mission1
{
public:
	mission3();
	void story3();
	void end3();
};
class mission4 :public mission1
{
public:
	mission4();
	void story4();
	void end4();
};
class mission5 :public mission1
{
public:
	mission5();
	void story5();
	void end5();
};
