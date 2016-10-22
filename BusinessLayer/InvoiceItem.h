#pragma once
#ifndef __INVOICEITEM_H_INCLUDED_
#define __INVOICEITEM_H_INCLUDED_

struct InvoiceItem {
	InvoiceItem() : m_bAdd(true) {}
	unsigned int m_iItemId;
	double m_dUnitPrice;
	double m_dQuantity;
	bool m_bAdd;
};

typedef struct InvoiceItem InvoiceItem;

#endif