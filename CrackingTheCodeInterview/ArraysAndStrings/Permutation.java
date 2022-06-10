import java.util.*;

public class Permutation
{
	public void permutation(String str)
	{
		permutation(str,"");
	}

	public void permutation(String str, String prefix)
	{
		if(str.length() == 0)
			System.out.println(prefix);
		else
		{
			for(int i = 0;i< str.length();i++)
			{
				String rem = str.substring(0,i) + str.substring(i+1);
				permutation(rem,prefix+str.charAt(i));
			}
		}
	
	}


	public static void main(String[] args)
	{
		Permutation p = new Permutation();

		p.permutation("abc");
	}
}
