#include <bits/stdc++.h>
using namespace std;
class Maths{
    public:
    int sum(int a,int b){
        return a+b;
    }
    int sum (int a,int b,int c){
        return a+b+c;
    }
    int sum(int a, float b){
        return a+b;
    }
};

class Param{
    public:
    int val;
    void operator +(Param &p2){
        int val1 = this->val;
        int val2 = p2.val;
        cout<<(val2-val1);
    }
};

class Animal{
    public:

    Animal(){
        cout<<"I am inside the Animal constructor"<<endl;
    }
    void speak(){
        cout<<"Speaking"<<endl;
    }
    
    // For Upcasting
    // virtual void speak(){
    //     cout<<"Speaking"<<endl;
    // }

};

class Dog: public Animal{
    public:
    Dog(){
        cout<<"I am inside the Dog constructor"<<endl;
    }
    //override
    void speak(){
        cout<<"Barking"<<endl;
    }
};


int main(){
    Maths obj;
    cout<<obj.sum(2,5)<<endl;
    cout<<obj.sum(2,5,7)<<endl;
    Param p1,p2;
    p1.val = 40;
    p2.val = 8;
    //Operator overloading
    //Printing difference using + operator
    p2+p1;
    cout<<endl;
    // Animal a;
    // a.speak();
    // Dog b;
    // b.speak();

    //Upcasting
    // Animal* a = new Dog();
    // a->speak();

    //Downcasting
    // Dog*b = new Animal();
    // Dog*b = (Dog* )new Animal();
    // b->speak();

    Animal* a = new Animal();
    Animal* b = new Dog();
    Dog* c = (Dog*) new Animal();
    Dog* d = new Dog();
}