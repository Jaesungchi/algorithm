import java.util.*

//[구슬탈출 2 난이도★★★](https://www.acmicpc.net/problem/13460)

var dy = listOf(0,1,0,-1)
var dx = listOf(1,0,-1,0)

data class ball (var x:Int,var y:Int)
var arr : ArrayList<String> = arrayListOf()
var chk : List<List<List<MutableList<Boolean>>>> = List(10) { List(10) { List(10) { MutableList(10) { false } } } }

fun move(b : ball, i : Int) : ball{
    while(true){
        b.x += dx[i]
        b.y += dy[i]
        if(arr[b.y][b.x] == '#') {
            b.x -= dx[i]
            b.y -= dy[i]
            break
        }
        else if(arr[b.y][b.x] == 'O')
            break
    }
    return b
}

fun main() = with(Scanner(System.`in`)){
    var (N,M) = nextLine().split(" ").map{it.toInt()}
    var output = -1
    repeat(N){
        arr.add(nextLine())
    }
    fun findPos(c:Char)= ball( arr.find{c in it}!!.indexOf(c), arr.indexOfFirst { c in it })
    var red = findPos('R')
    var blue = findPos('B')
    var goal = findPos('O')

    var q : Queue<Pair<Pair<ball,ball>,Int>> = LinkedList()
    q.add(Pair(Pair(red,blue),0))
    chk[red.x][red.y][blue.x][blue.y] = true
    while(!q.isEmpty()){
        var tmpR = q.peek().first.first
        var tmpB = q.peek().first.second
        var cnt = q.poll().second
        if(cnt > 10) break
        if(tmpR == goal){
            output = cnt
            break
        }
        for( i in 0..3){
            var tR = move(tmpR.copy(),i)
            var tB = move(tmpB.copy(),i)
            if (tB == goal) continue
            if (tR == tB){
                if(i == 0)
                    if(tmpR.x < tmpB.x) tR.x-- else tB.x--
                if(i == 1)
                    if(tmpR.y < tmpB.y) tR.y-- else tB.y--
                if(i == 2)
                    if(tmpR.x < tmpB.x) tB.x++ else tR.x++
                if(i == 3)
                    if(tmpR.y < tmpB.y) tB.y++ else tR.y++
            }
            if(chk[tR.x][tR.y][tB.x][tB.y])
                continue
            q.add(Pair(Pair(tR,tB),cnt+1))
            chk[tR.x][tR.y][tB.x][tB.y] = true
        }
    }
    println(output)
}