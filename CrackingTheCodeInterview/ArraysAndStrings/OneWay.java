import java.util.*;

public class OneWay
{

	public static void main(String [] args)
	{
		String pat1 = "pale";
		String pat2 = "bale";
		System.out.println(check(pat1,pat2));
	}

	public static boolean check(String pat1, String pat2)
	{
		
		if(Math.abs(pat1.length() - pat2.length()) > 1)
			return false;

		if(Math.abs(pat1.length() - pat2.length()) == 1)
		{
			int [] frev1 = new int[26];
			int [] frev2 = new int[26];

			for(int i = 0; i < pat1.length(); i++)
				frev1[pat1.charAt(i)-'a']++;

			for(int i = 0; i < pat2.length(); i++)
				frev2[pat2.charAt(i)-'a']++;

			int dif = 0;
			
			for(int i = 0; i < 26 ;i++)
			{
				if(frev1[i] != frev2[i])
					dif++;
			}

			if(dif > 1)
				return false;
			else
				return true;
			
		}
		
			int [] frev1 = new int[26];
			int [] frev2 = new int[26];

			for(int i = 0; i < pat1.length(); i++)
				frev1[pat1.charAt(i)-'a']++;

			for(int i = 0; i < pat2.length(); i++)
				frev2[pat2.charAt(i)-'a']++;

			int dif = 0;
			
			for(int i = 0; i < 26 ;i++)
			{
				if(frev1[i] != frev2[i])
					dif++;
			}

			if(dif > 2)
				return false;
			else
				return true;		
	}
}
