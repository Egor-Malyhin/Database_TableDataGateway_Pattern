#include "ProductsGateaway.h"

const RecordSet ProductsGateaway::loadData() {
	for (vector<string>* vector : product_data) {
		delete vector;
	}
	product_data.clear();

	try {

		SQLHSTMT stmt = connection.query(L"select * from products order by product_code;");
		SQLRETURN retcode;
		SQLCHAR* ColumnData[7];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(255);
		ColumnData[2] = (SQLCHAR*)malloc(255);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(6*1024);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 255, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 255, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 6*1024, nullptr);


		while (1) {
			retcode = SQLFetch(stmt);

			if (retcode == SQL_NO_DATA) {
				break;
			}
			vector<string>* rowData = new vector<string>();
			for (int i = 0; i < 7; i++) {
				string row = string((const char*)ColumnData[i]);
			    rowData->push_back(row);
			}
			product_data.push_back(rowData);

		}
		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(product_data);
		
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch (const logic_error& e) {
		cerr << e.what() << endl;
	}
}

const RecordSet ProductsGateaway::find(int id)
{
	for (vector<string>* vector : product_data) {
		delete vector;
	}
	product_data.clear();

	try {
		bool flag;
		const string preSql = "select * from products where product_code=" + to_string(id) + ";";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLRETURN retcode;
		SQLCHAR* ColumnData[7];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(255);
		ColumnData[2] = (SQLCHAR*)malloc(255);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(6*1024);

		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 255, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 255, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 6*1024, nullptr);

		retcode = SQLFetch(stmt);
		if (retcode == SQL_NO_DATA) {
			flag=0;
			return RecordSet(product_data, flag);
		}
		vector<string>* rowData = new vector<string>();
		for (int i = 0; i < 6; i++) {
			string row = string((const char*)ColumnData[i]);
			rowData->push_back(row);
			rowData->push_back(row);
		}
		product_data.push_back(rowData);

		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(product_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
}


void ProductsGateaway::insert(int lastname, string name, string surname, string address, int birth_date, int _class, string image)
{
	try {
		const string preSql = "INSERT INTO products VALUES (" + to_string(lastname) + ", '" + name + "', '" + surname + "', '" + address + "', " + to_string(birth_date) + ", " + to_string(_class) + ", " +"pg_read_binary_file('" + image + "'));";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());
		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
}

void ProductsGateaway::update(int id, string name, string model, string tech, int price, int guarantee)
{
	try {
		const string preSql = "UPDATE products SET product_name = '" + name + "', model = '" + model + "', tech_char = '" + tech + "', price = " + to_string(price) + ", guarantee_period = " + to_string(guarantee) + " where  product_code= " + to_string(id) + ';';
		const wstring sql = wstring(preSql.begin(), preSql.end());

		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
}

void ProductsGateaway::deleteById(int id)
{
	try {
		const string preSql = "DELETE from products WHERE product_code = " + to_string(id) + ';';
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());
		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}
	catch (const logic_error& e) {
		cerr << e.what() << endl;
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
}

int ProductsGateaway::countOfRecords() 
{
	SQLHSTMT stmt = connection.query(L"select count(*) from products;");
	SQLRETURN retcode;
	SQLCHAR* ColumnData;
	ColumnData = (SQLCHAR*)malloc(7);
	SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData, 7, nullptr);
	retcode = SQLFetch(stmt);
	int code = stoi((const char*)ColumnData);
	SQLFreeStmt(stmt, SQL_CLOSE);
	return code;
};
