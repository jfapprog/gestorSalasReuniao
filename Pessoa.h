/*
 * Pessoa.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef PESSOA_H_
#define PESSOA_H_

#include <string>
#include <fstream>

using namespace std;

class Pessoa
{
private:
	string nome;
	int telefone;

public:
	Pessoa();
	Pessoa(string, int);
	Pessoa(const Pessoa &);
	virtual ~Pessoa();

	virtual string getNome() const;
	virtual int getTelefone() const;

	virtual void setNome(string);
	virtual void setTelefone(int);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Pessoa & operator =(const Pessoa &);
	virtual bool operator ==(const Pessoa &) const;
};

#endif /* PESSOA_H_ */
