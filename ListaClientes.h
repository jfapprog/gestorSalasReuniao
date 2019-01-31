/*
 * ListaClientes.h
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef LISTACLIENTES_H_
#define LISTACLIENTES_H_

#include <fstream>
#include <vector>
#include "Cliente.h"

class ListaClientes
{
private:
	vector<Cliente> lista;

public:
	ListaClientes();
	virtual ~ListaClientes();

	virtual void adicionar(const Cliente &);
	virtual void remover(int);

	virtual Cliente & operator[](int);
	virtual int getNumero() const;

	virtual void escrever() const;
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual bool contem(const Cliente &) const;
};

#endif /* LISTACLIENTES_H_ */
