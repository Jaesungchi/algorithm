import java.util.*
//[산업 스파이의 편지](https://www.acmicpc.net/problem/3671)
fun main() = with(Scanner(System.`in`)) {
    var prime = BooleanArray(10000000){true}
    prime[0] = false
    prime[1] = false
    for(i in 2 until 10000000) {
        if(i*2 >= 10000000) break
        prime[i*2] = false
    }
    for(i in 3 until 10000000 step 2){
        if(i*i >= 10000000) break
        if(!prime[i]) continue
        for(j in i * 2 until 10000000 step i) prime[j] = false
    }
    repeat(nextLine().toInt()){
        var a = nextLine()
        var arr = MutableList(0){0}
        var chk = BooleanArray(a.length){false}
        var output = 0
        var sets : MutableSet<Int> = mutableSetOf()
        for(i in a.indices) arr.add(a[i]-'0')

        fun DFS(num : Int){
            if(prime[num] && sets.add(num)) output++
            for(i in 0 until arr.size){
                if(chk[i]) continue
                chk[i] = true
                DFS(num*10 + arr[i])
                chk[i] = false
            }
        }

        DFS(0)
        println(output)
    }
}