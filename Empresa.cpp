/*
 * Empresa.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Empresa.h"

//construtor sem parâmetros
Empresa::Empresa() :
		nome("")
{
}

//construtor elementar
Empresa::Empresa(string n) :
		nome(n)
{
}

//construtor por cópia
Empresa::Empresa(const Empresa &e) :
		nome(e.nome)
{

}

//destrutor
Empresa::~Empresa()
{
}

//retorna o nome da empresa
string Empresa::getNome() const
{
	return nome;
}

//modifica o nome da empresa
void Empresa::setNome(string n)
{
	nome = n;
}

//escreve os atributos da empresa
void Empresa::escrever() const
{
	cout << "Empresa: " << nome << endl;
}

//le os atributos
void Empresa::ler()
{
	string linha = "";
	cout << "Empresa: ";
	getline(cin, linha);
	nome = linha;
}

//grava o nome num ficheiro
void Empresa::gravar(ostream &fout) const
{
	fout << nome << endl;
}

//lê o nome de um ficheiro
void Empresa::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	nome = linha;
}

//afeta a empresa com a empresa indicado
Empresa & Empresa::operator =(const Empresa &e)
{
	nome = e.nome;
	return (*this);
}

//retorna true se tem os mesmos atributos da empresa indicada
bool Empresa::operator ==(const Empresa &e) const
{
	return (nome == e.nome);
}

