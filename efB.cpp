/*
 * efB.cpp
 *
 *  Created on: 22/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include "Menu.h"

int main()
{
	cout << "              Gestão de Salas";
	Menu m;
	int opcaoNivel1 = 0, opcaoNivel2 = 0, opcaoNivel3 = 0;
	do
	{
		m.apresentarMenu();
		opcaoNivel1 = m.getOpcao();
		//gerir reuniões
		if (opcaoNivel1 == 1)
		{
			do
			{
				m.apresentarSubMenu1();
				opcaoNivel2 = m.getOpcao();
				//listar reuniões
				if (opcaoNivel2 == 1)
				{
					do
					{
						m.apresentarSubMenu11();
						opcaoNivel3 = m.getOpcao();
						if (opcaoNivel3 == 1)
							m.listarReuniao(1);
						if (opcaoNivel3 == 2)
							m.listarReuniao(2);
						if (opcaoNivel3 == 3)
							m.listarReuniao(3);
						if (opcaoNivel3 == 4)
							break;
						if (opcaoNivel3 < 1 || opcaoNivel3 > 4)
							cout << "Erro na opcao (valores possiveis: 1 - 4)"
									<< endl;
					} while (true);
				}
				//marcar reunião
				if (opcaoNivel2 == 2)
				{
					do
					{
						m.apresentarSubMenu12();
						opcaoNivel3 = m.getOpcao();
						if (opcaoNivel3 == 1)
							m.marcarReuniao(1);
						if (opcaoNivel3 == 2)
							m.marcarReuniao(2);
						if (opcaoNivel3 == 3)
							break;
						if (opcaoNivel3 < 1 || opcaoNivel3 > 3)
							cout << "Erro na opcao (valores possiveis: 1 - 3)"
									<< endl;
					} while (true);
				}
				//modificar reunião
				if (opcaoNivel2 == 3)
				{
					do
					{
						m.apresentarSubMenu13();
						opcaoNivel3 = m.getOpcao();
						if (opcaoNivel3 == 1)
							m.modificarReuniao(1);
						if (opcaoNivel3 == 2)
							m.modificarReuniao(2);
						if (opcaoNivel3 == 3)
							m.modificarReuniao(3);
						if (opcaoNivel3 == 4)
							m.modificarReuniao(4);
						if (opcaoNivel3 == 5)
							break;
						if (opcaoNivel3 < 1 || opcaoNivel3 > 5)
							cout << "Erro na opcao (valores possiveis: 1 - 5)"
									<< endl;
					} while (true);
				}
				//remover reunião
				if (opcaoNivel2 == 4)
					m.removerReuniao();
				//pesquisar salas livres
				if (opcaoNivel2 == 5)
				{
					do
					{
						m.apresentarSubMenu15();
						opcaoNivel3 = m.getOpcao();
						if (opcaoNivel3 == 1)
							m.pesquisarSalasLivres(1);
						if (opcaoNivel3 == 2)
							m.pesquisarSalasLivres(2);
						if (opcaoNivel3 == 3)
							break;
						if (opcaoNivel3 < 1 || opcaoNivel3 > 3)
							cout << "Erro na opcao (valores possiveis: 1 - 3)"
									<< endl;
					} while (true);
				}
				if (opcaoNivel2 == 6)
					break;
				if (opcaoNivel2 < 1 || opcaoNivel2 > 6)
					cout << "Erro na opcao (valores possiveis: 1 - 6)" << endl;
			} while (true);
		}
		//gerir listas
		if (opcaoNivel1 == 2)
		{
			do
			{
				m.apresentarSubMenu2();
				opcaoNivel2 = m.getOpcao();
				if (opcaoNivel2 >= 1 && opcaoNivel2 <= 3)
				{
					do
					{
						m.apresentarSubMenu2X(opcaoNivel2);
						opcaoNivel3 = m.getOpcao();
						if (opcaoNivel3 == 1)
							m.listar(opcaoNivel2);
						if (opcaoNivel3 == 2)
							m.adicionar(opcaoNivel2);
						if (opcaoNivel3 == 3)
							m.modificar(opcaoNivel2);
						if (opcaoNivel3 == 4)
							break;
						if (opcaoNivel3 < 1 || opcaoNivel3 > 4)
							cout << "Erro na opcao (valores possiveis: 1 - 4)"
									<< endl;
					} while (true);
				}
				if (opcaoNivel2 == 4)
					break;
				if (opcaoNivel2 < 1 || opcaoNivel2 > 4)
					cout << "Erro na opcao (valores possiveis: 1 - 4)" << endl;
			} while (true);
		}
		if (opcaoNivel1 == 3)
			break;
		if (opcaoNivel1 < 1 || opcaoNivel1 > 3)
			cout << "Erro na opcao (valores possiveis: 1 - 3)" << endl;
	} while (true);
	cout << "--------------------------------------" << endl;
	cout << "              Gestão de Salas" << endl;
	return 0;
}

