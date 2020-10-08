// Copyright @ Tim Dong 2020

fun main()=with(java.util.Scanner(System.`in`)) {
    val n=nextInt()
    val m=nextInt()
    var index=0
    var f=Array(2){Array(n){0}}
    val a=Array(n){nextInt()}
    for (i in 0 until n){
        if (a[i]==m){
            index=i
            break
        }
    }
    var ans=1
    f[index%2][index]=0
    for (i in index downTo 0){
        if (i!=index){
            f[i%2][index]=f[1-i%2][index]+(if (a[i]>a[index]) 1 else -1)
            if ((index-i)%2==0 && f[i%2][index]==0 || (index-i)%2==1 && f[i%2][index]==1) ans++
        }
        for (j in index+1 until n){
            f[i%2][j]=f[i%2][j-1]+(if (a[j]>a[index]) 1 else -1)
            if ((j-i)%2==0 && f[i%2][j]==0 || (j-i)%2==1 && f[i%2][j]==1) ans++
        }
    }
    println(ans)
}
