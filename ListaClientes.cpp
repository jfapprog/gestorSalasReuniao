/*
 * ListaClientes.cpp
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "ListaClientes.h"

//construtor sem parâmetros
ListaClientes::ListaClientes()
{
}

//destrutor
ListaClientes::~ListaClientes()
{
}

//adiciona um cliente à lista
void ListaClientes::adicionar(const Cliente &c)
{
	lista.push_back(c);
}

//remove o cliente de índice indicado
void ListaClientes::remover(int i)
{
	lista.erase(lista.begin() + i);
}

//retorna uma referência para o cliente de índice indicado
Cliente & ListaClientes::operator [](int i)
{
	return lista[i];
}

//retorna o número de clientes da lista
int ListaClientes::getNumero() const
{
	return static_cast<int>(lista.size());
}

//escreve a lista de clientes com no máximo n clientes (por defeito, 5)
void ListaClientes::escrever() const
{
	int cont = 1;
	vector<Cliente>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		cout << "\n#Cliente " << cont << endl;
		i->escrever();
		cont++;
	}
}

//grava num ficheiro
void ListaClientes::gravar(ostream &fout) const
{
	fout << lista.size() << endl;
	vector<Cliente>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
		i->gravar(fout);
}

//lê de um ficheiro
void ListaClientes::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	int n = atoi(linha.c_str());
	Cliente c;
	for (int i = 0; i < n; i++)
	{
		c.abrir(fin);
		lista.push_back(c);
	}
}

//retorna true se já existe o cliente na lista
bool ListaClientes::contem(const Cliente &c) const
{
	vector<Cliente>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (*i == c)
			return true;
	}
	return false;
}

