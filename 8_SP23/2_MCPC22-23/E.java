import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// E
public class E {
    
    private static int[][] b;
    private static List<int[]> res;

    private static void swap(int i, int ii, int j, int jj, int k) {
        if (ii == 1) {
            if (jj == 0) {
                res.add(new int[]{j, k});
                res.add(new int[]{j, k});
                res.add(new int[]{j, k});
                res.add(new int[]{i, j});
                res.add(new int[]{i, j});
                res.add(new int[]{k, i});
                res.add(new int[]{k, i});
                res.add(new int[]{k, j});
                int i1 = b[i][1];
                int i2 = b[i][2];
                b[i][1] = b[i][0];
                b[i][2] = b[j][1];
                b[j][0] = i2;
                b[j][1] = i1;

            } else if (jj == 1) {
                res.add(new int[]{j, k});
                res.add(new int[]{i, k});
                res.add(new int[]{i, k});
                res.add(new int[]{j, i});
                res.add(new int[]{k, i});
                res.add(new int[]{k, j});
                res.add(new int[]{k, j});
                int i1 = b[i][1];
                int i2 = b[i][2];
                b[i][1] = b[i][0];
                b[i][2] = i1;
                b[j][1] = i2;

            } else {
                // jj == 2
                res.add(new int[]{i, k});
                res.add(new int[]{i, k});
                res.add(new int[]{j, i});
                res.add(new int[]{k, j});
                res.add(new int[]{k, i});
                b[j][2] = b[i][1];
                b[i][1] = b[i][0];

            }
        } else {
            // ii == 2;
            if (jj == 0) {
                res.add(new int[]{j, k});
                res.add(new int[]{j, k});
                res.add(new int[]{i, k});
                res.add(new int[]{j, i});
                res.add(new int[]{k, j});
                res.add(new int[]{k, j});
                res.add(new int[]{k, j});

                b[j][0] = b[i][2];
                b[i][2] = b[i][1];

            } else if (jj == 1) {
                res.add(new int[]{j, k});
                res.add(new int[]{i, k});
                res.add(new int[]{j, i});
                res.add(new int[]{k, j});
                res.add(new int[]{k, j});

                b[j][1] = b[i][2];
                b[i][2] = b[i][1];
            } else {
                res.add(new int[]{i, k});
                res.add(new int[]{j, i});
                res.add(new int[]{k, j});

                b[j][2] = b[i][2];
                b[i][2] = b[i][1];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        b = new int[n+1][3];
        for (int i = 0; i <= n; i++) {
            String[] vals = br.readLine().split(" ");
            for (int j = 0; j <= 2; j++) {
                b[i][j] = Integer.parseInt(vals[j]);
            }
        }

        res = new ArrayList<>();


        int idx = 2;
        while (idx >= 0 && b[n][idx] == 0) {
            idx--;
        }
       // System.out.println("idx: " + idx);
        if (idx >= 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    if (b[i][j] == 0) {
//                        System.out.println("hi");
                        b[i][j] = b[n][idx];
                        b[n][idx] = 0;
                        res.add(new int[]{n, i});
                        idx--;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int base = b[i][0];
            for (int ii = 1; ii < 3; ii++) {
                if (b[i][ii] == base) {
                    continue;
                }
               // System.out.println("base: " + base + ", b[i][ii]: " + b[i][ii]);
                loop:
                for (int j = i+1; j < n; j++) {
                    for (int jj = 0; jj < 3; jj++) {
                        if (b[j][jj] == base) {
                            swap(i, ii, j, jj, n);
//                            System.out.println("ii: " + ii + ", " + "jj: " + jj);
//                            System.out.println("************");
//                            for (int[] arr : b) {
//                                System.out.println(arr[0] + " " + arr[1] + " " + arr[2]);
//                            }
//                            System.out.println(")))))))))))))");
                            break loop;
                        }
                    }
                }
            }

        }

        System.out.println(res.size());
        if (!res.isEmpty()) {
            for (int[] arr : res) {
                System.out.println((arr[0]+1) + " " + (arr[1]+1));
            }
        }

//        System.out.println("************");
//        for (int[] arr : b) {
//            System.out.println(arr[0] + " " + arr[1] + " " + arr[2]);
//        }
//        System.out.println(")))))))))))))");

    }
}
