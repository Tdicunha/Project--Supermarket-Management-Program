#ifndef CListaHeader_h
#define CListaHeader_h

using namespace std;
#include <string>


//-----------------PRODUTOS -------------------------------------------------
class CNoListaDeProdutos{
public:
  
    int codigo;
    string nome;
    string marca;
    string tipo;
    double preco;

    CNoListaDeProdutos *seguinte;
	
   // friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};



//---------------- VENDA -----------------------------------
class CNoListaVenda{
public:
  
	   unsigned int codigoVenda;
       string data;
       double total;
	   int numelems;
        

   CNoListaVenda *seguinte;

  //  friend class CListaVendas; // permite a esta classe aceder atributos private
};

//--------------------ITENS DE VENDA---------------------
class CNoListaItemVenda{
public:
    
    int codigoVenda;
    int codigoProduto;
    int quantidade;
    double totalitem;
    
    CNoListaItemVenda *seguinte;

 //   friend class CListaItensVenda; // permite a esta classe aceder atributos private
};

//--------------- Lista de produtos-------------------------------------------
class CListaDeProdutos{
    CNoListaDeProdutos *inicio, *fim ;

public:
        CListaDeProdutos(void);
        ~CListaDeProdutos(void);

    	void inserirItem(int codigo, string nome, string marca, string tipo, double preco);
        void escreveLista(void) const;
    	void apagaItem(int codigo);
      	void novoPVP(int codigo, double preco);
        int checkProduto(int codigo);
        int procuraProduto(int codigo);
        bool filaVazia(void) const { return (inicio == NULL ); }

};

//------------------- Lista de vendas----------------------------------
class CListaVendas{
   CNoListaVenda *inicio, *fim;

public:
        CListaVendas(void);
        ~CListaVendas(void);

    //penso que so seja necessario um ou 2 metodos, sendo quem um deles e so para mostar os dados da venda
        void inserirVenda(int codigoVenda,int codigoproduto, string data, int numvendas, double precovenda);
        int criacodigovenda();
        //void escreveListaVendas(void) const;
        void escreveLista(void) const;
       // void operator + (const CListaVendas &);
       // bool filaVazia(void) const { return (inicio == NULL ); }
      
};

//-------------------- lista de itens vendidos ---------------------------
class CListaItemVenda{

    CNoListaItemVenda *inicio, *fim;

public:
        CListaItemVenda(void);
        ~CListaItemVenda(void);

    //penso que so seja necessario um ou 2 metodos, sendo quem um deles e so para mostar os dados da venda
        void inserirListaVenda (int codigovenda,string dt, int codigoproduto, int quantidade, double total);
        void escreveListaVenda(void)const;
       // int  fatura(int codigo);//nao deu certo
         //   void soma(int m);

        bool filaVazia(void) const { return (inicio == NULL ); }
};
#endif
