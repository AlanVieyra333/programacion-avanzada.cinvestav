//
//  Delegate.hpp
//  
//
//  Created by Amilcar Meneses Viveros on 14/10/19.
//
//

#ifndef Delegate_hpp
#define Delegate_hpp

#include <iostream>

class Delegate {
public:
    virtual void f1() = 0;
    virtual void f2() = 0;
};

class Delegate1 : public Delegate {
public:
    virtual void f1();
    virtual void f2();
};

class Delegate2 : public Delegate {
public:
    virtual void f1();
    virtual void f2();
};


#endif /* Delegate_hpp */
