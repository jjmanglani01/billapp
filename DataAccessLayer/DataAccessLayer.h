#pragma once
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
	class DataAccessLayer {
	private:
		sql::mysql::MySQL_Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::PreparedStatement  *prepstmt;
		void connect();
		void disconnect();
	public:
		DATAACCESSLAYER_API DataAccessLayer();
		DATAACCESSLAYER_API ~DataAccessLayer();
		bool DATAACCESSLAYER_API insertToFabricSupplier(std::string strSupplierName, std::string strPhoneNo, std::string strEmail, std::string strAddress);
	};
}