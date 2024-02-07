#pragma once
#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>


using namespace std;


class Connection
{
private:
	SQLHENV henv;
	SQLHDBC hdbc;
	SQLHSTMT hstmt;
	wstring connectionString;
public:
	Connection(const wstring& connectionString = L"Driver={PostgreSQL ODBC Driver(ANSI)};Server=localhost;Database=Internet_sales;DSN=PostgreSQL30;Uid=postgres;Pwd=12345;");
	~Connection();
	SQLHSTMT& query(const SQLWCHAR* sql);
	void connect();
	void checkTables();
	void checkConnection();
};
