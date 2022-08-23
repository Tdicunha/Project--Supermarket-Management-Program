#include <iostream>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <ctime>
#include <limits>


#include "CListaHeader.h"

#include "CListaTiposProdutos.cpp"
#include "CListaProdutos.cpp"
#include "CListaVenda.cpp"
#include "CListaItemVenda.cpp"
#include "CListaFornecedores.cpp"
#include "CListaProdutosDisponiveisFornecedores.cpp"
#include "CListaEncomendasFornecedores.cpp"
#include "CListaItensEncomendas.cpp"

using namespace std;

// struct para utilizar a data
struct tm;

//===================================================================================================================
//-------------------------MAIN---------------------------------------------------------------------------------------
int main()
{

    //struct para utilizar a data
    struct tm {
        int tm_sec;   // segundos de um minuto do 0 ao 61
        int tm_min;   // minutos de uma hora do 0 ao 59
        int tm_hour;  // horas de um dia do 0 ao 24
        int tm_mday;  // dia do mes, do 1 ao 31
        int tm_mon;   // mes do ano, 1 ao 12
        int tm_year;  // ano
        int tm_wday;  // dia a partir de domingo
        int tm_yday;  // numero de dias a partir do dia 1 de janeiro
        int tm_isdst; // horas de luz no dia
    };

    int n0,n1,n2,n3,n4,n41,n5,n6,n7,n8;
    char n9;

    float IVA;
    int codigo, codigoFornecedor, preco,numelems,quantidadeMinima;
    double descontos;
    int codigoTipo, stock, stockMinimo,stockMaximo;
    int codigoEncomenda;
    string marca,nome,tipo,morada,telefone;



    CListaTiposProdutos listaTiposProdutos;
    CListaDeProdutos listaProduto;
    CListaVendas listaVenda, aux;
    CListaItemVenda listaItemVenda;
    CListaFornecedores listaFornecedores;
    CListaProdutosDisponiveisFornecedores listaProdutosFornecedores;
    CListaItensEncomendas listaItensEncomendas;
    CListaEncomendasFornecedores listaEncomendasFornecedores;

    //ler ficheiros
    listaProduto.lerFicheiro();
    listaTiposProdutos.lerFicheiro();
    listaProdutosFornecedores.lerFicheiro();
    listaFornecedores.lerFicheiro();
    listaVenda.lerFicheiro();

    // data e horas atuais segundo o sistema
    time_t agora = time(0);

    // converter o "agora" para uma string
    char *dt = ctime(&agora);

    //==============================================================================================
    // -------------------------------- HUD MENU PRINCIPAL ----------------------------------------
MenuPrincipal:
    {
        system("cls"); //apaga tudo o que esta na linha de comandos

        //limpar as variaveis todas
        descontos=0; n0=0; n1=0; n2=0; n3=0; n4=0; n41=0; n5=0; n6=0; n7=0; n8=0;
        codigo=0; codigoFornecedor=0; preco=0;numelems=0;quantidadeMinima=0;
        codigoTipo=0; stock=0; stockMinimo=0;stockMaximo=0;


        time_t agora = time(0);
        dt = ctime(&agora);

        do{
            system("cls");
            fflush(stdin);

            time_t agora = time(0);
            dt = ctime(&agora);

            cout << "Data: " << dt << endl<<endl; //mostra a data

            cout<<"                                     _ _ _ _ _ _ _ _ _                                      \n";
            cout<<"                                    / _*_*_*_*_*_*_*_  \\                                   \n";
            cout<<"                                   /*/                \\*\\                                 \n";
            cout<<"                                  /*/    Bem Vindo     \\*\\                                \n";
            cout<<"                                 /*/        ao          \\*\\                               \n";
            cout<<"              __________________/*/   Super Manager 2.0  \\*\\__________________            \n";
            cout<<"             \\****************\\____________________________/ **************** /           \n";
            cout<<"              \\     1)Tipos de Produtos       5)Reposicao automatica de stoks /            \n";
            cout<<"               \\    2)Produtos                6)Rececao de encomenda         /             \n";
            cout<<"                \\   3)Venda                   7)Inventario                  /              \n";
            cout<<"                 \\  4)Fornecedores e Produtos 8)Faturacao                  /               \n";
            cout<<"                  \\ disponiveis para compra   9)Sair                      /                \n";
            cout<<"                   \\                                                     /                 \n";
            cout<<"                    \\___________________________________________________/                  \n";
            cout<<endl;
            cout<<"Insira uma opcao: ";

            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> n0;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }

        } while(n0!=1 && n0!=2 && n0!=3 && n0!=4 && n0!=5 && n0!=6 && n0!=7 && n0!=8 && n0!=9 && n0!=10); //repete o menu principal ate o valor introduzido for igual as opções
        fflush(stdin);

    }

    //===================================================================================================================
    // ---------------------------------  MENU PRINCIPAL      -----------------------------------
    switch (n0) {

    case 1: //Tipos de produtos
        system("cls");
        fflush(stdin);
        do{
            system("cls");

            cout<<"Tipos de Produtos: "<< endl<<endl;
            cout<<"1) Inserir Tipos de Produtos"<<endl;
            cout<<"2) Modificar Taxa IVA" <<endl;
            cout<<"3) Apagar"<<endl;
            cout<<"4) Sair"<<endl<<endl;
            cout<< "Insira a opcao: ";

            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> n1;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);
        }while(n1!=1 && n1!=2 && n1!=3 && n1!=4);
        fflush(stdin);
        break;

    case 2: //Produtos
        system("cls");
        fflush(stdin);

        do{
            system("cls");

            cout<<"Produtos: "<< endl<<endl;
            cout<<"1) Inserir Produtos"<<endl;
            cout<<"2) Modificar PVP" <<endl;
            cout<<"3) Modificar o nivel de stock(minimo/maximo)"<<endl;
            cout<<"4) Apagar Produtos"<<endl;
            cout<<"5) Sair"<<endl<<endl;
            cout<< "Insira a opcao: ";

            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar

                cin >> n2;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);
        }while(n2!=1 && n2!=2 && n2!=3 && n2!=4 && n2!=5);
        fflush(stdin);
        break;

    case 3: //Venda
        system("cls");
        fflush(stdin);

        do{
            system("cls");

            cout<<"Venda: "<< endl<<endl;
            cout<<"1) Sair"<<endl;
            cout<<"2) Vender"<<endl<<endl;
            cout<<"Insira a opcao: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar

                cin >> n3;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);
        }while(n3!=1 && n3!=2);
        fflush(stdin);
        break;


    case 4: //Fornecedores e Produtos disponiveis para compra
        system("cls");
        fflush(stdin);

        do{
            system("cls");

            cout<<"Fornecedores e Produtos disponiveis para compra: "<< endl<<endl;
            cout<<"1) Inserir Fornecedor"<<endl;
            cout<<"2) Apagar Fornecedor"<<endl;
            cout<<"3) Gerir Fornecedores"<<endl;
            cout<<"4) Sair"<<endl<<endl;
            cout<<"Insira a opcao: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar

                cin >> n4;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);
        }while(n4!=1 && n4!=2 && n4!=3 && n4!= 4);
        fflush(stdin);
        break;

    case 5: //Reposição automatica se stoks
        system("cls");
        fflush(stdin);

        do{
            system("cls");

            cout<<"Reposicao automatica se stocks: "<< endl<<endl;
            cout<<"1) Reporsicao total"<<endl;
            cout<<"2) Reporsicao parcial"<<endl;
            cout<<"3) Sair"<<endl<<endl;
            cout<<"Insira a opcao: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> n5;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
        }while(n5!=1 && n5!=2 && n5!=3);
        fflush(stdin);

        break;

    case 6: //Rececao de encomenda
        system("cls");
        fflush(stdin);

        do{
            system("cls");
            cout<<"Rececao de encomenda: "<< endl<<endl;
            cout<<"1) Registar rececao de encomenda"<<endl;
            cout<<"2) Sair"<<endl<<endl;
            cout<<"Insira a opcao: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> n6;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
        }while(n6!=1 && n6!=2);
        fflush(stdin);

        break;


    case 7:  //Inventario // FEITO
        system("cls");
        fflush(stdin);

        do{
            system("cls");
            cout<<"Inventario"<<endl<<endl;
            cout<<"1) Inventario Global"<<endl;
            cout<<"2) Pequisa por nome de produto "<<endl;
            cout<<"3) Sair"<<endl<<endl;;
            cout<<"Insira uma opcao: ";
            while(1){
                cin >> n7;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);
        }while(n7!=1 && n7!=2 && n7!=3);
        fflush(stdin);
        break;

    case 8: //Faturação // tem erro, executa a venda e depois é que mostra a lista de vendas
        system ("cls");
        fflush(stdin);

        do{
            system("cls");

            cout<<"Menu de Faturacao: "<< endl<<endl;
            cout<<"1) Por data"<<endl;
            cout<<"2) Por produto"<<endl;
            cout<<"3) Global"<<endl;
            cout<<"4) Sair"<<endl<<endl;
            cout<<"Insira a opcao: ";

            while(1){
                cin >> n8;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

        }while(n8!=1 && n8!=2 && n8!= 3 && n8!= 4);
        fflush(stdin);
        break;

    case 9: //Sair do programa // FEITO
        system("cls");
        fflush(stdin);


        do{
            system("cls");
            cout<<"Menu de Sair: "<< endl<<endl;
            cout<<"Deseja sair? (Y/N) : ";
            cin>>n9;
        }while(n9!='Y' && n9!='N' && n9 != 'n' && n9 != 'y');

        if (n9 == 'Y' || n9=='y') {
            cout<<"Programa Encerrado"<<endl;
            cout<<"Alexandre Marques(2018306089) Telmo Cunha(2018308321)"<<endl;

        }
        else {
            goto MenuPrincipal;
        }

        break;

    default: cout<<"ERROR:#n0"<<endl;
    }


    //==================================================================================================´~
    // --------------- TIPOS DE PRODUTOS ----------------------------------------------------------------------

    switch(n1){
    case 1: // Inserir tipos de produtos //--- FEITO -----
        system("cls");
        fflush(stdin);

        char z;

        do{
            system("cls");
            cout<<"Insirir Tipo de Produto"<<endl<<endl;
            cout<<"Insira o tipo: ";
            getline(cin,tipo);
            fflush(stdin);

            codigo = listaTiposProdutos.retornaCodigoTipoProduto();

            cout<<"Insira a taxa de IVA: ";
            while(1){
                cin>>IVA;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            listaTiposProdutos.inserirTipo(tipo,codigo,IVA);
            listaTiposProdutos.escreveListaTipoProduto();

            cout<<"Lista atualizada com o novo tipo de produto"<<endl;

            cout<<endl;
            cout<<"Deseja inserir mais produtos?(Y/N): ";
            cin>>z;

        }while(z=='N' || z=='n');
        fflush(stdin);

        goto MenuPrincipal;


    case 2: //modificar taxa de iva //--- FEITO -----
        system("cls");
        fflush(stdin);

        do{
            system("cls");

            listaTiposProdutos.escreveListaTipoProduto();
            cout<<endl<<endl;

            cout<<"Insira o codigo do produto: ";

            while(1){
                cin>>codigo;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            cout<<"Nova Taxa de IVA(%): ";
            while(1){
                cin>>IVA;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            listaTiposProdutos.novoIVA(codigo, IVA);    //altera o IVA do produto com o codigo introduzido
            cout<<endl;
            cout<<"Nova lista atualizada"<<endl;
            listaTiposProdutos.escreveListaTipoProduto();            //mostra a nova lista com o preco alterado

            cout<<"Deseja Sair?(Y/N) ";
            cin>>z;

        }while(z=='N' || z=='n');
        fflush(stdin);
        cin.clear();
        goto MenuPrincipal;


    case 3: // apagar tipo de produto

        system("cls");
        fflush(stdin);


        cout<< "Apagar tipos de produtos"<<endl<<endl;
        listaTiposProdutos.escreveListaTipoProduto();
        cout<<endl<<endl;

        cout<<"Insira o codigo do produto: ";
        while(1){
            cin>>codigo;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
            // verifica se o codigo corresponde a um produto da lista de produtos
        }
        fflush(stdin);

        bool tem;
        tem=listaProduto.verificaProduto(codigo);

        if(tem== false) {
            listaTiposProdutos.apagaTipoProduto(codigo);     //apaga o produto com o codigo introduzido
            listaTiposProdutos.escreveListaTipoProduto();   //mostra a nova fila com o produto apagado
        }
        else
            cout<<"Produto existente na lista de venda, nao pode eliminar"<<endl<<endl;
        cout<<"Deseja Sair?(Y/N) ";
        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');
        goto MenuPrincipal;                 //volta ao menu principal
        break;


    case 4:   //sair  //--- FEITO -----
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;                 //volta ao menu principal
        break;


    default: cout<<"ERROR:#n1"<<endl;
    }

    //=================================================================================================
    //-------------------------------------  PRODUTOS  -----------------------------------------------
    switch(n2) {
    case 1: // Inserir Produtos //--- FEITO -----
        char z;
        system("cls");
        fflush(stdin);


        cout<<"Inserir Produto"<<endl<<endl;

        do{
            fflush(stdin);

            codigo = listaProduto.retornacodigoproduto();

            cout<<"Insira o nome: ";
            getline(cin,nome);
            fflush(stdin);

            cout<<"Insira a marca: ";
            getline(cin,marca);
            fflush(stdin);

            cout<<"Insira o codigo do tipo: ";
            while(1){
                cin>>codigoTipo;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            cout<<"Insira o preco: ";
            while(1){
                cin>>preco;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            cout<<"Insira o stock atual: ";
            while(1){
                cin>>stock;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            cout<<"Insira o stock Minimo: ";
            while(1){
                cin>>stockMinimo;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            cout<<"Insira o stock Maximo: ";
            while(1){
                cin>>stockMaximo;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            listaProduto.inserirItem(codigo,nome,marca,codigoTipo,preco,stock,stockMinimo,stockMaximo);
            cout<<"Deseja Sair?(Y/N)";
            cin>>z;

        }while(z =='N' || z=='n');

        do{
            cout<<"Lista atualizada com o novo produto"<<endl;
            listaProduto.escreveLista();
        }while(z=='N' || z=='n');
        fflush(stdin);
        goto MenuPrincipal;


    case 2: //Modificar PVP        //--- FEITO -----


        system("cls");
        fflush(stdin);

        listaProduto.escreveLista();
        cout<<endl;
        cout<<"Insira o codigo do produto:";
        cin>>codigo;
        cout<<"Novo preco: ";
        cin>>preco;
        listaProduto.novoPVP(codigo, preco);    //altera o preco do produto com o codigo introduzido
        listaProduto.escreveLista();      //mostra a nova lista com o preco alterado

        cout<<endl;

        cout << "Deseja Sair?(Y/N) ";
        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');
        fflush(stdin);
        goto MenuPrincipal;
        break;

    case 3:
        system("cls");
        fflush(stdin);

        listaProduto.escreveLista();
        cout<<endl;

        cout<<"Insira o codigo do produto:";
        cin>>codigo;

        cout<<"Novo stock Minimo: ";
        cin>>stockMinimo;

        cout<<"Novo stock Maximo: ";
        cin>>stockMaximo;

        //listaProduto.    //altera o preco do produto com o codigo introduzido
        listaProduto.escreveLista();      //mostra a nova lista com o preco alterado

        cout<<endl;

        cout << "Deseja Sair?(Y/N) ";
        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');
        fflush(stdin);
        goto MenuPrincipal;
        break;

    case 4: // Apagar Produto // FEITO

        system("cls");
        fflush(stdin);

        cout<< "Apagar Produtos"<<endl<<endl;
        cout<<"Insira o codigo do produto: ";
        cin>>codigo;

        bool existe, existe1;
        existe=listaItemVenda.verificaItemProduto( codigo);
        existe1=listaItensEncomendas.verificaEncomendaProduto(codigo);

        if(existe == false && existe1== false) {
            listaProduto.apagaItem(codigo);     //apaga o produto com o codigo introduzido
            listaProduto.escreveLista();        //mostra a nova fila com o produto apagado
        }
        else
            cout<<"Nao se pode eliminar este produto"<<endl<<endl;

        cout << "Deseja Sair?(Y/N) ";

        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');

        fflush(stdin);
        goto MenuPrincipal;
        break;//volta ao menu principal

    case 5: // Sair para o menu principal // -----FEITO -------------

        system("cls");
        fflush(stdin);

        goto MenuPrincipal;                 //volta ao menu principal
        break;


    default: cout<<"ERROR:#n2"<<endl;
    }

    //================================================================================================================
    // -------------------------   VENDA --------------------------------------------------- (cena pra comprar cenas)
    switch(n3) {
    case 1: // sair para o menu principal //------ FEITO ----------
        char z;
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;


    case 2: //comprar cenas
        system("cls");
        fflush(stdin);

        listaProduto.escreveLista();
        cout<<endl;
        //mostra o inventario de produtos disponiveis para compra

        do{
            cout<<"Insira o codigo dos produtos que pretende comprar e respetiva quantidade"<<endl;
            cout<<"Codigo: ";
            cin>>codigo;
            cout<<"Quantidade: ";
            cin>>numelems;
            //---------------------------------------------------------
            int preco1=listaProduto.procuraProduto(codigo);
            int cvenda= aux.criacodigovenda();
            preco1=preco1*numelems;//preco total do produto
            listaItemVenda.inserirListaVenda(cvenda,codigo,numelems,preco1);
            listaVenda.escreveLista();
            //---------------------------------------------------------
            cout<<endl<<endl;

            cout<<"Pretende finalizar a compra?(Y/N) : ";
            cin>>z;
        }while (z=='N' || z=='n');
        fflush(stdin);

        goto MenuPrincipal;
        break;

    default: cout<<"ERROR:#n3"<<endl;
    }

    //=======================================================================================================================
    //------------------------------- FORNECEDORES E PRODUTOS DISPONIVEIS PARA COMPRA ---------------------------------------
    switch(n4){
    case 1://Inserir fornecedor
        system("cls");
        fflush(stdin);

        char z;
        cout<<"Inserir Fornecedor"<<endl<<endl;
        do{
            cout<<"Codigo de Fornecedor: ";

            while(1){
                cin>>codigoFornecedor;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            cout<<"Nome de Fornecedor: ";
            getline(cin,nome);
            fflush(stdin);

            cout<<"Morada: ";
            getline(cin, morada);
            fflush(stdin);

            while(1){
                cout<<"Telefone: ";
                getline(cin,telefone);
                if (sizeof(telefone)!=9)break;
                cin.clear();
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            fflush(stdin);

            listaFornecedores.inserirFornecedor(codigoFornecedor,nome,morada,telefone);
            listaFornecedores.escreveListaFornecedor();

            cout<<"Deseja voltar ao menu principal?(Y/N): ";
            cin>>z;

        }while(z=='N' || z=='n');
        fflush(stdin);

        goto MenuPrincipal;
        break;

    case 2: // apagar fornecedor

        system("cls");
        fflush(stdin);

        cout<<"Apagar Fornecedor"<<endl<<endl;

        listaFornecedores.escreveListaFornecedor();
        cout<<endl;

        cout<<"Codigo de Fornecedor: ";
        while(1){
            cin>>codigoFornecedor;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }
        fflush(stdin);

        listaFornecedores.apagaFornecedor(codigoFornecedor);
        listaFornecedores.escreveListaFornecedor();

        cout << "Deseja Sair?(Y/N) ";

        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');

        fflush(stdin);
        goto MenuPrincipal;
        break;


    case 3: // gerir fornecedor
        system("cls");
        fflush(stdin);

        do{
            system("cls");

            cout<<"Produtos disponiveis em cada fornecedor: "<<endl<<endl;
            cout<<"1) Inserir"<<endl;
            cout<<"2) Modificar"<<endl;
            cout<<"3) Apagar"<<endl;
            cout<<"4) Sair"<<endl<<endl;
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> n41;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
        }while(n41!=1 && n41!=2 && n41!= 3 && n41!= 4);
        fflush(stdin);
        break;


    case 4: //sair
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;
        break;


    default:cout<<"ERROR:#n4"<<endl;

    }

    switch(n41){ //produtos disponiveis em cada fornecedor
    case 1: //inserir
        system("cls");
        fflush(stdin);

        char z;
        do{
            cout<<"Inserir codigo produto: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> codigo;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }

            cout<<"Inserir codigo fornecedor: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> codigoFornecedor;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }

            cout<<"Inserir preco: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> preco;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }

            cout<<"Inserir quantidade minima: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> quantidadeMinima;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }

            cout<<"Inserir preco: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> preco;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }

            cout<<"Inserir descontos: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> descontos;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            listaProdutosFornecedores.inserirProdutosFornecedores(codigo,codigoFornecedor,preco,quantidadeMinima,descontos);
            listaProdutosFornecedores.escreveListaProdutoFornecedor();

            cout<<"Deseja Sair?(Y/N): ";
            cin>>z;

        }while(z=='N'||z=='n');

        goto MenuPrincipal;


    case 2: //modificar
        system("cls");
        fflush(stdin);

        cout<<"Modificar Produtos Disponiveis dos Fornecedores"<<endl<<endl;

        listaProdutosFornecedores.escreveListaProdutoFornecedor();

        cout<<endl;

        cout<<"Inserir codigo do fornecedor: ";
        while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
            cin >> codigoFornecedor;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }

        cout<<"Inserir codigo do produto: ";
        while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
            cin >> codigo;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }

        cout<<"Inserir preco: ";
        while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
            cin >> preco;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }

        cout<<"Inserir quantidade Minima: ";
        while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
            cin >> quantidadeMinima;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }

        cout<<"Inserir desconto: ";
        while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
            cin >> descontos;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }

        listaProdutosFornecedores.modificarProdutoFornecedor(codigoFornecedor,codigo,preco,quantidadeMinima,descontos);
        listaProdutosFornecedores.escreveListaProdutoFornecedor();

        cout << "Deseja Sair?(Y/N) ";

        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');

        fflush(stdin);
        goto MenuPrincipal;


    case 3://apagar
        system("cls");
        fflush(stdin);

        listaProdutosFornecedores.escreveListaProdutoFornecedor();

        do{
            cout<<"Inserir codigo produto: ";
            while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
                cin >> codigo;
                if (!cin.fail())break;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"INVALIDO"<<endl;
                cout<<"Tente Novamente: ";
            }
            cout<<"Deseja Sair(Y/N): ";
            cin>>z;
            listaProdutosFornecedores.apagaProdutoFornecedor(codigo);

        }while(z=='N' || z=='n');

        goto MenuPrincipal;
        break;


    case 4:
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;

    default:cout<<"ERROR:#n41"<<endl;
    }

    //================================================================================================
    //--------------------REPOSIÇÃO AUTOMATICA DE STOCK-----------------------------------------------
    switch(n5){
    case 1: //reposição total
        system("cls");
        fflush(stdin);
        cout<<"Reposicao Total de Stock"<<endl;


        //int codigoProduto = listaProduto.procuraProdutoFalta();
        //cout<<endl<<endl;
        // cout<<"Produtos com pouco Stock: "<<endl;
        //listaProduto.checkProduto(codigoProduto);


        //cout<<endl;
        //cout<<"Fornecedores: "<<endl;
        //listaFornecedores.escreveListaFornecedor();
        //cout<<endl<<endl;


        //cout<<"Inserir codigo de fornecedor: ";
        //while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
        //    cin >> codigoFornecedor;
        //    if (!cin.fail())break;
        //    cin.clear();
        //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //    cout<<"INVALIDO"<<endl;
        //    cout<<"Tente Novamente: ";
        //}

        //listaEncomendasFornecedores.inserirEncomenda(codigoProduto,codigoFornecedor,stock,stockMaximo);
        //int precoTotal;
        //precoTotal=(stockMaximo-stock)*preco;

        goto MenuPrincipal;


    case 2: // reposição parcial
        system("cls");
        fflush(stdin);
        cout<<"Reposicao Parcial de Stock"<<endl;

        goto MenuPrincipal;

    case 3: //sair
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;


    default:cout<<"ERROR:#n5"<<endl;
    }

    //========================================================================================
    //----------------------- RECEÇÃO DE ENCOMENDA ---------------------------------------------
    switch(n6){
    case 1: //registar receção de encomenda
        system("cls");
        fflush(stdin);

        cout<<"Registar rececao de encomenda"<<endl<<endl;
        cout<<"Inserir codigo atribuido a encomenda: ";
        while(1){ // ciclo para impedir serem inseridas letras e o programa crashar
            cin >> codigoEncomenda;
            if (!cin.fail())break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"INVALIDO"<<endl;
            cout<<"Tente Novamente: ";
        }



        break;

    case 2: //sair
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;
        break;

    default:cout<<"ERROR:#n6"<<endl;
    }

    //========================================================================================
    //------------------------------ >INVENTARIO ---------------------------------------------
    switch(n7) {
    case 1: //inventario global
        system("cls");
        fflush(stdin);

        char z;
        system("cls");


        cout<<"Inventario Global"<<endl<<endl;
        do{
            listaProduto.escreveLista();
            cout<<"Pressione Y para voltar ao menu principal"<<endl;
            cin>>z;
        }while (z == 'N' || z == 'y');
        fflush(stdin);
        goto MenuPrincipal;
        break;


    case 2: //inventario parcial
        system("cls");
        fflush(stdin);


        cout << "Inventario Parcial" << endl << endl;
        cout << "Insira o nome do produto: ";
        getline(cin,nome);
        fflush(stdin);

        int indice;
        indice = listaProduto.procuraNomeProduto(nome);

        while(indice == -1){
            system("cls");
            cout << "Inventario Parcial" << endl << endl;
            cout << "Produto nao existente" << endl << endl;
            cout << "Tente novamente: ";
            getline(cin, nome);
            fflush(stdin);
            indice = listaProduto.procuraNomeProduto(nome);
        }
        if(indice == -2){
            break;
        }

        cout << endl;
        listaProduto.checkProduto(indice);

        cout<<endl;
        cout << "Deseja Sair?(Y/N) ";

        do{
            cin.clear();
            fflush(stdin);
            cin>>z;
        }while(z=='N' || z=='n');

        fflush(stdin);
        goto MenuPrincipal;


    case 3 ://sair
        goto MenuPrincipal;

    default: cout<<"ERROR:#n7"<<endl;

    }

    //=====================================================================================
    //------------------------------FATURAÇÃO---------------------------------------------

    switch(n9) {

    case 1://por data
        system("cls");
        fflush(stdin);


        cout<<"Introduza a data:"<<endl;
        //cin>>....;
        //cena para verfificar se a data existe
        //chamar a func para mostrar o que foi vendido nessa data
        break;

    case 2://por produto
        system("cls");
                fflush(stdin);
                int codigoproduto;
                char z;
                cout<<"introduza o codigo do produto:"<<endl;
                cin>> codigoproduto;
                bool tem;
                listaProduto.verificaProduto(codigoproduto);
                if(tem==true)
                {
                    listaItemVenda.listaVendaProduto(codigoproduto, listaVenda,listaProduto);
                }
                else
                cout<<"Produto nao existe"<<endl;
                cout << "Deseja Sair?(Y/N) ";

                do{
                    cin.clear();
                    fflush(stdin);
                    cin>>z;
                }while(z=='N' || z=='n');
                //mostra a quantidade do produto que foi vendido, como o preoduto em si
                break;

    case 3://global
        listaItemVenda.listaVendaGlobal(listaProduto,listaVenda);
         cout << "Deseja Sair?(Y/N) ";
               do{
                   cin.clear();
                   fflush(stdin);
                   cin>>z;
               }while(z=='N' || z=='n');
               system("cls");
               fflush(stdin);


               break;
    case 4:
        system("cls");
        fflush(stdin);

        goto MenuPrincipal;

    default: cout<<"ERROR:#n9"<<endl;
    }

    return (0);
}
