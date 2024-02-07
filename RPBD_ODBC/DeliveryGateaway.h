#pragma once
#include "Connection.h"
#include <vector>
#include <iostream>
#include <string>
#include "RecordSet.h"


class DeliveryGateaway {
private:
	Connection& connection;
	vector<vector<string>*> delivery_data;

public:
	DeliveryGateaway(Connection& connection) : connection(connection) {}

	~DeliveryGateaway() {
		for (vector<string>* vector : delivery_data) {
			delete vector;
		}
		delivery_data.clear();
	}


	const RecordSet find(int id);
	const RecordSet loadData();
	int countOfRecords();
	void insert(int id, string delDate, string delTime, string address, string fullName, string nameCurr);
	void update(int id, string delDate, string delTime, string address, string fullName, string nameCurr);
	void deleteById(int id);

};