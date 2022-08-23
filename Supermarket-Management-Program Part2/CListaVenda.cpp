#include "CListaHeader.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;


//---------------------------------------------------------------------------------
CListaVendas::CListaVendas(void) {
    inicio = NULL;
    fim = NULL;
}

//---------------------------------------------------------------------------
CListaVendas::~CListaVendas(void)
{
    CNoListaVenda *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}
//---------------------------------------------------------------------------
//nova venda
void CListaVendas::inserirNovaVenda(int codigovenda, string data, int numelems, double preco)
{

    CNoListaVenda *novo = new CNoListaVenda;
    CNoListaVenda *atual;

    novo->codigoVenda=codigovenda;
    novo->data=data;
    novo->numElems=numelems;
    novo->total=preco;
    novo->seguinte=NULL;

    if(inicio==NULL)
    {
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

//----------------------------------------------------------------------------

void CListaVendas::inserirVenda(int codigovenda, string data, int numelems, double precovenda)
{
                                              //...(int codigoproduto,)
    CNoListaVenda *novo = new CNoListaVenda;
    CNoListaVenda *atual;

//    novo->codigoProduto=codigoproduto;
    novo->data=data;
    novo->numElems=numelems;
    novo->total=precovenda;
    novo->codigoVenda=codigovenda;
    novo->seguinte=NULL;

    if(inicio==NULL)
    {
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
// nao se esta é necessario
void CListaVendas::escreveLista(void) const
{

    CNoListaVenda *atual=inicio;
    system("cls");

      if(inicio==NULL)
          cout << "Lista sem informacao" << endl;
      else {
          while(atual!=NULL){

          cout<< "Codigo de venda: ";
          cout<<atual->codigoVenda<<endl;

          cout << "Codigo de Produto: ";
          cout<< atual->codigoVenda<<endl;
          
          cout << "Data de venda: ";
          cout<< atual->data;
          
          cout << "Preco do Total: ";
          cout<< atual->total<<endl;
          
          cout << "Numero de itens do produto: ";
          cout<< atual->numElems <<endl;

          atual=atual->seguinte;
          cout << endl;
          }
      }
}

//---------------------------------------------------------------------------------------------------------------
int CListaVendas :: criacodigovenda()
{
     CNoListaVenda *novo = new CNoListaVenda;
     CNoListaVenda *atual = inicio;

     int conta = 1;
        if (inicio==NULL)
	{
                novo->codigoVenda=0;
	}

     novo->codigoVenda=0;

    if(inicio==NULL){
        inicio=novo;
    }
    else
    {
        atual=inicio;
            while(atual->seguinte!=NULL)
            {
            atual=atual->seguinte;
		    }
        conta=atual->codigoVenda;
        novo->codigoVenda = conta+1;
        atual->seguinte=novo;

        return(novo->codigoVenda);
    }

}
//-------------------------------------------------------------------------
//bool CListaVendas :: verificação de codigo(int codigo)
//--*--------------------------------------------------------
/*int CListaVendas :: operator + (const CListaVendas &novo)
  {
    CNoListaVenda *atual;

        atual = novo.cabeca;

    if(novo.cabeca==NULL){
       return;
    }
    while(atual!=NULL){
                                                 
        atual=atual->seguinte;
    }

}*/

//----------------------------------------------------------
void CListaVendas::lerFicheiro(){

        ifstream vendas;
        vendas.open("ListaVendas.txt");

        if(!vendas.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigoVenda1;
        string data;
        string numelems1;
        string precoVenda1;


        while(vendas.get() != EOF){

                unsigned int codigoVenda2;
                double precoVenda2;
                int numelems2;

                getline(vendas, codigoVenda1, ';');
                getline(vendas, data, ';');
                getline(vendas, precoVenda1, ';');
                getline(vendas, numelems1, '\n');

                codigoVenda2 = stoi(codigoVenda1);
                precoVenda2 = stod(precoVenda1);
                numelems2 = stoi(numelems1);

                inserirVenda(codigoVenda2, data, precoVenda2, numelems2);
        }
        vendas.close();
}


	
	
	
