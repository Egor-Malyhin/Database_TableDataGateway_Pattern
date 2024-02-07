#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Connection.h"
#include <vector>
#include <iostream>
#include <string>
#include "RecordSet.h"

class StoresGateaway {
private:
	Connection& connection;
	//vector<SQLCHAR*>* rowData;
	vector<vector<string>*> store_data;
	
public:
	StoresGateaway(Connection& connection) : connection(connection) {}

	~StoresGateaway() {
		for (vector<string>* vector : store_data) {
			delete vector;
		}
		store_data.clear();
	}


	const RecordSet find(int id);
	const RecordSet loadData();
	int countOfRecords();
	void insert(int id, string enail, bool payment);
	void update(int id, string enail, bool payment);
	void deleteById(int id);

};