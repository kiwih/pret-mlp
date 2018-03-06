#pragma once

#define CONFIG_NAME "XOR"

#define LAYERS_LEN 3 //the total number of layers (must be at least 3)
#define LAYERS_INPUT_LEN 2 //the length of the input layer (in neurons)
#define LAYERS_OUTPUT_LEN 1 //the length of the output layer (in neurons)
#define LAYERS_HIDDEN_LEN 3 //the length of hidden layers (in neurons)

//comment this out to use a simpler threshold function
//#define USE_SIGMOID

//uncomment this to print debug messages
//#define PRINT_DEBUG
