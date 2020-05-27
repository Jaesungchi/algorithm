import java.util.*

//[순열 사이클★](https://www.acmicpc.net/problem/10451)

fun main() = with(Scanner(System.`in`)){
    repeat(nextLine().toInt()){
        var N = nextInt()
        var arr = MutableList(N) {nextInt()}
        var cnt = 0
        for(i in 0 until arr.size){
            if (arr[i] <= 0)
                continue
            cnt -= 1
            var next = arr[i]-1
            arr[i] = cnt
            while(arr[next] > 0){
                var tmp = arr[next]
                arr[next] = cnt
                next = tmp -1
            }
        }
        println( cnt * -1 )
    }
}