package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*;

/**
 * This is a self made simple problem. Given a grid and each of the element of the grid contains these 4 types of characters:
 * . -> blank space
 * X -> obstacle
 * S -> start point
 * E -> End point
 *
 * A robot can move into 4 directions only and staring form 'S' it wants to go to 'E'. Find minimum possible move required.
 */
class BFS_OnGrid_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    val dx = intArrayOf(-1, 0, 1, 0, -1, 1, 1, -1)
    val dy = intArrayOf(0, 1, 0, -1, 1, 1, -1, -1)

    var ROWS : Int = 0
    var COLS : Int = 0

    var grid : Array<CharArray> = Array(0) { CharArray(0) }
    var color : Array<ByteArray> = Array(0) { ByteArray(0) }
    var dist : Array<IntArray> = Array(0) { IntArray(0) }
    var sPoint : Pair = Pair()
    var ePoint : Pair = Pair()

    class Pair {
        var x : Int = 0
        var y : Int = 0

        constructor() {}
        constructor(x: Int, y: Int) {
            this.x = x
            this.y = y
        }
    }

    fun onGrid(p : Pair) : Boolean {
        return (p.x in 0 until ROWS) && (p.y in 0 until COLS)
    }

    fun BFS() : Int {
        color = Array(ROWS) { ByteArray(COLS) }
        dist = Array(ROWS) { IntArray(COLS) {Int.MAX_VALUE} }
        var Q : Queue<Pair> = LinkedList()

        dist[sPoint.x][sPoint.y] = 0
        Q.offer(sPoint)
        color[sPoint.y][ePoint.y] = GRAY

        while (!Q.isEmpty()) {
            var u : Pair = Q.poll()
            if (u == ePoint) break

            var curDist = dist[u.x][u.y] + 1
            for (i in 0 until 4) {
                var v : Pair = Pair(u.x + dx[i], u.y + dy[i])
                if (!onGrid(v)) continue
                if (curDist < dist[v.x][v.y]) {
                    Q.offer(v)
                    dist[v.x][v.y] = curDist
                }
            }
        }
        return dist[ePoint.x][ePoint.y]
    }

    fun fakeMain() {
        var scanner : Scanner? = inputFromFile()

        ROWS = scanner!!.nextInt()
        COLS = scanner!!.nextInt()
        scanner.nextLine()

        grid = Array(ROWS) {CharArray(0)}
        for (i in 0 until ROWS) {
            var line = scanner!!.nextLine()
            grid[i] = line.toCharArray()
            for (j in 0 until COLS) {
                if (grid[i][j] == 'S') sPoint = Pair(i, j)
                if (grid[i][j] == 'E') ePoint = Pair(i, j)
            }
        }

        BFS()

        println(dist[ePoint.x][ePoint.y])
    }
}

fun main(args : Array<String>) {
    BFS_OnGrid_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}

/**
INPUT:
4 4
....
...E
SX..
....
OUTPUT:
4
 **/