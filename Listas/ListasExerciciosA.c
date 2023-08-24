
PNodo /*struct nodo*/ criarListaAleatoria(int N)
{
  int k;
  PNodo L;
  INFO X;

  L = criarLista();
  k = 1;
  while (k <= N)
  {

    X = criarElemento();
    if (pesquisarLista(X, L) == 0)
    {
      L = inserirListaInicio(X, L);
      k = k + 1;
    }
  }
  return L;
}
