import java.lang.Math;
public class Questao3{
    double funcao(double t,double z){
        double x;
        x = Math.pow(t,z) * Math.pow(Math.E,-t);
        return x;
    }
    double calcularDelta(double a, double b, double n){
        double delta;
        delta = (b-a)/n;
        return delta;
    }
    double simularIntegral(double a, double b, double n,double z){
        Questao3 v = new Questao3();
        double somatorio = 0;
        for(int i=1; i <= n; i++){
            somatorio = somatorio + (v.funcao(a + i*(v.calcularDelta(a,b,n)),z)*v.calcularDelta(a,b,n));
        }
        return somatorio;
    }
    public static void main(String args[]){
        Questao3 v = new Questao3();
        double a,b,n,z;
        a = 0; 
        b = 1000;  
        n = 1000; // final do somatorio
        z = 5; // número do fatorial = z!
        System.out.println(v.simularIntegral(a,b,n,z));
    }
}