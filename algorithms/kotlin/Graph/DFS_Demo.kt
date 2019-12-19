package com.mahbub.algorithm.graph;

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*

class DFS_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES : Int = 0
    var EDGES : Int = 0
    var G : Array<MutableList<Int>?> = emptyArray()
    var source : Int = 0

    var discovered : IntArray = IntArray(0)
    var finished : IntArray = IntArray(0)
    var parent : IntArray = IntArray(0)
    var path : IntArray = IntArray(0)
    var color : ByteArray = ByteArray(0)
    var dfsTime : Int = 0

    fun dfs() {
        color = ByteArray(NODES+1)
        parent = IntArray(NODES+1)
        discovered = IntArray(NODES+1)
        finished = IntArray(NODES+1)

        dfsTime = 0

        for (i in 1 .. NODES)
            if (color[i] == WHITE) dfsVisit(i)
    }

    fun dfsVisit(u : Int) {
        dfsTime += 1
        discovered[u] = dfsTime
        color[u] = GRAY

        for (i in 0 until G[u]!!.size) {
            var v : Int = G[u]!![i]
            if (color[v] == WHITE) {
                parent[v] = u
                dfsVisit(v);
            }
        }

        color[u] = BLACK
        dfsTime += 1
        finished[u] = dfsTime
    }

    fun printDiscovered() {
        discovered.forEach { v -> print("$v ") }
        println()
    }

    fun printFinished() {
        finished.forEach { v -> print("$v ") }
        println()
    }

    fun fakeMain() {
        val scanner : Scanner? = inputFromFile()

        NODES = scanner!!.nextInt()
        EDGES = scanner!!.nextInt()

        G = arrayOfNulls(NODES + 1)
        for (i in 0 .. NODES) G[i] = ArrayList()

        for (i in 0 until EDGES) {
            var u = scanner.nextInt()
            var v = scanner.nextInt()
            G[u]!!.add(v)
            G[v]!!.add(u)
        }

        dfs()

        printDiscovered()
        printFinished()
    }
}

fun main(args : Array<String>) {
    DFS_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}

