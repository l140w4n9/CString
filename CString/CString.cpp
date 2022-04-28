#include "String.h"

void CString::AllocBuf(unsigned int nLength)
{
    m_uBufSize = nLength + 1;
    m_szBuf = new char[m_uBufSize];
}

void CString::FreeBuf()
{
    if (m_szBuf != nullptr)
    {
        delete[] m_szBuf;
        m_szBuf = nullptr;
    }
}

void CString::IntString(const char* psz)
{
    m_uLength = strlen(psz);
    AllocBuf(m_uLength);
    strcpy_s(m_szBuf, m_uBufSize, psz);
}

CString::CString()
{
    m_szBuf = new char[1];
    m_szBuf[0] = '\0';
    m_uBufSize = 1;
    m_uLength = 0;
}

CString::CString(const char* psz)
{
    IntString(psz);
}

 CString::CString(CString& Str)
{
    IntString(Str.GetString());
}

CString::~CString()
{
    FreeBuf();
}

const char* CString::GetString() const
{
    return m_szBuf;
}

void CString::Copy(const char* psz)
{
    if (m_uBufSize > strlen(psz))
    {
        m_uLength = strlen(psz);
        strcpy_s(m_szBuf, m_uLength + 1, psz); 
    }
    else
    {
        FreeBuf();
        m_uLength = strlen(psz);
        AllocBuf(m_uLength);
        strcpy_s(m_szBuf, m_uBufSize, psz);
    }
}

void CString::Copy(CString& CString)
{
    Copy(CString.GetString());
}

CString& CString::Concat(const char* psz)
{
    if (m_uBufSize > strlen(psz) + m_uLength)
    {
        m_uLength = strlen(psz) + m_uLength;
        strcat_s(m_szBuf, m_uLength + 1, psz);
    }
    else
    {
        const char* pOldBuf = GetString();
        m_uLength = strlen(psz) + m_uLength + 1;
        AllocBuf(m_uLength);
        strcpy(m_szBuf, pOldBuf);
        strcat_s(m_szBuf, m_uBufSize, psz);
        delete[] pOldBuf;
    }

    return *this;
}

CString& CString::Concat(CString& CString)
{
    return Concat(CString.GetString());
}

int CString::Compare(const char* psz)
{
    return strcmp(m_szBuf, psz);
}

int CString::Compare( CString& CString) const
{
    return strcmp(m_szBuf, CString.GetString());
}

unsigned int CString::Length()
{
    return m_uLength;
}

const char* CString::SubString(unsigned int nSubLength, unsigned int nSubIndex)
{
    if (nSubLength > m_uLength)
    {
        nSubLength = m_uLength;
    }
    if ((nSubIndex > m_uLength - 1) || nSubIndex < 0)
    {
        nSubIndex = 0;
    }
    char* szSubBuf = new char[nSubLength + 2];
    for (size_t i = 0; i < nSubLength; i++)
    {
        szSubBuf[i] = m_szBuf[nSubIndex + i];
    }
    szSubBuf[nSubLength + 1] = '\0';
    //strcpy_s(szSubBuf, nSubLength, (char *)& m_szBuf[nSubIndex]);
    return szSubBuf;
}

int CString::Replace(const char* pszSour, const char* pszDest)
{
    int nSearchFlag = 0;
    int nIndexFlag = 0;
    for (size_t i = 0; i < m_uLength; i++)
    {   
        if(m_szBuf[i] == pszSour[0])
        {
            nSearchFlag = 1;
            int nIndex = i;
            nIndexFlag = nIndex;
            for (size_t j = 0; j < strlen(pszSour); j++)
            {
                if (m_szBuf[nIndex] != pszSour[j])
                {
                    nSearchFlag = 0;
                    break;
                }
                nIndex++;
            }
            if (nSearchFlag == 1)
            {
                break;
            }
        }
    }
    if (nSearchFlag != 1)
    {
        return 0;
    }
    m_szBuf[nIndexFlag] = '\0';
    char* szTmpBuf1 = new char[nIndexFlag + 2];
    char* szTmpBuf2 = new char[m_uLength - (nIndexFlag + strlen(pszSour)) + 2];
    strcpy(szTmpBuf1, m_szBuf);
    for (size_t i = 0; i <m_uLength - (nIndexFlag + strlen(pszSour)); i++)
    {
        szTmpBuf2[i] = m_szBuf[nIndexFlag + strlen(pszSour) + 1 +i];
    }
    //szTmpBuf2[m_uLength - (nIndexFlag + strlen(pszSour)) + 1] = '\0';
    //strcpy_s(szTmpBuf2, m_uLength - (nIndexFlag + strlen(pszSour) - 1), &m_szBuf[nIndexFlag + strlen(pszSour)]);
    m_szBuf[0] = '\0';
    m_uLength = 0;
    Concat(szTmpBuf1);
    Concat(pszDest);
    Concat(szTmpBuf2);
    
    delete[] szTmpBuf1;
    delete[] szTmpBuf2;
    return 1;
}

int CString::Replace(CString& Sour, const char* pszDest)
{
    return Replace(Sour.GetString(), pszDest);
}

int CString::Replace(const char* pszSour, CString& Dest)
{
    return Replace(pszSour, Dest.GetString());
}

int CString::Replace(CString& Sour, CString& Dest)
{
    return Replace(Sour.GetString(), Dest.GetString());
}

void CString::ToUpperCase()
{
    _strupr(m_szBuf);
}

void CString::ToLowerCase()
{
    _strlwr(m_szBuf);
}

