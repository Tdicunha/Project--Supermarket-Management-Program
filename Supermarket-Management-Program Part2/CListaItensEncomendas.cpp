#include "CListaHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

CListaItensEncomendas::CListaItensEncomendas(void) {
    inicio = NULL;

}

//---------------------------------------------------------------------------------------------------------------------------------
CListaItensEncomendas::~CListaItensEncomendas(void)
{
    CNoListaItensEncomendas *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}

//---------------------------------------------------------------------------------------------------------------------------------

void CListaItensEncomendas:: inserirItenEncomenda (int codigoencomenda,int codigoproduto, int quantidade, int valordesconto, double custototal)
{
	CNoListaItensEncomendas *novo = new CNoListaItensEncomendas;
    CNoListaItensEncomendas *atual = inicio;

    novo->codigoEncomenda=codigoencomenda;
    novo->codigoProduto=codigoproduto;
    novo->quantidade=quantidade;
    novo->valorDesconto=valordesconto;
    novo->custoTotal=custototal;
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

void CListaItensEncomendas:: escreveItenEncomenda(void) const
{
    CNoListaItensEncomendas *atual = inicio;

    system("cls");

      if(inicio==NULL)
          cout << "Lista Vazia..." << endl;
      else{
          while(atual!=NULL){
              cout << left<<"Codigo da Encomenda " << atual->codigoEncomenda << "; "<<endl;
              cout << left<<setw(30)<<"Codigo do Produto: " << atual->codigoProduto << "; "<<endl;
              cout << right<<setw(20)<<"Quantidade: " << atual->quantidade<<"; " <<endl;
              cout << right<<setw(30)<<"Valor Descontado: " << atual->valorDesconto<<"; " <<endl;
              cout << right<<setw(40)<<"Custo de encomenda: " << atual->custoTotal<<". " <<endl;
              
              atual=atual->seguinte;
              cout << endl;
          }
          cout << "Fim da Lista" << endl;
      }
}

//---------------------------------------------------------------------------------------------------------------------------------
void CListaItensEncomendas :: apagaItenEncomenda(int codigoencomenda)
{
    CNoListaItensEncomendas *atual = inicio;
    CNoListaItensEncomendas *anterior;
    
    if(inicio==NULL)
	return;
	
	else 
	{
		anterior=NULL;
		while(atual!=NULL)
		{
                        if(atual->codigoEncomenda == codigoencomenda )
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
//----------------------------------------------------------------------
bool CListaItensEncomendas :: verificaEncomendaProduto(int codigoproduto)
 {
	 CNoListaItensEncomendas * atual=inicio;
	 
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
//--------------------------------------------------------------------------------------------------------------------------------
/*void CListaItensEncomendas::lerFicheiro()
{

        ifstream produtos;
        produtos.open("ListaProdutos.txt");

        if(!produtos.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigo1;
        string nome;
        string marca;
        string tipo;
        string preco1;

        while(produtos.get() != EOF){
                int codigo2;
                double preco2;
                getline(produtos, codigo1, ';');
                getline(produtos, nome, ';');
                getline(produtos, marca, ';');
                getline(produtos, preco1, '\n');
                codigo2 = stoi(codigo1);
                preco2 = stod(preco1);
                inserirItem(codigo2, nome, marca, preco2);
        }
        produtos.close();
}
*/
