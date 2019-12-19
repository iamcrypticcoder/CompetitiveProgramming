package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.min

class ArticulationPoint_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES: Int = 0
    var EDGES: Int = 0

    var G: Array<MutableList<Int>> = Array(0) { ArrayList<Int>() }
    var color: ByteArray = ByteArray(0)
    var parent: IntArray = IntArray(0)
    var dfsNum: IntArray = IntArray(0)
    var dfsLow: IntArray = IntArray(0)
    var artNodes: BooleanArray = BooleanArray(0)
    var artBridges : MutableList<Edge> = ArrayList()

    var dfsRoot = 0
    var rootChildren = 0
    var dfsNumberCount = 0

    class Edge {
        var u: Int = 0
        var v: Int = 0

        constructor()
        constructor(u: Int, v: Int) {
            this.u = u
            this.v = v
        }
    }

    fun articulationPointAndBridge(u : Int) {
        dfsNum[u] = dfsNumberCount
        dfsLow[u] = dfsNumberCount
        dfsNumberCount++

        for (i in 0 until G[u].size) {
            var v = G[u][i]
            if (color[v] == WHITE) {
                parent[v] = u
                if (u == dfsRoot) rootChildren++

                articulationPointAndBridge(v)

                if (dfsLow[v] >= dfsNum[u]) artNodes[u] = true
                if (dfsLow[v] > dfsNum[u]) artBridges.add(Edge(u, v))
                dfsLow[u] = min(dfsLow[u], dfsLow[v])
            } else if (v != parent[u]) {
                dfsLow[u] = min(dfsLow[u], dfsNum[v])
            }
        }
        color[u] = BLACK
    }

    fun findArtPointAndBridges() {
        color = ByteArray(NODES+1)
        parent = IntArray(NODES+1)
        dfsNum = IntArray(NODES+1)
        dfsLow = IntArray(NODES+1)
        artNodes = BooleanArray(NODES+1)

        dfsNumberCount = 0
        for (i in 0 until NODES) {
            if (color[i] == WHITE) {
                dfsRoot = i
                rootChildren = 0
                articulationPointAndBridge(i)
                artNodes[dfsRoot] = (rootChildren > 1)
            }
        }
    }

    fun fakeMain() {
        var scanner : Scanner? = inputFromFile()

        NODES = scanner!!.nextInt()
        EDGES = scanner!!.nextInt()

        G = Array(NODES+1) { ArrayList<Int>() }

        for (i in 0 until EDGES) {
            var u = scanner!!.nextInt()
            var v = scanner!!.nextInt()

            G[u].add(v)
            G[v].add(u)
        }

        findArtPointAndBridges()

        for (i in 0 until NODES)
            println("${dfsNum[i]} ${dfsLow[i]}")

        println("Articulation Points:")
        for (i in 0 until NODES)
            if (artNodes[i]) print("$i ")
        println()

        println("Articulation Bridge:")
        for (i in 0 until artBridges.size)
            println("${artBridges[i].u} ${artBridges[i].v}")
    }
}

fun main(args : Array<String>) {
    ArticulationPoint_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}
