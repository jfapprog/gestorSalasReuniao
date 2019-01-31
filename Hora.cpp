/*
 * Hora.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Hora.h"

//construtor sem parâmetros
Hora::Hora()
{
	time_t hora0 = time(0);
	struct tm *agora = localtime(&hora0);
	horas = agora->tm_hour;
	minutos = agora->tm_min;
}

//construtor elementar
Hora::Hora(int h, int m) :
		horas(h), minutos(m)
{
}

//construtor cópia
Hora::Hora(const Hora &h) :
		horas(h.horas), minutos(h.minutos)
{
}

//destrutor
Hora::~Hora()
{
}

//retorna as horas
int Hora::getHoras() const
{
	return horas;
}

//retorna os minutos
int Hora::getMinutos() const
{
	return minutos;
}

//modifica as horas
void Hora::setHoras(int h)
{
	horas = h;
}

//modifica os minutos
void Hora::setMinutos(int m)
{
	minutos = m;
}

//escreve as horas e minutos
void Hora::escrever() const
{
	cout << horas << "h " << minutos << "m" << endl;
}

//le as horas e minutos
void Hora::ler()
{
	bool valida = false;
	do
	{
		string linha = "";
		cout << "Horas: ";
		getline(cin, linha);
		int h = atoi(linha.c_str());
		cout << "Minutos: ";
		getline(cin, linha);
		int m = atoi(linha.c_str());
		if (Hora::validar(h, m))
		{
			horas = h;
			minutos = m;
			valida = true;
		}
		else
			cout << "Hora inválida" << endl;
	} while (!valida);
}

//grava as horas e minutos num ficheiro
void Hora::gravar(ostream &fout) const
{
	fout << horas << endl;
	fout << minutos << endl;
}

//le as horas de um ficheiro
void Hora::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	horas = atoi(linha.c_str());
	getline(fin, linha);
	minutos = atoi(linha.c_str());
}

//afeta a hora com a hora indicada
Hora & Hora::operator =(const Hora &h)
{
	horas = h.horas;
	minutos = h.minutos;
	return (*this);
}

//retorna true se a hora é igual à hora indicada
bool Hora::operator ==(const Hora &h) const
{
	return (horas == h.horas && minutos == h.minutos);
}

//retorna true se a data é menor à indicada
bool Hora::operator <(const Hora &h) const
{
	return horas < h.horas || (horas == h.horas && minutos < h.minutos);
}

//retorna true se a data é menor ou igual à indicada
bool Hora::operator <=(const Hora &h) const
{
	return operator <(h) || operator ==(h);
}

//retorna true se a data é maior à indicada
bool Hora::operator >(const Hora &h) const
{
	return !operator <=(h);
}

//retorna true se a data é maior ou igual à indicada
bool Hora::operator >=(const Hora &h) const
{
	return !operator <(h);
}

//retorna true se os dois argumentos constituem uma hora
bool Hora::validar(int h, int m)
{
	return (h >= 0 && h <= 23) && (m >= 0 && m <= 59);
}
