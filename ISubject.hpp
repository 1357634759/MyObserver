// Author: Dion Wang
// Date: 2020/12/10
#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include <string>

namespace DionWW{

template<typename T>
class IObserver;

// 虚基类 ISubject
template<typename T>
class ISubject{
public:
    ISubject();
    virtual ~ISubject() = 0;
    virtual int registerObserver(IObserver<T>* obj, T& msg) = 0;
    virtual int removeObserver(IObserver<T>* obj) = 0;
    virtual void notifyAll() = 0;
};

template<typename T>
ISubject<T>::ISubject(){
}

template<typename T>
ISubject<T>::~ISubject(){
}

}
#endif 