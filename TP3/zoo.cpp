#include "zoo.h"




int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1)
{
	animais.push_back(a1);
}

string Zoo::getInformacao() const
{
ostringstream informacao; //creating an empty string
for(unsigned int i=0; i < animais.size(); i++)
{
informacao << animais.at(i)->getInformacao();

}

return informacao.str(); //this function returns a string, and informacao is a ostringstream (so i could use the << operator), ".str()" solves that
}


bool Zoo::animalJovem(string nomeA){
	for (unsigned int i=0; i < animais.size(); i++)
	{
		if ((animais.at(i)->Animal::getNome() == nomeA) && (animais.at(i)->eJovem()))
				return true;
	}
	return false;

}

 void Zoo::alocaVeterinarios(istream &isV){
	string nome;
	string cod;
	while (!isV.eof())
	{
		getline(isV, nome);
		getline (isV, cod);
		Veterinario *a = new Veterinario(nome, std::stoi(cod));
		this->veterinarios.push_back(a);
	}

	unsigned int i=0; //count the vets
	for(Animal * a:this->animais){
		if (i == (this->animais.size()-1))
		{
			a->setvet(this->veterinarios.at(i));
			i=0;
		}
		else
		{
		a->setvet(this->veterinarios.at(i));
		i++;
		}
	}

}





