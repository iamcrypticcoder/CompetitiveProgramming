package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*
import kotlin.collections.ArrayList

class BipartiteCheck_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES : Int = 0
    var EDGES : Int = 0

    var G : Array<MutableList<Int>> = emptyArray()
    var color : ByteArray = ByteArray(0)

    var leftCount : Int = 0
    var rightCount : Int = 0

    // Using DFS
    // Stop when any color conflict happen
    fun isBipartite1(u : Int, c : Byte) : Boolean {
        color[u] = c
        var c = if (c == GRAY) BLACK else GRAY
        var ret = true
        for (i in 0 until G[u].size) {
            var v = G[u][i]
            if (color[v] == color[u]) return false
            if (color[v] == WHITE) ret = ret && isBipartite1(v, c)
        }
        return ret
    }

    // Using DFS
    // Keep coloring the nodes until connected component ends
    fun isBipartite2(u : Int, c : Byte) : Boolean {
        color[u] = c
        var c = if (c == GRAY) BLACK else GRAY

        var ret = true
        for (i in 0 until G[u].size) {
            var v = G[u][i]
            if (color[v] == WHITE) ret = isBipartite2(v, c) && ret;
            else if (color[v] == color[u]) ret = false
        }
        return ret
    }

    // Using DFS.
    // Stop when any color conflict happen.
    // Count nodes in left and right sides.
    fun isBipartite3(u : Int, c : Byte) : Boolean {
        color[u] = c
        if (c == GRAY) leftCount++
        else rightCount++
        var c = if (c == GRAY) BLACK else GRAY

        var ret = true
        for (i in 0 until G[u].size) {
            var v = G[u][i]
            if (color[v] == color[u]) return false
            if (color[v] == WHITE) ret = ret && isBipartite1(v, c)
        }
        return ret
    }

    // Using BFS.
    // Stop when any color conflict happen.
    // Count nodes in left and right sides.
    fun isBipartite4(s : Int) : Boolean {
        var ret = true

        var Q : Queue<Int> = LinkedList()
        Q.offer(s)
        color[s] = GRAY
        leftCount++

        while (!Q.isEmpty()) {
            var u = Q.poll()
            for (i in 0 until G[u].size) {
                var v = G[u][i]
                if (color[v] == WHITE) {
                    color[v] = if (color[u] == GRAY) BLACK else GRAY
                    Q.offer(v)
                    if (color[v] == GRAY) leftCount++
                    else rightCount++
                } else if (color[v] == color[u]) {
                    return false
                }
            }
        }

        return ret
    }

    fun fakeMain() {
        var scanner = inputFromFile()

        while (scanner!!.hasNext()) {
            NODES = scanner.nextInt()
            EDGES = scanner.nextInt()

            G = Array(NODES+1) { ArrayList<Int>() }

            for (i in 0 until EDGES) {
                var u = scanner.nextInt()
                var v = scanner.nextInt()

                G[u].add(v)
                G[v].add(u)
            }

            color = ByteArray(NODES+1)
            println(isBipartite1(0, GRAY))
            for (x in color) print("$x ")
        }
    }
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}