
#include "Net.h"
#include "Neuron.h"

Net::Net(vector<unsigned> input)
{
	for (unsigned layernum = 0; layernum < input.size(); layernum++)
	{
		v_layers.push_back(Layer());
		cout << "Warstwa " << layernum << endl;

		unsigned outputnum = layernum == input.size() - 1 ? 0 : input[layernum + 1];

		for (unsigned neuron = 0; neuron <= input[layernum]; neuron++)
		{
			cout << "neuron nr. " << neuron << std::endl;
			v_layers.back().push_back(make_unique<Neuron>(outputnum));
		}
	}
}