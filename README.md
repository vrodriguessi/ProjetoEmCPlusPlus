# Matriz Curricular - Manipulação de Matriz Curricular em Arquivo Binário <br>
Este é um programa desenvolvido pelo Grupo 23, composto por Guilherme Alexandre Cunha Silva, Lilian Carla de Freitas e Verônica Rodrigues da Silva França, que permite a manipulação de uma matriz curricular armazenada em um arquivo binário. O programa oferece diversas operações, incluindo visualização, busca, edição e exclusão de componentes curriculares. <br>

<h3>Recursos utilizados</h3>
<div>
  <ul>
    <li>Estruturas de Dados: O código utiliza estruturas de dados, como struct, para representar informações sobre os componentes curriculares.</li>
    <li>Manipulação de Arquivos: O programa faz uso de arquivos para armazenar e recuperar a matriz curricular. Ele lê informações de um arquivo CSV chamado "matriz.csv" e armazena em um arquivo binário "matriz.bin".</li>
    <li>Algoritmos de Ordenação: O código implementa o algoritmo de ordenação QuickSort para ordenar os componentes curriculares por código e nome.</li>
    <li>Recursão: Algumas funções, como quicksortCodigo e quicksortNome, utilizam recursão para dividir e conquistar na ordenação dos componentes.</li>
    <li>Busca Binária: O programa faz uso do algoritmo de busca binária para encontrar componentes curriculares por código e nome de forma eficiente.</li>
    <li>Uso de Ponteiros: O programa utiliza ponteiros para manipular e passar estruturas de dados entre funções.</li>
    <li>Manipulação de Strings: São usadas operações de manipulação de strings para processar e comparar códigos e nomes de componentes.</li>
    <li>Escrita em Arquivos Binários: O código utiliza a função write para escrever informações binárias em um arquivo binário.</li>
    <li>Operações com Strings: O programa faz uso de funções da biblioteca cstring para operações com strings, como strcpy e strcmp.</li>
    <li>Recursos de Controle de Fluxo: O programa faz uso de estruturas de controle de fluxo, como loops while e estruturas condicionais if e switch, para direcionar a execução do código.</li>
  </ul>
</div>
<br>
<h3>Funcionalidades</h3>
<div>
  <ul>
    <li>Visualizar toda a matriz curricular: Esta operação permite visualizar todos os componentes curriculares presentes no arquivo binário.</li>
    <li>Visualizar os componentes por período: Você pode selecionar um período (de 0 a 8) e visualizar todos os componentes curriculares desse período.</li>
    <li>Buscar um componente pelo código: Insira o código de um componente curricular e o programa irá mostrar as informações desse componente, se existir na matriz curricular.</li>
    <li>Buscar um componente pelo nome: Insira o nome de um componente curricular e o programa irá mostrar as informações desse componente, se existir na matriz curricular. A busca é case-insensitive.</li>
    <li>Adicionar um novo componente à matriz: Permite adicionar um novo componente curricular à matriz. Você precisa inserir informações como período, código, nome, tipo e cargas horárias.</li>
    <li>Editar um componente da matriz: Você pode editar informações de um componente curricular existente, fornecendo o código do componente e escolhendo o que deseja editar.</li>
    <li>Excluir um componente da matriz: Esta operação permite remover um componente curricular da matriz. Basta fornecer o código do componente que deseja excluir.</li>
    <li>Exportar a matriz curricular: Exporta a matriz curricular atual para um arquivo CSV chamado "arquivoExportadoCSV".</li>
  </ul>
</div>

<h3>Uso</h3>

Ao executar o programa, você será apresentado com um menu onde pode escolher a operação desejada digitando o número correspondente. Siga as instruções fornecidas pelo programa para realizar a operação desejada. Lembre-se de que o programa carrega a matriz curricular a partir de um arquivo CSV chamado "matriz.csv" e a transforma em um arquivo binário "matriz.bin". Certifique-se de que esses arquivos estejam presentes no mesmo diretório que o programa. Certifique-se também de que as entradas (código, nome, etc.) sejam fornecidas conforme especificado nas mensagens de solicitação do programa. Após realizar as operações desejadas, você pode exportar a matriz curricular atual para um arquivo CSV chamado "arquivoExportadoCSV" por meio da opção 8. Lembre-se de salvar as alterações no arquivo binário pressionando Enter antes de sair do programa.

Este programa oferece funcionalidades básicas para manipulação de uma matriz curricular. Você pode estender e aprimorar as funcionalidades conforme necessário.
