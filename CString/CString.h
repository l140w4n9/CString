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
	//�����ڴ�ռ�
	void AllocBuf(unsigned int nLength);

	//�ͷ��ڴ�ռ�
	void FreeBuf();

	//��ʼ��
	void IntString(const char* psz);
public:
	//���캯��
	CString();
	explicit CString(const char* psz);
	CString(CString& CString);
	//��������
	~CString();

	//��ȡ�ַ���
	const char* GetString() const;

	//�����ַ���
	void Copy(const char* psz);
	//�����ַ�����
	void Copy(CString& CString);

	//ƴ���ַ���
	CString& Concat(const char* psz);
	//ƴ���ַ�����
	CString& Concat(CString& CString);

	//�Ƚ��ַ�����С
	int Compare(const char* psz);
	//�Ƚ��ַ������С
	int Compare(CString& CString) const;

	//��ȡ�ַ������󳤶�
	unsigned int Length();

	//��ȡ�ַ���
	const char* SubString(unsigned int nSubLength, unsigned int nSubIndex = 0);

	//�ַ����滻�ַ���
	int Replace(const char* pszSour, const char* pszDest);
	int Replace(CString& Sour, const char* pszDest);
	int Replace(const char* pszSour, CString& Dest);
	int Replace(CString& Sour, CString& Dest);

	//���ַ�ת��Ϊ��д
	void ToUpperCase();
	//���ַ�ת��ΪСд
	void ToLowerCase();
};

