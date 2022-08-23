#include <iostream>
#include <cstring>
#include <sstream>

//include para utilizar delay
#include <chrono>
#include <thread>

#include <ctime>

#include <limits>


#include "CListaHeader.h"
#include "CListaProdutos.cpp"
#include "CListaVenda.cpp"
//#include "CListaItemVenda.cpp"

using namespace std;

// para utilizar o delay
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


// struct para utilizar a data
struct tm;

// --------------------------------------------- MENUS ----------------------------------------------------
//---------------------------------------------------------------------------------------------------------
int MenuProdutos(int *n)
{
    do{
        system("cls");

        cout<<"Menu de Produtos: "<< endl<<endl;
        cout<<"1) Inserir Produtos"<<endl;
        cout<<"2) Modificar PVP" <<endl;
        cout<<"3) Apagar Produtos"<<endl;
        cout<<"4) Sair"<<endl<<endl;
        cout<< "Insira a opcao: ";
        cin>>*n;
        fflush(stdin);
    }while(*n!=1 && *n!=2 && *n!=3 && *n!=4);
    return *n;
}

//--------------------------------------------------------------------
int MenuVenda (int *n2)
{
    do{
        system("cls");

        cout<<"Menu de Venda: "<< endl<<endl;
        cout<<"1) Sair"<<endl;
        cout<<"2) Pretende Comprar?"<<endl<<endl;
        cout<<"Insira a opcao: ";
        cin>>*n2;
        fflush(stdin);

    }while(*n2!=1 && *n2!=2);
    return *n2;
}
//--------------------------------------------------------------------
int MenuFaturacao(int *n6)
{
	do{
        system("cls");

        cout<<"Menu de Faturacao: "<< endl<<endl;
        cout<<"1) Por data"<<endl;
        cout<<"2) Por produto"<<endl;
        cout<<"3) Global"<<endl<<endl;
        cout<<"Insira a opcao: ";
        cin>>*n2;
        fflush(stdin);

    }while(*n6!=1 && *n6!=2);
    return *n6;
}
	

//--------------------------------------------------------------------
void MenuSair(char letra)
{
    do{
        system("cls");

        cout<<"Menu de Sair: "<< endl<<endl;
        cout<<"Deseja sair? (Y/N): ";
        cin>>letra;
        fflush(stdin);

    }while(letra!='Y' && letra!='N');

    if (letra == 'Y') {
        cout<<"Programa Encerrado"<<endl;
        cout<<"Alexandre Marques(2018306089) Telmo Cunha(2018308321)"<<endl;

        // parecido ao delay utilizado em arduino
        sleep_for(seconds(1));
        sleep_until(system_clock::now() + seconds(1));
     }

    // se carregar no N vai para o menu principal

}

//-------------------------------------------------------------------MAIN------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

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

    int n0,n1,n2;
    char n5;

    int codigo, preco,numelems;
    string marca,nome,tipo;

    CListaDeProdutos listaProduto;
    CListaVendas listaVenda, aux;
    //CListaItemVenda listaItemVenda;


    // data e horas atuais segundo o sistema
    time_t agora = time(0);

    // converter o "agora" para uma string
    char* dt = ctime(&agora);

    //inicializar a lista com alguns produtos
    listaProduto.inserirItem(1,"Ryzen 2600","AMD","CPU",120);
    listaProduto.inserirItem(2,"GTX 1070 ti oc","MSI","GPU",400);
    listaProduto.inserirItem(3,"8gb 3200 MHz","ADATA XPG","RAM",60);
    listaProduto.inserirItem(4,"B450 F Gaming","Asus Strix","Motherboard",130);
    listaProduto.inserirItem(5,"Cloud Alpha","HyperX","Headset",100);
    listaProduto.inserirItem(6,"Kraken Pro 2015","Razer","Headset",80);
    listaProduto.inserirItem(7,"Mi 2 Lite","Xiaomi","SmartPhone",180);
    listaProduto.inserirItem(8,"P30","Huawei","SmartPhone",450);
    listaProduto.inserirItem(9,"CyberPunk 2077","Project RED","Gaming",60);
    listaProduto.inserirItem(10,"Doom Eternal","Bethesda","Gaming",50);
    listaProduto.inserirItem(11,"Counter-Strike: Global Offensive","Valve","Gaming",0);




// -------------------------------- MENU PRINCIPAL --------------------------------
    MenuPrincipal:
    {
          system("cls"); //apaga tudo o que esta na linha de comandos

        do{
            system("cls");
            cout << "Data: " << dt << endl<<endl; //mostra a data

            cout<<"                              _ _ _ _ _ _ _ _ _                         \n";
            cout<<"                             / _*_*_*_*_*_*_*_  \\                       \n";
            cout<<"                            /*/                \\*\\                      \n";
            cout<<"                           /*/    Bem Vindo     \\*\\                     \n";
            cout<<"                          /*/        ao          \\*\\                    \n";
            cout<<"              ___________/*/     Super Manager    \\*\\____________    \n";
            cout<<"             \\*************\\_____________________/ **************/        \n";
            cout<<"              \\                   1)Produtos                    /          \n";
            cout<<"               \\                  2)Venda                      /          \n";
            cout<<"                \\                 3)Inventario                /          \n";
            cout<<"                 \\                4)Faturacao                /          \n";
            cout<<"                  \\               5)Sair                    /          \n";
            cout<<"                   \\_______________________________________/        \n";
            cout<<endl;
            cout<<"Insira uma opcao: ";



            // ciclo para impedir serem inseridas letras e o programa crashar
            while(1){

                 cin >> n0;
                 if (!cin.fail())break;
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 cout<<"INVALIDO"<<endl;
                 cout<<"Tente Novamente: ";
            }

        } while(n0!=1 && n0!=2 && n0!=3 && n0!=4 && n0!=5); //repete o menu principal ate o valor introduzido for igual as opções

    }


 // ---------------------------------  ciclo switch para o MENU PRINCIPAL      -----------------------------------
    switch (n0)
    {
        case 1: MenuProdutos(&n1);break;

        case 2: MenuVenda(&n2);break;

        case 3:  //Inventario // FEITO
            system("cls");
            cout<<"Inventario"<<endl<<endl;
            cout<<"1)Inventario Global"<<endl;
            cout<<"2)Pequisa por codigo de Produto "<<endl;
            cout<<"3) Sair"<<endl<<endl;;
            cout<<"Insira uma opcao: ";
            int z;
            do{
                while(1){

                     cin >> z;
                     if (!cin.fail())break;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     cout<<"INVALIDO"<<endl;
                     cout<<"Tente Novamente: ";
                }
            }while(z!=1 && z!=2 && z!=3);

            //switch para o inventario global ou pesquisa por produto
            switch(z){
            case 1:
                listaProduto.escreveLista();
                cout<<"Dentro de momentos voltara ao menu principal"<<endl;
                sleep_for(seconds(5));
                sleep_until(system_clock::now() + seconds(1));
                goto MenuPrincipal;

             case 2:
                cout<<"Insira o codigo do Produto: ";
                cin>>codigo;
                listaProduto.checkProduto(codigo);
                cout<<"Dentro de momentos voltara ao menu principal"<<endl;
                sleep_for(seconds(5));
                sleep_until(system_clock::now() + seconds(1));
                goto MenuPrincipal;

             case 3 : goto MenuPrincipal;
            }

            listaProduto.escreveLista();

            cout<<endl;
            cout<<"Voltar ao Menu Principal (Y): ";

            char k; cin>>k;
            if (k == 'Y' || k=='y') goto MenuPrincipal;
            else break;

        case 4: //Faturação // tem erro, executa a venda e depois é que mostra a lista de vendas
            system ("cls");
            fflush(stdin);
            //MenuFaturacao(&n6);break;

            listaVenda.escreveLista();

            cout<<"Dentro de momentos voltara ao menu principal"<<endl;
            sleep_for(seconds(5));
            sleep_until(system_clock::now() + seconds(1));
            goto MenuPrincipal;



        case 5: //Sair do programa // FEITO

            do{
                system("cls");
                cout<<"Menu de Sair: "<< endl<<endl;
                cout<<"Deseja sair? (Y/N) : ";
                cin>>n5;
                fflush(stdin);
            }while(n5!='Y' && n5!='N' && n5 != 'n' && n5 != 'y');

            if (n5 == 'Y') {
                cout<<"Programa Encerrado"<<endl;
                cout<<"Alexandre Marques(2018306089) Telmo Cunha(2018308321)"<<endl;

                // parecido ao delay utilizado em arduino

                sleep_for(seconds(1));
                sleep_until(system_clock::now() + seconds(1));

                return 0;
             }
             else goto MenuPrincipal;           //volta ao menu principal

        default: cout<<"Invalido"<<endl;
    }

//-------------------------------------  ciclo switch para o menu dos produtos  ---------------
    switch(n1)
    {
    case 1: // Inserir Produtos // FEITO

        system("cls");

        cout<<"Insirir Produto"<<endl<<endl;
        cout<<"Insira o codigo: ";

        while(1){
            cin>>codigo;
             if (!cin.fail())break;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             cout<<"INVALIDO"<<endl;
             cout<<"Tente Novamente: ";
             fflush(stdin);
        }

        fflush(stdin);

        cout<<"Insira o nome: ";
        getline(cin,nome);
        fflush(stdin);

        cout<<"Insira a marca: ";
        getline(cin,marca);
        fflush(stdin);

        cout<<"Insira o tipo: ";
        getline(cin,tipo);
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

        listaProduto.inserirItem(codigo,nome,marca,tipo,preco);

        cout<<"Lista atualizada com o novo produto"<<endl;
        listaProduto.escreveLista();
        cout<<"Dentro de momentos voltara ao menu principal" <<endl;
        sleep_for(seconds(5));
        sleep_until(system_clock::now() + seconds(1));
        goto MenuPrincipal;


    case 2: //Modificar PVP                         // FEITO

        system("cls");

            listaProduto.escreveLista();
            cout<<"Insira o codigo do produto:";
            cin>>codigo;
            cout<<"Novo preco: ";
            cin>>preco;
            listaProduto.novoPVP(codigo, preco);    //altera o preco do produto com o codigo introduzido
            listaProduto.escreveLista();            //mostra a nova lista com o preco alterado

         cout<<"Dentro de momentos voltara ao menu principal"<<endl;
         sleep_for(seconds(5));
         sleep_until(system_clock::now() + seconds(1));
         goto MenuPrincipal;

    case 3: // Apagar Produto // FEITO

        system("cls");
        cout<< "Apagar Produtos"<<endl<<endl;
        cout<<"Insira o codigo do produto: ";
        cin>>codigo;
        listaProduto.apagaItem(codigo);     //apaga o produto com o codigo introduzido
        listaProduto.escreveLista();        //mostra a nova fila com o produto apagado
        cout<<"Dentro de momentos voltara ao menu principal"<<endl;
        sleep_for(seconds(5));              //delay de 5 segundo
        sleep_until(system_clock::now() + seconds(1));
        goto MenuPrincipal;                 //volta ao menu principal

    case 4: // Sair para o menu principal

        system("cls");
        goto MenuPrincipal;                 //volta ao menu principal

    default: cout<<"Invalido"<<endl;
  }

// -------------------------  ciclo switch para o MENU VENDAS ---------------------------- (cena pra comprar cenas)
   switch(n2)
   {
        case 1: // sair para o menu principal
            system("cls");
            goto MenuPrincipal;

        case 2: //comprar cenas
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
                 listaVenda.inserirVenda(cvenda,codigo, dt,numelems,preco1);
                 listaVenda.escreveLista();
                 //---------------------------------------------------------
           }while (codigo == NULL && numelems == NULL);
            
            cout<<"Pretende finalizar a compra?(Y) : ";
            char s; cin>>s;

            if (s =='Y' || s== 'y'){
                system ("cls");
                goto MenuPrincipal;
            }


      // default: cout<<"Invalido"<<endl;
   }
//---------------------------------------------------------------------------
// ciclo para a faturacao
/*switch(n6)
 {
	 case 1:
	        cout<<"Introduza a data:"
	        cin>>....;
	        //cena para verfificar se a data existe
	        //chamar a func para mostrar o que foi vendido nessa data
	 case 2:
	        out<<"introduza o codigo do produto:"<<endl;
	        cin>>....;
	        //algo para verificar se o codigo esta correto
	        //mostra a quantidade do produto que foi vendido, como o preoduto em si
	case 3:
	//simplesmente mosta tudo
}
 */
    return (0);
}
