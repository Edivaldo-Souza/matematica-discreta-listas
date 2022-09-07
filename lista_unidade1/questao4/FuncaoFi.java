import java.util.Scanner;
class FuncaoFi{
    public double fi(int n){
        int temp = n;
        int cont = 1;
        int m = 1;
        int produtos = 1;
        while(temp>1){
            cont++;
            if(temp%cont == 0){
                while(temp%cont==0){
                    temp /= cont;
                }
                m *= cont;
                produtos *= (cont - 1);
            }
        }
        return (n/m)*produtos;
    }

    public static void main(String[] args){
        
        Scanner leitor = new Scanner(System.in);
        System.out.println("Digite um valor: ");
        FuncaoFi f = new FuncaoFi();

        int n = leitor.nextInt();
        System.out.println("fi(" + n + ") = " + f.fi(n));
    }
}