#pragma once
#ifndef __DATAACCESSMANAGER_H_INCLUDED__
#define __DATAACCESSMANAGER_H_INCLUDED__

#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

/* MySQL Connector/C++ specific headers */
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>

#ifdef DATAACCESSLAYER_EXPORTS
#define DATAACCESSLAYER_API __declspec(dllexport) 
#else
#define DATAACCESSLAYER_API __declspec(dllimport) 
#endif

namespace DataAccess {
	class DataAccessManager {
	private:
		std::unique_ptr<sql::mysql::MySQL_Driver> _pDriver;
		std::unique_ptr<sql::Connection> _pCon;
		DataAccessManager();
		static DataAccessManager *_pInstance;
		 ~DataAccessManager();
	public:
		void disconnect();
		void connect();
		std::unique_ptr<sql::Connection>& getConnection();
	    static DataAccessManager* getInstance();
	};
}

#endif