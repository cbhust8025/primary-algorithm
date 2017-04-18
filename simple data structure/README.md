# simple data structure--简单数据结构
<p>简单数据结构如线性表，栈，队列是日常使用频率最高的数据结构，将从以下的几个角度对其进行分析记忆。
    <ul>
    <li>实现方式</li>
    <li>存储方式</li>
    <li>使用注意事项</li>
</ul>
</p>

### 如何提取float的前N位小数
```C++
float ttt = 100.20146513;
float cd = ttt - int(ttt);//去掉小数点之前的数
int N = 3;
for (int i = 0;i < N;i++)
{
	cd *= 10;
	cout << (int) cd << " ";
	cd = cd - (int)cd;
}
```
