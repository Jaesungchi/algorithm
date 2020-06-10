import java.util.*
//[외판원 순회2](https://www.acmicpc.net/problem/10971)
fun main() = with(Scanner(System.`in`)) {
    var N = nextLine().toInt()
    var arr = List(N){nextLine().split(" ").map{it.toInt()}}
    var chk = BooleanArray(N){false}
    var output = 98765432
    fun DFS(index : Int, cost : Int, cnt : Int,start : Int){
        if(cnt == N) {
            if (arr[index][start] != 0) output = Math.min(cost + arr[index][start],output)
            return
        }
        for (i in 0 until N) {
            if (chk[i] || arr[index][i] == 0 || i == start) continue
            chk[i] = true
            DFS(i, cost + arr[index][i], cnt + 1, start)
            chk[i] = false
        }
    }
    for(i in 0 until N) DFS(i, 0, 1, i)
    println(output)
}