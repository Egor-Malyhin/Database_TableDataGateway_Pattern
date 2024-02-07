#include "DeliveryGateaway.h"

const RecordSet DeliveryGateaway::loadData(){
	for (vector<string>* vector : delivery_data) {
		delete vector;
	}
	delivery_data.clear();
	try {
		SQLHSTMT stmt = connection.query(L"select * from delivery order by order_code;");
		SQLRETURN retcode;
		SQLCHAR* ColumnData[8];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(255);
		ColumnData[2] = (SQLCHAR*)malloc(255);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(255);
		ColumnData[7] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 255, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 255, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 255, nullptr);
		SQLBindCol(stmt, 8, SQL_C_CHAR, ColumnData[7], 255, nullptr);
	


		while (1) {
			retcode = SQLFetch(stmt);

			if (retcode == SQL_NO_DATA) {
				break;
			}

			vector<string>* rowData = new vector<string>();
			for (int i = 0; i < 8; i++) {
				string row = string((const char*)ColumnData[i]);
				rowData->push_back(row);
			}
			delivery_data.push_back(rowData);

		}
		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(delivery_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};

const RecordSet DeliveryGateaway::find(int id) {
	try {

		for (vector<string>* vector : delivery_data) {
			delete vector;
		}
		delivery_data.clear();

		bool flag;
		const string preSql = "select * from delivery where order_code=" + to_string(id) + ";";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLRETURN retcode;
		SQLCHAR* ColumnData[8];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(255);
		ColumnData[2] = (SQLCHAR*)malloc(255);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(255);
		ColumnData[7] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 255, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 255, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 255, nullptr);
		SQLBindCol(stmt, 8, SQL_C_CHAR, ColumnData[7], 255, nullptr);

		retcode = SQLFetch(stmt);
		if (retcode == SQL_NO_DATA) {
			flag = 0;
			return RecordSet(delivery_data, flag);
		}
		vector<string>* rowData = new vector<string>();
		for (int i = 0; i < 8; i++) {
			string row = string((const char*)ColumnData[i]);
			rowData->push_back(row);
		}
		delivery_data.push_back(rowData);

		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(delivery_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}

};

void DeliveryGateaway::insert(int id, string delDate, string delTime, string address, string fullName, string nameCurr) {
	try {
		const string preSql = "INSERT INTO delivery VALUES(" + to_string(id) + ", '" + delDate + "', '" + delTime + "', '" + address + "', '" + fullName + "', '" + nameCurr + "');";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};


void DeliveryGateaway::update(int id, string delDate, string delTime, string address, string fullName, string nameCurr) {
	try {
		const string preSql = "UPDATE delivery SET delivery_date  = '" + delDate + "', delivery_time  = '" + delTime + "', delivery_address = '" + address + "', full_name_client = '" + fullName + "', full_name_courier = '" + nameCurr + "' where  order_code =" + to_string(id) + ';';
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


int DeliveryGateaway::countOfRecords() {
	SQLHSTMT stmt = connection.query(L"select count(*) from delivery;");
	SQLRETURN retcode;
	SQLCHAR* ColumnData;
	ColumnData = (SQLCHAR*)malloc(7);
	SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData, 7, nullptr);
	retcode = SQLFetch(stmt);
	int code = stoi((const char*)ColumnData);
	SQLFreeStmt(stmt, SQL_CLOSE);
	return code;
};

void DeliveryGateaway::deleteById(int id) {
	try {
		const string preSql = "DELETE from delivery WHERE order_code = " + to_string(id) + ';';
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
};