/*
 * Reuniao.cpp
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Cliente.h"
#include "Funcionario.h"
#include "Reuniao.h"

//construtor sem parâmetros
Reuniao::Reuniao() :
		tema(""), numParticipantes(0), data(), horaInicio(), horaFim(), sala(), tipoResponsavel(
				Func), responsavel(), situacao(Marcada)
{
}

//construtor elementar
Reuniao::Reuniao(string t, int np, const Data&d, const Hora &hi, const Hora &hf,
		const Sala &s, Reuniao::TipoResponsavel tr, const Pessoa &p) :
		tema(t), numParticipantes(np), data(d), horaInicio(hi), horaFim(hf), sala(
				s), tipoResponsavel(Func), responsavel(p), situacao(Marcada)
{
}

//construtor por cópia
Reuniao::Reuniao(const Reuniao &r) :
		tema(r.tema), numParticipantes(r.numParticipantes), data(r.data), horaInicio(
				r.horaInicio), horaFim(r.horaFim), sala(r.sala), tipoResponsavel(
				r.tipoResponsavel), responsavel(r.responsavel), situacao(
				r.situacao)
{
}

//destrutor
Reuniao::~Reuniao()
{
}

//retorna o tema
string Reuniao::getTema() const
{
	return tema;
}

//retorna o número de participantes
int Reuniao::getNumParticipantes() const
{
	return numParticipantes;
}

//retorna uma referência constante para a data
const Data & Reuniao::getData() const
{
	return data;
}

//retorna uma referência constante para a hora de início
const Hora & Reuniao::getHoraInicio() const
{
	return horaInicio;
}

//retorna uma referência constante para a hora de fim
const Hora & Reuniao::getHoraFim() const
{
	return horaFim;
}

//retorna uma referência constante para a sala
const Sala & Reuniao::getSala() const
{
	return sala;
}

//retorna o tipo de responsável
Reuniao::TipoResponsavel Reuniao::getTipoResponsavel() const
{
	return tipoResponsavel;
}

//retorna uma referência constante para o responsável
const Pessoa & Reuniao::getResponsavel() const
{
	return responsavel;
}

//retorna a situação
Reuniao::TipoSituacao Reuniao::getSituacao() const
{
	return situacao;
}

//modifica o tema
void Reuniao::setTema(string t)
{
	tema = t;
}

//modifica o número de participantes
void Reuniao::setNumParticipantes(int np)
{
	numParticipantes = np;
}

//modifica a data
void Reuniao::setData(const Data &d)
{
	data = d;
}

//modifica a hora de início
void Reuniao::setHoraInicio(const Hora &hi)
{
	horaInicio = hi;
}

//modifica a hora de fim
void Reuniao::setHoraFim(const Hora &hf)
{
	horaFim = hf;
}

//modifica a sala
void Reuniao::setSala(const Sala &s)
{
	sala = s;
}

//modifica o responsável
void Reuniao::setTipoResponsavel(Reuniao::TipoResponsavel tr)
{
	tipoResponsavel = tr;
}

//modifica o responsável
void Reuniao::setResponsavel(const Pessoa &p)
{
	responsavel = p;
}

//modifica a situação
void Reuniao::setSituacao(Reuniao::TipoSituacao s)
{
	situacao = s;
}

//escreve os atributos
void Reuniao::escrever() const
{
	cout << "Tema da reunião: " << tema << endl;
	cout << "Número de participantes: " << numParticipantes << endl;
	cout << "Data: ";
	data.escrever();
	cout << "Ínicio: ";
	horaInicio.escrever();
	cout << "Término: ";
	horaFim.escrever();
	sala.escrever();
	cout << "Situacao: ";
	if (situacao == Reuniao::Marcada)
		cout << "Marcada" << endl;
	if (situacao == Reuniao::Realizada)
		cout << "Realizada" << endl;
	if (situacao == Reuniao::Cancelada)
		cout << "Cancelada" << endl;
	cout << "Responsável: ";
	if (tipoResponsavel == Reuniao::Func)
		cout << "Funcionário" << endl;
	if (tipoResponsavel == Reuniao::Clie)
		cout << "Cliente" << endl;
	responsavel.escrever();
}

//lê os atributos - excepto sala, responsável e situação
void Reuniao::ler()
{
	string linha = "";
	cout << "Tema: ";
	getline(cin, linha);
	tema = linha;
	cout << "Número de participantes: ";
	getline(cin, linha);
	numParticipantes = atoi(linha.c_str());
	data.ler();
	cout << "Início" << endl;
	horaInicio.ler();
	cout << "Término" << endl;
	horaFim.ler();
}

//grava para um ficheiro
void Reuniao::gravar(ostream &fout) const
{
	fout << tema << endl;
	fout << numParticipantes << endl;
	data.gravar(fout);
	horaInicio.gravar(fout);
	horaFim.gravar(fout);
	sala.gravar(fout);
	fout << static_cast<int>(situacao) << endl;
	fout << static_cast<int>(tipoResponsavel) << endl;
	responsavel.gravar(fout);
}

//le de um ficheiro
void Reuniao::abrir(istream &fin)
{
	string linha = "";
	getline(fin, linha);
	tema = linha;
	getline(fin, linha);
	numParticipantes = atoi(linha.c_str());
	data.abrir(fin);
	horaInicio.abrir(fin);
	horaFim.abrir(fin);
	sala.abrir(fin);
	getline(fin, linha);
	int st = atoi(linha.c_str());
	if (st == 0)
		situacao = Reuniao::Marcada;
	if (st == 1)
			situacao = Reuniao::Realizada;
	if (st == 0)
			situacao = Reuniao::Cancelada;
	getline(fin, linha);
	int tr = atoi(linha.c_str());
	if (tr == 0)
		tipoResponsavel = Reuniao::Func;
	if (tr == 1)
		tipoResponsavel = Reuniao::Clie;
	responsavel.abrir(fin);
}

//afeta com a reuniao indicada
Reuniao & Reuniao::operator =(const Reuniao &r)
{
	tema = r.tema;
	numParticipantes = r.numParticipantes;
	data = r.data;
	horaInicio = r.horaInicio;
	horaFim = r.horaFim;
	sala = r.sala;
	tipoResponsavel = r.tipoResponsavel;
	responsavel = r.responsavel;
	situacao = r.situacao;
	return (*this);
}

//retorna true se tem os mesmos atributos da reuniao indicada
bool Reuniao::operator ==(const Reuniao &r) const
{
	return (tema == r.tema && numParticipantes == r.numParticipantes
			&& data == r.data && horaInicio == r.horaInicio
			&& horaFim == r.horaFim && sala == r.sala
			&& tipoResponsavel == r.tipoResponsavel
			&& responsavel == r.responsavel && situacao == r.situacao);
}
