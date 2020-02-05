import java.util.*

//[평범한 배낭 코틀린버전](https://www.acmicpc.net/problem/12865)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    val N = nextInt()
    val mMax = nextInt()
    var map = arrayListOf<Pair<Int,Int>>()
    var DP = Array(mMax+1){0}
    for(i in 0 until N)
        map.add(Pair(nextInt(),nextInt()))
    for(i in 0 until N)
        for(j in mMax downTo map[i].first)
            DP[j] = DP[j].coerceAtLeast(DP[j - map[i].first] + map[i].second)
    println(DP[mMax])
}