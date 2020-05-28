import java.util.*

//[수 이어쓰기2](https://www.acmicpc.net/problem/1790)

fun main() = with(Scanner(System.`in`)){
    var maxi = nextInt()
    var target = nextInt()
    var final : Long = 0
    var tmp: Long = target.toLong()
    var cntLength : Long = 1
    var cntNum : Long = 9
    while (tmp > cntLength * cntNum){
        tmp -= (cntLength * cntNum)
        final += cntNum
        cntLength++
        cntNum *= 10
    }
    final += ((tmp - 1) / cntLength) + 1
    if (final > maxi)
        println(-1)
    else
        println(final.toString()[((tmp-1)%cntLength).toInt()])
}