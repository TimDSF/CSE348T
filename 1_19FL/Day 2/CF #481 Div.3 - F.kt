// Copyright @ Tim Dong 2020

fun main()=with(java.util.Scanner(System.`in`)){
    fun lower_bound(l_:Int,h_:Int,query:Int,list:List<Int>):Int{
        var l=l_
        var h=h_
        while(h>l){
            val m=(h+l)/2
            if (list[m]<query) l=m+1
            else h=m
        }
        return h
    }
    val n=nextInt()
    val k=nextInt()
    val s=Array(n){nextInt()}
    val ss=s.copyOf().sorted()
    val g=Array(n){ArrayList<Int>()}
    repeat(k){
        val x=nextInt() - 1
        val y=nextInt() - 1
        g[x].add(y)
        g[y].add(x)
    }
    for (i in 0 until n) {
        val fp=Math.max(lower_bound(0,n - 1,s[i],ss),0)
        val quarrels=g[i].count{s[it]<s[i]}
        print("${fp-quarrels} ")
    }
}