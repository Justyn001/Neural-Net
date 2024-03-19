
#include "Neuron.h"

Neuron::Neuron(unsigned outputnumbers, unsigned myindex)
{
	for (unsigned c = 0; c < outputnumbers; c++)
	{
		outputweight.push_back(make_unique<Connection>());
		//std::cout << outputweight[c] << endl;
	}
	index = myindex;
}


void Neuron::feedforward(const vector<Neuron*> &prevLayer)
{
	double sum = 0;
	for (unsigned neuron = 0; neuron < prevLayer.size(); neuron++)
		sum += prevLayer[neuron]->get_output_val() * prevLayer[neuron]->outputweight[index]->weight;

	outputVal = tranfser_function(sum);
}


double Neuron::tranfser_function(double x)
{
	return tan(x);
}

double Neuron::transfer_function_derivative(double x)
{
	return 1 - (x * x);
}


void Neuron::calcoutputGradient(double targetValue)
{
	double dow = targetValue - outputVal;
	m_gradient = dow * Neuron::transfer_function_derivative(targetValue);
}


void Neuron::calchiddenGradient(const vector<Neuron*>& nextLayer)
{
	double dow = sumDow(nextLayer);
	m_gradient = dow * Neuron::transfer_function_derivative(outputVal);
}

double Neuron::sumDow(const vector<Neuron*>& nextLayer)
{
	double sum = 0;
	for (unsigned i = 0; i < nextLayer.size(); i++)
		sum += outputweight[i]->weight * nextLayer[i]->m_gradient;
	return sum;
}

void Neuron::updateInputWeights(vector<Neuron*>& prevlayer)
{
	for (unsigned n = 0; n < prevlayer.size(); ++n) 
	{
		Neuron* neuron = prevlayer[n];
		double oldDeltaWeight = neuron->outputweight[index]->deltaweight;

		double newDeltaWeight = eta * neuron->get_output_val() * m_gradient
			+ alpha * oldDeltaWeight;
		neuron->outputweight[index]->deltaweight = newDeltaWeight;
		neuron->outputweight[index]->weight += newDeltaWeight;
	}
}