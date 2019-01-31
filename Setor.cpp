/*
 * Setor.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Setor.h"

//construtor sem parâmetros
Setor::Setor() :
		nome("")
{
}

//construtor elementar
Setor::Setor(string n) :
		nome(n)
{
}

//construtor por cópia
Setor::Setor(const Setor &s) :
		nome(s.nome)
{

}

//destrutor
Setor::~Setor()
{
}

//retorna o nome do setor
string Setor::getNome() const
{
	return nome;
}

//modifica o nome do setor
void Setor::setNome(string n)
{
	nome = n;
}

//escreve os atributos do setor
void Setor::escrever() const
{
	cout << "Setor: " << nome << endl;
}

//lê os atributos do setor
void Setor::ler()
{
	string linha = "";
	cout << "Setor: ";
	getline(cin, linha);
	nome = linha;
}

//grava setor num ficheiro
void Setor::gravar(ostream &fout) const
{
	fout << nome << endl;
}

//lê setor de um ficheiro
void Setor::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	nome = linha;
}

//afeta o setor com o setor indicado
Setor & Setor::operator =(const Setor &s)
{
	nome = s.nome;
	return (*this);
}

//retorna true se tem os mesmos atributos do setor indicado
bool Setor::operator ==(const Setor &s) const
{
	return (nome == s.nome);
}
