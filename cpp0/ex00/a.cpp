#include <iostream>
#include <string.h>
#include <cctype>

class marine {
	int 	hp;
	int		coord_x, coord_y;
	int		damage;
	bool	is_dead;
	char	*name;

	public:
		marine();
		marine(int x, int y, char *marine_name);
		marine(int x, int y);
		~marine();

		int		attack();
		void	be_attacked(int damage_earn);
		void	move(int x, int y);
		void	show_status();
};

class photon_cannon {
	int		hp, shild;
	int		coord_x, coord_y;
	int		damage;
	char	*name;

	public:
		photon_cannon(int x, int y);
		photon_cannon(int x, int y, char *name);
		photon_cannon(const photon_cannon &pc);
		~photon_cannon();

		void	show_status();
};

void	photon_cannon::show_status(){
	std::cout << "**** " << name << " ****" << std::endl;
	std::cout << "    Hp : " << hp << std::endl;
	std::cout << "    Shild : " << shild << std::endl;
	std::cout << "Location ( " << coord_x << ", " << coord_y << " ) " << std::endl;
	std::cout << "**** " << "출력완료"<< " ****" << std::endl << std::endl;
}

photon_cannon::photon_cannon(const photon_cannon &pc){
	std::cout << "복사 생성자 호출!" << std::endl;
	hp = shild = pc.hp;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
	name = new char[strlen(pc.name)];
	strcpy(name, pc.name);
}

photon_cannon::photon_cannon(int x, int y){
	hp = shild = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = NULL;
}

photon_cannon::photon_cannon(int x, int y, char *p_name){
	hp = shild = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = new char[strlen(p_name)];
	strcpy(name, p_name);
}

photon_cannon::~photon_cannon(){
	if (name != NULL)
		delete []name;
	name = NULL;
}

marine::~marine() {
	std::cout << name << "소멸자 호출" << std::endl;
	if (name != NULL)
	{
		delete []name;
	}
}

marine::marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

marine::marine(int x, int y, char *marine_name) {
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);
}

marine::marine(int x, int y) {
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
	name = NULL;
}

int		 marine::attack(){
	return damage;
}

void	marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	std::cout << damage_earn << "damage 를 입었습니다." << std::endl;
	if (hp <= 0)
		is_dead = true;
}

void	marine::move(int x,int y) {
	coord_x = x;
	coord_y = y;
}

void	marine::show_status() {
	std::cout << "**** " << name << " ****" << std::endl;
	std::cout << "    Hp : " << hp << std::endl;
	std::cout << "Location ( " << coord_x << ", " << coord_y << " ) " << std::endl;
	std::cout << "**** " << "출력완료"<< " ****" << std::endl << std::endl;
}

int main(int argc, char *argv[]) {
	marine *marines[100];

	marines[0] = new marine(1,2, "Marine 1");
	marines[1] = new marine(3,4, "Marine 2");

	marines[0]->show_status();
	marines[1]->show_status();
	marines[0]->move(1,2);
	marines[1]->move(3,4);

	std::cout << "마린 1 이 마린 2 를 공격" << std::endl;
	marines[1]->be_attacked(marines[0]->attack());
		std::cout << "마린 1 이 마린 2 를 공격" << std::endl;
	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];

	photon_cannon pc(1, 2, "Cannon");
	photon_cannon pc2(pc);

	pc.show_status();
	pc2.show_status();
	return 0;
}
