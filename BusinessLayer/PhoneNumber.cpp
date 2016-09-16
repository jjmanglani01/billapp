#include "stdafx.h"
#include "PhoneNumber.h"
#include "Response.h"
#include "ValidationHelper.h"

PhoneNumber::PhoneNumber()
{
}


PhoneNumber::~PhoneNumber()
{
}

Response PhoneNumber::setPhoneType(std::string strPhoneType)
{
	int iCode = ALL_OK;
	std::string strResponseMsg;
	if (!ValidationHelper::isValidString(strPhoneType))
	{
		iCode = ERROR_CODE_NOT_ACCEPTED_VALUE;
		strResponseMsg = "PhoneType is not valid";
	}
	else
	{
		_strPhoneType = strPhoneType;
	}
	Response stResponse = generateResponse(iCode, strResponseMsg);
	return stResponse;
}

std::string PhoneNumber::getPhoneType()
{
	return _strPhoneType;
}

Response PhoneNumber::setPhoneDescription(std::string strPhoneDescription)
{
	int iCode = ALL_OK;
	std::string strResponseMsg;
	if (!ValidationHelper::isValidString(strPhoneDescription))
	{
		iCode = ERROR_CODE_NOT_ACCEPTED_VALUE;
		strResponseMsg = "PhoneDescription is not valid";
	}
	else
	{
		_strPhoneDescription = strPhoneDescription;
	}
	Response stResponse = generateResponse(iCode, strResponseMsg);
	return stResponse;
}

std::string PhoneNumber::getPhoneDescription()
{
	return _strPhoneDescription;
}

Response PhoneNumber::setPhoneNumber(std::string strPhoneNumber)
{
	int iCode = ALL_OK;
	std::string strResponseMsg;
	if (!ValidationHelper::isValidPhoneNumber(strPhoneNumber))
	{
		iCode = ERROR_CODE_NOT_ACCEPTED_VALUE;
		strResponseMsg = "PhoneNumber is not valid";
	}
	else
	{
		_strPhoneNumber = strPhoneNumber;
	}
	Response stResponse = generateResponse(iCode, strResponseMsg);
	return stResponse;
}

std::string PhoneNumber::getPhoneNumber()
{
	return _strPhoneNumber;
}
