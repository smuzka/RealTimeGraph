#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Data {
private:
	std::vector<double> _dataX;
	std::vector<double> _dataY;

public:
	Data() {};
	Data(std::vector<double>, std::vector<double>);

	std::vector<double> getX() const { return _dataX; };
	std::vector<double> getY() const { return _dataY; };

	double getMin();
	double getMax();
	double getScaleY(int);
	int getPixelY(int, int);
};

