/*
 * Menu.cpp
 *
 *  Created on: 24/05/2015
 *      Author: José Félix Póvoa
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "Menu.h"

//construtor sem parâmetros
Menu::Menu() :
		salas(), funcionarios(), clientes(), reunioes(), opcao(0)
{
	abrirFicheiros();
}

//destrutor
Menu::~Menu()
{
	gravarFicheiros();
}

//inicializa as listas
void Menu::abrirFicheiros()
{
	ifstream finSalas("salas.txt");
	ifstream finFuncionarios("funcionarios.txt");
	ifstream finClientes("clientes.txt");
	ifstream finReunioes("reunioes.txt");
	if (!finSalas || !finFuncionarios || !finClientes || !finReunioes)
	{
		cout << "Não foi possível inicializar listas" << endl;
		return;
	}
	salas.abrir(finSalas);
	finSalas.close();
	funcionarios.abrir(finFuncionarios);
	finFuncionarios.close();
	clientes.abrir(finClientes);
	finClientes.close();
	reunioes.abrir(finReunioes);
	finReunioes.close();
}

//grava as listas num ficheiro
void Menu::gravarFicheiros()
{
	ofstream foutSalas("salas.txt");
	ofstream foutFuncionarios("funcionarios.txt");
	ofstream foutClientes("clientes.txt");
	ofstream foutReunioes("reunioes.txt");
	if (!foutSalas || !foutFuncionarios || !foutClientes || !foutReunioes)
	{
		cout << "Não foi possível gravar listas" << endl;
		return;
	}
	salas.gravar(foutSalas);
	foutSalas.close();
	funcionarios.gravar(foutFuncionarios);
	foutFuncionarios.close();
	clientes.gravar(foutClientes);
	foutClientes.close();
	reunioes.gravar(foutReunioes);
	foutReunioes.close();
}

//retorna a opção
int Menu::getOpcao() const
{
	return opcao;
}

//apresenta o menu e lê a opcão escolhida
void Menu::apresentarMenu()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Menu";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Gerir reuniões" << endl;
	cout << "2 - Gerir listas" << endl;
	cout << "3 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 1 e lê a opção escolhida
void Menu::apresentarSubMenu1()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Submenu - Gerir reuniões";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Listar" << endl;
	cout << "2 - Marcar" << endl;
	cout << "3 - Modificar" << endl;
	cout << "4 - Remover" << endl;
	cout << "5 - Pesquisar salas livres" << endl;
	cout << "6 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 1.1 e lê a opção escolhida
void Menu::apresentarSubMenu11()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Submenu - Listar";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - De hoje" << endl;
	cout << "2 - De outro dia" << endl;
	cout << "3 - Entre datas" << endl;
	cout << "4 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 1.2 e lê a opção escolhida
void Menu::apresentarSubMenu12()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Submenu - Marcar";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Para funcionário" << endl;
	cout << "2 - Para cliente" << endl;
	cout << "3 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 1.3 e lê a opção escolhida
void Menu::apresentarSubMenu13()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Submenu - Modificar";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Situação" << endl;
	cout << "2 - Sala" << endl;
	cout << "3 - Data" << endl;
	cout << "4 - Hora" << endl;
	cout << "5 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 1.5 e lê a opção escolhida
void Menu::apresentarSubMenu15()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Submenu - Pesquisar salas livres";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Para data" << endl;
	cout << "2 - Para data e horário" << endl;
	cout << "3 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 2 e lê a opção escolhida
void Menu::apresentarSubMenu2()
{
	cout << "\n--------------------------------------" << endl;
	cout << "Submenu - Gerir listas";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Salas" << endl;
	cout << "2 - Funcionários" << endl;
	cout << "3 - Clientes" << endl;
	cout << "4 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//apresenta o submenu 2.X e lê a opção escolhida
void Menu::apresentarSubMenu2X(int n)
{
	cout << "\n--------------------------------------" << endl;
	if (n == 1)
		cout << "Submenu - Salas";
	if (n == 2)
		cout << "Submenu - Funcionários";
	if (n == 3)
		cout << "Submenu - Clientes";
	cout << "\n--------------------------------------" << endl;
	cout << "1 - Listar" << endl;
	cout << "2 - Adicionar" << endl;
	cout << "3 - Modificar" << endl;
	cout << "4 - Sair" << endl;
	cout << "\nOpcao: ";
	string linha = "";
	getline(cin, linha);
	opcao = atoi(linha.c_str());
}

//lista reuniao
void Menu::listarReuniao(int n) const
{
	cout << "\n--------------------------------------" << endl;
	Data di;
	Data df;
	if (n == 2)
	{
		di.ler();
		df = di;
	}
	if (n == 3)
	{
		cout << "Data inicial: " << endl;
		di.ler();
		cout << "Data final: " << endl;
		df.ler();
	}
	cout << "A lista tem " << reunioes.getNumero(di, df) << " reuniões";
	cout << "\n--------------------------------------" << endl;
	reunioes.escrever(di, df);
}

//adiciona uma reuniao
void Menu::marcarReuniao(int n)
{
	Pessoa p;
	Reuniao::TipoResponsavel tr = Reuniao::Func;
	bool valido = 0;
	string linha = "";
	cout << "\n--------------------------------------" << endl;
	cout << "Marcar reunião" << endl;
	//atribuir responsável
	cout << "Índice do responsável: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	//responsável é funcionário
	if (n == 1)
	{
		int indPoss = funcionarios.getNumero();
		cout << "--------------------------------------" << endl;
		if (indice < 1 || indice > indPoss)
			cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
					<< ")" << endl;
		else
		{
			p = funcionarios[indice - 1];
			valido = 1;
		}
	}
	//responsável é cliente
	if (n == 2)
	{
		tr = Reuniao::Clie;
		int indPoss = clientes.getNumero();
		cout << "--------------------------------------" << endl;
		if (indice < 1 || indice > indPoss)
			cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
					<< ")" << endl;
		else
		{
			p = clientes[indice - 1];
			valido = 1;
		}
	}
	//se ponteiro não é nulo é porque índice existe
	if (valido)
	{
		Reuniao r;
		//ler tema, número de participantes, data e horas de início e fim
		r.ler();
		//atribuir sala;
		cout << "Índice da sala: ";
		getline(cin, linha);
		int indice = atoi(linha.c_str());
		int indPoss = salas.getNumero();
		if (indice < 1 || indice > indPoss)
			cout << "Erro no índice indicado (valores possives: 1 - " << indPoss
					<< ")" << endl;
		else
		{
			r.setSala(salas[indice - 1]);
			r.setTipoResponsavel(tr);
			r.setResponsavel(p);
			if (reunioes.contem(r))
				cout << "A lista já contém a reunião" << endl;
			else if (reunioes.coincide(r))
				cout << "A sala está ocupada nesse horário" << endl;
			else
			{
				reunioes.adicionar(r);
				cout << "Reunião adicionada" << endl;
			}
		}
	}
}

//modifica a reunião
void Menu::modificarReuniao(int n)
{
	cout << "\n--------------------------------------" << endl;
	cout << "Modificar reunião" << endl;
	string linha = "";
	cout << "Índice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	int indPoss = reunioes.getNumero();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no indice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else if (reunioes[indice - 1].getSituacao() == Reuniao::Cancelada
			|| reunioes[indice - 1].getSituacao() == Reuniao::Realizada)
		cout << "Reunião cancelada ou já realizada " << endl;
	else
	{
		//situação
		if (n == 1)
		{
			cout << "Situação (c - cancelada, r - realizada): ";
			getline(cin, linha);
			cout << "--------------------------------------" << endl;
			if (tolower(linha[0]) == 'c')
				reunioes[indice - 1].setSituacao(Reuniao::Cancelada);
			if (tolower(linha[0]) == 'r')
				reunioes[indice - 1].setSituacao(Reuniao::Realizada);
			cout << "Situação modificada" << endl;
		}
		//sala
		if (n == 2)
		{
			cout << "Índice da nova sala: ";
			getline(cin, linha);
			int ind = atoi(linha.c_str());
			int indPoss = salas.getNumero();
			cout << "--------------------------------------" << endl;
			if (ind < 1 || ind > indPoss)
				cout << "Erro no índice indicado (valores possives: 1 - "
						<< indPoss << ")" << endl;
			else
			{
				Reuniao r = reunioes[indice - 1];
				r.setSala(salas[ind - 1]);
				if (reunioes.contem(r))
					cout << "A lista já contém a reunião" << endl;
				else if (reunioes.coincide(r))
					cout << "A sala está ocupada nesse horário" << endl;
				else
				{
					reunioes[indice - 1].setSala(salas[ind - 1]);
					cout << "Sala modificada" << endl;
				}
			}
		}
		//data
		if (n == 3)
		{
			Data nova;
			nova.ler();
			cout << "--------------------------------------" << endl;
			Reuniao r = reunioes[indice - 1];
			r.setData(nova);
			if (reunioes.contem(r))
				cout << "A lista já contém a reunião" << endl;
			else if (reunioes.coincide(r))
				cout << "A sala está ocupada nesse horário" << endl;
			else
			{
				reunioes[indice - 1].setData(nova);
				cout << "Data modificada" << endl;
			}
		}
		//hora
		if (n == 4)
		{
			Hora novaInicio, novaFim;
			cout << "Início" << endl;
			novaInicio.ler();
			cout << "Término" << endl;
			novaFim.ler();
			cout << "--------------------------------------" << endl;
			Reuniao r = reunioes[indice - 1];
			r.setHoraInicio(novaInicio);
			r.setHoraFim(novaFim);
			reunioes[indice - 1].setSituacao(Reuniao::Cancelada);
			if (reunioes.contem(r))
			{
				reunioes[indice - 1].setSituacao(Reuniao::Marcada);
				cout << "A lista já contém a reunião" << endl;
			}
			else if (reunioes.coincide(r))
			{
				reunioes[indice - 1].setSituacao(Reuniao::Marcada);
				cout << "A sala está ocupada nesse horário" << endl;
			}
			else
			{
				reunioes[indice - 1].setSituacao(Reuniao::Marcada);
				reunioes[indice - 1].setHoraInicio(novaInicio);
				reunioes[indice - 1].setHoraFim(novaFim);
				cout << "Hora modificada" << endl;
			}
		}
	}
}

//Remove uma reunião
void Menu::removerReuniao()
{

	cout << "\n--------------------------------------" << endl;
	cout << "Remover reuniao" << endl;
	string linha = "";
	cout << "Índice: ";
	getline(cin, linha);
	int indice = atoi(linha.c_str());
	cout << "--------------------------------------" << endl;
	int indPoss = reunioes.getNumero();
	if (indice < 1 || indice > indPoss)
		cout << "Erro no índice indicado (valores possives: 1 - " << indPoss
				<< ")" << endl;
	else
	{
		reunioes.remover(indice - 1);
		cout << "Reunião removida" << endl;
	}

}

//Pesquisa salas livres
void Menu::pesquisarSalasLivres(int n)
{
	//Para data
	if (n == 1)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Salas livres durante todo o dia" << endl;
		Data d;
		d.ler();
		cout << "--------------------------------------" << endl;
		for (int i = 0; i < salas.getNumero(); i++)
		{
			if (!reunioes.ocupada(salas[i], d))
				salas[i].escrever();
		}
	}
	//Para data e horário
	if (n == 2)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Salas livres durante um intervalo de tempo" << endl;
		Data d;
		d.ler();
		Hora inicio, fim;
		cout << "Início" << endl;
		inicio.ler();
		cout << "Término" << endl;
		fim.ler();
		cout << "--------------------------------------" << endl;
		for (int i = 0; i < salas.getNumero(); i++)
		{
			if (!reunioes.ocupada(salas[i], d, inicio, fim))
				salas[i].escrever();
		}
	}
}

//lista salas, funcionários ou clientes
void Menu::listar(int n) const
{
	//sala
	if (n == 1)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "A lista tem " << salas.getNumero() << " salas";
		cout << "\n--------------------------------------" << endl;
		salas.escrever();
	}
	//funcionário
	if (n == 2)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "A lista tem " << funcionarios.getNumero() << " funcionários";
		cout << "\n--------------------------------------" << endl;
		funcionarios.escrever();
	}
	//cliente
	if (n == 3)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "A lista tem " << clientes.getNumero() << " clientes";
		cout << "\n--------------------------------------" << endl;
		clientes.escrever();
	}
}

//adiciona sala, funcionário ou cliente
void Menu::adicionar(int n)
{
	//sala
	if (n == 1)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Adicionar sala" << endl;
		Sala s;
		s.ler();
		cout << "--------------------------------------" << endl;
		if (salas.contem(s))
			cout << "A lista já contém uma sala com esse ID" << endl;
		else
		{
			salas.adicionar(s);
			cout << "Sala adicionada à lista" << endl;
		}
	}
	//funcionário
	if (n == 2)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Adicionar funcionário" << endl;
		Funcionario f;
		f.ler();
		cout << "--------------------------------------" << endl;
		if (funcionarios.contem(f))
			cout << "A lista já contém o funcionário" << endl;
		else
		{
			funcionarios.adicionar(f);
			cout << "Funcionário adicionado à lista" << endl;
		}
	}
	//cliente
	if (n == 3)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Adicionar cliente" << endl;
		Cliente c;
		c.ler();
		cout << "--------------------------------------" << endl;
		if (clientes.contem(c))
			cout << "A lista já contém o cliente" << endl;
		else
		{
			clientes.adicionar(c);
			cout << "Cliente adicionado à lista" << endl;
		}
	}
}

//modifica sala, funcionário ou cliente
void Menu::modificar(int n)
{
	//sala
	if (n == 1)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Modificar sala" << endl;
		string linha = "";
		cout << "Índice: ";
		getline(cin, linha);
		int indice = atoi(linha.c_str());
		int indPoss = salas.getNumero();
		if (indice < 1 || indice > indPoss)
			cout << "Erro no índice indicado (valores possives: 1 - " << indPoss
					<< ")" << endl;
		else
		{
			Sala s;
			s.ler();
			cout << "--------------------------------------" << endl;
			if (salas.contem(s))
				cout << "A lista já contém uma sala com esse ID" << endl;
			else
			{
				salas[indice - 1] = s;
				cout << "Sala modificada" << endl;
			}
		}
	}
	//funcionário
	if (n == 2)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Modificar funcionário" << endl;
		string linha = "";
		cout << "Índice: ";
		getline(cin, linha);
		int indice = atoi(linha.c_str());
		int indPoss = funcionarios.getNumero();
		if (indice < 1 || indice > indPoss)
			cout << "Erro no índice indicado (valores possives: 1 - " << indPoss
					<< ")" << endl;
		else
		{
			Funcionario f;
			f.ler();
			cout << "--------------------------------------" << endl;
			if (funcionarios.contem(f))
				cout << "A lista já contém o funcionário" << endl;
			else
			{
				funcionarios[indice - 1] = f;
				cout << "Funcionário modificado" << endl;
			}
		}
	}
	//cliente
	if (n == 3)
	{
		cout << "\n--------------------------------------" << endl;
		cout << "Modificar cliente" << endl;
		string linha = "";
		cout << "Índice: ";
		getline(cin, linha);
		int indice = atoi(linha.c_str());
		int indPoss = clientes.getNumero();
		if (indice < 1 || indice > indPoss)
			cout << "Erro no índice indicado (valores possives: 1 - " << indPoss
					<< ")" << endl;
		else
		{
			Cliente c;
			c.ler();
			cout << "--------------------------------------" << endl;
			if (clientes.contem(c))
				cout << "A lista já contém o cliente" << endl;
			else
			{
				clientes[indice - 1] = c;
				cout << "Cliente modificado" << endl;
			}
		}
	}
}
