// Author: Dion Wang
// Date: 2020/12/10
#ifndef CSUBJECT_HPP
#define CSUBJECT_HPP

#include "ISubject.hpp"
#include "IObserver.hpp"
#include <map>
#include<algorithm>

namespace DionWW{

// ObserverMap map数据结构 <id, IObserver>

// 观察者对象类的实现 Contrete Subject
template<typename T>
class CSubject: public ISubject<T>{
public:
    CSubject();
    virtual ~CSubject();
    virtual int registerObserver(IObserver<T>* pOb, T& msg);
    virtual int registerObserver(IObserver<T>* pOb, T&& msg);
    virtual int removeObserver(IObserver<T>* pOb);
    virtual void notifyAll() ;
protected:
    std::map<IObserver<T>*, T&> oberserMap;
};

template<typename T>
CSubject<T>::CSubject(){

}

template<typename T>
CSubject<T>::~CSubject(){

}

template<typename T>
int CSubject<T>::registerObserver(IObserver<T>* pOb, T& msg) {
    if(pOb == nullptr)
        return -1;
    if(oberserMap.find(pOb) != oberserMap.end()){   
        // map 中已经存在
        return -1; 
    }
    // 尝试 insert 到 map 中
    if(oberserMap.insert(std::pair<IObserver<T>*, T&>(pOb, msg)).second == false){
        // insert 失败
        return -2; 
    }
    return 0;
}

template<typename T>
int CSubject<T>::registerObserver(IObserver<T>* pOb, T&& msg) {
    if(pOb == nullptr)
        return -1;
    if(oberserMap.find(pOb) != oberserMap.end()){   
        // map 中已经存在
        return -1; 
    }
    // 尝试 insert 到 map 中
    if(oberserMap.insert(std::pair<IObserver<T>*, T&>(pOb, msg)).second == false){
        // insert 失败
        return -2; 
    }
    return 0;
}

template<typename T>
int CSubject<T>::removeObserver(IObserver<T>* pOb) {
    if(pOb == nullptr)
        return -1;

    typename std::map<IObserver<T>*, T&>::iterator itor = oberserMap.find(pOb);
    if(itor == oberserMap.end()){  
        // pOb不存在  
        return -1;
    }
    oberserMap.erase(itor);
    return 0;
}

template<typename T>
void CSubject<T>::notifyAll(){
    typename std::map<IObserver<T>*, T&>::iterator itor = oberserMap.begin();
    for(;itor!=oberserMap.end();itor++){
        T& msg = itor->second;
        IObserver<T>* pObserver = itor->first;
        pObserver->update(msg);
    }
    return ;
}

}

#endif 