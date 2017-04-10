# C++ 基本概念
整理工作中常遇到的一些基本概念。  
### 尾置返回类型：
>`任何函数`的定义都能使用`尾置返回`，对于返回类型比较复杂的函数最为有效，比如返回类型是`数组指针`或者`数组引用`。例如：  
```C++
//func 接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组。下面两个声明等价。
int (*func(int i))[10];
auto func(int i) -> int(*)[10];
```
### 函数重载：
>如果同一作用域内的几个函数名字相同但形参列表不同，称之为`重载函数`。例如：
```C++
void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);
```
>`注`:main函数不能重载！
>不允许两个函数除返回类型外的所有要素都相同。
```C++
Record lookup(const Account&);
bool lookup(const Account&);//错误：虽然返回类型不同，但是其他的要素相同，此声明错误。
```
### 顶层const、底层const
>一般的，用顶层const表示指针本身是个常量（指针不能瞎指~）,用底层const表示指针指向的对象是一个常量（指的东西不能瞎改）。
>更加一般的是，顶层const可以表示任意的对象是常量（对所有数据类型都适用）。底层const则与指针和引用等复合类型的基本类型部分有关。
```C++
int i = 0;
//判断指针类型，可以采用从变量名到最左边，也即从里到外的顺顺序来判断。
int *const p1 = &i;//不能改变p1的值，此时p1的const是一个顶层const。（从p1往外走，先碰到const表示p1的const是不可改变的顶层const）
const int ci = 42;//不能改变ci的值，此时ci的const是一个顶层const。
const int *p2 = &ci;//允许p2的值，此时p2的const是一个底层const。(从p2往外走，先碰到*表示p2首先是个可变指针，再碰到const，表示p2指向的值不可改变也即指向一个常量,即此const为底层const)
const int *const p3 = p2;//靠右的const是顶层const，靠左的const是底层const。
const int &r = ci;//用于声明引用的const都是底层const。
```
>`注`：顶层、底层是针对const来讲。
>当执行对象的拷贝操作时，常量是顶层const还是底层const区别明显。其中顶层const不受影响：
```C++
i = ci;//正确：拷贝ci的值，ci是一个顶层const，对此操作无影响。
p2 = p3;//正确，p2,p3指向的对象类型相同，p3的顶层const的部分不影响。
```
>`注`：底层const对于对象的拷贝具有一定的限制，当执行对象的拷贝操作时，拷入和拷出的对象必须具有相同的底层const资格，或者两个对象的数据类型必须能够转换。一般来说，非常量可以转换成常量，反之不行：
```C++
int *p = p3;//错误：p3包含底层const的定义，而p没有
p2 = p3;//正确：p2和p3都是底层const
p2 = &i;//正确，int*能转换成const int*
int &r = ci;//错误：普通的int& 不能绑定到int 常量上
const int &r2 = i;正确：const int&可以绑定到一个普通int上
```
