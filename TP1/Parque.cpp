#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot,
		unsigned int nMaxCli) :
		lotacao(lot), numMaximoClientes(nMaxCli) {
	vagas = lotacao;
}

unsigned int ParqueEstacionamento::getNumLugares() const {
	return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
	return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
	while (true) {

	}
}

