#pragma once
#include <vector>
#include "Evaluator.h"


using namespace std;

class CIndividual{
public:

	CIndividual(double crossProbInput, double mutProbInput, CLFLnetEvaluator* c_evaluatorInput);
	CIndividual(CIndividual* firstParent, CIndividual* secondParent, int genotypeCut);
	CIndividual(CIndividual* other);
	~CIndividual();
	double dCalculateFitness();
	void vMutate(vector<CIndividual*>* population);
	vector<CIndividual*>* cross(CIndividual* sndParent);
	vector<int> getGenotype();
	int iGetSpecificGenotype(int index);
	int iGetGenotypeLen();

private:
	double mutProb;
	double crossProb;
	vector<int>* genotype;
	CLFLnetEvaluator* c_evaluator;
};