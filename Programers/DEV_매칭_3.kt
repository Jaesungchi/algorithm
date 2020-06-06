class Three {
    fun solution(command: String, buttons: Array<String>, scores: IntArray): Int {
        var answer = 0

        fun DFS(cmd : String,score : Int){
            if(cmd.isEmpty()){
                if(score > answer)
                    answer = score
                return
            }
            for(i in 0 until buttons.size){
                if(cmd.length < buttons[i].length) continue
                var tmp = cmd.substring(0,buttons[i].length)
                if(tmp == buttons[i])
                    DFS(cmd.substring(tmp.length,cmd.length),score+scores[i])
            }
            DFS(cmd.substring(1,cmd.length),score+1)
        }

        DFS(command, 0)

        return answer
    }
}
/*
    var button = arrayOf("v>AB^CYv^XA","<v>A","^XAZ","Yv^XA",">AB^")
    var score = intArrayOf(50, 18, 20, 30, 25)
    println(three.solution("<v>AB^CYv^XAZ",button,score))

    var button = arrayOf("BCXY")
    var score = intArrayOf(2)
    println(three.solution("ABCXYZ",button,score))

 */