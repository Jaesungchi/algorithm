import java.util.*

//[단어의 개수](https://www.acmicpc.net/problem/1152)
//코틀린으로 문자열 처리 익히기 위해 푼 문제.

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var inputs = readLine().toString()
    if (inputs.length == 0) {
        println(0)
        return
    }
    if(inputs.get(0) == ' ')
        inputs = inputs.substring(1,inputs.length)
    if(inputs.length > 1 && inputs.get(inputs.length-1) == ' ')
        inputs = inputs.substring(0, inputs.length-1)
    var data = inputs.split(" ").map{it.toString()}
    if(data.size == 1 && data[0] == "")
        println(0)
    else
        println(data.size)
}
