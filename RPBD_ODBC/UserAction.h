#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "ProductsGateaway.h"
#include "StoresGateway.h"
#include "RecordSet.h"
#include "OrdersGateaway.h"
#include "DeliveryGateaway.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <iostream>
#include <filesystem>
#include <cstdio>
#include <fstream>
#include <stdexcept>

class UserAction
{

private:
	void printProduct(RecordSet prod, int index);
	void printStore(RecordSet store, int index);
	void printOrder(RecordSet order, int index);
	void printFullOrder(RecordSet order, int index, RecordSet prod, RecordSet store, RecordSet del);
	void printOrderWithoutDel(RecordSet order, int index, RecordSet prod, RecordSet store);
	void printDelivery(RecordSet delivery, int index, string& decision);
	void printDeliveryWithOrder(RecordSet delivery, RecordSet order, int index, string& decision);


	void printTitleProduct();
	void printTitleStore();
	void printTitleOrder(string& decision);
	void printTitleDelivery(string& decision1);


public:
	void viewProduct(ProductsGateaway& gatewayStudent);
	void insertProduct(ProductsGateaway& gatewayStudent);
	void updateProduct(ProductsGateaway& gatewayStudent);
	void deleteProduct(ProductsGateaway& gatewayStudent, OrdersGateaway& gateawayOrder);
	void findProductById(ProductsGateaway& gatewayStudent);


	void viewStore(StoresGateaway& gatewayStore);
	void findStoreById(StoresGateaway& gatewayStore);
	void insertStore(StoresGateaway& gatewayStore);
	void updateStore(StoresGateaway& gatewayStore);
	void deleteStore(StoresGateaway& gatewayStore, OrdersGateaway& gateawayOrder);

	void viewOrder(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct, DeliveryGateaway& gateawayDelivery);
	void findOrderById(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct, DeliveryGateaway& gateawayDelivery);
	void insertOrder(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct);
	void updateOrder(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct);
	void deleteOrder(OrdersGateaway& gateawayOrder, DeliveryGateaway& gateawayDel);

	void viewDelivery(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder);
	void findDeliveryById(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder);
	void insertDelivery(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder);
	void updateDelivery(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder);
	void deleteDelivery(DeliveryGateaway& gateawayDelivery);
};