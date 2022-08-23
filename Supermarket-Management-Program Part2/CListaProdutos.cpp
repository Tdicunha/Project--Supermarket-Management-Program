#include "CListaHeader.h"

#include <iostream>
#include <string>

#include <fstream>
#include <iomanip>

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
void CListaDeProdutos::inserirItem(int codigo, string nome, string marca,int codigoTipo, double preco, int stock, int stockMinimo, int stockMaximo)
{

    CNoListaDeProdutos *novo = new CNoListaDeProdutos;
    CNoListaDeProdutos *atual = inicio;

    novo->codigo=codigo;
    novo->nome=nome;
    novo->marca=marca;
    novo->codigoTipo = codigoTipo;
    novo->preco=preco;
    novo->stock = stock;
    novo->stockMinimo = stockMinimo;
    novo->stockMaximo = stockMaximo;
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
              cout <<"Codigo: " << atual->codigo << "; "<<endl;
              cout << "Nome: " << atual->nome<<"; "<<endl;
              cout <<"Marca: " << atual->marca<<"; "<<endl;
              cout << "Tipo: " << atual->codigoTipo<<"; "<<endl;
              cout <<"Preco: " << atual->preco<< "euros "<<endl;
              cout <<"Stock: " << atual->stock<<endl;
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

     if(inicio==NULL)
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
        cout << "Tipo: " << atual->codigoTipo<< ", ";
        cout << "Preco: " << atual->preco << ", ";
        cout <<"Stock: "<<atual->stock << ".";
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

//-----------------------------------------------------------------

void CListaDeProdutos::lerFicheiro(){

        ifstream produtos;
        produtos.open("ListaProdutos.txt");

        if(!produtos.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigo1;
        string codigoTipo1;
        string nome;
        string marca;
        string preco1;
        string stock1;
        string stockMinimo1;
        string stockMaximo1;

        while(produtos.get() != EOF){
                int codigo2;
                int codigoTipo2;
                double preco2;
                int stock2;
                int stockMinimo2;
                int stockMaximo2;

                getline(produtos, codigo1, ';');
                getline(produtos, nome, ';');
                getline(produtos, marca, ';');
                getline(produtos, codigoTipo1, ';');
                getline(produtos, preco1, ';');
                getline(produtos, stock1, ';');
                getline(produtos, stockMinimo1, ';');
                getline(produtos, stockMaximo1, '\n');

                codigo2 = stoi(codigo1); //stoi == int
                codigoTipo2 = stoi(codigoTipo1);
                preco2 = stod(preco1);  //stod == double
                stock2 = stoi(stock1);
                stockMinimo2 = stoi(stockMinimo1);
                stockMaximo2 = stoi(stockMaximo1);


                inserirItem(codigo2, nome, marca, codigoTipo2,preco2,stock2,stockMinimo2,stockMaximo2);
        }
        produtos.close();
}


//--------------------------------------------------------------------------------------------------------------------------------
bool CListaDeProdutos :: verificaProduto(int codigoproduto)
{
	 CNoListaDeProdutos * atual=inicio;
	 
	 if(inicio==NULL)
	 return false;
	 
	 while(atual != NULL)
	 {
                 if(atual->codigo == codigoproduto)
		 return true;
		 atual=atual->seguinte;
	 }
	 return false;
}

//----------------------------------------------------------
void CListaDeProdutos :: novoStock(int codigo, int stockMinimo, int stockMaximo)
{
      CNoListaDeProdutos *atual = inicio;

     int i = 1;

     if(inicio==NULL)
            return;

    else
    {
         while(i != codigo){
             i++;
             atual=atual->seguinte;
         }
        atual->stockMinimo=stockMinimo;
        atual->stockMaximo=stockMaximo;

        return;


    }

}
//----------------------------------------------------------
int CListaDeProdutos :: retornacodigoproduto()
{
    CNoListaDeProdutos  *novo = new CNoListaDeProdutos;
    CNoListaDeProdutos  *atual = inicio;

    int conta =1;

    if(inicio == NULL)
    {
        novo->codigo= 1;
    }
    else
      atual =inicio;

        while(atual->seguinte!=NULL)
        {
            atual=atual->seguinte;
            conta=atual->codigo;
            novo->codigo = conta+1;
            atual->seguinte=novo;

            return(novo->codigo);
        }
}
//------------------------------------------------------------------
int CListaDeProdutos::procuraNomeProduto(string nome) const{
    CNoListaDeProdutos *atual=inicio;

        int indice=1;
    if(inicio==NULL)
        return -3;
    else{
        while(atual!=NULL){
                        std::size_t found = atual->nome.find(nome);
                        if (found!=std::string::npos){
                                return indice;
                        }
                        indice++;
            atual=atual->seguinte;
        }
        return -1;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------
void CListaDeProdutos::escreveProdutoItensVenda(int codigo)
{
    CNoListaDeProdutos *atual=inicio;
    int contador = 1;

    if(atual ==NULL){
        return;
    }
    while(contador != codigo){
        contador++;
        atual = atual->seguinte;
    }
    cout << "Nome: " << atual->nome << ", ";
    cout << "Marca: " << atual->marca << ", ";
    cout << "Tipo: " << atual->codigoTipo << ", ";
}
//--------------------------------------------------------------------------------------------------------------------------------
/*int CListaDeProdutos :: procuraProdutoFalta()
{
    CNoListaDeProdutos *atual =  inicio;

    if(inicio==NULL)
    cout<<"Lista encontra-se vazia"<<endl;

    else
    {
        while(atual!=NULL)
        {
                    if(atual->stock <= stockMinimo)
                    {
                        return(atual->codigo);
                    }
                    atual=atual->seguinte;
        }
    }
        return -1;
}
*/
