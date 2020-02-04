import java.util.*

//[피보나치함수](https://www.acmicpc.net/problem/1003)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var DP = Array(41){Pair<Long,Long>(0,0)} //앞은 값 뒤는 0,1 횟수
    DP[0] = Pair<Long,Long>(1,0)
    DP[1] = Pair<Long,Long>(0,1)

    for(n in 2..40)
        DP[n] = Pair(DP[n-1].first+DP[n-2].first,DP[n-1].second+DP[n-2].second)

    repeat(nextInt()){
        var output = nextInt()
        println("${DP[output].first} ${DP[output].second}")
    }
}