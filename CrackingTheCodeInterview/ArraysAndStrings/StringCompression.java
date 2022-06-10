public class StringCompression
{

	public static void main(String [] args)
	{
		String txt = "aaabbcccddddd";
		System.out.println(compress(txt));
	}

	public static String compress(String txt)
	{
		int [] frec = new int[26];
		char cur = txt.charAt(0);
		int count = 0;
		int j = 0;
		int i = 0;

		for(;;)
		{
			while(i < txt.length() && cur == txt.charAt(i))
			{
				i++;
				count++;
			}
			if( i == txt.length() )
			{
				frec[j++] = count;
				break;
			}
			cur = txt.charAt(i);
			frec[j++] = count;
			count = 0;
		}

		String newString = "" + txt.charAt(0);
		int index = 0;
		for(i = 0; i < 4; i++)
		{
			index += frec[i];
			newString = newString + frec[i];
			if( i + 1 < 4)
				newString = newString + txt.charAt(index - 1);
		}

		return newString;	
	}
}
