#include<iostream>
#include <string>
#include "CObserver.hpp"
#include "CSubject.hpp"
using namespace std;
using namespace DionWW;



void print(std::string& msg){
    cout<< msg <<endl;
}

int main(){
    // 被观察对象
    CSubject<string> sbj;
    
    // 注册观察者1
    CObserver<string> ob1(print);
    sbj.registerObserver(&ob1, string("message 1"));
    // 注册观察者2
    CObserver<string> ob2(print);
    sbj.registerObserver(&ob2, string("message 2"));
    // 注册观察者3
    CObserver<string> ob3(print);
    sbj.registerObserver(&ob3, string("message 3"));
    // 通知所有观察者
    sbj.notifyAll();
    // 移除观察者2
    sbj.removeObserver(&ob2);
    // 通知所有观察者
    sbj.notifyAll();
    
    return 0;
}