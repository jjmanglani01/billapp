// DataAccessLayer.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "DataAccessManager.h"

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "1234"
#define DATABASE "test"

namespace DataAccess {

	DataAccessManager* DataAccessManager::_pInstance = nullptr;

	DataAccessManager::DataAccessManager() {
		_pDriver = std::unique_ptr<sql::mysql::MySQL_Driver>(sql::mysql::get_mysql_driver_instance());
	}

	void DataAccessManager::connect() {
		_pCon = std::unique_ptr<sql::Connection>(_pDriver->connect(DBHOST, USER, PASSWORD));
		_pCon->setAutoCommit(0);
		_pCon->setSchema(DATABASE);
	}

	void DataAccessManager::disconnect() {
		if (!_pCon->isClosed()) {
			_pCon->close();
		}
		_pCon.reset();
	}

	std::unique_ptr<sql::Connection>& DataAccessManager::getConnection()
	{
		return _pCon;
	}


	DataAccessManager::~DataAccessManager() {
		disconnect();
		_pCon.reset();
		_pDriver.reset();
	}

	DataAccessManager* DataAccessManager::getInstance()
	{
		if (_pInstance == nullptr) {
			_pInstance = new DataAccessManager();
		}
		return _pInstance;
	}

}