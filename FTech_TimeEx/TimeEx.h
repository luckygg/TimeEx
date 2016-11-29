//----------------------------------------------------------
// TimeEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2016-11-29 10:38
// Modified by William Kim
//----------------------------------------------------------

#pragma once

#ifdef _UNICODE
bool CStringToChar(const CString strIn, char* pchOut)
{
	if (pchOut == NULL) return false;

	size_t szCvt = 0;
	wcstombs_s(&szCvt, pchOut, strIn.GetLength()+1, strIn, _TRUNCATE);

	return true;
}
#else
bool CStringToChar(CString strIn, char* pchOut)
{
	if (pchOut == NULL) return false;

	strcpy(pchOut, CT2A(strIn));

	return true;
}

#endif

CString WriteText(CString strFormat, ...);
class CTimeEx
{
public :
	static CString GetCurrentDateInfo(CString strFormat)
	{
		CString strDate=_T("");

		SYSTEMTIME time;
		GetLocalTime(&time);

		strDate = WriteText(strFormat, time.wYear, time.wMonth, time.wDay);

		return strDate;
	}

	static CString GetCurrentTimeInfo(CString strFormat, bool bMillisecond=false)
	{
		CString strTime=_T("");

		SYSTEMTIME time;
		GetLocalTime(&time);

		if (bMillisecond == true)
			strTime = WriteText(strFormat, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		else
			strTime = WriteText(strFormat, time.wHour, time.wMinute, time.wSecond);

		return strTime;
	}

	static CString GetCurrentDateTimeInfo(CString strFormat, bool bMillisecond=false)
	{
		CString strDateTime=_T("");

		SYSTEMTIME time;
		GetLocalTime(&time);

		if (bMillisecond == true)
			strDateTime = WriteText(strFormat, time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
		else
			strDateTime = WriteText(strFormat, time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);

		return strDateTime;
	}
};

CString WriteText(CString strFormat, ...)
{
	CString strValue=_T("");
	char szFmt[MAX_PATH] = {0,};
	char szBuf[MAX_PATH] = {0,};

	CStringToChar(strFormat,szFmt);

	va_list vlist;
	va_start(vlist, strFormat);
	vsprintf_s(szBuf, szFmt, vlist);
	va_end(vlist);

	strValue = (CString)szBuf;

	return strValue;
}