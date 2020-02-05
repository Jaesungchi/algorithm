import java.lang.Integer.max
import java.util.*

//[정수 삼각형](https://www.acmicpc.net/problem/1932)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    val N = nextInt()
    var map = ArrayList<Array<Int>>()
    for(i in 1 .. N) //1, 2, 3, 4 ... 자신의 갯수만큼만 받음
        map.add(Array(i){nextInt()})
    for(i in 1 until N){
        map[i][0] += map[i-1][0] //맨앞은 자기 위밖에 못받음
        for(j in 1 until i)
            map[i][j] += max(map[i-1][j-1],map[i-1][j])
        map[i][i] += map[i-1][i-1] //맨뒤는 자기 위밖에 못받음
    }
    println(map[N-1].max())
}