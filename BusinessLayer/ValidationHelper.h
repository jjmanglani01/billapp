#pragma once
#ifndef __VALIDATIONHELPER_H_INCLUDED__
#define __VALIDATIONHELPER_H_INCLUDED__

#include <string>
class ValidationHelper
{
public:
	ValidationHelper();
	~ValidationHelper();
	static bool isCharacter(const char character);
	static bool isSpecialCharacter(const char character);
	static bool isNumber(const char character);
	static bool  isValidPhoneNumber(const std::string& strNumber);
	static bool isValidEmailAddress(const std::string&  strEmailAddress);
	static bool isValidString(const std::string& strValue);
};

#endif