/*
 * Setor.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef SETOR_H_
#define SETOR_H_

#include <string>
#include <fstream>

using namespace std;

class Setor
{
private:
	string nome;

public:
	Setor();
	explicit Setor(string);
	Setor(const Setor &);
	virtual ~Setor();

	virtual string getNome() const;

	virtual void setNome(string);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Setor & operator =(const Setor &);
	virtual bool operator ==(const Setor &) const;
};

#endif /* SETOR_H_ */
