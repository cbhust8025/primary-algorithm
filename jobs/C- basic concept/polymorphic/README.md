# C++ 多态
C++的多态是面向对象的核心概念，极为重要，需要彻底的弄清楚。面向对象程序设计（Object-oriented programming）核心思想：数据抽象、继承和动态绑定。
### 1、概念储备：
##### 1、重写（覆盖 override）、重载（overload）、隐藏
* 重载 同一作用域下面的同名函数，具有相同的返回值和不同的参数列表：如果在内层作用域声明名字，它将隐藏外层作用域中声明的同名实体。在不同的作用域下无法重载函数名：
```C++
string read();
void print(const string &);
void print(double);//重载了print函数
void fooBar(int ival)
{
    bool read = false;//新作用域：隐藏了外层的read函数
    string s = read();//错误，当前的read为一个布尔值，而非一个函数。
    //通常来讲，在局部作用域声明函数时一个不好的选择。
    void print(int);//新作用域：隐藏了之前的print
    print("value:");//错误：print(const string &)被隐藏，无法调用。
    print(ival);//正确，当前print(int)可见。
    print(1.23);//正确，但是调用的是print(int)，而非print(double)。
}
```
* 重写/覆盖 派生类可以继承基类的成员，大多数时候，派生类需要使用同样的接口但是具有不一样的功能，这时候需要对基类的成员函数重新定义以覆盖（override）从基类继承而来的旧函数。对于基类来说，他的成员函数分为两种：
>* 一种是希望其派生类进行覆盖的函数，对于这类函数，常常将其定义为虚函数（virtual）。当我们使用指针或者引用调用虚函数，此次调用将被动态绑定。根据指针或引用绑定的对象类型的不同，该调用可能执行基类的版本，也可能执行某个派生类的版本。
>* 一种是希望其派生类直接继承而不进行修改的函数。
* 隐藏 类中的隐藏规则如下：
>* 如果派生类的函数与基类中的函数同名，但是参数不同。此时无论有无virtual关键字，基类的函数将被隐藏。
>* 如果派生类的函数与基类中的函数同名，并且参数也相同，若无virtual关键字，则基类的函数被隐藏。
```C++
class Base
{
public:
    virtual void f(float x){ cout << "Base::f(float) " << x << endl; }
　　void g(float x){ cout << "Base::g(float) " << x << endl; }
　　void h(float x){ cout << "Base::h(float) " << x << endl; }
}; 
class Derived : public Base
{
public:
   virtual void f(float x){ cout << "Derived::f(float) " << x << endl; }//virtual关键字，参数相同，对基类中的f函数进行了覆盖（override）
　 void g(int x){ cout << "Derived::g(int) " << x << endl; }//同名函数，参数不同，隐藏了基类中的g函数（并非只能发生在同一作用域的重载）
   void h(float x){ cout << "Derived::h(float) " << x << endl; }//同名函数，参数相同，无virtual关键字，隐藏了基类中的h函数，而非重写。
}; 
```
