/*
 * Hora.h
 *
 *  Created on: 23/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef HORA_H_
#define HORA_H_

#include <fstream>

using namespace std;

class Hora
{
private:
	int horas;
	int minutos;

public:
	Hora();
	Hora(int, int);
	Hora(const Hora &);
	virtual ~Hora();

	virtual int getHoras() const;
	virtual int getMinutos() const;

	virtual void setHoras(int);
	virtual void setMinutos(int);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Hora & operator =(const Hora &);
	virtual bool operator ==(const Hora &) const;
	virtual bool operator <(const Hora &) const;
	virtual bool operator <=(const Hora &) const;
	virtual bool operator >(const Hora &) const;
	virtual bool operator >=(const Hora &) const;

	static bool validar(int, int);
};

#endif /* HORA_H_ */
