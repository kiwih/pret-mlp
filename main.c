#include "nnetwork.h"

#include <stddef.h>
#include <stdio.h>


void main() {
	//create the neural network
	struct NeuralNetwork netw;

	//configure it, i.e. set up the connection graph (we're making one that can solve XOR)
	ConfigNetwork(&netw);

	//pass some inputs in and take a look at the output!
	double inputs[LAYERS_INPUT_LEN];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j<2; j++) {
			inputs[0] = (double)i;
			inputs[1] = (double)j;
			RunNetwork(&netw, inputs);
			printf("Inputs: %f, %f\t\tOutput: %f\n", inputs[0], inputs[1], ThresholdFunction(netw.Neurons[NUM_NEURONS-1].InputValue));
		}
	}

}