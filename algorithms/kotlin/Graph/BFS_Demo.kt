package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*
import kotlin.collections.ArrayList


class BFS_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES : Int = 0
    var EDGES : Int = 0
    var G : Array<MutableList<Int>?> = emptyArray()
    var source : Int = 0

    var dist : IntArray = IntArray(0)
    var color : ByteArray = ByteArray(0)
    var parent : IntArray = IntArray(0)
    var path : MutableList<Int> = ArrayList()

    fun bfs() {
        var u : Int
        var v : Int
        var Q : Queue<Int> = LinkedList()

        dist = IntArray(NODES+1)
        color = ByteArray(NODES+1)
        parent = IntArray(NODES+1)

        Q.offer(source)
        dist[source] = 0
        parent[source] = -1
        color[source] = GRAY

        while (Q.isNotEmpty()) {
            u = Q.poll()
            for (i in 0 until G[u]!!.size) {
                v = G[u]!![i]
                if (color[v] == WHITE) {
                    color[v] = GRAY
                    dist[v] = dist[u] + 1
                    parent[v] = u
                    Q.offer(v)
                }
            }
            color[u] = BLACK
        }
    }

    fun makePath(sink : Int) {
        if (parent[sink] == -1) {
            path.add(sink)
            return
        }
        makePath(parent[sink])
        path.add(sink)
    }

    fun fakeMain() {
        val scanner = inputFromFile()

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

        source = 1
        bfs()

        path.clear()
        makePath(5)
        path.forEach { v -> print("$v ")}
    }
}

fun main(args : Array<String>) {
    BFS_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}