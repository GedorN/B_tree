#Neste exemplo de Makefile, os arquivos objetos (.o) são gerados separadamente, assim, somente arquivos fonte (.c) alterados são recompilados para gerar um novo .o. Então o novo .o é linkado com os outros .o (dos arquivos não alterados) para gerar o executável. O make sabe o que deve ser recompilado com base nos timestamps dos arquivos fonte e seus respectivos arquivos objeto.


######### Sintaxe ###########
#regra: dependências
#<TAB>	comando	
#############################

#==============
#A regra all: é usada para construir o sistema de forma incremental 
all: saida
	@echo " " 
	@echo "Copilação concluída!!"
	@echo " " 
	./exe
	 

#==============
#A regra saida: tem como dependências os arquivos objeto, ou seja, para criar o executavel saida precisamos dos 6 arquivos .o 
#O comando cria o executável exe a partir dos arquivos objetos mainArvoreb.o insereArvoreb.o criaArvoreb.o buscaArvoreb.o printArvoreb.o removeArvoreb.o
saida: mainArvoreb.o insereArvoreb.o criaArvoreb.o buscaArvoreb.o printArvoreb.o removeArvoreb.o
	gcc -o exe mainArvoreb.o insereArvoreb.o criaArvoreb.o buscaArvoreb.o printArvoreb.o removeArvoreb.o  


#==============
#A regra mainArvoreb.o: tem como dependência o arquivo fonte, ou seja, para criar mainArvoreb.o precisamos do arquivo mainArvoreb.c 
#O comando cria o arquivo objeto progPrincipal.o a partir do arquivo fonte progPrincipal.c
mainArvoreb.o: mainArvoreb.c
	gcc -o mainArvoreb.o -c mainArvoreb.c 

#==============
#A regra insereArvoreb.o: tem como dependência o arquivo fonte insereArvoreb.c
#O comando cria o arquivo objeto insereArvoreb.o a partir do arquivo fonte insereArvore.c
insereArvoreb.o: insereArvoreb.c
	gcc -o insereArvoreb.o -c insereArvoreb.c

#==============
#A regra criaArvoreb.o: tem como dependência o arquivo fonte criaArvoreb.c
#O comando cria o arquivo objeto criaArvoreb.o a partir do arquivo fonte criaArvore.c
criaArvoreb.o: criaArvoreb.c
	gcc -o criaArvoreb.o -c criaArvoreb.c

#==============
#A regra buscaArvoreb.o: tem como dependência o arquivo fonte buscaArvore.c
#O comando cria o arquivo objeto  buscaArvore.o a partir do arquivo fonte  buscaArvore.c
buscaArvoreb.o: buscaArvoreb.c
	gcc -o buscaArvoreb.o -c buscaArvoreb.c  

#==============
#A regra printArvoreb.o tem como dependência o arquivo fonte printArvoreb.c
#O comando cria o arquivo objeto printArvoreb.o a partir do arquivo fonte printArvoreb.c
printArvoreb.o: printArvoreb.c
	gcc -o printArvoreb.o -c printArvoreb.c

#==============
#A regra removeArvoreb.o tem como dependência o arquivo fonte removeArvoreb.c
#O comando cria o arquivo objeto removeArvoreb.o a partir do arquivo fonte removeArvoreb.c
removeArvoreb.o: removeArvoreb.c
	gcc -o removeArvoreb.o -c removeArvoreb.c

#==============
#A regra clean: apaga os arquivos .o ao digitarmos make clean na console
clean: 
	rm -f *.o

#==============
#A regra execClean: apaga o arquivo executável ao digitarmos make cleanExec na console	
execClean:
	rm -f exe


