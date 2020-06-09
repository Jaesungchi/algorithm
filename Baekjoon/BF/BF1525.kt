import java.util.*
//[퍼즐](https://www.acmicpc.net/problem/1525)
fun main() = with(Scanner(System.`in`)) {
    var dy = listOf(0,0,-1,1)
    var dx = listOf(1,-1,0,0)
    var s = 0;
    var chk = hashSetOf<Int>()
    for(i in 0..2) {
        var t = nextLine().split(" ").map { it.toInt() }.toMutableList()
        for(j in t)
            s = if(j != 0) (s * 10) + j else (s*10) + 9
    }

    var q : Queue<Pair<Int,Int>> = LinkedList()
    fun addQ(data : Int, cnt : Int){
        if(chk.add(data))
            q.add(Pair(data,cnt))
    }
    addQ(s,0)
    while(q.isNotEmpty()){
        var t = q.peek().first
        var cnt = q.poll().second
        if(t == 123456789){
            println(cnt)
            return
        }
        var strT = t.toString()
        var x = strT.indexOf("9") / 3
        var y = strT.indexOf("9") % 3
        for(i in 0..3){
            var tx = x + dx[i]
            var ty = y + dy[i]
            var to = tx*3 +ty
            if(tx !in 0..2 || ty !in 0..2) continue
            var next = StringBuilder(strT)
            next.setCharAt(strT.indexOf('9'),next[to])
            next.setCharAt(to,'9')
            addQ(Integer.parseInt(next.toString()),cnt+1)
        }
    }
    println("-1")
}