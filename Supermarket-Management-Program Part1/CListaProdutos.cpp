#include "CListaHeader.h"
#include <iostream>
#include <string>

using namespace std;


CListaDeProdutos::CListaDeProdutos(void) {
    inicio = NULL;

}

//-------------------------------------------------------
CListaDeProdutos::~CListaDeProdutos(void)
{
    CNoListaDeProdutos *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}

//----------------------------------------------------------------------------
// insere novo elemento na cauda da fila
void CListaDeProdutos::inserirItem(int codigo, string nome, string marca, string tipo, double preco)
{

    CNoListaDeProdutos *novo = new CNoListaDeProdutos;
    CNoListaDeProdutos *atual = inicio;

    novo->codigo=codigo;
    novo->nome=nome;
    novo->marca=marca;
    novo->tipo=tipo;
    novo->preco=preco;
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

//-----------------------------------------------------------------------------
// escreve elementos na fila
void CListaDeProdutos::escreveLista(void) const
{
    CNoListaDeProdutos *atual = inicio;

    system("cls");

      if(inicio==NULL)
          cout << "Lista Vazia..." << endl;
      else{
          while(atual!=NULL){
              cout << "Codigo: " << atual->codigo << ", ";
              cout << "Nome: " << atual->nome << ", ";
              cout << "Marca: " << atual->marca << ", ";
              cout << "Tipo: " << atual->tipo << ", ";
              cout << "Preco: " << atual->preco << "euros ";
              atual=atual->seguinte;
              cout << endl;
          }
          cout << "Fim da Lista" << endl;
      }
  }

//-------------------------------------------------------
//elemina elementos da fila
void CListaDeProdutos :: apagaItem(int codigo)
{
    CNoListaDeProdutos *atual = inicio;
        CNoListaDeProdutos *anterior;
        if(inicio==NULL)
	   return;
	else 
	{
		anterior=NULL;
		while(atual!=NULL)
		{
                        if(atual->codigo == codigo )
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

//-------------------------------------------------------
void CListaDeProdutos :: novoPVP(int codigo, double preco)
{
      CNoListaDeProdutos *atual = inicio;

     int i = 1;

     if(inicio==NULL)s
            return;

    else
    {
         while(i != codigo){
             i++;
             atual=atual->seguinte;
         }
        atual->preco=preco;
        return;


    }

}
//-------------------------------------------------------
int CListaDeProdutos :: checkProduto(int codigo)
{
    CNoListaDeProdutos *atual = inicio;

            while(atual->codigo != codigo){
                    atual = atual->seguinte;
            }

            cout << "Codigo: " << atual->codigo << ", ";
            cout << "Nome: " << atual->nome << ", ";
        cout << "Marca: " << atual->marca << ", ";
        cout << "Tipo: " << atual->tipo<< ", ";
        cout << "Preco: " << atual->preco << ".";
        cout << endl;
}


//---------------------------------------------------------------
int CListaDeProdutos :: procuraProduto(int codigo)
{
        CNoListaDeProdutos *atual =  inicio;
	
        if(inicio==NULL)
	cout<<"Lista encontra-se vazia"<<endl;
	
	else
	{
		while(atual!=NULL)
		{
                    if(atual->codigo==codigo)
                    {
			return(atual->preco);
                    }
                    atual=atual->seguinte;
                }
	}
        return -1;
}
