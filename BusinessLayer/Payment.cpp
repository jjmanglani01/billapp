#include "stdafx.h"
#include "Payment.h"
#include "Response.h"

Payment::Payment()
{
}


Payment::~Payment()
{
}

void Payment::setPaymentID(unsigned long int iId)
{
	m_iPaymentID = iId;
}

unsigned long int Payment::getPaymentID()
{
	return m_iPaymentID;
}

Response Payment::setPaymentType(std::string strType)
{
	m_strPaymentType = strType;
	return generateResponse(ALL_OK);
}

std::string Payment::getPaymentType()
{
	return m_strPaymentType;
}

Response Payment::setPaymentDate(std::string strDate)
{
	m_strDate = strDate;
	return generateResponse(ALL_OK);
}

std::string Payment::getPaymentDate()
{
	return m_strDate;
}

Response Payment::setAmount(double dAmount)
{
	//TODO: check for amount is not greater than owe
	m_dAmount = dAmount;
	return generateResponse(ALL_OK);
}

double Payment::getAmount()
{
	return m_dAmount;
}

Response Payment::setChequeNo(std::string strChequeNo)
{
	m_strChequeNo = strChequeNo;
	return generateResponse(ALL_OK);
}

std::string Payment::getChequeNo()
{
	return m_strChequeNo;
}

Response Payment::setChequeDate(std::string strDate)
{
	m_strChequeDate = strDate;
	return generateResponse(ALL_OK);
}

std::string Payment::getChequeDate()
{
	return m_strChequeDate;
}
