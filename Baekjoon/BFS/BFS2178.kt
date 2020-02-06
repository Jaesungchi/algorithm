import java.util.*

//[미로 탐색](https://www.acmicpc.net/problem/2178)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    val dxy = listOf(Pair(-1,0),Pair(1,0),Pair(0,-1),Pair(0,1))
    val N = nextInt()
    val M = nextInt()
    var maps = Array<String>(N){next()}
    var check =Array(N){Array(M){false} }
    var q : Queue<Pair<Pair<Int,Int>,Int>> = LinkedList()
    check[0][0] = true
    q.add(Pair(Pair(0,0),1))
    while(!q.isEmpty()){
        var tmp = q.peek().first
        var dist = q.poll().second
        if(tmp.first == N-1 && tmp.second == M-1) {
            println(dist)
            return
        }
        for((dy,dx) in dxy){
            var moves = Pair(tmp.first+dy,tmp.second+dx)
            if(moves.toList().contains(-1) || moves.first >= N || moves.second >= M)
                continue
            if(maps[moves.first][moves.second] == '0' || check[moves.first][moves.second])
                continue
            check[moves.first][moves.second] = true
            q.add(Pair(moves,dist+1))
        }
    }
}