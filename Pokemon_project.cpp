#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
int aa=0;
int pokemon = 0;
class Monster {
public:
	string name;
	string type;
	int hp;
	int mp;

	Monster(string name, string type, int hp, int mp)
		:name(name), type(type), hp(hp), mp(mp) {};

	virtual void attack() = 0;  //공격기능
	void damage(int attack);    //데미지기능
	void mpConsum(int attack);  //마나 소모 기능
	void hearing(int hearing);     //회복 기능
	void showInfo();
};

//Monster 클래스 정의
void Monster::damage(int attack) {
	hp -= attack;
}
void Monster::hearing(int hearing) {
	hp += hearing;
}
void Monster::mpConsum(int attack) {
	mp -= attack;
}
void Monster::showInfo() {
	cout << "이름:" << name << endl;
	cout << "타입:" << type << endl;
	cout << "체력:" << hp << endl;
	cout << "마나:" << mp << endl;
	cout << "================" << endl;
}

//파이리 클래스
class Fire :public Monster {
public:
	Fire(string name, string type, int hp, int mp)
		:Monster(name, type, hp, mp) {};

	virtual void attack();
};
void Fire::attack() {
	cout << "파이리의 화염방산 발사" << endl;
}

//꼬부기 클래스
class Water :public Monster {
public:
	Water(string name, string type, int hp, int mp)
		:Monster(name, type, hp, mp) {};
	virtual void attack();
};
void Water::attack() {
	cout << "꼬부기의 물대포 발사" << endl;
}

//이상해씨  클래스
class Leaf :public Monster {
public:
	Leaf(string name, string type, int hp, int mp)
		:Monster(name, type, hp, mp) {};

	virtual void attack();
};
void Leaf::attack() {
	cout << "이상해씨의 잎 발사" << endl;
}
int choiceMenu() {
	int choice;

	cout << "어느 포켓몬을 고르시겠습니까?" << endl;
	cout << "1.파이리" << endl;
	cout << "2.꼬부기" << endl;
	cout << "3.이상해씨" << endl;

	cout << "선택:";
	cin >> choice;

	cout << endl;
	if (choice == 1) {
		cout << "파이리를 선택 하셨습니다" << endl;
	}
	else if (choice == 2) {
		cout << "꼬부기를 선택 하셨습니다." << endl;
	}
	else if (choice == 3) {
		cout << "이상해씨를 선택 하셨습니다" << endl;
	}
	cout << "=================" << endl;

	return choice;
}

int mainMenu() {     //메인메뉴
	int choice;

	cout << "1.공격" << endl;
	cout << "2.회복" << endl;
	cout << "3.도망간다." << endl;
	cout << "선택:";
	cin >> choice;
	cout << "================" << endl;

	return choice;
}

int attackMenu() {
	int choice;

	cout << "어느 포켓몬을 공격하시겠습니까?" << endl;
	if (pokemon == 1) {
		cout << "1.꼬부기" << endl;
		cout << "2.이상해씨" << endl;

		cout << "선택:";
		cin >> choice;

	}
	else if (pokemon == 2) {
		cout << "1.파이리" << endl;
		cout << "2.이상해씨" << endl;

		cout << "선택:";
		cin >> choice;
	}
	else if (pokemon == 3) {
		cout << "1.파이리" << endl;
		cout << "2.꼬부기" << endl;

		cout << "선택:";
		cin >> choice;
	}

	return choice;
}
int main(void) {
	Fire* monkey = new Fire("파이리", "불 타입", 100, 50);
	Water* turtle = new Water("꼬부기", "물 타입", 90, 60);
	Leaf* green = new Leaf("이상해씨", "풀 타입", 80, 70);

	int choice;


	monkey->showInfo();
	turtle->showInfo();
	green->showInfo();

	pokemon = choiceMenu();

	while (1) {
		choice = mainMenu();
		if (choice == 1) {   //공격
			if (monkey->mp == 0 || turtle->mp == 0 || green->mp == 0) {
				cout << "마나가 부족합니다." << endl;
			}
			else {

				choice = attackMenu();  //공격할 포켓몬 선택

				if (pokemon == 1) {     //내가 파이리일 경우
					monkey->attack();
					monkey->mpConsum(10);
					cout << monkey->name << "의 남은 마나 :" << monkey->mp << endl;
					cout << endl;
					if (choice == 1) {   //꼬부기 공격
						turtle->damage(10);
						cout << turtle->name << "의 남은 체력:"
							<< turtle->hp << endl;
						cout << "=======================" << endl;
					}
					else if (choice == 2) {  //이상해씨 공격
						green->damage(10);
						cout << green->name << "의 남은 체력:"
							<< green->hp << endl;
						cout << "=======================" << endl;
					}
				}
				if (pokemon == 2) {
					turtle->attack();
					turtle->mpConsum(10);
					cout << turtle->name << "의 남은 마나 :" << turtle->mp << endl;
					cout << endl;
					if (choice == 1) {
						monkey->damage(10);
						cout << monkey->name << "의 남은 체력:"
							<< monkey->hp << endl;

						cout << "=======================" << endl;
					}
					else if (choice == 2) {
						green->damage(10);
						cout << green->name << "의 남은 체력:"
							<< green->hp << endl;
						cout << "=======================" << endl;
					}
				}
				if (pokemon == 3) {
					green->attack();
					green->mpConsum(10);
					cout << green->name << "의 남은 마나 :" << green->mp << endl;
					cout << endl;
					if (choice == 1) {
						monkey->damage(10);
						cout << monkey->name << "의 남은 체력:"
							<< monkey->hp << endl;
						cout << "=======================" << endl;
					}
					else if (choice == 2) {
						turtle->damage(10);
						cout << turtle->name << "의 남은 체력:"
							<< turtle->hp << endl;
						cout << "=======================" << endl;
					}
				}
			}
		}
		else if (choice == 2) {
			if (pokemon == 1) {
				monkey->hearing(5);
				cout << monkey->name << "의 체력이 5만큼 회복됐습니다." << endl;
				cout << monkey->name << "의 현재 체력:" << monkey->hp << endl;
			}
			else if (pokemon == 2) {
				turtle->hearing(5);
				cout << turtle->name << "의 체력이 5만큼 회복됐습니다." << endl;
				cout << turtle->name << "의 현재 체력:" << turtle->hp << endl;
			}
			if (pokemon == 1) {
				green->hearing(5);
				cout << green->name << "의 체력이 5만큼 회복됐습니다." << endl;
				cout << green->name << "의 현재 체력:" << green->hp << endl;
			}
			cout << "===========================================" << endl;
		}
		else if (choice == 3) {
			cout << "도망에 성공 하셨습니다." << endl;
			cout << "프로그램이 종료됩니다." << endl;
			break;
		}
	}

	return 0;
}