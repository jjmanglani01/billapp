#pragma once
#ifndef __HELPER_H_INCLUDED__
#define __HELPER_H_INCLUDED__

#include <iostream>

class Helper
{
public:
	Helper();
	~Helper();
	static std::string convertCstringToString(CString str);
	static CString convertStringToCString(std::string str);
	static std::wstring stringTowstring(const std::string& str);
	static LPCWSTR convertStringToLpcwstr(std::string str);
	static void showDialog(std::string strMsg);
	static bool showDialog(struct Response);
	static bool validateDoubleString(CString value);
};

#endif