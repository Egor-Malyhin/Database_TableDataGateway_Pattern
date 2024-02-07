#include "UserAction.h"


void UserAction::printProduct(RecordSet prod, int index) {
    try {
        cout << left << setw(7) << index;
        cout << left << setw(10) << prod.getCurrentRecord()->at(1);
        cout << left << setw(10) << prod.getCurrentRecord()->at(2);
        cout << left << setw(30) << prod.getCurrentRecord()->at(3);
        cout << left << setw(10) << prod.getCurrentRecord()->at(4);
        cout << left << setw(20) << prod.getCurrentRecord()->at(5);
        cout << left << setw(10) << "Cannot see in CLI" << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}

void UserAction::printStore(RecordSet store, int index) {

    try {
        cout << left << setw(7) << index;
        cout << left << setw(20) << store.getCurrentRecord()->at(1);
        if (store.getCurrentRecord()->at(2) == "1") {
            cout << left << setw(20) << "Yes" << endl;
        }
        else cout << left << setw(20) << "No" << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}


void UserAction::printOrder(RecordSet order, int index) {
    try {
        cout << left << setw(15) << index;
        cout << left << setw(15) << order.getCurrentRecord()->at(1);
        cout << left << setw(17) << order.getCurrentRecord()->at(2);
        cout << left << setw(17) << order.getCurrentRecord()->at(3);
        cout << left << setw(17) << order.getCurrentRecord()->at(4);
        cout << left << setw(15) << order.getCurrentRecord()->at(5);
        cout << left << setw(23) << order.getCurrentRecord()->at(6);
        cout << left << setw(26) << order.getCurrentRecord()->at(7);
        if (order.getCurrentRecord()->at(8) == "1") {
            cout << left << setw(25) << "Yes" << endl;
        }
        else cout << left << setw(25) << "No" << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}


void UserAction::printFullOrder(RecordSet order, int index, RecordSet prod, RecordSet store, RecordSet del) {
    try {
        cout << left << setw(16) << index;
        cout << left << setw(4) << "||";
        cout << left << setw(16) << order.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";
        cout << left << setw(19) << order.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";
        cout << left << setw(32) << order.getCurrentRecord()->at(5);
        cout << left << setw(4) << "||";
        cout << left << setw(22) << order.getCurrentRecord()->at(6);
        cout << left << setw(4) << "||";
        cout << left << setw(25) << order.getCurrentRecord()->at(7);
        cout << left << setw(4) << "||";
        if (order.getCurrentRecord()->at(8) == "1") {
            cout << left << setw(24) << "Yes" << endl;
        }
        else cout << left << setw(24) << "No" << endl;


        cout << left << setw(16) << store.getCurrentRecord()->at(0);
        cout << left << setw(4) << "||";
        cout << left << setw(16) << store.getCurrentRecord()->at(1);
        cout << left << setw(4) << "||";
        if (store.getCurrentRecord()->at(2) == "y") {
            cout << left << setw(22) << "Yes" << endl;
        }
        else cout << left << setw(22) << "No" << endl;


        cout << left << setw(16) << prod.getCurrentRecord()->at(0);
        cout << left << setw(4) << "||";
        cout << left << setw(16) << prod.getCurrentRecord()->at(1);
        cout << left << setw(4) << "||";
        cout << left << setw(19) << prod.getCurrentRecord()->at(2);
        cout << left << setw(4) << "||";
        cout << left << setw(32) << prod.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";
        cout << left << setw(22) << prod.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";
        cout << left << setw(25) << prod.getCurrentRecord()->at(5);
        cout << left << setw(4) << "||";
        cout << left << setw(23) << "Cannot see in CLI" << endl;


        cout << left << setw(16) << index;                            
        cout << left << setw(4) << "||";                          
        cout << left << setw(16) << del.getCurrentRecord()->at(1);
        cout << left << setw(4) << "||";                            
        cout << left << setw(19) << del.getCurrentRecord()->at(2);
        cout << left << setw(4) << "||";                 
        cout << left << setw(32) << del.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";                            
        cout << left << setw(22) << del.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";                            
        cout << left << setw(18) << del.getCurrentRecord()->at(5) << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;         
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}


void UserAction::printOrderWithoutDel(RecordSet order, int index, RecordSet prod, RecordSet store) {
    try {
        cout << left << setw(16) << index;
        cout << left << setw(4) << "||";
        cout << left << setw(16) << order.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";
        cout << left << setw(19) << order.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";
        cout << left << setw(32) << order.getCurrentRecord()->at(5);
        cout << left << setw(4) << "||";
        cout << left << setw(22) << order.getCurrentRecord()->at(6);
        cout << left << setw(4) << "||";
        cout << left << setw(25) << order.getCurrentRecord()->at(7);
        cout << left << setw(4) << "||";
        if (order.getCurrentRecord()->at(8) == "1") {
            cout << left << setw(24) << "Yes" << endl;
        }
        else cout << left << setw(24) << "No" << endl;


        cout << left << setw(16) << store.getCurrentRecord()->at(0);
        cout << left << setw(4) << "||";
        cout << left << setw(16) << store.getCurrentRecord()->at(1);
        cout << left << setw(4) << "||";
        if (store.getCurrentRecord()->at(2) == "y") {
            cout << left << setw(22) << "Yes" << endl;
        }
        else cout << left << setw(22) << "No" << endl;


        cout << left << setw(16) << prod.getCurrentRecord()->at(0);
        cout << left << setw(4) << "||";
        cout << left << setw(16) << prod.getCurrentRecord()->at(1);
        cout << left << setw(4) << "||";
        cout << left << setw(19) << prod.getCurrentRecord()->at(2);
        cout << left << setw(4) << "||";
        cout << left << setw(32) << prod.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";
        cout << left << setw(22) << prod.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";
        cout << left << setw(25) << prod.getCurrentRecord()->at(5);
        cout << left << setw(4) << "||";
        cout << left << setw(23) << "Cannot see in CLI" << endl;


        cout << left << setw(14) << "No Delivery Info";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "No Data";
        cout << left << setw(4) << "||";
        cout << left << setw(19) << "No Data";
        cout << left << setw(4) << "||";
        cout << left << setw(32) << "No Data";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "No Data";
        cout << left << setw(4) << "||";
        cout << left << setw(18) << "No Data"<<endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}



void UserAction::printDelivery(RecordSet delivery, int index, string& decision) {
    try {
            cout << left << setw(14) << index;
            cout << left << setw(16) << delivery.getCurrentRecord()->at(1);
            cout << left << setw(19) << delivery.getCurrentRecord()->at(2);
            cout << left << setw(32) << delivery.getCurrentRecord()->at(3);
            cout << left << setw(22) << delivery.getCurrentRecord()->at(4);
            cout << left << setw(26) << delivery.getCurrentRecord()->at(5)<<endl;;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}


void UserAction::printDeliveryWithOrder(RecordSet delivery, RecordSet order, int index, string& decision) {
    try {
        cout << left << setw(16) << index;
        cout << left << setw(4) << "||";
        cout << left << setw(16) << order.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";
        cout << left << setw(19) << order.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";
        cout << left << setw(32) << order.getCurrentRecord()->at(5);
        cout << left << setw(4) << "||";
        cout << left << setw(22) << order.getCurrentRecord()->at(6);
        cout << left << setw(4) << "||";
        cout << left << setw(25) << order.getCurrentRecord()->at(7);
        cout << left << setw(4) << "||";
        if (order.getCurrentRecord()->at(8) == "1") {
            cout << left << setw(24) << "Yes" << endl;
        }
        else cout << left << setw(24) << "No" << endl;


        cout << left << setw(16) << index;
        cout << left << setw(4) << "||";
        cout << left << setw(16) << delivery.getCurrentRecord()->at(1);
        cout << left << setw(4) << "||";
        cout << left << setw(19) << delivery.getCurrentRecord()->at(2);
        cout << left << setw(4) << "||";
        cout << left << setw(32) << delivery.getCurrentRecord()->at(3);
        cout << left << setw(4) << "||";
        cout << left << setw(22) << delivery.getCurrentRecord()->at(4);
        cout << left << setw(4) << "||";
        cout << left << setw(18) << delivery.getCurrentRecord()->at(5) << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "std::logic_error caught: " << e.what() << std::endl;
    }
}

void UserAction::printTitleProduct() {
    cout << left << setw(7) << "ID";
    cout << left << setw(10) << "Name";
    cout << left << setw(10) << "Model";
    cout << left << setw(30) << "Technical Characterisation";
    cout << left << setw(10) << "Price";
    cout << left << setw(20) << "Guarantee Period";
    cout << left << setw(20) << "Image(byte)" << endl;
}

void UserAction::printTitleStore() {
    cout << left << setw(7) << "ID";
    cout << left << setw(20) << "Email";
    cout << left << setw(20) << "Delivery Payment" << endl;
}
void UserAction::printTitleOrder(string& decision) {
    if (decision == "n") {
        cout << left << setw(15) << "ID_Order";
        cout << left << setw(15) << "ID_Store";
        cout << left << setw(17) << "ID_Product";
        cout << left << setw(17) << "Order Date";
        cout << left << setw(17) << "Order Time";
        cout << left << setw(17) << "Quantity";
        cout << left << setw(23) << "Client Full Name";
        cout << left << setw(26) << "Client Phone Number";
        cout << left << setw(25) << "Order Confirmation" << endl;
    }
    else {
        cout << left << setw(16) << "ID_Order";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "Order Date";
        cout << left << setw(4) << "||";
        cout << left << setw(19) << "Order Time";
        cout << left << setw(4) << "||";
        cout << left << setw(32) << "Quantity";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "Client Full Name";
        cout << left << setw(4) << "||";
        cout << left << setw(25) << "Client Phone Number";
        cout << left << setw(4) << "||";
        cout << left << setw(24) << "Order Confirmation" << endl;

        cout << left << setw(16) << "ID_Store";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "Email";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "Delivery Payment" << endl;

        cout << left << setw(16) << "ID_Product";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "Name";
        cout << left << setw(4) << "||";
        cout << left << setw(19) << "Model";
        cout << left << setw(4) << "||";
        cout << left << setw(32) << "Technical Characterisation";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "Price";
        cout << left << setw(4) << "||";
        cout << left << setw(25) << "Guarantee Period";
        cout << left << setw(4) << "||";
        cout << left << setw(23) << "Image(byte)" << endl;

        cout << left << setw(16) << "Delivery Info";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "Delivery Date";
        cout << left << setw(4) << "||";
        cout << left << setw(19) << "Delivery Time";
        cout << left << setw(4) << "||";
        cout << left << setw(32) << "Delivery Address";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "Client Full Name";
        cout << left << setw(4) << "||";
        cout << left << setw(18) << "Currier Full Name" << endl;
        cout << endl;
    }
}
void UserAction::printTitleDelivery(string& decision1) {
    if (decision1 == "n") {
        cout << left << setw(14) << "ID_Order";
        cout << left << setw(16) << "Delivery Date";
        cout << left << setw(19) << "Delivery Time";
        cout << left << setw(32) << "Delivery Address";
        cout << left << setw(22) << "Client Full Name";
        cout << left << setw(18) << "Currier Full Name" << endl;
        cout << endl;
    }
    else {
        cout << left << setw(16) << "Delivery Info";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "Delivery Date";
        cout << left << setw(4) << "||";
        cout << left << setw(19) << "Delivery Time";
        cout << left << setw(4) << "||";
        cout << left << setw(32) << "Delivery Address";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "Client Full Name";
        cout << left << setw(4) << "||";
        cout << left << setw(18) << "Currier Full Name" << endl;

        cout << left << setw(16) << "ID_Order";
        cout << left << setw(4) << "||";
        cout << left << setw(16) << "Order Date";
        cout << left << setw(4) << "||";
        cout << left << setw(19) << "Order Time";
        cout << left << setw(4) << "||";
        cout << left << setw(32) << "Quantity";
        cout << left << setw(4) << "||";
        cout << left << setw(22) << "Client Full Name";
        cout << left << setw(4) << "||";
        cout << left << setw(25) << "Client Phone Number";
        cout << left << setw(4) << "||";
        cout << left << setw(24) << "Order Confirmation" << endl;
        cout << endl;
    }
};

void UserAction::viewProduct(ProductsGateaway& gatewayStudent) {

    try {

        if (gatewayStudent.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty, view Data is impossible");
        }

        printTitleProduct();
        RecordSet prod = gatewayStudent.loadData();

        for (int i = 0; i < prod.getSize(); i++) {
            printProduct(prod, prod.getIndex() + 1);
            if (i != 0 && (i % 10) == 0) {
                string decision;
                cout << "Enter 0 to stop printing or enter anything else to continue:";
                getline(cin, decision);
                if (decision == "0") {
                    break;
                }
            }
            prod.next();
        }

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
}

void UserAction::findProductById(ProductsGateaway& gatewayStudent) {
    try {

        if (gatewayStudent.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty, view Data is impossible");
        }

        string id;
        std::cout << "Enter product ID to find: ";
        (cin >> id).get();
        RecordSet recordSet = gatewayStudent.find(stoi(id));
        if (!recordSet.getFlag()) {
            cout << "No records found by the given ID" << endl;
            return;
        }
        printTitleProduct();
        printProduct(recordSet, stoi(recordSet.getCurrentRecord()->at(0)));
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
}


void UserAction::insertProduct(ProductsGateaway& gatewayStudent) {

    try {
        string id, name, surname, address, birth_date, entry_year, classInput, image;

        cout << "Enter product information:"<<endl;
        cout << "ID: ";
        (cin >> id).get();

        RecordSet recordSet = gatewayStudent.find(stoi(id));
        bool flag = recordSet.getFlag();
        if (flag) {
            throw std::out_of_range("Invalid id");
        }

        cout << "Name: ";
        getline(cin, name);
        cout << "Model: ";
        getline(cin, surname);
        cout << "Technical Characterisation: ";
        getline(cin, address);
        cout << "Price: ";
        getline(cin, birth_date);
        cout << "Guarantee Period: ";
        getline(cin, classInput);
        cout << "Image(Enter Path to Image): ";
        getline(cin, image);

        if (std::FILE* file = std::fopen(image.c_str(), "r")) {
            std::fclose(file);
        }
        else {
            throw std::ifstream::failure("The file does not exist or cannot be opened");
 
        }

        gatewayStudent.insert(stoi(id), name, surname, address, stoi(birth_date), stoi(classInput), image);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
}

void UserAction::updateProduct(ProductsGateaway& gatewayStudent)
{
    try {

        if (gatewayStudent.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty, update is impossible");
        }

        string id;
        std::cout << "Enter student ID to update: ";
        (cin >> id).get();

        RecordSet recordSet = gatewayStudent.find(stoi(id));
        if (1 > stoi(id) || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }


        std::string name, model, tech_char, price, guaranteeInput;
        int guarantee, price_;



        cout << "Name (Enter to keep the existing value): ";
        getline(std::cin, name);
        if (name.empty()) {
            name = recordSet.getCurrentRecord()->at(1);
        }

        cout << "Model (Enter to keep the existing value): ";
        getline(std::cin, model);
        if (model.empty()) {
            model = recordSet.getCurrentRecord()->at(2);
        }

        cout << "Technical Characterisation (Enter to keep the existing value): ";
        getline(std::cin, tech_char);
        if (tech_char.empty()) {
            tech_char = recordSet.getCurrentRecord()->at(3);
        }

        cout << "Price (Enter to keep the existing value): ";
        getline(std::cin, price);
        if (price.empty()) {
            price_ = stoi(recordSet.getCurrentRecord()->at(4));
        }
        else {
            price_ = stoi(price);
        }

        cout << "Guarantee Period (Enter to keep the existing value): ";
        getline(std::cin, guaranteeInput);
        if (guaranteeInput.empty()) {
            guarantee = stoi(recordSet.getCurrentRecord()->at(5));
        }
        else {
            guarantee = stoi(guaranteeInput);
        }

        gatewayStudent.update(stoi(id), name, model, tech_char, price_, guarantee);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
}
void UserAction::deleteProduct(ProductsGateaway& gatewayStudent, OrdersGateaway& gateawayOrder) {
    
    try {
        if (gatewayStudent.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty, Delete is impossible");
        }

        int id;
        std::cout << "Enter product ID to delete: ";
        std::cin >> id;
        RecordSet recordSet = gatewayStudent.find(id);
        if (1 > id || !recordSet.getFlag()) {
            throw std::out_of_range("Invalid id");
        }

       RecordSet orderRecordSet = gateawayOrder.findByProductId(id);
        if (!orderRecordSet.getFlag()) {
            gatewayStudent.deleteById(id);
            return;
        }
        else {
            for (int i = 0; i < orderRecordSet.getSize(); i++) {
                gateawayOrder.deleteById(stoi(orderRecordSet.getCurrentRecord()->at(0)));
                orderRecordSet.next();
            }
        }
        gatewayStudent.deleteById(id);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};


void UserAction::viewStore(StoresGateaway& gatewayStore) {
    try {
        if (gatewayStore.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        printTitleStore();
        RecordSet recordSet = gatewayStore.loadData();

        for (int i = 0; i < recordSet.getSize(); i++) {
            printStore(recordSet, recordSet.getIndex() + 1);

            if (i != 0 && (i % 10) == 0) {
                string decision;
                cout << "Enter 0 to stop printing or enter anything else to continue:";
                getline(cin, decision);
                if (decision == "0") {
                    break;
                }
            }
            recordSet.next();
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::findStoreById(StoresGateaway& gatewayStore) {
    try {
        if (gatewayStore.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }
        string id;
        std::cout << "Enter Store ID to find: ";
        (cin >> id).get();

        RecordSet recordSet= gatewayStore.find(stoi(id));
        if (!recordSet.getFlag()) {
            cout << "No records found by the given ID" << endl;
            return;
        }
        printTitleStore();
        printStore(recordSet, recordSet.getIndex());
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
}

void UserAction::insertStore(StoresGateaway& gatewayStore) {
    try {
        string id, email, payment;

        cout << "Enter Store information:" << endl;

        cout << "ID: ";
        (cin >> id).get();

        //storeRecordSet = gatewayStore.find(stoi(id));
        RecordSet recordSet = gatewayStore.find(stoi(id));
       
        if (recordSet.getFlag()) {
            throw std::out_of_range("Invalid id");
        }

        cout << "Email: ";
        getline(cin, email);
        cout << "Delivery Payment (y or n): ";
        getline(cin, payment);
        if (payment != "y" && payment != "n") {
            cout << "Wrong Payment";
            return;
        }

        gatewayStore.insert(stoi(id), email, payment=="y");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};


void UserAction::updateStore(StoresGateaway& gatewayStore) {
    try {

        if (gatewayStore.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        string id;
        std::cout << "Enter store ID to update: ";
        (cin >> id).get();

        RecordSet recordSet = gatewayStore.find(stoi(id));
        if (1 > stoi(id) || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }

        string email, payment;

        cout << "Email (Enter to keep the existing value): ";
        getline(std::cin, email);
        if (email.empty()) {
            email = recordSet.getCurrentRecord()->at(1);
        }

        cout << "Payment(y or n) (Enter to keep the existing value): ";
        getline(std::cin, payment);
        if (payment.empty()) {
            if (recordSet.getCurrentRecord()->at(2)=="1") {
                payment = "y";
            }
            else {
                payment = "n";
            }
        }
        else {
            if (payment != "y" && payment != "n") {
                cout << "Wrong Payment" << endl;
                return;
            }
        }
        gatewayStore.update(stoi(id), email, payment=="y");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::deleteStore(StoresGateaway& gatewayStore, OrdersGateaway& gateawayOrder){
    try {
        if (gatewayStore.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        int id;
        std::cout << "Enter store ID to delete: ";
        std::cin >> id;

        RecordSet recordSet = gatewayStore.find(id);
        if (1 > id || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }


        RecordSet orderRecordSet = gateawayOrder.findByStoreId(id);
        if (!orderRecordSet.getFlag()) {
            gatewayStore.deleteById(id);
            return;
        }
        else {
            for (int i = 0; i < orderRecordSet.getSize(); i++) {
                gateawayOrder.deleteById(stoi(orderRecordSet.getCurrentRecord()->at(0)));
                orderRecordSet.next();
            }
        }

        gatewayStore.deleteById(id);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::viewOrder(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct, DeliveryGateaway& gateawayDelivery) {

    try {
        if (gateawayOrder.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        RecordSet recordSet = gateawayOrder.loadData();
        string decision1;
        cout << "Do you need full Data?(y or n):";
        (cin >> decision1).get();
        if (decision1 != "y" && decision1 != "n") {
            cout << "Wrong Decision" << endl;
            return;
        }
        printTitleOrder(decision1);
        if (decision1 == "n") {
            for (int i = 0; i < recordSet.getSize(); i++) {
                printOrder(recordSet, recordSet.getIndex() + 1);
                if (i != 0 && (i % 10) == 0) {
                    string decision;
                    cout << "Enter 0 to stop printing or enter anything else to continue:";
                    getline(cin, decision);
                    if (decision == "0") {
                        break;
                    }
                }
                recordSet.next();
            }
        }
        else {
            
            for (int i = 0; i < recordSet.getSize(); i++) {

                RecordSet prod = gateawayProduct.find(stoi(recordSet.getCurrentRecord()->at(2)));
                RecordSet store = gateawayStore.find(stoi(recordSet.getCurrentRecord()->at(1)));

                RecordSet del = gateawayDelivery.find(stoi(recordSet.getCurrentRecord()->at(0)));
                bool flag = del.getFlag();

                if (!flag)
                    printOrderWithoutDel(recordSet, recordSet.getIndex() + 1, prod, store);
                else {
                    //Delivery delivery = *delRecordSet.getCurrentRecord();
                    printFullOrder(recordSet, recordSet.getIndex() + 1, prod, store, del);
                }
                if (i != 0 && (i % 10) == 0) {
                    string decision;
                    cout << "Enter 0 to stop printing or enter anything else to continue:";
                    getline(cin, decision);
                    if (decision == "0") {
                        break;
                    }
                }
                recordSet.next();
            }
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::findOrderById(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct, DeliveryGateaway& gateawayDelivery) {
    try {
        if (gateawayOrder.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        string id;
        string decisionn;
        std::cout << "Enter Order ID to find: ";
        (cin >> id).get();
        RecordSet recordSet = gateawayOrder.find(stoi(id));
        if (!recordSet.getFlag()) {
            cout << "No records found by the given ID" << endl;
            return;
        }

        cout << "Do you need full Data?(y or n):";
        (cin >> decisionn).get();
        if (decisionn != "y" && decisionn != "n") {
            cout << "Wrong Decision" << endl;
            return;
        }
        printTitleOrder(decisionn);


        if (decisionn == "n")
            printOrder(recordSet, recordSet.getIndex() + 1);
        else {
            
            RecordSet prod = gateawayProduct.find(stoi(recordSet.getCurrentRecord()->at(2)));
            RecordSet store = gateawayStore.find(stoi(recordSet.getCurrentRecord()->at(1)));

            RecordSet del = gateawayDelivery.find(stoi(recordSet.getCurrentRecord()->at(0)));
            bool flag = del.getFlag();

            if (!flag)
                printOrderWithoutDel(recordSet, recordSet.getIndex() + 1, prod, store);
            else {
                //Delivery delivery = *delRecordSet.getCurrentRecord();
                printFullOrder(recordSet, recordSet.getIndex() + 1, prod, store, del);
            }

        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::insertOrder(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct) {
    try {
        string id, id_store, id_product, date, time, quan, name, number, conf;

        cout << "Enter Order information:" << endl;
        cout << "ID: ";
        (cin >> id).get();

        RecordSet recordSet = gateawayOrder.find(stoi(id));
        if (recordSet.getFlag()) {
            throw std::out_of_range("Invalid id");
        }


        cout << "ID Store: ";
        getline(cin, id_store);

        RecordSet storeRecordSet = gateawayStore.find(stoi(id_store));
        if (storeRecordSet.getFlag() == 0) {
            throw std::out_of_range("Invalid Store id");
        }

        cout << "ID Product: ";
        getline(cin, id_product);

        RecordSet productRecordSet = gateawayProduct.find(stoi(id_product));
        if (productRecordSet.getFlag() == 0) {
            throw std::out_of_range("Invalid Product id");
        }

        cout << "Order Date (YY-MM-DD): ";
        getline(cin, date);
        cout << "Order Time (HH:MM:SS): ";
        getline(cin, time);
        cout << "Quantity: ";
        getline(cin, quan);
        cout << "Client Full Name: ";
        getline(cin, name);
        cout << "Client Phone Number: ";
        getline(cin, number);
        cout << "Order confirmed (y or n): ";
        getline(cin, conf);
        if (conf != "y" && conf != "n") {
            throw std::logic_error("Wrong Confirmation");
        }
        gateawayOrder.insert(stoi(id), stoi(id_store), stoi(id_product), date,time,stoi(quan),name,number, conf=="y");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};
void UserAction::updateOrder(OrdersGateaway& gateawayOrder, StoresGateaway& gateawayStore, ProductsGateaway& gateawayProduct) {
    try {

        if (gateawayOrder.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        string id;
        std::cout << "Enter order ID to update: ";
        (cin >> id).get();

        RecordSet recordSet = gateawayOrder.find(stoi(id));
        if (1 > stoi(id) || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }

        //Order order = *orderRecordSet.getCurrentRecord();

        string id_store, id_product, date, time, quan, name, number, conf;
        int id_store_, id_product_, quan_;

        cout << "ID store(Select from existing values in Database) (Enter to keep the existing value): ";
        getline(std::cin, id_store);
        if (id_store.empty()) {
            id_store_ = stoi(recordSet.getCurrentRecord()->at(1));
        }
        else {
            RecordSet storeRecordSet = gateawayStore.find(stoi(id_store));
            if (storeRecordSet.getFlag() == 0) {
                throw std::out_of_range("Invalid Store id");
            }
            id_store_ = stoi(id_store);
        }


        cout << "ID Product(Select from existing values in Database) (Enter to keep the existing value): ";
        getline(std::cin, id_product);
        if (id_product.empty()) {
            id_product_ = stoi(recordSet.getCurrentRecord()->at(2));
        }
        else {
            RecordSet productRecordSet = gateawayProduct.find(stoi(id_product));
            if (productRecordSet.getFlag() == 0) {
                throw std::out_of_range("Invalid product id");
            }
            id_product_ = stoi(id_product);
        }


        cout << "Order Date (YY-MM-DD): ";
        getline(cin, date);
        if (date.empty()) {
            date = recordSet.getCurrentRecord()->at(3);
        }

        cout << "Order Time (HH:MM:SS): ";
        getline(cin, time);
        if (time.empty()) {
            time = recordSet.getCurrentRecord()->at(4);
        }

        cout << "Quantity: ";
        getline(cin, quan);
        if (quan.empty()) {
            quan_ = stoi(recordSet.getCurrentRecord()->at(5));
        }
        else {
            quan_ = stoi(quan);
        }

        cout << "Client Full Name: ";
        getline(cin, name);
        if (name.empty()) {
            name = recordSet.getCurrentRecord()->at(6);
        }

        cout << "Client Phone Number: ";
        getline(cin, number);
        if (number.empty()) {
            number = recordSet.getCurrentRecord()->at(7);
        }

        cout << "Order confirmed (y or n): ";
        getline(cin, conf);
        if (conf.empty()) {
            if (recordSet.getCurrentRecord()->at(8)=="1") {
                conf = "y";
            }
            else {
                conf = "n";
            }
        }
        else {
            if (conf != "y" && conf != "n") {
                throw std::logic_error("Wrong Confirmation");
            }
        }
        gateawayOrder.update(stoi(id), id_store_, id_product_, date, time, quan_, name, number, conf=="y");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }

};

void UserAction::deleteOrder(OrdersGateaway& gateawayOrder, DeliveryGateaway& gateawayDel) {
    try {

        if (gateawayOrder.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        int id;
        std::cout << "Enter order ID to delete: ";
        std::cin >> id;


        RecordSet recordSet = gateawayOrder.find(id);
        if (1 > id || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }

        gateawayDel.deleteById(id);
        gateawayOrder.deleteById(id);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::viewDelivery(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder) {
    try {
        if (gateawayDelivery.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        RecordSet recordSet = gateawayDelivery.loadData();
        string decision1;

        cout << "Do you need Delivery Data with Order Data?(y or n):";
        (cin >> decision1).get();
        if (decision1 != "y" && decision1 != "n") {
            cout << "Wrong Decision" << endl;
            return;
        }

        printTitleDelivery(decision1);
        if (decision1 == "n") {
            for (int i = 0; i < recordSet.getSize(); i++) {
                printDelivery(recordSet, recordSet.getIndex() + 1, decision1);
                if (i != 0 && (i % 10) == 0) {
                    string decision;
                    cout << "Enter 0 to stop printing or enter anything else to continue:";
                    getline(cin, decision);
                    if (decision == "0") {
                        break;
                    }
                }
                recordSet.next();
            }
        }
        else {
            for (int i = 0; i < recordSet.getSize(); i++) {
                RecordSet orderRecordSet = gateawayOrder.find(stoi(recordSet.getCurrentRecord()->at(0)));
                printDeliveryWithOrder(recordSet, orderRecordSet, recordSet.getIndex() + 1, decision1);
                if (i != 0 && (i % 10) == 0) {
                    string decision;
                    cout << "Enter 0 to stop printing or enter anything else to continue:";
                    getline(cin, decision);
                    if (decision == "0") {
                        break;
                    }
                }
                recordSet.next();
            }
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::findDeliveryById(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder) {
    try {
        if (gateawayDelivery.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        string id;
        string decisionn;


        std::cout << "Enter Order ID to find: ";
        (cin >> id).get();
        RecordSet recordSet = gateawayDelivery.find(stoi(id));
        if (!recordSet.getFlag()) {
            cout << "No records found by the given ID" << endl;
            return;
        }


        cout << "Do you need full Data?(y or n):";
        (cin >> decisionn).get();

        if (decisionn != "y" && decisionn != "n") {
            cout << "Wrong Decision" << endl;
            return;
        }
        printTitleOrder(decisionn);
        if (decisionn == "n") {
            printDelivery(recordSet, recordSet.getIndex() + 1, decisionn);
        }
        else {
            RecordSet orderRecordSet = gateawayOrder.find(stoi(recordSet.getCurrentRecord()->at(0)));
            printDeliveryWithOrder(recordSet, orderRecordSet, recordSet.getIndex() + 1, decisionn);
        }

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::insertDelivery(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder) {
    try {
        string id_order, date, time, addr, name, number, conf, curr;

        cout << "Enter  information:" << endl;

        cout << "ID Order: ";
        (cin >> id_order).get();

        RecordSet recordSet = gateawayOrder.find(stoi(id_order));
        if (recordSet.getFlag() == 0) {
            throw std::out_of_range("Invalid Order id");
        }

        recordSet = gateawayDelivery.find(stoi(id_order));
        if (recordSet.getFlag()) {
            throw std::logic_error("Invalid Order id(Order already have Delivery Record)");
        }

        cout << "Delivery Date (YY-MM-DD): ";
        getline(cin, date);
        cout << "Delivery Time (HH:MM:SS): ";
        getline(cin, time);
        cout << "Delivery Address: ";
        getline(cin, addr);
        cout << "Client Full Name: ";
        getline(cin, name);
        cout << "Currier Full Name: ";
        getline(cin, curr);

        gateawayDelivery.insert(stoi(id_order), date, time, addr, name, curr);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::updateDelivery(DeliveryGateaway& gateawayDelivery, OrdersGateaway& gateawayOrder) {
    try {
        if (gateawayDelivery.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        string id;
        std::cout << "Enter order ID to update: ";
        (cin >> id).get();

        RecordSet recordSet = gateawayDelivery.find(stoi(id));
        if (1 > stoi(id) || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }

        //Delivery delivery = *delRecordSet.getCurrentRecord();

        string date, time, addr, name, number, conf, curr;
        int id_store_, id_product_, quan_;


        cout << "Delivery Date (YY-MM-DD): ";
        getline(cin, date);
        if (date.empty()) {
            date = recordSet.getCurrentRecord()->at(1);
        }

        cout << "Delivery Time (HH:MM:SS): ";
        getline(cin, time);
        if (time.empty()) {
            time = recordSet.getCurrentRecord()->at(2);
        }

        cout << "Address: ";
        getline(cin, addr);
        if (addr.empty()) {
            addr = recordSet.getCurrentRecord()->at(3);
        }
       

        cout << "Client Full Name: ";
        getline(cin, name);
        if (name.empty()) {
            name = recordSet.getCurrentRecord()->at(4);
        }

        cout << "Currier Full Name: ";
        getline(cin, name);
        if (name.empty()) {
            name = recordSet.getCurrentRecord()->at(5);
        }


        gateawayDelivery .update(stoi(id), date, time, addr, name, curr);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

void UserAction::deleteDelivery(DeliveryGateaway& gateawayDelivery) {

    try {
        if (gateawayDelivery.countOfRecords() <= 0) {
            throw std::logic_error("Table is empty");
        }

        int id;
        std::cout << "Enter order ID to delete: ";
        std::cin >> id;

        RecordSet recordSet = gateawayDelivery.find(id);
        if (1 > id || (!recordSet.getFlag())) {
            throw std::out_of_range("Invalid id");
        }
        gateawayDelivery.deleteById(id);
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
    catch (const logic_error& e) {
        cerr << e.what() << endl;
    }
};

