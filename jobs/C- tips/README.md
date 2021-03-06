# C++ tips
>记录遇到的一些tips,大多数只有一句话，但是却很重要，在此进行记录，以便查用。  

#### 1、定义在类内部的函数是隐式的inline函数
#### 2、成员函数的声明必须在类的内部。
#### 3、构造函数的名字和类名相同，和其他函数不一样的是，构造函数没有返回类型。
#### 4、构造函数可以在类的const对象的构造过程中向其写值。
#### 5、只有当类没有声明任何构造函数时，编译器才会自动地生成默认构造函数。
#### 6、构造函数不应该轻易覆盖掉类内的初始值，除非新赋的值与原值不同。
#### 7、如果不使用类内初始值，则所有构造函数都应该显式地初始化每个内置类型的成员。
#### 8、定义在public访问说明符之后的成员在整个程序内可被访问，public成员定义类的接口。
#### 9、定义在private说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，即private部分封装了（隐藏了）类的实现细节。
#### 10、类可在第一个访问说明符之前定义成员，若使用struct关键字，则此类成员为public的；反之若使用class关键字，则此类成员为private的。
#### 11、使用class和struct定义类的唯一区别就是默认的访问权限。
#### 12、一般来说，最好在类定义开始或结束前的位置集中声明友元（允许其他类或者函数访问它的非公有成员）。
#### 13、在声明和定义函数的地方同时声明inline是合法的。然而最好只在类外部定义的地方说明inline可以便于理解。
#### 14、如果成员是const、引用，或者属于某种未提供默认构造函数的类类型，必须通过构造函数初始值列表为这些成员提供初值。
#### 15、初始值列表的初始化顺序与它们在类定义中的出现顺序一致，其中的初始值列表中的顺序不影响实际的初始化顺序。
#### 16、通常，使用vector是最好的选择，除非有很好的理由选择其他容器。
#### 17、只有顺序容器的构造函数才接受大小参数，关联容器并不支持。
#### 18、只有当容器中元素类型定义了相应的比较运算符时，我们才可以使用关系运算符来比较容器。
#### 19、容器的capacity和size：size是容器当前所含的元素个数总数，capacity是容器在不分配新的内存的前提下最多可保存多少元素。可调用reserve方法去改变capacity。
#### 20、string容器的replace操作=erase+insert，即replace是先删除对应位置的若干个元素然后插入在此位置插入指定元素。
#### 21、适配器stack(栈)/queue(队列)在默认情况下是基于deque实现的。
#### 22、泛型算法本身不会执行容器的操作，它们只会运行于迭代器之上，执行迭代器的操作。
#### 23、泛型算法向目的位置迭代器写入数据的算法假定目的位置足够大，能容纳要写入的元素。
#### 24、泛型算法独立于容器，主要依赖于迭代器。
#### 25、lambda函数必须使用尾置返回来指定返回类型。
#### 26、lambda函数不能有默认参数，也就是说实参数目永远与形参数目相等。
#### 27、编译器对未声明constructor的类合成一个default constructor，被合成的constructor的是为了满足编译器需要而合成。
#### 28、编译器合成default constructor的四种情况：（除次之外的编译器合成default constructor是implicit trivial default constructors ，实际上并不会被合成）
>* 调用成员函数的默认构造函数
>* 调用基类的默认构造函数
>* 为每一个成员初始化其虚函数机制
>* 为每一个成员初始化virtual base class机制
#### 29、编译器合成default constructor是为了满足自己的需求，不会满足程序需要。
#### 30、必须使用成员初始化列表的四种情况：
>* 当初始化一个引用成员时；
>* 当初始化一个const成员时；
>* 当调用一个基类的构造函数并且此构造函数具有一组参数的时候；
>* 当调用一个成员类的构造函数时，并且此构造函数具有一组参数的时候。
#### 31、sizeof并不是一个函数，也不是一个一元操作符，是一个特殊的编译预处理。
#### 32、union的大小取决于所有成员中，占用内存空间最大的那一个成员大小，即等于这个最大成员的大小。
#### 33、对于单纯常量，最好以const对象或enums替换#define.(一个属于枚举类型（enumerated type）的数值可权充ints被使用)
#### 34、对于形似函数的宏，最好改用inline函数替换#defines。
#### 35、任何class只要带有virtual 函数都几乎确定应该也有一个virtual 析构函数。
#### 36、尽量用const&而非直接传值到函数，这样可以节省很多操作。
#### 37、sizeof是用来计算栈大小，不涉及全局区，故类的静态成员大小sizeof不涉及。
#### 38、C++中的priority_queue默认是最大堆。
#### 39、list容器不能使用stl算法库中的sort(),必须使用自己的sort() member function.
#### 40、一般地，stl库中的容器等类的迭代器具有五个型别，大多继承自std::iterator,类型分别为：
* value_type：值类型，容器包含的值类型，```vector<int>```对应迭代器的value_type为int
* difference_type：用于表示两个迭代器之间的距离，也可以用来表示容器的最大容量，因为对于连续控件的容器而言，头尾之间的距离就是其最大容量。
* reference type:引用类型,一般情况为内嵌类型T&
* pointer type:指针类型，一般情况为内嵌类型T\*
* iterator_category:划分该迭代器行为，根据移动特性和施行操作划分为以下五类：

>- Input Iterator:这种迭代器所指的对象，不允许外界改变。只读（read only）。
>- Output Iterator:唯写（write only）。
>- Forward Iterator:允许“写入型”算法（如replace()）在此种迭代器所形成的区间上进行读写操作。
>- Bidirectional Iterator:可双向移动，如需逆向移动，则可使用此种迭代器。
>- Random Access Iterator：前四种迭代器都只提供一部分指针算数能力（前三种支持operator++,第四种支持operator--），第五种则涵盖所有指针算数能力（p+n,p-n,p[n],p1-p2,p1\<p2），也即随机读取迭代器。

#### 41、若使用```::class_name or ::func_name```则表示全局作用域的类，或函数。
