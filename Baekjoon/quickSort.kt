import java.lang.Math.random
import java.util.*

/**
 * 원하는 사이즈의 값을 입력하면 랜덤으로 0~100까지의 수를 만듭니다.(중복 도됨)
 * My 는 제가 만든 Quick_sort 이고 Co 는 지원해주는 Sort 입니다. 정답 비교용으로 출력했습니다.
 */

/**
 * data = 현재 리스트 , left = pivot이 되는 지점, right = 어디까지 비교
 */
fun quick_sort( data : Array<Int>, left : Int,right : Int){
    if(left >= right) return
    var i = left+1
    var j = right
    while(i <= j){
        while(i <= right && data[i] < data[left]) i++ //pivot 보다 큰값이 나오면 멈춘다
        while(j > left && data[j] >= data[left]) j-- //pivot 보다 작거나 같은 값이 나오면 멈춘다.
        if(i <= j) data[i] = data[j].also{data[j]=data[i]} //아직 i 가 작으니 자체 교환
    }
    data[left] = data[j].also{data[j] = data[left]}
    quick_sort(data,left,j-1)
    quick_sort(data,j+1,right)
}

fun main(args:Array<String>) = with(Scanner(System.`in`)){
    var data = Array(nextInt()){0}
    for(i in 0 until data.size)
        data[i] = (random() * 100).toInt()
    println(data.joinToString(" "))
    quick_sort(data,0,data.size-1)
    println("My = " + data.joinToString(" "))
    data.sortedArray()
    println("Co = " + data.joinToString(" "))
}