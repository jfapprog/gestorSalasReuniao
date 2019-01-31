/*
 * Sala.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef SALA_H_
#define SALA_H_

#include <string>
#include <fstream>

using namespace std;

class Sala
{
private:
	string id;
	int capacidade;

public:
	Sala();
	Sala(string, int);
	Sala(const Sala &);
	virtual ~Sala();

	virtual string getId() const;
	virtual int getCapacidade() const;

	virtual void setId(string);
	virtual void setCapacidade(int);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Sala & operator =(const Sala &);
	virtual bool operator ==(const Sala &) const;
};

#endif /* SALA_H_ */
