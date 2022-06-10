import java.util.*;

class Unique
{
	boolean isUniq(String s)
	{
		int[] v = new int[26];
		for(int i = 0;i < s.length();i++)
		{
			v[s.charAt(i)-'a']++;
			if(v[s.charAt(i)-'a'] > 1)
				return false;
		}

		return true;
	}

	boolean isUniqHash(String s)
	{
		HashMap<Character,Integer> h = new HashMap<Character,Integer>();

		for(int i=0;i<s.length();i++)
		{
					
			if(h.containsKey(s.charAt(i)))
				return false;
			else
				h.put(s.charAt(i),1);
		}

		return true;
	}

	public static void main(String [] args)
	{
		Unique u = new Unique();

		System.out.println(u.isUniq("abcc"));
		System.out.println(u.isUniqHash("abcc"));	
	}

}
