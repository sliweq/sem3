#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

CGeneticAlgorithm::CGeneticAlgorithm(int popSizeInput, float crossProbInput, float mutProbInput, CLFLnetEvaluator* c_evaluatorInput){
	popSize = popSizeInput;
	crossProb = crossProbInput;
	mutProb = mutProbInput;
	c_evaluator = c_evaluatorInput;
	srand(time(NULL));

	population = new vector<CIndividual*>();

	for (int i = 0; i < popSize; i++){
		population->push_back(new CIndividual(crossProb, mutProb, c_evaluator));
	}
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
	for (int i = 0; i < popSize; i++) {
		delete (*population)[i];
	}
	delete population;
	c_evaluator = NULL;
}


CIndividual* CGeneticAlgorithm::runIteration(){
	vCross();
	vMutate();

	int bestInvidualIndex = 0;
	double bestInvidualAdaptationTmp = 0;

	for (int i = 0; i < popSize; i++) {
		double tmpAdaptation = ((*population)[i])->dCalculateFitness();
		if (tmpAdaptation > bestInvidualAdaptationTmp) {
			bestInvidualIndex = i;
			bestInvidualAdaptationTmp = tmpAdaptation;
		}
	}
	return (*population)[bestInvidualIndex];
}

void CGeneticAlgorithm::vMutate(){
	for (int i = 0; i < popSize; i++) {
		((*population)[i])->vMutate(population);
	}
}

void CGeneticAlgorithm::vCross(){
	vector<CIndividual*>* newPopulation = new vector<CIndividual*>();

	while ((*newPopulation).size() < (popSize - (popSize % 2))) {
		int firtParent = iFindParent();
		int secondParent = iFindParent();
		vector<CIndividual*>* children = (*population)[firtParent]->cross((*population)[secondParent]);
		(*newPopulation).push_back((*children)[0]);
		(*newPopulation).push_back((*children)[1]);
		(*children)[0] = NULL;
		(*children)[1] = NULL;
		delete children;
	}

	if ((popSize % 2) == 1) {
		int firtParent = iFindParent();
		int secondParent = iFindParent();
		vector<CIndividual*>* children = (*population)[firtParent]->cross((*population)[secondParent]);
		(*newPopulation).push_back((*children)[0]);
		delete (*newPopulation)[1];
		(*children)[0] = NULL;
		delete children;
	}

	for (int i = popSize - 1; i >= 0; i--) {
		delete (*population)[i];
	}

	delete population;
	population = newPopulation;
	newPopulation = NULL;
	delete newPopulation;
}

int CGeneticAlgorithm::iFindParent() {
	int firtParent = rand() % (*population).size();
	int secondParent = rand() % (*population).size();
	
	if ((*population)[firtParent]->dCalculateFitness() >= (*population)[secondParent]->dCalculateFitness()) {
		return firtParent;
	}
	return secondParent;
}