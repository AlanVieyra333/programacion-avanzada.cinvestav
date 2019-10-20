//
//  WithDelegate.cpp
//  
//
//  Created by Amilcar Meneses Viveros on 14/10/19.
//
//

#include "WithDelegate.hpp"
#include "Delegate.hpp"

using namespace std;

#define YES 1 
#define NO  0

class WithDelegate {
    Delegate *delegate;

public:
    WithDelegate() {
        delegate=NULL;
    }
    
/*    ~WithDelegate() {
        if (isDelegated()==YES)
            delete delegate;
    }
    */
    
    void setDelegate(Delegate *d) {
        delegate = d;
    }
    
    int isDelegated() {
        return (delegate==NULL)?NO:YES;
    }
    
    void f1() {
        if (isDelegated()==YES) {
            delegate->f1();
        }
        else {
            cout << "WithDelegate::f1()" << endl;
        }
    }
    
    void f2() {
        if (isDelegated()==YES) {
            delegate->f2();
        }
        else {
            cout << "WithDelegate::f2()" << endl;
        }
    }
   
    void f3() {
        cout << "WithDelegate::f3()" << endl;
    }
};

int main() {
    WithDelegate w1, w2;
    Delegate1 del1;
    Delegate2 del2;
    
    cout << "w1" << endl;
    w1.f1();
    w1.f2();
    w1.f3();
    
    cout << endl << "w2" << endl;
    w2.setDelegate(&del1);
    w2.f1();
    w2.f2();
    w2.f3();
    
    cout << endl << "w2" << endl;
    w2.setDelegate(&del2);
    w2.f1();
    w2.f2();
    w2.f3();
    
}
