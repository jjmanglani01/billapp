// CreateDatabase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Standard C++ headers */
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

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "1234"
#define DATABASE "test"

int main()
{
	sql::mysql::MySQL_Driver *_pDriver;
	sql::Connection *_pCon;
	sql::Statement *_pStmt;
	try {
		_pDriver = sql::mysql::get_mysql_driver_instance();
		_pCon = _pDriver->connect(DBHOST, USER, PASSWORD);
		_pCon->setAutoCommit(0);
		_pCon->setSchema(DATABASE);
		_pStmt = _pCon->createStatement();
		_pStmt->execute("CALL create_tables()");
		/* Remove all tables from database 
		std::string str = "";
		stmt->execute("SHOW TABLES");
		std::unique_ptr< sql::ResultSet > res;
		do {
			res.reset(stmt->getResultSet());
			while (res->next()) {
				 str += res->getString(1)+",";
			}
		} while (stmt->getMoreResults());
		str.erase(str.length() - 1);
		stmt->execute("DROP TABLE " + str);*/
		_pCon->close();
		delete _pStmt;
		delete _pCon;
		std::cout << "Created Tables Successfully";
	}
	catch (std::exception e) {
		std::cout << "Something wrong happens "<<e.what();
	}
	std::cin.ignore();
    return 0;
}

