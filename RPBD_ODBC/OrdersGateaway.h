#pragma once
#include "Connection.h"
#include <vector>
#include <iostream>
#include <string>
#include "RecordSet.h"


class OrdersGateaway {
private:
	Connection& connection;
	vector<vector<string>*> order_data;

public:
	OrdersGateaway(Connection& connection) : connection(connection) {}

	~OrdersGateaway() {
		for (vector<string>* vector : order_data) {
			delete vector;
		}
		order_data.clear();
	}


	const RecordSet find(int id);
	const RecordSet findByProductId(int id);
	const RecordSet findByStoreId(int id);
	const RecordSet loadData();
	int countOfRecords();
	void insert(int id, int productId, int storeId, string orderDate, string orderTime, int quantity, string fullName, string number, bool confirm);
	void update(int id, int productId, int storeId, string orderDate, string orderTime, int quantity, string fullName, string number, bool confirm);
	void deleteById(int id);

};