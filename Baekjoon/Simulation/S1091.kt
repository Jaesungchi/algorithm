import java.util.*
//[카드섞기](https://www.acmicpc.net/problem/1091)
fun main() = with(Scanner(System.`in`)) {
    var n = nextLine().toInt()
    var p = nextLine().split(" ").map{it.toInt()}.toMutableList()
    for(i in 0 .. n*2) p.add(0)
    var s = nextLine().split(" ").map{it.toInt()}.toMutableList()
    var output = 0
    fun isSame() : Boolean{
        for (i in 0 until n)
            if(p[i] != i%3) return false
        return true
    }
    while(true){
        if(isSame()) break
        for(i in 0 until n) p[n+s[i]] = p[i]
        for(i in 0 until n) p[i] = p[n+i]
        output++
        if(output > 1e7) {
            output = -1
            break
        }
    }
    println(output)
}