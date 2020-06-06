class two{
    var x = 500
    var y = 500
    var Varr = List(1002){MutableList(1002){false}} //세로줄
    var Harr = List(1002){MutableList(1002){false}} //가로줄
    fun countBox() : Int{
        var cnt = 0
        for(i in 0..1000)
            for(j  in 0.. 1000)
                if(Harr[i][j] && Harr[i+1][j] && Varr[i][j] && Varr[i][j+1])
                    cnt++
        return cnt
    }
    fun solution(moves: Array<String>): Int {
        for(i in moves)
            when(i){
                "U" -> Varr[--y][x] = true
                "D" -> Varr[y++][x] = true
                "L" -> Harr[y][--x] = true
                "R" -> Harr[y][x++] = true
            }
        return countBox()
    }
}
/*
    var arr = arrayOf("U", "L", "D", "R", "R", "D", "D", "L", "U", "U")
    //"U", "L", "D", "R", "R", "D", "D", "L", "U", "U"
    //"U", "U", "R", "D", "L", "L", "L", "U", "R", "D", "D", "D", "L", "U", "R", "R", "R", "D", "L", "U"
    //"U", "R", "D", "L", "U", "R", "D", "L"
 */