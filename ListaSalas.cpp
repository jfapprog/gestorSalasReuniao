/*
 * ListaSalas.cpp
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "ListaSalas.h"

//construtor sem parâmetros
ListaSalas::ListaSalas()
{
}

//destrutor
ListaSalas::~ListaSalas()
{
}

//adiciona uma sala à lista
void ListaSalas::adicionar(const Sala &s)
{
	lista.push_back(s);
}

//remove a sala de índice indicado
void ListaSalas::remover(int i)
{
	lista.erase(lista.begin() + i);
}

//retorna uma referência para a sala de índice indicado
Sala & ListaSalas::operator [](int i)
{
	return lista[i];
}

//retorna o número de salas da lista
int ListaSalas::getNumero() const
{
	return static_cast<int>(lista.size());
}

//escreve a lista de salas com no máximo n salas (por defeito, 5)
void ListaSalas::escrever() const
{
	int cont = 1;
	vector<Sala>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		cout << "\n#Sala " << cont << endl;
		i->escrever();
		cont++;
	}
}

//grava a lista de salas num ficheiro
void ListaSalas::gravar(ostream &fout) const
{
	fout << lista.size() << endl;
	vector<Sala>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
		i->gravar(fout);
}

//lê a lista de salas de um ficheiro
void ListaSalas::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	int n = atoi(linha.c_str());
	Sala s;
	for (int i = 0; i < n; i++)
	{
		s.abrir(fin);
		lista.push_back(s);
	}
}

//retorna true se a sala indicada já existe na lista
int ListaSalas::contem(const Sala &s) const
{
	int ind = 0;
	vector<Sala>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		ind++;
		if (*i == s)
			return ind;
	}
	return 0;
}
