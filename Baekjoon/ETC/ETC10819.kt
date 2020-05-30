import java.util.*

//[차이를 최대로](https://www.acmicpc.net/problem/10819)

fun main() = with(Scanner(System.`in`)){
    var N = nextLine().toInt()
    var arr = MutableList(N){nextInt()}
    var result = 0
    for (i in 2 until N)
        N *= i
    repeat(N){
        arr.shuffle()
        var data = 0
        for(i in 0 until arr.size - 1)
            data += Math.abs(arr[i] - arr[i+1])
        if(data > result) result = data
    }
    println(result)
}