import java.util.*
//[물통](https://www.acmicpc.net/problem/2251)
fun main() = with(Scanner(System.`in`)) {
    var (A,B,C) = nextLine().split(" ").map{it.toInt()}
    var chk = List(201){List(201){ BooleanArray(201){false} } }
    data class D(val a:Int,val b:Int,val c:Int)
    var q : Queue<D> = LinkedList()
    q.add(D(0,0,C))
    fun addQ(ta : Int, tb : Int, tc : Int){
        if(!chk[ta][tb][tc]) {
            chk[ta][tb][tc] = true
            q.add(D(ta,tb,tc))
        }
    }
    while(q.isNotEmpty()){
        var a = q.peek().a
        var b = q.peek().b
        var c = q.poll().c

        if(a+b > B) addQ(a+b-B,B,c)
        else addQ(0,a+b,c)

        if(a+b > A) addQ(A,a+b-A,c)
        else addQ(a+b,0,c)

        if(a+c > C) addQ(a+c-C,b,C)
        else addQ(0,b,a+c)

        if(a+c > A) addQ(A,b,a+c-A)
        else addQ(a+c,b,0)

        if(b+c > B) addQ(a,B,b+c-B)
        else addQ(a,b+c,0)

        if(b+c > C) addQ(a,b+c-C,C)
        else addQ(a,0,b+c)
    }
    print((0..C).filter{ c -> (0..B).any{b->chk[0][b][c]}}.joinToString(" "))
}