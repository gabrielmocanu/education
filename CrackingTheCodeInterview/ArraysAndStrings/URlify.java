import java.util.*;

class space
{
	
	public char[] transformSpace( char[] s)
	{
		int nr_spaces = 0;
		for(int i=s.length-1;i>=0;i--)
		{
			if(s[i] == ' ')
				nr_spaces++;
		}

		System.out.println(nr_spaces);

		int new_length = s.length + nr_spaces*3;
		char[] new_s = new char[new_length];
		
		new_length--;
		for(int i=s.length-1;i>=0;i--)
		{
			if( s[i] != ' ')
			{
				new_s[new_length] = s[i];
				new_length--;
			}
			else
			{
				new_s[new_length] = '0';
				new_length--;
				new_s[new_length] = '2';
				new_length--;
				new_s[new_length] = '%';
				new_length--;	
			}
		System.out.println(new_s);
		}

		return new_s;

	}

	public static void main( String[] args)
	{
	
		space sp = new space();

		char[] s = new char[13];

		Scanner sc = new Scanner(System.in);

		for(int i=0;i<13;i++)
			s[i] = sc.nextLine().charAt(0);
		
		System.out.println(sp.transformSpace(s));
	}
}

