/*
 * Funcionario.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <fstream>
#include "Setor.h"
#include "Pessoa.h"

using namespace std;

class Funcionario: public Pessoa
{
private:
	string cargo;
	Setor setor;

public:
	Funcionario();
	Funcionario(const Pessoa &, string, const Setor &);
	Funcionario(const Funcionario &);
	virtual ~Funcionario();

	virtual string getCargo() const;
	virtual const Setor & getSetor() const;

	virtual void setCargo(string);
	virtual void setSetor(const Setor &);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Funcionario & operator =(const Funcionario &);
	virtual bool operator ==(const Funcionario &) const;
};

#endif /* FUNCIONARIO_H_ */
