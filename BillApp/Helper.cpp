#include "stdafx.h"
#include "Helper.h"
#include "Response.h"

Helper::Helper()
{
}


Helper::~Helper()
{
}

std::string Helper::convertCstringToString(CString str)
{
	// Convert a TCHAR string to a LPCSTR
	CT2CA pszConvertedAnsiString(str);
	// construct a std::string using the LPCSTR input
	return std::string(pszConvertedAnsiString);
}

CString Helper::convertStringToCString(std::string strValue)
{
	return CString(strValue.c_str());
}

std::wstring Helper::stringTowstring(const std::string & str)
{
	int len;
	int slength = (int)str.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

LPCWSTR Helper::convertStringToLpcwstr(std::string str)
{
	std::wstring stemp = stringTowstring(str);
	return stemp.c_str();
}


void Helper::showDialog(std::string strMsg)
{
	MessageBox(0, convertStringToLpcwstr(strMsg), (LPCWSTR)L"Error", MB_ICONERROR | MB_OK);
}

bool Helper::showDialog(struct Response stResponse)
{
	bool bRet = false;
	if (stResponse.iResponseCode != ALL_OK)
	{
		showDialog(stResponse.strResponseMsg);
		bRet = true;
	}
	return bRet;
}

bool Helper::validateDoubleString(CString value)
{
	bool stringShouldChange = true;

	LPTSTR invalidStr;

	// The code will return double value from the string and if any other characters are left after extracting double value, they will be stored in invalidStr

	double doubleValue = _tcstod(value, &invalidStr);

	if (*invalidStr)
	{
		stringShouldChange = false;
	}

	return stringShouldChange;
}


