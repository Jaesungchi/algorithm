//[설탕배달](https://www.acmicpc.net/problem/2839)

fun main(){
    var N = readLine()?.toInt()
    var five = N?.div(5)
    var output = -1
    for(i in five!! downTo 0){
        var data = N!! - (5*i)
        if(data.rem(3) != 0)
            continue //나눠지지않는다.
        output = data.div(3) + i
        break
    }
    println(output)
}
