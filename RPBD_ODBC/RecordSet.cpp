#include "RecordSet.h"

void RecordSet::next() {
    this->currentIndex++;
}

bool RecordSet::hasNext() const {
    return this->currentIndex + 1 < data.size();
}

const vector<string>* RecordSet::getCurrentRecord() {
    if (this->currentIndex < data.size()) {
        return this->data.at(currentIndex);
    }
    else {
        return {};
    }

}
int RecordSet::getIndex() const {
    return this->currentIndex;
}

int RecordSet::getSize() const {
    return this->data.size();
}

bool RecordSet::getFlag() const{
    return this->dataFlag;
}