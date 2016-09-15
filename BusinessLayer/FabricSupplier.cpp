#include "stdafx.h"
#include "Response.h"
#include "FabricSupplierService.h"
#include "FabricSupplier.h"

FabricSupplier::FabricSupplier()
{
}


FabricSupplier::~FabricSupplier()
{
}

struct Response FabricSupplier::setSupplierID(unsigned int iId)
{
	_iSupplierID = iId;
	struct Response stResponse;
	stResponse.iResponseCode = ALL_OK;
	stResponse.strResponseMsg = (std::string)NOERROR;
	return stResponse;
}

unsigned int FabricSupplier::getSupplierID()
{
	return _iSupplierID;
}

struct Response FabricSupplier::setName(std::string name)
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

	struct Response stResponse = generateResponse(iCode,strResponse);
	return stResponse;
}

std::string FabricSupplier::getName()
{
	return _strName;
}

struct Response FabricSupplier::setAddress1(std::string address1)
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
	struct Response stResponse = generateResponse(iCode, strResponse);
	return stResponse;
}

std::string FabricSupplier::getAddress1()
{
	return _strAddress1;
}

struct Response FabricSupplier::setAddress2(std::string address2)
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
	struct Response stResponse = generateResponse(iCode, strResponse);
	return stResponse;
}

std::string FabricSupplier::getAddress2()
{
	return _strAddress2;
}

struct Response FabricSupplier::setCity(std::string city)
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
	struct Response stResponse = generateResponse(iCode,strResponse);
	return stResponse;
}

std::string FabricSupplier::getCity()
{
	return _strCity;
}

struct Response FabricSupplier::setState(std::string state)
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
	struct Response stResponse = generateResponse(iCode, strResponse);

	return stResponse;
}

std::string FabricSupplier::getState()
{
	return _strState;
}

struct Response FabricSupplier::setEmail(std::string email)
{
	int iCode = ALL_OK;
	std::string strResponse = (std::string)NOERROR;
	if (email.length() > LENGTH_50) {
		iCode = ERROR_CODE_LENGTH;
		strResponse = "Email " + (std::string)LENGTH_LESS_THAN_50;
	}
	else {
		_strEmail = email;
	}
	struct Response stResponse = generateResponse(iCode, strResponse);
	return stResponse;
}

std::string FabricSupplier::getEmail()
{
	return _strEmail;
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
