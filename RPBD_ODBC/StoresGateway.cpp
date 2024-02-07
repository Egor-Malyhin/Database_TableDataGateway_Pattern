#include "StoresGateway.h"


const  RecordSet StoresGateaway::loadData()
{
	for (vector<string>* vector : store_data) {
		delete vector;
	}
	store_data.clear();
	try {
		SQLHSTMT stmt = connection.query(L"select * from stores order by store_code;");
		SQLRETURN retcode;
		SQLCHAR* ColumnData[3];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(255);
		ColumnData[2] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 255, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 255, nullptr);

		while (1) {
			retcode = SQLFetch(stmt);

			if (retcode == SQL_NO_DATA) {
				break;
			}

			vector<string>* rowData = new vector<string>();
			for (int i = 0; i < 3; i++) {
				string row = string((const char*)ColumnData[i]);
				rowData->push_back(row);
			}
			store_data.push_back(rowData);

		}
		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(store_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
}

const RecordSet StoresGateaway::find(int id) {
	try {
		for (vector<string>* vector : store_data) {
			delete vector;
		}
		store_data.clear();
		bool flag;
		const string preSql = "select * from stores where store_code=" + to_string(id) + ";";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLRETURN retcode;
		SQLCHAR* ColumnData[3];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(255);
		ColumnData[2] = (SQLCHAR*)malloc(255);

		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 255, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 255, nullptr);

		retcode = SQLFetch(stmt);
		if (retcode == SQL_NO_DATA) {
			flag = 0;
			return RecordSet(store_data, flag);
		}

		vector<string>* rowData = new vector<string>();
		for (int i = 0; i < 3; i++) {
			string row = string((const char*)ColumnData[i]);
			rowData->push_back(row);
		}
		store_data.push_back(rowData);

		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(store_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};

void StoresGateaway::insert(int id, string enail, bool payment) {
	try {
		const string preSql = "INSERT INTO stores VALUES (" + to_string(id) + ", '" + enail + "', '" + to_string(payment) +"');";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};


void StoresGateaway::update(int id, string enail, bool payment) {

	try {
		const string preSql = "UPDATE stores SET email_address = '" + enail + "', del_payment = '" + to_string(payment) + "' where  store_code= " + to_string(id) + ';';
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
};

void StoresGateaway::deleteById(int id) {
	try {
		const string preSqlFamilyRelationships = "DELETE from orders WHERE store_code = " + to_string(id) + ';';
		const wstring sqlFamilyRelationships = wstring(preSqlFamilyRelationships.begin(), preSqlFamilyRelationships.end());
		SQLHSTMT stmt = connection.query(sqlFamilyRelationships.c_str());
		SQLFreeStmt(stmt, SQL_CLOSE);

		const string preSql = "DELETE from stores WHERE store_code = " + to_string(id) + ';';
		const wstring sql = wstring(preSql.begin(), preSql.end());
		stmt = connection.query(sql.c_str());
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
};

int StoresGateaway::countOfRecords()
{
	SQLHSTMT stmt = connection.query(L"select count(*) from stores;");
	SQLRETURN retcode;
	SQLCHAR* ColumnData;
	ColumnData = (SQLCHAR*)malloc(7);
	SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData, 7, nullptr);
	retcode = SQLFetch(stmt);
	int code = stoi((const char*)ColumnData);
	SQLFreeStmt(stmt, SQL_CLOSE);
	return code;
};


