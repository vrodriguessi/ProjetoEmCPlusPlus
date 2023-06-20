// Matriz Curricular - Manipula matriz curricular presente em um arquivo binário
// Desenvolvido pelo Grupo 23: Guilherme Alexandre Cunha Silva, Lilian Carla de Freitas, Verônica Rodrigues da Silva França

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//##################################################################################################################

struct componente
{
  int periodo;
  string codigo;
  string nome;
  char tipo;
  int cargaTeorica;
  int cargaPratica;
  int cargaExtensao;
  float cargaRelogio;
};

//##################################################################################################################

void leitura(ifstream &entrada, componente vetor[], int tam)
{
   //procedimento para ler os dados do arquivo em um vetor descartando em lixo as "," entre um dado e outro de cada linha
  char lixo;
  for (int i = 0; i < tam; i++)
  {
    entrada >> vetor[i].periodo;
    entrada >> lixo;
    getline(entrada, vetor[i].codigo,',');
    getline(entrada, vetor[i].nome, ',');
    entrada >> vetor[i].tipo;
    entrada >> lixo;
    entrada >> vetor[i].cargaTeorica;
    entrada >> lixo;
    entrada >> vetor[i].cargaPratica;
    entrada >> lixo;
    entrada >> vetor[i].cargaExtensao;
    entrada >> lixo;
    entrada >> vetor[i].cargaRelogio;
    entrada.ignore();
  }
  vetor[tam-1].codigo = " "; //A última opção terá sempre como código " "
}

//##################################################################################################################


void mostrartudo (componente vetor[], int t){
//procedimento para listar todos os componentes do que recebeu os dados do arquivo  
	cout<<"Pressione Enter para rolar o arquivo para baixo"<<endl;
  for (int a = 0; a < t; a++)
    {
     if (vetor[a].codigo != " ") // na última posição do vetor temos o código espaço em branco 
     { 
      cout<<"***************************************************************************"<<endl;
      cout << "Periodo: " << vetor[a].periodo << endl;
      cout << "Código: " << vetor[a].codigo << endl;
      cout << "Nome do curso: " << vetor[a].nome << endl;
      cout << "Tipo: " << vetor[a].tipo << endl;
      cout << "Carga teórica: " << vetor[a].cargaTeorica << endl;
      cout << "Carga prática: " << vetor[a].cargaPratica << endl;
      cout << "Carga extensão: " << vetor[a].cargaExtensao << endl;
      cout << "Carga relógio: " << vetor[a].cargaRelogio << endl;
      cout<<"***************************************************************************"<<endl; 
      if (a%4 == 0) //a cada 4 exibições de componentes curriculares o usuário deverá apertar enter
        cin.ignore();
    }
  }
}

//##################################################################################################################

void mostrarperiodo (componente vetor[], int t){
//procedimento para listar os componentes curriculares de um período informado pelo usuário  
  int periodo=-1;
  bool correto = false;
  while (correto == false) //repete até que o usuário digite um valor válido para período
  {
  cout<<"Informe um número entre 0 e 8 referente ao período que deseja visualizar: "<<endl;
  cin>>periodo;
  if (periodo<0 or periodo>8)
  {
    cout<<endl<<"***************************************************************************"<< endl;
    cout<<"Informe um valor válido para período (entre 0 e 8)!"<<endl;
    cout<<endl<<"***************************************************************************"<< endl;
  }
  else
  {
  correto = true;  
  for (int a = 0; a < t; a++)
    {
     if (vetor[a].periodo == periodo) // na última posição do vetor temos o código espaço em branco 
     { 
      cout<<endl<<"***************************************************************************"<< endl;
      cout << "Periodo: " << vetor[a].periodo << endl;
      cout << "Código: " << vetor[a].codigo << endl;
      cout << "Nome do curso: " << vetor[a].nome << endl;
      cout << "Tipo: " << vetor[a].tipo << endl;
      cout << "Carga teórica: " << vetor[a].cargaTeorica << endl;
      cout << "Carga prática: " << vetor[a].cargaPratica << endl;
      cout << "Carga extensão: " << vetor[a].cargaExtensao << endl;
      cout << "Carga relógio: " << vetor[a].cargaRelogio << endl;
      cout<<"***************************************************************************"<< endl; 
      if (a%4 == 0) //a cada 4 exibições de componentes curriculares o usuário deverá apertar enter
        cin.ignore();
    }
   }
  }
 }
}

//##################################################################################################################

void procuranome (componente vetor[], int t){
//procedimento de buscar por nome do componente curricular 
    string nomeProcurado;
    cout<<"Digite o nome do componente curricular desejado: "<<endl;
    getline(cin, nomeProcurado);
    //esta parte ainda precisa ser tratata em relação a letras maiúsculas e minúsculas, vígulas, acentos e caracteres especiais

    int cont = 0;
    bool achou = false;

    while (cont < t and !achou)
    {
      if (nomeProcurado == vetor[cont].nome)
      {
        achou = true;
      }
      else
      {
        cont++;
      }
    }
    if (achou)
    {
      cout<<endl<<"***************************************************************************"<< endl;
      cout << "Periodo: " << vetor[cont].periodo << endl;
      cout << "Código: " << vetor[cont].codigo << endl;
      cout << "Nome do componente: " << vetor[cont].nome << endl;
      cout << "Tipo: " << vetor[cont].tipo << endl;
      cout << "Carga teórica: " << vetor[cont].cargaTeorica << endl;
      cout << "Carga prática: " << vetor[cont].cargaPratica << endl;
      cout << "Carga extensão: " << vetor[cont].cargaExtensao << endl;
      cout << "Carga relógio: " << vetor[cont].cargaRelogio << endl;
      cout<<endl<<"***************************************************************************"<< endl;
    }
    else
    {
      cout << "Componente não encontrado" << endl;
      cout<<endl<<"***************************************************************************"<< endl;
    }
  }

 //################################################################################################################## 

void buscaDocodigo (componente vetor[], int t){
//procedimento de busca pelo código do componente curricular  
    string codigoProcurado;
    cout<<"Digite o código do curso desejado: "<<endl;
    getline(cin, codigoProcurado);
    
    int cont = 0;
    bool achou = false;

    while (cont < t and !achou)
    {
      if (codigoProcurado == vetor[cont].codigo)
      {
        achou = true;
      }
      else
      {
        cont++;
      }
    }
    if (achou)
    {
      cout<<endl<<"***************************************************************************"<< endl;
      cout << "Periodo: " << vetor[cont].periodo << endl;
      cout << "Código: " << vetor[cont].codigo << endl;
      cout << "Nome do curso: " << vetor[cont].nome << endl;
      cout << "Tipo: " << vetor[cont].tipo << endl;
      cout << "Carga teórica: " << vetor[cont].cargaTeorica << endl;
      cout << "Carga prática: " << vetor[cont].cargaPratica << endl;
      cout << "Carga extensão: " << vetor[cont].cargaExtensao << endl;
      cout << "Carga relógio: " << vetor[cont].cargaRelogio << endl;
      cout<<endl<<"***************************************************************************"<< endl;
    }
    else
    {
      cout << "Componente não encontrado" << endl;
      cout<<endl<<"***************************************************************************"<< endl;
    }
  }

  
//##################################################################################################################

bool buscaadicionarComponente(componente vetor[], int &t,string codigoadicionar, int &cont) {
//verifica a existência de um determinado componente pelo seu código 

    bool achou = false;
   
    while (cont < t and !achou)
    {
      if (codigoadicionar == vetor[cont].codigo)
      {
        achou = true;
        cout<<endl<<"***************************************************************************"<< endl;
        cout<<"O componente curricular já está cadastrado!"<<endl;
        cout<<endl<<"***************************************************************************"<< endl;
      }
      else
      {
        cont++;
      }
    }
  return achou;
}

//##################################################################################################################

void editar(ifstream &arquivo, componente vetor[], int t){
//procedimento que permite a edição de dados a partir do código do componente currucular que deve ser alterado  

    string editado;
    bool repete = true;
    cout<<"Digite o código do componente a ser editado: "<<endl;
    getline(cin, editado);

    int cont = 0;
    if (buscaadicionarComponente(vetor, t, editado, cont) == true)
    {   
      int edicao;
      
      
      while (repete == true) {
         cout<<endl<<"***************************************************************************"<< endl;
         cout<<"Qual será a edição?"<<endl<<endl;

         cout<<"1 - Periodo"<<endl<<"2 - Código"<<endl<<"3 - Nome"<<endl;
         cout<<"4 - Tipo"<<endl<<"5 - Carga teorica"<<endl<<"6 - Carga prática"<<endl;
         cout<<"7 - Carga extensão"<<endl<<"8 - Carga relógio"<<endl;
         cout<<"0 - Sair"<<endl;
        cin>>edicao;
        cin.ignore();
        
        if(edicao<0 or edicao>8){
          cout<<"O valor deve representar uma operação"<<endl;
          cout<<endl<<"***************************************************************************"<< endl;
          return;
        }
        else 
        if (edicao == 0)
        {
          repete = false;
        }
        else
        {
          int periodoNovo;
          string novoCodigo;
          string nomeNovo;
    
          switch (edicao)
          {
          case 1:
                  cout<<"Digite o novo periodo: "<<endl;
                  cin>>periodoNovo;
                  cin.ignore();
                  vetor[cont].periodo=periodoNovo;
          break;
        
          case 2:
                  cout<<"Digite o novo codigo e aperte Enter duas vezes: "<<endl;
                  getline(cin, novoCodigo);
                  cin.ignore();
                  vetor[cont].codigo=novoCodigo;
                  break;

          case 3:
                  cout<<"Digite o novo nome e aperte Enter duas vezes:  "<<endl;
                  getline(cin, nomeNovo);
                  cin.ignore();
                  vetor[cont].nome=nomeNovo;
                  break;
          case 4:
                  cout<<"Digite o novo tipo: "<<endl;
                  cin>>vetor[cont].tipo;
                  break;
          case 5:
                  cout<<"Digite a nova carga teorica: "<<endl;
                  cin>>vetor[cont].cargaTeorica;
                  break;
          case 6:
                  cout<<"Digite a nova carga horaria prática: "<<endl;
                  cin>>vetor[cont].cargaPratica;
                  break;
          case 7:
                  cout<<"Digite a nova carga horario de extensão: "<<endl;
                  cin>>vetor[cont].cargaExtensao;
                  break;
          case 8:
                  cout<<"Digite a nova carga horaria relogio: "<<endl;
                  cin>>vetor[cont].cargaRelogio;
                  break;
          default:
          break;
        }

    //escrevendo os dados alterados no arquivo  
    ofstream arquivo("matriz.csv");
    if (!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }
    else
    {
      for (int i = 0; i < t; i++){
        arquivo << vetor[i].periodo << ",";
        arquivo << vetor[i].codigo << ",";
        arquivo << vetor[i].nome << ",";
        arquivo << vetor[i].tipo << ",";
        arquivo << vetor[i].cargaTeorica << ",";
        arquivo << vetor[i].cargaPratica << ",";
        arquivo << vetor[i].cargaExtensao << ",";
        arquivo << vetor[i].cargaRelogio << endl;
      }
    
      arquivo.close();
      cout<<endl<<"***************************************************************************"<< endl;  
      cout << "Edição realizada com sucesso." << endl;
      cout<<endl<<"***************************************************************************"<< endl;
    
    }
    }
    }
    }
    else
    {
      cout<<endl<<"***************************************************************************"<< endl;
      cout<<"Não foi possível encontrar o componente curricular desejado"<<endl;
      cout<<endl<<"***************************************************************************"<< endl;
    }
}

//##################################################################################################################

void adicionarComponente(ifstream &arquivo, componente vetor[], int &t) {
//procedimento para adicionar novo componente curricular no arquivo 

    string codigoadicionar;
    cout<<"Informe o código do componente que você deseja adicionar: "<<endl;
    cin>>codigoadicionar;
    cin.ignore();
    int cont=0;

    if (buscaadicionarComponente(vetor, t, codigoadicionar, cont) == false)
    {
      componente novocomponente;
      novocomponente.codigo = codigoadicionar;
      cout << "Digite o nome do componente curricular: ";
      getline(cin, novocomponente.nome);
      cout << "Tipo: ";
      cin >> novocomponente.tipo;
      cin.ignore();
      cout << "Período: ";
      cin >> novocomponente.periodo;
      cin.ignore();     
      cout << "Carga teórica: ";
      cin >> novocomponente.cargaTeorica;
      cin.ignore();
      cout << "Carga prática: ";
      cin >> novocomponente.cargaPratica;
      cin.ignore();
      cout << "Carga extensão: ";
      cin >> novocomponente.cargaExtensao;
      cin.ignore();
      cout << "Carga relógio: ";
      cin >> novocomponente.cargaRelogio;
      cin.ignore();

      componente armazenamentonovo[t+1];
        for (int i=0; i<t; i++)
          armazenamentonovo[i] = vetor[i];

      armazenamentonovo[t] = novocomponente;
      
       ofstream arquivo("matriz.csv");
       if (!arquivo.is_open()) {
            cout<<endl<<"***************************************************************************"<< endl;
            cout<<"Erro ao abrir o arquivo"<< endl;
            cout<<endl<<"***************************************************************************"<< endl;
            return;
        }
        else
        {
          t++;  
          for (int i = 0; i < t; i++){
              if (armazenamentonovo[i].codigo != " ")
              {
                  arquivo << armazenamentonovo[i].periodo << ",";
                  arquivo << armazenamentonovo[i].codigo << ",";
                  arquivo << armazenamentonovo[i].nome << ",";
                  arquivo << armazenamentonovo[i].tipo << ",";
                  arquivo << armazenamentonovo[i].cargaTeorica << ",";
                  arquivo << armazenamentonovo[i].cargaPratica << ",";
                  arquivo << armazenamentonovo[i].cargaExtensao << ",";
                  arquivo << armazenamentonovo[i].cargaRelogio << endl;
              }
          }     
        }
    
        arquivo.close();
        cout<<endl<<"***************************************************************************"<< endl;
        cout << "Componente adiocionado com sucesso." << endl;
        cout<<endl<<"***************************************************************************"<< endl;
      
}
else
{
        cout<<endl<<"***************************************************************************"<< endl;
        cout << "O componente já está cadastrado" << endl;
        cout<<endl<<"***************************************************************************"<< endl;
}
}

//##################################################################################################################

void Remove_componente(ifstream &arquivo, componente vetor[], int &t) {
	//procedimento para remover um componente da matriz curricular
    int cont = 0, op_menu = 3;
    string excluir;
    cout<<"Informe o código do componente curricular que deverá ser removido: " <<endl;
    getline(cin, excluir);
    bool achou = false, repetir = true;
    while (cont < t and !achou)
    {
      if (excluir == vetor[cont].codigo)
      {
        achou = true;
      }
      else
      {
        cont++;
      }
    }     
  if (achou == false) {
    cout<<"Não foi possível encontrar o componente curricular desejado"<<endl;
  }  
  else {
    cout<<"Deseja realmente excluir o componente curricular: "<<endl;
    cout<<"Período: "<<vetor[cont].periodo<<endl
        <<"Código: "<<vetor[cont].codigo<<endl
        <<"Nome: "<<vetor[cont].nome<<endl
        <<"Tipo: "<<vetor[cont].tipo<<endl
        <<"CH Teórica: "<<vetor[cont].cargaTeorica<<endl
        <<"CH Prática: "<<vetor[cont].cargaPratica<<endl
        <<"CH Extensão: "<<vetor[cont].cargaExtensao<<endl
        <<"CH Relógio: "<<vetor[cont].cargaRelogio;
        cout<<endl<<"***************************************************************************"<< endl;
      
        do
        {    
            cout<<"Digite 1 para remover o componente ou 9 para voltar ao menu principal"<<endl; 
            cin>>op_menu;
            if (op_menu == 1)
            {
              repetir = false;
              while (cont < t-1)
              {
                vetor[cont] = vetor[cont+1];
                cont++;
              }
              vetor[t-1].codigo = " ";
              t--;
                    
              ofstream arquivo("matriz.csv");
              
              if (!arquivo.is_open()){
                  cout << "Erro ao abrir o arquivo." << endl;
                  return;
              }
              else
              {
                for (int i = 0; i < t; i++){
                  if (vetor[i].codigo != " ")
                  {
                    arquivo << vetor[i].periodo << ",";
                    arquivo << vetor[i].codigo << ",";
                    arquivo << vetor[i].nome << ",";
                    arquivo << vetor[i].tipo << ",";
                    arquivo << vetor[i].cargaTeorica << ",";
                    arquivo << vetor[i].cargaPratica << ",";
                    arquivo << vetor[i].cargaExtensao << ",";
                    arquivo << vetor[i].cargaRelogio << endl;
                  }
                }     
              
                arquivo.close();
                cout<<endl<<"***************************************************************************"<< endl;
                cout << "Exclusão realizada com sucesso." << endl;
                cout<<endl<<"***************************************************************************"<< endl;
              }
            }  
            else
             if(op_menu == 9 ){
                repetir = false;
             }
             else  
             {
                cout<<endl<<"***************************************************************************"<< endl;              
                cout<<"O valor informado deve corresponder a uma das operações"<<endl; 
                cout<<endl<<"***************************************************************************"<< endl;
             }   
    
    } while (repetir == true);
  }
}

//##################################################################################################################

int main()
{
  int operacao;
  do
  {
  
    cout<<"Bem vindo(a) ao sistema da matriz curricular, escolha a operação desejada: "<<endl;
    cout<<"1 - Exibir toda a matriz"<<endl;
    cout<<"2 - Exibir os componentes de um período"<<endl;
    cout<<"3 - Buscar pelo nome do curso"<<endl;
    cout<<"4 - Buscar pelo código do curso"<< endl;
    cout<<"5 - Adicionar um novo curso à matriz"<<endl;
    cout<<"6 - Remover um curso da matriz"<<endl;
    cout<<"7 - Editar um curso da matriz"<<endl;
    cout<<"0 - Sair"<<endl;
    
    cin>>operacao;
    cin.ignore();

    if (operacao != 0)
    {
      if(operacao<1 or operacao>7){
        cout<<"O velor informado deve corresponder a uma das operações"<<endl;
        return 0;
      }
      else
      {
        ifstream matriz_csv("matriz.csv");
        if (!matriz_csv)
            cout << "Erro na leitura do arquivo. \n";
        else
        {
          //descobrindo o tamanho do arquivo
          int t=1;
          string contar;
          while(getline(matriz_csv,contar)){
             t++;
          }
          
          //realocar o ponteiro para o começo do arquivo
          matriz_csv.clear();
          matriz_csv.seekg(0, ios::beg);
          componente armazenamento[t];
          leitura(matriz_csv, armazenamento, t);

          
          switch (operacao)
          {
          case 1:
                  mostrartudo(armazenamento, t);
                  break;
          case 2:
                  mostrarperiodo(armazenamento, t);
                  break;        
          case 3:
                  procuranome(armazenamento, t);
                  break;
          case 4:
                  buscaDocodigo(armazenamento, t);
                  break;
          case 5:
                  adicionarComponente(matriz_csv, armazenamento, t);
                  break;
          case 6: 
                  Remove_componente(matriz_csv,armazenamento, t);
                  break;
          case 7:
                  editar(matriz_csv, armazenamento, t);
                  break;
          default:
          break;
          }
        }
        matriz_csv.close();
      }
    }
  }
  while (operacao != 0);
  
  return 0;
}

//##################################################################################################################
