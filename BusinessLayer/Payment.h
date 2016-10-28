#pragma once
#ifndef __PAYMENT_H_INCLUDED_
#define __PAYMENT_H_INCLUDED_

#include "stdafx.h"
#include <string>
struct Response;

class Payment
{
private:
	unsigned long int m_iPaymentID;
	std::string m_strPaymentType;
	std::string m_strDate;
	double m_dAmount;
	std::string m_strChequeNo;
	std::string m_strChequeDate;
public:
	BUSINESSLAYER_API Payment();
	BUSINESSLAYER_API ~Payment();

	BUSINESSLAYER_API void setPaymentID(unsigned long int iId);
	BUSINESSLAYER_API unsigned long int getPaymentID();

	BUSINESSLAYER_API Response setPaymentType(std::string strType);
	BUSINESSLAYER_API std::string getPaymentType();

	BUSINESSLAYER_API Response setPaymentDate(std::string strDate);
	BUSINESSLAYER_API std::string getPaymentDate();

	BUSINESSLAYER_API Response setAmount(double dAmount);
	BUSINESSLAYER_API double getAmount();

	BUSINESSLAYER_API Response setChequeNo(std::string strChequeNo);
	BUSINESSLAYER_API std::string getChequeNo();

	BUSINESSLAYER_API Response setChequeDate(std::string strDate);
	BUSINESSLAYER_API std::string getChequeDate();
};

#endif