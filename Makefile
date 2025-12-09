EXECUTAVEL = main
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

FLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

#se eu criar um novo arquivo .h e .cpp com mesmo nome, adicionar " \ $(OBJ_DIR)/[nomenovo].o"
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/Base.o $(OBJ_DIR)/Categoria.o $(OBJ_DIR)/Cliente.o \
       $(OBJ_DIR)/Fornecedor.o $(OBJ_DIR)/Funcionario.o $(OBJ_DIR)/Localizacao.o \
       $(OBJ_DIR)/Peca.o $(OBJ_DIR)/pedidoCompra.o $(OBJ_DIR)/Pessoa.o $(OBJ_DIR)/Venda.o \
	   $(OBJ_DIR)/Funcs.o $(OBJ_DIR)/FuncionarioRepositorio.o 

all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJS)
	g++ $(OBJS) -o $(EXECUTAVEL)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/main.o: main.cpp $(OBJ_DIR)
	g++ $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

# all: main.o Base.o Categoria.o Cliente.o Fornecedor.o Funcionario.o Localizacao.o Peca.o pedidoCompra.o Pessoa.o Venda.o
# 	g++ -o main main.o Base.o Categoria.o Cliente.o Fornecedor.o Funcionario.o Localizacao.o Peca.o pedidoCompra.o Pessoa.o Venda.o

# Base.o: src/Base.cpp include/Base.h
# 	g++ $(CPPFLAGS) -c src/Base.cpp

# Categoria.o: src/Categoria.cpp include/Categoria.h
# 	g++ $(CPPFLAGS) -c src/Categoria.cpp

# Cliente.o: src/Cliente.cpp include/Cliente.h
# 	g++ $(CPPFLAGS) -c src/Cliente.cpp

# Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.h
# 	g++ $(CPPFLAGS) -c src/Fornecedor.cpp

# Funcionario.o: src/Funcionario.cpp include/Funcionario.h
# 	g++ $(CPPFLAGS) -c src/Funcionario.cpp

# Localizacao.o: src/Localizacao.cpp include/Localizacao.h
# 	g++ $(CPPFLAGS) -c src/Localizacao.cpp

# Peca.o: src/Peca.cpp include/Peca.h
# 	g++ $(CPPFLAGS) -c src/Peca.cpp

# pedidoCompra.o: src/pedidoCompra.cpp include/pedidoCompra.h
# 	g++ $(CPPFLAGS) -c src/pedidoCompra.cpp

# Pessoa.o: src/Pessoa.cpp include/Pessoa.h
# 	g++ $(CPPFLAGS) -c src/Pessoa.cpp

# Venda.o: src/Venda.cpp include/Venda.h
# 	g++ $(CPPFLAGS) -c src/Venda.cpp

# main.o: main.cpp
# 	g++ $(CPPFLAGS) -c main.cpp
