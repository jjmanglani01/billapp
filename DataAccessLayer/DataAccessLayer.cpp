// DataAccessLayer.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "DataAccessLayer.h"

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "1234"
#define DATABASE "test"

namespace DataAccess {

	DataAccessLayer::DataAccessLayer() {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(DBHOST, USER, PASSWORD);
		con->setAutoCommit(0);
		con->setSchema(DATABASE);
		stmt = con->createStatement();
		//con->close();
	}

	void DataAccessLayer::connect() {
		if (con->isClosed()) {
			con->reconnect();
		}
	}

	void DataAccessLayer::disconnect() {
		if (!con->isClosed()) {
			con->close();
		}
	}

	bool DataAccessLayer::insertToFabricSupplier(std::string strSupplierName, std::string strPhoneNo, std::string strEmail, std::string strAddress) {
		bool bRet = false;
		connect();
		try {
			prepstmt = con->prepareStatement("CALL insert_fabric_supplier(?,?,?,?)");
			prepstmt->setString(1, strSupplierName);
			prepstmt->setString(2, strPhoneNo);
			prepstmt->setString(3, strEmail);
			prepstmt->setString(4, strAddress);
			prepstmt->execute();
			con->commit();
			bRet = true;
		}
		catch (std::exception e) {
		}
		disconnect();
		return bRet;
	}

	DataAccessLayer::~DataAccessLayer() {
		disconnect();
		delete stmt;
		delete con;
		delete driver;
	}
}