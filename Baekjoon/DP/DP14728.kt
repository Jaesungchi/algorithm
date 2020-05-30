import java.util.*

//[벼락치기](https://www.acmicpc.net/problem/14728)

fun main() = with(Scanner(System.`in`)){
    var (N,M) = nextLine().split(" ").map{it.toInt()}
    var arr = MutableList(M+1){0}
    repeat(N){
        var (a,b) = nextLine().split(" ").map{it.toInt()}
        for(i in M downTo a) arr[i] = Math.max(arr[i],arr[i-a]+b)
    }
    println(arr[M])
}