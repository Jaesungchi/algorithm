// [터보소트](https://www.acmicpc.net/problem/3006)
// 세그먼트 트리 형태로 지우면서 해야함.

fun main(args:Array<String>) {
    var input = ArrayList<Int>()
    var arrSize = readLine()!!.toInt()
    var maxFind = arrSize
    var minFind = 1
    for(i in 0 until arrSize)
        input.add(readLine()!!.toInt())
    for (i in 0 until arrSize)
        if (i % 2 == 0) {
            println(input.indexOf(minFind))
            input.remove(minFind++)
        } else {
            println(input.size - input.indexOf(maxFind) - 1)
            input.remove(maxFind--)
        }
}
