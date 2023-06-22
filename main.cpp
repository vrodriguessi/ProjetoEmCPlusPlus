#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct componente{
  int periodo;
  string codigo;
  string nome;
  char tipo;
  int cargaTeorica;
  int cargaPratica;
  int cargaExtensao;
  float cargaRelogio;
};

void vizualizarTudo(componente *entrada, int tam){
  int indice = 0;
  cout << "Pressione Enter para descer na rolagem" << endl;
  while (indice < tam)
  {
    cout << "Periodo: " << entrada[indice].periodo << endl;
    cout << "Código: " << entrada[indice].codigo << endl;
    cout << "Nome: " << entrada[indice].nome << endl;
    cout << "Tipo: " << entrada[indice].tipo << endl;
    cout << "Carga teorica: " << entrada[indice].cargaTeorica << endl;
    cout << "Carga prática: " << entrada[indice].cargaPratica << endl;
    cout << "Carga extensão: " << entrada[indice].cargaExtensao << endl;
    cout << "Carga relógio: " << entrada[indice].cargaRelogio << endl;
    cout << "=========================================================" << endl;
    if (indice % 4 == 0) // a cada 4 exibições de componentes curriculares o usuário deverá apertar enter
      cin.ignore();
    indice++;
  }
}

void mostrarperiodo(componente *entrada, int t){
  // procedimento para listar os componentes curriculares de um período informado pelo usuário
  int periodo = -1;
  bool correto = false;
  while (correto == false) // repete até que o usuário digite um valor válido para período
  {
    cout << "Informe um número entre 0 e 8 referente ao período que deseja visualizar: " << endl;
    cin >> periodo;
    if (periodo < 0 or periodo > 8)
    {
      cout << endl
           << "============================================================================" << endl;
      cout << "Informe um valor válido para período (entre 0 e 8)!" << endl;
      cout << endl
           << "============================================================================" << endl;
    }
    else
    {
      correto = true;
      for (int a = 0; a < t; a++)
      {
        if (entrada[a].periodo == periodo) // na última posição do vetor temos o código espaço em branco
        {
          cout << endl;
          cout << "Periodo: " << entrada[a].periodo << endl;
          cout << "Código: " << entrada[a].codigo << endl;
          cout << "Nome do curso: " << entrada[a].nome << endl;
          cout << "Tipo: " << entrada[a].tipo << endl;
          cout << "Carga teórica: " << entrada[a].cargaTeorica << endl;
          cout << "Carga prática: " << entrada[a].cargaPratica << endl;
          cout << "Carga extensão: " << entrada[a].cargaExtensao << endl;
          cout << "Carga relógio: " << entrada[a].cargaRelogio << endl;
          cout << endl
               << "============================================================================" << endl;
          if (a % 4 == 0) // a cada 4 exibições de componentes curriculares o usuário deverá apertar enter
            cin.ignore();
        }
      }
    }
  }
}

void buscaDocodigo(componente *entrada, int t){
  // procedimento de busca pelo código do componente curricular
  cout << "Digite o código do curso desejado: " << endl;
  int posicao;
  string codigoProcurado;
  int* ponteiroPosicao = NULL;
  cin.ignore();
  getline(cin, codigoProcurado);
  int index=0;
  while((index<t) and (ponteiroPosicao==NULL)){
    if(entrada[index].codigo == codigoProcurado){
      posicao=index;
      ponteiroPosicao= &posicao;
    }
    else
    index++;
  }
  if (ponteiroPosicao != NULL)
  {
    cout << endl
         << "===========================================================================" << endl;
    cout << "Periodo: " << entrada[index].periodo << endl;
    cout << "Código: " << entrada[index].codigo << endl;
    cout << "Nome do curso: " << entrada[index].nome << endl;
    cout << "Tipo: " << entrada[index].tipo << endl;
    cout << "Carga teórica: " << entrada[index].cargaTeorica << endl;
    cout << "Carga prática: " << entrada[index].cargaPratica << endl;
    cout << "Carga extensão: " << entrada[index].cargaExtensao << endl;
    cout << "Carga relógio: " << entrada[index].cargaRelogio << endl;
    cout << endl
         << "===========================================================================" << endl;
  }
  else
  {
    cout << "Componente não encontrado" << endl;
    cout << endl
         << "===========================================================================" << endl;
  }
}

void procuranome (componente* entrada, int t){
//procedimento de buscar por nome do componente curricular 
    string nomeProcurado;
    cout<<"Digite o nome do componente curricular desejado: "<<endl;
    cin.ignore();
    getline(cin, nomeProcurado);
    //esta parte ainda precisa ser tratata em relação a letras maiúsculas e minúsculas, vígulas, acentos e caracteres especiais

    int contador = 0;
    bool achou = false;

    while (contador < t and !achou)
    {
      if (nomeProcurado == entrada[contador].nome)
      {
        achou = true;
      }
      else
      {
        contador++;
      }
    }
    if (achou)
    {
      cout<<endl<<"==========================================================================="<< endl;
      cout << "Periodo: " << entrada[contador].periodo << endl;
      cout << "Código: " << entrada[contador].codigo << endl;
      cout << "Nome do componente: " << entrada[contador].nome << endl;
      cout << "Tipo: " << entrada[contador].tipo << endl;
      cout << "Carga teórica: " << entrada[contador].cargaTeorica << endl;
      cout << "Carga prática: " << entrada[contador].cargaPratica << endl;
      cout << "Carga extensão: " << entrada[contador].cargaExtensao << endl;
      cout << "Carga relógio: " << entrada[contador].cargaRelogio << endl;
      cout<<endl<<"==========================================================================="<< endl;
    }
    else
    {
      cout << "Componente não encontrado" << endl;
      cout<<endl<<"==========================================================================="<< endl;
    }
  }

bool buscaadicionarComponente(componente* entrada, int t,string codigoadicionar, int &cont) {
//verifica a existência de um determinado componente pelo seu código 

    bool achou = false;
   
    while (cont < t and !achou)
    {
      if (codigoadicionar == entrada[cont].codigo)
      {
        achou = true;
        cout<<endl<<"==========================================================================="<< endl;
        cout<<"O componente curricular já está cadastrado!"<<endl;
        cout<<endl<<"==========================================================================="<< endl;
      }
      else
      {
        cont++;
      }
    }
  return achou;
}

void adicionarComponente(componente* entrada, int t, int capaz) {
    // Procedimento para adicionar novo componente curricular no arquivo

    string codigoadicionar;
    cout << "Informe o código do componente que você deseja adicionar: " << endl;
    cin.ignore();
    cin >> codigoadicionar;
    cin.ignore();
    int cont = 0;

    if (buscaadicionarComponente(entrada, t, codigoadicionar, cont) == false) {
        if (t == capaz) {
            componente* novoComponente = new componente[capaz + 8];
            copy(entrada, entrada+capaz, novoComponente);
            delete[] entrada;
            capaz += 8;
            entrada = novoComponente;
        }

        // Criar uma nova variável para armazenar o componente adicionado
        componente novo;
          novo.codigo=codigoadicionar;
          cout << "Digite o nome do componente curricular: " << endl;
          getline(cin, novo.nome);
          cout << "Tipo: ";
          cin >> novo.tipo;
          cin.ignore();
          cout << "Período: ";
          cin >> novo.periodo;
          cin.ignore();
          cout << "Carga teórica: ";
          cin >> novo.cargaTeorica;
          cin.ignore();
          cout << "Carga prática: ";
          cin >> novo.cargaPratica;
          cin.ignore();
          cout << "Carga extensão: ";
          cin >> novo.cargaExtensao;
          cin.ignore();
          cout << "Carga relógio: ";
          cin >> novo.cargaRelogio;
          cin.ignore();

        // Adicionar o novo componente ao array
        entrada[t] = novo;
        t++;

        ofstream arquivo("matriz.csv");
        if (!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo." << endl;
        return;
        }
        else
        {
        for (int i = 0; i < t; i++){
        arquivo << entrada[i].periodo << ",";
        arquivo << entrada[i].codigo << ",";
        arquivo << entrada[i].nome << ",";
        arquivo << entrada[i].tipo << ",";
        arquivo << entrada[i].cargaTeorica << ",";
        arquivo << entrada[i].cargaPratica << ",";
        arquivo << entrada[i].cargaExtensao << ",";
        arquivo << entrada[i].cargaRelogio << endl;
      }
    
      arquivo.close();
        cout << endl << "===========================================================================" << endl;
        cout << "Componente adicionado com sucesso." << endl;
        cout << endl << "===========================================================================" << endl;
    }
}
}

void editar(componente* entrada, int t){
//procedimento que permite a edição de dados a partir do código do componente currucular que deve ser alterado  

    string editado;
    bool repete = true;
    cout<<"Digite o código do componente a ser editado: "<<endl;
    cin.ignore();
    getline(cin, editado);

    int contar = 0;
    if (buscaadicionarComponente(entrada, t, editado, contar) == true)
    {   
      int edicao;
      
      
      while (repete == true) {
         cout<<endl<<"==========================================================================="<< endl;
         cout<<"Qual será a edição?"<<endl<<endl;

         cout<<"1 - Periodo"<<endl<<"2 - Código"<<endl<<"3 - Nome"<<endl;
         cout<<"4 - Tipo"<<endl<<"5 - Carga teorica"<<endl<<"6 - Carga prática"<<endl;
         cout<<"7 - Carga extensão"<<endl<<"8 - Carga relógio"<<endl;
         cout<<"0 - Sair"<<endl;
         cin>>edicao;
         cin.ignore();
        
        if(edicao<0 or edicao>8){
          cout<<"O valor deve representar uma operação"<<endl;
          cout<<endl<<"==========================================================================="<< endl;
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
                  entrada[contar].periodo=periodoNovo;
          break;
        
          case 2:
                  cout<<"Digite o novo codigo e aperte Enter duas vezes: "<<endl;
                  getline(cin, novoCodigo);
                  cin.ignore();
                  entrada[contar].codigo=novoCodigo;
                  break;

          case 3:
                  cout<<"Digite o novo nome e aperte Enter duas vezes:  "<<endl;
                  getline(cin, nomeNovo);
                  cin.ignore();
                  entrada[contar].nome=nomeNovo;
                  break;
          case 4:
                  cout<<"Digite o novo tipo: "<<endl;
                  cin>>entrada[contar].tipo;
                  break;
          case 5:
                  cout<<"Digite a nova carga teorica: "<<endl;
                  cin>>entrada[contar].cargaTeorica;
                  break;
          case 6:
                  cout<<"Digite a nova carga horaria prática: "<<endl;
                  cin>>entrada[contar].cargaPratica;
                  break;
          case 7:
                  cout<<"Digite a nova carga horario de extensão: "<<endl;
                  cin>>entrada[contar].cargaExtensao;
                  break;
          case 8:
                  cout<<"Digite a nova carga horaria relogio: "<<endl;
                  cin>>entrada[contar].cargaRelogio;
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
        arquivo << entrada[i].periodo << ",";
        arquivo << entrada[i].codigo << ",";
        arquivo << entrada[i].nome << ",";
        arquivo << entrada[i].tipo << ",";
        arquivo << entrada[i].cargaTeorica << ",";
        arquivo << entrada[i].cargaPratica << ",";
        arquivo << entrada[i].cargaExtensao << ",";
        arquivo << entrada[i].cargaRelogio << endl;
      }
    
      arquivo.close();
      cout<<endl<<"==========================================================================="<< endl;  
      cout << "Edição realizada com sucesso." << endl;
      cout<<endl<<"==========================================================================="<< endl;
    
    }
    }
    }
    }
    else
    {
      cout<<endl<<"==========================================================================="<< endl;
      cout<<"Não foi possível encontrar o componente curricular desejado"<<endl;
      cout<<endl<<"==========================================================================="<< endl;
    }
}

void Remove_componente(ifstream &arquivo, componente vetor[], int &t) {
	//procedimento para remover um componente da matriz curricular
    int cont = 0, op_menu = 3;
    string excluir;
    cout<<"Informe o código do componente curricular que deverá ser removido: " <<endl;
    cin.ignore();
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
        cout<<endl<<"==========================================================================="<< endl;
      
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
                cout<<endl<<"==========================================================================="<< endl;
                cout << "Exclusão realizada com sucesso." << endl;
                cout<<endl<<"==========================================================================="<< endl;
              }
            }  
            else
             if(op_menu == 9 ){
                repetir = false;
             }
             else  
             {
                cout<<endl<<"==========================================================================="<< endl;              
                cout<<"O valor informado deve corresponder a uma das operações"<<endl; 
                cout<<endl<<"==========================================================================="<< endl;
             }   
    
    } while (repetir == true);
  }
}

void chamada(int operacao){
  ifstream matriz_csv("matriz.csv");
  if (!matriz_csv)
  {
    cout << "Erro na abertura do arquivo!" << endl;
    return;
  }

  // Conta o número de linhas no arquivo
  int tamanho = 0;
  string linha;
  while (getline(matriz_csv, linha))
  {
    tamanho++;
  }
  int capacidade=tamanho+1;
  matriz_csv.clear();            // Limpa o erro do arquivo
  matriz_csv.seekg(0, ios::beg); // Volta para o início do arquivo

  componente *componenteMatriz = new componente[capacidade];
  // Lê os dados do arquivo e armazena no array de componentes
  for (int i = 0; i < tamanho; i++)
  {
    matriz_csv >> componenteMatriz[i].periodo;
    matriz_csv.ignore();
    getline(matriz_csv, componenteMatriz[i].codigo, ',');
    getline(matriz_csv, componenteMatriz[i].nome, ',');
    matriz_csv >> componenteMatriz[i].tipo;
    matriz_csv.ignore();
    matriz_csv >> componenteMatriz[i].cargaTeorica;
    matriz_csv.ignore();
    matriz_csv >> componenteMatriz[i].cargaPratica;
    matriz_csv.ignore();
    matriz_csv >> componenteMatriz[i].cargaExtensao;
    matriz_csv.ignore();
    matriz_csv >> componenteMatriz[i].cargaRelogio;
    matriz_csv.ignore();
  }

  matriz_csv.close();

  switch (operacao)
  {
  case 1:
    vizualizarTudo(componenteMatriz, tamanho);
    break;
  case 2:
    mostrarperiodo(componenteMatriz, tamanho);
    break;
  case 3:
    buscaDocodigo(componenteMatriz, tamanho);
    break;
  case 4:
    procuranome(componenteMatriz, tamanho);
    break;
  case 5:
    adicionarComponente(componenteMatriz, tamanho, capacidade);
    break;
  case 6:
    editar(componenteMatriz, tamanho);
    break;
  case 7:
   Remove_componente(matriz_csv, componenteMatriz, tamanho);
   break;
  default:
    break;
  }

  delete[] componenteMatriz;
}

int main(){
  int operacao;
  do
  {
    cout << "Bem vindo(a) ao sistema da matriz curricular, selecione a operação desejada: " << endl;
    cout << "1 - Visualizar toda a matriz curricular" << endl;
    cout << "2 - Visualizar os componentes pelo período" << endl;
    cout << "3 - Buscar um componente pelo código" << endl;
    cout << "4 - Buscar um componente pelo nome" << endl;
    cout << "5 - Adicionar um novo componente à matriz" << endl;
    cout << "6 - Editar um componente da matriz" << endl;
    cout << "7 - Excluir um componente da matriz" << endl;
    cout << "0 - Sair" << endl;
    cin >> operacao;
    chamada(operacao);
  } while (operacao != 0);
}