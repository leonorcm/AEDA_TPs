#include "Veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a):
		marca(mc), mes(m), ano(a) {}

Motorizado::Motorizado(string mc, int m, int a,string c,int cil):
	Veiculo(mc,m,a)
{
	combustivel = c;
	cilindrada = cil;
}

Automovel::Automovel(string mc, int m, int a,string c, int cil):
		Motorizado(mc,m,a,c,cil)
{

}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm):
		Motorizado (mc,m,a,c,cil)
{
	carga_maxima = cm;
}

Bicicleta::Bicicleta(string mc, int m, int a,string t):
		Veiculo(mc,m,a)
{
	tipo = t;
}

string Motorizado::getCombustivel() const {
	return combustivel;
	}

string Veiculo::getMarca() const {
	return marca;
}
 int Veiculo::getAno() const
 {
	 return ano;
 }

 int Veiculo::info() const
 {
	 cout << marca << " " << mes << " " << ano << endl;
	 return 3;

 }

 int Motorizado::info() const
 {
	 Veiculo::info();
	 cout << combustivel << " " << cilindrada << endl;
	 return 5;
 }

 int Automovel::info() const
 {
	 Motorizado::info();
	 return 5;
 }

int Camiao::info() const
{
	Motorizado::info();
	cout << carga_maxima << endl;
	return 6;
}

int Bicicleta::info() const
{
	cout << tipo << endl;
	Veiculo::info();
	return 4;
}

bool Veiculo::operator < (const Veiculo & v) const
{
	if (this->getAno()<v.getAno())
		return true;
	if ((this->getAno()==v.getAno()) && (this->mes < v.mes))
			return true;
	else return false;
}



float Veiculo::calcImposto() const
{
	return 0;
}

float Motorizado::calcImposto() const
{
	float imposto;
	if (this->combustivel == "gasolina")
	{
		if(this->cilindrada <=1000)
		{
			if (this->ano > 1995)(imposto = 14.56);
			else imposto = 8.10;
		}

		else if(this->cilindrada <=1300)
		{
			if (this->ano > 1995)(imposto = 29.06);
			else imposto = 14.56;
		}
		else if(this->cilindrada <=1750)
				{
				if (this->ano > 1995)(imposto=45.15);
					else imposto=22.65;
				}
		else if(this->cilindrada <=2600)
				{
					if (this->ano > 1995)(imposto=113.98);
					else imposto=54.89;
				}
		else if(this->cilindrada <=3500)
				{
					if (this->ano > 1995)(imposto=181.17);
					else imposto=87.13;
				}
		else if(this->cilindrada > 3500)
				{
					if (this->ano > 1995)(imposto=320.89);
					else imposto=148.37;

				}


	}
	else
	{
		if(this->cilindrada <=1500)
						{
							if (this->ano > 1995)(imposto=14.56);
							else imposto=8.10;
						}
		else if(this->cilindrada <=2000)
						{
							if (this->ano > 1995)(imposto=29.06);
							else imposto=14.56;
						}
		else if(this->cilindrada <=3000)
						{
							if (this->ano > 1995)(imposto=45.15);
							else imposto=22.65;
						}
		else if(this->cilindrada > 3000)
								{
									if (this->ano > 1995)(imposto=113.98);
									else imposto=54.89;
								}

}
	return imposto;
}







