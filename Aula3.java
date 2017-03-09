import java.util.Random;
import java.util.Scanner;


public class Aula3 {
	static Scanner scan = new Scanner(System.in);
	static Random rand  = new Random();
	public static void main(String[] args) {
		ex10();
	}
	
	static void ex1(){
		int res = 0, dal;
		int[] vet = new int[4];
		for (int i = 0; i < vet.length; i++) {
			do{
				dal = scan.nextInt();
			}while(dal < 0 || dal % 2 != 0);
			
			vet[i] = dal;
			
		}
		
		for (int i = 0; i < vet.length; i++) {
			res += vet[i];
		}
		
		System.out.println("O somatorio desses valores é " + res);
	}

	static void ex2(){
		int[] conj = new int[3];
		int temp;
		boolean feshow = false;
		do{
			for (int i = 0; i < conj.length; i++) {
				temp = scan.nextInt();
				conj[i] = temp;
			}	
			
			if(conj[0] < conj[1] && conj[1] < conj[2]){
				System.out.println("A media é "+ ( conj[0] + conj[1] + conj[2] )  /3);
				feshow = true;
			}
		}while(!feshow);
	}
	
	static void ex3(){
		int[] vals = new int [6];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = i+1;
		}
		
		for (int i = 0; i < vals.length; i++) {
			for (int j = 0; j < vals.length; j++) {
				if(vals[i] + vals [ j] == 7){
					System.out.println("Dado 1: " + vals[i] +
									   " Dado 2: " + vals [ j]+
										" sua soma e 7");
				}
			}
		}
		
	}
	
	static void ex4(){
		int max = scan.nextInt();
		int dam, dom, dum = 0, dem = 0;
		for(int i = 1; i <= max; i++){
			dam = i * i * i;
			dom = ( i*i) - (i-1);
			dum = dom;
			System.out.print(i + " ao cube e "+ dam + ". ");
			for (int j = 0; j < i; j++) {
				if(j == 0){
					System.out.print(dum);
				}else
				System.out.print(" + " + dum);
				dum +=2 ;
			}
			
			System.out.print( "  = " + dam);
			
			System.out.println(" ----------------");
		}
	}
	
	static void ex10(){
		int[][] mat = new int [4][4];
		int a, linDoImpar, colDoImpar, linDoPar, colDoPar, das;
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				a = rand.nextInt(100);
				mat[i][j] = a;
			}
		}
		
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length; j++) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println("-------------Aqui acaba a declaracao da matriz-----------");
		for (int i = 0; i < mat.length; i++) {
			for (int j = 0; j < mat[i].length - 1; j++) {
				if(mat[i][j]  % 2 != 0){
					linDoImpar = i;
					colDoImpar = j;
					for (int q = mat.length - 1; i > -1 ; i++) {
						for (int w = mat.length - 1; j > -1; j++) {
							if(mat[q][w] % 2 == 0){
								das = mat[i][j];
								mat[i][j] = mat[q][w];
								mat[q][w] = das;
							}
						}
					}
				
				}
			}
		}
		
		for (int i = 0; i < mat.length; i++) {
			for (int j2 = 0; j2 < mat[i].length -1 ; j2++) {
				System.out.println(mat[i][j2] + " ");
			}
			System.out.println();
		}
		
		
	}

}

