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
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(DBHOST, USER, PASSWORD);
		con->setAutoCommit(0);
		con->setSchema(DATABASE);
		stmt = con->createStatement();
		stmt->execute("CALL create_tables()");
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
		con->close();
		delete stmt;
		delete con;
		std::cout << "Created Tables Successfully";
	}
	catch (std::exception e) {
		std::cout << "Something wrong happens "<<e.what();
	}
	std::cin.ignore();
    return 0;
}

