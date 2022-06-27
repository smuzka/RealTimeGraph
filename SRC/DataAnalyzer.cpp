#include "DataAnalyzer.h"

Data* DataAnalyzer::newData = new Data();
Data* DataAnalyzer::oldData = new Data();

void DataAnalyzer::ReadData() {
    std::string line;
    std::ifstream myFile("dane.dat");
    std::vector<double> dataX;
    std::vector<double> dataY;

    for (int i = 0; i < DataAnalyzer::DATA_SIZE; i++) {
        double buffer;
        char space;
        myFile >> buffer;
        dataX.push_back(buffer);
        myFile >> space;
        myFile >> buffer;
        dataY.push_back(buffer);
    }

    myFile.close();

    bool diff = false;
    if (newData->getY().size() > 0) {
        int i = 0;
        while (i < 10) {
            if (newData->getY()[i] != dataY[i]) {
                i = 10;
                diff = true;
            }
            else i++;
        }
    }
    else diff = true;

    if (diff) {
        oldData = new Data(newData->getX(), newData->getY());
        newData = new Data(dataX, dataY);
    }
};

