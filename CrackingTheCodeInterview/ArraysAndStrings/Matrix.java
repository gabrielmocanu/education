import java.util.*;

public class Matrix
{

	public static void main(String [] args)
	{

		Scanner in = new Scanner(System.in);
		int [][] matr = new int[3][3];
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				matr[i][j] = in.nextInt();

		matr = rotate(matr);

		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				System.out.println(matr[i][j] + " ");
			}
			System.out.println();
		}

	}		

	public static int [][] rotate(int [][] matrix)
	{
		int n = 3;
		for(int i = 0; i < n/2; i++)
		{
			for(int j = i; j <n - i - 1; j++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][n-1-i];
				matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
				matrix[n-1-j][i] = temp;
			}
		}
		return matrix;
	}
}	
