#include "CListaHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


CListaTiposProdutos::CListaTiposProdutos(void) {
    inicio = NULL;

}

//----------------------------------------------------------------------
CListaTiposProdutos::~CListaTiposProdutos(void)
{
    CNoListaTiposProdutos *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}

//----------------------------------------------------------------------

void CListaTiposProdutos :: inserirTipo(string tipo, int codigo, float IVA)
{

    CNoListaTiposProdutos *novo = new CNoListaTiposProdutos;
    CNoListaTiposProdutos *atual = inicio;

    novo->tipo=tipo;
    novo->codigo=codigo;
    novo->IVA=IVA;
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
//----------------------------------------------------------------------
 void CListaTiposProdutos::escreveListaTipoProduto(void) const
{
    CNoListaTiposProdutos *atual = inicio;

    system("cls");

      if(inicio==NULL)
          cout << "Lista Vazia..." << endl;
      else{
          while(atual!=NULL){
              cout << "Tipo de produto: " << atual->tipo << "; "<<endl;
              cout << "Codigo do produto: " << atual->codigo << "; "<<endl;
              cout << "IVA do produto: " << atual->IVA << ". "<<endl;
              
              atual=atual->seguinte;
              cout << endl;
          }
          cout << "Fim da Lista" << endl;
      }
  }
//----------------------------------------------------------------------
void CListaTiposProdutos :: novoIVA(int codigo, float IVA)
{
      CNoListaTiposProdutos *atual = inicio;

     int i = 1;

     if(inicio==NULL)
            return;

    else
    {
         while(i != codigo){
             i++;
             atual=atual->seguinte;
         }
        atual->IVA=IVA;
        return;


    }

}
//----------------------------------------------------------------------

void CListaTiposProdutos :: apagaTipoProduto(int codigo)
{
    CNoListaTiposProdutos *atual = inicio;
        CNoListaTiposProdutos *anterior;
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
void CListaTiposProdutos::lerFicheiro(){

        ifstream tiposProdutos;
        tiposProdutos.open("ListaTiposProdutos.txt");

        if(!tiposProdutos.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string tipo;
        string codigo1;
        string IVA1;

        while(tiposProdutos.get() != EOF){

                int codigo2;
                float IVA2;

                getline(tiposProdutos, tipo, ';');
                getline(tiposProdutos, codigo1, ';');
                getline(tiposProdutos, IVA1, '\n');

                codigo2 = stoi(codigo1);
                IVA2 = stod(IVA1);

                inserirTipo(tipo, codigo2, IVA2);
        }
        tiposProdutos.close();
}

//---------------------------------------------------------------------------------
int CListaTiposProdutos :: retornaCodigoTipoProduto()
{
    CNoListaTiposProdutos  *novo = new CNoListaTiposProdutos;
    CNoListaTiposProdutos  *atual = inicio;

    int conta =0;

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
