
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
			v_layers.back().push_back(make_unique<Neuron>(outputnum, neuron).release());
		}
	}
}

void Net::feedforward(const vector<double>& inputVal)
{
	assert(inputVal.size() == v_layers[0].size() - 1);

	for (unsigned i = 0; i < inputVal.size(); i++)
		v_layers[0][i]->set_output_val(inputVal[i]);

	for (unsigned layernum = 1; layernum < inputVal.size(); layernum++)
	{
		Layer &prevlayer = v_layers[layernum - 1];
		for (unsigned neuronnum = 0; neuronnum < v_layers[layernum].size() - 1; neuronnum++)
			v_layers[layernum][neuronnum]->feedforward(prevlayer);
	}
}

void Net::backProp()
{

}