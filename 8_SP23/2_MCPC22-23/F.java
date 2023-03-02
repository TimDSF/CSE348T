import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/lang/Object.html
public class F {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] values = br.readLine().split(" ");
        int a = Integer.parseInt(values[0]);
        int b = Integer.parseInt(values[1]);
        int n = Integer.parseInt(values[2]);

        int[][] blades = new int[n+1][2];
        for (int i = 0; i < n; i++) {
            values = br.readLine().split(" ");
            blades[i][0] = Integer.parseInt(values[0]);
            blades[i][1] = Integer.parseInt(values[1]);
        }
        blades[n][0] = b;
        blades[n][1] = Integer.MAX_VALUE;

        Arrays.sort(blades, (aa, bb) -> bb[0] - aa[0]);

        if (a > blades[0][0]) {
            System.out.println(-1);
            return;
        }

        int curr = a;
        int minBlade = Integer.MAX_VALUE;
        int idx = 0;

        double total = 0;
        while (idx < n && curr > b) {
            while (idx < n && blades[idx][0] >= curr) {
                minBlade = Math.min(minBlade, blades[idx][1]);
                idx++;
            }
            total += Math.log(curr / (double) blades[idx][0]) / Math.log(2) * minBlade;
            curr = blades[idx][0];
        }

        System.out.println(total);


    }
}