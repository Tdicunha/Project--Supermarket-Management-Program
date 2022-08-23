#include "CListaHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

CListaProdutosDisponiveisFornecedores::CListaProdutosDisponiveisFornecedores(void) {
    inicio = NULL;

}

//---------------------------------------------------------------------------------------------------------------------------------
CListaProdutosDisponiveisFornecedores::~CListaProdutosDisponiveisFornecedores(void)
{
    CNoListaProdutosDisponiveisFornecedores *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}
//---------------------------------------------------------------------------------------------------------------------------------
void CListaProdutosDisponiveisFornecedores :: inserirProdutosFornecedores(int codigo, int codigofornecedor, double preco, int quantidademinima, int descontos)
{

    CNoListaProdutosDisponiveisFornecedores *novo = new CNoListaProdutosDisponiveisFornecedores;
    CNoListaProdutosDisponiveisFornecedores *atual = inicio;

    novo->codigo=codigo;
    novo->codigoFornecedor=codigofornecedor;
    novo->preco=preco;
    novo->quantidadeMinima=quantidademinima;
    novo->desconto=descontos;
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
void CListaProdutosDisponiveisFornecedores::escreveListaProdutoFornecedor(void) const
{
    CNoListaProdutosDisponiveisFornecedores *atual = inicio;

    system("cls");

      if(inicio==NULL)
          cout << "Lista Vazia..." << endl;
      else{
          while(atual!=NULL){
			  
              cout << "Codigo do produto: " << atual->codigo << "; "<<endl;
              cout << "Codigo do fornecedor: " << atual->codigoFornecedor << "; "<<endl;
              cout << "Preco do produto fornecido: " << atual->preco << "; "<<endl;
              cout << "Quantidade minima a comprar(fornecer): " << atual->quantidadeMinima << "; "<<endl;
              cout << "Desconto: " << atual->desconto << ". "<<endl;  
              atual=atual->seguinte;
              cout << endl << endl;
          }
          cout << "Fim da Lista" << endl;
      }
  }
 //--------------------------------------------------------------------------------------------------------------------------------
  void CListaProdutosDisponiveisFornecedores :: apagaProdutoFornecedor(int codigo)
{
    CNoListaProdutosDisponiveisFornecedores*atual = inicio;
    CNoListaProdutosDisponiveisFornecedores *anterior;
        
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

//--------------------------------------------------------------------------------------------------------------------------------
void CListaProdutosDisponiveisFornecedores::lerFicheiro(){

        ifstream produtosDisponiveisFornecedores;
        produtosDisponiveisFornecedores.open("ListaProdutosFornecedores.txt");

        if(!produtosDisponiveisFornecedores.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigo1;
        string codigoFornecedor1;
        string preco1;
        string quantidadeMinima1;
        string descontos1;

        while(produtosDisponiveisFornecedores.get() != EOF){
                int codigo2;
                int codigoFornecedor2;
                double preco2;
                int quantidadeMinima2;
                int descontos2;

                getline(produtosDisponiveisFornecedores, codigo1, ';');
                getline(produtosDisponiveisFornecedores, codigoFornecedor1, ';');
                getline(produtosDisponiveisFornecedores, preco1, ';');
                getline(produtosDisponiveisFornecedores, quantidadeMinima1, ';');
                getline(produtosDisponiveisFornecedores, descontos1, '\n');

                codigo2 = stoi(codigo1);
                codigoFornecedor2 = stoi(codigoFornecedor1);
                preco2 = stod(preco1);
                quantidadeMinima2 = stoi(quantidadeMinima1);
                descontos2 = stoi(descontos1);

                inserirProdutosFornecedores(codigo2, codigoFornecedor2, preco2, quantidadeMinima2,descontos2);
        }
        produtosDisponiveisFornecedores.close();
}

//--------------------------------------------------------------------------------------------------------------------------------

 void CListaProdutosDisponiveisFornecedores :: modificarProdutoFornecedor(int codigofornecedor, int codigo, double preco, int quantidademinima,double desconto)
  {
        CNoListaProdutosDisponiveisFornecedores *atual = inicio;

       int i = 1;

       if(inicio==NULL)
              return;

      else
      {
           while(i != codigofornecedor){
               i++;
               atual=atual->seguinte;
           }
          atual->codigo=codigo;
          atual->preco=preco;
          atual->quantidadeMinima=quantidademinima;
          atual->desconto=desconto;

          return;


      }

  }
//----------------------------------------------------------------------
 int CListaProdutosDisponiveisFornecedores :: checkProdutoFornecedor(int codigo)
{
    CNoListaProdutosDisponiveisFornecedores *atual = inicio;

            while(atual->codigo != codigo)
            {
                    atual = atual->seguinte;
            }

        cout << "Codigo do produto: " << atual->codigo << "; "<<endl;
        cout << "Codigo do fornecedor: " << atual->codigoFornecedor << "; "<<endl;
        cout << "Preco do produto fornecido: " << atual->preco << "; "<<endl;
        cout << "Desconto: " << atual->desconto << ". "<<endl;
        cout << endl;
        return(atual->codigoFornecedor);
}

//--------------------------------------------------------------------------------------------------------------------------------
int CListaProdutosDisponiveisFornecedores :: checkPrecoForncedor(int codigofornecedor)
{
	 CNoListaProdutosDisponiveisFornecedores *atual = inicio;
	 double tab[20];
	 if(inicio==NULL)
		cout<<"Lista encontra-se vazia"<<endl;
	 else
	 {
		 
			 while(atual!= NULL)
			 {
				 if(atual->codigoFornecedor== codigofornecedor)
				
				 atual=atual->seguinte;
			 }
            //return(((atual->stockMaximo-atual->stock)*actual->preco)-atual->desconto);
	  }
	  
 }
