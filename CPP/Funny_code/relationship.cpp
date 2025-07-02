#include <iostream>
#include <string>
using namespace std;

class Furry {
private:
    string name;
    double comment;

public:
    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    double getComment() {
        return comment;
    }

    void setComment(double comment) {
        this->comment += comment;
    }

    Furry() {
        name = "";
        comment = 0;
    }
};

void menu() {
    cout << "1. 为狐狐解决学业/生活/创业问题" << endl;
    cout << "2. 给狐狐陪伴" << endl;
    cout << "3. 抚慰狐狐内心的创伤" << endl;
    cout << "4. 退出" << endl;
}

int main() {
    Furry fox, wolf;
    int wolf_activity;
    fox.setName("Lanyi_adict");
    wolf.setName("Wolf_MoMo");

    cout << "请输入" << fox.getName() << "对狼的初始好感值（正数为好感/负数为恶意）：";
    double fox_comment;
    if (!(cin >> fox_comment)) {
        cout << fox.getName() << "正在潜行并坐着睡觉。" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return 0;
    }
    fox.setComment(fox_comment);

    if (fox.getComment() < 0) {
        cout << "坏" << fox.getName() << "（好感值为负数)" << endl;
    } else if (fox.getComment() > 0) {
        cout << "好" << fox.getName() << "（好感值为正数)" << endl;
    } else {
        cout << fox.getName() << "正在潜行并坐着睡觉。" << endl;
    }

    do {
        menu();
        cout << "请选择狼的行动：";
        cin >> wolf_activity;

        switch (wolf_activity) {
            case 1:
                fox.setComment(1.0);
                cout << fox.getName() << "的好感度增加了 1.0,当前好感度为：" << fox.getComment() << endl;
                break;
            case 2:
                fox.setComment(2.0);
                cout << fox.getName() << "的好感度增加了 2.0,当前好感度为：" << fox.getComment() << endl;
                break;
            case 3:
                fox.setComment(5.0);
                cout << fox.getName() << "的好感度增加了 5.0,当前好感度为：" << fox.getComment() << endl;
                break;
            case 4:
                cout << "退出程序。" << endl;
                break;
            default:
                cout << "无效的选择，请重新输入。" << endl;
        }
    } while (wolf_activity != 4);

    if(fox.getComment() >=100){
        cout << "我们在一起吧"<<endl;
    }else{
        cout<<"还需要努力哦"<<endl;
    }

    return 0;
}    