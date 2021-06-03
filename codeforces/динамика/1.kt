    import java.math.BigInteger
    import kotlin.math.*
    import kotlin.system.exitProcess
    import java.util.Scanner
    fun readInt(): Int {
        return readLine()!!.toInt()
    }
    
    fun readLong(): Long {
        return readLine()!!.toLong()
    }
    
    fun readBigInt(): BigInteger {
        return readLine()!!.toBigInteger()
    }
    
    fun readInts(): List<Int> {
        return readLine()!!.split(" ").map(String::toInt)
    }
    
    fun readLongs(): List<Long> {
        return readLine()!!.split(" ").map(String::toLong)
    }
    
    fun readBigInts(): List<BigInteger> {
        return readLine()!!.split(" ").map(String::toBigInteger)
    }

    fun main() {
        val input = Scanner(System.`in`)
        val t: Int = readInt()
        for (i in 0 until t) {
            val (n, k1, k2) = readLine()!!.split(" ").map(String::toInt)
            var cnt: Int = 0
            val a = readLine()
            var pos: Int = k2
            for(j in 0 until n) {
                if(a!![j] == '0') {
                    pos = k2
                }
                else {
                    if(pos >= k1) {
                        cnt += k1
                        pos -= k1
                    }
                    else{
                        cnt += pos
                        pos = k2 - pos
                    }
                    
                }
            }
            println(cnt)
        }
    }