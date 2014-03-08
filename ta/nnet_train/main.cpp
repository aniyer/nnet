#include <iostream>
#include <ctime>

//custom includes
#include "../../nnetlib/neural_network.h"
#include "../../nnetlib/neural_network_trainer.h"
#include "../../nnetlib/data_reader.h"

//use standard namespace
using namespace std;

void main()
{		
	//seed random number generator
	srand( (unsigned int) time(0) );
	
	//create data set reader and load data file
	dataReader d;
	d.loadDataFile("E:\\2014-Projects\\explore\\nnet\\data\\letter-recognition-2.csv",16,3);
	d.setCreationApproach( STATIC, 10 );	

	//create neural network
	NeuralNetwork nn(16,10,3);

	//create neural network trainer
	NeuralNetworkTrainer nT( &nn );
	nT.setTrainingParameters(0.001, 0.9, false);
	nT.setStoppingConditions(150, 90);
	nT.enableLogging("log.csv", 5);
	
	//train neural network on data sets
	for (int i=0; i < d.getNumTrainingSets(); i++ )
	{
		nT.trainNetwork( d.getTrainingDataSet() );
	}	

	//save the weights
	nn.saveWeights("weights.csv");
		
	cout << endl << endl << "-- END OF PROGRAM --" << endl;
	//char c; cin >> c;
}
