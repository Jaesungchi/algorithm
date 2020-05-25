//[로또 난이도★](https://www.acmicpc.net/problem/6603)

var N : List<Int>? = null

fun DFS(arr : ArrayList<Int>, index : Int){
    if(index >= N!!.size){
        if(arr.size != 6)
            return
        for(i in arr)
            print("$i ")
        println()
        return
    }
    arr.add(N!![index])
    DFS(arr,index+1)
    arr.remove(N!![index])
    DFS(arr,index+1)
}

fun main(){
    while(true) {
        N = readLine()?.split(" ")?.map { it.toInt() }
        if(N!![0] == 0)
            break
        DFS(arrayListOf(),1)
        println()
    }
}
