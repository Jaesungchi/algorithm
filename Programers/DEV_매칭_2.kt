class one{
    var dy = listOf(0,1,1)
    var dx = listOf(1,1,0)

    fun solution(board: Array<IntArray>): Int {
        var answer: Int = 0

        fun run(x : Int, y : Int, ball : Int) : Boolean{
            for(i in 0 until 3){
                var tx = x
                var ty = y
                var cnt = 1
                for(j in 0 until 4){
                    tx += dx[i]
                    ty += dy[i]
                    if(board[ty][tx] == ball) cnt++
                    else break
                }
                if(cnt == 5) return true
            }
            return false
        }

        for(i in 0 until board.size)
            for(j in 0 until board[i].size){
                if(board[i][j] == 0) continue
                if(run(j,i,board[i][j])){
                    answer = board[i][j]
                    return answer
                }
            }
        return answer
    }
}
/*
    var board = ArrayList<IntArray>(0)
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 2, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    board.add("0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0".split(",").map{it.toInt()}.toIntArray())
    println(solution(board))
 */