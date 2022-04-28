#pragma once
#include <stdlib.h>
#include <string.h>

class CString
{
private:
	char* m_szBuf;
	unsigned int m_uBufSize;
	unsigned int m_uLength;
private:
	//申请内存空间
	void AllocBuf(unsigned int nLength);

	//释放内存空间
	void FreeBuf();

	//初始化
	void IntString(const char* psz);
public:
	//构造函数
	CString();
	explicit CString(const char* psz);
	CString(CString& CString);
	//析构函数
	~CString();

	//获取字符串
	const char* GetString() const;

	//拷贝字符串
	void Copy(const char* psz);
	//拷贝字符对象
	void Copy(CString& CString);

	//拼接字符串
	CString& Concat(const char* psz);
	//拼接字符对象
	CString& Concat(CString& CString);

	//比较字符串大小
	int Compare(const char* psz);
	//比较字符对象大小
	int Compare(CString& CString) const;

	//获取字符串对象长度
	unsigned int Length();

	//截取字符串
	const char* SubString(unsigned int nSubLength, unsigned int nSubIndex = 0);

	//字符串替换字符串
	int Replace(const char* pszSour, const char* pszDest);
	int Replace(CString& Sour, const char* pszDest);
	int Replace(const char* pszSour, CString& Dest);
	int Replace(CString& Sour, CString& Dest);

	//把字符转化为大写
	void ToUpperCase();
	//把字符转化为小写
	void ToLowerCase();
};

