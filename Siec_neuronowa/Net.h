#ifndef Net_H
#define Net_H

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include "Neuron.h"

using namespace std;


class Neuron;

class Net
{
public:
	Net(vector<unsigned> input);
	void feedforward(const vector<double> &inputVal);
	void backProp(const vector<double> &targetVals);
private:
	typedef vector<Neuron*> Layer;
	vector<Layer> v_layers;  // v_layers[layernum][neuronnum]
	double m_error;
	double m_recentAverageError;
	static double m_recentAverageSmoothingFactor;

};
#endif