import java.util.*;

public class checkPermutation
{

	public static void main(String [] args)
	{
		String pat1 = "abcd";
		String pat2 = "bcda";
		System.out.println(checkPermute(pat1,pat2));
		System.out.println(checkPermute2(pat1,pat2));
	}

	public static boolean checkPermute(String pat1, String pat2)
	{
		int [] v1 = new int[26];
		int [] v2 = new int[26];

		for(int i = 0; i < pat1.length(); i++)
			v1[pat1.charAt(i) - 'a']++;

		for(int i = 0; i < pat2.length(); i++)
			v2[pat2.charAt(i) - 'a']++;

		for(int i = 0; i < v1.length; i++)
		{
			if(v1[i] != v2[i])
				return false;
		}

		return true;
	}

	public static boolean checkPermute2(String pat1, String pat2)
	{

		char tempArray1[] = pat1.toCharArray();
		char tempArray2[] = pat2.toCharArray();

		Arrays.sort(tempArray1);
		Arrays.sort(tempArray2);

		for(int i = 0; i < tempArray1.length; i++)
		{
			if(tempArray1[i] != tempArray2[i])
				return false;
		}
		
		return true;

	}

}
