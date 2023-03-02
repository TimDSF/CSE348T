import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;



public class TriCol{
	public static void main(String[] args) throws IOException {
		FastScanner fs=new FastScanner(System.in);	
		int cases = fs.nextInt();
		int[] k = new int[cases];
		for(int i=0;i<cases;i++) {
			k[i]=fs.nextInt();

		}
		Arrays.sort(k);
		long ans = 0;
		for(int i = 0;i<cases;i++) {
			for(int j = i+1;j<cases-1;j++) {
				int fin = cases-1;
				while(k[fin]>=k[j]+k[i]) {
					fin--;
				}
				if(fin > j) {
					ans += Math.pow(2, fin -j)-1;
				}
			}
		}
		System.out.println(ans);

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
	}}

