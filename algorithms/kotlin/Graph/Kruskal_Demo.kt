package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*
import kotlin.collections.ArrayList

class Kruskal_Demo {

    class Edge : Comparable<Edge> {
        var u = 0
        var v = 0
        var c = 0

        constructor(u: Int, v: Int, c: Int) {
            this.u = u
            this.v = v
            this.c = c
        }
        override fun compareTo(o: Edge): Int {
            return this.c - o.c
        }
    }

    // -------------------- Disjoint Set Structure --------------------------------------
    private var dset: IntArray = IntArray(0)

    fun initSet(N: Int) {
        dset = IntArray(N + 1)
        for (i in 0..N) dset[i] = i
    }

    fun findSet(u: Int): Int {
        var ret : Int
        if (dset[u] == u)
            ret = u
        else {
            dset[u] = findSet(dset[u])
            ret = dset[u]
        }
        return ret
    }

    fun union(u: Int, v: Int) {
        dset[findSet(u)] = findSet(v)
    }
    // ----------------------------------------------------------------------------------

    var NODES : Int = 0
    var EDGES : Int = 0
    var edges : MutableList<Edge> = ArrayList()
    var spanEdges : MutableList<Edge> = ArrayList()
    var mstCost : Int = 0

    fun kruskal() : Int {
        var countSpanEdges : Int = 0
        mstCost = 0

        edges.sort()
        initSet(NODES)
        spanEdges = ArrayList()

        for (i in 0 until edges.size) {
            if (countSpanEdges == NODES - 1) break
            var e = edges[i]
            if (findSet(e.u) != findSet(e.v)) {
                spanEdges.add(edges[i])
                union(edges[i].u, e.v)
                mstCost += e.c
                countSpanEdges++
            }
        }

        return mstCost
    }

    fun fakeMain() {
        var scanner: Scanner? = inputFromFile()

        NODES = scanner!!.nextInt()
        EDGES = scanner!!.nextInt()

        edges = ArrayList()

        for (i in 0 until EDGES) {
            var u = scanner!!.nextInt()
            var v = scanner!!.nextInt()
            var c = scanner!!.nextInt()

            edges.add(Edge(u, v, c))
        }

        println("MST Cost: " + kruskal())
        for (i in 0 until spanEdges.size) {
            var e = spanEdges[i]
            println("${e.u} ${e.v} ${e.c}")
        }
    }
}

fun main(args : Array<String>) {
    Kruskal_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}
