#include "stdafx.h"
#include "FabricPayment.h"


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
