#include "stdafx.h"
#include "FabricPayment.h"
#include "FabricPaymentService.h"

FabricPayment::FabricPayment()
{
}


FabricPayment::~FabricPayment()
{
}

void FabricPayment::setFabricSupplierID(unsigned int iID)
{
	m_iFabricSupplierID = iID;
}

unsigned int FabricPayment::getFabricSupplierID()
{
	return m_iFabricSupplierID;
}

bool FabricPayment::save()
{
	FabricPaymentService oPaymentService;
	return oPaymentService.insert(m_iFabricSupplierID, m_strPaymentType, m_strDate, m_dAmount, m_strChequeNo, m_strChequeDate);
}

bool FabricPayment::update()
{
	return false;
}
