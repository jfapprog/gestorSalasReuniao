/*
 * ListaReunioes.cpp
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "ListaReunioes.h"

//construtor sem parâmetros
ListaReunioes::ListaReunioes()
{
}

//destrutor
ListaReunioes::~ListaReunioes()
{
}

//adiciona uma reunião à lista
void ListaReunioes::adicionar(const Reuniao &r)
{
	lista.push_back(r);
}

//remove a reunião de índice indicado
void ListaReunioes::remover(int i)
{
	lista.erase(lista.begin() + i);
}

//retorna uma referência para a reunião de índice indicado
Reuniao & ListaReunioes::operator [](int i)
{
	return lista[i];
}

//retorna o número de reuniões da lista
int ListaReunioes::getNumero() const
{
	return static_cast<int>(lista.size());
}

//retorna o número de reuniões no intervalo das datas indicadas
int ListaReunioes::getNumero(const Data &di, const Data &df) const
{
	int cont = 0;
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (i->getData() >= di && i->getData() <= df)
			cont++;
	}
	return cont;
}

//escreve a lista de reuniões com no máximo n reuniões (por defeito, 5)
void ListaReunioes::escrever() const
{
	int cont = 1;
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		cout << "\n#Reunião " << cont << endl;
		i->escrever();
		cont++;
	}
}

//escreve a lista de reuniões no intervalo das datas indicadas
void ListaReunioes::escrever(const Data &di, const Data &df) const
{
	int cont = 1;
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (i->getData() >= di && i->getData() <= df)
		{
			cout << "\n#Reunião " << cont << endl;
			i->escrever();
		}
		cont++;
	}
}

//grava a lista num ficheiro
void ListaReunioes::gravar(ostream &fout) const
{
	fout << lista.size() << endl;
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
		i->gravar(fout);
}

//lê de um ficheiro
void ListaReunioes::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	int n = atoi(linha.c_str());
	Reuniao r;
	for (int i = 0; i < n; i++)
	{
		r.abrir(fin);
		lista.push_back(r);
	}
}

//retorna true se a reunião indicada já existe na lista
bool ListaReunioes::contem(const Reuniao &r) const
{
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (*i == r)
			return true;
	}
	return false;
}

//retorna true se existe uma reunião com data e horas em simultâneo
bool ListaReunioes::coincide(const Reuniao &r) const
{
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (i->getSituacao() == Reuniao::Marcada && i->getSala() == r.getSala()
				&& i->getData() == r.getData())
		{
			if (r.getHoraInicio() >= i->getHoraInicio()
					&& r.getHoraInicio() < i->getHoraFim())
				return true;
			if (r.getHoraFim() < i->getHoraInicio()
					&& r.getHoraFim() >= i->getHoraFim())
				return true;
		}
	}
	return false;
}

//retorna true se a sala está reservada para uma determinada data
bool ListaReunioes::ocupada(const Sala &s, const Data &d) const
{
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (i->getSituacao() == Reuniao::Marcada && i->getSala() == s
				&& i->getData() == d)
			return true;
	}
	return false;
}

//retorna true se a sala está reservada para uma determinada data e horário
bool ListaReunioes::ocupada(const Sala &s, const Data &d, const Hora &hi,
		const Hora &hf) const
{
	vector<Reuniao>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (i->getSituacao() == Reuniao::Marcada && i->getSala() == s
				&& i->getData() == d)
		{
			if (hi >= i->getHoraInicio() && hi < i->getHoraFim())
				return true;
			if (hf < i->getHoraInicio() && hf >= i->getHoraFim())
				return true;
		}
	}
	return false;
}
