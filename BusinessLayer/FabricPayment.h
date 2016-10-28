#pragma once
#ifndef __FABRICPAYMENT_H_INCLUDED_
#define __FABRICPAYMENT_H_INCLUDED_

#include "Payment.h"

class FabricPayment : public Payment 
{
private:
	unsigned int m_iFabricSupplierID;
public:
	BUSINESSLAYER_API FabricPayment();
	BUSINESSLAYER_API ~FabricPayment();

	BUSINESSLAYER_API void setFabricSupplierID(unsigned int iID);
	BUSINESSLAYER_API unsigned int getFabricSupplierID();
};

#endif