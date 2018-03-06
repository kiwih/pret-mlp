#include "nnetwork.h"
#include <math.h>

#ifdef PRINT_DEBUG
#include <stdio.h>
#endif

// double SigmoidFunction(double input) {
// 	return exp(input) / (1 + exp(input));
// }

double ThresholdFunction(double input) {
	return (double)(input >= 1);
}

//RunNetwork will run the network and feed-forward all values
void RunNetwork(struct NeuralNetwork* netw, double inputs[LAYERS_INPUT_LEN]) {
	//assign the values to the input neurons
	#pragma loopbound LAYERS_INPUT_LEN
	for(uint32_t i=0; i < LAYERS_INPUT_LEN; i++) {
		netw->Neurons[i].InputValue = inputs[i];
		#ifdef PRINT_DEBUG 
		printf("Neuron %d assigned value %f\n", i, inputs[i]);
		#endif
	}

	//reset the neural network (aside from the input neurons)
	#pragma loopbound (NUM_NEURONS-LAYERS_INPUT_LEN)
	for(uint32_t i=LAYERS_INPUT_LEN; i < NUM_NEURONS; i++) {
		netw->Neurons[i].InputValue = 0;
	}

	//for each of the connections, update the associated neurons
	//because we store all connections in order, there's no risk of updating a neuron after we've started consuming its output
	//(i.e., all neurons will have their final InputValue known before you need to use that to start on the next neuron)
	#pragma loopbound NUM_CONNECTIONS
	for(uint32_t i=0; i < NUM_CONNECTIONS; i++) {
		struct NeuralNetworkNeuron* src = &(netw->Neurons[netw->Connections[i].Source]);
		struct NeuralNetworkNeuron* dest = &(netw->Neurons[netw->Connections[i].Destination]);

		dest->InputValue += ThresholdFunction(src->InputValue) * netw->Connections[i].Weight;
		#ifdef PRINT_DEBUG
		printf("src neuron %d (with out val %f converted to %f) added to dest neuron %d (taking in value to %f)\n", 
			netw->Connections[i].Source,
			ThresholdFunction(src->InputValue),
			ThresholdFunction(src->InputValue) * netw->Connections[i].Weight,
			netw->Connections[i].Destination,
			dest->InputValue);
		#endif
	}
}