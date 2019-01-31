/*
 * ListaReunioes.h
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef LISTAREUNIOES_H_
#define LISTAREUNIOES_H_

#include <vector>
#include <fstream>
#include "Reuniao.h"

class ListaReunioes
{
	private:
	vector<Reuniao> lista;

public:
	ListaReunioes();
	virtual ~ListaReunioes();

	virtual void adicionar(const Reuniao &);
	virtual void remover(int);

	virtual Reuniao & operator[](int);
	virtual int getNumero() const;
	virtual int getNumero(const Data &, const Data &) const;

	virtual void escrever() const;
	virtual void escrever(const Data &, const Data &) const;
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual bool contem(const Reuniao &) const;
	virtual bool coincide(const Reuniao &) const;
	virtual bool ocupada(const Sala &, const Data &) const;
	virtual bool ocupada(const Sala &, const Data &, const Hora &, const Hora &) const;
};

#endif /* LISTAREUNIOES_H_ */
