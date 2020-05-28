import java.util.*

//[수면장애](https://www.acmicpc.net/problem/12755)

fun main() = with(Scanner(System.`in`)){
    var target = nextInt()
    var datas : String? = "1"
    var plus = 1
    while(target > datas!!.length){
        target -= datas!!.length
        plus++
        datas = plus.toString()
    }
    println(datas.get(target-1))
}