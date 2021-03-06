#pragma once
#ifndef __FABRICSUPPLIER_H_INCLUDED__
#define __FABRICSUPPLIER_H_INCLUDED__

#include <string>
#include <vector>
struct Response;
class PhoneNumber;
#include "stdafx.h"
#include <memory>

const std::string strId = "FabricSupplierId";
const std::string strSuppliername = "SupplierName";
const std::string strAddress1 = "Address1";
const std::string strAddress2 = "Address2";
const std::string strCity = "City";
const std::string strState = "State";
const std::string strEmail = "Email";
const std::string strBillAmount = "BillAmount";
const std::string strPaidAmount = "PaidAmount";

class FabricSupplier
{
private:
	unsigned int _iSupplierID;
	std::string _strName;
	std::string _strAddress1;
	std::string _strAddress2;
	std::string _strCity;
	std::string _strState;
	std::string _strEmail;
	std::vector<PhoneNumber> _vecPhone;
	static std::vector< std::unique_ptr<FabricSupplier > > m_vecFabricSupplier;
public:
	BUSINESSLAYER_API  FabricSupplier();
	BUSINESSLAYER_API  ~FabricSupplier();

	BUSINESSLAYER_API Response setSupplierID(unsigned int iId);
	BUSINESSLAYER_API  unsigned int getSupplierID();

	BUSINESSLAYER_API Response setName(std::string name);
	BUSINESSLAYER_API  std::string getName();

	BUSINESSLAYER_API Response setAddress1(std::string address1);
	BUSINESSLAYER_API  std::string getAddress1();

	BUSINESSLAYER_API Response setAddress2(std::string address2);
	BUSINESSLAYER_API  std::string getAddress2();

	BUSINESSLAYER_API Response setCity(std::string city);
	BUSINESSLAYER_API std::string getCity();

	BUSINESSLAYER_API Response setState(std::string state);
	BUSINESSLAYER_API std::string getState();

	BUSINESSLAYER_API Response setEmail(std::string email);
	BUSINESSLAYER_API std::string getEmail();

	BUSINESSLAYER_API Response addPhoneNumber(std::string _strPhoneType, std::string _strPhoneDescription, std::string _strPhoneNumber);
	BUSINESSLAYER_API std::vector<PhoneNumber> getPhoneNumbers();

	BUSINESSLAYER_API bool save();
	BUSINESSLAYER_API bool update();
	BUSINESSLAYER_API bool deleteData();
	BUSINESSLAYER_API static std::vector< std::unique_ptr< FabricSupplier > >& getAllItem();
	BUSINESSLAYER_API static std::unique_ptr<FabricSupplier>& getItemById(unsigned int iId);
};

#endif