import java.util.*
//[숨바꼭질](https://www.acmicpc.net/problem/1697)
fun main() = with(Scanner(System.`in`)){
    var (N,K) = nextLine().split(" ").map{it.toInt()}
    var chk = MutableList(100001){false}
    var q :Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(N,0))
    chk[N] = true
    while(!q.isEmpty()){
        var pos = q.peek().first
        var times = q.poll().second
        if(pos == K) {
            println(times)
            break
        }
        if(pos > 0 && !chk[pos-1]) {
            chk[pos-1] = true
            q.add(Pair(pos - 1, times + 1))
        }
        if(pos < 100000 && !chk[pos+1]) {
            chk[pos+1] = true
            q.add(Pair(pos + 1, times + 1))
        }
        if(pos*2 <= 100000 && !chk[pos*2]) {
            chk[pos*2] = true
            q.add(Pair(pos * 2, times + 1))
        }
    }
}