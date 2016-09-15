#pragma once
#ifndef __FABRICSUPPLIER_H_INCLUDED__
#define __FABRICSUPPLIER_H_INCLUDED__
#include <iostream>
struct Response;
#include "stdafx.h"

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
public:
	BUSINESSLAYER_API  FabricSupplier();
	BUSINESSLAYER_API  ~FabricSupplier();
	
	BUSINESSLAYER_API  struct Response setSupplierID(unsigned int iId);
	BUSINESSLAYER_API  unsigned int getSupplierID();

	BUSINESSLAYER_API  struct Response setName(std::string name);
	BUSINESSLAYER_API  std::string getName();
	
	BUSINESSLAYER_API  struct Response setAddress1(std::string address1);
	BUSINESSLAYER_API  std::string getAddress1();

	BUSINESSLAYER_API  struct Response setAddress2(std::string address2);
	BUSINESSLAYER_API  std::string getAddress2();

	BUSINESSLAYER_API  struct Response setCity(std::string city);
	BUSINESSLAYER_API std::string getCity();

	BUSINESSLAYER_API struct Response setState(std::string state);
	BUSINESSLAYER_API std::string getState();

	BUSINESSLAYER_API struct Response setEmail(std::string email);
	BUSINESSLAYER_API std::string getEmail();

	BUSINESSLAYER_API bool save();
	BUSINESSLAYER_API bool update();
	BUSINESSLAYER_API bool deleteData();
};

#endif