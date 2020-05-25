import java.util.*
import kotlin.collections.ArrayList

//[토마토 난이도★](https://www.acmicpc.net/problem/7576)

var dx = listOf(-1,0,1,0)
var dy = listOf(0,-1,0,1)

fun main(){
    var output = 0
    var NM = readLine()?.split(" ")?.map{it.toInt()}
    var arr : ArrayList<MutableList<Int>?> = arrayListOf()
    var q : Queue<Pair<Pair<Int, Int>,Int>> = LinkedList() //큐 선언시 LinkedList()로 선언
    repeat(NM!![1]) { i ->
        var tmp = readLine()?.split(" ")?.map { it.toInt() }?.toMutableList()
        repeat(tmp!!.size){ j ->
            if(tmp[j] == 1) {
                q.add(Pair(Pair(i, j),0))
                tmp[j] = -1
            }
        }
        arr.add(tmp)
    }
    while(!q.isEmpty()){
        var dir = q.poll()
        var cnt = dir.second
        output = cnt
        repeat(4){ i ->
            var ty = dir.first.first + dy[i]
            var tx = dir.first.second + dx[i]
            if(ty >= 0 && tx >= 0 && ty < NM!![1] && tx < NM!![0] && arr.get(ty)?.get(tx) == 0 ) {
                arr.get(ty)!![tx] = -1
                q.add(Pair(Pair(ty, tx), cnt + 1))
            }
        }
    }
    for(i in arr)
        for(j in i!!)
            if(j == 0) {
                println(-1)
                return
            }
    println(output)
}
