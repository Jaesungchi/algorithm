import java.util.*

//[레이저빔은 어디로](https://www.acmicpc.net/problem/3709)

fun main() = with(Scanner(System.`in`)) {
    var dx = listOf(0,1,0,-1)
    var dy= listOf(-1,0,1,0)
    repeat(nextLine().toInt()){
        var (n,r) = nextLine().split(" ").map{it.toInt()}
        var maps = List(n+2){BooleanArray(n+2){false}}
        repeat(r){
            var (a,b) = nextLine().split(" ").map{it.toInt()}
            maps[a][b] = true
        }
        var (y,x) = nextLine().split(" ").map{it.toInt()}
        var dir = if(x == 0) 1 else if (y == 0) 2 else if (y > n) 0 else 3
        y += dy[dir]
        x += dx[dir]
        while(x in 1..n && y in 1.. n){
            if(maps[y][x])// 회전
                dir = (dir + 1) % 4
            y += dy[dir]
            x += dx[dir]
        }
        println("$y $x")
    }
}