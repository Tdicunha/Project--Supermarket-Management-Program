#include <iostream>
#include <string>
#include <cstring>

#include "CListaHeader.h"
using namespace std;

//--------------------------------------------------------
CListaItemVenda::CListaItemVenda(){
    inicio = NULL;
    fim = NULL;
}

//-------------------------------------------------------
CListaItemVenda::~CListaItemVenda(void)
{
    CNoListaItemVenda *aux;

    while (inicio != NULL)
    {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}
//-----------------------------------------------------------
void CListaItemVenda :: inserirListaVenda(int codigovenda, int codigoproduto,int quantidade, double total)
{
    CNoListaItemVenda *novo=new CNoListaItemVenda;
    CNoListaItemVenda *atual;
    
    novo->codigoVenda=codigovenda;
    novo->codigoProduto=codigoproduto;
    novo->quantidade=quantidade;
    novo->total=total;
    novo->seguinte=NULL;
    
     if(inicio==NULL){
        inicio = novo;
    }else{
        atual=inicio;
        while(atual->seguinte!=NULL)
            atual = atual->seguinte;
        atual->seguinte = novo;
	}
}
//-----------------------------------------------------------
void escreveListaVenda(void)
{
        CNoListaItemVenda *atual;
        

    if(atual==NULL)
        cout << "Lista sem informacao" << endl;
    else{
        while(atual!=NULL){
            cout << "Codigo da venda: " <<endl; 
            cout<<atual->codigoVenda << "; "<<endl;
            cout << "Codigo do produto: " <<endl;
            cout<< atual->codigoProduto << "; "<<endl;
            cout << "Data: " <<endl;
            cout<< atual->data << "; "<<endl;
            cout << "Quantidade: " <<endl;
            cout<< atual->quantidade << "; "<<endl;
            cout << "Preco: " <<endl;
            cout<< atual->total << "."<<endl;;
            atual=atual->seguinte;
            cout << endl;
        }
        cout << endl;
    }
}
//--------------------------------------------------------------------
//============METODO QUE PROCURA PRODUTO NUMA VENDA=================
int CListaItemVenda::procuraProdutoVenda(unsigned int codigoproduto) const{
    CNoListaItensVenda *atual=cabeca;
	int indice=0;
    if(cabeca==NULL)
        return -1;
    else{
        while(atual!=NULL){
            if(atual->codigoproduto == codigoproduto){
				return indice;
			}
			indice++;
            atual=atual->proximo;
        }
        return -1;
    }
}
//------------------------------------------------------------------
// faturacao-data
void CListaItemVenda::listaVendaGlobal(CListaProdutos &produtos, CListaVendas &vendas){
	CNoListaItensVenda *atual;
	atual=cabeca;
	string data;
	
    if(cabeca==NULL){
        cout << "Lista Vazia." << endl;
	}
    else{
        while(atual!=NULL){
			cout << "Codigo da venda: " << atual->codigovenda << ", ";
			data.clear();
			data = vendas.retornaData(atual->codigovenda);
			cout << "Data de venda (AAAAMMDD): " << data << ", ";
			cout << "Codigo do produto: " << atual->codigoproduto << endl;
			produtos.escreveProdutoItensVenda(atual->codigoproduto);
			cout << "Quantidade: " << atual->quantidade << ", ";
			cout << "Preco: " << atual->preco << "." << endl << endl;
			atual = atual->proximo;
		}
    }
}
//--------------------------------------------------------------------
/*int CListaItemVenda :: fatura (int codigo)//nao deu certo
{
        CNoListaItemVenda *atual=cabeca;
        CNoListaItemVenda *novo,*nv;
        if(cabeca==NULL)return 0;
	

	while (atual != NULL) 
	{
                if (atual->codigovenda == codigo);
		{
			
                        if(nome == atual->seguinte)
			{
                                nv =nome;

			}
			if(preco==atual->seguinte)
			{
				novo=preco;
			    soma(novo);
		    }
                }
		atual = atual->seguinte;
    
  }
}

//------------------------------------------------------

void CListaItemVenda :: soma(int m){
        CNoListaItemVenda * novo= new CNoListaItemVenda;
        //novo = m;
        //total=total+novo;
}*/
	
	
	
