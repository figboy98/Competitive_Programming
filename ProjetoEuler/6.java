public class euler_6{
  public static int  soma_dos_quadrados(int inicio, int fim){
    int resultado=0;

    for(int i=inicio; i<=fim; i++){
      resultado+=i*i;
    }
    return resultado;

  }

  public static int quadrado_da_soma(int inicio, int fim){
    int resultado=0;
    for(int i=inicio; i<=fim; i++){
      resultado+=i;
    }
    return resultado*resultado;
  }


  public static void main(String args[]){
    System.out.println(soma_dos_quadrados(1,100)-quadrado_da_soma(1,100));
  }
}
