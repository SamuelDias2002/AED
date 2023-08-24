
void mostrarElemento(INFO X){
  printf("%d --> ", X.numAluno);
  printf("%5.2f --> ", X.notaFreq);
  printf("%4.2f --> ", X.notaPratica);
  if (X.aprovado)
    printf("Aprovado\n");
  else
    printf("Reprovado\n");
}

INFO criarElemento(){
  INFO X;
  X.numAluno = gerarNumeroInteiro(40000, 55000);
  X.notaFreq = gerarNumeroReal(0, 16);
  X.notaPratica = gerarNumeroReal(0, 4);
  if (X.notaFreq + X.notaPratica >= 9.5)
    X.aprovado = 1;
  else
    X.aprovado = 0;
  return X;
}

// comparação de 2 elementos do tipo INFO, segundo o campo NFatura (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementos(INFO X, INFO Y){
  if (X.numAluno > Y.numAluno)
    return 1;
  if (X.numAluno < Y.numAluno)
    return -1;
  return 0;
}




