package stringint;
import java.lang.Integer;
public class stringint 
{
	public static void main(String[] args)
	{
		String str1 = "-7a23bc";
	    // 1. null or empty string
	    if (str1 == null || str1.length() == 0) 
	    	System.out.print(0);
	    
	    // 2. whitespaces
	    str1 = str1.trim();
	    
	    // 3. +/- sign
	    boolean positive = true;
	    int i = 0;
	    if (str1.charAt(0) == '+') 
	    {
	        i++;
	    } else if (str1.charAt(0) == '-') 
	    {
	        positive = false;
	        i++;
	    }
	    
	    // 4. calculate real value
	    double tmp = 0;
	    for ( ; i < str1.length(); i++) 
	    {
	        int digit = str1.charAt(i) - '0';
	        
	        if (digit < 0 || digit > 9) break;
	        
	        // 5. handle min & max
	        if (positive) 
	        {
	            tmp = 10*tmp + digit;
	            if (tmp > Integer.MAX_VALUE) 
	            	System.out.print(Integer.MAX_VALUE);
	        } 
	        else 
	        {
	            tmp = 10*tmp - digit;
	            if (tmp < Integer.MIN_VALUE) 
	            	System.out.print(Integer.MIN_VALUE);
	        }
	    }
	    
	    int ret = (int)tmp;
	    System.out.print(ret);
	}

}
