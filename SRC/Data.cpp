#include "Data.h"

Data::Data(std::vector<double> dataX, std::vector<double> dataY) {
	_dataX.swap(dataX);
	_dataY.swap(dataY);
};

double Data::getMin() {
	return *std::min_element(_dataY.begin(), _dataY.end());
};

double Data::getMax() {
	return *std::max_element(_dataY.begin(), _dataY.end());
};

double Data::getScaleY(int height) {
	return (getMax() - getMin()) / height;
};

int Data::getPixelY(int index, int height) {
	if (_dataY.size() > index)
		return (int)((_dataY[index] - getMin()) / getScaleY(height));
	else
		return 0;
};