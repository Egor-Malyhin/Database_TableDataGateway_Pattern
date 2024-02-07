#include "Connection.h"

Connection::Connection(const wstring& connectionString)
{
    this->connectionString = connectionString;
    this->connect();
}

Connection::~Connection()
{
    SQLDisconnect(hdbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    SQLFreeHandle(SQL_HANDLE_ENV, henv);
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
}

SQLHSTMT& Connection::query(const wchar_t* sql)
{
    checkConnection();
    SQLRETURN retcode = SQLExecDirect(hstmt, (SQLWCHAR*)sql, SQL_NTS);
    if (retcode != SQL_SUCCESS && retcode != SQL_SUCCESS_WITH_INFO && retcode != SQL_NO_DATA) {
        SQLSMALLINT recNumber = 1;
        SQLWCHAR sqlState[6];
        SQLINTEGER nativeError;
        SQLWCHAR errMsg[SQL_MAX_MESSAGE_LENGTH];
        SQLSMALLINT errMsgLength;
        SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, recNumber, sqlState, &nativeError, errMsg, SQL_MAX_MESSAGE_LENGTH, &errMsgLength);
        std::wcerr << L"SQL query execution failed. SQL State: " << sqlState << L", Native Error: " << nativeError << L", Error Message: " << errMsg << std::endl;
        throw std::runtime_error("SQL query execution failed");
    }
    return hstmt;
}

void Connection::connect()
{
    try {
        SQLRETURN retcode;
        retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

        retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

        retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

        retcode = SQLDriverConnect(hdbc, NULL, (SQLWCHAR*)connectionString.c_str(), SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);

        retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

        if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            std::cout << "Connected to the database." << std::endl;
        }
        else {
            std::cerr << "Connection failed." << std::endl;
            throw std::runtime_error("Cannot connect to Database");
        }

        this->checkTables();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::exit(1);
    }
}

void Connection::checkTables()
{
    wstring sql = L"CREATE TABLE IF not exists products (product_code integer primary key, product_name text, model text, tech_char text, price integer, guarantee_period integer, image bytea);";
    this->query(sql.c_str());

    sql = L"CREATE TABLE IF not exists stores (store_code integer primary key, email_address text, del_payment boolean);";
    this->query(sql.c_str());

    sql = L"CREATE TABLE IF not exists orders (order_code integer primary key, store_code integer references stores(store_code), product_code integer references product(product_code), order_date date, order_time time without time zone, quantity integer, full_name_client text, phone_number text, order_conf boolean);";
    this->query(sql.c_str());

    sql = L"create table if not exists delivery (order_code integer primary key references orders(order_code), delivery_date date, delivery_time time without time zone, delivery_address text, full_name_client text, full_name_courier text);";
    this->query(sql.c_str());

}

void Connection::checkConnection()
{
    SQLRETURN retcode = SQLTables(hstmt, NULL, 0, NULL, 0, NULL, 0, NULL, 0);
    if (retcode == SQL_ERROR) {
        this->connect();
    }
    SQLCloseCursor(hstmt);
}
