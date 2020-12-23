// Author: Dion Wang
// Date: 2020/12/10
#ifndef IOBERSER_HPP
#define IOBERSER_HPP

#include <string>

namespace DionWW{

// 虚基类 IObserver

template<typename T>
class IObserver{
public:
    IObserver();
    virtual ~IObserver() = 0;
    virtual void update(T& msg) = 0;
};

template<typename T>
IObserver<T>::IObserver(){
}

template<typename T>
IObserver<T>::~IObserver(){
}


}

#endif 