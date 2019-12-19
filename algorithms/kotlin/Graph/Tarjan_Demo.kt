package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.E
import kotlin.math.min

class Tarjan_Demo {
    val WHITE : Byte = 0
    val GRAY : Byte = 1
    val BLACK : Byte = 2

    var NODES : Int = 0
    var EDGES : Int = 0
    var G : Array<MutableList<Int>> = arrayOf()
    var color : ByteArray = ByteArray(0)

    var dfsNum : IntArray = IntArray(0)
    var dfsLow : IntArray = IntArray(0)
    var dfsNumberCounter : Int = 0
    var S : Stack<Int> = Stack()
    var inStack : BooleanArray = BooleanArray(0)

    fun tarjanSSC() {
        color = ByteArray(NODES+1)
        dfsNum = IntArray(NODES+1)
        dfsLow = IntArray(NODES+1)
        S = Stack()
        inStack = BooleanArray(NODES+1)

        for (i in 0 until NODES)
            if (color[i] == WHITE) strongConnect(i)
    }

    fun strongConnect(u : Int) {
        dfsNumberCounter++
        dfsNum[u] = dfsNumberCounter
        dfsLow[u] = dfsNumberCounter
        color[u] = GRAY
        S.push(u)
        inStack[u] = true

        for (i in 0 until G[u].size) {
            var v = G[u].get(i)
            if (color[v] == WHITE) {
                strongConnect(v)
                dfsLow[u] = min(dfsLow[u], dfsLow[v])
            } else if (inStack[v] == true) {
                dfsLow[u] = min(dfsLow[u], dfsNum[v]);
            }
        }

        if (dfsNum[u] == dfsLow[u]) {
            var v = -1
            while (v != u) {
                v = S.pop()
                inStack[v] = false
                print("${v} ")
            }
            println()
        }
    }

    fun fakeMain() {
        var scanner = inputFromFile()

        NODES = scanner!!.nextInt()
        EDGES = scanner!!.nextInt()

        G = Array(NODES+1) { ArrayList<Int>() }

        for (i in 0 until EDGES) {
            var u = scanner!!.nextInt()
            var v = scanner!!.nextInt()

            G[u].add(v)
        }

        tarjanSSC()
        println()
    }
}

fun main(args : Array<String>) {
    Tarjan_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}