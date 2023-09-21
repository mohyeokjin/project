#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
    private:
    string name, weapon;
    int level, power, w_kind;
    int hp = 100;

    public:
    Character () {}
    Character(string name, int level, int hp) : name(name), level(level), hp(hp) {}

    vector<string> w_list = {};

    int Attack() { return power; }
    int Gethp() { return hp; }
    int Level_up() { return level += 1; }

    string getname() { return name; }
    int getlevel() { return level; }
    int gethp() { return hp; }
    int getdamage() { return hp -= power; }
    
    void setname(string name) {this -> name = name;}
    void setlevel(int level) {this -> level = level; }
    void sethp(int hp) {this -> hp = hp; }
    void setdamage(int power) { this -> power = power; }

    void Getweapon() {
        cout << "습득할 무기를 고르세요. (1 : 칼, 2 : 총) : ";
        cin >> w_kind;
        if(w_kind == 1) w_list.push_back("칼");
        if(w_kind == 2) w_list.push_back("총");
    }

    void Info() {
        cout << "===============캐릭터 정보===============" << endl;
        cout << "캐릭터 이름 : " << name << endl;
        cout << "현재 레벨 : " << level << endl;
        cout << "현재 체력 : " << hp << endl;
        cout << "현재 보유하고 있는 무기 : ";
        if(w_list.size() == 0) {
            cout << "보유하고 있는 무기가 없습니다." << endl;
        }
        else {
            for(int i = 0; i < w_list.size(); i++) {
                cout << w_list[i] << "  ";
            }
        }
        cout << endl << "========================================" << endl;
    }
};

class Weapon {
    protected:
    int gun, sword, power, att_num;

    public:
    virtual void attack() = 0;
    
};

class Sword : public Weapon {
    public:
    int hp = 100;
    int power = 5;
    int att_num = 3;
    int damage;

    int getDamage() { return damage; }

    void setDamage(int damage) {this -> damage = damage;}

    void attack() {
        damage = (power * att_num);
        cout << "찌르기!" << endl;
    }
};

class Gun : public Weapon {
    public:
    int hp = 100;
    int power = 10;
    int att_num = 1;
    int damage;

    int getDamage() { return damage; }

    void setDamage(int hp) {this -> hp = hp;}

    void attack() {
        damage = (power * att_num);
        cout << "총쏘기!" << endl;
    }
};

int main(void) {
    string name;
    int hp = 100;
    int level = 1;
    int order, w_order, chooseWeapon;
    vector<string> weapon;

    Character game(name, level, hp);
    Sword sword;
    Gun gun;

    cout << "프로젝트 7. 클래스 종합 - 게임 만들기" << endl;
    cout << "이름을 입력해주세요. : ";
    cin >> name;
    game.setname(name);

    cout << "캐릭터가 생성되었습니다!" << endl;
    game.Info();

    while(1) {
        cout << "어떤 동작을 실행하시겠습니까? (1 : 레벨업, 2 : 무기 획득, 3 : 공격, 4 : 현재 정보, 0 : 종료) ";
        cin >> order;

        if(order == 1) {
            game.setlevel(game.Level_up());
            cout << "level up!!" << endl << "현재 레벨 : " << game.getlevel() << endl;
        }

        if(order == 2) {
            game.Getweapon();
        }

        if(order == 3) {
            cout << "공격할 무기를 선택하세요. (1 : 칼, 2 : 총) :" << endl;
            cin >> chooseWeapon;

            if(chooseWeapon == 1) {
                sword.attack();
                game.setdamage(sword.getDamage());
                if(game.getdamage() <= 0) {
                    game.sethp(0);
                }
                cout << "칼로 공격 당했습니다." << endl << "현재 체력 : " << game.gethp() << endl;
            }
            if(chooseWeapon == 2) {
                gun.attack();
                game.setdamage(gun.getDamage());
                if(game.getdamage() <= 0) {
                    game.sethp(0);
                }
                cout << "총으로 공격 당했습니다." << endl << "현재 체력 : " << game.gethp() << endl;
            }
        }

        if(order == 4) {
            game.Info();
        }

        if(order == 0) {
            cout << "게임을 종료합니다." << endl;
            break;
        }

        if(game.gethp() <= 0) {
            hp = 0;
            cout << "체력이 " << hp << "이 되었습니다." << endl;
            cout << "GAME OVER!!" << endl;
            break;
        }


    }





}