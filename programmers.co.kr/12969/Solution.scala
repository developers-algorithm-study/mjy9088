import scala.io.StdIn.readLine

object Solution {
    def main(args: Array[String]) {
        val n = readLine().split(" ")
        val (a, b) = (n(0).toInt, n(1).toInt)
        for(i <- 1 to b) {
            for(j <- 1 to a) {
                print("*")
            }
            println()
        }
    }
}