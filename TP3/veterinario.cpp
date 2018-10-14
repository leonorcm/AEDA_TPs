
#include "veterinario.h"


string Veterinario::getNome() const {
	return nome;
}

int Veterinario::getCod() const
{
	return codOrdem;
}

Veterinario::Veterinario(string nome, int cod):
		nome(nome), codOrdem(cod) {}




