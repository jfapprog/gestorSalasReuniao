/*
 * Empresa.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include <fstream>
#include <string>

using namespace std;

class Empresa
{
private:
	string nome;

public:
	Empresa();
	explicit Empresa(string);
	Empresa(const Empresa &);
	virtual ~Empresa();

	virtual string getNome() const;

	virtual void setNome(string);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Empresa & operator =(const Empresa &);
	virtual bool operator ==(const Empresa &) const;
};

#endif /* EMPRESA_H_ */
