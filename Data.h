/*
 * Data.h
 *
 *  Created on: 22/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef DATA_H_
#define DATA_H_

#include <fstream>

using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;

	static const int diasDoMes[12];

public:
	Data();
	Data(int, int, int);
	Data(const Data &);
	virtual ~Data();

	virtual int getDia() const;
	virtual int getMes() const;
	virtual int getAno() const;

	virtual void setDia(int);
	virtual void setMes(int);
	virtual void setAno(int);

	virtual void escrever() const;
	virtual void ler();
	virtual void gravar(ostream &) const;
	virtual void abrir(istream &);

	virtual Data & operator =(const Data &);
	virtual bool operator ==(const Data &) const;
	virtual bool operator <(const Data &) const;
	virtual bool operator <=(const Data &) const;
	virtual bool operator >(const Data &) const;
	virtual bool operator >=(const Data &) const;

	virtual bool anoBissexto() const;
	virtual int numDiasMes() const;
	virtual int numDiasAno() const;

	static bool verificarAnoBissexto(int);
	static int determinarnumDiasMes(int, int);
	static bool validar(int, int, int);
};

#endif /* DATA_H_ */
