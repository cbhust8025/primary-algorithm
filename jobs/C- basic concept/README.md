# C++ 基本概念
整理工作中常遇到的一些基本概念。  
### 1、尾置返回类型：
>`任何函数`的定义都能使用`尾置返回`，对于返回类型比较复杂的函数最为有效，比如返回类型是`数组指针`或者`数组引用`。例如：  
```C++
//func 接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组。下面两个声明等价。
int (*func(int i))[10];
auto func(int i) -> int(*)[10];
```
### 2、函数重载：
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
### 3、顶层const、底层const
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
### 4、内联
#### 包装规模较小的操作成函数的好处：
* 阅读和理解函数的调用比读懂的等价的条件表达式容易得多。
* 使用函数可以确保行为的统一，每次相关操作都能保证按照同样的方式进行。
* 如果我们需要修改计算过程，显然修改函数要比先找到等价表达式所有出现的地方再逐一修改更加容易。
* 函数可以被其他应用重复利用，省去了程序员重新编写的代价。
#### 然而，调用函数一般比求等价表达式的值要慢一些，大多数机器上，一次函数调用其实包含着一系列工作：调用前要先保存寄存器，并在返回时恢复；可能需要拷贝实参；程序转向一个新的位置继续执行。基于这些特点，我们定义内联函数（inline），通常就是将函数在每个调用点"内联地"展开。
```C++
cout << shorterString(s1, s2) << endl;
//可在编译过程中内联展开为：
cout << (s1.size() <s2.size()? s1:s2) << endl;
//只需要进行以下内联声明即可：
inline const string & shorterString(const string &s1, const string &s2)
{
    return s1.size()<= s2.size()?  s1 : s2;
}
```
>`注`：
>* 内联说明只是向编译器发出的一个请求，编译器可以选择忽略这个请求。
>* 一般来说，内联机制用于优化规模小、流程直接、频繁调用的函数。很多遍一起都不支持内联递归函数，而且一个较长比如说50行的函数也不大可能在调用点内联的展开。
### 5、lambda函数
#### 一个lambda表达式表示一个可调用的代码单元。可以将其理解成为一个未命名的内联函数。与所有函数类似，一个lambda具有一个返回类型、一个参数列表和一个函数体。但与函数不同的是，lambda可能定义在函数内部。一个lambda表达式具有如下形式：
```C++
[capture list](parameter list) -> return type {function body}
```
>其中，capture list（捕获列表）是一个lambda所在函数中定义的局部变量的列表（通常为空）;return type、parameter list和function body与任何普通函数一样，分别表示返回类型、参数列表和函数体。但是与普通函数不同的是，lambda 必须使用尾置返回来指定返回类型。
#### 我们可以忽略（缺省）参数列表和返回类型，但是必须永远包含捕获列表和函数体。如：
```C++
auto f = [] {return 42;};//定义一个f等于某个lambda 函数，这个f为一个可调用对象，参数列表缺省代表不接受任何参数，返回42.
cout << f()<<endl;//lambda 函数与普通函数相同，使用调用运算符（）进行调用。
```
* 如果lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void。
* 捕获列表的内容表示是否使用它所在函数中的任何局部变量，为空则不使用。一个lambda通过将局部变量包含在其捕获列表中来指出将会使用这些变量。
```C++
[sz](const string &a){return a.size() >= sz;};//捕获sz变量的lambda函数会将string a的size和捕获的sz进行比较。
```
* 一个lambda 只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体重使用该变量。
* 捕获列表只用于局部非static变量，lambda可以直接使用局部static变量和它所在函数之外声明的名字。
#### 值捕获，类似参数传递，变量的捕获方式也可以是值或引用。同样的，既可以显示捕获也可以进行隐式捕获。
* 与传值参数类似，采用值捕获的前提是变量可以拷贝。与参数不同，被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝：
```C++
void fcn1()
{
    size_t v1 = 42;//局部变量
    //将v1拷贝到名为f的可调用对象
    auto f = [v1]{return v1;};
    v1 = 0;
    auto j = f();//j为42:f保存了我们创建它时的v1的拷贝。
}
//由于被捕获变量的值是在lambda创建时拷贝，因此随后对其进行修改不会影响到lambda内对应的值。
```
* 一个以引用方式捕获的变量与其他任何类型的引用的行为类似。当我们在lambda函数体内使用此变量，实际上使用的是引用所绑定的对象。
```C++
void fcn2()
{
    size_t v1 = 42;//局部变量
    //对象f2包含v1的引用
    auto f2 = [&v1]{return v1;};
    v1 = 0;
    auto j = f2();//j为0:f2保存v1的引用，而非拷贝。
}
//如果需要采用引用方式捕获一个变量，就必须确保被引用的对象在lambda执行的时候是存在的。
```
* 隐式捕获，除了显式列出我们希望使用的来自所在函数的变量之外，还可以让编译器根据lambda中的代码来推断我们要使用哪些变量。
>* &告诉编译器采用捕获引用方式,=则表示采用值捕获方式。
```C++
//sz为隐式捕获，值捕获方式
wc = find_if(words.begin(),words.end()),[=](const string &s){return s.size()>= sz;};
```
>* 如果希望一部分值捕获，一部分引用捕获，则可以进行使用隐式捕获和显示捕获。
```C++
void biggies(vector<string> &word,vector<string>::size_type sz,ostream &os = cout, char c = ' ')
{
    //其他处理略去
    //os 隐式捕获，引用捕获方式;c显示捕获，值捕获方式
    for_each(word.begin(),word.end(),[&,c](const string &s){os<<s<<c;});
    //os 显示捕获，引用捕获方式;c隐式捕获，值捕获方式
    for_each(word.begin(),word.end(),[=,&os](const string &s){os<<s<<c;});
}
```
>* 当混合使用了隐式捕获和显示捕获时，捕获列表中的第一个元素必须是一个&或=。此符号指定了默认捕获方式为引用或值。
>* 当混合使用了隐式捕获和显示捕获时，显示捕获的变量必须使用与隐式捕获不同的方式。
* 可变lambda，默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。如果我们希望能改变一个被捕获的变量的值，就必须在参数列表后加上关键字mutable。因此，可变lambda能够省略参数列表：
```C++
//值捕获可变lambda
void fun3()
{
    size_t v1 = 42;//局部变量
    //mutable可使对象f能够改变捕获的v1
    auto f = [v1]()mutable{return ++v1;};
    v1 = 0
    auto j = f();//j=43
}
```
>一个引用捕获的变量是否（如往常一样）可以修改依赖于此引用指向的是一个const类型还是一个非const类型，无需mutable关键字。
```C++
void fun4()
{
    size_t v1 = 42;//局部变量
    //v1可以使一个非const变量的引用
    //可以通过f2中的引用来改变它
    auto f2 = [&v1]{return ++v1;};
    v1 = 0
    auto j = f();//j=1
}
```
### 6、splice函数
#### splice函数用于在容器与容器之间，或者容器内部高效的移动元素。结合list这种在插入删除元素速度很快的容器使用尤佳。具有以下三种调用方式（以list这种容器为例）：  

```C++
// entire list (1)	:
void splice (const_iterator position, list& x);
void splice (const_iterator position, list&& x);
// single element (2):	
void splice (const_iterator position, list& x, const_iterator i);
void splice (const_iterator position, list&& x, const_iterator i);
// element range (3):
void splice (const_iterator position, list& x,
             const_iterator first, const_iterator last);
void splice (const_iterator position, list&& x,
             const_iterator first, const_iterator last);
```
* 第一种：移动整个容器（void splice(const_iterator position, list& x)）
>参数说明：第一个参数 position,元素的新归宿（某个容器）的迭代器，将x这个list中的所有元素按照在x中的顺序放入带position这个迭代器之前。  
position = y.begin() --->插入到y这个新容器的开头位置，第一个元素为x中的第一个元素 。 
position = y.end() --->插入到y这个新容器的最后面，最后一个元素为x中的最后一个元素。  
一旦进行操作，被移动元素的列表肯定是全部清空，变为空list
```C++
list<int> a{1,2,3,4,5,6};
list<int> b{10};
//将a这个list插入到b的起始位置
b.splice(b.begin(), a);
// b = {1,2,3,4,5,6,10};
// a = {};
```
* 第二种：移动某个容器的单个元素到某个容器（可以在自身中移动）（void splice(const_iterator position, list& x, const_iterator i)）
>参数说明：第一个参数position,元素的新归宿（某个容器）的迭代器，将x这个list中的某个迭代器i指向的元素移动到position之前，并删去x中的对应元素。  
一旦进行操作，position之前多了一个元素，x中的那个对应元素被删除。
```C++
list<int> a{1,2,3,4,5,6};
list<int> b{10,11};
//将a中的第一个元素放在b的最后
b.splice(b.end(), a, a.begin());
// b = {10,11,1};
// a = {2,3,4,5,6};
```
* 第三种：移动某个容器中的一连串元素到某个容器中（可以自身中移动）（void splice(const_iterator position, list& x, const_iterator first, const_iterator last)）
> 参数first，last是x这个需要移动元素的容器的两个迭代器，元素的区间为：[first,last)，完成操作后，x容器中的从[first,last)的所有元素都将被删除
```C++
list<int> a{1,2,3,4,5,6};
list<int> b{10,11};
//将a中的前两个元素放在b的最后
auto it = a.begin();
it++;it++;
b.splice(b.end(), a, a.begin(), it);
// b = {10,11,1,2};
// a = {3,4,5,6};
```
