<p align="center">
 <img src="https://giovanidacruz.com.br/wp-content/uploads/2022/11/C-programming-1024x530-1.jpg" height="250" width="500">  </p>
 <h1 align="center">C language code</h1>
<p align="center">
</p>
Backend application using C language.


### Description 
---
### --------------------- DESAFIO 01 ------------------------------------------|
### Desafio Avançado de Implementação de Formas Geométricas em C			   |
### ---------------------------------------------------------------------------|

# Descrição:
Neste desafio avançado, você deve implementar uma hierarquia de classes em C 
para representar diferentes tipos de formas geométricas, incluindo retângulos 
e triângulos.

# Classe Base "Forma Geométrica":
A classe base "Forma Geométrica" deve ter os seguintes atributos e métodos:
- **Atributos**:
  - Não possui atributos específicos, pois é uma classe base abstrata.

- **Métodos Virtuais**:
  - `calcular_area`: um método virtual puro para calcular a área da 
  forma geométrica.
  - `calcular_perimetro`: um método virtual puro para calcular o perímetro 
  da forma geométrica.
  - `imprimir`: um método virtual puro para imprimir os detalhes da 
  forma geométrica.

# Classe Derivada "Retângulo":
A classe derivada "Retângulo" deve herdar da classe base "Forma Geométrica" 
e adicionar os seguintes atributos e métodos:
- **Atributos**:
  - `largura`: a largura do retângulo.
  - `altura`: a altura do retângulo.

- **Métodos**:
  - Implementação dos métodos virtuais herdados:
    - `calcular_area`: calcular a área do retângulo.
    - `calcular_perimetro`: calcular o perímetro do retângulo.
    - `imprimir`: imprimir os detalhes do retângulo (largura, altura,
	área e perímetro).

# Classe Derivada "Triângulo":
A classe derivada "Triângulo" também deve herdar da classe base 
"Forma Geométrica" e adicionar os seguintes atributos e métodos:
- **Atributos**:
  - `lado1`, `lado2`, `lado3`: os comprimentos dos lados do triângulo.

- **Métodos**:
  - Implementação dos métodos virtuais herdados:
    - `calcular_area`: calcular a área do triângulo.
    - `calcular_perimetro`: calcular o perímetro do triângulo.
    - `imprimir`: imprimir os detalhes do triângulo (comprimentos dos lados,
	área e perímetro).

Além disso, você deve implementar um main que cria instâncias de retângulos, 
triângulos e imprima os detalhes das formas criadas

# Critérios de Avaliação:
Esse desafio fornecerá aos candidatos a oportunidade de demonstrar suas 
habilidades em herança, polimorfismo e manipulação avançada de recursos 
da liguagem C, aplicadas a diferentes tipos de formas geométricas.
Os candidatos serão avaliados com base nos seguintes critérios:

1. **Correção da Implementação**: As classes devem ser implementadas 
corretamente, seguindo as especificações fornecidas.
2. **Uso de Polimorfismo**: O código deve fazer uso eficiente de 
polimorfismo por meio de métodos virtuais.
3. **Organização do Código**: O código deve ser organizado de forma clara 
e modular, com cada classe em seus próprios arquivos de cabeçalho 
e implementação.
4. **Boas Práticas**: Os candidatos devem seguir boas práticas de 
programação em C, como tratamento de erros, uso adequado de ponteiros, etc.
5. **Eficiência do Código**: O código deve ser eficiente em termos de 
uso de memória e tempo de execução.
6. **Interatividade do Programa**: O programa principal deve permitir 
uma interação intuitiva com o usuário, facilitando a criação, manipulação 
e exibição de retângulos e outras formas geométricas.

```bash
					 ____________________________________________
					|                FormaGeometrica             |
					|--------------------------------------------|
					| + calcular_area(): float                   |
					| + calcular_perimetro(): float              |
					| + imprimir(): void                         |
					| + criar_forma_geometrica(): void*          |
					 --------------------------------------------
                                                          /\
                                                          ||
                                                        extends
                                                          ||
                                    |-----------------------------------------------|
                                    |                    |
                                Retangulo         				Triangulo
                            ----------------------------------  	--------------------------------------
                          |+ largura: float          			|	|+ lado1: float 	|
                          |+ altura: float           			|	|+ lado2: float 	 |
                          |                          			|	|+ lado3: float    |
                          |-----------------------------------|	|--------------------------------------|
                          |+ criar_retangulo(): void*			|	|+ criar_triangulo(): void* 	             |
                          |+ calc_area_retangulo(): float 	|	|+ calc_area_triangulo(): float 	       |
                          |+ calc_perimetro_retangulo(): float|	|+ calc_perimetro_triangulo(): float   |
                          |+ imprimir(): void                 |	|+ imprimir(): void                    |
                          ---------------_-------____--------------	----------------------------------------

```

### --------------------- DESAFIO 02 ----------------------------------------|
### Desafio de Implementação em C: Interpretação de Pacotes de Dados 		   |
### Serial e Padrão Observer			   									   |
### ---------------------------------------------------------------------------|

#Descrição:
Você foi designado para implementar um sistema em C para interpretar pacotes de 
dados recebidos pela porta serial de um dispositivo embarcado. 
Os pacotes de dados são enviados com um protocolo específico que inclui um 
cabeçalho com as seguintes informações:

- Byte 1: Start Symbol (Especificar um simbulo de start, indicando que é o inicio de um pacote)
- Byte 2: Tipo de pacote (1 byte)
- Bytes 3-4: Comprimento dos dados (2 bytes, big-endian)
- Bytes 5 em diante: Dados (variável)
- Últimos 2 bytes: Valor de CRC (Cyclic Redundancy Check,
2 bytes, big-endian)

Além disso, você deve implementar um padrão Observer para permitir que 
diferentes partes do sistema possam se registrar para receber notificações 
apenas sobre os tipos específicos de pacotes de dados que lhes interessam. 

#Tarefas:
1. Implemente as funções necessárias para interpretar os pacotes de dados 
recebidos pela porta serial, seguindo o protocolo especificado. Isso inclui 
verificar o cabeçalho do pacote, calcular o CRC e criar uma estrutura de 
dados adequada para representar o pacote.

2. Implemente as estruturas e funções necessárias para o padrão Observer. 
Isso inclui a criação de observadores, registro de observadores em um objeto 
observável e notificação dos observadores quando um novo pacote de dados 
é recebido.

3. Garanta que cada observador seja notificado apenas quando um pacote de 
dados do tipo específico de interesse for recebido.

#Requisitos:

- A interpretação dos pacotes de dados deve ser robusta, verificando 
erros de formatação e integridade dos dados.
- A implementação do padrão Observer deve permitir que novos observadores sejam 
adicionados dinamicamente e que eles sejam notificados apenas sobre os tipos de 
pacotes de dados que lhes interessam.

#Observações:
- Você pode simular os dados recebidos pela porta serial para testar sua implementação.
- Certifique-se de incluir comentários adequados em seu código para explicar a 
lógica e o propósito de cada função e estrutura.


---

### Starting
```bash
# Clone this project
$ git clone https://github.com/JenniferFariasRodrigues/linguagem_C.git

# Access using IDE ou through the code
On the IDE Enviromental choose the open project.

# 1 Challenge: 
# Choose FormaGeometrica folder in IDE and run the project
Click on  "FormaGeometrica" folder and choose "Main.c" class.
# Put the line on the terminal
$ gcc -o main main.c Retangulo.c Triangulo.c -lm

# Run code
$ ./main

# 2 Challenge: 
# Choose InterpretacaoPacoteDeDados folder in IDE and run the project
Click on  "InterpretacaoPacoteDeDados" folder and choose "main.c" class.
# Put the line on the terminal
$ gcc -o main main.c observer.c crc32.c

# Run code
$ ./main


```

---
### Output
###
The expected Desafio-01 project output is:
---
```bash

----------------------

Dados do Retângulo

----------------------
Retângulo:
Largura = 5.00
Altura = 3.00
Área = 15.00
Perímetro = 16.00

 
----------------------

Dados do Triângulo

----------------------
Triângulo:
Lado 1 = 3.00
Lado 2 = 4.00
Lado 3 = 5.00
Área = 6.00
Perímetro = 12.00

```

The expected Desafio-02 project output is:
---
-Correct result :
```bash
Digite o Nome: jennifer
Digite a Serial: 849
CRC calculado - nome: 458E27B7
CRC calculado - função: E5CD778D
Serial correto: 849

Resultado:
Dados corretos!
Erro: Cabeçalho do pacote inválido!

 
---Aviso---
Notificando observadores para o tipo de pacote: 1

Pacote de dados recebido:
Tipo: 1
Comprimento: 8
Dados: jennifer
CRC: 0x27B7

```

-wrong result:
```bash
Digite o Nome: jennifer
Digite a Serial: 85
CRC calculado - nome: 458E27B7
CRC calculado - função: E5CD778D
Serial correto: 849

Resultado:
Tente outra vez...
```
