### <center> Trabalho Estrutura de Dados</center>

#### <center>Flávio Lúcio Corrêa Júnior </center>

**<center>Universidade Federal de Minas Gerais (UFMG) </center>**
**<center>Belo Horizonte - MG - Brazil</center>**

---

- #### Sumário:
  **1. Introdução**
  **2. Implementação**
  **3. Análise de complexidade**
  **4. Conclusão**
  **5. Bibliografia**

---

## 1 Introdução

O trabalho consiste em construir um sistema de simulação do SISU (Sistema de Seleção Unificada) para o reino de Arendelle, tal sistema deve ser capaz de classificar os alunos baseando-se em suas notas, opções de curso e ordem de chegada. O objetivo deste trabalho é praticar os conceitos de listas encadeadas e análise de complexidade.

## 2 Implementação:

- #### Estrutura de dados:
- **Vetor:**
  - **Uso**: armazenar os cursos ordenados por ordem de chegada em que o índice do vetor representa o ID do curso.
  - **Motivo de escolha:** acesso constante a qualuer elemento pelo índice (ID) e os elementos não teriam sua ordem alterada ou seriam removidos uma vez inseridos no vetor.
- **Lista duplamente encadeada:**
  - **Uso:** armazenar os alunos de um curso tanto na lista de classificados quando na lista de espera.
  - **Motivo de escolha:** muitas inserções e remoções de elementos do meio, ínicio e fim da lista, o que pode ser feito em tempo constante
- #### Classes:

  ![alt text](https://github.com/flaviolc18/cpp_codes/blob/master/tests/tp-es.png?raw=true)

- #### Algoritmo:
  - Basicamente o algoritmo principal consiste em processar os alunos conforme eles vão sendo lidos e manter a lista ordenada pelos critérios definidos e sempre que o curso está cheio e um novo aluno é incluido, o aluno com menor nota é removido e o procedimento é repitido para sua segunda opção de curso, segue uma representação em pseudo-código:

```python
cursos = ler_cursos()
num_alunos = ler_num_alunos()

for num_aluno in num_alunos:
    aluno = ler_aluno()
    processa_aluno(aluno, opcao_curso1)

def processa_aluno(aluno, opcao_curso):
  resultado = tenta_incluir_curso_opcao(opcao_curso, aluno)

  if(resultado == nota_nao_suficiente):
    inclui_lista_espera(opcao_curso)
    processa_aluno(aluno, opcao_curso2)

  if(resultado == aluno_incluido_e_outro_eliminado_por_falta_de_vagas):
    inclui_lista_espera(aluno_eliminado)

    if(aluno_eliminado.opcao_curso == opcao_curso1)
      processa_aluno(aluno_eliminado, aluno_eliminado.opcao_curso2)

```

- #### Compilador:
  O compilador usado foi o `g++` com a flag `-std=c++14`

## 3 Análise de complexidade:

- **q** = quantidade de vagas de um curso
- **a** = quantidade de alunos
- **c** = quantidade de cursos
- **n** = número de inserções de alunos na lista de classificados de sua segunda opção de curso em que não esteja com todas as vagas ocupadas

### Complexidade de tempo:

![alt text](https://github.com/flaviolc18/cpp_codes/blob/master/tests/alg.png?raw=true)

Temos que **processar_aluno() = T(n) = 2(1+q) + T(n-1)**
Logo a complexidade final do programa = **F(a,q,n) = O(a.q.n)**

### Complexidade de espaço:

- Considerando apenas os objetos instanciados:
  - **F(a, c) = O(a + c)**
- Considerando os ponteiros (shared_ptr):
  - **F(a, c, n) = n(O(1) + O(1)) + O(a+c) = O(a + c + n)**

## 4 Conclusão:

- Atividade prática super interessante pois serviu para fixar os conceitos vistos em sala tais como as estruturas de dados usadas e a análise de complexidade. Além disso, foi possível rever os conceitos de programação orientada a objetos e a sintaxe da linguagem C++, vistos na disciplina PDS2. Uma das principais dificuldades na resolução do problema foi a implementação dos casos de desempate, o que foi resolvido incluindo várias checagens com condicionais para que a ordenação dos alunos fique correta.

## 5 Bibliografia:

- http://stackoverflow.com/
- https://www.wikipedia.org/
- https://github.com
