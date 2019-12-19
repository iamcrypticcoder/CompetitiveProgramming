package com.mahbub.algorithm.graph

import java.util.*
import kotlin.collections.ArrayList


class ConnectedComponent_Demo {
    class Edge(u : Int, v : Int) {
        var u = u
        var v = v
    }

    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES : Int = 0
    var EDGES : Int = 0
    var G : Array<MutableList<Int>> = arrayOf()
    var edgeList : MutableList<Edge> = ArrayList()

    var color : ByteArray = ByteArray(0)

    var ccCount : Int = 0
    var ccList : MutableList<MutableList<Int>> = ArrayList()

    // Disjoint Set Data Structure
    var dset: IntArray = IntArray(0)
    var rank: IntArray = IntArray(0)

    fun initWithRank(n: Int) {
        dset = IntArray(n + 1)
        rank = IntArray(n + 1)
        for (i in 0..n) {
            dset[i] = i
            rank[i] = 0
        }
    }

    // Find with path compression
    fun findSet(u: Int): Int {
        return if (dset[u] == u) u else findSet(dset[u]).also { dset[u] = it }
    }

    fun unionByRank(x: Int, y: Int) {
        val xRoot = findSet(x)
        val yRoot = findSet(y)
        if (xRoot == yRoot) return
        // Attach smaller rank tree under root of high rank tree
        if (rank[xRoot] > rank[yRoot]) {
            dset[yRoot] = xRoot
        } else if (rank[xRoot] < rank[yRoot]) {
            dset[xRoot] = yRoot
        } else {
            dset[xRoot] = yRoot
            rank[yRoot]++
        }
    }
    // Disjoint Set Data Structure

    fun findCCUsingDFS() {
        ccCount = 0
        ccList = ArrayList()
        color = ByteArray(NODES+1)
        for (i in 1 .. NODES) {
            if (color[i] == WHITE) {
                var list = ArrayList<Int>()
                ccCount++
                dfs(i, list)
                ccList.add(list)
            }
        }
    }

    fun dfs(u : Int, list : MutableList<Int>) {
        list.add(u)
        color[u] = GRAY
        for (i in 0 until G[u].size) {
            var v = G[u][i]
            if (color[v] == WHITE) dfs(v, list)
        }
        color[u] = BLACK
    }

    fun findCCUsingBFS() {
        ccCount = 0
        ccList = ArrayList()
        color = ByteArray(NODES+1) { WHITE }
        for (i in 1 .. NODES) {
            if (color[i] == WHITE) {
                var list = ArrayList<Int>()
                ccCount++
                bfs(i, list)
                ccList.add(list)
            }
        }
    }

    fun bfs(u: Int, list: MutableList<Int>) {
        var u = u
        val Q: Queue<Int> = LinkedList()

        color[u] = GRAY
        Q.offer(u)
        list.add(u)

        while (!Q.isEmpty()) {
            u = Q.poll()
            for (i in 0 until G[u].size) {
                val v = G[u][i]
                if (color[v] === WHITE) {
                    color[v] = GRAY
                    Q.offer(v)
                    list.add(v)
                }
            }
            color[u] = BLACK
        }
    }

    fun findCCUsingDisjointSet() {
        initWithRank(NODES + 1)
        for (i in 0 until edgeList.size) {
            val edge: Edge = edgeList.get(i)
            unionByRank(edge.u, edge.v)
        }

        ccCount = 0
        val map: MutableMap<Int, MutableList<Int>> = HashMap()
        for (i in 1..NODES) {
            if (dset[i] == i) {
                ccCount++
                map[i] = ArrayList()
            }
        }
        ccList = ArrayList(ccCount)
        for (i in 1..NODES) {
            map[findSet(i)]!!.add(i)
        }

        for ((k, v) in map) ccList.add(v)
    }
}



fun main(args : Array<String>) {

}