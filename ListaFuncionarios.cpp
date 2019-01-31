/*
 * ListaFuncionarios.cpp
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "ListaFuncionarios.h"

//construtor sem parâmetros
ListaFuncionarios::ListaFuncionarios()
{
}

//destrutor
ListaFuncionarios::~ListaFuncionarios()
{
}

//adiciona um funcionário à lista
void ListaFuncionarios::adicionar(const Funcionario &f)
{
	lista.push_back(f);
}

//remove o funcionário de índice indicado
void ListaFuncionarios::remover(int i)
{
	lista.erase(lista.begin() + i);
}

//retorna uma referência para o funcionário de índice indicado
Funcionario & ListaFuncionarios::operator [](int i)
{
	return lista[i];
}

//retorna o número de funcionários da lista
int ListaFuncionarios::getNumero() const
{
	return static_cast<int>(lista.size());
}

//escreve a lista de funcionários com no máximo n funcionários (por defeito, 5)
void ListaFuncionarios::escrever() const
{
	int cont = 1;
	vector<Funcionario>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		cout << "\n#Funcionário " << cont << endl;
		i->escrever();
		cont++;
	}
}

//grava num ficheiro
void ListaFuncionarios::gravar(ostream &fout) const
{
	fout << lista.size() << endl;
	vector<Funcionario>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
		i->gravar(fout);
}

//lê de um ficheiro
void ListaFuncionarios::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	int n = atoi(linha.c_str());
	Funcionario f;
	for (int i = 0; i < n; i++)
	{
		f.abrir(fin);
		lista.push_back(f);
	}
}

//retorna true se já contém o funcionário
bool ListaFuncionarios::contem(const Funcionario &f) const
{
	vector<Funcionario>::const_iterator i;
	for (i = lista.begin(); i != lista.end(); i++)
	{
		if (*i == f)
			return true;
	}
	return false;
}
