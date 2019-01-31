/*
 * ListaSalas.h
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef LISTASALAS_H_
#define LISTASALAS_H_

#include <vector>
#include <fstream>
#include "Sala.h"

class ListaSalas
{
private:
	vector<Sala> lista;

public:
	ListaSalas();
	virtual ~ListaSalas();

	virtual void adicionar(const Sala &);
	virtual void remover(int);

	virtual Sala & operator[](int);
	virtual int getNumero() const;

	virtual void escrever() const;
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual int contem(const Sala &) const;
};

#endif /* LISTASALAS_H_ */
