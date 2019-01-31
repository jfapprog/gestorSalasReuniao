/*
 * Data.cpp
 *
 *  Created on: 22/05/2015
 *      Author: José Félix Póvoa
 */

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Data.h"

const int Data::diasDoMes[12] =
{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//construtor sem parâmetros - inicia com a data atual do sistema
Data::Data()
{
	time_t data0 = time(0);
	struct tm *hoje = localtime(&data0);
	dia = hoje->tm_mday;
	mes = hoje->tm_mon + 1;
	ano = hoje->tm_year + 1900;
}

//construtor elementar
Data::Data(int d, int m, int a) :
		dia(d), mes(m), ano(a)
{
}

//construtor por cópia
Data::Data(const Data &d) :
		dia(d.dia), mes(d.mes), ano(d.ano)
{
}

//destrutor
Data::~Data()
{
}

//retorna o dia
int Data::getDia() const
{
	return dia;
}

//retorna o mes
int Data::getMes() const
{
	return mes;
}

//retorna o ano
int Data::getAno() const
{
	return ano;
}

//modifica o dia
void Data::setDia(int d)
{
	dia = d;
}

//modifica o mes
void Data::setMes(int m)
{
	mes = m;
}

//modifica o ano
void Data::setAno(int a)
{
	ano = a;
}

//escreve a data
void Data::escrever() const
{
	cout << dia << " " << mes << " " << ano << endl;
}

//le a data
void Data::ler()
{
	bool valida = false;
	do
	{
		string linha = "";
		cout << "Dia: ";
		getline(cin, linha);
		int d = atoi(linha.c_str());
		cout << "Mes: ";
		getline(cin, linha);
		int m = atoi(linha.c_str());
		cout << "Ano: ";
		getline(cin, linha);
		int a = atoi(linha.c_str());
		if (Data::validar(d, m, a))
		{
			dia = d;
			mes = m;
			ano = a;
			valida = true;
		}
		else
			cout << "Data inválida" << endl;
	} while (!valida);
}

//grava a data num ficheiro
void Data::gravar(ostream &fout) const
{
	fout << dia << endl;
	fout << mes << endl;
	fout << ano << endl;
}

//le a data de um ficheiro
void Data::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	dia = atoi(linha.c_str());
	getline(fin, linha);
	mes = atoi(linha.c_str());
	getline(fin, linha);
	ano = atoi(linha.c_str());
}

//afeta a data com a nova data
Data & Data::operator =(const Data &d)
{
	dia = d.dia;
	mes = d.mes;
	ano = d.ano;
	return *this;
}

//retorna true se duas datas são iguais
bool Data::operator ==(const Data &d) const
{
	return (dia == d.dia && mes == d.mes && ano == d.ano);
}

//retorna true se a data é menor à indicada
bool Data::operator <(const Data &d) const
{
	return ano < d.ano
			|| ((ano == d.ano && mes < d.mes) || (mes == d.mes && dia < d.dia));
}

//retorna true se a data é menor ou igual à indicada
bool Data::operator <=(const Data &d) const
{
	return operator <(d) || operator ==(d);
}

//retorna true se a data é maior à indicada
bool Data::operator >(const Data &d) const
{
	return !operator <=(d);
}

//retorna true se a data é maior ou igual à indicada
bool Data::operator >=(const Data &d) const
{
	return !operator <(d);
}

//retorna true se o ano é bissexto
bool Data::anoBissexto() const
{
	return verificarAnoBissexto(ano);
}

//retorna o número de dias do ano
int Data::numDiasMes() const
{
	return determinarnumDiasMes(mes, ano);
}

//retorna o número de dias do ano
int Data::numDiasAno() const
{
	return 365 + anoBissexto();
}

//verifica se o ano indicado é bissexto
bool Data::verificarAnoBissexto(int a)
{
	return (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0));
}

//retorna o número de dias do mês e ano indicados
int Data::determinarnumDiasMes(int m, int a)
{
	return diasDoMes[m - 1] + (m == 2 && verificarAnoBissexto(a));
}

//retorna true se os três argumentos constituem uma data
bool Data::validar(int d, int m, int a)
{
	return (d >= 1 && d <= determinarnumDiasMes(m, a)) && (m >= 1 && m <= 12)
			&& (a >= 1901);
}
