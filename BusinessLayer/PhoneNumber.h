#pragma once
#include <iostream>
class PhoneNumber
{
private:
	std::string _strPhoneType;
	std::string _strPhoneDescription;
	std::string _strPhoneNumber;
public:
	PhoneNumber();
	~PhoneNumber();
	struct Response setPhoneType(std::string _strPhoneType);
	std::string getPhoneType();
	struct Response setPhoneDescription(std::string _strPhoneDescription);
	std::string getPhoneDescription();
	struct Response setPhoneNumber(std::string _strPhoneNumber);
	std::string getPhoneNumber();
};

