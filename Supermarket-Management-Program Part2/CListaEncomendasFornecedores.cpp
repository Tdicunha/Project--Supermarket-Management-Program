#include "CListaHeader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


CListaEncomendasFornecedores::CListaEncomendasFornecedores(void) 
{
    inicio = NULL;

}

//---------------------------------------------------------------------------------------------------------------------------------
CListaEncomendasFornecedores::~CListaEncomendasFornecedores(void)
{
    CNoEncomendasFornecedores *aux;

    while (inicio != NULL) {
        aux = inicio->seguinte; // elemento seguinte
        delete inicio;              // apaga elemento no inicio da fila
        inicio = aux;          // define nova cabeca da fila
    }
    fim = NULL;
}
//---------------------------------------------------------------------------------------------------------------------------------

void CListaEncomendasFornecedores:: inserirEncomenda (int codigoEncomenda,int codigoFornecedor, string data, int hora, int numeroItens, double custo, bool recebido, string dataRec)
{
	CNoEncomendasFornecedores *novo = new CNoEncomendasFornecedores;
    CNoEncomendasFornecedores *atual = inicio;

    novo->codigoEncomenda=codigoEncomenda;
    novo->codigoFornecedor=codigoFornecedor;
    novo->data=data;
    novo->hora=hora;
    novo->numeroItens=numeroItens;
    novo->custoTotal=custo;
    novo->recebida=recebido;
    novo->dataRececao=dataRec;
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

 void CListaEncomendasFornecedores::escreveEncomenda(void) const
{
    CNoEncomendasFornecedores *atual = inicio;

    system("cls");

      if(inicio==NULL)
          cout << "Lista Vazia..." << endl;
      else{
          while(atual!=NULL){
              cout << "Codigo da Encomenda: " << atual->codigoEncomenda << "; "<<endl;
              cout << "Codigo do Fornecedor: " << atual->codigoFornecedor << "; "<<endl;
              cout << "Data: " << atual->data << "; "<<endl;
              cout << "Hora: " << atual->hora << "; "<<endl;
              cout << "Quantidade: " << atual->numeroItens << "; "<<endl;
              cout << "Preco: " << atual->custoTotal << "; "<<endl;
              cout << "Recebido: " << atual->recebida << "; "<<endl;
              cout << "Data de Rececao: " << atual->dataRececao << ". "<<endl;
              
              atual=atual->seguinte;
              cout << endl;
          }
          cout << "Fim da Lista" << endl;
      }
  }
//--------------------------------------------------------------------------------------------------------------------------------
void CListaEncomendasFornecedores :: apagaEncomenda(int codigoencomenda)
{
    CNoEncomendasFornecedores *atual = inicio;
    CNoEncomendasFornecedores *anterior;
    
    if(inicio==NULL)
	return;
	
	else 
	{
		anterior=NULL;
		while(atual!=NULL)
		{
                        if(atual->codigoEncomenda == codigoencomenda) 
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
// serve para dar o codigo de fornecedor, depois verifica-se se existe na lista de fonrcedores e assim sabemos que este 
//fornecedor tem encomenda e nao pode ser apagado
int CListaEncomendasFornecedores :: verifica(int codigoencomenda)
{
    CNoEncomendasFornecedores *atual =  inicio;
	
    if(inicio==NULL)
	cout<<"Lista encontra-se vazia"<<endl;
	
	else
	{
		while(atual!=NULL)
		{
                    if(atual->codigoEncomenda==codigoencomenda)
                    {
			return(atual->codigoFornecedor);
                    }
                    atual=atual->seguinte;
                }
	}
        return -1;
}

//---------------------------------------------------------------------------------------------------------------------------------
void CListaEncomendasFornecedores::lerFicheiro()
{

        ifstream encomendasFornecedores;
        encomendasFornecedores.open("ListaEncomendasFornecedores.txt");

        if(!encomendasFornecedores.is_open()){
                cout << "Ficheiro nao pode ser aberto" << endl;
                return;
        }

        string codigoEncomenda1;
        string codigoFornecedor1;
        string data;
        string hora1;
        string numeroItens1;
        string custo1;
        string dataRec;
        string preco1;

        while(encomendasFornecedores.get() != EOF){
                int codigoEncomenda2;
                int codigoFornecedor2;
                int hora2;
                int numeroItens2;
                double custo2;
                bool recebido;

                getline(encomendasFornecedores, codigoEncomenda1, ';');
                getline(encomendasFornecedores, codigoFornecedor1, ';');
                getline(encomendasFornecedores, data, ';');
                getline(encomendasFornecedores, hora1, ';');
                getline(encomendasFornecedores, numeroItens1, ';');
                getline(encomendasFornecedores, custo1, ';');
                getline(encomendasFornecedores,dataRec,'\n');


                codigoEncomenda2 = stoi(codigoEncomenda1);
                codigoFornecedor2 = stoi(codigoFornecedor1);
                custo2 = stod(custo1);
                hora2 = stoi(hora1);
                numeroItens2 = stoi(numeroItens1);


                inserirEncomenda(codigoEncomenda2,codigoFornecedor2 ,data, hora2, numeroItens2,custo2,recebido,dataRec);
        }
        encomendasFornecedores.close();
}

