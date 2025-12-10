# Projeto de Fábio Augusto V. de S. Vila
# Professor: Jefferson Gomes Dutra

# Visão Geral

Este projeto é uma aplicação de gestão (CRUD) desenvolvida em C++, utilizando rigorosamente os principais conceitos da Programação Orientada a Objetos (POO) e Padrões de Projeto (Repository Pattern) para garantir código modular, coeso e reutilizável. O contexto da aplicação envolve o cadastro, consulta, alteração e remoção de dados de um sistema de gestão de estoque e vendas.

# Requisitos Mínimos
*Mínimo 11 Classes* -> O projeto possui 20 Classes/Interfaces Próprias. Isso inclui 8 Entidades, 8 Repositórios Concretos, 2 Classes Abstratas e 2 Interfaces de Programação.

*Encapsulamento de Entidades* -> Todos os atributos são private ou protected. O acesso é feito via métodos getters e setters. A classe Pessoa utiliza atributos protected para otimizar o acesso pelas classes herdeiras.

*Polimorfismo e Herança* -> Toda a lógica de herança e implementação (como a herança de Base e Pessoa, e a implementação da CrudInterface) utiliza apenas classes próprias, sem dependência de bibliotecas externas

*CRUD em 8 Entidades* -> O CRUD está implementado para as 8 entidades de negócio: Categoria, Cliente, Fornecedor, Funcionario, Localizacao, Peca, pedidoCompra e Venda.

*Tratamento de Exceções* -> ex: CampoVazioException, ValorInvalidoException

*Validação de Dados* -> As exceções são lançadas dentro dos métodos de validação dos Repositórios para garantir a integridade dos dados (ex: preço positivo, campos não vazios).

*Salvar e Carregar Info de Usuário* -> O FuncionarioRepositorio é responsável por salvar em arquivo (usuarios.txt) o Nome de Exibição e o tema (claro/escuro) do usuário. Estas informações são carregadas e exibidas ao inicializar a aplicação.

*Diagrama de Classes - UML* -> O diagrama foi gerado com a ferramenta Mermaid/PlantUML
Link para o Diagrama Mermaid: https://www.mermaidchart.com/app/projects/69ceeb0f-547c-483b-bf58-ea52512b0b25/diagrams/f3b10483-6f2a-4620-8c1d-efd6449cdf47/version/v0.1/edit

*Interação com o Usuário* -> O sistema funciona via menu interativo (main / iniciarMenu), permitindo que o usuário interaja diretamente com as operações de CRUD.

# Instruções para Rodar a Aplicação

Executar os seguintes comandos no terminal:

1º -> "make"
2º -> "make run"

