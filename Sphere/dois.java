import java.util.*;
class dois{
  public static void primeNumbers(int min, int max){
    try{
      boolean numeros[] = new boolean[max+1];
    //Inicializar array como true
    for(int i=0; i<2; i++){
      numeros[i]=false;
    }
    for(int i=2; i<=max; i++){
      numeros[i]=true;
    }

    for(int i=2; i*i<numeros.length; i++){
      if(numeros[i]==true){
        for(int j=i*2; j<numeros.length; j+=i ){
          numeros[j]=false;
        }
      }
    }
  /*  for(int i=0; i<numeros.length; i++){
      System.out.println(i+ " "+ numeros[i]);
    } */
    for(int i=min; i<numeros.length; i++){
      if(numeros[i]==true) System.out.println(i);
    }
  } catch(Exception e){
    return;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int times=in.nextInt();
    for(int i=0; i<times; i++){
      int min= in.nextInt();
      int max=in.nextInt();
      primeNumbers(min,max);
      System.out.println();
    }

    }
  }
