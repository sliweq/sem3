#pragma once
#include <vector>
#include "CIndividual.h"

using namespace std;

class CGeneticAlgorithm{
public:
	CGeneticAlgorithm(int popSizeInput, float crossProbInput, float mutProbInput, CLFLnetEvaluator* c_evaluatorInput);
	CIndividual* runIteration();
	~CGeneticAlgorithm();
	int iFindParent();
	void vMutate();
	void vCross();
	
private:
	vector<CIndividual*>* population;
	float crossProb;
	float mutProb;
	int popSize;
	CLFLnetEvaluator* c_evaluator;
};