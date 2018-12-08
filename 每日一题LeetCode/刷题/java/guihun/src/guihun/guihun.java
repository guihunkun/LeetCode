package guihun;

public class guihun 
{
	 private static int maxLen;
	private static int low;

	public static void main(String[] args) 
	 {
	        String s="asbsa";
	        //public String longestPalindrome(String s) 
	        
	            int len=s.length();
	            if(len<2) 
	            	System.out.println(s);
	            for(int i=0;i<len;i++)
	            {
	                extendPalindrome(s,i,i);//回文子串是奇数的情况
	                extendPalindrome(s,i,i+1);//回文子串是偶数的情况
	            }
	            System.out.println(s.substring(low, low+maxLen));        
		 //System.out.println("Hello World!");
	 }
	private static void extendPalindrome(String s, int j, int k) 
	{
        while(j>=0&&k<s.length()&&s.charAt(j)==s.charAt(k))
        {
            j--;
            k++;
        }
        if(maxLen<k-j-1)
        {
            low=j+1;
            maxLen=k-j-1;
        }
		
	}

}
