import java.util.*

//[별찍기-13](https://www.acmicpc.net/problem/2523)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var A = nextInt()
    for(i in 1 until A*2){
        if(i <= A){
            for(j in 1 .. i) print("*")
            println()
        }
        else{
            for(j in 1.. A*2-i) print("*")
            println()
        }
    }
}