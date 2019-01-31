/*
 * Menu.h
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#ifndef MENU_H_
#define MENU_H_

#include "ListaSalas.h"
#include "ListaFuncionarios.h"
#include "ListaClientes.h"
#include "ListaReunioes.h"

class Menu
{
private:
	ListaSalas salas;
	ListaFuncionarios funcionarios;
	ListaClientes clientes;
	ListaReunioes reunioes;
	int opcao;

	virtual void abrirFicheiros();
	virtual void gravarFicheiros();

public:
	Menu();
	virtual ~Menu();

	int getOpcao() const;

	void apresentarMenu();

	void apresentarSubMenu1();
	void apresentarSubMenu11();
	void apresentarSubMenu12();
	void apresentarSubMenu13();
	void apresentarSubMenu15();

	void apresentarSubMenu2();
	void apresentarSubMenu2X(int);

	void listarReuniao(int) const;
	void marcarReuniao(int);
	void modificarReuniao(int);
	void removerReuniao();
	void pesquisarSalasLivres(int);

	void listar(int) const;
	void adicionar(int);
	void modificar(int);
};

#endif /* MENU_H_ */
