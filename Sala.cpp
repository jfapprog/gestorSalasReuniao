/*
 * Sala.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include <cstdlib>
#include "Sala.h"

//construtor sem parâmetros
Sala::Sala() :
		id(""), capacidade(0)
{
}

//construtor elementar
Sala::Sala(string i, int c) :
		id(i), capacidade(c)
{
}

//construtor por cópia
Sala::Sala(const Sala &s) :
		id(s.id), capacidade(s.capacidade)
{
}

//destrutor
Sala::~Sala()
{
}

//retorna o id da sala
string Sala::getId() const
{
	return id;
}

//retorna a capacidade da sala
int Sala::getCapacidade() const
{
	return capacidade;
}

//modifica a id da sal
void Sala::setId(string i)
{
	id = i;
}

//modifica a capacidade da sala
void Sala::setCapacidade(int c)
{
	capacidade = c;
}

//escreve os atributos da sala
void Sala::escrever() const
{
	cout << "Sala: " << id << endl;
	cout << "Capacidade: " << capacidade << endl;
}

//lê os atributos da sala
void Sala::ler()
{
	string linha1 = "";
	cout << "Id: ";
	getline(cin, linha1);
	id = linha1;
	cout << "Capacidade: ";
	getline(cin, linha1);
	capacidade = atoi(linha1.c_str());
}

//grava os atributos de sala num ficheiro
void Sala::gravar(ostream &fout) const
{
	fout << id << endl;
	fout << capacidade << endl;
}

//abre os atributos de sala de um ficheiro
void Sala::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	id = linha;
	getline(fin, linha);
	capacidade = atoi(linha.c_str());
}

//afeta a sala com a sala indicada
Sala & Sala::operator =(const Sala &s)
{
	id = s.id;
	capacidade = s.capacidade;
	return (*this);
}

//retorna true se tem o id igual à sala indicada
bool Sala::operator ==(const Sala &s) const
{
	return (id == s.id);
}
