
#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <iterator>

class Zoo {
	vector<Animal *> animais;
	vector<Veterinario *> veterinarios;
public:
	int numAnimais() const;
	int numVeterinarios() const;
	void adicionaAnimal(Animal *a1);
	string getInformacao() const;
	bool animalJovem(string nomeA);
	void alocaVeterinarios(istream &isV);

};


#endif /* ZOO_H_ */
