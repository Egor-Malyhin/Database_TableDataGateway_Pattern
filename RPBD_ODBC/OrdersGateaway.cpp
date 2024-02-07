#include "OrdersGateaway.h"

const RecordSet OrdersGateaway::loadData() {
	for (vector<string>* vector : order_data) {
		delete vector;
	}
	order_data.clear();
	try {
		SQLHSTMT stmt = connection.query(L"select * from orders order by order_code;");
		SQLRETURN retcode;
		SQLCHAR* ColumnData[9];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(7);
		ColumnData[2] = (SQLCHAR*)malloc(7);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(255);
		ColumnData[7] = (SQLCHAR*)malloc(255);
		ColumnData[8] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 7, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 7, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 255, nullptr);
		SQLBindCol(stmt, 8, SQL_C_CHAR, ColumnData[7], 255, nullptr);
		SQLBindCol(stmt, 9, SQL_C_CHAR, ColumnData[8], 255, nullptr);


		while (1) {
			retcode = SQLFetch(stmt);

			if (retcode == SQL_NO_DATA) {
				break;
			}

			vector<string>* row = new vector<string>();
			for (int i = 0; i < 9; i++) {
				string rowData = string((const char*)ColumnData[i]);
				row->push_back(rowData);
			}
			order_data.push_back(row);

		}
		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(order_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};

const RecordSet OrdersGateaway::find(int id) {
	for (vector<string>* vector : order_data) {
		delete vector;
	}
	order_data.clear();
	try {
		bool flag;
		const string preSql = "select * from orders where order_code=" + to_string(id) + ";";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());
		SQLRETURN retcode;
		SQLCHAR* ColumnData[9];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(7);
		ColumnData[2] = (SQLCHAR*)malloc(7);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(255);
		ColumnData[7] = (SQLCHAR*)malloc(255);
		ColumnData[8] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 7, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 7, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 255, nullptr);
		SQLBindCol(stmt, 8, SQL_C_CHAR, ColumnData[7], 255, nullptr);
		SQLBindCol(stmt, 9, SQL_C_CHAR, ColumnData[8], 255, nullptr);


		retcode = SQLFetch(stmt);

		if (retcode == SQL_NO_DATA) {
			flag = 0;
			return RecordSet(order_data, flag);
		}

		vector<string>* row = new vector<string>();
		for (int i = 0; i < 9; i++) {
			string rowData = string((const char*)ColumnData[i]);
			row->push_back(rowData);
		}
		order_data.push_back(row);

		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(order_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};

const RecordSet OrdersGateaway::findByProductId(int id) {
	for (vector<string>* vector : order_data) {
		delete vector;
	}
	order_data.clear();
	try {
		bool flag;
		const string preSql = "select * from orders where product_code=" + to_string(id) + ";";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());
		SQLRETURN retcode;
		SQLCHAR* ColumnData[9];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(7);
		ColumnData[2] = (SQLCHAR*)malloc(7);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(255);
		ColumnData[7] = (SQLCHAR*)malloc(255);
		ColumnData[8] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 7, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 7, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 255, nullptr);
		SQLBindCol(stmt, 8, SQL_C_CHAR, ColumnData[7], 255, nullptr);
		SQLBindCol(stmt, 9, SQL_C_CHAR, ColumnData[8], 255, nullptr);


		retcode = SQLFetch(stmt);

		if (retcode == SQL_NO_DATA) {
			flag = 0;
			return RecordSet(order_data, flag);
		}

		vector<string>* row = new vector<string>();
		for (int i = 0; i < 9; i++) {
			string rowData = string((const char*)ColumnData[i]);
			row->push_back(rowData);
		}
		order_data.push_back(row);

		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(order_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};

const RecordSet OrdersGateaway::findByStoreId(int id) {
	for (vector<string>* vector : order_data) {
		delete vector;
	}
	order_data.clear();
	try {
		bool flag;
		const string preSql = "select * from orders where store_code=" + to_string(id) + ";";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());
		SQLRETURN retcode;
		SQLCHAR* ColumnData[9];

		ColumnData[0] = (SQLCHAR*)malloc(7);
		ColumnData[1] = (SQLCHAR*)malloc(7);
		ColumnData[2] = (SQLCHAR*)malloc(7);
		ColumnData[3] = (SQLCHAR*)malloc(255);
		ColumnData[4] = (SQLCHAR*)malloc(255);
		ColumnData[5] = (SQLCHAR*)malloc(255);
		ColumnData[6] = (SQLCHAR*)malloc(255);
		ColumnData[7] = (SQLCHAR*)malloc(255);
		ColumnData[8] = (SQLCHAR*)malloc(255);


		SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData[0], 7, nullptr);
		SQLBindCol(stmt, 2, SQL_C_CHAR, ColumnData[1], 7, nullptr);
		SQLBindCol(stmt, 3, SQL_C_CHAR, ColumnData[2], 7, nullptr);
		SQLBindCol(stmt, 4, SQL_C_CHAR, ColumnData[3], 255, nullptr);
		SQLBindCol(stmt, 5, SQL_C_CHAR, ColumnData[4], 255, nullptr);
		SQLBindCol(stmt, 6, SQL_C_CHAR, ColumnData[5], 255, nullptr);
		SQLBindCol(stmt, 7, SQL_C_CHAR, ColumnData[6], 255, nullptr);
		SQLBindCol(stmt, 8, SQL_C_CHAR, ColumnData[7], 255, nullptr);
		SQLBindCol(stmt, 9, SQL_C_CHAR, ColumnData[8], 255, nullptr);


		retcode = SQLFetch(stmt);

		if (retcode == SQL_NO_DATA) {
			flag = 0;
			return RecordSet(order_data, flag);
		}

		vector<string>* row = new vector<string>();
		for (int i = 0; i < 9; i++) {
			string rowData = string((const char*)ColumnData[i]);
			row->push_back(rowData);
		}
		order_data.push_back(row);

		SQLFreeStmt(stmt, SQL_CLOSE);
		return RecordSet(order_data);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
};

void OrdersGateaway::insert(int id, int productId, int storeId, string orderDate, string orderTime, int quantity, string fullName, string number, bool confirm) {
	try {
		const string preSql = "INSERT INTO orders VALUES(" + to_string(id) + ", " + to_string(productId) + ", " + to_string(storeId) +", '"+ orderDate + "', '" + orderTime + "', " + to_string(quantity) + ", '" + fullName+"', '"+ number+"', '"+to_string(confirm) + "');";
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());

		SQLFreeStmt(stmt, SQL_CLOSE);
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}

};
void OrdersGateaway::update(int id, int productId, int storeId, string orderDate, string orderTime, int quantity, string fullName, string number, bool confirm) {
	try {
		const string preSql = "UPDATE orders SET store_code = " + to_string(productId) + ", product_code  = " + to_string(storeId) + ", order_date  = '"+ orderDate + "', order_time  = '" + orderTime + "', quantity = " + to_string(quantity) + ", full_name_client = '" + fullName + "', phone_number = '" + number + "', order_conf = '" + to_string(confirm) + "' where  order_code ="+ to_string(id) + ';';
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

int OrdersGateaway::countOfRecords() {
	SQLHSTMT stmt = connection.query(L"select count(*) from orders;");
	SQLRETURN retcode;
	SQLCHAR* ColumnData;
	ColumnData = (SQLCHAR*)malloc(7);
	SQLBindCol(stmt, 1, SQL_C_CHAR, ColumnData, 7, nullptr);
	retcode = SQLFetch(stmt);
	int code = stoi((const char*)ColumnData);
	SQLFreeStmt(stmt, SQL_CLOSE);
	return code;
};

void OrdersGateaway::deleteById(int id) {
	try {


		const string preSql = "DELETE from delivery WHERE order_code = " + to_string(id) + ';';
		const wstring sql = wstring(preSql.begin(), preSql.end());
		SQLHSTMT stmt = connection.query(sql.c_str());
		SQLFreeStmt(stmt, SQL_CLOSE);

		const string preSqlFamilyRelationships = "DELETE from orders WHERE order_code = " + to_string(id) + ';';
		const wstring sqlFamilyRelationships = wstring(preSqlFamilyRelationships.begin(), preSqlFamilyRelationships.end());
		stmt = connection.query(sqlFamilyRelationships.c_str());
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