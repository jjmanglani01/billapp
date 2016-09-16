#include "stdafx.h"
#include "Response.h"
#include "FabricSupplierService.h"
#include "FabricSupplier.h"
#include "PhoneNumber.h"
#include "ValidationHelper.h"

FabricSupplier::FabricSupplier()
{
}


FabricSupplier::~FabricSupplier()
{
}

Response FabricSupplier::setSupplierID(unsigned int iId)
{
	_iSupplierID = iId;
	Response stResponse;
	stResponse.iResponseCode = ALL_OK;
	stResponse.strResponseMsg = (std::string)NOERROR;
	return stResponse;
}

unsigned int FabricSupplier::getSupplierID()
{
	return _iSupplierID;
}

Response FabricSupplier::setName(std::string name)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;
	if (name.empty()) {
		iCode = ERROR_CODE_NOT_NULL;
		strResponse = "Supplier Name can not be empty";
	}
	else if (name.length() > LENGTH_100) {
		iCode = ERROR_CODE_LENGTH;
		strResponse = "Supplier Name should be less than 100";
	}
	else {
		_strName = name;
	}

	Response stResponse = generateResponse(iCode,strResponse);
	return stResponse;
}

std::string FabricSupplier::getName()
{
	return _strName;
}

Response FabricSupplier::setAddress1(std::string address1)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;

	 if (address1.length() > LENGTH_200) {
		 iCode = ERROR_CODE_LENGTH;
		 strResponse = "Address1 should be less than 200";
	}
	else {
		_strAddress1 = address1;
	}
	Response stResponse = generateResponse(iCode, strResponse);
	return stResponse;
}

std::string FabricSupplier::getAddress1()
{
	return _strAddress1;
}

Response FabricSupplier::setAddress2(std::string address2)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;
	if (address2.length() > LENGTH_200) {
		iCode = ERROR_CODE_LENGTH;
		strResponse = "Address2 " + (std::string)LENGTH_LESS_THAN_200;
	}
	else {
		_strAddress2 = address2;
	}
	Response stResponse = generateResponse(iCode, strResponse);
	return stResponse;
}

std::string FabricSupplier::getAddress2()
{
	return _strAddress2;
}

Response FabricSupplier::setCity(std::string city)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;
	if (city.length() > LENGTH_20) {
		iCode = ERROR_CODE_LENGTH;
		strResponse = "City " + (std::string)LENGTH_LESS_THAN_20;
	}
	else {
		_strCity = city;
	}
	Response stResponse = generateResponse(iCode,strResponse);
	return stResponse;
}

std::string FabricSupplier::getCity()
{
	return _strCity;
}

Response FabricSupplier::setState(std::string state)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;
	if (state.length() > LENGTH_15) {
		iCode = ERROR_CODE_LENGTH;
		strResponse = "State " + (std::string)LENGTH_LESS_THAN_15;
	}
	else {
		_strState = state;
	}
	Response stResponse = generateResponse(iCode, strResponse);

	return stResponse;
}

std::string FabricSupplier::getState()
{
	return _strState;
}

Response FabricSupplier::setEmail(std::string email)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;
	if (email.length() > LENGTH_50) 
	{
		iCode = ERROR_CODE_LENGTH;
		strResponse = "Email " + (std::string)LENGTH_LESS_THAN_50;
	}
	else if (ValidationHelper::isValidEmailAddress(email))
	{
		iCode = ERROR_CODE_NOT_ACCEPTED_VALUE;
		strResponse = "Email address is not valid";
	}
	else 
	{
		_strEmail = email;
	}
	Response stResponse = generateResponse(iCode, strResponse);
	return stResponse;
}

std::string FabricSupplier::getEmail()
{
	return _strEmail;
}

Response FabricSupplier::addPhoneNumber(std::string strPhoneType, std::string strPhoneDescription, std::string strPhoneNumber)
{
	PhoneNumber oPhone;
	Response stResponse = oPhone.setPhoneType(strPhoneType);
	if (stResponse.iResponseCode != ALL_OK)
	{
		return stResponse;
	}

	stResponse = oPhone.setPhoneDescription(strPhoneDescription);
	if (stResponse.iResponseCode != ALL_OK)
	{
		return stResponse;
	}

	stResponse = oPhone.setPhoneNumber(strPhoneNumber);
	if (stResponse.iResponseCode != ALL_OK)
	{
		return stResponse;
	}
	FabricSupplierService oService;
	bool bInserted = oService.insertPhoneNumber(_iSupplierID, strPhoneType, strPhoneDescription, strPhoneNumber);
	if (!bInserted)
	{
		return  generateResponse(ERROR_CODE_DATABASE, (std::string)DATABASE_ERROR);
	}
	_vecPhone.push_back(oPhone);
	return stResponse;
}

std::vector<PhoneNumber> FabricSupplier::getPhoneNumbers()
{
	return _vecPhone;
}

bool FabricSupplier::save()
{
	bool bRet = false;
	FabricSupplierService oService;
	 unsigned int iRet = oService.insert(_strName, _strAddress1, _strAddress2, _strCity, _strState, _strEmail);
	 if (iRet)
	 {
		 setSupplierID(iRet);
		 bRet = true;
	 }
	 return bRet;
}

bool FabricSupplier::update()
{
	return 0;
}

bool FabricSupplier::deleteData()
{
	return 0;
}
