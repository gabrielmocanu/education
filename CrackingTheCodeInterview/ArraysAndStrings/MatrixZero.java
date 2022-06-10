import java.util.*;

public class MatrixZero
{

	
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		int [][] matrix = new int[4][4];
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0;j < 4;j++)
			{
				matrix[i][j] = in.nextInt();
			}
		}

		matrix = setZero(matrix);
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0;j < 4;j++)
			{
				System.out.println(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static int [][] setZero(int matrix[][])
	{
		boolean firstColumn = false ,firstRow = false;
		for(int i = 0; i < 4; i++)
		{
			if(matrix[i][0] == 0)
			{
				firstColumn = true;
			}
		}
		for(int i = 1; i < 4; i++)
		{
			if(matrix[0][i] == 0)
			{
				firstRow = true;
			}
		}

		for(int i = 1; i < 4; i++)
		{
			for(int j = 1; j < 4; j++)
			{
				if(matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(matrix[i][0] == 0)
			{
				for(int j = 0; j < 4; j++)
				{
					matrix[i][j] = 0;
				}
			}
		}

		for(int i = 1; i < 4; i++)
		{
			if(matrix[0][i] == 0)
			{
				for(int j = 0; j < 4; j++)
				{
					matrix[j][i] = 0;
				}
			}
		}

		if(firstColumn)
		{
			for(int i = 0;i < 4; i++)
				matrix[i][0] = 0;
		}

		if(firstRow)
		{
			for(int i = 0;i < 4; i++)
				matrix[0][i] = 0;
		}
	
		return matrix;
	}
}
