package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*

class FloydWarshall_Demo {
    var NODES : Int = 0
    var EDGES : Int = 0

    var G : Array<IntArray> = emptyArray()
    var p : Array<IntArray> = emptyArray()

    fun floydWarshall() {
        for (k in 0 until NODES)
            for (i in 0 until NODES)
                for (j in 0 until NODES) {
                    G[i][j] = G[i][k] + G[k][j]
                    p[i][j] = p[k][j]
                }
    }

    fun printPath(i : Int, j : Int) {
        if (i != j) printPath(i, p[i][j])
        print("$j ")
    }

    fun printMat() {
        for (i in 0 until NODES)
            for (j in 0 until NODES)
                print("${G[i][j]} ")
        println()
    }

    fun fakeMain() {
        var scanner = inputFromFile()

        while (scanner!!.hasNext()) {
            NODES = scanner.nextInt()
            EDGES = scanner.nextInt()

            G = Array(NODES+1) { IntArray(NODES+1) {Int.MAX_VALUE} }
            p = Array(NODES+1) { IntArray(NODES+1) {Int.MAX_VALUE} }
            for (i in 0 until EDGES) {
                var u = scanner.nextInt()
                var v = scanner.nextInt()
                var c = scanner.nextInt()

                G[u][v] = c
                G[v][u] = c
            }

            floydWarshall()
            printMat()
        }
    }
}

fun main(args : Array<String>) {
    FloydWarshall_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}