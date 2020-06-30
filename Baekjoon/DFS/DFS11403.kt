import java.util.*
//[경로찾기](https://www.acmicpc.net/problem/11403)
fun main() = with(Scanner(System.`in`)) {
    var n = nextLine().toInt()
    var arr = MutableList(n){nextLine().split(" ").map{it.toInt()}.toIntArray()}
    var chk = BooleanArray(n){false}

    fun DFS(index:Int, pos:Int){
        for(i in 0 until n)
            if(arr[index][i] == 1 && !chk[i]){
                arr[pos][i] = 1
                chk[i] = true
                DFS(i,pos)
            }
    }
    for(i in 0 until n) {
        chk = BooleanArray(n){false}
        DFS(i, i)
    }
    println(arr.map{it.joinToString(" ")}.joinToString ("\n"))
}