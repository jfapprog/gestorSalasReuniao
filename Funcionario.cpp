/*
 * Funcionario.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Funcionario.h"

//construtor sem parâmetros
Funcionario::Funcionario() :
		Pessoa(), cargo(""), setor()
{
}

//construtor elementar
Funcionario::Funcionario(const Pessoa &p, string c, const Setor &s) :
		Pessoa(p), cargo(c), setor(s)
{
}

//construtor por cópia
Funcionario::Funcionario(const Funcionario &f) :
		Pessoa(f), cargo(f.cargo), setor(f.setor)
{
}

//destrutor
Funcionario::~Funcionario()
{
}

//retorna o cargo
string Funcionario::getCargo() const
{
	return cargo;
}

//retorna uma referência constante para o setor
const Setor & Funcionario::getSetor() const
{
	return setor;
}

//modifica o cargo
void Funcionario::setCargo(string c)
{
	cargo = c;
}

//modifica o setor
void Funcionario::setSetor(const Setor &s)
{
	setor = s;
}

//escreve os atributos do funcionario
void Funcionario::escrever() const
{
	Pessoa::escrever();
	cout << "Cargo: " << cargo << endl;
	setor.escrever();
}

//le os atributos
void Funcionario::ler()
{
	Pessoa::ler();
	string linha = "";
	cout << "Cargo: ";
	getline(cin, linha);
	cargo = linha;
	setor.ler();
}

//grava num ficheiro
void Funcionario::gravar(ostream &fout) const
{
	Pessoa::gravar(fout);
	fout << cargo << endl;
	setor.gravar(fout);
}

//lê de um ficheiro
void Funcionario::abrir(istream &fin)
{
	Pessoa::abrir(fin);
	string linha = "";
	getline(fin, linha);
	cargo = linha;
	setor.abrir(fin);
}

//afeta com o funcionario indicado
Funcionario & Funcionario::operator =(const Funcionario &f)
{
	Pessoa::operator =(f);
	cargo = f.cargo;
	setor = f.setor;
	return (*this);
}

//retorna true se tem os mesmos atributos do funcionário indicado
bool Funcionario::operator ==(const Funcionario &f) const
{
	return (Pessoa::operator ==(f) && cargo == f.cargo && setor == f.setor);
}
