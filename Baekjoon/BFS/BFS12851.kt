import java.util.*
//[숨바꼭질2](https://www.acmicpc.net/problem/12851)
fun main() = with(Scanner(System.`in`)){
    var (N,K) = nextLine().split(" ").map{it.toInt()}
    var chk = MutableList(100001){100001}
    var q : Queue<Int> = LinkedList()
    q.add(N)
    chk[N] = 0
    var cnt = 0
    while(!q.isEmpty()){
        var pos = q.poll()
        if(pos == K) cnt++
        if(chk[K] <= chk[pos]) continue
        if(pos > 0 && chk[pos-1] >= chk[pos]+1) {
            chk[pos-1] = chk[pos]+1
            q.add(pos - 1)
        }
        if(pos < 100000 && chk[pos+1] >= chk[pos]+1) {
            chk[pos+1] = chk[pos]+1
            q.add(pos + 1)
        }
        if(pos*2 <= 100000 && chk[pos*2] >= chk[pos]+1) {
            chk[pos*2] = chk[pos]+1
            q.add(pos * 2)
        }
    }
    println(chk[K])
    println(cnt)
}