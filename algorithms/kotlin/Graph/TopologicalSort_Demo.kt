package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*
import kotlin.collections.ArrayList

class TopologicalSort_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES : Int = 0
    var EDGES : Int = 0
    var G : Array<MutableList<Int>> = arrayOf()
    var color : ByteArray = ByteArray(0)
    var topoOrder : MutableList<Int> = ArrayList()

    fun topoSort() {
        color = ByteArray(NODES+1) {WHITE}
        topoOrder = ArrayList()
        for (i in 1 until NODES) {
            if (color[i] == WHITE) dfs(i)
        }
        topoOrder.reverse()
    }

    fun dfs(u : Int) {
        color[u] = GRAY
        for (i in 0 until G[u].size) {
            var v = G[u][i]
            if (color[v] == WHITE) dfs(v)
        }
        topoOrder.add(u)
        color[u] = BLACK
    }

    fun fakeMain() {
        var scanner = inputFromFile()

        while (scanner!!.hasNext()) {
            NODES = scanner!!.nextInt()
            EDGES = scanner!!.nextInt()

            G = Array(NODES + 1) { ArrayList<Int>() }

            for (i in 0 until EDGES) {
                var u = scanner!!.nextInt()
                var v = scanner!!.nextInt()

                G[u].add(v)
            }

            topoSort()

            topoOrder.forEach { v -> print("$v ") }
            println()
        }
    }
}

fun main(args : Array<String>) {
    TopologicalSort_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}

/**
Input:
4 5
1 2
1 3
3 2
2 4
3 4

9 9
1 2
2 3
1 4
4 3
5 4
6 5
5 7
6 7
8 7

Output:
1 3 2 4
9 8 6 5 7 1 4 2 3
 **/