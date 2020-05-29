import java.util.*
import kotlin.math.*

//[뱀 난이도★★★★](https://www.acmicpc.net/problem/10875)

var dx = listOf(1,0,-1,0)
var dy = listOf(0,-1,0,1)
var x = 0
var y = 0
var nowdir = 0 //내 방향
var allTime : Long = 0 //총 시간.

data class Line(val x1:Int, val x2 : Int, val y1 : Int, val y2 : Int,var dir : Int) //dir 0 가로 1 세로
var lines : ArrayList<Line> = arrayListOf()

fun addLine(x1: Int, x2:Int, y1: Int,y2: Int){
    var dir = 0
    if (y1 != y2)
        dir = 1
    lines.add(Line(min(x1,x2),max(x1,x2),min(y1,y2),max(y1,y2),dir))
}

fun canGo() : Int{
    var result : Int = 2000000000
    for (i in lines){
        if(i.dir == 0){ //가로인경우
            if(nowdir == 0 && y == i.y1 && x < i.x1) //오른쪽으로 가는중.
                result = min(result,i.x1-x)
            else if (nowdir == 1 && i.x1 <= x && x <= i.x2 && i.y1 < y)
                result = min(result,y - i.y1)
            else if (nowdir == 2 && y == i.y1 && i.x2 < x)
                result = min(result,x-i.x2)
            else if (nowdir == 3 && i.x1 <= x && x <= i.x2 && y < i.y1)
                result = min(result,i.y1-y)
        }
        else{ //세로인 경우
            if (nowdir == 0 && i.y1 <= y && y <= i.y2 && x < i.x1)
                result = min(result,i.x1-x)
            else if (nowdir == 1 && x == i.x1 && i.y2 < y)
                result = min(result,y-i.y2)
            else if (nowdir == 2 && i.y1 <= y && y <= i.y2 && i.x1 < x)
                result = min(result, x - i.x1)
            else if (nowdir == 3 && x == i.x1 && y < i.y1)
                result = min(result,i.y1-y)
        }
    }
    return result
}

fun main() = with(Scanner(System.`in`)){
    var l = nextInt()
    var tmp1 = -l -1
    var tmp2 = l+1
    addLine(tmp1,tmp1,tmp1,tmp2)
    addLine(tmp1,tmp2,tmp1,tmp1)
    addLine(tmp1,tmp2,tmp2,tmp2)
    addLine(tmp2,tmp2,tmp1,tmp2)
    repeat(nextInt()){
        var t = nextInt()
        var dir = next()
        var go = canGo()
        if(go <= t){
            println(allTime + go)
            return
        }
        allTime += t
        var tx = x + t * dx[nowdir]
        var ty = y + t * dy[nowdir]
        if(dir[0] == 'L')
            nowdir = (nowdir+3)%4
        else
            nowdir = (nowdir+1)%4
        addLine(x,tx,y,ty)
        x = tx
        y = ty
    }
    var go = canGo()
    println(allTime+go)
}