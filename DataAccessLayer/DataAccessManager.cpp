// DataAccessLayer.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "DataAccessManager.h"

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "1234"
#define DATABASE "test"

namespace DataAccess {

	DataAccessManager* DataAccessManager::m_pInstance = nullptr;

	DataAccessManager::DataAccessManager() {
		driver = std::unique_ptr<sql::mysql::MySQL_Driver>(sql::mysql::get_mysql_driver_instance());
		con = std::unique_ptr<sql::Connection>(driver->connect(DBHOST, USER, PASSWORD));
		con->setAutoCommit(0);
		con->setSchema(DATABASE);
	}

	void DataAccessManager::connect() {
		if (con->isClosed()) {
			con->reconnect();
		}
	}

	void DataAccessManager::disconnect() {
		if (!con->isClosed()) {
			con->close();
		}
	}

	std::unique_ptr<sql::Connection>& DataAccessManager::getConnection()
	{
		return con;
	}


	DataAccessManager::~DataAccessManager() {
		disconnect();
		con.reset();
		driver.reset();
	}
	DataAccessManager* DataAccessManager::getInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new DataAccessManager();
		}
		return m_pInstance;
	}
}