#ifndef NNetwork
#define NNetwork

#include "data_reader.h"
#include "common.h"

class NeuralNetworkTrainer;

class NNET_DLL NeuralNetwork
{
	//class members
	//--------------------------------------------------------------------------------------------
private:

	//number of neurons
	int nInput, nHidden, nOutput;
	
	//neurons
	double* inputNeurons;
	double* hiddenNeurons;
	double* outputNeurons;

	//weights
	double** wInputHidden;
	double** wHiddenOutput;
		
	//Friends
	//--------------------------------------------------------------------------------------------
	friend NeuralNetworkTrainer;
	
	//public methods
	//--------------------------------------------------------------------------------------------

public:

	//constructor & destructor
	NeuralNetwork(int numInput, int numHidden, int numOutput);
	~NeuralNetwork();

	//weight operations
	bool loadWeights(char* inputFilename);
	bool saveWeights(char* outputFilename);
	int* feedForwardPattern( double* pattern );
	double getSetAccuracy( std::vector<dataEntry*>& set );
	double getSetMSE( std::vector<dataEntry*>& set );

	//private methods
	//--------------------------------------------------------------------------------------------

private: 

	void initializeWeights();
	inline double activationFunction( double x );
	inline int clampOutput( double x );
	void feedForward( double* pattern );
	
};

#endif
