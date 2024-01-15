import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;



public class ExamManip{
	public static void main(String[] args) throws IOException {
		FastScanner fs=new FastScanner(System.in);		
		int n = fs.nextInt();
		int k = fs.nextInt();
		String[] a = new String[n];
		for(int i =0;i<n;i++) {
			a[i]=fs.next();
		}
		int fin = 0;
		for(int num = 0; num<Math.pow(2, k);num++) {
			String kk =Integer.toBinaryString(num);
			StringBuilder st = new StringBuilder("");
			for(int jj=0;jj<kk.length();jj++) {
				if(kk.charAt(jj)=='1')
					st.append("T");
				else
					st.append("F");
			}
			String ans = st.toString();
			int min = Integer.MAX_VALUE;
			for(int i =0;i<n;i++) {
				int c=0;
				for(int jj=0;jj<kk.length();jj++)
					if(a[i].charAt(jj)==ans.charAt(jj)) {
						c++;
				}
				min=Math.min(c, min);
			}
			fin=Math.max(fin, min);
		}
		System.out.println(fin);
	}
		


			
	static class FastScanner {
	    BufferedReader br;
	    StringTokenizer st;
	    public FastScanner(InputStream i){
	        br = new BufferedReader(new InputStreamReader(i));
	        st = new StringTokenizer("");
	    }
	    public String next() throws IOException{
	        if(st.hasMoreTokens()) return st.nextToken();
	        else st = new StringTokenizer(br.readLine());
	        return next();
	    }
	    public long nextLong() throws IOException{ return Long.parseLong(next()); }
	    public int nextInt() throws IOException { return Integer.parseInt(next()); }
	    public double nextDouble() throws IOException { return Double.parseDouble(next()); }
	    public String nextLine() throws IOException {
	        if(!st.hasMoreTokens()) 
	            return br.readLine();
	        String ret = st.nextToken();
	        while(st.hasMoreTokens()) 
	            ret += " " + st.nextToken();
	        return ret;
	    }
	}
}

