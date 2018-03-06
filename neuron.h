#ifndef _NEURON_H
#define _NEURON_H

#include <stddef.h>

#define LAYERS_LEN 3 //the total number of layers (must be at least 3)
#define LAYERS_INPUT_LEN 3 //the length of the input layer (in neurons)
#define LAYERS_OUTPUT_LEN 1 //the length of the output layer (in neurons)
#define LAYERS_HIDDEN_LEN 5 //the length of hidden layers (in neurons)

#define NUM_CONNECTIONS (LAYERS)

struct NeuralNetworkConnection {
	uint32_t Source;
	uint32_t Destination;
	uint32_t Weight;
}

struct NeuralNetwork
{
	//a neural network is made up of a directed acyclic graph of neurons
	NeuralNetworkConnection Connections[LAYERS_;

}

struct Neuron
{
	uint8_t Weight;
}

uint32_t
RunNeuron(
	struct Neuron *n,
	uint32_t *incomingVals,
	uint32_t incomingValsL, )

#endif