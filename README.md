# CString
C++实现字符串对象

#实现了字符串对象

目前实现了一下功能

1、拷贝字符串 —— Copy()
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

3、比较字符串 —— Compare()

4、截取字符串 —— SubString()

5、替换字符串 —— Replace()

6、字符串长度 —— Length()

7、返回字符串 —— GetString()

8、把字符转化为大写 —— ToUpperCase()

9、把字符转化为小写 —— ToLowerCase()

#后续会继续添加其他功能
