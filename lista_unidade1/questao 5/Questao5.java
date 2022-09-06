import java.lang.Math;
public class Questao5 {
    double calcularFatorial(int n){
        int fat = 1;
        for(int i = 1; i <= n; i++ ){
            fat = fat * i;
        }
        return fat;
    }
    double calcularSomatorio(int n){
        double somatorio = 0;
        Questao5 v = new Questao5();
        for(int k = 0; k <= n; k++){
            somatorio = somatorio + (Math.pow(-1,k)/v.calcularFatorial(k));
        }
        return somatorio;
    }
    public static void main(String args[]){
        int n = 5;
        double subfatorial;
        Questao5 v = new Questao5();
        subfatorial = (v.calcularFatorial(n))*(v.calcularSomatorio(n));
        System.out.println("O subfatorial de " + n + " e " + subfatorial);
    }
}
