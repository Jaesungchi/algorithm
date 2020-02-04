import java.util.*

//[배수찾기 코틀린](https://www.acmicpc.net/problem/4504)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var pivot = nextInt()
    var A = nextInt()
    while(A != 0){
        if(A % pivot != 0) println("$A is NOT a multiple of $pivot.")
        else println("$A is a multiple of $pivot.")
        A = nextInt()
    }
}