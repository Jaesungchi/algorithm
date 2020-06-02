import java.util.*
//[결혼식](https://www.acmicpc.net/problem/5567)
fun main() = with(Scanner(System.`in`)){
    var n = nextLine().toInt()
    var arr = List(n+1){ ArrayList<Int>(0) }
    var chk = IntArray(n+1){0}
    repeat(nextLine().toInt()){
        var (a,b) = nextLine().split(" ").map{it.toInt()}
        arr[a].add(b)
        arr[b].add(a)
    }
    var q : Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(1,0))
    chk[1] = 2
    while(!q.isEmpty()){
        var pos = q.peek().first
        var one = q.poll().second
        for(i in arr[pos]){
            if(chk[i] != 0 && chk[i] <= one+1)
                continue
            chk[i] = one+1
            if(chk[i] < 2) q.add(Pair(i,chk[i]))
        }
    }
    println(chk.count{it > 0}-1)
}