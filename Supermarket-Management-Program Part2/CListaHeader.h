#ifndef CListaHeader_h
#define CListaHeader_h

using namespace std;
#include <string>


//--------------------------------------------------------------------
// ------------------- TIPOS DE PRODUTOS ------------------------------
class CNoListaTiposProdutos{
public:

    string tipo;
    int codigo;
    float IVA;

    CNoListaTiposProdutos *seguinte;

   // friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};

//--------------------------------------------------------------------------
//-----------------PRODUTOS -------------------------------------------------
class CNoListaDeProdutos{
public:
  
    int codigo;
    string nome;
    string marca;
    int codigoTipo;
    double preco;
    int stock;
    int stockMinimo;
    int stockMaximo;

    CNoListaDeProdutos *seguinte;
	
   friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};

//--------------------------------------------------------
//---------------- VENDA -----------------------------------
class CNoListaVenda{
public:
  
       unsigned int codigoVenda;
       string data;
       string hora;
       double total;
       int numElems;
        
   CNoListaVenda *seguinte;

  //  friend class CListaVendas; // permite a esta classe aceder atributos private
};

//-------------------------------------------------------
//--------------------ITENS DE VENDA---------------------
class CNoListaItemVenda{
public:
    
    int codigoVenda;
    int codigoProduto;
    int quantidade;
    double totalItem;
    
    CNoListaItemVenda *seguinte;

 //   friend class CListaItensVenda; // permite a esta classe aceder atributos private
};

//----------------------------------------------------------------
//----------------FORNECEDORES----------------------------------
class CNoFornecedores{
public:

    int codigoFornecedor;
    string nome;
    string morada;
    string telefone;

    CNoFornecedores *seguinte;

   // friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};

//-------------------------------------------------------------
//--------------------PRODUTOS DISPONIVEIS EM FORNECEDORES----------------------------------
class CNoListaProdutosDisponiveisFornecedores{
public:

    int codigo;
    int codigoFornecedor;
    double preco;
    int quantidadeMinima;
    double desconto;

    CNoListaProdutosDisponiveisFornecedores *seguinte;

   // friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};

//----------------------------------------------------------------------------
//------------ENCOMENDAS A FORNECEDORES--------------------------------------------
class CNoEncomendasFornecedores{
public:

    int codigoEncomenda;
    int codigoFornecedor;
    string data;
    int hora;
    int numeroItens;
    double custoTotal;
    bool recebida;
    string dataRececao;

    CNoEncomendasFornecedores *seguinte;

   // friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};

//------------------------------------------------------
//--------------------ITENS DE ENCOMENDAS----------------------
class CNoListaItensEncomendas{
public:

    int codigoEncomenda;
    int codigoProduto;
    int quantidade;
    int valorDesconto;//nao devia ser double
    double custoTotal;

    CNoListaItensEncomendas *seguinte;

   // friend class CListaDeProdutos; // permite a esta classe aceder atributos private
};


//-------------------------------------//---------------------------------------//------------------------------------------------

class CListaTiposProdutos{
    CNoListaTiposProdutos *inicio, *fim;

public:
    CListaTiposProdutos(void);
    ~CListaTiposProdutos(void);

    void inserirTipo(string tipo, int codigo, float IVA);
    void escreveListaTipoProduto(void) const;
    void novoIVA(int codigo, float IVA);
    void apagaTipoProduto(int codigo);
    int  retornaCodigoTipoProduto();

    void lerFicheiro();
    bool filaVazia(void) const { return (inicio == NULL ); }
    
};

//--------------- Lista de produtos-------------------------------------------
class CListaDeProdutos{
    CNoListaDeProdutos *inicio, *fim ;

public:
        CListaDeProdutos(void);
        ~CListaDeProdutos(void);

        void inserirItem(int codigo, string nome, string marca,int codigoTipo, double preco, int stock, int stockMinimo, int stockMaximo);
        void escreveLista(void) const;
    	void apagaItem(int codigo);
        void novoStock(int codigo, int stockMinimo, int stockMaximo);
      	void novoPVP(int codigo, double preco);

        int checkProduto(int codigo);
        int procuraProduto(int codigo);
        int procuraNomeProduto(string nome) const;
        bool verificaProduto(int codigoproduto);
        int retornacodigoproduto();
        void escreveProdutoItensVenda(int codigo);

        void lerFicheiro(void);
        bool filaVazia(void) const { return (inicio == NULL ); }
    
};

//------------------- Lista de vendas----------------------------------
class CListaVendas{
   CNoListaVenda *inicio, *fim;

public:
        CListaVendas(void);
        ~CListaVendas(void);

    //penso que so seja necessario um ou 2 metodos, sendo quem um deles e so para mostar os dados da venda
        void inserirVenda(int codigoVenda, string data, int numvendas, double precovenda);
        int criacodigovenda();
        void inserirNovaVenda(int codigovenda, string data, int numelems, double preco);
        //void escreveListaVendas(void) const;
        void escreveLista(void) const;
       // void operator + (const CListaVendas &);


        void lerFicheiro(void);
        bool filaVazia(void) const { return (inicio == NULL ); }
      
};

//-------------------- lista de itens vendidos ---------------------------
class CListaItemVenda{

    CNoListaItemVenda *inicio, *fim;

public:
        CListaItemVenda(void);
        ~CListaItemVenda(void);

    //penso que so seja necessario um ou 2 metodos, sendo quem um deles e so para mostar os dados da venda
        void inserirListaVenda (int codigovenda, int codigoproduto, int quantidade, double total);
        void escreveListaVenda(void);
        // int  fatura(int codigo);//nao deu certo
        // void soma(int m);
        bool verificaItemProduto(int codigoproduto);
        void listaVendaGlobal(CListaDeProdutos &, CListaVendas &);
        void listaVendaProduto( int codigoproduto, CListaVendas &, CListaDeProdutos &);
        int procuraDataVenda(CListaVendas &) const;
        void lerFicheiro();
        bool filaVazia(void) const { return (inicio == NULL ); }

};


//----------------------lista de fornecedores ----------------------
class CListaFornecedores{
    CNoFornecedores *inicio, *fim;

public:
    CListaFornecedores(void);
    ~CListaFornecedores(void);

     void inserirFornecedor (int codigoFornecedor,string nome, string morada, string telefone);
     void escreveListaFornecedor(void) const;
     void apagaFornecedor(int codigoFornecedor);
     bool comparaFornecedor(int codigoFornecedor);
     void lerFicheiro();


     //CNoFornecedores *seguinte;
};

//-------------------------------------------------------------
class CListaProdutosDisponiveisFornecedores
{
	 CNoListaProdutosDisponiveisFornecedores *inicio, * fim;
 public:
        CListaProdutosDisponiveisFornecedores(void);
        ~CListaProdutosDisponiveisFornecedores(void);

        void inserirProdutosFornecedores(int codigo, int codigofornecedor, double preco, int quantidademinima, int descontos);
        void escreveListaProdutoFornecedor(void) const;
        void apagaProdutoFornecedor(int codigo);
        void modificarProdutoFornecedor(int codigofornecedor, int codigo, double preco, int quantidademinima,double desconto);
        int checkProdutoFornecedor(int codigo);
        int checkPrecoForncedor(int codigofornecedor);

        void lerFicheiro();
        bool filaVazia(void) const { return (inicio == NULL ); }
       // CNoListaProdutosDisponiveisFornecedores *seguinte;
};
//--------------------------------------------------------------------------------------------------------------------------------
class CListaItensEncomendas
{
	CNoListaItensEncomendas *inicio, *fim;
	
	public:
        CListaItensEncomendas(void);
        ~CListaItensEncomendas(void);
		 
         void inserirItenEncomenda (int codigoEncomenda,int codigoProduto, int quantidade, int valorDesconto, double custoTotal);
         void escreveItenEncomenda(void) const;
         void apagaItenEncomenda(int codigoEncomenda);

         bool verificaEncomendaProduto(int codigoproduto);
         void lerFicheiro();
         bool filaVazia(void) const { return (inicio == NULL ); }
        //  CNoListaItensEncomendas * seguinte;
};
//--------------------------------------------------------------------------------------------------------------------------------

class CListaEncomendasFornecedores
{
	
	CNoEncomendasFornecedores*inicio, *fim;
	
	public:
	
		CListaEncomendasFornecedores(void);
		~CListaEncomendasFornecedores(void);
		
        void inserirEncomenda (int codigoEncomenda,int codigoFornecedor, string data, int hora, int numeroItens, double custo, bool recebido, string dataRec);
		void escreveEncomenda(void) const;
        void apagaEncomenda(int codigoEncomenda);
		void lerFicheiro();
        int  verifica(int codigoEncomenda);
};


#endif
