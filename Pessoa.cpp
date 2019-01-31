/*
 * Pessoa.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include <cstdlib>
#include "Pessoa.h"

//construtor sem parâmetros
Pessoa::Pessoa() :
		nome(""), telefone(0)
{
}

//construtor elementar
Pessoa::Pessoa(string n, int t) :
		nome(n), telefone(t)
{
}

//construtor por cópia
Pessoa::Pessoa(const Pessoa &p) :
		nome(p.nome), telefone(p.telefone)
{
}

//destrutor
Pessoa::~Pessoa()
{
}

//retorna o nome
string Pessoa::getNome() const
{
	return nome;
}

//retorna o telefone
int Pessoa::getTelefone() const
{
	return telefone;
}

//modifica o nome
void Pessoa::setNome(string n)
{
	nome = n;
}

//modifica o telefone
void Pessoa::setTelefone(int t)
{
	telefone = t;
}

//escreve os atributos
void Pessoa::escrever() const
{
	cout << "Nome: " << nome << endl;
	cout << "Telefone: " << telefone << endl;
}

//le os atributos
void Pessoa::ler()
{
	string linha = "";
	cout << "Nome: ";
	getline(cin, linha);
	nome = linha;
	cout << "Telefone: ";
	getline(cin, linha);
	telefone = atoi(linha.c_str());
}

//grava num ficheiro
void Pessoa::gravar(ostream &fout) const
{
	fout << nome << endl;
	fout << telefone << endl;
}

//le de um ficheiro
void Pessoa::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	nome = linha;
	getline(fin, linha);
	telefone = atoi(linha.c_str());
}

//afeta com a pessoa indicada
Pessoa & Pessoa::operator =(const Pessoa &p)
{
	nome = p.nome;
	telefone = p.telefone;
	return (*this);
}

//retorna true se tem os mesmos atributos da pessoa indicada
bool Pessoa::operator ==(const Pessoa &p) const
{
	return (nome == p.nome && telefone == p.telefone);
}
