#include "CIndividual.h"

CIndividual::CIndividual(double crossProbInput, double mutProbInput, CLFLnetEvaluator* c_evaluatorInput){
	genotype = new vector<int>();
	c_evaluator = c_evaluatorInput;
	mutProb = mutProbInput;
	crossProb = crossProbInput;
	
	for (int j = 0; j < c_evaluator->iGetNumberOfBits(); j++){
		genotype->push_back(lRand(c_evaluator->iGetNumberOfValues(j)));
	}
}

CIndividual::CIndividual(CIndividual* firstParent, CIndividual* secondParent, int genotypeCut){
	genotype = new vector<int>();
	c_evaluator = firstParent->c_evaluator;
	mutProb = firstParent->mutProb;
	crossProb = firstParent->crossProb;

	for (int i = 0; i < genotypeCut; i++) {
		genotype->push_back(firstParent->iGetSpecificGenotype(i));
	}

	for (int i = genotypeCut; i < firstParent->iGetGenotypeLen(); i++) {
		genotype->push_back(secondParent->iGetSpecificGenotype(i));
	}
}

CIndividual::CIndividual(CIndividual* parent){
	mutProb = parent->mutProb;
	crossProb = parent->crossProb;
	genotype = new vector<int>;

	for (int i = 0; i < parent->iGetGenotypeLen(); i++) {
		genotype->push_back(parent->iGetSpecificGenotype(i));
	}
}

CIndividual::~CIndividual() {	delete genotype;	c_evaluator = NULL;		}

int CIndividual::iGetSpecificGenotype(int index) {
	if (index >= genotype->size()) {	return (*genotype)[0];	}

	return (*genotype)[index];
}

double CIndividual::dCalculateFitness(){
	double fitness = c_evaluator->dEvaluate(genotype);
	return fitness;
}

void CIndividual::vMutate(vector<CIndividual*>* population){
	int genotypeMutation = (rand() % (genotype->size()));

	vector<int> individualsWithDifferentGenotype;
	int vactorIndexTmp = 0;

	for (int i = 0; i < population->size(); i++) {
		if (((*population)[i])->iGetSpecificGenotype(genotypeMutation) != (*genotype)[i]) {
			individualsWithDifferentGenotype.push_back(i);
			vactorIndexTmp += 1;
		}
	}

	if (vactorIndexTmp != 0) {
		int randomIndividual = (rand() % (vactorIndexTmp));
		(*genotype)[genotypeMutation] = (*population)[individualsWithDifferentGenotype[randomIndividual]]->iGetSpecificGenotype(genotypeMutation);
	}	
}

vector<CIndividual*>* CIndividual::cross(CIndividual* sndParent){
	int possibleGenotypeCuts = (genotype->size())-1;
	int currentCut = (rand() % possibleGenotypeCuts) + 1;

	//cout << "currentCut: " << currentCut << endl;

	CIndividual* firstChild = new CIndividual(this, sndParent, currentCut);
	CIndividual* secondChild = new CIndividual(sndParent, this, currentCut);

	vector<CIndividual*>* children = new vector<CIndividual*>();
	children->push_back(firstChild);
	children->push_back(secondChild);
	return children;
}

vector<int> CIndividual::getGenotype() {	return (*genotype);		}

int CIndividual::iGetGenotypeLen() {	return genotype->size();	}