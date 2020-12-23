// Author: Dion Wang
// Date: 2020/12/10
#ifndef COBERSER_HPP
#define COBERSER_HPP

#include "IObserver.hpp"

namespace DionWW{

template<typename T>
class CObserver: public IObserver<T>{
public:
    CObserver(void(*p)(T&));
    virtual ~CObserver();
    virtual void update(T& msg);
    virtual void update(T&& msg);

    typedef void(*PtrFunc)(T&);
protected:
    PtrFunc _func;
};
    
template<typename T>
CObserver<T>::CObserver( void(*p)(T&) )
    : _func(p) {
}

template<typename T>
CObserver<T>::~CObserver(){
}

template<typename T>
void CObserver<T>::update(T& msg){
    _func(msg);
}

template<typename T>
void CObserver<T>::update(T&& msg){
    _func(msg);
}

}

#endif 