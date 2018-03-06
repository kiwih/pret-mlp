#ifndef _NEURON_H
#define _NEURON_H

#include <stddef.h>

#include "neuron_config.h"

#define NUM_CONNECTIONS (LAYERS_INPUT_LEN * LAYERS_HIDDEN_LEN + (LAYERS_HIDDEN_LEN * LAYERS_HIDDEN_LEN) * (LAYERS_LEN - 2) + LAYERS_HIDDEN_LEN * LAYERS_OUTPUT_LEN)

struct NeuralNetworkConnection {
	uint32_t Source;
	uint32_t Destination;
	uint32_t Weight;
}

struct NeuralNetwork
{
	//a neural network is made up of a directed acyclic graph of neurons
	NeuralNetworkConnection Connections[NUM_CONNECTIONS];
}

uint32_t
RunNeuron(
	struct Neuron *n,
	uint32_t *incomingVals,
	uint32_t incomingValsL, )

#endif