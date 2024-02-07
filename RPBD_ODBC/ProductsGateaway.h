#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Connection.h"
#include <vector>
#include <iostream>
#include <string>
#include "RecordSet.h"


class ProductsGateaway
{
private:

	Connection& connection;
    vector<vector<string>*> product_data;

public:
	ProductsGateaway(Connection& connection) : connection(connection) {}

	~ProductsGateaway() {
		for (vector<string>* vector : product_data) {
			delete vector;
		}
		product_data.clear();
	}

	const RecordSet find(int id);
	const RecordSet loadData();
	void insert(int lastname, string name, string surname, string address, int birth_date, int _class, string image);
	void update(int id, string name, string model, string tech, int price, int guarantee);
	void deleteById(int id);
	int countOfRecords();
};

