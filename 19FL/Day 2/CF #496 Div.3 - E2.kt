// Copyright @ Tim Dong 2020

fun main()=with(java.util.Scanner(System.`in`)){
    val n=nextInt()
    val m=nextInt()
    val a=Array(n){nextInt()}

    fun count(mm:Int):Long {
        var sum = Array(2 * n + 1) { 0 }
        sum[n]=1
        var dif = n
        var dlt: Long = 0
        var ans: Long = 0
        for (i in 0 until n) {
            if (a[i] < mm) {
                --dif
                dlt -= sum[dif]
            } else {
                dlt += sum[dif]
                ++dif
            }
            ans += dlt
            ++sum[dif]
        }
        return ans
    }

    println(count(m)-count(m+1))
}