#ifndef Net_H
#define Net_H

#include <iostream>
#include <vector>

using namespace std;

class Neuron;

class Net
{
public:
	Net(vector<unsigned> input);
private:
	typedef vector<unique_ptr<Neuron>> Layer;
	vector<Layer> v_layers;  // v_layers[layernum][neuronnum]
};
#endif