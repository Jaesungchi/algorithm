import java.util.*
//[특정한 최단경로 난이도★★★★](https://www.acmicpc.net/problem/1504)
var N = 0
var arr = List(801){IntArray(801){0}}
var INF = 987654321
data class Point(var end: Int, var weight: Int) : Comparable<Point?> {
    override operator fun compareTo(o: Point?): Int {
        return weight - o!!.weight
    }
}

fun dijkstra(start : Int, end : Int) : Int{
    var dist = IntArray(N+1){INF}
    var chk = BooleanArray(N+1){false}
    var q : PriorityQueue<Point> = PriorityQueue()
    q.add(Point(start,0))
    dist[start] = 0
    while(q.isNotEmpty()){
        var idx = q.peek().end
        var weight = q.poll().weight
        if(chk[idx]) continue
        chk[idx] = true
        for(i in 1..N){
            if(arr[idx][i] == 0 || chk[i]) continue
            if(dist[i] > weight + arr[idx][i]){
                dist[i] = weight + arr[idx][i]
                q.add(Point(i,weight + arr[idx][i]))
            }
        }
    }
    return dist[end]
}

fun main() = with(Scanner(System.`in`)) {
    var (n,m) = nextLine().split(" ").map{it.toInt()}
    N = n
    for(i in 1..N) arr[i][i] = 0
    repeat(m){
        var (a,b,c) = nextLine().split(" ").map{it.toInt()}
        arr[a][b] = c
        arr[b][a] = c
    }
    var (t1,t2) = nextLine().split(" ").map{it.toInt()}
    dijkstra(1,0)
    dijkstra(t1,1)
    dijkstra(t2,2)
    var output = Math.min(dijkstra(1,t1)+dijkstra(t1,t2)+dijkstra(t2,N) , dijkstra(1,t2)+dijkstra(t2,t1)+dijkstra(t1,N))
    if(output == INF || output < 0) println(-1)
    else println(output)
}