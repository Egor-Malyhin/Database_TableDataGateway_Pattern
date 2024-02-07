#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class RecordSet {
private:
    vector<vector<string>*> data;
    int currentIndex;
    bool dataFlag;

public:
    RecordSet()
        : currentIndex(0), dataFlag(0) {}

    RecordSet(const vector<vector<string>*>& data, bool dataFlag)
        : data(data), currentIndex(0), dataFlag(dataFlag) {}

    RecordSet(const vector<vector<string>*>& data)
        : data(data), currentIndex(0), dataFlag(1) {}


    RecordSet& operator=(const RecordSet& other) {
        this->data = other.data;
        this->dataFlag = other.dataFlag;
        this->currentIndex = other.currentIndex;
        return *this;
    }


    void next();
    bool hasNext() const;
    const vector<string>* getCurrentRecord();
    int getIndex() const;
    int getSize() const;
    bool getFlag() const;

};