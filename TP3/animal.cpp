
#include "animal.h"
#include <iostream>
#include <fstream>
#include <string>

int Animal::maisJovem = 0x7fffffff;

string Animal::getNome() const {
	return nome;
}

void Animal::setvet(Veterinario *v){
	this->vet = v;
}


Animal::Animal(string nome, int idade):
	nome(nome), idade(idade)
{
	if (idade < this->maisJovem) maisJovem=idade;
}


string Animal::getInformacao() {
	ostringstream a;
	if (this->vet != NULL)
	{
		a << this->vet->getNome() << ", " << this->vet->getCod();
	}
	else (a << this->getNome() << ", " << this->idade);

return a.str();
}


int Voador::getVmax() const {
	return this->velocidade_max;
}


int Voador::getAmax() const {
	return this->altura_max;
}


Cao::Cao(string nome, int idade, string raca):
		Animal(nome, idade)
{
	this->raca=raca;
}

 string Cao::getInformacao()
 {
	 ostringstream c;
	 c << Animal::getInformacao() << ", "<< this->raca;


	 return c.str(); //explained in zoo.cpp
 }

Voador::Voador(int vmax, int amax):
		velocidade_max(vmax), altura_max(amax) {}

Morcego::Morcego(string nome, int idade, int vmax, int amax):
		Animal(nome, idade),
		Voador(vmax, amax) {}

string Morcego::getInformacao()
{
	 ostringstream m;
	m << Animal::getInformacao()<< ", "<<  this->getVmax() << ", " << this->getAmax();
	 return m.str();
}

int Animal::getMaisJovem()
{
	return maisJovem;
}

bool Cao::eJovem()const
{
	if (this->idade < 5) return true;
	else return false;
}

bool Morcego::eJovem()const
{
	if (this->idade < 4) return true;
	else return false;
}







