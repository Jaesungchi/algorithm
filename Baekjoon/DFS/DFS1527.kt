import java.util.*

//[금민수의 개수](https://www.acmicpc.net/problem/1527)

fun DFS(start : Int , end : Int, depth : Int, now : Int) : Int {
    var sum = 0
    if(depth >= 10 || now > end) return 0
    if(now >= start) sum += 1
    sum += DFS(start,end,depth+1,now*10+4)
    sum += DFS(start,end,depth+1,now*10+7)
    return sum
}

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var (N,M) = nextLine().split(" ").map{it.toInt()}
    println(DFS(N,M,0,0))
}
