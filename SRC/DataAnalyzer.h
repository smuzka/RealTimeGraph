#pragma once
#include <vector>
#include <iomanip>
#include <fstream>

#include "Data.h"

class Data;

class DataAnalyzer {
public:
    static void ReadData();
    const static int DATA_SIZE = 1000;

    static Data* newData;
    static Data* oldData;
};