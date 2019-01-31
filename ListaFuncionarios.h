/*
 * ListaFuncionarios.h
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef LISTAFUNCIONARIOS_H_
#define LISTAFUNCIONARIOS_H_

#include <vector>
#include <fstream>
#include "Funcionario.h"

class ListaFuncionarios
{
private:
	vector<Funcionario> lista;

public:
	ListaFuncionarios();
	virtual ~ListaFuncionarios();

	virtual void adicionar(const Funcionario &);
	virtual void remover(int);

	virtual Funcionario & operator[](int);
	virtual int getNumero() const;

	virtual void escrever() const;
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual bool contem(const Funcionario &) const;
};

#endif /* LISTAFUNCIONARIOS_H_ */
