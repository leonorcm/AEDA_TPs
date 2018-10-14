#include "Frota.h"
#include <string>
#include <strstream>


using namespace std;


void Frota::adicionaVeiculo(Veiculo *v1)
{
veiculos.push_back(v1); //adding v1 to veiculos
}

int Frota::numVeiculos() const
{
return veiculos.size();
}

int Frota::menorAno() const
{
	int menor= 0x7fffff; //putting a huge number at menor, so any number will be smaller than him
	if (veiculos.empty()) return 0;

	for (size_t i=0; i< veiculos.size(); i++)
	{
		if (veiculos.at(i)->getAno() < menor) //getAno because we are talking about ages.
		{
			menor = veiculos.at(i)->getAno();
		}
//comparing each veiculo to the one that is into menor, if it happends to be smaller than him, becomes menor.

	}
	return menor;
}

ostream & operator<<(ostream & o, const Frota & f)
{
	for (int i=0; i<f.numVeiculos();i++)
	{
		o << f.veiculos.at(i)->info();
	}
	return o;
}

vector<Veiculo *> Frota::operator () (int anoM) const
{
	vector<Veiculo *> a;
	for (int i=0; i<veiculos.size(); i++)
	{
		if (veiculos.at(i)->getAno() == anoM)
			a.push_back(veiculos.at(i));
	}
	return a;
}
float Frota::totalImposto() const
{
	float total=0;
	for(int i=0; i <= numVeiculos(); i++)
	{
		total= total + veiculos.at(i)->calcImposto();
	}
	return  total;
}
