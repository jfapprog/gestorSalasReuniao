/*
 * Reuniao.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef REUNIAO_H_
#define REUNIAO_H_

#include <string>
#include <fstream>
#include "Sala.h"
#include "Data.h"
#include "Hora.h"
#include "Pessoa.h"

using namespace std;

class Reuniao
{
public:
	enum TipoSituacao
	{
		Marcada, Realizada, Cancelada
	};
	enum TipoResponsavel
	{
		Func, Clie
	};
private:
	string tema;
	int numParticipantes;
	Data data;
	Hora horaInicio;
	Hora horaFim;
	Sala sala;
	TipoResponsavel tipoResponsavel;
	Pessoa responsavel;
	TipoSituacao situacao;

public:
	Reuniao();
	Reuniao(string, int, const Data &, const Hora &, const Hora &, const Sala &,
			TipoResponsavel, const Pessoa &);
	Reuniao(const Reuniao &);
	virtual ~Reuniao();

	virtual string getTema() const;
	virtual int getNumParticipantes() const;
	virtual const Data & getData() const;
	virtual const Hora & getHoraInicio() const;
	virtual const Hora & getHoraFim() const;
	virtual const Sala & getSala() const;
	virtual TipoResponsavel getTipoResponsavel() const;
	virtual const Pessoa & getResponsavel() const;
	virtual TipoSituacao getSituacao() const;

	virtual void setTema(string);
	virtual void setNumParticipantes(int);
	virtual void setData(const Data &);
	virtual void setHoraInicio(const Hora &);
	virtual void setHoraFim(const Hora &);
	virtual void setSala(const Sala &);
	virtual void setTipoResponsavel(TipoResponsavel);
	virtual void setResponsavel(const Pessoa &);
	virtual void setSituacao(TipoSituacao);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Reuniao & operator =(const Reuniao &);
	virtual bool operator ==(const Reuniao &) const;
};

#endif /* REUNIAO_H_ */
