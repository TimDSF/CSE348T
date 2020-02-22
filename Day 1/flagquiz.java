// Copyright @ Xiaoyan Zheng 2020

import java.util.Scanner;

public class flagquiz {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        in.nextLine();
        int n = in.nextInt();
        in.nextLine();

        String[][] flag = new String[n][];
        int[] min = new int[n];
        int m;
        for (int i=0; i<n; ++i){
            flag[i] = in.nextLine().split(", ");
        }
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if(j==i)continue;
                m=0;
                for (int k=0; k<flag[0].length; ++k){
                    if(!flag[i][k].equals(flag[j][k])){
                        ++m;
                    }
                }
                if(m>min[i]) min[i]=m;
            }
        }

        m=min[0];
        for(int i=0;i<n;++i){
            if (m > min[i]) {
                m=min[i];
            }
        }
        int j;
        for(int i=0; i<n; ++i){
            if(min[i]==m){
                for(j=0;j<flag[0].length-1;++j){
                    System.out.print(flag[i][j]+", ");
                }
                System.out.print(flag[i][j]);
                System.out.println();
            }
        }
    }
}
