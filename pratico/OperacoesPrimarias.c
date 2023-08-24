
void mostrarElementoAB(INFOAB X)
{
    printf("%d --> ", X.numAluno);
    printf("%5.2f --> ", X.notaFreq);
    printf("%4.2f --> ", X.notaPratica);
    if (X.aprovado)
        printf("Aprovado\n");
    else
        printf("Reprovado\n");
}

INFOAB criarElementoAB()
{
    INFOAB X;
    X.numAluno = gerarNumeroInteiro(4000, 4100);
    X.notaFreq = gerarNumeroReal(0, 16);
    X.notaPratica = gerarNumeroReal(0, 4);
    if (X.notaFreq + X.notaPratica >= 9.5)
        X.aprovado = 1;
    else
        X.aprovado = 0;
    return X;
}

// comparação de 2 elementos do tipo INFOAB, segundo o campo numAluno (chave)
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int compararElementosAB(INFOAB X, INFOAB Y)
{
    if (X.numAluno > Y.numAluno)
        return 1;
    if (X.numAluno < Y.numAluno)
        return -1;
    return 0;
}
