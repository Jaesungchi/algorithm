import java.util.*
//[숨바꼭질4](https://www.acmicpc.net/problem/13913)
fun main() = with(Scanner(System.`in`)) {
    var (N,K) = nextLine().split(" ").map{it.toInt()}
    var arr = IntArray(100001){-1}
    var q : Queue<Pair<Int,Int>> = LinkedList()
    q.add(Pair(N,0))
    arr[N] = -2
    while(!q.isEmpty()){
        var index = q.peek().first
        var cnt = q.poll().second
        if(index == K){
            println(cnt)
            break
        }
        fun good(t : Int){
            if(t in 0..100000 && arr[t] == -1){
                arr[t] = index
                q.add(Pair(t,cnt+1))
            }
        }
        good(index+1)
        good(index-1)
        good(index*2)
    }
    var output : Stack<Int> = Stack()
    var tmp = K
    while(tmp != N){
        output.add(tmp)
        tmp = arr[tmp]
    }
    output.add(N)
    while(!output.isEmpty()){
        print("${output.pop()} ")
    }
}