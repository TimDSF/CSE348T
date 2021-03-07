// Copyright @ Tim Dong 2020

fun main()=with(java.util.Scanner(System.`in`)){
    val n=nextInt()
    val m=nextInt()
    val a=Array(n){nextInt()}

    var index=0
    for (i in 0 until n){
        if (a[i]==m){
            index=i
            break
        }
    }

    var f0=Array(2*n+1){0}
    var f1=Array(2*n+1){0}

    var tmp=0
    f1[0+n]++

    for (i in index-1 downTo 0){
        tmp+=(if (a[i]>a[index]) 1 else -1)
        if ((index-i)%2==0) f1[tmp+n]++ else f0[tmp+n]++
    }

    var ans:Long=(f0[1+n]+f1[0+n]).toLong();
    tmp=0
    for (i in index+1 until n){
        tmp+=(if (a[i]>a[index]) 1 else -1)
        if ((i-index)%2==0) ans+=f0[1-tmp+n]+f1[-tmp+n] else ans+=f1[1-tmp+n]+f0[-tmp+n]
    }
    println(ans)
}