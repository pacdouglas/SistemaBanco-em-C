/***********************************************************
* Nome Aluno: Douglas Martins		RA:41045922854 *
* Data: 28/05/2013									*
* Resumo do problema: Trabalho02 - Controle bancário *
************************************************************/
#include <iostream.h>
#include <conio.h>
#include <locale.h>
#include <iomanip>

//Banner
void tela(){
cout<<" ##############################################################################\n";     
cout<<" #                   ___                         _____  __  ___               #\n";
cout<<" #                  / __\\ __ _ _ __   ___ ___   /__   \\/__\\/ __\\              #\n";
cout<<" #                 /__\\/// _` | '_ \\ / __/ _ \\    / /\\/_\\ / /                 #\n";
cout<<" #                / \\/  \\ (_| | | | | (_| (_) |  / / //__/ /___               #\n";
cout<<" #                \\_____/\\__,_|_| |_|\\___\\___/   \\/  \\__/\\____/               #\n";
cout<<" ##############################################################################\n";   
} 

//Variaveis Globais
int i, j, k, cod_conta[50], opc=0, qtd_contas=0, escolha, cont=1, verificar, senha, codigo;
float saldo[50], deposito, saque, total=0;

//Inserir contas
void inserir_contas(){
escolha=0;
system("cls");
tela();
cout<<"\n  Digite a quantidade de contas que deseja inserir no momento: ";
cin>>escolha;
verificar=qtd_contas+escolha;
while(verificar>50){
                   cout<<"\n\n    Quantidade de contas maior que a permitida.";
                   cout<<"\n\n      Esse programa permite no máximo 50 contas e já possui "<<qtd_contas<<" contas.";
                   cout<<"\n\n        Tente novamente: ";
                   cin>>escolha;
                   verificar=0;
                   verificar=qtd_contas+escolha;
                   system("cls");
                   tela();
}                                            
      for(i=0;i<escolha;i++){
      cout<<"\n\n Digite o código para a "<<cont<<"ª conta: ";
      cin>>cod_conta[qtd_contas];
      while(cod_conta[qtd_contas]<=0){
                                  cout<<"\n Não é permitido códigos nulos ou negativos.";
                                  cout<<"\n  Tente novamente: ";
                                  cin>>cod_conta[qtd_contas];
                    }
      if(qtd_contas!=0){
                        k=qtd_contas;                       
                        for(j=0;j<k;j++){                        
                                         while(cod_conta[k]==cod_conta[j]){
                                                                           cout<<"\n Ops! Código de conta já existente.";
                                                                           cout<<"\n  Digite outro código: ";
                                                                           cin>>cod_conta[qtd_contas];
                                                                           j=0;
                                         }
                                                                         
                        }                     
      }
      cout<<"\n Digite o saldo para a "<<cont<<"ª conta: R$";
      cin>>saldo[qtd_contas];                             
      cont++;      
      system("cls");
      tela(); 
      cout<<" \n\n\n\n      Parabéns! Conta criada com sucesso.";
      cout<<"\n                 Código da conta: "<<cod_conta[qtd_contas];
      cout<<"\n                 Saldo  da conta: R$"<<saldo[qtd_contas];
      cout<<"\n\n\n\n      Pressione ENTER para continuar.";
      qtd_contas++;
      getch();
      system("cls");
      tela();
      }
}
main(){       
//Personalização de Cor
system("color 17");

//Configurando Idioma e casas decimais
setlocale(LC_ALL, "Portuguese"); 
cout.precision(2);
cout << setiosflags (ios::fixed);
tela();

//Cabeçalho Inicial    
cout<<"\n\n\n\n       Bem vindo ao sistema de controle bancário do Banco Tec.";
cout<<" \n\n                        1 - Escolha uma senha de gerente para inserir contas.";   
cout<<" \n                                      (Sua senha deve conter apenas números.)";
cout<<" \n                        2 - Insira o código referente a conta.";         
cout<<" \n                        3 - Insira o valor do saldo do correntista.";
cout<<" \n\n\n\n                                   Pressione ENTER para começar.";
getch();
cout<<" \n\n\n\n                 Escolha uma senha de gerente: ";
cin>>senha;

//Chamar a Função uma vez
inserir_contas();

//Menu Principal
do{
system("cls");
tela();
cout<<"\n\n                                 Menu Principal";
cout<<"\n\n\n\n\n 1 - Efetuar depósito                                  2 - Efetuar Saque";
cout<<"\n\n\n\n 3 - Consultar o Ativo Bancário                        4 - Finalizar o sistema";
cout<<"\n\n\n\n\n\n Para inserir novas contas digite sua senha de gerente.                     ";
cin>>opc;
         if(opc==senha)
         inserir_contas();
         if(opc==1){
                    system("cls");
                    tela();
                    cout<<"\n\n                                 Depósitos\n\n";
                    cout<<"\n  Insira o código da conta para efetuar o deposito: ";
                    cin>>codigo;
                    while(codigo<=0){
                                  cout<<"\n Não existem códigos nulos ou negativos.";
                                  cout<<"\n  Tente novamente: ";
                                  cin>>codigo;
                    }
                    j=0;
                    for(i=0;i<qtd_contas;i++){
                                              if(codigo==cod_conta[i]){
                                                                          cout<<"\n Olá cliente "<<cod_conta[i];
                                                                          cout<<"\n Seu saldo é de: R$"<<saldo[i];
                                                                          cout<<"\n\n  Insira o valor a ser depositado: R$";
                                                                          cin>>deposito;                                                                          
                                                                          while(deposito<=0){
                                                                                             cout<<"\n  Não é possivel depositar valores negativos ou nulos.";
                                                                                             cout<<"\n  Tente novamente: ";
                                                                                             cin>>deposito;
                                                                          }
                                                                          saldo[i]=saldo[i]+deposito;
                                                                          cout<<"\n\n Agora seu saldo é de: R$"<<saldo[i]<<"\n\n  Pressione ENTER para voltar ao menu.";
                                                                          getch();
                                                                          j=0;
                                                                          codigo=0;                                                                        
                                                                          }
                    }
                  if(j!=codigo){
                                cout<<"\n\n Código não encontrado!"<<"\n    Pressione ENTER";
                                getch();
                  }                                                                 
         }
         if(opc==2){
                    system("cls");
                    tela();
                    cout<<"\n\n                                   Saques\n\n";
                    cout<<"\n  Insira o código da conta para efetuar o saque: ";
                    cin>>codigo;
                    while(codigo<=0){
                                  cout<<"\n Não existem códigos nulos ou negativos.";
                                  cout<<"\n  Tente novamente: ";
                                  cin>>codigo;
                    }
                    j=0;
                    for(i=0;i<qtd_contas;i++){
                                              if(codigo==cod_conta[i]){
                                                                          cout<<"\n Olá cliente "<<cod_conta[i];
                                                                          cout<<"\n Seu saldo é de: R$"<<saldo[i];
                                                                          cout<<"\n\n  Insira o valor a ser sacado: R$";
                                                                          cin>>saque;                                                                          
                                                                          while(saque>saldo[i]){
                                                                                             cout<<"\n  Saldo Insuficiente.";
                                                                                             cout<<"\n   Tente novamente: ";
                                                                                             cin>>saque;
                                                                          }
                                                                          saldo[i]=saldo[i]-saque;
                                                                          cout<<"\n\n Agora seu saldo é de: R$"<<saldo[i]<<"\n\n  Pressione ENTER para voltar ao menu.";
                                                                          getch();
                                                                          j=0;
                                                                          codigo=0;                                                                        
                                                                          }
                    }
                  if(j!=codigo){
                                cout<<"\n\n Código não encontrado!"<<"\n    Pressione ENTER";
                                getch();
                  }
                                                                          
         }
         if(opc==3){
                    system("cls");
                    tela();
                    cout<<"\n\n                                 Ativo Bancário\n\n";
                    cout<<"\n\n\n  Ativo bancário do banco TEC: R$";
                    for(i=0;i<qtd_contas;i++)
                    total=total+saldo[i];
                    cout<<total;
                    cout<<"\n\n\n             Pressione ENTER para continuar";
                    getch();
                    total=0; 
         }     
}
while(opc!=4);
}                       

