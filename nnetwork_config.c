#include "nnetwork.h"

//for an XOR solving MLP we have the following pre-trained setup
/*      H1
 *     /   \
 *    /(1)  \(1)
 *  I1       \
 *    \(0.5)  \
 *     \       \
 *      H2-(-2)-O1
 *     /       /
 *    /(0.5)  /
 *  I2       /
 *    \(1)  /(1)
 *     \   /
 *      H3
 * 
 */
//see https://en.wikipedia.org/wiki/Feedforward_neural_network 
//and https://en.wikipedia.org/wiki/Feedforward_neural_network#/media/File:XOR_perceptron_net.png

//ConfigNetwork creates a network to solve XOR
void ConfigNetwork(struct NeuralNetwork* netw) {
	
	//NUM_CONNECTIONS (LAYERS_INPUT_LEN * LAYERS_HIDDEN_LEN + (LAYERS_HIDDEN_LEN * LAYERS_HIDDEN_LEN) * (LAYERS_LEN - 2) + LAYERS_HIDDEN_LEN * LAYERS_OUTPUT_LEN)
	
	//remember that in our default config every neuron in layer N goes to every neuron in layer N+1, but in the diagram we don't illustrate lines with weight 0
	//so we're missing lines from I1 to H3, and I2 to H1 (they both have weight 0)

	//also remember that connections and neurons are both one-dimensional arrays, so to get the neuron index you have to add it to the length of all previous layers
	
	//configure all network connections
	netw->Connections[0] = (struct NeuralNetworkConnection){.Source = 0, .Destination = 2, .Weight = 1};
	netw->Connections[1] = (struct NeuralNetworkConnection){.Source = 0, .Destination = 3, .Weight = 0.5};
	netw->Connections[2] = (struct NeuralNetworkConnection){.Source = 0, .Destination = 4, .Weight = 0};

	netw->Connections[3] = (struct NeuralNetworkConnection){.Source = 1, .Destination = 2, .Weight = 0};
	netw->Connections[4] = (struct NeuralNetworkConnection){.Source = 1, .Destination = 3, .Weight = 0.5};
	netw->Connections[5] = (struct NeuralNetworkConnection){.Source = 1, .Destination = 4, .Weight = 1};

	netw->Connections[6] = (struct NeuralNetworkConnection){.Source = 2, .Destination = 5, .Weight = 1};

	netw->Connections[7] = (struct NeuralNetworkConnection){.Source = 3, .Destination = 5, .Weight = -2};

	netw->Connections[8] = (struct NeuralNetworkConnection){.Source = 4, .Destination = 5, .Weight = 1};
}