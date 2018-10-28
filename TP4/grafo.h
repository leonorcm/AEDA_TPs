#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template<class N, class A> class Aresta;

template<class N, class A>
class No {
public:
	N info;
	vector<Aresta<N, A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template<class N, class A>
class Aresta {
public:
	A valor;
	No<N, A> *destino;
	Aresta(No<N, A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template<class N, class A>
class Grafo {
	vector<No<N, A> *> nos;
public:
	Grafo();
	~Grafo();
	Grafo & inserirNo(const N &dados);
	Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
	Grafo & eliminarAresta(const N &inicio, const N &fim);
	A & valorAresta(const N &inicio, const N &fim);
	int numArestas(void) const;
	int numNos(void) const;
	void imprimir(std::ostream &os) const;
};

template<class N, class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N, A> &g);

// excecao  NoRepetido
template<class N>
class NoRepetido {
public:
	N info;
	NoRepetido(N inf) {
		info = inf;
	}
};
template<class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no) {
	out << "No repetido: " << no.info;
	return out;
}

// excecao NoInexistente
template<class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

// Aresta Repetida
template<class N>
class ArestaRepetida {
public:
	N inicio;
	N destino;
	ArestaRepetida(N inicio, N destino) {
		this->inicio = inicio;
		this->destino = destino;
	}
};

template<class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &ar) {
	out << "Aresta repetida: " << ar.inicio << " , " << ar.destino;
	return out;
}

template<class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni) {
	out << "No inexistente: " << ni.info;
	return out;
}

template<class N>
class ArestaInexistente {
public:
	N inicio;
	N destino;
	ArestaInexistente(N inicio, N destino) {
		this->inicio = inicio;
		this->destino = destino;
	}
};

template<class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &ai) {
	out << "Aresta inexistente: " << ai.inicio << " , " << ai.destino;
	return out;
}

template<class N, class A>
Grafo<N, A>::Grafo() {
}

template<class N, class A>
Grafo<N, A>::~Grafo() {
	for (int i = 0; i < nos.size(); i++) {
		nos.erase(nos.begin());
	}
}

template<class N, class A>
int Grafo<N, A>::numNos(void) const {
	return nos.size();
}

template<class N, class A>
int Grafo<N, A>::numArestas(void) const {
	int contador = 0;
	for (int i = 0; i < nos.size(); i++) {
		contador = contador + nos.at(i)->arestas.size();
	}

	return contador;
}

template<class N, class A>
Grafo<N, A> & Grafo<N, A>::inserirNo(const N &dados) {
	for (unsigned int i = 0; i < nos.size(); i++) {
		if (this->nos.at(i)->info == dados) {
			throw NoRepetido<N>(dados);
		}
	}
	No<N, A> *no = new No<N, A>(dados);
	nos.push_back(no);
	return *this;

}

template<class N, class A>
Grafo<N, A> & Grafo<N, A>::inserirAresta(const N &inicio, const N &fim, const A &val) {
		for(unsigned int i = 0; i < this->nos.size(); i++){ //ver todos os nos
			if(this->nos.at(i)->info == inicio){ //caso contrario linha 176
				for(unsigned int j = 0; j < this->nos[i]->arestas.size(); j++){ // ver todas as arestas que estão dentro do vetor nós
					if(this->nos[i]->arestas[j].destino->info == fim){
						throw ArestaRepetida<N>(inicio, fim);
					}
				}
				for(unsigned int j = 0; j < this->nos.size();j++){
					if(this->nos.at(j)->info == fim){ //caso contrario linha 172
						Aresta<N, A> *a = new Aresta<N,A>(this->nos[j],val);
						this->nos.at(i)->arestas.push_back(*a);
						return *this;
					}
				}
				throw NoInexistente<N>(fim);
			}
		}
		throw NoInexistente<N>(inicio);
	}

template<class N, class A>
A & Grafo <N,A>::valorAresta(const N &inicio, const N &fim){
	for(unsigned int i = 0; i < this->nos.size(); i++){
				if(this->nos.at(i)->info == inicio){
					for(unsigned int j = 0; j < this->nos[i]->arestas.size(); j++){
						if(this->nos[i]->arestas[j].destino->info != fim){
							throw ArestaInexistente<N>(inicio, fim);
						}
						else return this->nos[i]->arestas[j].valor;
					}
				} else throw NoInexistente<N>(inicio);
}
}

template <class N, class A>
Grafo<N, A> & Grafo<N, A>::eliminarAresta(const N &inicio, const N &fim){
	for(unsigned int i = 0; i < this->nos.size(); i++){
					if(this->nos.at(i)->info == inicio){
						for(unsigned int j = 0; j < this->nos[i]->arestas.size(); j++){
							if(this->nos[i]->arestas[j].destino->info != fim){
								throw ArestaInexistente<N>(inicio, fim);
							}
							else {
							this->nos[i]->arestas.erase(this->nos[i]->arestas.begin()+j);
								return *this;
							}
						}
					}
	}
		throw NoInexistente<N>(inicio);
	}

template <class N, class A>
void Grafo<N,A>::imprimir(std::ostream &os) const {
	for(unsigned int i = 0; i < this->nos.size(); i++) {
		os << "( ";
		os << this->nos.at(i)->info;
	for(unsigned int j = 0; j < this->nos[i]->arestas.size(); j++){
		os << "[ " << this->nos[i]->arestas[j].destino->info << " " << this->nos[i]->arestas[j].valor << "] ";
		}
	os << ") ";

}

}

template <class N, class A>
ostream & operator<<(ostream &os, const Grafo<N,A> &s){
	s.imprimir(os);
	return os;
}



