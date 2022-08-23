#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

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
    novo->totalItem=total;
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
            //cout<< atual->data << "; "<<endl; da erro aqui
            cout << "Quantidade: " <<endl;
            cout<< atual->quantidade << "; "<<endl;
            cout << "Preco: " <<endl;
            cout<< atual->totalItem << "."<<endl;;
            atual=atual->seguinte;
            cout << endl;
        }
        cout << endl;
    }
}
//--------------------------------------------------------------------
bool CListaItemVenda :: verificaItemProduto(int codigoproduto)
 {
	 CNoListaItemVenda * atual=inicio;
	 
	 if(inicio==NULL)
	 return false;
	 
	 while(atual != NULL)
	 {
		 if(atual->codigoProduto == codigoproduto)
		 return true;
		 atual=atual->seguinte;
	 }
	 return false;
 }

//---------------------------------------------------

void CListaItemVenda::lerFicheiro(){

        ifstream ItemVenda;
        ItemVenda.open("ListaProdutos.txt");

        if(!ItemVenda.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigoVenda1;
        string codigoProduto1;
        string quantidade1;
        string total1;

        while(ItemVenda.get() != EOF){

                int codigoVenda2;
                int codigoProduto2;
                int quantidade2;
                double total2;


                getline(ItemVenda, codigoVenda1, ';');
                getline(ItemVenda, codigoProduto1, ';');
                getline(ItemVenda,quantidade1,';');
                getline(ItemVenda, total1, '\n');


                codigoVenda2 = stoi(codigoVenda1); //stoi == int
                codigoProduto2 = stoi(codigoProduto1);
                total2 = stod(total1);  //stod == double
                quantidade2 = stoi(quantidade1);

                inserirListaVenda(codigoVenda2, codigoProduto2, quantidade2, total2);
        }
        ItemVenda.close();
}

//----------------------------------------------------------
void CListaItemVenda::listaVendaGlobal(CListaDeProdutos &produtos, CListaVendas &vendas)
{
    CNoListaItemVenda *atual;
    atual=inicio;


    if(inicio==NULL){
        cout << "Lista Vazia." << endl;
    }
    else{
        while(atual!=NULL){
            cout << "Codigo da venda: " << atual->codigoVenda << ", ";

            cout << "Codigo do produto: " << atual->codigoProduto << endl;
            produtos.escreveProdutoItensVenda(atual->codigoProduto);
            cout << "Quantidade: " << atual->quantidade << ", ";
            cout << "Preco: " << atual->totalItem << "." << endl << endl;
            atual = atual->seguinte;
        }
    }
}

//----------------------------------------------------------------------
void CListaItemVenda::listaVendaProduto( int codigoproduto, CListaVendas &vendas, CListaDeProdutos &produtos)
{
    CNoListaItemVenda *atual;
    atual=inicio;


    if(inicio==NULL){
        cout << "Lista Vazia." << endl;
    }
    else{
        while(atual!=NULL){
            if(atual->codigoProduto == codigoproduto){
                cout << "Codigo da venda: " << atual->codigoVenda << ", ";
                cout << "Codigo do produto: " << atual->codigoProduto << endl;
                produtos.escreveProdutoItensVenda(atual->codigoProduto);
                cout << "Quantidade: " << atual->quantidade << ", ";
                cout << "Preco: " << atual->totalItem << "." << endl << endl;
            }
            atual=atual->seguinte;
        }
    }
}

//--------------------------------------------------
/*int CListaItemVenda::procuraDataVenda(CListaVendas &data) const{

    CNoListaItemVenda *atual=inicio;

    int indice=1;
    if(inicio==NULL)
        return -3;
    else{
        while(atual!=NULL){
                       // std::size_t found = atual->*data.find(data);
                        if (found!=std::string::npos){
                                return indice;
                        }
                        indice++;
            atual=atual->seguinte;
        }
        return -1;
    }
}


//============METODO QUE PROCURA PRODUTO NUMA VENDA=================

int CListaItemVenda::procuraProdutoVenda(unsigned int codigoproduto) const{
    CNoListaItensVenda *atual=inicio;
	int indice=0;
    if(inicio==NULL)
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

void CListaItemVenda::listaVendaGlobal(CListaDeProdutos &produtos, CListaVendas &vendas){
    CNoListaItemVenda *atual;
    atual=inicio;
	string data;
	
    if(inicio==NULL){
        cout << "Lista Vazia." << endl;
	}
    else{
        while(atual!=NULL){
            cout << "Codigo da venda: " << atual->codigoVenda << ", ";
			data.clear();
            data = vendas.retornaData(atual->codigoVenda);
			cout << "Data de venda (AAAAMMDD): " << data << ", ";
            cout << "Codigo do produto: " << atual->codigoProduto << endl;
            produtos.escreveProdutoItensVenda(atual->codigoProduto);
			cout << "Quantidade: " << atual->quantidade << ", ";
			cout << "Preco: " << atual->preco << "." << endl << endl;
            atual = atual->seguinte;
		}
    }
}
//--------------------------------------------------------------------
int CListaItemVenda :: fatura (int codigo)//nao deu certo
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
}
	
    */
	
