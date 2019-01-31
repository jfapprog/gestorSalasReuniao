/*
 * Cliente.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <fstream>
#include "Empresa.h"
#include "Pessoa.h"

using namespace std;

class Cliente: public Pessoa
{
private:
	Empresa empresa;

public:
	Cliente();
	Cliente(const Pessoa &, const Empresa &);
	Cliente(const Cliente &);
	virtual ~Cliente();

	virtual const Empresa & getEmpresa() const;

	virtual void setEmpresa(const Empresa &);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Cliente & operator =(const Cliente &);
	virtual bool operator ==(const Cliente &) const;
};

#endif /* CLIENTE_H_ */
