#pragma once

#include <stddef.h>
#include <stdint.h>
#include "nnetwork_config.h"

#define NUM_CONNECTIONS (LAYERS_INPUT_LEN * LAYERS_HIDDEN_LEN + (LAYERS_HIDDEN_LEN * LAYERS_HIDDEN_LEN) * (LAYERS_LEN - 3) + LAYERS_HIDDEN_LEN * LAYERS_OUTPUT_LEN)
#define NUM_NEURONS (LAYERS_INPUT_LEN + (LAYERS_HIDDEN_LEN) * (LAYERS_LEN - 2) + LAYERS_OUTPUT_LEN)

//A NeuralNetworkConnection provides a connection between two neurons in the MLP
//It also provides the Weight for that connection
struct NeuralNetworkConnection {
	uint32_t Source;
	uint32_t Destination;
	double Weight;
};

//A NeuralNetworkNeuron provides just the sum of all values sent to it. 
//To calculate the OutputValue, just pass the InputValue through an appropriate activation function
struct NeuralNetworkNeuron {
	double InputValue;
};

//A NeuralNetwork provides the arrays of Neurons and Connections.
//In a MLP, all neurons between layers N and N+1 are connected.
struct NeuralNetwork
{
	//a neural network is made up of a directed acyclic graph of neurons
	struct NeuralNetworkNeuron Neurons[NUM_NEURONS];
	struct NeuralNetworkConnection Connections[NUM_CONNECTIONS];
};

//Some Activation Functions
//double SigmoidFunction(double input);
double ThresholdFunction(double input);

//ConfigNetwork needs to be provided to initialise the network connection graph
void ConfigNetwork(struct NeuralNetwork* netw);

//RunNetwork will run the network and feed-forward all values
void RunNetwork(struct NeuralNetwork* netw, double inputs[LAYERS_INPUT_LEN]); 

