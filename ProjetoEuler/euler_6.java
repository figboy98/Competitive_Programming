public class euler_6{
  public static int  soma_dos_quadrados(int inicio, int fim){
    int resultado=0;

    for(int i=inicio; i<=fim; i++){
      resultado+=(i*i);
    }
    System.out.println("Soma dos quadrados: "+ resultado);
    return resultado;

  }

  public static int quadrado_da_soma(int inicio, int fim){
    int resultado=0;
    for(int i=inicio; i<=fim; i++){
      resultado+=i;
    }
    System.out.println("Quadrado da soma: "+ (resultado*resultado));
    return resultado*resultado;
  }

public static void main(String args[]){
int aux=soma_dos_quadrados(1,100);
int aux1=quadrado_da_soma(1,100);
int resultado=aux1-aux;
System.out.println(resultado);
  }
}
