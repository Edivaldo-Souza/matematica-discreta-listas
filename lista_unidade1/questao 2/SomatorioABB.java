import java.util.Scanner;

public class SomatorioABB {
  public static void main(String[] args) throws Exception {

    Scanner scanner = new Scanner(System.in);
    int n;

    System.out.print("Digite o valor de N: ");
    n = scanner.nextInt();

    System.out.printf("O valor de Pi é: %.10f %n", (somatorio(n)));

    scanner.close();
  }

  public static float somatorio(int num) {
    float soma = 0;
    float k = 0;

    for (int i = 1; i < num; i++, k++) {
      soma += (1 / Math.pow(16, k)) * ((4 / (8 * k + 1)) -
          (2 / (8 * k + 4)) -
          (1 / (8 * k + 5)) -
          (1 / (8 * k + 6)));
    }
    return soma;
  }
}