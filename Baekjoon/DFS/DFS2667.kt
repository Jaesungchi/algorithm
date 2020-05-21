import java.util.*

//[단지번호 붙이기](https://www.acmicpc.net/problem/2667)ㄴ
var arrSize : Int= 0
var inputs : Array<String>? = null
var chk : Array<Array<Int>>? = null
var output = ArrayList<Int>()
var dx = arrayOf(0,0,-1,1)
var dy = arrayOf(-1,1,0,0)
//계산된 갯수를 돌려준다.
fun DFS(y:Int,x:Int,num :Int) : Int{
    var sum = 1
    chk!![y][x] = num
    for(i in 0 until 4){
        var tx = x + dx[i]
        var ty = y + dy[i]
        if(tx < 0 || ty < 0 || tx >= arrSize || ty >= arrSize)
            continue
        if(inputs!![ty][tx] == '1' && chk!![ty][tx] == 0)
            sum += DFS(ty,tx,num)
    }
    return sum
}

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    arrSize = readLine()!!.toInt()
    inputs = Array(arrSize){next()}
    chk = Array(arrSize){Array(arrSize){0} }
    for(i in 0 until arrSize)
        for(j in 0 until arrSize)
            if(inputs!![i][j] == '1' && chk!![i][j] == 0) {
                var data = DFS(i,j,output.size+1)
                output.add(data)
            }
    println(output.size)
    output.sort()
    for(i in 0 until output.size)
        println(output[i])
}
