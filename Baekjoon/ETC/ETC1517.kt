import java.util.*
//[버블소트](https://www.acmicpc.net/problem/1517)
fun main() = with(Scanner(System.`in`)) {
    var n = nextLine().toInt()
    var a = nextLine().split(" ").map{it.toInt()}.toMutableList()
    var output : Long = 0
    var tmp = MutableList(500010){0}
    fun merge(s:Int , e:Int){
        if(s == e) return
        var m = (s+e)/2
        merge(s,m)
        merge(m+1,e)
        var i = s
        var j = m+1
        var idx = 0
        while(i <= m || j <= e){
            if(i <=m &&(j > e || a[i] <= a[j])) tmp[idx++] = a[i++]
            else{
                output += (m-i+1)
                tmp[idx++] = a[j++]
            }
        }
        for(z in s..e) a[z] = tmp[z-s]
    }
    merge(0,n-1)
    println(output)
}