#include "CListaHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


CListaFornecedores::CListaFornecedores(void) {
    inicio = NULL;

}

//---------------------------------------------------------------------------------------------------------------------------------
CListaFornecedores::~CListaFornecedores(void)
{
    CNoFornecedores *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}

//---------------------------------------------------------------------------------------------------------------------------------
void CListaFornecedores:: inserirFornecedor (int codigofornecedor,string nome, string morada, string telefone)
{
	CNoFornecedores *novo = new CNoFornecedores;
        CNoFornecedores *atual = inicio;

    novo->codigoFornecedor=codigofornecedor;
    novo->nome=nome;
    novo->morada=morada;
    novo->telefone=telefone;
    novo->seguinte=NULL;

    if(inicio==NULL){
        inicio=novo;
    }
    else
    {
        atual=inicio;
            while(atual->seguinte!=NULL)
            atual=atual->seguinte;
        atual->seguinte=novo;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------
void CListaFornecedores:: escreveListaFornecedor(void) const
{
    CNoFornecedores *atual = inicio;

    system("cls");

      if(inicio==NULL)
          cout << "Lista Vazia..." << endl;
      else{
          while(atual!=NULL){
              cout << left<<"Nome do Fornecedor: " << atual->nome << "; ";
              cout << left<<setw(30)<<"Morada: " << atual->morada << "; ";
              cout << right<<setw(20)<<"Contacto: " << atual->telefone ;
              
              atual=atual->seguinte;
              cout << endl;
          }
          cout << "Fim da Lista" << endl;
      }
}

//----------------------------------------------------------------------------------------------------------------------------------
void CListaFornecedores :: apagaFornecedor(int codigofornecedor)
{
    CNoFornecedores *atual = inicio;
    CNoFornecedores *anterior;
    
    if(inicio==NULL)
	return;
	
	else 
	{
		anterior=NULL;
		while(atual!=NULL)
		{
                        if(atual->codigoFornecedor == codigofornecedor )
                        {
				if(anterior==NULL)
                                inicio=atual->seguinte;
				else
				anterior->seguinte=atual->seguinte;
				delete(atual);
				return;
			}
			anterior=atual;
			atual=atual->seguinte;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------------------
void CListaFornecedores::lerFicheiro(){

        ifstream fornecedores;
        fornecedores.open("ListaFornecedores.txt");

        if(!fornecedores.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigoFornecedor1;
        string nome;
        string morada;
        string telefone;

        while(fornecedores.get() != EOF){
                int codigoFornecedor2;

                getline(fornecedores, codigoFornecedor1, ';');
                getline(fornecedores,nome,';');
                getline(fornecedores, morada, ';');
                getline(fornecedores, telefone, '\n');

                codigoFornecedor2 = stoi(codigoFornecedor1);

                inserirFornecedor(codigoFornecedor2,nome,morada, telefone);
        }
        fornecedores.close();
}

//--------------------------------------------------------------------------------------------------------------------------------
 bool CListaFornecedores :: comparaFornecedor(int codigofornecedor)
 {
	 CNoFornecedores * atual=inicio;
	 
	 if(inicio==NULL)
	 return false;
	 
	 while(atual != NULL)
	 {
		 if(atual->codigoFornecedor == codigofornecedor)
		 return true;
		 atual=atual->seguinte;
	 }
	 return false;
 }
