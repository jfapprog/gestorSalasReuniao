/*
 * Cliente.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include "Cliente.h"

//construtor sem parâmetros
Cliente::Cliente() :
		Pessoa(), empresa()
{
}

//construtor elementar
Cliente::Cliente(const Pessoa &p, const Empresa &e) :
		Pessoa(p), empresa(e)
{
}

//construtor por cópia
Cliente::Cliente(const Cliente &c) :
		Pessoa(c), empresa(c.empresa)
{
}

//destrutor
Cliente::~Cliente()
{
}

//retorna uma referência constante para a empresa
const Empresa & Cliente::getEmpresa() const
{
	return empresa;
}

//modifica a empresa
void Cliente::setEmpresa(const Empresa &e)
{
	empresa = e;
}

//escreve os atributos do cliente
void Cliente::escrever() const
{
	Pessoa::escrever();
	empresa.escrever();
}

//le os atributos
void Cliente::ler()
{
	Pessoa::ler();
	empresa.ler();
}

//grava num ficheiro
void Cliente::gravar(ostream &fout) const
{
	Pessoa::gravar(fout);
	empresa.gravar(fout);
}

//le de um ficheiro
void Cliente::abrir(istream &fin)
{
	Pessoa::abrir(fin);
	empresa.abrir(fin);
}

//afeta com o Cliente indicado
Cliente & Cliente::operator =(const Cliente &c)
{
	Pessoa::operator =(c);
	empresa = c.empresa;
	return (*this);
}

//retorna true se tem os mesmos atributos do funcionário indicado
bool Cliente::operator ==(const Cliente &c) const
{
	return (Pessoa::operator ==(c) && empresa == c.empresa);
}

