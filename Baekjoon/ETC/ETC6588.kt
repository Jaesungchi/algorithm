import java.util.*
//[골드바흐의 추측](https://www.acmicpc.net/problem/6588)
fun main() = with(Scanner(System.`in`)){
    var sosu = MutableList(1000001){true}
    for (i in 2..1000000)
        for(j in i * 2..1000000 step i) {
            if (!sosu[j]) continue
            sosu[j] = false
        }
    while(true){
        var n = nextInt()
        if(n == 0) return
        var isGood = false
        for(i in 2..n/2)
            if(sosu[i] && sosu[n-i]){
                println("$n = $i + ${n-i}")
                isGood = true
                break
            }
        if(!isGood) println("Goldbach's conjecture is wrong.")
    }
}