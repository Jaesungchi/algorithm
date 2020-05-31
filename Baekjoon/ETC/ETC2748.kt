import java.util.*

//[피보나치수2](https://www.acmicpc.net/problem/2748)

fun main() = with(Scanner(System.`in`)){
    var arr = MutableList<Long>(91){0}
    fun fibo( t : Int) : Long{
        if(t == 0) return 0
        if(t == 1) return 1
        if(arr[t] == 0.toLong())
            arr[t] = fibo(t-1) + fibo(t-2)
        return arr[t]
    }
    println(fibo(nextInt()))
}