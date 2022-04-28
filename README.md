# CString
C++实现字符串对象

#实现了字符串对象

目前实现了一下功能

1、拷贝字符串 —— Copy()

参数：可以是字符串，可以是CString对象

例：
```
CString str1("str1");
CString str2("str2");

str2.Copy(str1);
cout << str2.GetString() << endl;
str2.Copy("hello");
cout << str2.GetString() << endl;
```
输出
```
str1
hello
```
2、拼接字符串 —— Concat()

参数：可以是字符串，可以是CString对象

例：
```
CString str1("str1");
CString str2("str2");

str2.Concat(str1);
cout << str2.GetString() << endl;
str2.Concat("hello").Concat(str1);
cout << str2.GetString() << endl;
```
输出
```
str2str1
str2str1hellostr1
```
3、比较字符串 —— Compare()

 参数：可以是字符串，可以是CString对象

返回值
 string1 与 string2 的关系
 
< 0 string1 小于 string2。
 
0 string1 等于 string2
 
> 0 string1 大于 string2
 
例：
```
CString str1("hello");
CString str2("hello");

cout << str2.Compare(str1) << endl;
cout << str2.Compare("hello") << endl;
```
输出
```
0
0
```
4、截取字符串 —— SubString()

 参数：unsigned int n1, unsigned int n2
 
 n1指定从哪里截取， n2指定截取多长
 
例：
```
CString str1("hello");

str1.SubString(1 , 2)
cout << str1.GetString() << endl;
```
输出
```
0
0
```
5、替换字符串 —— Replace()

 参数：CString& Sour/const char* Sour, CString& pszDest/const char* pszDest

 Sour指定要替换的字符串， pszDest指定替换成什么
 
例：
```
CString str1("hellotesthello");

str2.Replace("test" , "123456")
cout << str1.GetString() << endl;
```
输出
```
hello123456hello
```
6、字符串长度 —— Length()

例：
```
CString str1("hello");

cout << str1.Length() << endl;
```
输出
```
5
```
7、返回字符串 —— GetString()

例：
```
CString str1("hello");

cout << str1.GetString() << endl;
```
输出
```
hello
```
8、把字符转化为大写 —— ToUpperCase()

例：
```
CString str1("hello");
str1.ToUpperCase()
cout << str1.GetString() << endl;
```
输出
```
HELLO
```
9、把字符转化为小写 —— ToLowerCase()

例：
```
CString str1("HELLO");
str1.ToLowerCase()
cout << str1.GetString() << endl;
```
输出
```
hello
```
#觉得好用可以留言后续会继续添加其他功能
