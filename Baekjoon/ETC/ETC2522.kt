import java.util.*

//[별찍기-12](https://www.acmicpc.net/problem/2522)

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var A = nextInt()
    for(i in 1 until A*2){
        if(i <= A){
            for(j in 1 .. A-i) print(" ")
            for(j in 1 .. i) print("*")
            println()
        }
        else{
            for(j in 1..i-A) print(" ")
            for(j in 1.. A*2-i) print("*")
            println()
        }
    }
}