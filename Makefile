EXECUTAVEL = main
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

FLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

#se eu criar um novo arquivo .h e .cpp com mesmo nome, adicionar " \ $(OBJ_DIR)/[nomenovo].o"
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/Base.o $(OBJ_DIR)/Categoria.o $(OBJ_DIR)/Cliente.o \
       $(OBJ_DIR)/Fornecedor.o $(OBJ_DIR)/Funcionario.o $(OBJ_DIR)/Localizacao.o \
       $(OBJ_DIR)/Peca.o $(OBJ_DIR)/pedidoCompra.o $(OBJ_DIR)/Pessoa.o $(OBJ_DIR)/Venda.o \
	   $(OBJ_DIR)/Funcs.o $(OBJ_DIR)/FuncionarioRepositorio.o $(OBJ_DIR)/CategoriaRepositorio.o \
	   $(OBJ_DIR)/ClienteRepositorio.o $(OBJ_DIR)/FornecedorRepositorio.o  $(OBJ_DIR)/LocalizacaoRepositorio.o \
	   $(OBJ_DIR)/PecaRepositorio.o $(OBJ_DIR)/PedidoCompraRepositorio.o $(OBJ_DIR)/VendaRepositorio.o

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
	clear
	./$(EXECUTAVEL)